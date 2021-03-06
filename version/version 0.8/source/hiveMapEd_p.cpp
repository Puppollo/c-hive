#include <condefs.h>
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <stdlib.h>
#include <ddraw.h>

#include <c_DDraw.h>
#include <c_SpriteList.h>
#include <c_Font.h>
#include "HiveMain.h"
#include "HiveMapEditMain.h"
#include "HiveTerrain.h"
#include "c_HiveWorld.h"
//---------------------------------------------------------------------------
#define WINDOW_CLASS_NAME "WINCLASS1"
#define screen_WIDTH     640
#define screen_HEIGHT    480
#define screen_BITDEPTH  16
//---------------------------------------------------------------------------
const map_scroll_DELAY = 50 ;

const int sprite_FONTSMALL_ID   = 0 ;
const int sprite_TERRAIN_ID     = 1 ;
const int sprite_BUILDINGS_ID   = 2 ;


const int sprite_BUILDINGS_X_COUNT  =14 ;
const int sprite_BUILDINGS_Y_COUNT  = 7 ;
const int sprite_TERRAIN_X_COUNT    =12;
const int sprite_TERRAIN_Y_COUNT    = 4 ;
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
DWORD ThisTickCount,LastTickCount=0,MouseScrollTickCount=0;
s_mouse mouse ;
int player_ID ;
int TIME ;
//---------------------------------------------------------------------------
//main
c_Font         *font_info    =NULL ;
c_World        *world=NULL ;
s_EditInfo     EditInfo ;
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
                      "THE HIVE",
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

    case WM_LBUTTONDOWN : // mouse left button down
    {
      mouse.x = (int)LOWORD(lparam) ;
      mouse.y = (int)HIWORD(lparam) ;
      mouse.button = mouse_LEFT ;
      return 0 ;
    }break ;
    case WM_RBUTTONDOWN : // mouse right button down
    {
      mouse.x = (int)LOWORD(lparam) ;
      mouse.y = (int)HIWORD(lparam) ;
      mouse.button = mouse_RIGHT ;
    }return 0;break ;
    case WM_MOUSEMOVE :
    {
      mouse.x = (int)LOWORD(lparam) ;
      mouse.y = (int)HIWORD(lparam) ;
      mouse.cell_x = (mouse.x>>5)+(world->player[player_ID]).current_x_screen ;
      mouse.cell_y = (mouse.y>>5)+(world->player[player_ID]).current_y_screen ;
      int button=(int)wparam ;
      if(button & MK_RBUTTON)mouse.button=mouse_RIGHT ;
      if(button & MK_LBUTTON)mouse.button=mouse_LEFT ;
    } ;
    return 0;break;
    case WM_CHAR ://ascii - wparam, key state - lparam
    {
      switch(wparam)
      {

        case 27:
                PostMessage(main_handle,WM_QUIT,0,0) ;  //if ESC is down
                app_run=0;
                break;
        case 's' : // save map
        {
          FILE *save_file = fopen("MAP\\new_map.ldp","w+") ;
          world->SaveLandscape(save_file) ;
          fclose(save_file) ;
        } ;
        break;
        case 'l' : // load map
        {
          FILE *load_file = fopen("MAP\\new_map.ldp","r") ;
          if(load_file)world->LoadLandscape(load_file) ;
          fclose(load_file) ;
        } ;
        break;
        case ']' : // next player
          if(EditInfo.current_player<(world->GetPlayerCount()-1))
            EditInfo.current_player++;
        break;
        case '[' : // prev player
          if(EditInfo.current_player>0)
            EditInfo.current_player-- ;
        break;
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
  randomize() ;
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
  SpriteList->Add(DDraw->DDraw,"art\\fontSmall.bmp",font_STD_X_COUNT,font_STD_Y_COUNT*3,log_file) ;                 // 0
  SpriteList->Add(DDraw->DDraw,"art\\terrain.bmp",sprite_TERRAIN_X_COUNT,sprite_TERRAIN_Y_COUNT,log_file) ;         // 1 
  SpriteList->Add(DDraw->DDraw,"art\\buildings.bmp",sprite_BUILDINGS_X_COUNT,sprite_BUILDINGS_Y_COUNT,log_file) ;   // 2

  font_info = new c_Font(SpriteList->Find(sprite_FONTSMALL_ID),3) ;

  player_ID = 0 ;

  mouse.x=1;
  mouse.y=1;
  mouse.sprite=SpriteList->Find(sprite_BUILDINGS_ID);
  mouse.x_frame = building_type_SELECT ;
  mouse.y_frame = building_y_frame_GOODPLACE;

  world = new c_World(SpriteList->Find(sprite_BUILDINGS_ID),
                      NULL,
                      SpriteList->Find(sprite_TERRAIN_ID),2,0) ;
  (world->player[player_ID]).current_x_screen=0;
  (world->player[player_ID]).current_y_screen=0;
  world->MapEditINIT() ;

  EditInfo.current_player = 0 ;
  EditInfo.current_building_type = building_type_NO ;
} ;
//-----------------------------
void GameExit()
{
  if(log_file)fprintf(log_file,"GameExit\n") ;
  DDraw->ReleaseAll(&DDRelease) ;
  if(world)        world->Release(log_file) ;
  app_run= 0 ;
  if(log_file)fclose(log_file);
} ;
//-----------------------------
void GameMain()
{
  DDraw->FillSurface(DDraw->DDSBack,0) ;

  //turn
  CheckAction(mouse,EditInfo,world) ;
  mouse.button = mouse_NO ;
  //map scroll
  ThisTickCount = GetTickCount() ;
  if(ThisTickCount-MouseScrollTickCount>map_scroll_DELAY)
  {
    MouseScrollTickCount=ThisTickCount ;
    MoveMapByMouse(mouse.x,mouse.y,
                   (world->player[player_ID]).current_x_screen,(world->player[player_ID]).current_y_screen,
                   screen_HEIGHT,screen_WIDTH) ;
  } ;
  //drawind
  res=world->Draw(player_ID,screen,DDraw->DDSBack) ; // draw world
  CheckError(res,"world->Draw") ;
  if(mouse.x_frame>=0&&mouse.y_frame>=0)                                                                  //
  {                                                                                                       //  Draw
    res=(mouse.sprite)->Draw(DDraw->DDSBack,(mouse.x>>5)<<5,(mouse.y>>5)<<5,mouse.x_frame,mouse.y_frame) ;//  mouse
    CheckError(res,"mouse->Draw") ;                                                                       //
  } ;                                                                                                     //
  //game supply information out
  res=font_info->Draw(DDraw->DDSBack,mouse.cell_x,font_info_COORDX_X,font_info_COORDX_Y,1) ;
  CheckError(res,"font->Draw") ;
  res=font_info->Draw(DDraw->DDSBack,mouse.cell_y,font_info_COORDY_X,font_info_COORDY_Y,1) ;
  CheckError(res,"font->Draw") ;
  res=font_info->Draw(DDraw->DDSBack,world->CYCLE,font_info_CYCLE_X,font_info_CYCLE_Y,1) ;
  CheckError(res,"font->Draw") ;
  res=font_info->Draw(DDraw->DDSBack,((world->building[mouse.cell_x][mouse.cell_y]).terrain.type),font_info_H_X,font_info_H_Y,1) ;
  CheckError(res,"font->Draw") ;

  res=font_info->Draw(DDraw->DDSBack,EditInfo.current_player,font_EditInfo_X,font_EditInfo_Y,2) ;
  CheckError(res,"font->Draw") ;
  res=font_info->Draw(DDraw->DDSBack,EditInfo.current_building_type,font_EditInfo_X,font_EditInfo_Y+20,2) ;
  CheckError(res,"font->Draw") ;
  //... EditInfo out
  //other
  DDraw->FlipPage() ;
} ;
//---------------------------------------------------------------------------


