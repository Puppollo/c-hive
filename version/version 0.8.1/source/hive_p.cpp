#include <condefs.h>
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <stdlib.h>
#include <ddraw.h>

#include <c_DDraw.h>
#include <c_SpriteList.h>
#include <c_Font.h>
#include "c_HiveElement.h"
#include "HiveMain.h"
#include "HiveTerrain.h"
#include "c_HiveParticicleS.h"
#include "c_HiveParticicleC.h"
#include "c_HiveWorld.h"
#include "HiveButtonFunction.h"
//---------------------------------------------------------------------------
#define WINDOW_CLASS_NAME "WINCLASS1"
#define screen_WIDTH     640
#define screen_HEIGHT    480
#define screen_BITDEPTH  16
//---------------------------------------------------------------------------
const map_scroll_DELAY = 50 ;

const int game_DELAY = 1 ;

const int sprite_FONTBIG_ID     = 0 ;
const int sprite_PARTICICLE_ID  = 1 ;
const int sprite_BUILDINGS_ID   = 2 ;
const int sprite_BUTTONS_ID     = 3 ;
const int sprite_PANELS_ID      = 4 ;
const int sprite_FONTSMALL_ID   = 5 ;
const int sprite_TERRAIN_ID     = 6 ;

const int sprite_BUILDINGS_X_COUNT  =14 ;
const int sprite_BUILDINGS_Y_COUNT  = 7 ;
const int sprite_PARTICICLE_X_COUNT = 5 ;
const int sprite_PARTICICLE_Y_COUNT = 3 ;
const int sprite_BUTTONS_X_COUNT    =12 ;
const int sprite_BUTTONS_Y_COUNT    = 6 ;
const int sprite_PANELS_X_COUNT     = 3 ;
const int sprite_PANELS_Y_COUNT     = 1 ;
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
DWORD ThisTickCount,LastTickCount=0,MouseScrollTickCount=0;
int TIME ;
s_mouse mouse ;
c_Sprite *panels=NULL;
int player_ID ;
//---------------------------------------------------------------------------
//main
c_Particicle   *particicle   =NULL ;
c_World        *world        =NULL ;
c_Font         *font         =NULL ;
c_Font         *font_info    =NULL ;
c_HiveElements *HiveElements =NULL ;
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

    case WM_LBUTTONUP : // mouse left button down
    {
      mouse.x = (int)LOWORD(lparam) ;
      mouse.y = (int)HIWORD(lparam) ;
      mouse.button = mouse_LEFT ;
      int inPanel = mouse.x>common_panel_X && mouse.x<common_panel_X+192 && // 128 - panel width
                    mouse.y>common_panel_Y && mouse.y<common_panel_Y+64 ;   // 64 - panel height
      if((world->building[mouse.cell_x][mouse.cell_y]).type!=building_type_NO && inPanel==0)
      {
        HiveElements->action=action_BUILDING_CLICK ;
        HiveElements->param[0]=mouse.cell_x;
        HiveElements->param[1]=mouse.cell_y;
      } ;
      return 0 ;
    }break ;
    case WM_RBUTTONUP : // mouse right button down
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
      if((world->building[mouse.cell_x][mouse.cell_y]).type==building_type_NO &&
         (world->building[mouse.cell_x][mouse.cell_y]).territory[player_ID]==1 &&
         (world->building[mouse.cell_x][mouse.cell_y]).terrain.type==terrain_type_FULL_CLEAR_U)
        mouse.y_frame=building_y_frame_GOODPLACE;
      else
        mouse.y_frame=building_y_frame_BADPLACE;
     /* int button=(int)wparam ;
      if(button & MK_LBUTTON)
        mouse.button=mouse_LEFT ;
      else
      if(button & MK_RBUTTON)
        mouse.button=mouse_RIGHT ;*/
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
        case '8' :  //  MOVE MAP UP
          MoveMap((world->player[player_ID]).current_x_screen,(world->player[player_ID]).current_y_screen,0,-1);
        break;
        case '2' :  //  MOVE MAP DOWN
          MoveMap((world->player[player_ID]).current_x_screen,(world->player[player_ID]).current_y_screen,0,1);
        break;
        case '4' :  //  MOVE MAP LEFT
          MoveMap((world->player[player_ID]).current_x_screen,(world->player[player_ID]).current_y_screen,-1,0);
        break;
        case '6' :  //  MOVE MAP RIGHT
          MoveMap((world->player[player_ID]).current_x_screen,(world->player[player_ID]).current_y_screen,1,0);
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
  SpriteList->Add(DDraw->DDraw,"art\\fontBig.bmp",font_STD_X_COUNT,font_STD_Y_COUNT,log_file) ;                     // 0
  SpriteList->Add(DDraw->DDraw,"art\\particicle.bmp",sprite_PARTICICLE_X_COUNT,sprite_PARTICICLE_Y_COUNT,log_file) ;// 1
  SpriteList->Add(DDraw->DDraw,"art\\buildings.bmp",sprite_BUILDINGS_X_COUNT,sprite_BUILDINGS_Y_COUNT,log_file) ;   // 2
  SpriteList->Add(DDraw->DDraw,"art\\buttons.bmp",sprite_BUTTONS_X_COUNT,sprite_BUTTONS_Y_COUNT,log_file) ;         // 3
  SpriteList->Add(DDraw->DDraw,"art\\panels.bmp",sprite_PANELS_X_COUNT,sprite_PANELS_Y_COUNT,log_file) ;            // 4
  SpriteList->Add(DDraw->DDraw,"art\\fontSmall.bmp",font_STD_X_COUNT,font_STD_Y_COUNT*3,log_file) ;                 // 5
  SpriteList->Add(DDraw->DDraw,"art\\terrain.bmp",sprite_TERRAIN_X_FRAME_COUNT,sprite_TERRAIN_Y_FRAME_COUNT*terrain_H_COUNT,log_file) ;         // 6 

  font = new c_Font(SpriteList->Find(sprite_FONTBIG_ID)) ;
  font_info = new c_Font(SpriteList->Find(sprite_FONTSMALL_ID),3) ;
  panels = SpriteList->Find(sprite_PANELS_ID) ;

  player_ID = 0 ;

  mouse.x=1;
  mouse.y=1;
  mouse.sprite=SpriteList->Find(sprite_BUILDINGS_ID);
  mouse.x_frame = building_type_SELECT ;
  mouse.y_frame=building_y_frame_GOODPLACE;

  world = new c_World(SpriteList->Find(sprite_BUILDINGS_ID),
                      SpriteList->Find(sprite_PARTICICLE_ID),
                      SpriteList->Find(sprite_TERRAIN_ID),1,1) ;
  (world->player[player_ID]).current_x_screen=20;
  (world->player[player_ID]).current_y_screen=20;
  FILE *map_file=fopen("MAP\\map1.lnd","r") ;
  if(map_file)
  {
    world->MapEditINIT() ;
    world->LoadLandscape(map_file) ;
  } ;
  world->SetBuilding(25,25,building_type_BASE,player_ID) ;
  world->SetBuilding(30,30,building_type_MAIN,player_ID) ;
  fclose(map_file) ;

  HiveElements = new c_HiveElements(world,&mouse,SpriteList->Find(sprite_BUTTONS_ID),
                                    common_panel_X,common_panel_Y,
                                    SpriteList->Find(sprite_FONTSMALL_ID),player_ID) ;
} ;
//-----------------------------
void GameExit()
{
  if(log_file)fprintf(log_file,"GameExit\n") ;
  DDraw->ReleaseAll(&DDRelease) ;
  if(HiveElements) HiveElements->Release(log_file) ;
  if(world)        world->Release(log_file) ;
  app_run= 0 ;
  if(log_file)fclose(log_file);
} ;
//-----------------------------
void GameMain()
{
  DDraw->FillSurface(DDraw->DDSBack,0) ;

  //turn
  HiveElements->CheckAction() ;
  HiveElements->Turn(0) ;
  ThisTickCount=GetTickCount();
  if(ThisTickCount-LastTickCount>game_DELAY)
  {
    LastTickCount=ThisTickCount ;
    world->Turn() ;
  } ;
  mouse.button = mouse_button_NO ;
  //map scroll
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
  res=panels->Draw(DDraw->DDSBack,common_panel_X,common_panel_Y,0,0) ;     //
  CheckError(res,"panels->Draw") ;                                         //
  res=panels->Draw(DDraw->DDSBack,common_panel_X+64,common_panel_Y,1,0) ;  //  DRAW
  CheckError(res,"panels->Draw") ;                                         //  PANELS
  res=panels->Draw(DDraw->DDSBack,common_panel_X+128,common_panel_Y,2,0) ; //
  CheckError(res,"panels->Draw") ;                                         //
  res=HiveElements->Draw(screen,DDraw->DDSBack) ; // draw buttons
  CheckError(res,"HiveElements->Draw") ;
  //game supply information out
  res=font_info->Draw(DDraw->DDSBack,mouse.cell_x,font_info_COORDX_X,font_info_COORDX_Y,1) ;
  CheckError(res,"font->Draw") ;
  res=font_info->Draw(DDraw->DDSBack,mouse.cell_y,font_info_COORDY_X,font_info_COORDY_Y,1) ;
  CheckError(res,"font->Draw") ;
  res=font_info->Draw(DDraw->DDSBack,world->CYCLE,font_info_CYCLE_X,font_info_CYCLE_Y,1) ;
  CheckError(res,"font->Draw") ;
  res=font_info->Draw(DDraw->DDSBack,((world->building[mouse.cell_x][mouse.cell_y]).terrain.type),font_info_H_X,font_info_H_Y,1) ;
  CheckError(res,"font->Draw") ;
  //supply text out
  res = font->Draw(DDraw->DDSBack,world->TIME,600,1) ;
  CheckError(res,"font->Draw") ;
  res = font->Draw(DDraw->DDSBack,(world->player[player_ID]).current_x_screen,600,30) ;
  CheckError(res,"font->Draw") ;
  res = font->Draw(DDraw->DDSBack,(world->player[player_ID]).current_y_screen,600,60) ;
  CheckError(res,"font->Draw") ;
  //other
  DDraw->FlipPage() ;
} ;
//---------------------------------------------------------------------------


