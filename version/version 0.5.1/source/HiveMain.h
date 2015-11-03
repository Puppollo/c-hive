#ifndef HiveMainH
#define HiveMainH
//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <ddraw.h>
#include "c_DDraw.h"
#include "c_grObject.h"

#define sqr(x) ((x)*(x))
//---------------------------------------------------------------------------
const int   particicle_MAX_COUNT =500 ;
const float particicle_d_MIN = -10 ;
const float particicle_d_MAX =  10 ;

const int particicle_GENERATE_TIME =100;
const int particicle_TIMETOTURN = 2 ;
/////////////
const int particicle_type_SUPPLY_EMPTY   = 0 ;
const int particicle_type_SUPPLY_MINERAL = 1 ;
const int particicle_type_SUPPLY_ENERGY  = 2 ;

const int particicle_combat_type_IMPACTOR = 0 ;
const int particicle_combat_type_CHAOSGUN = 1 ;
//...
/////////////
const int build_panel_X =0;
const int build_panel_Y =415;
const int common_panel_X=65;
const int common_panel_Y=415;
/////////////
const int player_buildings_COUNT = 6 ;
const int player_buildings_NODE    = 0 ;
const int player_buildings_FACTORY = 1 ;
const int player_buildings_MINE    = 2 ;
const int player_buildings_CHARGE  = 3 ;
const int player_buildings_SPEED   = 4 ;
const int player_buildings_POWER   = 5 ;
/////////////
const int building_type_NO           =-1 ;
const int building_type_MAIN         = 0 ;  // ���� (������ ������)
const int building_type_NODE         = 1 ;  // ����
const int building_type_FACTORY      = 2 ;  // �����
const int building_type_MINE         = 3 ;  // �����
const int building_type_SPEED        = 4 ;  // ����������
const int building_type_CHARGE       = 5 ;  // �����������
const int building_type_POWER        = 6 ; // �������������
const int building_type_BUILDPLACE   = 7 ;  // ������ ���������
const int building_type_CONSTRUCTING = 8 ;  // �������
const int building_type_SELECT       = 9 ;  // ������ ������
const int building_type_BASE         = 10 ; // ����
const int building_type_MINERAL      = 11 ; // ������������� ���������
/////////////
const int building_owner_NEUTRAL = -1 ;
/////////////
const int building_y_frame_GOODPLACE = 0 ;
const int building_y_frame_BADPLACE  = 1 ;
const int building_y_frame_NODE_NO   = 0;
const int building_y_frame_NODE_U    = 1;
const int building_y_frame_NODE_UR   = 2;
const int building_y_frame_NODE_R    = 3;
const int building_y_frame_NODE_DR   = 4;
const int building_y_frame_NODE_D    = 5;
const int building_y_frame_NODE_DL   = 6;
const int building_y_frame_NODE_L    = 7;
const int building_y_frame_NODE_UL   = 8;
/////////////
const int building_NODE_WORK_RANGE       = 10 ;                     // ������ ������ ������ �����
const int building_NODE_RANGE            = 50 ;                     // ������ ������� ������� ������
const int building_NODE_SKIPENABLE_COUNT = building_NODE_RANGE+20 ; // ������������ ����������� ������� ������
const int building_SPEED_RESURCE_REDUCED = 10 ; // ������� ���������� ��� ��������� ����� �������
const int building_CHARGE_RESURCE_REDUCED = 25 ;// ������� ���������� ��� ����������� ����� �������
/////////////
const int building_territory_ADD_COUNT = 4 ; // ���-�� ������ ���������� � ���������� ������ ������ ������
const int building_territory_FRAME_X = 7 ;
const int building_territory_FRAME_Y = 2 ;
/////////////
const int building_CELL_FRAME_X = 9 ;
const int building_CELL_FRAME_Y = 2 ;
/////////////
const int building_FACTORY_BUILD_TIME = 1000 ; // ���-�� ����� ��� ��������� ������
const int building_MINE_BUILD_TIME    = 1500 ; // ���-�� ����� ��� ��������� �����
const int building_CHARGE_BUILD_TIME  = 2000 ; // ���-�� ����� ��� ��������� ���������
const int building_SPEED_BUILD_TIME   = 500 ;  // ���-�� ����� ��� ��������� ����������
const int building_POWER_BUILD_TIME   = 1000 ; // ���-�� ����� ��� ��������� ��������������
/////////////
const int building_exit_coord_X = 1 ; // X ���������� ����������� ������� �� ������
const int building_exit_coord_Y = 1 ; // Y ���������� ����������� ������� �� ������
/////////////
const int building_CONSTRUCTING_ENERGY_REDUCED=3; // ���-�� ������� ������� �������� �� �������������
const int building_FACTORY_ENERGY_REDUCED     =5; // ���-�� ������� ������� �������� �� ������������
const int building_MINE_ENERGY_REDUCED        =2; // ���-�� ������� ������� �������� �� ������ ���������
const int building_POWER_ENERGY_REDUCED       =10;// ���-�� ������� ������� �������� �� ������ �������
const int building_BASE_ENERGY_REDUCED        =6; // ���-�� ������� ������� �������� �� ����
/////////////
const int building_MINERAL_HP = 10 ;
const int building_NODE_HP = 250 ;
const int building_FACTORY_HP = 2000 ;
const int building_MINE_HP = 1000 ;
const int building_SPEED_HP = 500 ;
const int building_CHARGE_HP = 1000 ;
const int building_MAIN_HP = 100 ;
const int building_BASE_HP = 10000;
const int building_CONSTRUCTING_HP = 500 ;
const int building_POWER_HP = 1000 ;
/////////////
const int resurce_NODE_PRICE    = 100  ; // ���� ��������� ��������� �����
const int resurce_FACTORY_PRICE = 500  ; // ���� ��������� ��������� ������
const int resurce_MINE_PRICE    = 1000 ; // ���� ��������� ��������� �����
const int resurce_SPEED_PRICE   = 200  ; // ���� ��������� ��������� ����������
const int resurce_CHARGE_PRICE  = 800  ; // ���� ��������� ��������� ���������
const int resurce_POWER_PRICE   = 500  ; // ���� ��������� ��������� ��������������
//...
/////////////
const int unit_type_STD = 0 ;
/////////////
const int world_X_COUNT = 256 ;
const int world_Y_COUNT = 256 ;

const int world_MAX_SUPPLY_COUNT = 50 ;             // ����������� ��������� ����� ����������� ������ ���� c_Particicle
const int world_MAX_SUPPLY_PARTICICLE_COUNT = 100 ; // ����������� ��������� ����� ������ ����������� ����������� c_Particicle
const int world_MINERAL_SIZE = 1 ;                  // ������ ����������� ����
const int world_MINERAL_RANDOM = 2 ;                // ����������� ���� ��� � ������ ������������� �������
const int world_MINERAL_PARAM = 500 ;               // ������� �������� ��������� param[0] ���� building_type_MINERAL
const int world_MINERAL_PARAM_VARIATION = 450 ;     // 500 +- 450
/////////////
const int screen_X_CELL_SIZE = 32 ; // 2^5
const int screen_Y_CELL_SIZE = 32 ;
const int screen_X_CELL_COUNT = 20 ; //640/32
const int screen_Y_CELL_COUNT = 15 ; //480/32
const int screen_X_CELL_CENTER = 16 ;
const int screen_Y_CELL_CENTER = 16 ;
/////////////
const int MAX_RANGE = 2 ; // ���-�� ������ ������� "�����������" ������� ������ ����
const int mouse_LEFT  = 1 ;
const int mouse_RIGHT = 2 ;
//---------------------------------------------------------------------------
void MoveTo(float src_x,float src_y,long dst_x,long dst_y,float &dx,float &dy,FILE *log_file=NULL) ;
//void MoveFrom(int &src_x,int &src_y,int dst_x,int dst_y,FILE *log_file=NULL) ;
int  inRange(long x,long y,long x0,long y0,int r,FILE *log_file=NULL) ;
void MoveMap(int &current_x_screen,int &current_y_screen,int dx,int dy) ;
void MoveMapByMouse(int mouse_x,int mouse_y,int &current_x_screen,int &current_y_screen,int screen_HEIGHT,int screen_WIDTH) ;
//---------------------------------------------------------------------------
struct s_mouse
{
  int x,y ;
  int cell_x,cell_y ;
  int button ;
  c_Sprite *sprite ;
  int x_frame,y_frame ;
} ;
//---------------------------------------------------------------------------
const int building_param_COUNT = 7;
struct s_building
{
  int r ;
  int y_frame ;      // animation or type
  int type ;         // ��� ������ (x_frame)
  float param[building_param_COUNT] ;
  int owner ;            // �������������� ������-���� ������
  int enable;
  int HP ,maxHP;
  int *territory ; // ������ ������������ �����-�� ������� ������
  int draw_flag ;
} ;
//---------------------------------------------------------------------------
struct s_Player
{
  int show_territory, // ������������ ����������
      show_grid ;     // ������������ �����
  int ID ;
  int current_x_screen,current_y_screen ;
  int buildings_count[player_buildings_COUNT];
  int supply_carring_count ; // ���-�� ���� ������������ ��������
  //...
} ;
//---------------------------------------------------------------------------
int inRange(long x,long y,long x0,long y0,int r,FILE *log_file)
{
  long by_x = sqr(x-x0) ;
  long by_y = sqr(y-y0) ;
  int res = by_x+by_y<sqr(r) ;
  if(log_file)(log_file,"  inRange(%d,%d,%d,%d,%d) %d\n",x,y,x0,y0,res) ;
  return res ;
} ;
void MoveTo(float src_x,float src_y,long dst_x,long dst_y,float &dx,float &dy,FILE *log_file)
{
  if(src_x<dst_x)      dx=2.0;
  else if(src_x>dst_x) dx=-2.0;
  else                 dx=0.0;
  if(src_y<dst_y)      dy=2.0;
  else if(src_y>dst_y) dy=-2.0;
  else                 dy=0.0;
} ;
/*
void MoveFrom(int &src_x,int &src_y,int dst_x,int dst_y)
{
  if(src_x<dst_x)src_x--;
  else if(src_x>dst_x)src_x++ ;
  if(src_y<dst_y)src_y--;
  else if(src_y>dst_y)src_y++ ;
} ;
*/
void MoveMap(int &current_x_screen,int &current_y_screen,int dx,int dy)
{
  if(dx<0)
  {if(current_x_screen>0)current_x_screen--;}
  else
  if(dx>0)
  {if(current_x_screen<world_X_COUNT-screen_X_CELL_COUNT)current_x_screen++;};
  if(dy<0)
  {if(current_y_screen>0)current_y_screen-- ;}
  else
  if(dy>0)
  {if(current_y_screen<world_Y_COUNT-screen_Y_CELL_COUNT)current_y_screen++;};
} ;
void MoveMapByMouse(int mouse_x,int mouse_y,int &current_x_screen,int &current_y_screen,int screen_HEIGHT,int screen_WIDTH)
{
  if(mouse_x>=0 && mouse_x<=10)
  {
    if(mouse_y>=0 && mouse_y<=10)
      MoveMap(current_x_screen,current_y_screen,-1,-1);
    else
    if(mouse_y>=screen_HEIGHT-10 && mouse_y<=screen_HEIGHT)
      MoveMap(current_x_screen,current_y_screen,-1,1);
    else
      MoveMap(current_x_screen,current_y_screen,-1,0);
  }
  else
  if(mouse_x>=screen_WIDTH-10 && mouse_x<=screen_WIDTH)
  {
    if(mouse_y>=0 && mouse_y<=10)
      MoveMap(current_x_screen,current_y_screen,1,-1);
    else
    if(mouse_y>=screen_HEIGHT-10 && mouse_y<=screen_HEIGHT)
      MoveMap(current_x_screen,current_y_screen,1,1);
    else
      MoveMap(current_x_screen,current_y_screen,1,0);
  }
  else
  {
    if(mouse_y>=0 && mouse_y<=10)
      MoveMap(current_x_screen,current_y_screen,0,-1);
    else
    if(mouse_y>=screen_HEIGHT-10 && mouse_y<=screen_HEIGHT)
      MoveMap(current_x_screen,current_y_screen,0,1);
  } ;
} ;
//------------------------------------------------------------------------------
#endif
