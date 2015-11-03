#ifndef cHiveWorldH
#define cHiveWorldH
//---------------------------------------------------------------------------
#include <ddraw.h>
#include <stdio.h>

#include <c_grObject.h>
#include "HiveMain.h"
#include "c_HiveParticicleS.h"
//---------------------------------------------------------------------------
const int building_NODE_ARROW_FRAME_X = 1 ;
const int building_NODE_ARROW_FRAME_Y = 1 ;
const int building_NODE_ARROW_U_X  = 14 ;
const int building_NODE_ARROW_U_Y  = 1 ;
const int building_NODE_ARROW_UR_X = 26 ;
const int building_NODE_ARROW_UR_Y = 1 ;
const int building_NODE_ARROW_R_X  = 26 ;
const int building_NODE_ARROW_R_Y  = 14 ;
const int building_NODE_ARROW_DR_X = 26 ;
const int building_NODE_ARROW_DR_Y = 26 ;
const int building_NODE_ARROW_D_X  = 14 ;
const int building_NODE_ARROW_D_Y  = 26 ;
const int building_NODE_ARROW_DL_X = 1 ;
const int building_NODE_ARROW_DL_Y = 26 ;
const int building_NODE_ARROW_L_X  = 1 ;
const int building_NODE_ARROW_L_Y  = 14 ;
const int building_NODE_ARROW_UL_X = 1 ;
const int building_NODE_ARROW_UL_Y = 1 ;
const int building_NODE_FOR_X   = 21 ;
const int building_NODE_FOR_Y   = 23 ;
const int building_NODE_FOR_EMPTY_FRAME_X = 1 ;
const int building_NODE_FOR_EMPTY_FRAME_Y = 2 ;
const int building_NODE_FOR_MINERAL_FRAME_X = 1 ;
const int building_NODE_FOR_MINERAL_FRAME_Y = 3 ;
const int building_NODE_FOR_ENERGY_FRAME_X  = 1 ;
const int building_NODE_FOR_ENERGY_FRAME_Y  = 4 ;
//---------------------------------------------------------------------------
class c_World:public c_grObject
{
  private :
    int player_count ;
    int particicle_supply_count ;
    HRESULT DrawNodeParam(int x,int y,int current_x,int current_y,RECT screen,IDirectDrawSurface *DDSSurface);
    void ReGenMap() ; // дальнейшее изменение карты
  public :
    int TIME ,CYCLE;
    s_Player *player;
    c_Particicle *ParticicleSupply[world_MAX_SUPPLY_COUNT] ;
    s_building building[world_X_COUNT][world_Y_COUNT] ;

    c_World(c_Sprite *s,c_Sprite *particicle_sprite,int p_count=1,int p_supply_count=1) ;
    void GenMap();    // формирование начальной карты
    HRESULT Draw(int player_ID,RECT screen,IDirectDrawSurface *DDSSurface,FILE *log_file=NULL) ;
    void Turn(FILE *log_file=NULL) ;
    void Release(FILE *log_file) ;
    void SetBuilding(int x,int y,int type,int player_ID) ;
} ;
//---------------------------------------------------------------------------
void c_World::GenMap()
{
  // задание начальных вершин
  for(int x=0;x<world_X_COUNT;x++)
    for(int y=0;y<world_Y_COUNT;y++)
    {
      int r=random(100) ;
      if(r<world_START_PEACK_RANDOM)
        building[x][y].terrain.height=random(building_terrain_MAX_HEIGHT+1);
    } ;
  // создание ландшафта
  for(int current_h=building_terrain_MAX_HEIGHT;current_h>0;current_h--)
  {
    for(int x=0;x<world_X_COUNT;x++)
    {
      for(int y=0;y<world_Y_COUNT;y++)
      {
        if(building[x][y].terrain.height==current_h)
        {
          if(x>0)
          {
            if(building[x-1][y].terrain.height<current_h)
              building[x-1][y].terrain.height=current_h-1;
          };
          if(x<world_X_COUNT-1)
          {
            if(building[x+1][y].terrain.height<current_h)
              building[x+1][y].terrain.height=current_h-1;
          };
          if(y>0)
          {
            if(building[x][y-1].terrain.height<current_h)
              building[x][y-1].terrain.height=current_h-1;
          };
          if(y<world_Y_COUNT-1)
          {
            if(building[x][y+1].terrain.height<current_h)
              building[x][y+1].terrain.height=current_h-1;
          };
        };
      } ;
    };
  };
  // создание начальных залежей минералов
  for(int x=0;x<world_X_COUNT;x++)
    for(int y=0;y<world_Y_COUNT;y++)
    {
      int mr = random(100*(building[x][y].terrain.height+1)) ;
      if(mr<world_MINERAL_RANDOM)
      {
        building[x][y].type=building_type_MINERAL ;
        building[x][y].maxHP = building_MINERAL_HP ;
        building[x][y].HP = building_MINERAL_HP ;
        building[x][y].param[0] = world_MINERAL_PARAM+random((world_MINERAL_PARAM_VARIATION<<1)+1)-world_MINERAL_PARAM_VARIATION ;
      };
    } ;
  // формирование минеральных жил
  for(int x=0;x<world_X_COUNT;x++)
    for(int y=0;y<world_Y_COUNT;y++)
      if(building[x][y].type==building_type_MINERAL)
      {
        if(x>0)
        {
          int r=random(100) ;
          if(r<world_MINERAL_IN_RANDOM)
          {
            building[x-1][y].type=building_type_MINERAL ;
            building[x-1][y].maxHP = building_MINERAL_HP ;
            building[x-1][y].HP = building_MINERAL_HP ;
            building[x-1][y].param[0] = world_MINERAL_PARAM+random((world_MINERAL_PARAM_VARIATION<<1)+1)-world_MINERAL_PARAM_VARIATION ;
            continue;
          } ;
        };
        if(x<world_X_COUNT-1)
        {
          int r=random(100) ;
          if(r<world_MINERAL_IN_RANDOM)
          {
            building[x+1][y].type=building_type_MINERAL ;
            building[x+1][y].maxHP = building_MINERAL_HP ;
            building[x+1][y].HP = building_MINERAL_HP ;
            building[x+1][y].param[0] = world_MINERAL_PARAM+random((world_MINERAL_PARAM_VARIATION<<1)+1)-world_MINERAL_PARAM_VARIATION ;
            continue;
          } ;
        };
        if(y>0)
        {
          int r=random(100) ;
          if(r<world_MINERAL_IN_RANDOM)
          {
            building[x][y-1].type=building_type_MINERAL ;
            building[x][y-1].maxHP = building_MINERAL_HP ;
            building[x][y-1].HP = building_MINERAL_HP ;
            building[x][y-1].param[0] = world_MINERAL_PARAM+random((world_MINERAL_PARAM_VARIATION<<1)+1)-world_MINERAL_PARAM_VARIATION ;
            continue;
          } ;
        };
        if(y<world_Y_COUNT-1)
        {
          int r=random(100) ;
          if(r<world_MINERAL_IN_RANDOM)
          {
            building[x][y+1].type=building_type_MINERAL ;
            building[x][y+1].maxHP = building_MINERAL_HP ;
            building[x][y+1].HP = building_MINERAL_HP ;
            building[x][y+1].param[0] = world_MINERAL_PARAM+random((world_MINERAL_PARAM_VARIATION<<1)+1)-world_MINERAL_PARAM_VARIATION ;
            continue;
          } ;
        };
      } ;
} ;

void c_World::ReGenMap()
{
} ;
//---------------------------------------------------------------------------
c_World::c_World(c_Sprite *s,c_Sprite *particicle_sprite,int p_count,int p_supply_count)
:c_grObject(s,0,0)
{
  TIME = 0 ;
  CYCLE=0;
  //players init
  player_count=p_count ;
  player = new s_Player[player_count] ;
  for(int p=0;p<player_count;p++)
  {
    for(int bcc=0;bcc<player_buildings_combat_COUNT;bcc++)
      player[p].buildings_combat_count[bcc]=10;
    for(int bc=0;bc<player_buildings_COUNT;bc++)
      player[p].buildings_count[bc]=50;
  } ;
  for(int p=0;p<player_count;p++)
  {
    player[p].ID = p ;
    player[p].show_territory=0;
    player[p].show_grid=0;
    player[p].supply_mineral_carring_count=5 ;
    player[p].supply_energy_carring_count =1 ;
  } ;
  //buildings init
  for(int x=0;x<world_X_COUNT;x++)
    for(int y=0;y<world_Y_COUNT;y++)
    {
      building[x][y].y_frame=0 ;
      building[x][y].r = 0 ;
      building[x][y].owner = building_owner_NEUTRAL ;
      building[x][y].draw_flag = 0;
      building[x][y].territory = new int[player_count];
      building[x][y].enable=1;
      building[x][y].type = building_type_NO ;
      building[x][y].HP=1;
      building[x][y].maxHP=1;
      for(int p=0;p<building_param_COUNT;p++)
        building[x][y].param[p]=1 ;
      for(int p=0;p<player_count;p++)
        building[x][y].territory[p]=building_owner_NEUTRAL ;
      building[x][y].terrain.height=0;
      building[x][y].terrain.dheight = 0 ;
      building[x][y].terrain.type=building_type_TERRAIN;
    } ;
  //particicle supply init
  particicle_supply_count = p_supply_count;
  if(particicle_supply_count>world_MAX_SUPPLY_PARTICICLE_COUNT)particicle_supply_count=world_MAX_SUPPLY_PARTICICLE_COUNT;
  s_ParticicleInfo PInfo ;
  PInfo.TurnTime = 1 ;
  PInfo.GenerateTime = particicle_GENERATE_TIME ;
  PInfo.TurnCount = 1000 ;
  PInfo.GenerateCountPerTurn = 1 ;
  PInfo.width = screen_X_CELL_SIZE ;
  PInfo.height = screen_Y_CELL_SIZE ;
  PInfo.enable = 1 ;
  PInfo.dx = 0.0 ;
  PInfo.dy = 0.0 ;
  PInfo.dxVariation = 20 ;
  PInfo.dyVariation = 20 ;
  PInfo.x_frame_count = 5 ;
  PInfo.type_count    = 3 ;
  PInfo.ParticicleCount = world_MAX_SUPPLY_PARTICICLE_COUNT ;

  ParticicleSupply[0]=new c_Particicle(particicle_sprite,100,100,PInfo) ; //TEST
  building[100][100].type=building_type_MAIN ;                            //TEST
  building[100][100].HP=building_MAIN_HP ;                                //TEST
  building[100][100].maxHP=building_MAIN_HP ;                             //TEST
/*
  for(int p=0;p<particicle_supply_count;p++)
  {
    int x=random(world_X_COUNT) ;
    int y=random(world_Y_COUNT) ;
    if(building[x][y].type==building_type_NO)
    {
      ParticicleSupply[p]=new c_Particicle(particicle_sprite,x,y,PInfo) ;
      building[x][y].type=building_type_MAIN ;
      building[x][y].HP=building_MAIN_HP ;
      building[x][y].maxHP=building_MAIN_HP ;
    };
  } ;*/
  GenMap() ;
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
      building[x][y].param[0]=1000;
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
void c_World::Turn(FILE *log_file)
{
  TIME++;
  if(TIME>10000)
  {
    TIME=0;
    CYCLE++;
    if(CYCLE>100)
    {
      CYCLE=0;
      //... ReGenMap();
    } ;
  };

  for(int ps=0;ps<particicle_supply_count;ps++)
    ParticicleSupply[ps]->Turn(TIME,building,player,log_file) ;
} ;
//---------------------------------------------------------------------------
HRESULT c_World::DrawNodeParam(int x,int y,int current_x,int current_y,RECT screen,IDirectDrawSurface *DDSSurface)
{
  int particicle_dx = building[x][y].param[0],
      particicle_dy = building[x][y].param[1] ;
  if(particicle_dx==2)
  {
    if(particicle_dy==-2) // direction UR
       SetCoord(((x-current_x)<<5)+building_NODE_ARROW_UR_X,((y-current_y)<<5)+building_NODE_ARROW_UR_Y);
    else
    if(particicle_dy==2)  // direction DR
      SetCoord(((x-current_x)<<5)+building_NODE_ARROW_DR_X,((y-current_y)<<5)+building_NODE_ARROW_DR_Y);
    else                  // direction R
      SetCoord(((x-current_x)<<5)+building_NODE_ARROW_R_X,((y-current_y)<<5)+building_NODE_ARROW_R_Y);
  }
  else
  if(particicle_dx==-2)
  {
    if(particicle_dy==-2) // directon UL
      SetCoord(((x-current_x)<<5)+building_NODE_ARROW_UL_X,((y-current_y)<<5)+building_NODE_ARROW_UL_Y);
    else
    if(particicle_dy==2)  // direction DL
      SetCoord(((x-current_x)<<5)+building_NODE_ARROW_DL_X,((y-current_y)<<5)+building_NODE_ARROW_DL_Y);
    else                  // direction L
      SetCoord(((x-current_x)<<5)+building_NODE_ARROW_L_X,((y-current_y)<<5)+building_NODE_ARROW_L_Y);
  }
  else
  {
    if(particicle_dy==-2) // direction U
      SetCoord(((x-current_x)<<5)+building_NODE_ARROW_U_X,((y-current_y)<<5)+building_NODE_ARROW_U_Y);
    else
    if(particicle_dy==2)  // direction D
      SetCoord(((x-current_x)<<5)+building_NODE_ARROW_D_X,((y-current_y)<<5)+building_NODE_ARROW_D_Y);
  };
  //draw arrow
  SetFrame(building_NODE_ARROW_FRAME_X,building_NODE_ARROW_FRAME_Y) ;
  HRESULT res;
  res = c_grObject::DrawClip(screen,DDSSurface) ;
  if(res!=DD_OK)return res;
  //draw param
  SetCoord(((x-current_x)<<5)+building_NODE_FOR_X,((y-current_y)<<5)+building_NODE_FOR_Y);
  if(building[x][y].param[3])
  {
    SetFrame(building_NODE_FOR_EMPTY_FRAME_X,building_NODE_FOR_EMPTY_FRAME_Y);
    res=c_grObject::DrawClip(screen,DDSSurface) ;
    if(res!=DD_OK)return res;
  } ;
  if(building[x][y].param[4])
  {
    SetFrame(building_NODE_FOR_MINERAL_FRAME_X,building_NODE_FOR_MINERAL_FRAME_Y);
    res=c_grObject::DrawClip(screen,DDSSurface) ;
    if(res!=DD_OK)return res;
  } ;
  if(building[x][y].param[5])
  {
    SetFrame(building_NODE_FOR_ENERGY_FRAME_X,building_NODE_FOR_ENERGY_FRAME_Y);
    res=c_grObject::DrawClip(screen,DDSSurface) ;
    if(res!=DD_OK)return res;
  } ;
  return DD_OK ;
} ;
//---------------------------------------------------------------------------
HRESULT c_World::Draw(int player_ID,RECT screen,IDirectDrawSurface *DDSSurface,FILE *log_file)
{
  HRESULT res;
  int current_x=(player[player_ID]).current_x_screen,current_y=(player[player_ID]).current_y_screen ;
  int x_start_map = current_x ,
      y_start_map = current_y ,
      x_end_map = current_x+screen_X_CELL_COUNT ,
      y_end_map = current_y+screen_Y_CELL_COUNT ;
  //building draw
  for(int x=x_start_map;x<x_end_map;x++)
    for(int y=y_start_map;y<y_end_map;y++)
    {
      //отрисовать поверхность
      SetCoord((x-current_x)<<5,(y-current_y)<<5) ;
      SetFrame(building[x][y].terrain.type,building[x][y].terrain.height);
      res=c_grObject::Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;

      SetCoord((x-current_x)<<5,(y-current_y)<<5) ;
      //отрисовать территорию
      if(player[player_ID].show_territory && building[x][y].territory[player_ID]==1)
      {
        SetFrame(building_territory_FRAME_X,building_territory_FRAME_Y+player_ID) ;
        res=c_grObject::Draw(DDSSurface,log_file) ;
        if(res!=DD_OK)return res;
      } ;
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
        if(building[x][y].owner!=building_owner_NEUTRAL && building[x][y].type!=building_type_BLOW)
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
        //draw building
        if(building[x][y].type==building_type_NODE)
        {
          res = DrawNodeParam(x,y,current_x,current_y,screen,DDSSurface) ;
          if(res!=DD_OK)return res;
          SetCoord((x-current_x)<<5,(y-current_y)<<5) ;
        } ;
        SetFrame(building[x][y].type,building[x][y].y_frame) ;
        res=c_grObject::Draw(DDSSurface,log_file) ;
        if(res!=DD_OK)return res;
        //blow animation
        if(building[x][y].type==building_type_BLOW)
        {
          building[x][y].y_frame++;
          if(building[x][y].y_frame>=7)
          {
            building[x][y].type=building_type_NO ;
            building[x][y].y_frame=0;
            building[x][y].owner=building_owner_NEUTRAL;
          } ;
        }
      } ;
    } ;
  //supply particicle draw
  for(int ps=0;ps<particicle_supply_count;ps++)
  {
    res=ParticicleSupply[ps]->Draw(screen,player[player_ID].current_x_screen,player[player_ID].current_y_screen,DDSSurface);
    if(res!=DD_OK)return res;
  } ;
  return DD_OK ;
} ;
//---------------------------------------------------------------------------
#endif
