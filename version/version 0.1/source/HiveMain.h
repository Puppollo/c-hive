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

const int building_type_NO      = -1 ;
const int building_type_MAIN    = 0 ;
const int building_type_NODE    = 1 ;
const int building_type_FACTORY = 2 ;
const int building_owner_NEUTRAL = 0 ;

const int building_NODE_WORK_RANGE = 10 ;

const int unit_type_STD = 0 ;

const int world_X_COUNT = 256 ;
const int world_Y_COUNT = 256 ;

const int screen_X_CELL_SIZE = 32 ; // 2^5
const int screen_Y_CELL_SIZE = 32 ;
const int screen_X_CELL_COUNT = 20 ; //640/32
const int screen_Y_CELL_COUNT = 15 ; //480/32

const int screen_X_CELL_CENTER = 16 ;
const int screen_Y_CELL_CENTER = 16 ;

const int MAX_RANGE = 5 ;
//---------------------------------------------------------------------------
void MoveTo(int &src_x,int &src_y,int dst_x,int dst_y) ;
int inRange(int x,int y,int x0,int y0,int r) ;
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
//---------------------------------------------------------------------------
const int building_param_COUNT = 4;
struct s_building
{
  int r ;
  int y_frame ;      // animation
  int type ;         // ��� ������ (x_frame)
  float param[building_param_COUNT] ;
  int owner ;            // �������������� ������-���� ������
} ;
//---------------------------------------------------------------------------
class c_World:public c_grObject
{
  private :
    int sprite_building_dx,sprite_building_dy ; // not USED
  public :
    int TIME ;
    s_building building[world_X_COUNT][world_Y_COUNT] ;
    c_World(c_Sprite *s) ;
    HRESULT Draw(IDirectDrawSurface *DDSSurface,int current_x_screen,int current_y_screen,FILE *log_file=NULL) ;
} ;
//---------------------------------------------------------------------------
c_World::c_World(c_Sprite *s)
:c_grObject(s,0,0)
{
  sprite_building_dx =0;//screen_X_CELL_SIZE-((s->GetYSize())/2);
  sprite_building_dy =0;//(-1*(s->GetYSize()))+screen_Y_CELL_SIZE;
  TIME = 0 ;
  for(int x=0;x<world_X_COUNT;x++)
    for(int y=0;y<world_Y_COUNT;y++)
    {
      building[x][y].type = building_type_NO ;
      building[x][y].y_frame=0 ;
      building[x][y].r = 0 ;
      building[x][y].owner = building_owner_NEUTRAL ;
      for(int p=0;p<building_param_COUNT;p++)
        building[x][y].param[p]=1 ;
    } ;
} ;
//---------------------------------------------------------------------------
HRESULT c_World::Draw(IDirectDrawSurface *DDSSurface,int current_x_screen,int current_y_screen,FILE *log_file)
{
  HRESULT res;
  int x_end = current_x_screen+screen_X_CELL_COUNT ,
      y_end = current_y_screen+screen_Y_CELL_COUNT ;
  for(int x=current_x_screen;x<x_end;x++)
    for(int y=current_y_screen;y<y_end;y++)
      if(building[x][y].type != building_type_NO)
      {
        SetCoord(((x-current_x_screen)<<5)+sprite_building_dx,((y-current_y_screen)<<5)+sprite_building_dy) ;
        SetFrame(building[x][y].type,building[x][y].y_frame) ;
        res=c_grObject::Draw(DDSSurface,log_file) ;
        if(res!=DD_OK)return res;
      } ;
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
        case building_type_NODE : // ����
          if(inRange((int)PInfo.x,(int)PInfo.y,
                     (x<<5)+screen_X_CELL_CENTER,
                     (y<<5)+screen_Y_CELL_CENTER,
                     (world->building[x][y]).r)) // � ���� �������� �����
          {
            if(inRange((int)PInfo.x,(int)PInfo.y,
                       (x<<5)+screen_X_CELL_CENTER,
                       (y<<5)+screen_Y_CELL_CENTER,
                       building_NODE_WORK_RANGE))
            {
              PInfo.dx = (world->building[x][y]).param[0] ;
              PInfo.dy = (world->building[x][y]).param[1] ;
              UInfo.TimeToTurn = (world->building[x][y]).param[2] ;
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
        case building_type_MAIN : // ����
          if(cell_x==x && cell_y==y) // � ��� �� ������ ��� � ����
          {
            PInfo.CurrentTurn=0;     // ������������ �������
            PInfo.x_frame = 0;
            PInfo.x = 600.0 ;
            PInfo.y = 400.0 ;
          } ;
        break;
        case building_type_FACTORY : // �����
          //...
        break ;
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
struct s_ParticicleInfo
{
  // ����������� ���������
  int TurnTime ;                // ����� ��� ���� (�������� �������)
  int GenerateTime ;            // �������� ������������� �������
  int TurnCount ;               // ����� ������ ������� (���-�� �����)
  int GenerateCountPerTurn;     // ���-�� ������������ ������ � ���
  int width,height ;            // ������� ����������
  int enable ;                  // �������
  float dx,dy ;                 // ���������� ������
  int dxVariation,dyVariation;  // �������� ��������� ���������
  int x_frame_count ;           // �������� �� x (���������)
  int y_frame_count ;           // ���-�� ����� ������
  int ParticicleCount ;         // ���-�� ������
  // �� ����������� ���������
  int isLiveCount ;             // ������� ������������ ������
  int ChangeFramePoint ;        // ��� ������� ������� ����� �����
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
    if(TIME % info.GenerateTime == 0) // ������������� ������
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
        particicle[pc].PInfo.x = random(info.width) +((GetCoordX()<<5)+screen_X_CELL_CENTER) ; // coordinates
        particicle[pc].PInfo.y = random(info.height)+((GetCoordY()<<5)+screen_Y_CELL_CENTER) ; // <<5 = *32
        particicle[pc].PInfo.x_frame = 0;
        particicle[pc].PInfo.y_frame = random(info.y_frame_count) ;
        particicle[pc].PInfo.CurrentTurn = 0;
        particicle[pc].PInfo.isLive = 1 ;
        particicle[pc].PInfo.dx=info.dx+(random((info.dxVariation<<1)+1)-info.dxVariation)/10.0;
        particicle[pc].PInfo.dy=info.dy+(random((info.dyVariation<<1)+1)-info.dyVariation)/10.0;
       } ;
    } ; // end gen time

  if(TIME % info.TurnTime == 0)  // ����������� ������
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
#endif
