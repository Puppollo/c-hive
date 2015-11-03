/*
*  c_Particicle
*  частицы "поддержки", класс для
*  создания частиц переносящих минералы
*  и энергию
*/
#ifndef c_HiveParticicleSH
#define c_HiveParticicleSH
//---------------------------------------------------------------------------
#include <stdio.h>
#include <ddraw.h>

#include "HiveMain.h"
//---------------------------------------------------------------------------
struct s_PInfo
{
  float x,y,dx,dy;
  int x_frame,type ;
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
  int ChangeDirection_flag ; // для определения можно-ли сменить направление
  int param ; // используется для опеределения сколько веса несет(может нести) частица
  //...
} ;
//---------------------------------------------------------------------------
struct s_Particicle
{
  s_PInfo PInfo ;
  s_UInfo UInfo ;
  void Move(int TIME,s_building building[world_X_COUNT][world_Y_COUNT],s_Player *player,FILE *log_file) ;
  void OutLog(FILE *log_file) ;
} ;
//---------------------------------------------------------------------------
void s_Particicle::OutLog(FILE *log_file)
{
  if(log_file)
  {
    fprintf(log_file,"---%4d---\n",PInfo.CurrentTurn) ;
    fprintf(log_file,"   coord  (%3.2f;%3.2f)\n",PInfo.x,PInfo.y) ;
    fprintf(log_file,"   dcoord (%3.2f;%3.2f)\n",PInfo.dx,PInfo.dy) ;
    fprintf(log_file,"   type %d\n",PInfo.type) ;
    fprintf(log_file,"   enable %d\n",UInfo.Enable) ;
    fprintf(log_file,"   SkipEnableCount %d\n",UInfo.SkipEnableCount) ;
    fprintf(log_file,"   isLive %d\n",PInfo.isLive) ;
    fprintf(log_file,"-------------\n") ;
  } ;
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
  int type_count ;              // кол-во типов частиц
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
    int pTIME ;
  public :
    c_Particicle(c_Sprite *s,int x,int y,s_ParticicleInfo i) ;
    void SetEnable(int e=1){if(e==0)info.enable=0;else info.enable=1;};
    void Turn(int TIME,s_building building[world_X_COUNT][world_Y_COUNT],s_Player *player,FILE *log_file=NULL) ;
    HRESULT Draw(RECT screen,int Screen_X_Coord,int Screen_Y_Coord,
                 IDirectDrawSurface *DDSSurface,FILE *log_file=NULL) ;
    void SaveInfo(FILE *save_file){fwrite(&info,sizeof(s_ParticicleInfo),1,save_file);} ;
    void LoadInfo(FILE *load_file){fread (&info,sizeof(s_ParticicleInfo),1,load_file);} ;
    int GetHeight() {return info.height;};
    int GetWidth()  {return info.width;};
    void OutLog() ;
    void OutLogEx(FILE *log_file=NULL) ;
    void Release(){delete []particicle;} ;
} ;
//---------------------------------------------------------------------------
c_Particicle::c_Particicle(c_Sprite *s,int x,int y,s_ParticicleInfo i)
:c_grObject(s,x,y)
{
  pTIME=0;
  info = i ;
  info.isLiveCount =0 ;
  info.ChangeFramePoint=info.TurnCount/info.x_frame_count ;
  if(info.ParticicleCount>particicle_MAX_COUNT)info.ParticicleCount=particicle_MAX_COUNT ;
  particicle = new s_Particicle[info.ParticicleCount] ;
  for(int pc=0;pc<info.ParticicleCount;pc++)
  {
    particicle[pc].PInfo.ID = pc ;
    particicle[pc].UInfo.TimeToTurn = particicle_TIMETOTURN ;
    particicle[pc].UInfo.TimeToChangeDirection = 30 ;
    particicle[pc].UInfo.SkipEnableCount = 0 ;
    particicle[pc].UInfo.Enable = 0 ;
    particicle[pc].UInfo.param=0;
    particicle[pc].UInfo.ChangeDirection_flag=1;
  } ;
} ;
//---------------------------------------------------------------------------
void c_Particicle::Turn(int TIME,s_building building[world_X_COUNT][world_Y_COUNT],s_Player *player,FILE *log_file)
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
        particicle[pc].PInfo.type = particicle_type_SUPPLY_EMPTY ;
        particicle[pc].PInfo.CurrentTurn = 0;
        particicle[pc].UInfo.TimeToTurn=particicle_TIMETOTURN;
        particicle[pc].UInfo.TimeToChangeDirection=20;
        particicle[pc].PInfo.isLive = 1 ;
        particicle[pc].PInfo.dx=info.dx+(random((info.dxVariation<<1)+1)-info.dxVariation)/10.0;
        particicle[pc].PInfo.dy=info.dy+(random((info.dyVariation<<1)+1)-info.dyVariation)/10.0;
        if(particicle[pc].PInfo.dx==0.0 && particicle[pc].PInfo.dy==0.0)particicle[pc].PInfo.dx=1.0;
        particicle[pc].UInfo.param=0;
        particicle[pc].UInfo.SkipEnableCount=0;
        particicle[pc].UInfo.Enable=0;
       } ;
    } ; // end gen time

  if(TIME % info.TurnTime == 0)  // перемещение частиц
  {
    pTIME++;
    if(pTIME>10000)pTIME=0;
    if(log_file)fprintf(log_file,"   particicle turn\n") ;
    if(log_file)fprintf(log_file,"   info.isLiveCount %d\n",info.isLiveCount) ;
    int N = info.isLiveCount ;
    for(int pc=0;pc<N;pc++)
    {
      if(log_file)fprintf(log_file,"   particicle[%d] move\n",pc) ;
      if(particicle[pc].PInfo.isLive)
        particicle[pc].Move(pTIME,building,player,log_file) ;
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
                                particicle[pc].PInfo.x_frame,particicle[pc].PInfo.type,
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
  fprintf(log,"type_count         %d\n",info.type_count) ;
  fprintf(log,"ParticicleCount       %d\n",info.ParticicleCount) ;
  fprintf(log,"ChangeFramePoint      %d\n",info.ChangeFramePoint) ;
  fclose(log);
} ;
//---------------------------------------------------------------------------
void c_Particicle::OutLogEx(FILE *log_file)
{
  int N = info.isLiveCount ;
  for(int pc=0;pc<N;pc++)
    if(particicle[pc].PInfo.isLive)
      particicle[pc].OutLog(log_file) ;
} ;
//---------------------------------------------------------------------------
void s_Particicle::Move(int TIME,s_building building[world_X_COUNT][world_Y_COUNT],s_Player *player,FILE *log_file)
{
  if(UInfo.SkipEnableCount>0)
    UInfo.SkipEnableCount--;
  if(UInfo.SkipEnableCount<=0)
    UInfo.Enable =0 ;
  int cell_x=((int)PInfo.x)>>5, cell_y=((int)PInfo.y)>>5 ;
  int x_start=cell_x-MAX_RANGE ;
  if(x_start<0)x_start=0 ;
  int x_end  =cell_x+MAX_RANGE ;
  if(x_end>=world_X_COUNT)x_end=world_X_COUNT-1 ;
  int y_start=cell_y-MAX_RANGE ;
  if(y_start<0)y_start=0 ;
  int y_end  =cell_y+MAX_RANGE ;
  if(y_end>=world_Y_COUNT)y_end=world_Y_COUNT-1 ;
  //перемещение
  if(UInfo.Enable==0 && UInfo.ChangeDirection_flag && PInfo.CurrentTurn % UInfo.TimeToChangeDirection==0)
  {
    PInfo.dx = (random(21)-10)/10.0 ;
    PInfo.dy = (random(21)-10)/10.0 ;
    if(PInfo.dx==0.0 && PInfo.dy==0.0)
      PInfo.dx=0.2 ;
  } ;
  if(TIME % UInfo.TimeToTurn==0)
  {
    PInfo.x+=PInfo.dx;
    PInfo.y+=PInfo.dy;
    UInfo.ChangeDirection_flag=1;
    PInfo.CurrentTurn++;
  };
  // просмотреть ячейки вокруг себя
  for(int x=x_start;x<x_end;x++)
    for(int y=y_start;y<y_end;y++)
    {
      int owner = building[x][y].owner;
      switch(building[x][y].type)
      {
        //////////////////////////////////////////////////
        case building_type_MAIN : // core ядро
          if(cell_x==x && cell_y==y && UInfo.Enable==0) // в той же клетке что и ядро
          {
            PInfo.CurrentTurn=0;     // восстановить энергию
            PInfo.x_frame = 0;
            UInfo.ChangeDirection_flag=0;
            UInfo.Enable=1;
            UInfo.SkipEnableCount=50;
            return ;
          } ;
        break;
        //////////////////////////////////////////////////
        case building_type_BASE :
          if(cell_x==x && cell_y==y && (building[x][y]).enable && PInfo.type!=particicle_type_SUPPLY_EMPTY)
          {
            switch(PInfo.type) // доставка груза
            {
              case particicle_type_SUPPLY_MINERAL :
                if((int)building[x][y].param[4]<9990)
                {
                  building[x][y].param[4]+=UInfo.param ;
                  UInfo.param=0;
                };
              break;
              case particicle_type_SUPPLY_ENERGY :
                if((int)building[x][y].param[5]<9990)
                {
                  building[x][y].param[5]+=UInfo.param ;
                  UInfo.param=0;
                };
              break;
            } ;
            PInfo.CurrentTurn+=building_BASE_ENERGY_REDUCED ;
            PInfo.type = particicle_type_SUPPLY_EMPTY ;
            int dx=building[x][y].param[2],dy=building[x][y].param[3];
            PInfo.x = ((x+dx)<<5)+screen_X_CELL_CENTER ;
            PInfo.y = ((y+dy)<<5)+screen_Y_CELL_CENTER ;
            UInfo.SkipEnableCount=0;
            UInfo.ChangeDirection_flag=0;
            return ;
          } ;
        break;
        //////////////////////////////////////////////////
        case building_type_FACTORY : // завод
          if(cell_x==x && cell_y==y && (building[x][y]).enable && PInfo.type!=particicle_type_SUPPLY_EMPTY)
          {
            switch(PInfo.type) // доставка груза
            {
              case particicle_type_SUPPLY_MINERAL :
                if((int)building[x][y].param[4]<9990)
                {
                  building[x][y].param[4]+=UInfo.param ;
                  UInfo.param=0;
                };
              break;
              case particicle_type_SUPPLY_ENERGY :
                if((int)(building[x][y]).param[5]<9990)
                {
                  building[x][y].param[5]+=UInfo.param ;
                  UInfo.param=0;
                };
              break;
            } ;
            PInfo.type = particicle_type_SUPPLY_EMPTY ;
            PInfo.CurrentTurn+=building_FACTORY_ENERGY_REDUCED ;
            int dx=building[x][y].param[2],dy=building[x][y].param[3];
            PInfo.x = ((x+dx)<<5)+screen_X_CELL_CENTER ;
            PInfo.y = ((y+dy)<<5)+screen_Y_CELL_CENTER ;
            UInfo.SkipEnableCount=0;
            UInfo.ChangeDirection_flag=0;
            return ;
          } ;
        break ;
        //////////////////////////////////////////////////
        case building_type_CONSTRUCTING : // стройка
          if(cell_x==x && cell_y==y && PInfo.type == particicle_type_SUPPLY_EMPTY && building[cell_x][cell_y].enable) // работать может только "пустая частица"
          {
            PInfo.CurrentTurn+=building_CONSTRUCTING_ENERGY_REDUCED ;
            building[x][y].param[1]--;
            // ...change y frame
            if(building[x][y].param[1]<=0)//проверка конец строительства здания
            {
              building[x][y].type=(building[x][y]).param[0];
              building[x][y].r=0;
              building[x][y].y_frame=0;
              building[x][y].param[2]=building_exit_coord_X;
              building[x][y].param[3]=building_exit_coord_Y;
              building[x][y].param[4]=0;
              building[x][y].param[5]=0;
              switch((building[x][y]).type) // что за здание построено
              {
                case building_type_POWER :
                 (building[x][y]).HP = building_POWER_HP ;
                 (building[x][y]).maxHP = building_POWER_HP ;
                break;
                case building_type_FACTORY :
                  (building[x][y]).param[0]=-1;//завод ничего не производит
                  (building[x][y]).param[1]=0;
                  (building[x][y]).HP = building_FACTORY_HP ;
                  (building[x][y]).maxHP = building_FACTORY_HP ;
                break;
                case building_type_SPEED :
                  (building[x][y]).param[0]=1;
                  (building[x][y]).param[1]=0;
                  (building[x][y]).HP = building_SPEED_HP ;
                  (building[x][y]).maxHP = building_SPEED_HP ;
                break;
                case building_type_CHARGE :
                  (building[x][y]).HP = building_CHARGE_HP ;
                  (building[x][y]).maxHP = building_CHARGE_HP ;
                break;
                case building_type_MINE :
                  (building[x][y]).HP = building_MINE_HP ;
                  (building[x][y]).maxHP = building_MINE_HP ;
                break;
                //... more buildings
              } ;
            } ;
            int dx=(building[x][y].param[2]),dy=(building[x][y]).param[3];
            PInfo.x = ((x+dx)<<5)+screen_X_CELL_CENTER ;
            PInfo.y = ((y+dy)<<5)+screen_Y_CELL_CENTER ;
            UInfo.SkipEnableCount=0;
            UInfo.ChangeDirection_flag=0;
            return ;
          } ;
        break;
        //////////////////////////////////////////////////
        case building_type_MINE :
          if(cell_x==x && cell_y==y && (building[x][y]).enable && PInfo.type==particicle_type_SUPPLY_EMPTY)// шахта работать может только "пустая" частица
          {
            int mineral_sx=x-1,mineral_ex=x+1,
                mineral_sy=y-1,mineral_ey=y+1;
            if(mineral_sx<0)mineral_sx=0;
            if(mineral_ex>=world_X_COUNT)mineral_ex=world_X_COUNT-1;
            if(mineral_sy<0)mineral_sy=0;
            if(mineral_ey>=world_Y_COUNT)mineral_ey=world_Y_COUNT-1;
            for(int mineral_x=mineral_sx;mineral_x<=mineral_ex;mineral_x++)  // поиск минералов вокруг шахты
              for(int mineral_y=mineral_sy;mineral_y<=mineral_ey;mineral_y++)// поиск минералов вокруг шахты
                if((building[mineral_x][mineral_y]).type==building_type_MINERAL)
                {
                  int mineral_resurce_count = (building[mineral_x][mineral_y]).param[0];
                  if(mineral_resurce_count>0) // месторождение не исчерпано
                  {
                    mineral_resurce_count--;
                    (building[mineral_x][mineral_y]).param[0]=mineral_resurce_count ;
                    //... change y_frame  (изменяется с уменьшением кол-ва ресурсов)
                    PInfo.CurrentTurn+=building_MINE_ENERGY_REDUCED ;
                    PInfo.type = particicle_type_SUPPLY_MINERAL ;
                    UInfo.param=(player[owner]).supply_carring_count;
                    break;
                  }
                  else // месторождение исчерпано
                    (building[mineral_x][mineral_y]).type=building_type_NO;
                };
            int dx=(building[x][y].param[2]),dy=(building[x][y]).param[3];
            PInfo.x = ((x+dx)<<5)+screen_X_CELL_CENTER ;
            PInfo.y = ((y+dy)<<5)+screen_Y_CELL_CENTER ;
            UInfo.SkipEnableCount=0;
            UInfo.ChangeDirection_flag=0;
            return ;
          } ;
        break;
        //////////////////////////////////////////////////
        case building_type_CHARGE : // зарядник
          if(cell_x==x && cell_y==y && (building[x][y]).enable)
          {
            if(PInfo.CurrentTurn>0)  // нужно заряжать частицу
            {
              PInfo.CurrentTurn=0;
              PInfo.x_frame=0;
              UInfo.ChangeDirection_flag=0;
            } ;
            return ;
          };
        break;
        //////////////////////////////////////////////////
        case building_type_SPEED : // ускоритель
          if(cell_x==x && cell_y==y && (building[x][y]).enable)
          {
            if(UInfo.TimeToTurn>1) // нужно ускорять
            {
              UInfo.TimeToTurn=1;
              PInfo.x_frame=0;
              UInfo.ChangeDirection_flag=0;
            } ;
            return ;
          };
        break;
        //////////////////////////////////////////////////
        case building_type_POWER :
        if(cell_x==x && cell_y && (building[x][y]).enable && PInfo.type==particicle_type_SUPPLY_EMPTY)
          {
            PInfo.type = particicle_type_SUPPLY_ENERGY ;
            UInfo.param = (player[owner]).supply_carring_count ;
            int dx=(building[x][y].param[2]),dy=(building[x][y]).param[3];
            PInfo.x = ((x+dx)<<5)+screen_X_CELL_CENTER ;
            PInfo.y = ((y+dy)<<5)+screen_Y_CELL_CENTER ;
            PInfo.CurrentTurn+=building_POWER_ENERGY_REDUCED ;
            UInfo.SkipEnableCount=0;
            UInfo.ChangeDirection_flag=0;
            return ;
          } ;
        break;
        //////////////////////////////////////////////////
        case building_type_NODE : // маяк
        {
          int correct_type = building[x][y].param[PInfo.type+3] ;
          if(building[x][y].enable && correct_type &&
              inRange((long)PInfo.x,(long)PInfo.y,
                     (x<<5)+screen_X_CELL_CENTER,
                     (y<<5)+screen_Y_CELL_CENTER,
                     building[x][y].r,log_file)) // в зоне действия маяка
          {
            UInfo.ChangeDirection_flag=0;
            if(inRange((long)PInfo.x,(long)PInfo.y,
                       (x<<5)+screen_X_CELL_CENTER,
                       (y<<5)+screen_Y_CELL_CENTER,
                       building_NODE_WORK_RANGE))
            {
              PInfo.dx = building[x][y].param[0] ;
              PInfo.dy = building[x][y].param[1] ;
              UInfo.Enable=1 ;
              UInfo.SkipEnableCount = (int)building[x][y].param[2];
            }
            else if(UInfo.Enable==0)
              MoveTo(PInfo.x,PInfo.y,(x<<5)+screen_X_CELL_CENTER,(y<<5)+screen_Y_CELL_CENTER,PInfo.dx,PInfo.dy) ;
          };
        };
        break ;
        //////////////////////////////////////////////////
     } ;
    } ;
} ;
//---------------------------------------------------------------------------
#endif