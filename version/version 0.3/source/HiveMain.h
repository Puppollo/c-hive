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
const int build_panel_X =0;
const int build_panel_Y =415;
const int common_panel_X=65;
const int common_panel_Y=415;
/////////////
const int building_type_NO           =-1 ;
const int building_type_MAIN         = 0 ;  // ядро (выпуск частиц)
const int building_type_NODE         = 1 ;  // маяк
const int building_type_FACTORY      = 2 ;  // завод
const int building_type_MINE         = 3 ;  // шахта
const int building_type_SPEED        = 4 ;  // ускоритель
const int building_type_CHARGE       = 5 ;  // перезарядка
const int building_type_CONNECTOR    = 6 ;  // коонектор (труба)
const int building_type_BUILDPLACE   = 7 ;  // маркер постройки
const int building_type_CONSTRUCTING = 8 ;  // стройка
const int building_type_SELECT       = 9 ;  // маркер выбора
const int building_type_BASE         = 10 ; // база
/////////////
const int building_owner_NEUTRAL = 0 ;
/////////////
const int building_y_frame_GOODPLACE = 0 ;
const int building_y_frame_BADPLACE = 1 ;
const int building_y_frame_NODE_NO   = 0;
const int building_y_frame_NODE_U    = 1;
const int building_y_frame_NODE_UUR  = 2;
const int building_y_frame_NODE_UR   = 3;
const int building_y_frame_NODE_URR  = 4;
const int building_y_frame_NODE_R    = 5;
const int building_y_frame_NODE_DRR  = 6;
const int building_y_frame_NODE_DR   = 7;
const int building_y_frame_NODE_DDR  = 8;
const int building_y_frame_NODE_D    = 9;
const int building_y_frame_NODE_DDL  = 10;
const int building_y_frame_NODE_DL   = 11;
const int building_y_frame_NODE_DLL  = 12;
const int building_y_frame_NODE_L    = 13;
const int building_y_frame_NODE_ULL  = 14;
const int building_y_frame_NODE_UL   = 15;
const int building_y_frame_NODE_UUL  = 16;
/////////////
const int building_NODE_WORK_RANGE = 10 ;
const int building_NODE_RANGE      = 50 ;
/////////////
const int building_territory_ADD_COUNT = 4 ;
const int building_territory_NEUTRAL = -1 ;
const int building_territory_FRAME_X = 7 ;
const int building_territory_FRAME_Y = 2 ;
/////////////
const int unit_type_STD = 0 ;
/////////////
const int world_X_COUNT = 256 ;
const int world_Y_COUNT = 256 ;
/////////////
const int screen_X_CELL_SIZE = 32 ; // 2^5
const int screen_Y_CELL_SIZE = 32 ;
const int screen_X_CELL_COUNT = 20 ; //640/32
const int screen_Y_CELL_COUNT = 15 ; //480/32
/////////////
const int screen_X_CELL_CENTER = 16 ;
const int screen_Y_CELL_CENTER = 16 ;
/////////////
const int MAX_RANGE = 2 ;
const int mouse_LEFT  = 1 ;
const int mouse_RIGHT = 2 ;
//---------------------------------------------------------------------------
void MoveTo(int &src_x,int &src_y,int dst_x,int dst_y) ;
void MoveFrom(int &src_x,int &src_y,int dst_x,int dst_y) ;
int  inRange(int x,int y,int x0,int y0,int r) ;
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
const int building_param_COUNT = 5;
struct s_building
{
  int r ;
  int y_frame ;      // animation or type
  int type ;         // тип здания (x_frame)
  float param[building_param_COUNT] ;
  int owner ;            // принадлежность какому-либо игроку
  int territory ;        // чья территория
} ;
//---------------------------------------------------------------------------
struct s_Player
{
  int show_territory ;
  int resurce_count ;
  int ID ;
  int current_x_screen,current_y_screen ;
  //...
} ;
//---------------------------------------------------------------------------
class c_World:public c_grObject
{
  private :
    int player_count ;
    int sprite_building_dx,sprite_building_dy ; // not USED
  public :
    int TIME ;
    s_Player *player;
    s_building building[world_X_COUNT][world_Y_COUNT] ;
    c_World(c_Sprite *s,int pc=1) ;
    HRESULT Draw(int player_ID,IDirectDrawSurface *DDSSurface,FILE *log_file=NULL) ;
} ;
//---------------------------------------------------------------------------
c_World::c_World(c_Sprite *s,int pc)
:c_grObject(s,0,0)
{
  player_count=pc ;
  player = new s_Player[player_count] ;
  for(int p=0;p<player_count;p++)
  {
    player[p].resurce_count = 1000 ;
    player[p].ID = pc ;
  } ;
  sprite_building_dx =0;
  sprite_building_dy =0;
  TIME = 0 ;
  for(int x=0;x<world_X_COUNT;x++)
    for(int y=0;y<world_Y_COUNT;y++)
    {
      building[x][y].territory=building_territory_NEUTRAL ;
      building[x][y].type = building_type_NO ;
      building[x][y].y_frame=0 ;
      building[x][y].r = 0 ;
      building[x][y].owner = building_owner_NEUTRAL ;
      for(int p=0;p<building_param_COUNT;p++)
        building[x][y].param[p]=1 ;
    } ;
} ;
//---------------------------------------------------------------------------
HRESULT c_World::Draw(int player_ID,IDirectDrawSurface *DDSSurface,FILE *log_file)
{
  HRESULT res;
  int x_end = (player[player_ID]).current_x_screen+screen_X_CELL_COUNT ,
      y_end = (player[player_ID]).current_y_screen+screen_Y_CELL_COUNT ;
  for(int x=(player[player_ID]).current_x_screen;x<x_end;x++)
    for(int y=(player[player_ID]).current_y_screen;y<y_end;y++)
    {
      if((player[player_ID]).show_territory)
        if(building[x][y].territory!=building_territory_NEUTRAL)
        {
          SetCoord(((x-player[player_ID].current_x_screen)<<5)+sprite_building_dx,
                 ((y-player[player_ID].current_y_screen)<<5)+sprite_building_dy) ;
          SetFrame(building_territory_FRAME_X,building_territory_FRAME_Y+player_ID) ;
          res=c_grObject::Draw(DDSSurface,log_file);
          if(res!=DD_OK)return res;
        };
      if(building[x][y].type != building_type_NO)
      {
        SetCoord(((x-player[player_ID].current_x_screen)<<5)+sprite_building_dx,
                 ((y-player[player_ID].current_y_screen)<<5)+sprite_building_dy) ;
        SetFrame(building[x][y].type,building[x][y].y_frame) ;
        res=c_grObject::Draw(DDSSurface,log_file) ;
        if(res!=DD_OK)return res;
      } ;
    };
  return DD_OK ;
} ;
//---------------------------------------------------------------------------
struct s_PInfo
{
  float x,y,dx,dy;
  int x_frame,y_frame ;
  int CurrentTurn;
  int isLive;
  unsigned ID ;
} ;
struct s_UInfo
{
  int TimeToTurn ;
  int TimeToChangeDirection ;
  int SkipEnableCount ;
  int Enable ;
  //...
} ;
//---------------------------------------------------------------------------
struct s_Particicle
{
  s_PInfo PInfo ;
  s_UInfo UInfo ;
  void Move(c_World *world) ;
} ;
//---------------------------------------------------------------------------
struct s_ParticicleInfo
{
  // указываемые параметры
  int TurnTime ;                // время для хода (скорость частицы)
  int GenerateTime ;            // скорость генерирования частицы
  int TurnCount ;               // время жизньи частицы (кол-во ходов)
  int GenerateCountPerTurn;     // кол-во генерируемых частиц в ход
  int width,height ;            // размеры генератора
  int enable ;                  // включен
  float dx,dy ;                 // приращение частиц
  int dxVariation,dyVariation;  // диапазон случайных изменений
  int x_frame_count ;           // анимация по x (затухание)
  int y_frame_count ;           // кол-во типов частиц
  int ParticicleCount ;         // кол-во частиц
  // не указываемые параметры
  int isLiveCount ;             // счетчик существующих частиц
  int ChangeFramePoint ;        // для расчета времени смены кадра
} ;
//===========================================================================
class c_Particicle:public c_grObject
{
  private :
    s_Particicle *particicle;
    s_ParticicleInfo info ;
  public :
    c_Particicle(c_Sprite *s,int x,int y,s_ParticicleInfo i) ;
    void SetEnable(int e=1){if(e==0)info.enable=0;else info.enable=1;};
    void Turn(int TIME,c_World *world,FILE *log_file=NULL) ;
    HRESULT Draw(RECT screen,int Screen_X_Coord,int Screen_Y_Coord,
                 IDirectDrawSurface *DDSSurface,FILE *log_file=NULL) ;
    void SaveInfo(FILE *save_file){fwrite(&info,sizeof(s_ParticicleInfo),1,save_file);} ;
    void LoadInfo(FILE *load_file){fread (&info,sizeof(s_ParticicleInfo),1,load_file);} ;
    int GetHeight() {return info.height;};
    int GetWidth()  {return info.width;};
    void OutLog() ;
    void Release(){delete []particicle;} ;
} ;
//---------------------------------------------------------------------------
c_Particicle::c_Particicle(c_Sprite *s,int x,int y,s_ParticicleInfo i)
:c_grObject(s,x,y)
{
  info = i ;
  info.isLiveCount =0 ;
  info.ChangeFramePoint=info.TurnCount/info.x_frame_count ;
  if(info.ParticicleCount>particicle_MAX_COUNT)info.ParticicleCount=particicle_MAX_COUNT ;
  particicle = new s_Particicle[info.ParticicleCount] ;
  for(int pc=0;pc<info.ParticicleCount;pc++)
  {
    particicle[pc].PInfo.ID = pc ;
    particicle[pc].UInfo.TimeToTurn = 2 ;
    particicle[pc].UInfo.TimeToChangeDirection = 20 ;
    particicle[pc].UInfo.SkipEnableCount = 0 ;
    particicle[pc].UInfo.Enable = 0 ;
  } ;
} ;
//---------------------------------------------------------------------------
void c_Particicle::Turn(int TIME,c_World *world,FILE *log_file)
{
  if(log_file)fprintf(log_file,"START c_Particicle::Turn\n") ;
  if(log_file)fprintf(log_file,"   particicle enabled\n") ;

  if(info.enable==1)
    if(TIME % info.GenerateTime == 0) // генерирование частиц
    {
      if(log_file)fprintf(log_file,"   particicle generate\n") ;
      int N = info.isLiveCount+info.GenerateCountPerTurn ;
      if(N>info.ParticicleCount)N=info.ParticicleCount ;
      if(log_file)fprintf(log_file,"   pre:info.isLiveCount %d\n",info.isLiveCount) ;
      if(log_file)fprintf(log_file,"   N (high index) %d\n",N) ;
      for(int pc=info.isLiveCount;pc<N;pc++)
      {
        info.isLiveCount++;
        if(log_file)fprintf(log_file,"   set particicle[%d].PInfo.isLive = %d to 1\n",pc,particicle[pc].PInfo.isLive) ;
        particicle[pc].PInfo.x = random(info.width) +(GetCoordX()<<5) ; // coordinates
        particicle[pc].PInfo.y = random(info.height)+(GetCoordY()<<5) ; // <<5 = *32
        particicle[pc].PInfo.x_frame = 0;
        particicle[pc].PInfo.y_frame = random(info.y_frame_count) ;
        particicle[pc].PInfo.CurrentTurn = 0;
        particicle[pc].PInfo.isLive = 1 ;
        particicle[pc].PInfo.dx=info.dx+(random((info.dxVariation<<1)+1)-info.dxVariation)/10.0;
        particicle[pc].PInfo.dy=info.dy+(random((info.dyVariation<<1)+1)-info.dyVariation)/10.0;
       } ;
    } ; // end gen time

  if(TIME % info.TurnTime == 0)  // перемещение частиц
  {
    if(log_file)fprintf(log_file,"   particicle turn\n") ;
    if(log_file)fprintf(log_file,"   info.isLiveCount %d\n",info.isLiveCount) ;
    int N = info.isLiveCount ;
    for(int pc=0;pc<N;pc++)
    {
      if(log_file)fprintf(log_file,"   particicle[%d] move\n",pc) ;
      if(particicle[pc].PInfo.isLive)
        particicle[pc].Move(world) ;
      if(particicle[pc].PInfo.CurrentTurn%info.ChangeFramePoint==0)    // Frame change
        if(particicle[pc].PInfo.x_frame<info.x_frame_count-1)          // Frame change
          particicle[pc].PInfo.x_frame++;                              // Frame change
      if(particicle[pc].PInfo.CurrentTurn >= info.TurnCount)
      {
        particicle[pc] = particicle[info.isLiveCount-1] ; // SWAP
        particicle[info.isLiveCount-1].PInfo.isLive =0 ;  // SWAP
        info.isLiveCount-- ;
      };
    } ;
  } ;
  if(log_file)fprintf(log_file,"   info.isLiveCount %d\n",info.isLiveCount) ;
  if(log_file)fprintf(log_file,"END   c_Particicle::Turn\n") ;
} ;
//---------------------------------------------------------------------------
HRESULT c_Particicle::Draw(RECT screen,int Screen_X_Coord,int Screen_Y_Coord,
                           IDirectDrawSurface *DDSSurface,FILE *log_file)
{
  HRESULT res;
  for(int pc=0;pc<info.ParticicleCount;pc++)
    if(particicle[pc].PInfo.isLive == 1)
    {
      int real_x = ((int)(particicle[pc].PInfo.x))-(Screen_X_Coord<<5) ,
          real_y = ((int)(particicle[pc].PInfo.y))-(Screen_Y_Coord<<5) ;
      res=GetSprite()->DrawClip(DDSSurface,real_x,real_y,
                                particicle[pc].PInfo.x_frame,particicle[pc].PInfo.y_frame,
                                screen,log_file) ;
      if(res!=DD_OK)return res;
    } ;
  return DD_OK ;
} ;
//---------------------------------------------------------------------------
void c_Particicle::OutLog()
{
  FILE *log = fopen("particicle.log","w+") ;
  fprintf(log,"info :\n") ;
  fprintf(log,"TurnTime              %d\n",info.TurnTime) ;
  fprintf(log,"GenerateTime          %d\n",info.GenerateTime) ;
  fprintf(log,"GenerateCountPerTurn  %d\n",info.GenerateCountPerTurn) ;
  fprintf(log,"width                 %d\n",info.width) ;
  fprintf(log,"height                %d\n",info.height) ;
  fprintf(log,"dx                    %3.3f\n",info.dx) ;
  fprintf(log,"dy                    %3.3f\n",info.dy) ;
  fprintf(log,"dxVariation           %d\n",info.dxVariation) ;
  fprintf(log,"dyVariation           %d\n",info.dyVariation) ;
  fprintf(log,"x_frame_count         %d\n",info.x_frame_count) ;
  fprintf(log,"y_frame_count         %d\n",info.y_frame_count) ;
  fprintf(log,"ParticicleCount       %d\n",info.ParticicleCount) ;
  fprintf(log,"ChangeFramePoint      %d\n",info.ChangeFramePoint) ;
  fclose(log);
} ;
//---------------------------------------------------------------------------
void s_Particicle::Move(c_World *world)
{
  if(UInfo.SkipEnableCount>0)UInfo.SkipEnableCount--;
  if(UInfo.SkipEnableCount==0)
    UInfo.Enable =0 ;
  if(UInfo.Enable==0&&PInfo.CurrentTurn % UInfo.TimeToChangeDirection==0)
  {
    PInfo.dx = (random(21)-10)/10.0 ;
    PInfo.dy = (random(21)-10)/10.0 ;
  } ;
  int cell_x=((int)PInfo.x)>>5, cell_y=((int)PInfo.y)>>5 ;
  int x_start=cell_x-MAX_RANGE ;
  if(x_start<0)x_start=0 ;
  int x_end  =cell_x+MAX_RANGE ;
  if(x_end>=world_X_COUNT)x_end=world_X_COUNT-1 ;
  int y_start=cell_y-MAX_RANGE ;
  if(y_start<0)y_start=0 ;
  int y_end  =cell_y+MAX_RANGE ;
  if(y_end>=world_Y_COUNT)y_end=world_Y_COUNT-1 ;
  for(int x=x_start;x<=x_end;x++)
    for(int y=y_start;y<=y_end;y++)
    {
      switch((world->building[x][y]).type)
      {
        case building_type_NODE : // маяк
          if(inRange((int)PInfo.x,(int)PInfo.y,
                     (x<<5)+screen_X_CELL_CENTER,
                     (y<<5)+screen_Y_CELL_CENTER,
                     (world->building[x][y]).r)) // в зоне действия маяка
          {
            if(inRange((int)PInfo.x,(int)PInfo.y,
                       (x<<5)+screen_X_CELL_CENTER,
                       (y<<5)+screen_Y_CELL_CENTER,
                       building_NODE_WORK_RANGE))
            {
              PInfo.dx = (world->building[x][y]).param[0] ;
              PInfo.dy = (world->building[x][y]).param[1] ;
              UInfo.Enable=1 ;
              UInfo.SkipEnableCount = (world->building[x][y]).param[3];
            }
            else if(UInfo.Enable==0)
            {
              int mx = (int)PInfo.x , my = (int)PInfo.y ;
              MoveTo(mx,my,(x<<5)+screen_X_CELL_CENTER,(y<<5)+screen_Y_CELL_CENTER) ;
              PInfo.x = mx ; PInfo.y = my ;
            } ;
          };
        break ;
        case building_type_MAIN : // база
          if(cell_x==x && cell_y==y) // в той же клетке что и база
          {
            PInfo.CurrentTurn=0;     // восстановить энергию
            PInfo.x_frame = 0;
          } ;
        break;
        case building_type_FACTORY : // завод
          if(cell_x==x && cell_y==y)
          {
            PInfo.CurrentTurn++ ;
            //... проверка конец строительства прототипа здания
          } ;
        break ;
        case building_type_CONSTRUCTING : // стройка
          if(cell_x==x && cell_y==y)
          {
            PInfo.CurrentTurn++ ;
            //... проверка конец строительства здания
            PInfo.x = (world->building[x][y]).param[3] ;
            PInfo.y = (world->building[x][y]).param[4] ;
          } ;
        case building_type_MINE :
          if(cell_x==x && cell_y==y)      // шахта
          {
            if((world->building[x][y]).param[0]>0) // шахта пуста?
            {
              PInfo.CurrentTurn++ ;
              (world->building[x][y]).param[0]--; // убавить ресов в шахте
              int owner = (world->building[x][y]).owner ;
              (world->player[owner]).resurce_count++; // добавить ресов игроку
            } ;
            PInfo.x = (world->building[x][y]).param[2] ;
            PInfo.y = (world->building[x][y]).param[3] ;
          } ;
        break;
     } ;
    } ;
  if(world->TIME % UInfo.TimeToTurn==0)
  {
    PInfo.x+=PInfo.dx;
    PInfo.y+=PInfo.dy;
  };
  PInfo.CurrentTurn++;
} ;
//---------------------------------------------------------------------------
void MoveMap(int &current_x_screen,int &current_y_screen,int dx,int dy) ;
void MoveMapByMouse(int mouse_x,int mouse_y,int &current_x_screen,int &current_y_screen,int screen_HEIGHT,int screen_WIDTH) ;
int  FindPath(int src_x,int src_y,int dest_x,int dest_y,c_World *world,int path[world_X_COUNT][world_Y_COUNT],FILE *log_file=NULL);
int  BuildConnector(int &src_x,int &src_y,c_World *world,int path[world_X_COUNT][world_Y_COUNT],FILE *log_file=NULL);
//---------------------------------------------------------------------------
int inRange(int x,int y,int x0,int y0,int r)
{
  int by_x = sqr(x-x0) ;
  int by_y = sqr(y-y0) ;
  int res = by_x+by_y<sqr(r) ;
  return res ;
} ;
void MoveTo(int &src_x,int &src_y,int dst_x,int dst_y)
{
  if(src_x<dst_x)src_x++;
  else if(src_x>dst_x)src_x-- ;
  if(src_y<dst_y)src_y++;
  else if(src_y>dst_y)src_y-- ;
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
int FindPath(int src_x,int src_y,int dest_x,int dest_y,
             c_World *world,int path[world_X_COUNT][world_Y_COUNT],FILE *log_file)
{
  for(int x=0;x<world_X_COUNT;x++)
    for(int y=0;y<world_Y_COUNT;y++)
    {
      path[x][y]=-1 ;// очистка массива пути
      if((world->building[x][y]).type!=building_type_NO)path[x][y]=-2; //на клетке шарик
    } ;
  path[src_x][src_y]=-1;
  path[dest_x][dest_y]=0 ;
  if(log_file)fprintf(log_file,"--->>>FindPath\n") ;
  int check_no_way = 0 ; // проверка на "невозможность пройти"
  for(int current_step=1;current_step<100;current_step++)
  {
    for(int x=0;x<world_X_COUNT;x++)
      for(int y=0;y<world_Y_COUNT;y++)
      {
        if(path[x][y]!=-1 && current_step-path[x][y]==1)
        {
          if(log_file)fprintf(log_file,"path[%d][%d] %2d,current_step %2d\n",x,y,path[x][y],current_step) ;
          // проверка по X
          if(x==0)              {if(path[x+1][y]==-1){path[x+1][y]=current_step;check_no_way++;};}
          else
          if(x==world_X_COUNT-1) {if(path[x-1][y]==-1){path[x-1][y]=current_step;check_no_way++;};}
          else
          {
            if(path[x+1][y]==-1){path[x+1][y]=current_step;check_no_way++;};
            if(path[x-1][y]==-1){path[x-1][y]=current_step;check_no_way++;};
          } ;
          // проверка по Y
          if(y==0)              {if(path[x][y+1]==-1){path[x][y+1]=current_step;check_no_way++;};}
          else
          if(y==world_Y_COUNT-1) {if(path[x][y-1]==-1){path[x][y-1]=current_step;check_no_way++;};}
          else
          {
            if(path[x][y+1]==-1){path[x][y+1]=current_step;check_no_way++;};
            if(path[x][y-1]==-1){path[x][y-1]=current_step;check_no_way++;};
          } ;
        }
      } ;
    if(log_file)
    {
      fprintf(log_file,"path, current_step %d\n",current_step) ;
      for(int y=0;y<world_Y_COUNT;y++)
      {
        for(int x=0;x<world_X_COUNT;x++)
          fprintf(log_file,"%3d",path[x][y]) ;
        fprintf(log_file,"\n") ;
      } ;
    } ;
    // no way check
    if(check_no_way==0)
    {
      if(log_file)fprintf(log_file,"   NO PATH\n") ;
      return 0;
    } ;
    // end way check
    if(path[src_x][src_y]>=0)
    {
      if(log_file)fprintf(log_file,"   PATH FIND\n") ;
      return 1 ;
    } ;
  };
  // out log
  if(log_file)
  {
    fprintf(log_file,"path\n") ;
    for(int y=0;y<world_Y_COUNT;y++)
    {
      for(int x=0;x<world_X_COUNT;x++)
        fprintf(log_file,"%3d",path[x][y]) ;
      fprintf(log_file,"\n") ;
    } ;
  } ;
  if(log_file)fprintf(log_file,">>>---FindPathBall\n") ;
  return 0; // no way
} ;
//------------------------------------------------------------------------------
int BuildConnector(int &src_x,int &src_y,c_World *world,int path[world_X_COUNT][world_Y_COUNT],FILE *log_file)
{
  if(log_file)fprintf(log_file,"--->>>Move\n") ;
  (world->building[src_x][src_y]).type=building_type_CONNECTOR ;

  if(src_x>0) // проверка по X
    if(path[src_x][src_y]>path[src_x-1][src_y] && path[src_x-1][src_y]>-1)
    {
      src_x-- ;
      if(log_file,"   move left\n");
      (world->building[src_x][src_y]).type=building_type_CONNECTOR ;
      if(log_file)fprintf(log_file,">>>---Move\n") ;
      return 1 ;
    } ;
  if(src_x<world_X_COUNT-1)
    if(path[src_x+1][src_y]<path[src_x][src_y] && path[src_x+1][src_y]>-1)
    {
      src_x++;
      if(log_file,"   move right\n");
      if(log_file)fprintf(log_file,">>>---Move\n") ;
      return 1 ;
    } ;
  if(src_y>0) // проверка по Y
    if(path[src_x][src_y-1]<path[src_x][src_y] && path[src_x][src_y-1]>-1)
    {
      src_y-- ;
      if(log_file,"   move up\n");
      (world->building[src_x][src_y]).type=building_type_CONNECTOR ;
      if(log_file)fprintf(log_file,">>>---Move\n") ;
      return 1 ;
    } ;
  if(src_y<world_Y_COUNT-1)
    if(path[src_x][src_y+1]<path[src_x][src_y] && path[src_x][src_y+1]>-1)
    {
      src_y++;
      if(log_file,"   move down\n");
      if(log_file)fprintf(log_file,">>>---Move\n") ;
      return 1 ;
    } ;
  if(log_file)fprintf(log_file,"   END WAY\n") ;
  if(log_file)fprintf(log_file,">>>---MoveBall\n") ;
  return 0; // конец пути
} ;
//---------------------------------------------------------------------------
#endif
