/*
*   c_ParticicleC
*   "Боевые" частицы, класс для
*   создания пушек (боевых зданий)
*
*/
#ifndef c_HiveParticicleCH
#define c_HiveParticicleCH
//---------------------------------------------------------------------------
#include <stdio.h>
#include <ddraw.h>

#include "HiveMain.h"
//---------------------------------------------------------------------------
struct s_PCInfo
{
  float x,y,dx,dy;
  int x_frame,y_frame ;
  int CurrentTurn;
  int isLive;
  unsigned ID ;
} ;
struct s_UCInfo
{
  int TimeToTurn ;
  int TimeToChangeDirection ;
  int Type;
  int Enable ;
  //...
} ;
//---------------------------------------------------------------------------
struct s_ParticicleC
{
  s_PCInfo PInfo ;
  s_UCInfo UInfo ;
  void Move(c_World *world) ;
} ;
//---------------------------------------------------------------------------
struct s_ParticicleCInfo
{
  // указываемые параметры
  int type;
  // не указываемые параметры
  int isLiveCount ;             // счетчик существующих частиц
  int ChangeFramePoint ;        // для расчета времени смены кадра
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
} ;
//===========================================================================
class c_ParticicleCombat:public c_grObject
{
  private :
    s_ParticicleC *particicle;
    s_ParticicleCInfo info ;
  public :
    c_ParticicleCombat(c_Sprite *s,int x,int y,s_ParticicleCInfo i) ;
    void SetEnable(int e=1){if(e==0)info.enable=0;else info.enable=1;};
    void Turn(int TIME,c_World *world,FILE *log_file=NULL) ;
    HRESULT Draw(RECT screen,int Screen_X_Coord,int Screen_Y_Coord,
                 IDirectDrawSurface *DDSSurface,FILE *log_file=NULL) ;
    void SaveInfo(FILE *save_file){fwrite(&info,sizeof(s_ParticicleInfo),1,save_file);} ;
    void LoadInfo(FILE *load_file){fread (&info,sizeof(s_ParticicleInfo),1,load_file);} ;
    void OutLog() ;
    void Release(){delete []particicle;} ;
} ;
//---------------------------------------------------------------------------
c_ParticicleCombat::c_ParticicleCombat(c_Sprite *s,int x,int y,s_ParticicleCInfo i)
:c_grObject(s,x,y)
{
  info = i ;
  switch(info.type)
  {
    case particicle_combat_type_IMPACTOR :
      info.TurnTime=1;
      info.GenerateTime=1;
    //...
    break;
    //...
  } ;
  info.isLiveCount =0 ;
  info.ChangeFramePoint=info.TurnCount/info.x_frame_count ;
  if(info.ParticicleCount>particicle_MAX_COUNT)info.ParticicleCount=particicle_MAX_COUNT ;
  particicle = new s_ParticicleC[info.ParticicleCount] ;
  for(int pc=0;pc<info.ParticicleCount;pc++)
  {
    particicle[pc].PInfo.ID = pc ;
    particicle[pc].UInfo.TimeToTurn = 2 ;
    particicle[pc].UInfo.TimeToChangeDirection = 20 ;
  } ;
} ;
//---------------------------------------------------------------------------
void c_ParticicleCombat::Turn(int TIME,c_World *world,FILE *log_file)
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
HRESULT c_ParticicleCombat::Draw(RECT screen,int Screen_X_Coord,int Screen_Y_Coord,
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
void c_ParticicleCombat::OutLog()
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
void s_ParticicleC::Move(c_World *world)
{
  int cell_x=((int)PInfo.x)>>5, cell_y=((int)PInfo.y)>>5 ;
  switch(UInfo.Type)
  {
    //...
  } ;
  if(world->TIME % UInfo.TimeToTurn==0)
  {
    PInfo.x+=PInfo.dx;
    PInfo.y+=PInfo.dy;
  };
  PInfo.CurrentTurn++;
} ;
//---------------------------------------------------------------------------
#endif