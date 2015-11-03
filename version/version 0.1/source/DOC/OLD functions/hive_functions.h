#ifndef HiveFunctionsH
#define HiveFunctionsH
//---------------------------------------------------------------------------
#define sqr(x) ((x)*(x))
#include <stdio.h>
//---------------------------------------------------------------------------
const int building_type_MAIN    = 0 ;
const int building_type_NODE    = 1 ;
const int building_type_FACTORY = 2 ;

const int unit_type_STD = 0 ;
//---------------------------------------------------------------------------
struct s_unit
{
  int type ;
  int TimeToTurn ;
  //...
} ;
//---------------------------------------------------------------------------
const int building_param_COUNT = 4;
struct s_Building
{
  int x,y ;                          // координаты
  int r ;                            // радиус действия здания
  int type ;                         // тип здания (x_frame)
  float param[building_param_COUNT] ;// параметры
} ;
//---------------------------------------------------------------------------
const int player_building_MAX_COUNT = 100 ;
struct s_Player
{
  s_Building building[player_building_MAX_COUNT] ;
  int current_building_count ;

} ;
//---------------------------------------------------------------------------
void particicle_units_MOVE(float &x,float &y,float &dx,float &dy,int &CurrentTurn,const int ID,const int y_frame,void *param,void *ex)
{
  s_Player world=*(s_Player*)ex ;
  //FIRST INIT
  s_unit *info;
  if(CurrentTurn==0)
  {
    info->type = unit_type_STD ;
    info->TimeToTurn=10 ;
    param=&info;
    FILE *f=fopen("test.log","w+") ;
    fprintf(f,"%d",info->TimeToTurn) ;
    fclose(f) ;
  }
  else
    info=(s_unit*)param;
  //TURN
  if(CurrentTurn%20==0)
  {
    dx=((random(10<<1)+1)-10)/10.0;
    dy=((random(10<<1)+1)-10)/10.0;
  } ;
  for(int bc=0;bc<world.current_building_count;bc++)
    if(sqr(x-world.building[bc].x)+sqr(y-world.building[bc].y)<sqr(world.building[bc].r))
      switch(world.building[bc].type)
      {
        case building_type_NODE :
          dx=world.building[bc].param[0] ;
          dy=world.building[bc].param[1] ;
        break;
        case building_type_FACTORY :
          if(world.building[bc].param[1]>0)
            world.building[bc].param[1]-- ;
          x=world.building[bc].param[2] ;
          y=world.building[bc].param[3] ;
      } ;
  x+=dx; y+=dy ;
} ;
//---------------------------------------------------------------------------
#endif