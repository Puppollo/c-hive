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
const int font_info_COORDX_X = 26 ;
const int font_info_COORDX_Y = 4 ;
const int font_info_COORDY_X = 69 ;
const int font_info_COORDY_Y = 4 ;
const int font_info_CYCLE_X  = 625 ;
const int font_info_CYCLE_Y  = 4 ;
const int font_info_Htxt_X = 91 ;
const int font_info_Htxt_Y = 4 ;
const int font_info_H_X    = 102 ;
const int font_info_H_Y    = 4 ;
/////////////
const int common_panel_X=0;
const int common_panel_Y=415;
/////////////
const int player_buildings_COUNT = 7 ;
const int player_buildings_NO = -1 ;
const int player_buildings_NODE      = 0 ;
const int player_buildings_FACTORY   = 1 ;
const int player_buildings_MINE      = 2 ;
const int player_buildings_CHARGE    = 3 ;
const int player_buildings_SPEED     = 4 ;
const int player_buildings_POWER     = 5 ;
const int player_buildings_SEPARATOR = 6 ;

const int player_buildings_combat_COUNT =1 ;
const int player_buildings_combat_NO = -1 ;
const int player_buildings_combat_IMPACTOR = 0 ;
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
const int building_type_BLOW         = 12 ; // взрыв
const int building_type_SEPARATOR    = 13 ; // раделитель
const int building_type_TERRAIN      = 14 ; // поверхность
/////////////
const int building_owner_NEUTRAL = -1 ;
/////////////
const int building_y_frame_GOODPLACE = 0 ;
const int building_y_frame_BADPLACE  = 1 ;
const int building_y_frame_SEPARATOR_HORIZONTAL = 0 ;
const int building_y_frame_SEPARATOR_VERTICAL   = 1 ;
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
const int building_FACTORY_BUILD_TIME   = 1000 ; // кол-во ходов для постройки завода
const int building_MINE_BUILD_TIME      = 1500 ; // кол-во ходов для постройки шахты
const int building_CHARGE_BUILD_TIME    = 2000 ; // кол-во ходов для постройки зарядника
const int building_SPEED_BUILD_TIME     = 500 ;  // кол-во ходов для постройки ускорителя
const int building_POWER_BUILD_TIME     = 1000 ; // кол-во ходов для постройки электростанции
const int building_SEPARATOR_BUILD_TIME = 50 ;   // кол-во ходов для постройки разделителя
/////////////
const int building_terrain_MAX_HEIGHT = 6 ; // максимальная высота поверхности (y_frame)
/////////////
const int building_exit_coord_X = 1 ; // X координата перемещения частицы из здания
const int building_exit_coord_Y = 1 ; // Y координата перемещения частицы из здания
/////////////
const int building_CONSTRUCTING_ENERGY_REDUCED=3;  // кол-во энергии частицы уходящей на строительство
const int building_FACTORY_ENERGY_REDUCED     =5;  // кол-во энергии частицы уходящей на производство
const int building_MINE_ENERGY_REDUCED        =2;  // кол-во энергии частицы уходящей на добычу минералов
const int building_POWER_ENERGY_REDUCED       =10; // кол-во энергии частицы уходящей на добычу энергии
const int building_BASE_ENERGY_REDUCED        =6;  // кол-во энергии частицы уходящей на базе
const int building_BLOW_ENERGY_REDUCED        =500;// кол-во энергии частицы уходящей при попадании в взрыв
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
const int building_SEPARATOR_HP = 500 ;
/////////////
const int building_MAX_MINERAL_COUNT = 30000 ; // максимальное кол-во минералов в здании
const int building_MAX_ENERGY_COUNT  = 30000 ; // максимальное кол-во энергии в здании
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

const int world_START_PEACK_RANDOM = 2 ;  // вероятность что в точке сгенерируется вершина (возвышенность)
const int world_ENERGY_HEIGHT_START=3 ;   // высота с которой начинается добыча энергии
const int world_MINERAL_SIZE = 1 ;             // размер минеральной жилы
const int world_MINERAL_RANDOM = 1 ;           // вероятность того что в клетке сгенерируется минеральная жила
const int world_MINERAL_IN_RANDOM = 15 ;       // вероятность того что в жиле сгенерируеться минерал
const int world_MINERAL_PARAM = 100 ;          // среднее значение параметра param[0] типа building_type_MINERAL
const int world_MINERAL_PARAM_VARIATION = 50 ;// 100 +- 50


const int world_MAX_SUPPLY_COUNT = 50 ;             // максимально возможное число генераторов частиц типа c_Particicle
const int world_MAX_SUPPLY_PARTICICLE_COUNT = 100 ; // максимально возможное число частиц выпускаемых генератором c_Particicle
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
struct s_terrain
{
  int height ;       // высота поверхности (y_frame)
  int dheight ;      // изменение высоты (какова будет высота на конец периода( >10 +1, <10 -1)
  int type ;   // тип поверхности    (x_frame)
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
  int *territory ; // массив определяющий можно-ли строить здания  (определяет принадлежность территории)
  int draw_flag ; // флаг отрисовки, для отрисовки территории

  s_terrain terrain;
} ;
//---------------------------------------------------------------------------
struct s_Player
{
  int show_territory, // отрисовывать территорию
      show_grid ;     // отрисовывать сетку
  int ID ;
  int current_x_screen,current_y_screen ;
  int buildings_count[player_buildings_COUNT];                // кол-во прототипов supply зданий
  int buildings_combat_count[player_buildings_combat_COUNT] ; // кол-во прототипов combat зданий
  int supply_mineral_carring_count ,// кол-во минералов переносимого частицей 
      supply_energy_carring_count;  // кол-во энергии переносимого частицей
  int constructing_list[5][3]; // очередь на строительство [][0]-тип здания,[][1]-кол-во прототипов для постройки,[][2]-текущий процесс
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
