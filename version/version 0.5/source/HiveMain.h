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
const int building_type_MAIN         = 0 ;  // ядро (выпуск частиц)
const int building_type_NODE         = 1 ;  // маяк
const int building_type_FACTORY      = 2 ;  // завод
const int building_type_MINE         = 3 ;  // шахта
const int building_type_SPEED        = 4 ;  // ускоритель
const int building_type_CHARGE       = 5 ;  // перезарядка
const int building_type_POWER        = 6 ; // энергостанция
const int building_type_BUILDPLACE   = 7 ;  // маркер постройки
const int building_type_CONSTRUCTING = 8 ;  // стройка
const int building_type_SELECT       = 9 ;  // маркер выбора
const int building_type_BASE         = 10 ; // база
const int building_type_MINERAL      = 11 ; // месторождение минералов
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
const int building_NODE_WORK_RANGE       = 10 ;                     // радиус начала работы маяка
const int building_NODE_RANGE            = 50 ;                     // радиус захвата частицы маяком
const int building_NODE_SKIPENABLE_COUNT = building_NODE_RANGE+20 ; // длительность перемещения частицы маяком
const int building_SPEED_RESURCE_REDUCED = 10 ; // ресурсы необходимы для ускорения одной частицы
const int building_CHARGE_RESURCE_REDUCED = 25 ;// ресурсы необходимы для перезарядки одной частицы
/////////////
const int building_territory_ADD_COUNT = 4 ; // кол-во клеток добавляемы к территории игрока вокруг здания
const int building_territory_FRAME_X = 7 ;
const int building_territory_FRAME_Y = 2 ;
/////////////
const int building_CELL_FRAME_X = 9 ;
const int building_CELL_FRAME_Y = 2 ;
/////////////
const int building_FACTORY_BUILD_TIME = 1000 ; // кол-во ходов для постройки завода
const int building_MINE_BUILD_TIME    = 1500 ; // кол-во ходов для постройки шахты
const int building_CHARGE_BUILD_TIME  = 2000 ; // кол-во ходов для постройки зарядника
const int building_SPEED_BUILD_TIME   = 500 ;  // кол-во ходов для постройки ускорителя
const int building_POWER_BUILD_TIME   = 1000 ; // кол-во ходов для постройки электростанции
/////////////
const int building_exit_coord_X = 1 ; // X координата перемещения частицы из здания
const int building_exit_coord_Y = 1 ; // Y координата перемещения частицы из здания
/////////////
const int building_CONSTRUCTING_ENERGY_REDUCED=3; // кол-во энергии частицы уходящей на строительство
const int building_FACTORY_ENERGY_REDUCED     =5; // кол-во энергии частицы уходящей на производство
const int building_MINE_ENERGY_REDUCED        =2; // кол-во энергии частицы уходящей на добычу минералов
const int building_POWER_ENERGY_REDUCED       =10;// кол-во энергии частицы уходящей на добычу энергии
const int building_BASE_ENERGY_REDUCED        =6; // кол-во энергии частицы уходящей на базе
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
const int resurce_NODE_PRICE    = 100  ; // цена постройки прототипа маяка
const int resurce_FACTORY_PRICE = 500  ; // цена постройки прототипа завода
const int resurce_MINE_PRICE    = 1000 ; // цена постройки прототипа шахты
const int resurce_SPEED_PRICE   = 200  ; // цена постройки прототипа ускорителя
const int resurce_CHARGE_PRICE  = 800  ; // цена постройки прототипа зарядника
const int resurce_POWER_PRICE   = 500  ; // цена постройки прототипа электростнации
//...
/////////////
const int unit_type_STD = 0 ;
/////////////
const int world_X_COUNT = 256 ;
const int world_Y_COUNT = 256 ;

const int world_MAX_SUPPLY_COUNT = 50 ; // максимально возможное число генераторов частиц типа c_Particicle
/////////////
const int screen_X_CELL_SIZE = 32 ; // 2^5
const int screen_Y_CELL_SIZE = 32 ;
const int screen_X_CELL_COUNT = 20 ; //640/32
const int screen_Y_CELL_COUNT = 15 ; //480/32
const int screen_X_CELL_CENTER = 16 ;
const int screen_Y_CELL_CENTER = 16 ;
/////////////
const int MAX_RANGE = 2 ; // кол-во клеток которые "осматривает" частица вокруг себя
const int mouse_LEFT  = 1 ;
const int mouse_RIGHT = 2 ;
//---------------------------------------------------------------------------
void MoveTo(float &src_x,float &src_y,int dst_x,int dst_y) ;
void MoveFrom(int &src_x,int &src_y,int dst_x,int dst_y) ;
int  inRange(int x,int y,int x0,int y0,int r) ;
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
  int type ;         // тип здания (x_frame)
  float param[building_param_COUNT] ;
  int owner ;            // принадлежность какому-либо игроку
  int enable;
  int HP ,maxHP;
  int *territory ; // массив определяющий можно-ли строить здания
  int draw_flag ;
} ;
//---------------------------------------------------------------------------
struct s_Player
{
  int show_territory, // отрисовывать территорию
      show_grid ;     // отрисовывать сетку
  int ID ;
  int current_x_screen,current_y_screen ;
  int buildings_count[player_buildings_COUNT];
  int supply_carring_count ; // кол-во веса переносимого частицей
  //...
} ;
//---------------------------------------------------------------------------
class c_World:public c_grObject
{
  private :
    int player_count ;
    int particicle_supply_count ;
  public :
    int TIME ;
    s_Player *player;
    c_Particicle (*ParticicleSupply)[world_MAX_SUPPLY_COUNT] ;
    s_building building[world_X_COUNT][world_Y_COUNT] ;

    c_World(c_Sprite *s,int p_count=1,int p_supply_count=1) ;
    HRESULT Draw(int player_ID,IDirectDrawSurface *DDSSurface,FILE *log_file=NULL) ;
    void Turn(FILE *log_file=NULL) ;
    void Release(FILE *log_file) ;
    void SetBuilding(int x,int y,int type,int player_ID) ;
} ;
//---------------------------------------------------------------------------
c_World::c_World(c_Sprite *s,int pc,int p_supply_count)
:c_grObject(s,0,0)
{
  player_count=p_count ;
  player = new s_Player[player_count] ;
  for(int p=0;p<player_count;p++)
    for(int bc=0;bc<player_buildings_COUNT;bc++)
      player[p].buildings_count[bc]=50;
  for(int p=0;p<player_count;p++)
  {
    player[p].ID = pc ;
    player[p].show_territory=0;
    player[p].show_grid=0;
    player[p].supply_carring_count=5 ;
  } ;
  TIME = 0 ;
  particicle_supply_count = p_supply_count;
  for(int x=0;x<world_X_COUNT;x++)
    for(int y=0;y<world_Y_COUNT;y++)
    {
      building[x][y].enable=1;
      building[x][y].type = building_type_NO ;
      building[x][y].y_frame=0 ;
      building[x][y].r = 0 ;
      building[x][y].owner = building_owner_NEUTRAL ;
      building[x][y].draw_flag = 0;
      building[x][y].territory = new int[player_count] ;
      building[x][y].HP=1;
      building[x][y].maxHP=1;
      for(int p=0;p<player_count;p++)
        building[x][y].territory[p]=building_owner_NEUTRAL ;
      for(int p=0;p<building_param_COUNT;p++)
        building[x][y].param[p]=1 ;
    } ;
} ;
//---------------------------------------------------------------------------
void c_World::SetBuilding(int x,int y,int type,int player_ID)
{
  building[x][y].type = type ;
  switch(type)
  {
    case building_type_MAIN :
      building[x][y].HP = building_MAIN_HP ;
      building[x][y].maxHP = building_MAIN_HP ;
    break;
    case building_type_BASE :
      building[x][y].HP = building_BASE_HP ;
      building[x][y].maxHP = building_BASE_HP ;
      building[x][y].param[4]=0;
      building[x][y].param[5]=0;
      building[x][y].owner=player_ID ;
      building[x][y].enable=1;
    break;
    case building_type_MINERAL :
      building[x][y].HP = building_MINERAL_HP ;
      building[x][y].maxHP = building_MINERAL_HP ;
      building[x][y].param[0]=10000;
    break;
  } ;
} ;
//---------------------------------------------------------------------------
void c_World::Release(FILE *log_file)
{
  if(log_file)fprintf(log_file,"START c_World::Release\n") ;
  if(log_file)fprintf(log_file,"   releasing...\n");
  delete []player ;
  for(int x=0;x<world_X_COUNT;x++)
    for(int y=0;y<world_Y_COUNT;y++)
      delete [](building[x][y].territory);
  if(log_file)fprintf(log_file,"   release complete\n");
  if(log_file)fprintf(log_file,"END   c_World::Release\n") ;
} ;
//---------------------------------------------------------------------------
HRESULT c_World::Draw(int player_ID,IDirectDrawSurface *DDSSurface,FILE *log_file)
{
  HRESULT res;
  int current_x=(player[player_ID]).current_x_screen,current_y=(player[player_ID]).current_y_screen ;
  int x_start_map = current_x ,
      y_start_map = current_y ,
      x_end_map = current_x+screen_X_CELL_COUNT ,
      y_end_map = current_y+screen_Y_CELL_COUNT ;
  for(int x=x_start_map;x<x_end_map;x++)
    for(int y=y_start_map;y<y_end_map;y++)
    {
      SetCoord((x-current_x)<<5,(y-current_y)<<5) ;
      //отрисовать сетку
      if(player[player_ID].show_grid)
      {
        SetFrame(building_CELL_FRAME_X,building_CELL_FRAME_Y);
        res=c_grObject::Draw(DDSSurface,log_file) ;
        if(res!=DD_OK)return res;
      } ;
      // отрисовать здание
      if(building[x][y].type != building_type_NO)
      {
        // определить территорию вокруг здания
        if(building[x][y].owner!=building_owner_NEUTRAL)
        {
          int owner=building[x][y].owner;
          int t_sx=x-building_territory_ADD_COUNT,t_ex=x+building_territory_ADD_COUNT,
              t_sy=y-building_territory_ADD_COUNT,t_ey=y+building_territory_ADD_COUNT;
          if(t_sx<0)             t_sx=0;
          if(t_ex>=world_X_COUNT)t_ex=world_X_COUNT-1;
          if(t_sy<0)             t_sy=0;
          if(t_ey>=world_Y_COUNT)t_ey=world_Y_COUNT-1;
          for(int t_x=t_sx;t_x<=t_ex;t_x++)
            for(int t_y=t_sy;t_y<=t_ey;t_y++)
              building[t_x][t_y].territory[owner]=1;
        }
        SetFrame(building[x][y].type,building[x][y].y_frame) ;
        res=c_grObject::Draw(DDSSurface,log_file) ;
        if(res!=DD_OK)return res;
      } ;
      //отрисовать территорию
      if(player[player_ID].show_territory && building[x][y].territory[player_ID]==1)
      {
        SetFrame(building_territory_FRAME_X,building_territory_FRAME_Y+player_ID) ;
        res=c_grObject::Draw(DDSSurface,log_file) ;
        if(res!=DD_OK)return res;
      } ;
    } ;
  return DD_OK ;
} ;
//---------------------------------------------------------------------------
int inRange(int x,int y,int x0,int y0,int r)
{
  int by_x = sqr(x-x0) ;
  int by_y = sqr(y-y0) ;
  int res = by_x+by_y<sqr(r) ;
  return res ;
} ;
void MoveTo(float &src_x,float &src_y,int dst_x,int dst_y)
{
  if(src_x<dst_x)src_x+=2.0;
  else if(src_x>dst_x)src_x-=2.0 ;
  if(src_y<dst_y)src_y+=2.0;
  else if(src_y>dst_y)src_y-=2.0 ;
} ;
void MoveFrom(int &src_x,int &src_y,int dst_x,int dst_y)
{
  if(src_x<dst_x)src_x--;
  else if(src_x>dst_x)src_x++ ;
  if(src_y<dst_y)src_y--;
  else if(src_y>dst_y)src_y++ ;
} ;
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
