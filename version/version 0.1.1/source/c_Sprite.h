/*
*  c_Sprite class
*  кдасс для работы со спрайтами
*
*  version 1.1
*/
#ifndef _c_Sprite
#define _c_Sprite
#include <stdio.h>
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <ddraw.h>
#include "c_DDraw.h"
//---------------------------------------------------------------------------
//###########################################################################
class c_Sprite
{
  private :
    IDirectDrawSurface *DDSSprite ;         // spite surface
    unsigned x_count,y_count,x_size,y_size ;// sprite param
  public :
    c_Sprite(IDirectDraw *DDraw,LPCSTR path,unsigned x_count,unsigned y_count,FILE *log_file=NULL) ;
    HRESULT Restore() {HRESULT res=DDSSprite->Restore();return res;};
    void    Release() {if(DDSSprite){DDSSprite->Release();DDSSprite=NULL;}};
    unsigned GetXSize(){return x_size;};
    unsigned GetYSize(){return y_size;};
    HRESULT Draw    (IDirectDrawSurface *DDSSurface,int x,int y,int x_num,int y_num,FILE *log_file=NULL) ;
    HRESULT DrawClip(IDirectDrawSurface *DDSSurface,int x,int y,int x_num,int y_num,
                     RECT screen,FILE *log_file=NULL) ;
} ;
//###########################################################################
//---------------------------------------------------------------------------
c_Sprite::c_Sprite(IDirectDraw *DDraw,LPCSTR path,unsigned x_count,unsigned y_count,FILE *log_file)
{
  if(log_file)fprintf(log_file,"START c_Sprite::c_Sprite\n") ;
  int height,width ;
  DDSSprite = DDLoadBitmap(DDraw,path,0,0,height,width);
  this->x_count = x_count ;
  this->y_count = y_count ;
  x_size = width  / x_count ;
  y_size = height / y_count ;
  if(log_file)fprintf(log_file,"   x_size %d, y_size %d\n",x_size,y_size) ;
  HRESULT res ;
  res = DDSetColorKey(DDSSprite,RGB(255,0,255)) ;// default color key
  if(log_file)fprintf(log_file,"END   c_Sprite::c_Sprite\n") ;
} ;
//---------------------------------------------------------------------------
HRESULT c_Sprite::Draw(IDirectDrawSurface *DDSSurface,int x,int y,int x_num,int y_num,FILE *log_file)
{
  if(log_file)fprintf(log_file,"START c_Sprite::Draw\n") ;
  HRESULT res ;
  int sprite_x = x_num*x_size,
      sprite_y = y_num*y_size;
  if(log_file)fprintf(log_file,"   sprite_x %d, sprite_y %d\n",sprite_x,sprite_y) ;
  RECT srcRect ;
  SetRect(&srcRect,sprite_x,sprite_y,sprite_x+x_size,sprite_y+y_size) ;
  res = DDSSurface->BltFast(x,y,DDSSprite,&srcRect,
                            DDBLTFAST_WAIT | DDBLTFAST_SRCCOLORKEY);
  if(log_file)fprintf(log_file,"END   c_Sprite::Draw\n") ;
  return res ;
} ;
//---------------------------------------------------------------------------
HRESULT c_Sprite::DrawClip(IDirectDrawSurface *DDSSurface,int x,int y,
                           int x_num,int y_num,RECT screen,FILE *log_file)
{
  if(log_file)fprintf(log_file,"START c_Sprite::DrawClip\n") ;
  int x_start=-100,x_end=-100,y_start=-100,y_end=-100 ;
  int x_sprite_start = x_num*x_size,
      y_sprite_start = y_num*y_size;
  if(log_file)fprintf(log_file,"   sprite_start(%3d;%3d)\n",x_sprite_start,y_sprite_start) ;
  int xx=x,yy=y;

  int x_right  = x+x_size,
      y_bottom = y+y_size ;

  if(x_right<=screen.left || y_bottom<=screen.top || x>=screen.right || y>=screen.bottom)
  {
    if(log_file)fprintf(log_file,"   can,t draw (out of screen)\n") ;
    return DD_OK ;
  }

  if(x<screen.left)xx=screen.left;
  if(y<screen.top)yy=screen.top;
  if(x>=screen.left && x+x_size<=screen.right && y>=screen.top && y+y_size<=screen.bottom)
  {
    x_start=x_sprite_start;
    x_end  =x_sprite_start+x_size;
    y_start=y_sprite_start;
    y_end  =y_sprite_start+y_size;
    if(log_file)fprintf(log_file,"   sprite in center start(%3d;%3d) end(%3d;%3d)\n",x_start,y_start,x_end,y_end) ;
  }
  else
  {
    //find by x
    if((y<=screen.top    && y+y_size>=screen.top)||     // 1.2.8. (y)
       (y>=screen.top    && y+y_size<=screen.bottom)||  // 3.7.   (y)
       (y<=screen.bottom && y+y_size>=screen.bottom))   // 4.5.6. (y)
    {
      //find x_start
      if(x>=screen.left && x<=screen.right)
        x_start = x_sprite_start ;
      else
      {
        int xx=x;
        if(x<0)xx*=-1;
        x_start = x_sprite_start+(screen.left+xx) ;
      } ;
      //find x_end
      if(x+x_size>=screen.left && x+x_size<=screen.right)
        x_end = x_sprite_start+x_size ;
      else
        x_end = x_sprite_start+(screen.right-x);
    };
    //find by y
    if((x<=screen.left  && x+x_size>=screen.left)||  // 1.2.8. (x)
       (x>=screen.left  && x+x_size<=screen.right)|| // 3.7.   (x)
       (x<=screen.right && x+x_size>=screen.right))  // 4.5.6. (x)
    {
      //find y_start
      if(y>=screen.top && y<=screen.bottom)
        y_start = y_sprite_start ;
      else
      {
        int yy=y;
        if(y<0)yy*=-1;
        y_start = y_sprite_start+(screen.top+yy) ;
      };
      //find y_end
      if(y+y_size>=screen.top && y+y_size<=screen.bottom)
        y_end = y_sprite_start+y_size ;
      else
        y_end = y_sprite_start+(screen.bottom-y) ;
    } ;
  };
  HRESULT res=DD_OK ;
  RECT srcRect ;
  SetRect(&srcRect,x_start,y_start,x_end,y_end) ;
  if(x_start>=0 && y_start>=0 && x_end>=0 && y_start>=0)
  {
    if(log_file)fprintf(log_file,"   try to draw\n") ;
    res = DDSSurface->BltFast(xx,yy,DDSSprite,&srcRect,DDBLTFAST_WAIT | DDBLTFAST_SRCCOLORKEY);
  };
  if(log_file)fprintf(log_file,"   try (%3d;%3d) to (%3d;%3d)\n",x,y,xx,yy) ;
  if(log_file)fprintf(log_file,"   start(%3d;%3d) end(%3d;%3d)\n",x_start,y_start,x_end,y_end) ;
  if(log_file)fprintf(log_file,"END   c_Sprite::DrawClip\n") ;
  return res ;
} ;
//---------------------------------------------------------------------------
#endif
