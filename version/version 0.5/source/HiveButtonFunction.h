#ifndef HiveButtonFunctionH
#define HiveButtonFunctionH
//---------------------------------------------------------------------------
#include <stdio.h>
#include <ddraw.h>
#include <windows.h>
#include <windowsx.h>

#include <c_Sprite.h>
#include <c_Font.h>
#include "c_HiveElement.h"
#include "HiveMain.h"
//---------------------------------------------------------------------------
const int font_common_title_X = 3 ;
const int font_common_title_Y = 5 ;
const int font_common_process_X = 146 ;
const int font_common_process_Y = 5 ;
const int font_common_HP_X = 28 ;
const int font_common_HP_Y = 50 ;
const int font_common_MINERAL_X = 176;
const int font_common_MINERAL_Y = 33;
const int font_common_ENERGY_X  = 176;
const int font_common_ENERGY_Y  = 46;
const int font_common_MRL_X = 107;
const int font_common_MRL_Y = 33;
const int font_common_ENY_X = 107;
const int font_common_ENY_Y = 46;

const int font_build_X  = 51 ;
const int font_build_Y  = 49 ;

const int action_NO               = 0 ;
const int action_BUILDING_CLICK   = 1 ; // нажатие на здание
const int action_DESTROY_BUILDING = 2 ; // уничтожить здание
const int action_SHOW_TERRITORY   = 3 ; // показать территорию
const int action_BUILD_NEXT       = 4 ; // нажатие на кнопку след. здание
const int action_BUILD_PREV       = 5 ; // нажатие на кнопку перд. здание
const int action_BUILD_NODE       = 6 ; // строить маяк
const int action_BUILD_FACTORY    = 7 ; // строить завод
const int action_BUILD_MINE       = 8 ; // строить шахту
const int action_BUILD_CHARGE     = 9 ; // строить зарядку
const int action_BUILD_SPEED      =10 ; // строить ускоритель
const int action_BUILD_POWER      =11 ; // строить энергостанцию
const int action_BUILDING_ENABLE  =12 ; // вкл/выкл здание
const int action_DIRECTION_FOR_EMPTY  = 13 ; // направлять epmty
const int action_DIRECTION_FOR_MINERAL= 14 ; // направлять mineral
const int action_DIRECTION_FOR_ENERGY = 15 ; // направлять energy
const int action_SET_DIRECTION_U   = 16 ; //
const int action_SET_DIRECTION_UR  = 17 ; //
const int action_SET_DIRECTION_R   = 18 ; //
const int action_SET_DIRECTION_DR  = 19 ; //
const int action_SET_DIRECTION_D   = 20 ; //
const int action_SET_DIRECTION_DL  = 21 ; //
const int action_SET_DIRECTION_L   = 22 ; //
const int action_SET_DIRECTION_UL  = 23 ; //


const int screen_panel_BUILD_NODE      = 0 ;
const int screen_panel_BUILD_FACTORY   = 1 ;
const int screen_panel_BUILD_MINE      = 2 ;
const int screen_panel_BUILD_CHARGE    = 3 ;
const int screen_panel_BUILD_SPEED     = 4 ;
const int screen_panel_BUILD_POWER     = 5 ;
const int screen_panel_COMMON_NO       = 6 ;
const int screen_panel_COMMON_BUILDING = 7 ;

const int emtBuildingSetDirection_FRAME_X = 0 ;
const int emtBuildingSetDirection_FRAME_Y = 2 ;
const int emtBuildingSetDirectionU_X   =  77;
const int emtBuildingSetDirectionU_Y   =  20;
const int emtBuildingSetDirectionUR_X  =  90;
const int emtBuildingSetDirectionUR_Y  =  20;
const int emtBuildingSetDirectionR_X   =  90;
const int emtBuildingSetDirectionR_Y   =  33;
const int emtBuildingSetDirectionDR_X  =  90;
const int emtBuildingSetDirectionDR_Y  =  46;
const int emtBuildingSetDirectionD_X   =  77;
const int emtBuildingSetDirectionD_Y   =  46;
const int emtBuildingSetDirectionDL_X  =  64;
const int emtBuildingSetDirectionDL_Y  =  46;
const int emtBuildingSetDirectionL_X   =  64;
const int emtBuildingSetDirectionL_Y   =  33;
const int emtBuildingSetDirectionUL_X  =  64;
const int emtBuildingSetDirectionUL_Y  =  20;

const int emtDirectionForEmpty_FRAME_X   = 6 ;
const int emtDirectionForEmpty_FRAME_Y   = 2 ;
const int emtDirectionForEmpty_X = 47 ;
const int emtDirectionForEmpty_Y = 18 ;
const int emtDirectionForMineral_FRAME_X = 7 ;
const int emtDirectionForMineral_FRAME_Y = 2 ;
const int emtDirectionForMineral_X = 47 ;
const int emtDirectionForMineral_Y = 32 ;
const int emtDirectionForEnergy_FRAME_X  = 8 ;
const int emtDirectionForEnergy_FRAME_Y  = 2 ;
const int emtDirectionForEnergy_X = 47 ;
const int emtDirectionForEnergy_Y = 46 ;

const int emtBuildNext_X = 21 ;
const int emtBuildNext_Y = 46 ;
const int emtBuildNext_FRAME_X = 2 ;
const int emtBuildNext_FRAME_Y = 2 ;

const int emtBuildPrev_X = 3 ;
const int emtBuildPrev_Y = 46 ;
const int emtBuildPrev_FRAME_X = 1 ;
const int emtBuildPrev_FRAME_Y = 2 ;

const int emtBuild_X = 21 ;
const int emtBuild_Y = 16 ;

const int emtBuildNode_FRAME_X    =0 ;
const int emtBuildNode_FRAME_Y    =0 ;
const int emtBuildFactory_FRAME_X =1 ;
const int emtBuildFactory_FRAME_Y =0 ;
const int emtBuildMine_FRAME_X    =2 ;
const int emtBuildMine_FRAME_Y    =0 ;
const int emtBuildCharge_FRAME_X  =3 ;
const int emtBuildCharge_FRAME_Y  =0 ;
const int emtBuildSpeed_FRAME_X   =4 ;
const int emtBuildSpeed_FRAME_Y   =0 ;
const int emtBuildPower_FRAME_X   =5 ;
const int emtBuildPower_FRAME_Y   =0 ;

const int emtDestroyBuilding_X = 176 ;
const int emtDestroyBuilding_Y = 4 ;
const int emtDestroyBuilding_FRAME_X = 4 ;
const int emtDestroyBuilding_FRAME_Y = 2 ;

const int emtShowTerritory_X = 160 ;
const int emtShowTerritory_Y = 4 ;
const int emtShowTerritory_FRAME_X = 3 ;
const int emtShowTerritory_FRAME_Y = 2 ;

const int emtBuildingEnable_X = 160 ;
const int emtBuildingEnable_Y = 4 ;
const int emtBuildingEnable_FRAME_X = 5 ;
const int emtBuildingEnable_FRAME_Y = 2 ;
//...
//---------------------------------------------------------------------------
void DummyFunction(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // пустышка

void OnBuildingSetDirectionU_click  (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Верх
void OnBuildingSetDirectionUL_click (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Верх-Лево
void OnBuildingSetDirectionL_click  (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Лево
void OnBuildingSetDirectionDL_click (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Низ-Лево
void OnBuildingSetDirectionD_click  (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Низ
void OnBuildingSetDirectionDR_click (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Низ-Право
void OnBuildingSetDirectionR_click  (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Право
void OnBuildingSetDirectionUR_click (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Верх-Право

void OnDirectionForEmpty_click  (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ;
void OnDirectionForMineral_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ;
void OnDirectionForEnergy_click (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ;

void OnBuildNext_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // прокрутка зданий для постройки
void OnBuildPrev_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // прокрутка зданий для постройки

void OnBuildMine_click   (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // строить шахту
void OnBuildFactory_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // строить завод
void OnBuildNode_click   (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // строить маяк
void OnBuildSpeed_click  (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // строить ускоритель
void OnBuildCharge_click (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // строить перезарядку
void OnBuildPower_click  (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // строить энергостанцию

void OnDestroyBuilding_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // уничтожить здание

void OnShowTerritory_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ;// показать территорию

void OnBuildingEnable_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // вкл/выкл здание
//... more function
//---------------------------------------------------------------------------
const int hiveelements_param_COUNT =2 ;
class c_HiveElements
{
  private :
    c_World *world ;
    s_mouse *mouse ;
    c_Sprite *sprite ;
    int build_panel_x,build_panel_y ;
    int common_panel_x,common_panel_y ;
    int build_screen_panel,common_screen_panel;
    c_Font *font ;
    int player_ID ;
    c_Element *emtBuildingSetDirectionU,
              *emtBuildingSetDirectionUR,
              *emtBuildingSetDirectionR,
              *emtBuildingSetDirectionDR,
              *emtBuildingSetDirectionD,
              *emtBuildingSetDirectionDL,
              *emtBuildingSetDirectionL,
              *emtBuildingSetDirectionUL,

              *emtDirectionForEmpty,
              *emtDirectionForMineral,
              *emtDirectionForEnergy,

              *emtBuildNext,  // building scroll
              *emtBuildPrev , // building scroll

              *emtBuildNode,
              *emtBuildFactory,
              *emtBuildMine,
              *emtBuildCharge,
              *emtBuildSpeed,
              *emtBuildPower,

              *emtDestroyBuilding,

              *emtShowTerritory,

              *emtBuildingEnable;
    //... more elements
    //supply
    void DirectionButtonFrameCheck(int particicle_dx,int particicle_dy) ;
    HRESULT DrawDirectionButton(RECT screen,IDirectDraw *DDSSurface,FILE *log_file) ;
  public :
    int action,param[hiveelements_param_COUNT] ;
    c_HiveElements(c_World *w,s_mouse *m,c_Sprite *s,
                   int bpx,int bpy,int cpx,int cpy,
                   c_Sprite *font_sprite,int pID,FILE *log_file=NULL) ;
    void Turn(char key,FILE *log_file=NULL) ;
    void CheckAction(FILE *log_file=NULL) ;
    int GetBuildScreenPanel() {return build_screen_panel;};
    int GetCommonScreenPanel(){return common_screen_panel;};
    HRESULT Draw(RECT screen,IDirectDrawSurface *DDSSurface,FILE *log_file=NULL) ;
    void Release(FILE *log_file=NULL) ;
} ;
//---------------------------------------------------------------------------
void c_HiveElements::DirectionButtonFrameCheck(int particicle_dx,int particicle_dy)
{
  FILE *f=fopen("LOG\\Check.log","w+");
  fprintf(f,"%d %d",particicle_dx,particicle_dy) ;
  fclose(f) ;
  if(particicle_dx==1)
  {
    if(particicle_dy==-1) // direction UR
    {
      emtBuildingSetDirectionU ->SetFrameY(emtBuildingSetDirection_FRAME_Y) ;
      emtBuildingSetDirectionUL->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionL ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionDL->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionD ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionDR->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionR ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionUR->SetFrameY(emtBuildingSetDirection_FRAME_Y+1);
    }
    else
    if(particicle_dy==1)  // direction DR
    {
      emtBuildingSetDirectionU ->SetFrameY(emtBuildingSetDirection_FRAME_Y) ;
      emtBuildingSetDirectionUL->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionL ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionDL->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionD ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionDR->SetFrameY(emtBuildingSetDirection_FRAME_Y+1);
      emtBuildingSetDirectionR ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionUR->SetFrameY(emtBuildingSetDirection_FRAME_Y);
    }
    else                  // direction R
    {
      emtBuildingSetDirectionU ->SetFrameY(emtBuildingSetDirection_FRAME_Y) ;
      emtBuildingSetDirectionUL->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionL ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionDL->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionD ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionDR->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionR ->SetFrameY(emtBuildingSetDirection_FRAME_Y+1);
      emtBuildingSetDirectionUR->SetFrameY(emtBuildingSetDirection_FRAME_Y);
    }
  }
  else
  if(particicle_dx==-1)
  {
    if(particicle_dy==-1) // directon UL
    {
      emtBuildingSetDirectionU ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionUL->SetFrameY(emtBuildingSetDirection_FRAME_Y+1);
      emtBuildingSetDirectionL ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionDL->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionD ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionDR->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionR ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionUR->SetFrameY(emtBuildingSetDirection_FRAME_Y);
    }
    else
    if(particicle_dy==1)  // direction DL
    {
      emtBuildingSetDirectionU ->SetFrameY(emtBuildingSetDirection_FRAME_Y) ;
      emtBuildingSetDirectionUL->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionL ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionDL->SetFrameY(emtBuildingSetDirection_FRAME_Y+1);
      emtBuildingSetDirectionD ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionDR->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionR ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionUR->SetFrameY(emtBuildingSetDirection_FRAME_Y);
    }
    else                  // direction L
    {
      emtBuildingSetDirectionU ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionUL->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionL ->SetFrameY(emtBuildingSetDirection_FRAME_Y+1);
      emtBuildingSetDirectionDL->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionD ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionDR->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionR ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionUR->SetFrameY(emtBuildingSetDirection_FRAME_Y);
    }
  }
  else
  {
    if(particicle_dy==-1) // direction U
    {
      emtBuildingSetDirectionU ->SetFrameY(emtBuildingSetDirection_FRAME_Y+1) ;
      emtBuildingSetDirectionUL->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionL ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionDL->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionD ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionDR->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionR ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionUR->SetFrameY(emtBuildingSetDirection_FRAME_Y);
    }
    else
    if(particicle_dy==1)  // direction D
    {
      emtBuildingSetDirectionU ->SetFrameY(emtBuildingSetDirection_FRAME_Y) ;
      emtBuildingSetDirectionUL->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionL ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionDL->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionD ->SetFrameY(emtBuildingSetDirection_FRAME_Y+1);
      emtBuildingSetDirectionDR->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionR ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionUR->SetFrameY(emtBuildingSetDirection_FRAME_Y);
    }
    else                  // no direction
    {
      emtBuildingSetDirectionU ->SetFrameY(emtBuildingSetDirection_FRAME_Y) ;
      emtBuildingSetDirectionUL->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionL ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionDL->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionD ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionDR->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionR ->SetFrameY(emtBuildingSetDirection_FRAME_Y);
      emtBuildingSetDirectionUR->SetFrameY(emtBuildingSetDirection_FRAME_Y);
    }
  }
} ;
//---------------------------------------------------------------------------
c_HiveElements::c_HiveElements(c_World *w,s_mouse *m,c_Sprite *s,int bpx,int bpy,int cpx,int cpy,
                               c_Sprite *font_sprite,int pID,FILE *log_file)
{
  player_ID = pID ;
  font = new c_Font(font_sprite,3);
  for(int p=0;p<hiveelements_param_COUNT;p++)
    param[p]=0;
  build_panel_x=bpx;
  build_panel_y=bpy;
  common_panel_x=cpx;
  common_panel_y=cpy;
  world=w;mouse=m;
  action=action_NO;
  build_screen_panel=screen_panel_BUILD_MINE;
  common_screen_panel=screen_panel_COMMON_NO;
  sprite=s ;
// NodeSetDirection INIT///////////////
  emtBuildingSetDirectionU  =new c_Element(sprite,emtBuildingSetDirectionU_X+common_panel_x,emtBuildingSetDirectionU_Y+common_panel_y,
                                           0,0,emtBuildingSetDirection_FRAME_X,emtBuildingSetDirection_FRAME_Y,
                                           &OnBuildingSetDirectionU_click,&DummyFunction,log_file) ;
  emtBuildingSetDirectionUR =new c_Element(sprite,emtBuildingSetDirectionUR_X+common_panel_x,emtBuildingSetDirectionUR_Y+common_panel_y,
                                           0,0,emtBuildingSetDirection_FRAME_X,emtBuildingSetDirection_FRAME_Y,
                                           &OnBuildingSetDirectionUR_click,&DummyFunction,log_file) ;
  emtBuildingSetDirectionR  =new c_Element(sprite,emtBuildingSetDirectionR_X+common_panel_x,emtBuildingSetDirectionR_Y+common_panel_y,
                                           0,0,emtBuildingSetDirection_FRAME_X,emtBuildingSetDirection_FRAME_Y,
                                           &OnBuildingSetDirectionR_click,&DummyFunction,log_file) ;
  emtBuildingSetDirectionDR =new c_Element(sprite,emtBuildingSetDirectionDR_X+common_panel_x,emtBuildingSetDirectionDR_Y+common_panel_y,
                                           0,0,emtBuildingSetDirection_FRAME_X,emtBuildingSetDirection_FRAME_Y,
                                           &OnBuildingSetDirectionDR_click,&DummyFunction,log_file) ;
  emtBuildingSetDirectionD  =new c_Element(sprite,emtBuildingSetDirectionD_X+common_panel_x,emtBuildingSetDirectionD_Y+common_panel_y,
                                           0,0,emtBuildingSetDirection_FRAME_X,emtBuildingSetDirection_FRAME_Y,
                                           &OnBuildingSetDirectionD_click,&DummyFunction,log_file) ;
  emtBuildingSetDirectionDL =new c_Element(sprite,emtBuildingSetDirectionDL_X+common_panel_x,emtBuildingSetDirectionDL_Y+common_panel_y,
                                           0,0,emtBuildingSetDirection_FRAME_X,emtBuildingSetDirection_FRAME_Y,
                                           &OnBuildingSetDirectionDL_click,&DummyFunction,log_file) ;
  emtBuildingSetDirectionL  =new c_Element(sprite,emtBuildingSetDirectionL_X+common_panel_x,emtBuildingSetDirectionL_Y+common_panel_y,
                                           0,0,emtBuildingSetDirection_FRAME_X,emtBuildingSetDirection_FRAME_Y,
                                           &OnBuildingSetDirectionL_click,&DummyFunction,log_file) ;
  emtBuildingSetDirectionUL =new c_Element(sprite,emtBuildingSetDirectionUL_X+common_panel_x,emtBuildingSetDirectionUL_Y+common_panel_y,
                                           0,0,emtBuildingSetDirection_FRAME_X,emtBuildingSetDirection_FRAME_Y,
                                           &OnBuildingSetDirectionUL_click,&DummyFunction,log_file) ;
  emtBuildingSetDirectionU->SetElementSize  (12,12);
  emtBuildingSetDirectionUR->SetElementSize (12,12);
  emtBuildingSetDirectionR->SetElementSize  (12,12);
  emtBuildingSetDirectionDR->SetElementSize (12,12);
  emtBuildingSetDirectionD->SetElementSize  (12,12);
  emtBuildingSetDirectionDL->SetElementSize (12,12);
  emtBuildingSetDirectionL->SetElementSize  (12,12);
  emtBuildingSetDirectionUL->SetElementSize (12,12);
///////////////////////////////////////
  emtDirectionForEmpty = new c_Element  (sprite,emtDirectionForEmpty_X+common_panel_x,emtDirectionForEmpty_Y+common_panel_y,
                                         0,0,emtDirectionForEmpty_FRAME_X,emtDirectionForEmpty_FRAME_Y,
                                         &OnDirectionForEmpty_click,&DummyFunction,log_file);
  emtDirectionForMineral = new c_Element(sprite,emtDirectionForMineral_X+common_panel_x,emtDirectionForMineral_Y+common_panel_y,
                                         0,0,emtDirectionForMineral_FRAME_X,emtDirectionForMineral_FRAME_Y,
                                         &OnDirectionForMineral_click,&DummyFunction,log_file);
  emtDirectionForEnergy = new c_Element (sprite,emtDirectionForEnergy_X+common_panel_x,emtDirectionForEnergy_Y+common_panel_y,
                                         0,0,emtDirectionForEnergy_FRAME_X,emtDirectionForEnergy_FRAME_Y,
                                         &OnDirectionForEnergy_click,&DummyFunction,log_file);
  emtDirectionForEmpty->SetElementSize(12,12) ;
  emtDirectionForMineral->SetElementSize(12,12) ;
  emtDirectionForEnergy->SetElementSize(12,12) ;
///////////////////////////////////////
  emtBuildNext = new c_Element(sprite,emtBuildNext_X+build_panel_x,emtBuildNext_Y+build_panel_y,0,0,
                               emtBuildNext_FRAME_X,emtBuildNext_FRAME_Y,
                               &OnBuildNext_click,&DummyFunction,log_file) ;
  emtBuildPrev = new c_Element(sprite,emtBuildPrev_X+build_panel_x,emtBuildPrev_Y+build_panel_y,0,0,
                               emtBuildPrev_FRAME_X,emtBuildPrev_FRAME_Y,
                               &OnBuildPrev_click,&DummyFunction,log_file) ;
  emtBuildNext->SetElementSize(18,14) ;
  emtBuildPrev->SetElementSize(18,14) ;
///////////////////////////////////////
  emtBuildNode    = new c_Element(sprite,emtBuild_X+build_panel_x,emtBuild_Y+build_panel_y,0,0,
                                  emtBuildNode_FRAME_X,emtBuildNode_FRAME_Y,
                                  &OnBuildNode_click,&DummyFunction,log_file);
  emtBuildFactory = new c_Element(sprite,emtBuild_X+build_panel_x,emtBuild_Y+build_panel_y,0,0,
                                  emtBuildFactory_FRAME_X,emtBuildFactory_FRAME_Y,
                                  &OnBuildFactory_click,&DummyFunction,log_file);
  emtBuildMine    = new c_Element(sprite,emtBuild_X+build_panel_x,emtBuild_Y+build_panel_y,0,0,
                                  emtBuildMine_FRAME_X,emtBuildMine_FRAME_Y,
                                  &OnBuildMine_click,&DummyFunction,log_file);
  emtBuildCharge  = new c_Element(sprite,emtBuild_X+build_panel_x,emtBuild_Y+build_panel_y,0,0,
                                  emtBuildCharge_FRAME_X,emtBuildCharge_FRAME_Y,
                                  &OnBuildCharge_click,&DummyFunction,log_file);
  emtBuildSpeed   = new c_Element(sprite,emtBuild_X+build_panel_x,emtBuild_Y+build_panel_y,0,0,
                                  emtBuildSpeed_FRAME_X,emtBuildSpeed_FRAME_Y,
                                  &OnBuildSpeed_click,&DummyFunction,log_file);
  emtBuildPower   = new c_Element(sprite,emtBuild_X+build_panel_x,emtBuild_Y+build_panel_y,0,0,
                                  emtBuildPower_FRAME_X,emtBuildPower_FRAME_Y,
                                  &OnBuildPower_click,&DummyFunction,log_file);
///////////////////////////////////////
  emtDestroyBuilding = new c_Element(sprite,emtDestroyBuilding_X+common_panel_x,emtDestroyBuilding_Y+common_panel_y,
                                     0,0,emtDestroyBuilding_FRAME_X,emtDestroyBuilding_FRAME_Y,
                                     &OnDestroyBuilding_click,&DummyFunction,log_file) ;
  emtDestroyBuilding->SetElementSize(12,12) ;
///////////////////////////////////////
  emtShowTerritory = new c_Element(sprite,emtShowTerritory_X+common_panel_x,emtShowTerritory_Y+common_panel_Y,
                                   0,0,emtShowTerritory_FRAME_X,emtShowTerritory_FRAME_Y,
                                   &OnShowTerritory_click,&DummyFunction,log_file) ;
  emtShowTerritory->SetElementSize(12,12) ;
///////////////////////////////////////
  emtBuildingEnable = new c_Element(sprite,emtBuildingEnable_X+common_panel_x,emtBuildingEnable_Y+common_panel_Y,
                                    0,0,emtBuildingEnable_FRAME_X,emtBuildingEnable_FRAME_Y,
                                    &OnBuildingEnable_click,&DummyFunction,log_file) ;
  emtBuildingEnable->SetElementSize(12,12) ;
} ;
//---------------------------------------------------------------------------
void c_HiveElements::Release(FILE *log_file)
{
  if(log_file)fprintf(log_file,"START c_HiveElements::Release\n") ;
  if(log_file)fprintf(log_file,"   releasing...\n") ;

  delete emtBuildingSetDirectionU;
  delete emtBuildingSetDirectionUL;
  delete emtBuildingSetDirectionL;
  delete emtBuildingSetDirectionDL;
  delete emtBuildingSetDirectionD;
  delete emtBuildingSetDirectionDR;
  delete emtBuildingSetDirectionR;
  delete emtBuildingSetDirectionUR;

  delete emtDirectionForEmpty;
  delete emtDirectionForMineral;
  delete emtDirectionForEnergy;

  delete emtBuildNext ;
  delete emtBuildPrev ;

  delete emtBuildNode ;
  delete emtBuildMine ;
  delete emtBuildFactory ;
  delete emtBuildCharge ;
  delete emtBuildSpeed ;
  delete emtBuildPower ;

  delete emtDestroyBuilding ;

  delete emtShowTerritory ;

  delete emtBuildingEnable ;
  //...

  if(log_file)fprintf(log_file,"   release complete\n") ;
  if(log_file)fprintf(log_file,"END   c_HiveElements::Release\n") ;
} ;
//---------------------------------------------------------------------------
void c_HiveElements::Turn(char key,FILE *log_file)
{
  switch(build_screen_panel)
  {
    case screen_panel_BUILD_NODE :
      emtBuildNode->CheckState(mouse,world,action,player_ID) ;
    break;
    case screen_panel_BUILD_FACTORY :
      emtBuildFactory->CheckState(mouse,world,action,player_ID) ;
    break;
    case screen_panel_BUILD_MINE :
      emtBuildMine->CheckState(mouse,world,action,player_ID) ;
    break;
    case screen_panel_BUILD_CHARGE :
      emtBuildCharge->CheckState(mouse,world,action,player_ID) ;
    break ;
    case screen_panel_BUILD_SPEED :
      emtBuildSpeed->CheckState(mouse,world,action,player_ID) ;
    break ;
    case screen_panel_BUILD_POWER :
      emtBuildPower->CheckState(mouse,world,action,player_ID) ;
    break;
  } ;
  switch(common_screen_panel)
  {
    case screen_panel_COMMON_BUILDING :
      emtBuildingSetDirectionU->CheckState(mouse,world,action,player_ID) ;
      emtBuildingSetDirectionUR->CheckState(mouse,world,action,player_ID) ;
      emtBuildingSetDirectionR->CheckState(mouse,world,action,player_ID) ;
      emtBuildingSetDirectionDR->CheckState(mouse,world,action,player_ID) ;
      emtBuildingSetDirectionD->CheckState(mouse,world,action,player_ID) ;
      emtBuildingSetDirectionDL->CheckState(mouse,world,action,player_ID) ;
      emtBuildingSetDirectionL->CheckState(mouse,world,action,player_ID) ;
      emtBuildingSetDirectionUL->CheckState(mouse,world,action,player_ID) ;
      { // check special buildings buttons
        int x=param[0],y=param[1];
        switch((world->building[x][y]).type)
        {
          case building_type_FACTORY :
            emtDestroyBuilding->CheckState(mouse,world,action,player_ID) ;
            emtBuildingEnable->CheckState(mouse,world,action,player_ID) ;
          break;
          case building_type_MINE :
            emtDestroyBuilding->CheckState(mouse,world,action,player_ID) ;
            emtBuildingEnable->CheckState(mouse,world,action,player_ID) ;
          break;
          case building_type_CHARGE :
            emtDestroyBuilding->CheckState(mouse,world,action,player_ID) ;
            emtBuildingEnable->CheckState(mouse,world,action,player_ID) ;
          break;
          case building_type_SPEED :
            emtDestroyBuilding->CheckState(mouse,world,action,player_ID) ;
            emtBuildingEnable->CheckState(mouse,world,action,player_ID) ;
          break;
          case building_type_POWER :
            emtDestroyBuilding->CheckState(mouse,world,action,player_ID) ;
            emtBuildingEnable->CheckState(mouse,world,action,player_ID) ;
          break;
          case building_type_CONSTRUCTING :
            emtDestroyBuilding->CheckState(mouse,world,action,player_ID) ;
            emtBuildingEnable->CheckState(mouse,world,action,player_ID) ;
          break;
          case building_type_NODE :
            emtDestroyBuilding->CheckState(mouse,world,action,player_ID) ;
            emtBuildingEnable->CheckState(mouse,world,action,player_ID) ;
            emtDirectionForEmpty->CheckState(mouse,world,action,player_ID) ;
            emtDirectionForMineral->CheckState(mouse,world,action,player_ID) ;
            emtDirectionForEnergy->CheckState(mouse,world,action,player_ID) ;
          break;
        } ;
      };
      //...
    break;
    case screen_panel_COMMON_NO :
      emtShowTerritory->CheckState(mouse,world,action,player_ID) ;
      //...
    break;
  } ;
  emtBuildNext->CheckState(mouse,world,action,player_ID) ;
  emtBuildPrev->CheckState(mouse,world,action,player_ID) ;
  //...
} ;
//---------------------------------------------------------------------------
HRESULT c_HiveElements::Draw(RECT screen,IDirectDrawSurface *DDSSurface,FILE *log_file)
{
  HRESULT res;
  if(res!=DD_OK)return res;
  switch(build_screen_panel)
  {
    case screen_panel_BUILD_NODE :
      res = emtBuildNode->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res=font->Draw(DDSSurface,(world->player[player_ID]).buildings_count[player_buildings_NODE],
                     font_build_X+build_panel_x,font_build_Y+build_panel_y,2) ;
      if(res!=DD_OK)return res;
    break ;
    case screen_panel_BUILD_FACTORY :
      res=emtBuildFactory->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res=font->Draw(DDSSurface,(world->player[player_ID]).buildings_count[player_buildings_FACTORY],
                     font_build_X+build_panel_x,font_build_Y+build_panel_y,2) ;
      if(res!=DD_OK)return res;
    break;
    case screen_panel_BUILD_MINE :
      res=emtBuildMine->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res=font->Draw(DDSSurface,(world->player[player_ID]).buildings_count[player_buildings_MINE],
                     font_build_X+build_panel_x,font_build_Y+build_panel_y,2) ;
      if(res!=DD_OK)return res;
    break ;
    case screen_panel_BUILD_CHARGE :
      res=emtBuildCharge->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res=font->Draw(DDSSurface,(world->player[player_ID]).buildings_count[player_buildings_CHARGE],
                     font_build_X+build_panel_x,font_build_Y+build_panel_y,2) ;
      if(res!=DD_OK)return res;
    break ;
    case screen_panel_BUILD_SPEED :
      res=emtBuildSpeed->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res=font->Draw(DDSSurface,(world->player[player_ID]).buildings_count[player_buildings_SPEED],
                     font_build_X+build_panel_x,font_build_Y+build_panel_y,2) ;
      if(res!=DD_OK)return res;
    break ;
    case screen_panel_BUILD_POWER :
      res=emtBuildPower->Draw(DDSSurface,log_file);
      if(res!=DD_OK)return res;
      res=font->Draw(DDSSurface,(world->player[player_ID]).buildings_count[player_buildings_POWER],
                     font_build_X+build_panel_x,font_build_Y+build_panel_y,2) ;
    //...
  } ;
  switch(common_screen_panel)
  {
    case screen_panel_COMMON_NO :
      res=emtShowTerritory->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res=font->Draw(DDSSurface,"The Hive",8,font_common_title_X+common_panel_x,font_common_title_Y+common_panel_y,2) ;
      if(res!=DD_OK)return res;
      //...
    break;
    case screen_panel_COMMON_BUILDING :
    {
      int x=param[0],y=param[1];
      //draw HP %
      int HP=(world->building[x][y]).HP,maxHP=(world->building[x][y]).maxHP;
      int HP_percent= (HP*100)/maxHP ;
      res=font->Draw(DDSSurface,HP_percent,font_common_HP_X+common_panel_x,font_common_HP_Y+common_panel_y,2);
      if(res!=DD_OK)return res;
      //other
      switch((world->building[x][y]).type)
      {
        case building_type_MAIN :
          res=font->Draw(DDSSurface,"MAIN core",9,font_common_title_X+common_panel_x,font_common_title_Y+common_panel_y,2) ;
          if(res!=DD_OK)return res;
        break;
        case building_type_BASE :
          //draw title
          res=font->Draw(DDSSurface,"Base",4,font_common_title_X+common_panel_x,font_common_title_Y+common_panel_y,2) ;
          if(res!=DD_OK)return res;
          //draw direction set buttons
          {
            int dx=(world->building[x][y]).param[2],dy=(world->building[x][y]).param[3];
            DirectionButtonFrameCheck(dx,dy) ;
          }
          res=emtBuildingSetDirectionU->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionUR->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionR->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionDR->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionD->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionDL->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionL->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionUL->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          //draw resurce count
          res=font->Draw(DDSSurface,"MRL",3,font_common_MRL_X+common_panel_x,font_common_MRL_Y+common_panel_y,2);
          if(res!=DD_OK)return res;
          res=font->Draw(DDSSurface,"ENY",3,font_common_ENY_X+common_panel_x,font_common_ENY_Y+common_panel_y,2);
          if(res!=DD_OK)return res;
          res=font->Draw(DDSSurface,(int)(world->building[x][y]).param[4],font_common_MINERAL_X+common_panel_x,font_common_MINERAL_Y+common_panel_y,2);
          if(res!=DD_OK)return res;
          res=font->Draw(DDSSurface,(int)(world->building[x][y]).param[5],font_common_ENERGY_X+common_panel_x,font_common_ENERGY_Y+common_panel_y,2);
          if(res!=DD_OK)return res;
          //other
          if((world->building[x][y]).enable==0) emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y+1);
          else                                  emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y);
          res=emtBuildingEnable->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
          //...draw special
        break;
        case building_type_NODE :
          //draw title
          res=font->Draw(DDSSurface,"Node",4,font_common_title_X+common_panel_x,font_common_title_Y+common_panel_y,2) ;
          if(res!=DD_OK)return res;
          //draw direction set buttons
          {
            int dx=((world->building[x][y]).param[0])/2,dy=((world->building[x][y]).param[1])/2;
            DirectionButtonFrameCheck(dx,dy) ;
          }
          res=emtBuildingSetDirectionU->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionUR->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionR->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionDR->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionD->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionDL->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionL->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionUL->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          //draw special
          if((world->building[x][y]).param[3]==0) emtDirectionForEmpty->SetFrameY(emtDirectionForEmpty_FRAME_Y+1) ;
          else                                    emtDirectionForEmpty->SetFrameY(emtDirectionForEmpty_FRAME_Y) ;
          if((world->building[x][y]).param[4]==0) emtDirectionForMineral->SetFrameY(emtDirectionForMineral_FRAME_Y+1) ;
          else                                    emtDirectionForMineral->SetFrameY(emtDirectionForMineral_FRAME_Y) ;
          if((world->building[x][y]).param[5]==0) emtDirectionForEnergy->SetFrameY(emtDirectionForEnergy_FRAME_Y+1);
          else                                    emtDirectionForEnergy->SetFrameY(emtDirectionForEnergy_FRAME_Y) ;
          res=emtDirectionForEmpty->DrawClip(screen,DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
          res=emtDirectionForMineral->DrawClip(screen,DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
          res=emtDirectionForEnergy->DrawClip(screen,DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
          //other
          res=emtDestroyBuilding->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
          if((world->building[x][y]).enable==0) emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y+1);
          else                                  emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y);
          res=emtBuildingEnable->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
        break;
        case building_type_FACTORY :
          //draw title
          res=font->Draw(DDSSurface,"Factory",7,font_common_title_X+common_panel_x,font_common_title_Y+common_panel_y,2) ;
          if(res!=DD_OK)return res;
          //draw direction set buttons
          {
            int dx=((world->building[x][y]).param[2]),dy=((world->building[x][y]).param[3]);
            DirectionButtonFrameCheck(dx,dy) ;
          }
          res=emtBuildingSetDirectionU->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionUR->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionR->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionDR->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionD->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionDL->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionL->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionUL->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          //draw resurce count
          res=font->Draw(DDSSurface,"MRL",3,font_common_MRL_X+common_panel_x,font_common_MRL_Y+common_panel_y,2);
          if(res!=DD_OK)return res;
          res=font->Draw(DDSSurface,"ENY",3,font_common_ENY_X+common_panel_x,font_common_ENY_Y+common_panel_y,2);
          if(res!=DD_OK)return res;
          res=font->Draw(DDSSurface,(int)(world->building[x][y]).param[4],font_common_MINERAL_X+common_panel_x,font_common_MINERAL_Y+common_panel_y,2);
          if(res!=DD_OK)return res;
          res=font->Draw(DDSSurface,(int)(world->building[x][y]).param[5],font_common_ENERGY_X+common_panel_x,font_common_ENERGY_Y+common_panel_y,2);
          if(res!=DD_OK)return res;
          //other
          res=emtDestroyBuilding->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
          if((world->building[x][y]).enable==0) emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y+1);
          else                                  emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y);
          res=emtBuildingEnable->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
          //...draw special
        break;
        case building_type_SPEED :
          res=font->Draw(DDSSurface,"Speed",5,font_common_title_X+common_panel_x,font_common_title_Y+common_panel_y,2) ;
          if(res!=DD_OK)return res;
          res=emtDestroyBuilding->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
          if((world->building[x][y]).enable==0) emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y+1);
          else                                  emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y);
          res=emtBuildingEnable->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
        break;
        case building_type_MINE :
          //draw title
          res=font->Draw(DDSSurface,"Mine",4,font_common_title_X+common_panel_x,font_common_title_Y+common_panel_y,2) ;
          if(res!=DD_OK)return res;
          //draw direction set buttons
          {
            int dx=((world->building[x][y]).param[2]),dy=((world->building[x][y]).param[3]);
            DirectionButtonFrameCheck(dx,dy) ;
          }
          res=emtBuildingSetDirectionU->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionUR->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionR->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionDR->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionD->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionDL->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionL->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionUL->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          //other
          res=emtDestroyBuilding->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
          if((world->building[x][y]).enable==0) emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y+1);
          else                                  emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y);
          res=emtBuildingEnable->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
        break;
        case building_type_CHARGE :
          res=font->Draw(DDSSurface,"Charge",6,font_common_title_X+common_panel_x,font_common_title_Y+common_panel_y,2) ;
          if(res!=DD_OK)return res;
          res=emtDestroyBuilding->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
          if((world->building[x][y]).enable==0) emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y+1);
          else                                  emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y);
          res=emtBuildingEnable->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
        break;
        case building_type_POWER :
          //draw title
          res=font->Draw(DDSSurface,"Power",5,font_common_title_X+common_panel_x,font_common_title_Y+common_panel_y,2) ;
          if(res!=DD_OK)return res;
          //draw direction set buttons
          {
            int dx=((world->building[x][y]).param[2]),dy=((world->building[x][y]).param[3]);
            DirectionButtonFrameCheck(dx,dy) ;
          }
          res=emtBuildingSetDirectionU->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionUR->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionR->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionDR->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionD->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionDL->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionL->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionUL->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          //other
          res=emtDestroyBuilding->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
          if((world->building[x][y]).enable==0) emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y+1);
          else                                  emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y);
          res=emtBuildingEnable->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
        break;
        case building_type_CONSTRUCTING :
          //draw process
          res=font->Draw(DDSSurface,(int)(world->building[x][y]).param[1],font_common_process_X+common_panel_x,font_common_process_Y+common_panel_y,2) ;
          if(res!=DD_OK)return res;
          //draw direction set buttons
          {
            int dx=((world->building[x][y]).param[2]),dy=((world->building[x][y]).param[3]);
            DirectionButtonFrameCheck(dx,dy) ;
          }
          res=emtBuildingSetDirectionU->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionUR->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionR->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionDR->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionD->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionDL->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionL->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          res=emtBuildingSetDirectionUL->DrawClip(screen,DDSSurface,log_file);
          if(res!=DD_OK)return res;
          //other
          res=emtDestroyBuilding->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
          if((world->building[x][y]).enable==0) emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y+1);
          else                                  emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y);
          res=emtBuildingEnable->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
          //other
          switch((int)((world->building[x][y]).param[0]))
          {
            case building_type_FACTORY :
              res=font->Draw(DDSSurface,"Factory",7,font_common_title_X+common_panel_x,font_common_title_Y+common_panel_y,2) ;
              if(res!=DD_OK)return res;
            break;
            case building_type_MINE :
              res=font->Draw(DDSSurface,"Mine",4,font_common_title_X+common_panel_x,font_common_title_Y+common_panel_y,2) ;
              if(res!=DD_OK)return res;
            break;
            case building_type_CHARGE :
              res=font->Draw(DDSSurface,"Charge",6,font_common_title_X+common_panel_x,font_common_title_Y+common_panel_y,2) ;
              if(res!=DD_OK)return res;
            break;
            case building_type_SPEED :
              res=font->Draw(DDSSurface,"Speed",5,font_common_title_X+common_panel_x,font_common_title_Y+common_panel_y,2) ;
              if(res!=DD_OK)return res;
            break ;
            case building_type_POWER :
              res=font->Draw(DDSSurface,"Power",5,font_common_title_X+common_panel_x,font_common_title_Y+common_panel_y,2);
              if(res!=DD_OK)return res;
          } ;
        break;
        case building_type_MINERAL :
          //draw mineral count
          res=font->Draw(DDSSurface,(int)(world->building[x][y]).param[0],font_common_process_X+common_panel_x,font_common_process_Y+common_panel_y,2) ;
          if(res!=DD_OK)return res;
          //draw title
          res=font->Draw(DDSSurface,"Mineral",7,font_common_title_X+common_panel_x,font_common_title_Y+common_panel_y,2);
          if(res!=DD_OK)return res;
      } ;
    };
    break;
    //...
  } ;
  res=emtBuildNext->DrawClip(screen,DDSSurface,log_file) ;
  if(res!=DD_OK)return res;
  res=emtBuildPrev->DrawClip(screen,DDSSurface,log_file) ;
  if(res!=DD_OK)return res;
  //...

  return DD_OK ;
} ;
//---------------------------------------------------------------------------
void c_HiveElements::CheckAction(FILE *log_file)
{
  if(mouse->button==mouse_button_RIGHT)
  {
    action=action_NO ;
    mouse->x_frame = building_type_SELECT ;
    common_screen_panel=screen_panel_COMMON_NO;
    switch(build_screen_panel)
    {
      case screen_panel_BUILD_NODE :
        emtBuildNode->SetFrameY(emtBuildNode_FRAME_Y) ;
      break;
      case screen_panel_BUILD_MINE :
        emtBuildMine->SetFrameY(emtBuildMine_FRAME_Y);
      break;
      case screen_panel_BUILD_FACTORY :
        emtBuildFactory->SetFrameY(emtBuildFactory_FRAME_Y);
      break;
      case screen_panel_BUILD_SPEED :
        emtBuildSpeed->SetFrameY(emtBuildSpeed_FRAME_Y);
      break;
      case screen_panel_BUILD_CHARGE :
        emtBuildCharge->SetFrameY(emtBuildCharge_FRAME_Y);
      break;
      case screen_panel_BUILD_POWER :
        emtBuildPower->SetFrameY(emtBuildPower_FRAME_Y) ;
      break;
    } ;
    return ;
  } ;
  switch(action)
  {
    case action_BUILD_NEXT :
      emtBuildNext->SetFrameY(emtBuildNext_FRAME_Y) ;
      if(build_screen_panel<player_buildings_COUNT-1)build_screen_panel++;
      action=action_NO ;
    break;
    case action_BUILD_PREV :
      emtBuildPrev->SetFrameY(emtBuildPrev_FRAME_Y) ;
      if(build_screen_panel>0)build_screen_panel--;
      action=action_NO ;
    break;
    case action_BUILDING_CLICK : // нажатие на здание
      action=action_NO ;
      common_screen_panel=screen_panel_COMMON_BUILDING;
    break ;
    case action_DESTROY_BUILDING : // уничтожить здание
      action=action_NO ;
      emtDestroyBuilding->SetFrameY(emtDestroyBuilding_FRAME_Y) ;
      common_screen_panel = screen_panel_COMMON_NO ;
      {
        //убрать здание
        int x=param[0],y=param[1];
        (world->building[x][y]).type = building_type_NO ;
        //убрать территорию вокруг здания
        int owner=(world->building[x][y]).owner;
        int t_sx=x-building_territory_ADD_COUNT,t_ex=x+building_territory_ADD_COUNT,
            t_sy=y-building_territory_ADD_COUNT,t_ey=y+building_territory_ADD_COUNT;
        if(t_sx<0)             t_sx=0;
        if(t_ex>=world_X_COUNT)t_ex=world_X_COUNT-1;
        if(t_sy<0)             t_sy=0;
        if(t_ey>=world_Y_COUNT)t_ey=world_Y_COUNT-1;
        for(int t_x=t_sx;t_x<=t_ex;t_x++)
          for(int t_y=t_sy;t_y<=t_ey;t_y++)
            (world->building[t_x][t_y]).territory[player_ID]=0;
      } ;
    break;
    case action_SHOW_TERRITORY :     // показать территорию
      action=action_NO ;
      if((world->player[player_ID]).show_territory==0) (world->player[player_ID]).show_territory=1;
      else                                             (world->player[player_ID]).show_territory=0;
    //...
    break;
    case action_BUILDING_ENABLE :   // вкл/выкл здание
      action=action_NO ;
      {
        int x=param[0],y=param[1];
        if((world->building[x][y]).enable == 0)(world->building[x][y]).enable=1;
        else                                   (world->building[x][y]).enable=0;
      } ;
    break;
    case action_SET_DIRECTION_U :
    {
      action=action_NO;
      int x=param[0],y=param[1];
      if((world->building[x][y]).type==building_type_NODE)
      {
        (world->building[x][y]).param[0] = 0 ;
        (world->building[x][y]).param[1] = -2 ;
      }
      else
      {
        (world->building[x][y]).param[2] = 0 ;
        (world->building[x][y]).param[3] = -1 ;
      } ;
    };
    break;
    case action_SET_DIRECTION_UR :
    {
      action=action_NO;
      int x=param[0],y=param[1];
      if((world->building[x][y]).type==building_type_NODE)
      {
        (world->building[x][y]).param[0] = 2 ;
        (world->building[x][y]).param[1] = -2 ;
      }
      else
      {
        (world->building[x][y]).param[2] = 1 ;
        (world->building[x][y]).param[3] = -1 ;
      } ;
    };
    break;
    case action_SET_DIRECTION_R :
    {
      action=action_NO;
      int x=param[0],y=param[1];
      if((world->building[x][y]).type==building_type_NODE)
      {
        (world->building[x][y]).param[0] = 2 ;
        (world->building[x][y]).param[1] = 0 ;
      }
      else
      {
        (world->building[x][y]).param[2] = 1 ;
        (world->building[x][y]).param[3] = 0 ;
      } ;
    };
    break;
    case action_SET_DIRECTION_DR :
    {
      action=action_NO;
      int x=param[0],y=param[1];
      if((world->building[x][y]).type==building_type_NODE)
      {
        (world->building[x][y]).param[0] = 2 ;
        (world->building[x][y]).param[1] = 2 ;
      }
      else
      {
        (world->building[x][y]).param[2] = 1 ;
        (world->building[x][y]).param[3] = 1 ;
      } ;
    };
    break;
    case action_SET_DIRECTION_D :
    {
      action=action_NO;
      int x=param[0],y=param[1];
      if((world->building[x][y]).type==building_type_NODE)
      {
        (world->building[x][y]).param[0] = 0 ;
        (world->building[x][y]).param[1] = 2 ;
      }
      else
      {
        (world->building[x][y]).param[2] = 0 ;
        (world->building[x][y]).param[3] = 1 ;
      } ;
    };
    break;
    case action_SET_DIRECTION_DL :
    {
      action=action_NO;
      int x=param[0],y=param[1];
      if((world->building[x][y]).type==building_type_NODE)
      {
        (world->building[x][y]).param[0] = -2 ;
        (world->building[x][y]).param[1] = 2 ;
      }
      else
      {
        (world->building[x][y]).param[2] = -1 ;
        (world->building[x][y]).param[3] = 1 ;
      } ;
    };
    break;
    case action_SET_DIRECTION_L :
    {
      action=action_NO;
      int x=param[0],y=param[1];
      if((world->building[x][y]).type==building_type_NODE)
      {
        (world->building[x][y]).param[0] = -2 ;
        (world->building[x][y]).param[1] = 0 ;
      }
      else
      {
        (world->building[x][y]).param[2] = -1 ;
        (world->building[x][y]).param[3] = 0 ;
      } ;
    };
    break;
    case action_SET_DIRECTION_UL :
    {
      action=action_NO;
      int x=param[0],y=param[1];
      if((world->building[x][y]).type==building_type_NODE)
      {
        (world->building[x][y]).param[0] = -2 ;
        (world->building[x][y]).param[1] = -2 ;
      }
      else
      {
        (world->building[x][y]).param[2] = -1 ;
        (world->building[x][y]).param[3] = -1 ;
      } ;
    };
    break;
    case action_DIRECTION_FOR_EMPTY :
    {
      action=action_NO;
      int x=param[0],y=param[1];
      if((world->building[x][y]).param[3]==1)(world->building[x][y]).param[3]=0;
      else                                   (world->building[x][y]).param[3]=1;
    } ;
    break;
    case action_DIRECTION_FOR_MINERAL :
    {
      action=action_NO;
      int x=param[0],y=param[1];
      if((world->building[x][y]).param[4]==1)(world->building[x][y]).param[4]=0;
      else                                   (world->building[x][y]).param[4]=1;

    } ;
    break;
    case action_DIRECTION_FOR_ENERGY :
    {
      action=action_NO;
      int x=param[0],y=param[1];
      if((world->building[x][y]).param[5]==1)(world->building[x][y]).param[5]=0;
      else                                   (world->building[x][y]).param[5]=1;
    } ;
    break;
  } ;
  if(mouse->button==mouse_button_LEFT&&mouse->y_frame==building_y_frame_GOODPLACE)
  {
    switch(action)
    {
      case action_BUILD_NODE :          // поставить маяк
        action=action_NO ;
        emtBuildNode->SetFrameY(emtBuildNode_FRAME_Y) ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type = building_type_NODE ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame=0;
        (world->building[mouse->cell_x][mouse->cell_y]).r = building_NODE_RANGE ;
        (world->building[mouse->cell_x][mouse->cell_y]).HP = building_NODE_HP ;
        (world->building[mouse->cell_x][mouse->cell_y]).maxHP = building_NODE_HP ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=building_NODE_SKIPENABLE_COUNT;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=0; // не действует на particicle_type_EMPTY
        (world->building[mouse->cell_x][mouse->cell_y]).param[4]=0; // не действует на particicle_type_MINERAL
        (world->building[mouse->cell_x][mouse->cell_y]).param[5]=0; // не действует на particicle_type_ENERGY
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID ;
        (world->building[mouse->cell_x][mouse->cell_y]).enable=0;
      break;
      case action_BUILD_FACTORY :     // начать строительство завода
        action=action_NO ;
        emtBuildFactory->SetFrameY(emtBuildFactory_FRAME_Y) ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_CONSTRUCTING ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame=0 ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=0;
        (world->building[mouse->cell_x][mouse->cell_y]).HP = building_CONSTRUCTING_HP ;
        (world->building[mouse->cell_x][mouse->cell_y]).maxHP = building_CONSTRUCTING_HP ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=building_type_FACTORY ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=building_FACTORY_BUILD_TIME ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=building_exit_coord_X ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=building_exit_coord_Y ;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        (world->building[mouse->cell_x][mouse->cell_y]).enable=1;
      break;
      case action_BUILD_MINE :        // начать строительство шахты
        action=action_NO ;
        emtBuildMine->SetFrameY(emtBuildMine_FRAME_Y) ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_CONSTRUCTING ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame=0 ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=0;
        (world->building[mouse->cell_x][mouse->cell_y]).HP = building_CONSTRUCTING_HP ;
        (world->building[mouse->cell_x][mouse->cell_y]).maxHP = building_CONSTRUCTING_HP ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=building_type_MINE ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=building_MINE_BUILD_TIME ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=building_exit_coord_X ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=building_exit_coord_Y ;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        (world->building[mouse->cell_x][mouse->cell_y]).enable=1;
      break;
      case action_BUILD_CHARGE :     // начать строительство зарядника
        action=action_NO ;
        emtBuildCharge->SetFrameY(emtBuildCharge_FRAME_Y) ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_CONSTRUCTING ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame=0 ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=0;
        (world->building[mouse->cell_x][mouse->cell_y]).HP = building_CONSTRUCTING_HP ;
        (world->building[mouse->cell_x][mouse->cell_y]).maxHP = building_CONSTRUCTING_HP ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=building_type_CHARGE ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=building_CHARGE_BUILD_TIME ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=building_exit_coord_X ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=building_exit_coord_Y ;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        (world->building[mouse->cell_x][mouse->cell_y]).enable=1;
      break;
      case action_BUILD_SPEED :      // начать строительство завода
        action=action_NO ;
        emtBuildSpeed->SetFrameY(emtBuildSpeed_FRAME_Y) ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_CONSTRUCTING ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame=0 ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=0;
        (world->building[mouse->cell_x][mouse->cell_y]).HP = building_CONSTRUCTING_HP ;
        (world->building[mouse->cell_x][mouse->cell_y]).maxHP = building_CONSTRUCTING_HP ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=building_type_SPEED ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=building_SPEED_BUILD_TIME ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=building_exit_coord_X ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=building_exit_coord_Y ;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        (world->building[mouse->cell_x][mouse->cell_y]).enable=1;
      break;
      case action_BUILD_POWER :     // начать строительство электростанции
        action=action_NO ;
        emtBuildPower->SetFrameY(emtBuildPower_FRAME_Y) ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_CONSTRUCTING ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame=0 ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=0;
        (world->building[mouse->cell_x][mouse->cell_y]).HP = building_CONSTRUCTING_HP ;
        (world->building[mouse->cell_x][mouse->cell_y]).maxHP = building_CONSTRUCTING_HP ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=building_type_POWER ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=building_POWER_BUILD_TIME ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=building_exit_coord_X ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=building_exit_coord_Y ;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        (world->building[mouse->cell_x][mouse->cell_y]).enable=1;
      //...
    } ;
  } ;
} ;
//---------------------------------------------------------------------------
void DummyFunction(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element){} ;
//---------------------------------------------------------------------------
void OnBuildingSetDirectionU_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  action = action_SET_DIRECTION_U ;
} ;
void OnBuildingSetDirectionUR_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  action = action_SET_DIRECTION_UR ;
} ;
void OnBuildingSetDirectionR_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  action = action_SET_DIRECTION_R ;
} ;
void OnBuildingSetDirectionDR_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  action = action_SET_DIRECTION_DR ;
} ;
void OnBuildingSetDirectionD_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  action = action_SET_DIRECTION_D ;
} ;
void OnBuildingSetDirectionDL_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  action = action_SET_DIRECTION_DL ;
} ;
void OnBuildingSetDirectionL_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  action = action_SET_DIRECTION_L ;
} ;
void OnBuildingSetDirectionUL_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  action = action_SET_DIRECTION_UL ;
} ;
//---------------------------------------------------------------------------
void OnDirectionForEmpty_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *elemnt)
{
  action=action_DIRECTION_FOR_EMPTY ;
} ;
void OnDirectionForMineral_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *elemnt)
{
  action=action_DIRECTION_FOR_MINERAL ;
} ;
void OnDirectionForEnergy_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *elemnt)
{
  action=action_DIRECTION_FOR_ENERGY ;
} ;
//---------------------------------------------------------------------------
void OnBuildNext_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  action = action_BUILD_NEXT ;
  element->SetFrameY(emtBuildNext_FRAME_Y+1) ;
} ;
void OnBuildPrev_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  action = action_BUILD_PREV ;
  element->SetFrameY(emtBuildPrev_FRAME_Y+1) ;
} ;
//---------------------------------------------------------------------------
void OnBuildNode_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_NODE]>0)//проверка на наличие прототипа здания
  {
    (world->player[player_ID]).buildings_count[player_buildings_NODE]--;
    action=action_BUILD_NODE ;
    mouse->x_frame=building_type_BUILDPLACE ;
    element->SetFrameY(emtBuildNode_FRAME_Y+1) ;
  } ;
} ;
void OnBuildFactory_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_FACTORY]>0)//проверка на наличие прототипа здания
  {
    (world->player[player_ID]).buildings_count[player_buildings_FACTORY]--;
    action=action_BUILD_FACTORY ;
    mouse->x_frame=building_type_BUILDPLACE ;
    element->SetFrameY(emtBuildFactory_FRAME_Y+1) ;
  } ;
} ;
void OnBuildMine_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_MINE]>0)//проверка на наличие прототипа здания
  {
    (world->player[player_ID]).buildings_count[player_buildings_MINE]--;
    action=action_BUILD_MINE ;
    mouse->x_frame=building_type_BUILDPLACE ;
    element->SetFrameY(emtBuildMine_FRAME_Y+1) ;
  } ;
} ;
void OnBuildCharge_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_CHARGE]>0)//проверка на наличие прототипа здания
  {
    (world->player[player_ID]).buildings_count[player_buildings_CHARGE]--;
    action=action_BUILD_CHARGE ;
    mouse->x_frame=building_type_BUILDPLACE ;
    element->SetFrameY(emtBuildCharge_FRAME_Y+1) ;
  } ;
} ;
void OnBuildSpeed_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_SPEED]>0)//проверка на наличие прототипа здания
  {
    (world->player[player_ID]).buildings_count[player_buildings_SPEED]--;
    action=action_BUILD_SPEED ;
    mouse->x_frame=building_type_BUILDPLACE ;
    element->SetFrameY(emtBuildSpeed_FRAME_Y+1) ;
  } ;
} ;
void OnBuildPower_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_POWER]>0)//проверка на наличие прототипа здания
  {
    (world->player[player_ID]).buildings_count[player_buildings_POWER]--;
    action=action_BUILD_POWER ;
    mouse->x_frame=building_type_BUILDPLACE ;
    element->SetFrameY(emtBuildPower_FRAME_Y+1) ;
  } ;
} ;
//---------------------------------------------------------------------------
void OnDestroyBuilding_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  action = action_DESTROY_BUILDING ;
  element->SetFrameY(emtDestroyBuilding_FRAME_Y+1) ;
}
//---------------------------------------------------------------------------
void OnShowTerritory_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  action = action_SHOW_TERRITORY ;
  if(element->GetFrameY()==emtShowTerritory_FRAME_Y) element->SetFrameY(emtShowTerritory_FRAME_Y+1) ;
  else                                               element->SetFrameY(emtShowTerritory_FRAME_Y) ;
} ;
//---------------------------------------------------------------------------
void OnBuildingEnable_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  action = action_BUILDING_ENABLE ;
} ;
//---------------------------------------------------------------------------
#endif
