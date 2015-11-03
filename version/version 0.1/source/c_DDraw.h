//---------------------------------------------------------------------------
#ifndef c_DDrawH
#define c_DDrawH
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <ddraw.h>
//---------------------------------------------------------------------------
#define RGB_256    (r,g,b)((DWORD)(((BYTE)(r)|((WORD)(g)<<8))|(((DWORD)(BYTE)(b))<<16)))
#define RGB_16_555 (r,g,b)((b&31)+((g&31)<<5)+((r&31)<<10))
#define RGB_16_565 (r,g,b)((b&31)+((g&63)<<5)+((r&31)<<11))
//---------------------------------------------------------------------------
HRESULT             DDCopyBitmap(IDirectDraw *DDSSurface, HBITMAP hbm,int x, int y, int dx, int dy) ;
IDirectDrawSurface *DDLoadBitmap(IDirectDrawSurface *DDraw,LPCSTR szBitmap,
                                 int dx, int dy, int &height,int &width) ;
DWORD   DDColorMatch(IDirectDrawSurface *DDSSurface, COLORREF rgb) ;
HRESULT DDSetColorKey(IDirectDrawSurface *DDSSurface, COLORREF rgb) ;
void    DDOutErrorCode(FILE *error_log) ;
IDirectDrawClipper *DDAttachClipper(IDirectDraw *DDraw,
                                    IDirectDrawSurface *DDSSurface,
                                    int num_rects,RECT *clip_list) ;
//---------------------------------------------------------------------------
//###########################################################################
class c_DDraw
{
  private :
    unsigned screen_WIDTH,screen_HEIGHT,screen_BITDEPTH;
    HWND      app_handle;
    HINSTANCE app_instance;
    HRESULT (*RestoreFunction)() ;
  public :
    IDirectDraw *DDraw ;                     // main object
    IDirectDrawSurface *DDSPrimary,*DDSBack; // Primary,Back surface
    c_DDraw(HWND app_handle,HINSTANCE app_instance,HRESULT (*RestoreFunction)(),
            unsigned screen_WIDTH,unsigned screen_HEIGHT,unsigned screen_BITDEPTH) ;
    HRESULT Init(FILE *log_file=NULL) ;                    // try to init ddraw,primary and back surface
    HRESULT FillSurface(IDirectDrawSurface *DDSSurface,
                     DWORD color,FILE *log_file=NULL) ; // try to fill surface
    HRESULT FlipPage(FILE *log_file=NULL) ;                // flip page primary->back
    HRESULT RestoreAll(FILE *log_file=NULL) ;              // try to restore all surface
    void ReleaseAll(void (*ReleaseFunction)()) ;        // try to release all surface
} ;
//---------------------------------------------------------------------------
//###########################################################################
//---------------------------------------------------------------------------
c_DDraw::c_DDraw(HWND app_handle,HINSTANCE app_instance,HRESULT (*RestoreFunction)(),
                 unsigned screen_WIDTH,unsigned screen_HEIGHT,unsigned screen_BITDEPTH)
{
  this->RestoreFunction = RestoreFunction ;
  this->app_handle=app_handle ;
  this->app_instance=app_instance ;
  this->screen_HEIGHT = screen_HEIGHT ;
  this->screen_WIDTH = screen_WIDTH ;
  this->screen_BITDEPTH = screen_BITDEPTH;
  DDraw=NULL ;
  DDSPrimary=NULL ;
  DDSBack=NULL ;
} ;
//---------------------------------------------------------------------------
HRESULT c_DDraw::Init(FILE *log_file)
{
  DirectDrawCreate(NULL, &DDraw, NULL);
  DDraw->SetCooperativeLevel(app_handle,DDSCL_EXCLUSIVE|DDSCL_FULLSCREEN);
  DDraw->SetDisplayMode(screen_WIDTH,screen_HEIGHT,screen_BITDEPTH);

  DDSURFACEDESC ddsd;
  ZeroMemory(&ddsd, sizeof(ddsd));
  ddsd.dwSize = sizeof(ddsd);
  ddsd.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
  ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE |
                        DDSCAPS_FLIP |
                        DDSCAPS_COMPLEX ;
  ddsd.dwBackBufferCount = 1 ;
  HRESULT res=DDraw->CreateSurface(&ddsd, &DDSPrimary, NULL);
  if (res !=DD_OK)
  {
    if(log_file)fprintf(log_file,"ERROR: c_DDraw::Init, Create primary surface") ;
    return res;
  } ;
  if(log_file)fprintf(log_file,"DONE! Create Main Surface\n");
  DDSCAPS ddscaps ;
  ddscaps.dwCaps = DDSCAPS_BACKBUFFER;
  res = DDSPrimary->GetAttachedSurface(&ddscaps,&DDSBack);
  if (res!=DD_OK)
  {
    if(log_file)fprintf(log_file,"ERROR: c_DDraw::Init, Create back surface") ;
    return res;
  } ;
  if(log_file)fprintf(log_file,"DONE! Attach Back Buffer\n");
  return res;
};
//---------------------------------------------------------------------------
HRESULT c_DDraw::FillSurface(IDirectDrawSurface *DDSSurface,
                          DWORD color,FILE *log_file)
{
  DDBLTFX ddbltfx ;
  ZeroMemory(&ddbltfx,sizeof(ddbltfx)) ;
  ddbltfx.dwSize = sizeof(ddbltfx) ;
  ddbltfx.dwFillColor = color ;
  if(log_file)fprintf(log_file,"DONE! c_DDraw::FillSurface()\n");
  HRESULT res=DD_OK ;
  while(true)
  {
     res = DDSSurface->Blt (NULL,NULL,NULL,DDBLT_COLORFILL|DDBLT_WAIT,&ddbltfx) ;
     if (res==DD_OK)break;
     else
     if (res==DDERR_SURFACELOST)RestoreAll() ;
     else
     {
        if(log_file)fprintf(log_file,"ERROR: c_DDraw::FillSurface()\n") ;
        break;
     } ;
  } ;
  return res;
} ;
//---------------------------------------------------------------------------
HRESULT c_DDraw::FlipPage(FILE *log_file)
{
  HRESULT res;
  while(true)
  {
    res = DDSPrimary->Flip(NULL,DDFLIP_WAIT) ;
    if (res==DD_OK)break;
    else
    if (res==DDERR_SURFACELOST)RestoreAll() ;
    else
    {
      if(log_file)fprintf(log_file,"ERROR: c_DDraw::FlipPage()") ;
      break;
    } ;
  } ;
  return res;
} ;
//---------------------------------------------------------------------------
HRESULT c_DDraw::RestoreAll(FILE *log_file)
{
  HRESULT res ;
  res = DDSPrimary->Restore() ;
  if (res == DD_OK)
  {
    res = RestoreFunction() ;
    if (res!=DD_OK)
    {
      if(log_file)fprintf(log_file,"ERROR: c_DDraw::RestoreAll, extern\n") ;
      return res;
    } ;
  }
  else
  {
    if(log_file)fprintf(log_file,"ERROR: c_DDraw::RestoreAll, Primary\n") ;
    return res;
  } ;
  return res;
} ;
//---------------------------------------------------------------------------
void c_DDraw::ReleaseAll(void (*ReleaseFunction)())
{
  if (DDraw)
  {
    if (DDSPrimary)
    {
      ReleaseFunction() ;
      DDSPrimary->Release() ;
      DDSPrimary = NULL ;
    }
    DDraw->Release() ;
    DDraw = NULL ;
  };
} ;
//###########################################################################
//---------------------------------------------------------------------------
HRESULT DDCopyBitmap(IDirectDrawSurface *DDSSurface, HBITMAP hbm, int x, int y, int dx, int dy)
{
  HDC                 hdcImage;
  HDC                 hdc;
  BITMAP              bm;
  DDSURFACEDESC       ddsd;
  HRESULT             hr;

  if (hbm == NULL || DDSSurface == NULL)
  	return E_FAIL;
  //
  // make sure this surface is restored.
  //
  DDSSurface->Restore();
  //
  //  select bitmap into a memoryDC so we can use it.
  //
  hdcImage = CreateCompatibleDC(NULL);
  if (!hdcImage)
  	OutputDebugString("createcompatible dc failed\n");
  SelectObject(hdcImage, hbm);

  //
  // get size of the bitmap
  //
  GetObject(hbm, sizeof(bm), &bm);    // get size of bitmap
  dx = dx == 0 ? bm.bmWidth  : dx;    // use the passed size, unless zero
  dy = dy == 0 ? bm.bmHeight : dy;

  //
  // get size of surface.
  //
  ddsd.dwSize = sizeof(ddsd);
  ddsd.dwFlags = DDSD_HEIGHT | DDSD_WIDTH;
  DDSSurface->GetSurfaceDesc(&ddsd);

  if ((hr = DDSSurface->GetDC(&hdc)) == DD_OK)
  {
	  StretchBlt(hdc, 0, 0, ddsd.dwWidth, ddsd.dwHeight, hdcImage, x, y, dx, dy, SRCCOPY);
	  DDSSurface->ReleaseDC(hdc);
  }
  DeleteDC(hdcImage);
  return hr;
} ;
//---------------------------------------------------------------------------
IDirectDrawSurface *DDLoadBitmap(IDirectDraw *DDraw,LPCSTR szBitmap,
                                 int dx, int dy,int &height,int &width)
{
  HBITMAP             hbm;
  BITMAP              bm;
  DDSURFACEDESC       ddsd;
  IDirectDrawSurface *pdds;
  //
  //  try to load the bitmap as a resource, if that fails, try it as a file
  //
  hbm = (HBITMAP)LoadImage(GetModuleHandle(NULL), szBitmap, IMAGE_BITMAP, dx, dy, LR_CREATEDIBSECTION);
  if (hbm == NULL)
	  hbm = (HBITMAP)LoadImage(NULL, szBitmap, IMAGE_BITMAP, dx, dy, LR_LOADFROMFILE|LR_CREATEDIBSECTION);
  if (hbm == NULL)
	  return NULL;

  //
  // get size of the bitmap
  //
  GetObject(hbm, sizeof(bm), &bm);      // get size of bitmap

  //
  // create a DirectDrawSurface for this bitmap
  //
  ZeroMemory(&ddsd, sizeof(ddsd));
  ddsd.dwSize = sizeof(ddsd);
  ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT |DDSD_WIDTH;
  ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_VIDEOMEMORY;
  ddsd.dwWidth = bm.bmWidth;
  ddsd.dwHeight = bm.bmHeight;
  height = bm.bmHeight ;
  width  = bm.bmWidth ;
  HRESULT res =DDraw->CreateSurface(&ddsd, &pdds, NULL) ;
  if (res == DDERR_OUTOFVIDEOMEMORY)
  {
    ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
    res = DDraw->CreateSurface(&ddsd,&pdds,NULL) ;
  } ;
  if(res!=DD_OK)return NULL ;

  DDCopyBitmap(pdds, hbm, 0, 0, 0, 0);

  DeleteObject(hbm);

  return pdds;
}
//---------------------------------------------------------------------------
DWORD DDColorMatch(IDirectDrawSurface *DDSSurface, COLORREF rgb)
{
  COLORREF rgbT;
  HDC hdc;
  DWORD dw = CLR_INVALID;
  DDSURFACEDESC ddsd;
  HRESULT hres;

  //
  //  use GDI SetPixel to color match for us
  //
  if (rgb != CLR_INVALID && DDSSurface->GetDC(&hdc) == DD_OK)
  {
	  rgbT = GetPixel(hdc, 0, 0);             // save current pixel value
	  SetPixel(hdc, 0, 0, rgb);               // set our value
	  DDSSurface->ReleaseDC(hdc);
  }

  //
  // now lock the surface so we can read back the converted color
  //
  ddsd.dwSize = sizeof(ddsd);
  while ((hres = DDSSurface->Lock(NULL, &ddsd, 0, NULL)) == DDERR_WASSTILLDRAWING);
  if (hres == DD_OK)
  {
	  dw  = *(DWORD *)ddsd.lpSurface;                     // get DWORD
    if(ddsd.ddpfPixelFormat.dwRGBBitCount < 32)
      dw &= (1 << ddsd.ddpfPixelFormat.dwRGBBitCount)-1;  // mask it to bpp
	  DDSSurface->Unlock(NULL);
  }

  //
  //  now put the color that was there back.
  //
  if (rgb != CLR_INVALID && DDSSurface->GetDC(&hdc) == DD_OK)
  {
	  SetPixel(hdc, 0, 0, rgbT);
	  DDSSurface->ReleaseDC(hdc);
  }

  return dw;
}
//---------------------------------------------------------------------------
/*
 * DDSetColorKey
 *
 * set a color key for a surface, given a RGB.
 * if you pass CLR_INVALID as the color key, the pixel
 * in the upper-left corner will be used.
 */
HRESULT DDSetColorKey(IDirectDrawSurface *DDSSurface, COLORREF rgb)
{
  DDCOLORKEY          ddck;
  ddck.dwColorSpaceLowValue  = DDColorMatch(DDSSurface, rgb);
  ddck.dwColorSpaceHighValue = ddck.dwColorSpaceLowValue;
  return DDSSurface->SetColorKey(DDCKEY_SRCBLT, &ddck);
}
//---------------------------------------------------------------------------
void DDOutErrorCode(FILE *error_log)
{
  fprintf(error_log,"DDERR_ALREADYINITIALIZED           %6u\n",DDERR_ALREADYINITIALIZED) ;
  fprintf(error_log,"DDERR_CANNOTATTACHSURFACE          %6u\n",DDERR_CANNOTATTACHSURFACE);
  fprintf(error_log,"DDERR_CANNOTDETACHSURFACE          %6u\n",DDERR_CANNOTDETACHSURFACE);
  fprintf(error_log,"DDERR_CURRENTLYNOTAVAIL            %6u\n",DDERR_CURRENTLYNOTAVAIL) ;
  fprintf(error_log,"DDERR_EXCEPTION                    %6u\n",DDERR_EXCEPTION) ;
  fprintf(error_log,"DDERR_GENERIC                      %6u\n",DDERR_GENERIC) ;
  fprintf(error_log,"DDERR_HEIGHTALIGN                  %6u\n",DDERR_HEIGHTALIGN) ;
  fprintf(error_log,"DDERR_INCOMPATIBLEPRIMARY          %6u\n",DDERR_INCOMPATIBLEPRIMARY) ;
  fprintf(error_log,"DDERR_INVALIDCAPS                  %6u\n",DDERR_INVALIDCAPS) ;
  fprintf(error_log,"DDERR_INVALIDCLIPLIST              %6u\n",DDERR_INVALIDCLIPLIST) ;
  fprintf(error_log,"DDERR_INVALIDMODE                  %6u\n",DDERR_INVALIDMODE) ;
  fprintf(error_log,"DDERR_INVALIDOBJECT                %6u\n",DDERR_INVALIDOBJECT);
  fprintf(error_log,"DDERR_INVALIDPARAMS                %6u\n",DDERR_INVALIDPARAMS);
  fprintf(error_log,"DDERR_INVALIDPIXELFORMAT           %6u\n",DDERR_INVALIDPIXELFORMAT);
  fprintf(error_log,"DDERR_INVALIDRECT                  %6u\n",DDERR_INVALIDRECT);
  fprintf(error_log,"DDERR_LOCKEDSURFACES               %6u\n",DDERR_LOCKEDSURFACES);
  fprintf(error_log,"DDERR_NO3D                         %6u\n",DDERR_NO3D);
  fprintf(error_log,"DDERR_NOALPHAHW                    %6u\n",DDERR_NOALPHAHW);
  fprintf(error_log,"DDERR_NOCLIPLIST                   %6u\n",DDERR_NOCLIPLIST);
  fprintf(error_log,"DDERR_NOCOLORCONVHW                %6u\n",DDERR_NOCOLORCONVHW);
  fprintf(error_log,"DDERR_NOCOOPERATIVELEVELSET        %6u\n",DDERR_NOCOOPERATIVELEVELSET);
  fprintf(error_log,"DDERR_NOCOLORKEY                   %6u\n",DDERR_NOCOLORKEY);
  fprintf(error_log,"DDERR_NOCOLORKEYHW                 %6u\n",DDERR_NOCOLORKEYHW);
  fprintf(error_log,"DDERR_NODIRECTDRAWSUPPORT          %6u\n",DDERR_NODIRECTDRAWSUPPORT);
  fprintf(error_log,"DDERR_NOEXCLUSIVEMODE              %6u\n",DDERR_NOEXCLUSIVEMODE);
  fprintf(error_log,"DDERR_NOFLIPHW                     %6u\n",DDERR_NOFLIPHW);
  fprintf(error_log,"DDERR_NOGDI                        %6u\n",DDERR_NOGDI);
  fprintf(error_log,"DDERR_NOMIRRORHW                   %6u\n",DDERR_NOMIRRORHW);
  fprintf(error_log,"DDERR_NOTFOUND                     %6u\n",DDERR_NOTFOUND);
  fprintf(error_log,"DDERR_NOOVERLAYHW                  %6u\n",DDERR_NOOVERLAYHW);
  fprintf(error_log,"DDERR_NORASTEROPHW                 %6u\n",DDERR_NORASTEROPHW);
  fprintf(error_log,"DDERR_NOROTATIONHW                 %6u\n",DDERR_NOROTATIONHW);
  fprintf(error_log,"DDERR_NOSTRETCHHW                  %6u\n",DDERR_NOSTRETCHHW);
  fprintf(error_log,"DDERR_NOT4BITCOLOR                 %6u\n",DDERR_NOT4BITCOLOR);
  fprintf(error_log,"DDERR_NOT4BITCOLORINDEX            %6u\n",DDERR_NOT4BITCOLORINDEX);
  fprintf(error_log,"DDERR_NOT8BITCOLOR                 %6u\n",DDERR_NOT8BITCOLOR);
  fprintf(error_log,"DDERR_NOTEXTUREHW                  %6u\n",DDERR_NOTEXTUREHW);
  fprintf(error_log,"DDERR_NOVSYNCHW                    %6u\n",DDERR_NOVSYNCHW);
  fprintf(error_log,"DDERR_NOZBUFFERHW                  %6u\n",DDERR_NOZBUFFERHW);
  fprintf(error_log,"DDERR_NOZOVERLAYHW                 %6u\n",DDERR_NOZOVERLAYHW);
  fprintf(error_log,"DDERR_OUTOFCAPS                    %6u\n",DDERR_OUTOFCAPS);
  fprintf(error_log,"DDERR_OUTOFMEMORY                  %6u\n",DDERR_OUTOFMEMORY);
  fprintf(error_log,"DDERR_OUTOFVIDEOMEMORY             %6u\n",DDERR_OUTOFVIDEOMEMORY);
  fprintf(error_log,"DDERR_OVERLAYCANTCLIP              %6u\n",DDERR_OVERLAYCANTCLIP);
  fprintf(error_log,"DDERR_OVERLAYCOLORKEYONLYONEACTIVE %6u\n",DDERR_OVERLAYCOLORKEYONLYONEACTIVE);
  fprintf(error_log,"DDERR_PALETTEBUSY                  %6u\n",DDERR_PALETTEBUSY);
  fprintf(error_log,"DDERR_COLORKEYNOTSET               %6u\n",DDERR_COLORKEYNOTSET);
  fprintf(error_log,"DDERR_SURFACEALREADYATTACHED       %6u\n",DDERR_SURFACEALREADYATTACHED);
  fprintf(error_log,"DDERR_SURFACEALREADYDEPENDENT      %6u\n",DDERR_SURFACEALREADYDEPENDENT);
  fprintf(error_log,"DDERR_SURFACEBUSY                  %6u\n",DDERR_SURFACEBUSY);
  fprintf(error_log,"DDERR_CANTLOCKSURFACE              %6u\n",DDERR_CANTLOCKSURFACE);
  fprintf(error_log,"DDERR_SURFACEISOBSCURED            %6u\n",DDERR_SURFACEISOBSCURED);
  fprintf(error_log,"DDERR_SURFACELOST                  %6u\n",DDERR_SURFACELOST);
  fprintf(error_log,"DDERR_SURFACENOTATTACHED           %6u\n",DDERR_SURFACENOTATTACHED);
  fprintf(error_log,"DDERR_TOOBIGHEIGHT                 %6u\n",DDERR_TOOBIGHEIGHT);
  fprintf(error_log,"DDERR_TOOBIGSIZE                   %6u\n",DDERR_TOOBIGSIZE);
  fprintf(error_log,"DDERR_TOOBIGWIDTH                  %6u\n",DDERR_TOOBIGWIDTH);
  fprintf(error_log,"DDERR_UNSUPPORTED                  %6u\n",DDERR_UNSUPPORTED);
  fprintf(error_log,"DDERR_UNSUPPORTEDFORMAT            %6u\n",DDERR_UNSUPPORTEDFORMAT);
  fprintf(error_log,"DDERR_UNSUPPORTEDMASK              %6u\n",DDERR_UNSUPPORTEDMASK);
  fprintf(error_log,"DDERR_VERTICALBLANKINPROGRESS      %6u\n",DDERR_VERTICALBLANKINPROGRESS);
  fprintf(error_log,"DDERR_WASSTILLDRAWING              %6u\n",DDERR_WASSTILLDRAWING);
  fprintf(error_log,"DDERR_XALIGN                       %6u\n",DDERR_XALIGN);
  fprintf(error_log,"DDERR_INVALIDDIRECTDRAWGUID        %6u\n",DDERR_INVALIDDIRECTDRAWGUID);
  fprintf(error_log,"DDERR_DIRECTDRAWALREADYCREATED     %6u\n",DDERR_DIRECTDRAWALREADYCREATED);
  fprintf(error_log,"DDERR_NODIRECTDRAWHW               %6u\n",DDERR_NODIRECTDRAWHW);
  fprintf(error_log,"DDERR_PRIMARYSURFACEALREADYEXISTS  %6u\n",DDERR_PRIMARYSURFACEALREADYEXISTS);
  fprintf(error_log,"DDERR_NOEMULATION                  %6u\n",DDERR_NOEMULATION);
  fprintf(error_log,"DDERR_REGIONTOOSMALL               %6u\n",DDERR_REGIONTOOSMALL);
  fprintf(error_log,"DDERR_CLIPPERISUSINGHWND           %6u\n",DDERR_CLIPPERISUSINGHWND);
  fprintf(error_log,"DDERR_NOCLIPPERATTACHED            %6u\n",DDERR_NOCLIPPERATTACHED);
  fprintf(error_log,"DDERR_NOHWND                       %6u\n",DDERR_NOHWND);
  fprintf(error_log,"DDERR_HWNDSUBCLASSED               %6u\n",DDERR_HWNDSUBCLASSED);
  fprintf(error_log,"DDERR_HWNDALREADYSET               %6u\n",DDERR_HWNDALREADYSET);
  fprintf(error_log,"DDERR_NOPALETTEATTACHED            %6u\n",DDERR_NOPALETTEATTACHED);
  fprintf(error_log,"DDERR_NOPALETTEHW                  %6u\n",DDERR_NOPALETTEHW);
  fprintf(error_log,"DDERR_BLTFASTCANTCLIP              %6u\n",DDERR_BLTFASTCANTCLIP);
  fprintf(error_log,"DDERR_NOBLTHW                      %6u\n",DDERR_NOBLTHW);
  fprintf(error_log,"DDERR_NODDROPSHW                   %6u\n",DDERR_NODDROPSHW);
  fprintf(error_log,"DDERR_OVERLAYNOTVISIBLE            %6u\n",DDERR_OVERLAYNOTVISIBLE);
  fprintf(error_log,"DDERR_NOOVERLAYDEST                %6u\n",DDERR_NOOVERLAYDEST);
  fprintf(error_log,"DDERR_INVALIDPOSITION              %6u\n",DDERR_INVALIDPOSITION);
  fprintf(error_log,"DDERR_NOTAOVERLAYSURFACE           %6u\n",DDERR_NOTAOVERLAYSURFACE);
  fprintf(error_log,"DDERR_EXCLUSIVEMODEALREADYSET      %6u\n",DDERR_EXCLUSIVEMODEALREADYSET);
  fprintf(error_log,"DDERR_NOTFLIPPABLE                 %6u\n",DDERR_NOTFLIPPABLE);
  fprintf(error_log,"DDERR_CANTDUPLICATE                %6u\n",DDERR_CANTDUPLICATE);
  fprintf(error_log,"DDERR_NOTLOCKED                    %6u\n",DDERR_NOTLOCKED);
  fprintf(error_log,"DDERR_CANTCREATEDC                 %6u\n",DDERR_CANTCREATEDC);
  fprintf(error_log,"DDERR_NODC                         %6u\n",DDERR_NODC);
  fprintf(error_log,"DDERR_WRONGMODE                    %6u\n",DDERR_WRONGMODE);
  fprintf(error_log,"DDERR_IMPLICITLYCREATED            %6u\n",DDERR_IMPLICITLYCREATED);
  fprintf(error_log,"DDERR_NOTPALETTIZED                %6u\n",DDERR_NOTPALETTIZED);
  fprintf(error_log,"DDERR_UNSUPPORTEDMODE              %6u\n",DDERR_UNSUPPORTEDMODE);
  fprintf(error_log,"DDERR_NOMIPMAPHW                   %6u\n",DDERR_NOMIPMAPHW);
  fprintf(error_log,"DDERR_INVALIDSURFACETYPE           %6u\n",DDERR_INVALIDSURFACETYPE);
  fprintf(error_log,"DDERR_NOOPTIMIZEHW                 %6u\n",DDERR_NOOPTIMIZEHW);
  fprintf(error_log,"DDERR_NOTLOADED                    %6u\n",DDERR_NOTLOADED);
  fprintf(error_log,"DDERR_NOFOCUSWINDOW                %6u\n",DDERR_NOFOCUSWINDOW);
  fprintf(error_log,"DDERR_DCALREADYCREATED             %6u\n",DDERR_DCALREADYCREATED);
  fprintf(error_log,"DDERR_NONONLOCALVIDMEM             %6u\n",DDERR_NONONLOCALVIDMEM);
  fprintf(error_log,"DDERR_CANTPAGELOCK                 %6u\n",DDERR_CANTPAGELOCK);
  fprintf(error_log,"DDERR_CANTPAGEUNLOCK               %6u\n",DDERR_CANTPAGEUNLOCK);
  fprintf(error_log,"DDERR_NOTPAGELOCKED                %6u\n",DDERR_NOTPAGELOCKED);
  fprintf(error_log,"DDERR_MOREDATA                     %6u\n",DDERR_MOREDATA);
  fprintf(error_log,"DDERR_VIDEONOTACTIVE               %6u\n",DDERR_VIDEONOTACTIVE);
  fprintf(error_log,"DDERR_DEVICEDOESNTOWNSURFACE       %6u\n",DDERR_DEVICEDOESNTOWNSURFACE);
  fprintf(error_log,"DDERR_NOTINITIALIZED               %6u\n",DDERR_NOTINITIALIZED);
} ;
//---------------------------------------------------------------------------
IDirectDrawClipper *DDAttachClipper(IDirectDraw *DDraw,
                                    IDirectDrawSurface *DDSSurface,
                                    int num_rects,RECT *clip_list)
{
  int index ;
  IDirectDrawClipper *clipper ;
  RGNDATA *region_data ;
  if (FAILED(DDraw->CreateClipper(0,&clipper,NULL))) return NULL;
  region_data = new RGNDATA[num_rects] ;
  memcpy(region_data->Buffer, clip_list, sizeof(RECT)*num_rects);
  region_data->rdh.dwSize          = sizeof(RGNDATAHEADER);
  region_data->rdh.iType           = RDH_RECTANGLES;
  region_data->rdh.nCount          = num_rects;
  region_data->rdh.nRgnSize        = num_rects*sizeof(RECT);

  region_data->rdh.rcBound.left    =  64000;
  region_data->rdh.rcBound.top     =  64000;
  region_data->rdh.rcBound.right   = -64000;
  region_data->rdh.rcBound.bottom  = -64000;

  // find bounds of all clipping regions
  for (index=0; index<num_rects; index++)
  {
    // test if the next rectangle unioned with the current bound is larger
    if (clip_list[index].left < region_data->rdh.rcBound.left)
      region_data->rdh.rcBound.left = clip_list[index].left;
    if (clip_list[index].right > region_data->rdh.rcBound.right)
      region_data->rdh.rcBound.right = clip_list[index].right;
    if (clip_list[index].top < region_data->rdh.rcBound.top)
      region_data->rdh.rcBound.top = clip_list[index].top;
    if (clip_list[index].bottom > region_data->rdh.rcBound.bottom)
      region_data->rdh.rcBound.bottom = clip_list[index].bottom;

  } ;// end for index
// now we have computed the bounding rectangle region and set up the data
// now let's set the clipping list
  if (FAILED(clipper->SetClipList(region_data, 0)))
  {
    // release memory and return error
    delete region_data ;
    return NULL;
  } ;// end if
  if (FAILED(DDSSurface->SetClipper(clipper)))
  {
    // release memory and return error
    delete region_data;
    return NULL;
  } ;// end if
// all is well, so release memory and send back the pointer to the new clipper
  delete region_data;
  return clipper;
} ;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
LPDIRECTDRAWCLIPPER DDraw_Attach_Clipper(LPDIRECTDRAW lpdd,
                                         LPDIRECTDRAWSURFACE lpdds,
                                         int num_rects,
                                         LPRECT clip_list)

{
// this function creates a clipper from the sent clip list and attaches
// it to the sent surface

int index;                         // looping var
LPDIRECTDRAWCLIPPER lpddclipper;   // pointer to the newly created dd clipper
LPRGNDATA region_data;             // pointer to the region data that contains
                                   // the header and clip list

// first create the direct draw clipper
if (FAILED(lpdd->CreateClipper(0,&lpddclipper,NULL)))
   return(NULL);

// now create the clip list from the sent data

// first allocate memory for region data
region_data = (LPRGNDATA)malloc(sizeof(RGNDATAHEADER)+num_rects*sizeof(RECT));

// now copy the rects into region data
memcpy(region_data->Buffer, clip_list, sizeof(RECT)*num_rects);

// set up fields of header
region_data->rdh.dwSize          = sizeof(RGNDATAHEADER);
region_data->rdh.iType           = RDH_RECTANGLES;
region_data->rdh.nCount          = num_rects;
region_data->rdh.nRgnSize        = num_rects*sizeof(RECT);

region_data->rdh.rcBound.left    =  64000;
region_data->rdh.rcBound.top     =  64000;
region_data->rdh.rcBound.right   = -64000;
region_data->rdh.rcBound.bottom  = -64000;

// find bounds of all clipping regions
for (index=0; index<num_rects; index++)
    {
    // test if the next rectangle unioned with the current bound is larger
    if (clip_list[index].left < region_data->rdh.rcBound.left)
       region_data->rdh.rcBound.left = clip_list[index].left;

    if (clip_list[index].right > region_data->rdh.rcBound.right)
       region_data->rdh.rcBound.right = clip_list[index].right;

    if (clip_list[index].top < region_data->rdh.rcBound.top)
       region_data->rdh.rcBound.top = clip_list[index].top;

    if (clip_list[index].bottom > region_data->rdh.rcBound.bottom)
       region_data->rdh.rcBound.bottom = clip_list[index].bottom;

    } // end for index

// now we have computed the bounding rectangle region and set up the data
// now let's set the clipping list

if (FAILED(lpddclipper->SetClipList(region_data, 0)))
   {
   // release memory and return error
   free(region_data);
   return(NULL);
   } // end if

// now attach the clipper to the surface
if (FAILED(lpdds->SetClipper(lpddclipper)))
   {
   // release memory and return error
   free(region_data);
   return(NULL);
   } // end if

// all is well, so release memory and send back the pointer to the new clipper
free(region_data);
return(lpddclipper);
} // end DDraw_Attach_Clipper
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
