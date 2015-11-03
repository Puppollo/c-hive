#include <condefs.h>
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <stdlib.h>
#include "c_DDraw.h"
#include "c_SpriteList.h"
#include "c_Font.h"
#include "HiveMain.h"
//---------------------------------------------------------------------------
#define WINDOW_CLASS_NAME "WINCLASS1"
#define screen_WIDTH     640
#define screen_HEIGHT    480
#define screen_BITDEPTH  16
//---------------------------------------------------------------------------
const int particicle_DELAY = 1 ;

const int sprite_PARTICICLE_ID  = 0 ;
const int sprite_BUILDINGS_ID   = 1 ;
const int sprite_FONT_ID        = 2 ;

const int sprite_BUILDINGS_COUNT = 3 ;
//---------------------------------------------------------------------------
//SYSTEM---------------------------------------------------------------------
LRESULT CALLBACK WindowProc(HWND hwnd,UINT msg,WPARAM wparam,LPARAM lparam);
//---------------------
int app_run ;
HWND main_handle ;
HINSTANCE main_hinstance ;
FILE *log_file=NULL ;
c_DDraw *DDraw=NULL ;
HRESULT DDRestore() ;
void DDRelease() ;
void GameInit();                                                     // game init (load some resurce,init AI,etc.)
void GameMain();                                                     // main game function
void GameExit();                                                     // game shutdown (release some resurce)
void CheckError(HRESULT res,char *message);
RECT screen ;
HRESULT res;
//---------------------------------------------------------------------------
//supply
c_SpriteList *SpriteList=NULL ;
DWORD ThisTickCount,LastTickCount=0;
int current_x_screen,current_y_screen ;
int TIME ;
//---------------------------------------------------------------------------
//main
c_Particicle *particicle=NULL ;
c_World      *world=NULL ;
c_Font *font = NULL ;
//---------------------------------------------------------------------------
//###########################################################################
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hprevinstance,
                   LPSTR lpcmdline, int ncmdshow)
{
  WNDCLASSEX winclass ;
  HWND hwnd ;
  MSG msg ;
  winclass.cbSize=sizeof(WNDCLASSEX);
  winclass.style =CS_DBLCLKS|CS_OWNDC|CS_HREDRAW|CS_VREDRAW;
  winclass.lpfnWndProc = WindowProc;
  winclass.cbClsExtra=0;
  winclass.cbWndExtra=0;
  winclass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
  winclass.hCursor=LoadCursor(NULL,IDC_ARROW);
  winclass.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);
  winclass.lpszMenuName=NULL;
  winclass.lpszClassName=WINDOW_CLASS_NAME;
  winclass.hIconSm=LoadIcon(NULL,IDI_APPLICATION);
  if(!RegisterClassEx(&winclass))
    return(0);
  hwnd=CreateWindowEx(NULL,WINDOW_CLASS_NAME,
                      "TEMP DirectX project",
                      WS_POPUP|WS_VISIBLE,
                      0,0,     //- position
                      screen_HEIGHT,screen_WIDTH, //- size
                      NULL,NULL,hinstance,NULL);
  if(!hwnd)return(0);
  main_handle = hwnd ;
  main_hinstance = hinstance ;
  GameInit(); // INITIALIZING
  while(true)
  {
    if(PeekMessage(&msg,NULL,0,0,PM_REMOVE))
    {
      if(msg.message==WM_QUIT)break;
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    } ;
    GameMain(); // MAIN GAME FUNCTION
  } ;
  GameExit(); // RELEASE
  return(msg.wParam);
};
//---------------------------------------------------------------------------
LRESULT CALLBACK WindowProc(HWND hwnd,UINT msg,WPARAM wparam,LPARAM lparam)
{
  PAINTSTRUCT ps;
  HDC hdc;
  switch(msg)
  {
    case WM_CHAR ://ascii - wparam, key state - lparam
    {
      switch(wparam)
      {

        case 27:
                PostMessage(main_handle,WM_QUIT,0,0) ;  //if ESC is down
                app_run=0;
                break;
        case '8' :  //  MOVE MAP UP
          if(current_y_screen>0)current_y_screen-- ;
        break;
        case '2' :  //  MOVE MAP DOWN
          if(current_y_screen<world_Y_COUNT-screen_Y_CELL_COUNT)current_y_screen++ ;
        break;
        case '4' :  //  MOVE MAP LEFT
          if(current_x_screen>0)current_x_screen-- ;
        break;
        case '6' :  //  MOVE MAP RIGHT
          if(current_x_screen<world_X_COUNT-screen_X_CELL_COUNT)current_x_screen++ ;
        break ;
      } ;
      return 0;
    }break;
    case WM_CREATE :
    {
      return 0 ;
    }break ;
    case WM_PAINT  :
    {
      hdc=BeginPaint(hwnd,&ps) ;
      EndPaint(hwnd,&ps) ;
      return 0 ;
    }break ;
    case WM_DESTROY:
    {
      PostQuitMessage(0) ;
      app_run = 0;
      return 0 ;
    }break ;
    default:break;
  } ;//end switch
  return(DefWindowProc(hwnd,msg,wparam,lparam)) ;
};//end WinProc
//###########################################################################
//###########################################################################
HRESULT DDRestore()
{
  HRESULT res = DD_OK ;
  res = SpriteList->RestoreAll();
  return res;
} ;
void DDRelease()
{
  FILE *release_file=fopen("LOG\\release.log","w+") ;
  SpriteList->ReleaseAll(release_file) ;
  fclose(release_file) ;
} ;
//-----------------------------
void CheckError(HRESULT res,char *message)
{
  if(res!=DD_OK)
  {
    if(res==DDERR_SURFACELOST)DDraw->RestoreAll(log_file) ;
    else
    if(log_file)fprintf(log_file,"ERROR : %s\n",message) ;
    {
      FILE *error_log = fopen("LOG\\error.log","w+") ;
      DDOutErrorCode(error_log) ;
      fprintf(error_log,"current %u\n",res) ;
      fclose(error_log) ;
      app_run=0 ;
      PostMessage(main_handle,WM_QUIT,0,0);
    } ;
  };
} ;
//-----------------------------
void GameInit()
{
  app_run = 1 ;
  log_file = fopen("LOG\\debug.log","w+") ;
  if(log_file)fprintf(log_file,"GameInit\n") ;
  DDraw = new c_DDraw(main_handle,main_hinstance,&DDRestore,screen_WIDTH,screen_HEIGHT,screen_BITDEPTH) ;
  DDraw->Init(log_file);
  SetRect(&screen,0,0,screen_WIDTH-1,screen_HEIGHT-1) ;

  TIME =0 ;
  ThisTickCount=GetTickCount();
  LastTickCount=ThisTickCount;

  SpriteList = new c_SpriteList() ;
  SpriteList->Add(DDraw->DDraw,"art\\particicle.bmp",3,3,log_file) ;
  SpriteList->Add(DDraw->DDraw,"art\\buildings.bmp",sprite_BUILDINGS_COUNT,1,log_file) ;
  SpriteList->Add(DDraw->DDraw,"art\\font.bmp",font_STD_X_COUNT,font_STD_Y_COUNT,log_file) ;

  font = new c_Font(SpriteList->Find(sprite_FONT_ID)) ;

  current_x_screen=0;
  current_y_screen=0;

  world = new c_World(SpriteList->Find(sprite_BUILDINGS_ID)) ;
  (world->building[3][3]).type = building_type_MAIN ;
  (world->building[3][4]).type = building_type_MAIN ;
  (world->building[3][5]).type = building_type_MAIN ;
  (world->building[3][6]).type = building_type_MAIN ;
  (world->building[3][7]).type = building_type_MAIN ;
  (world->building[3][7]).type = building_type_MAIN ;
  (world->building[4][3]).type = building_type_MAIN ;
  (world->building[5][3]).type = building_type_MAIN ;
  (world->building[6][3]).type = building_type_MAIN ;
  (world->building[7][3]).type = building_type_MAIN ;
  (world->building[8][3]).type = building_type_MAIN ;

  (world->building[6][6]).type = building_type_NODE ;
  (world->building[6][6]).r = 50 ;
  (world->building[6][6]).param[0] = 2 ;
  (world->building[6][6]).param[1] = 0 ;
  (world->building[6][6]).param[2] = 1 ;
  (world->building[6][6]).param[3] = 51 ;

  s_ParticicleInfo PInfo ;
  PInfo.TurnTime = 1 ;
  PInfo.GenerateTime = 50 ;
  PInfo.TurnCount = 1000 ;
  PInfo.GenerateCountPerTurn = 1 ;
  PInfo.width = 10 ;
  PInfo.height = 10 ;
  PInfo.enable = 1 ;
  PInfo.dx = 0.5 ;
  PInfo.dy = 0.0 ;
  PInfo.dxVariation = 0 ;
  PInfo.dyVariation = 0 ;
  PInfo.x_frame_count = 3 ;
  PInfo.y_frame_count = 3 ;
  PInfo.ParticicleCount = 100 ;
  
  particicle = new c_Particicle(SpriteList->Find(sprite_PARTICICLE_ID),4,4,PInfo) ;
} ;
//-----------------------------
void GameExit()
{
  if(log_file)fprintf(log_file,"GameExit\n") ;
  if(log_file)fclose(log_file);
  DDraw->ReleaseAll(&DDRelease) ;
  if(particicle)particicle->Release() ;
  app_run= 0 ;
} ;
//-----------------------------
void GameMain()
{
  DDraw->FillSurface(DDraw->DDSBack,0) ;

  //turn
  ThisTickCount=GetTickCount();
  if(ThisTickCount-LastTickCount>particicle_DELAY)
  {
    LastTickCount=ThisTickCount ;
    particicle->Turn(TIME,world) ;
    TIME++;
    if(TIME>10000)TIME=0;
  } ;

  //drawind
  res=world->Draw(DDraw->DDSBack,current_x_screen,current_y_screen) ;
  CheckError(res,"world->Draw") ;
  res=particicle->Draw(screen,current_x_screen,current_y_screen,DDraw->DDSBack) ;
  CheckError(res,"particicle->Draw") ;

  //supply text out
  res = font->Draw(DDraw->DDSBack,current_x_screen,600,30) ;
  CheckError(res,"font->Draw") ;
  res = font->Draw(DDraw->DDSBack,current_y_screen,600,60) ;
  CheckError(res,"font->Draw") ;

  world->TIME++;
  if(world->TIME >= 10000)world->TIME=0 ;
  DDraw->FlipPage() ;
} ;
//---------------------------------------------------------------------------
