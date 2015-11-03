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
const int font_common_X = 10 ;
const int font_common_Y = 10 ;
const int font_RESURCE_X = 620 ;
const int font_RESURCE_Y = 20 ;
const int font_build_X  = 46 ;
const int font_build_Y  = 46 ;

const int action_NO               = 0 ;
const int action_BUILDING_CLICK   = 1 ; // нажатие на здание
const int action_DESTROY_BUILDING = 2 ; // уничтожить здание
const int action_SHOW_TERRITORY   = 3 ; // показать территорию
const int action_BUILD_NEXT       = 4 ; // нажатие на кнопку след. здание
const int action_BUILD_PREV       = 5 ; // нажатие на кнопку перд. здание
const int action_BUILD_NODE_U     = 6 ; //
const int action_BUILD_NODE_UUL   = 7 ; //
const int action_BUILD_NODE_UL    = 8 ; //
const int action_BUILD_NODE_ULL   = 9 ; //
const int action_BUILD_NODE_L     =10 ; //
const int action_BUILD_NODE_DLL   =11 ; //
const int action_BUILD_NODE_DL    =12 ; //
const int action_BUILD_NODE_DDL   =13 ; //
const int action_BUILD_NODE_D     =14 ; //
const int action_BUILD_NODE_DDR   =15 ; //
const int action_BUILD_NODE_DR    =16 ; //
const int action_BUILD_NODE_DRR   =17 ; //
const int action_BUILD_NODE_R     =18 ; //
const int action_BUILD_NODE_URR   =19 ; //
const int action_BUILD_NODE_UR    =20 ; //
const int action_BUILD_NODE_UUR   =21 ; //
const int action_BUILD_FACTORY    =22 ; // строить завод
const int action_BUILD_MINE       =23 ; // строить шахту
const int action_BUILD_CHARGE     =24 ; // строить зарядку
const int action_BUILD_SPEED      =25 ; // строить ускоритель
const int action_BUILDING_ENABLE  =26 ; // вкл/выкл здание

const int screen_panel_BUILD_NODE      = 0 ;
const int screen_panel_BUILD_FACTORY   = 1 ;
const int screen_panel_BUILD_MINE      = 2 ;
const int screen_panel_BUILD_CHARGE    = 3 ;
const int screen_panel_BUILD_SPEED     = 4 ;
const int screen_panel_COMMON_NO       = 5 ;
const int screen_panel_COMMON_BUILDING = 6 ;

const int emtNodeSetDirection_FRAME_X = 0 ;
const int emtNodeSetDirection_FRAME_Y = 2 ;
const int emtNodeSetDirectionU_X   = 20 ;
const int emtNodeSetDirectionU_Y   = 1  ;
const int emtNodeSetDirectionUUR_X = 29 ;
const int emtNodeSetDirectionUUR_Y = 3  ;
const int emtNodeSetDirectionUR_X  = 35 ;
const int emtNodeSetDirectionUR_Y  = 6  ;
const int emtNodeSetDirectionURR_X = 39 ;
const int emtNodeSetDirectionURR_Y = 12 ;
const int emtNodeSetDirectionR_X   = 40 ;
const int emtNodeSetDirectionR_Y   = 20 ;
const int emtNodeSetDirectionDRR_X = 38 ;
const int emtNodeSetDirectionDRR_Y = 28 ;
const int emtNodeSetDirectionDR_X  = 35 ;
const int emtNodeSetDirectionDR_Y  = 34 ;
const int emtNodeSetDirectionDDR_X = 29 ;
const int emtNodeSetDirectionDDR_Y = 38 ;
const int emtNodeSetDirectionD_X   = 20 ;
const int emtNodeSetDirectionD_Y   = 40 ;
const int emtNodeSetDirectionDDL_X = 12 ;
const int emtNodeSetDirectionDDL_Y = 38 ;
const int emtNodeSetDirectionDL_X  = 6  ;
const int emtNodeSetDirectionDL_Y  = 35 ;
const int emtNodeSetDirectionDLL_X = 3  ;
const int emtNodeSetDirectionDLL_Y = 29 ;
const int emtNodeSetDirectionL_X   = 2  ;
const int emtNodeSetDirectionL_Y   = 21 ;
const int emtNodeSetDirectionULL_X = 3  ;
const int emtNodeSetDirectionULL_Y = 14 ;
const int emtNodeSetDirectionUL_X  = 6  ;
const int emtNodeSetDirectionUL_Y  = 6  ;
const int emtNodeSetDirectionUUL_X = 12 ;
const int emtNodeSetDirectionUUL_Y = 3  ;

const int emtBuildNext_X = 31 ;
const int emtBuildNext_Y = -20 ;
const int emtBuildNext_FRAME_X = 2 ;
const int emtBuildNext_FRAME_Y = 2 ;

const int emtBuildPrev_X = 11 ;
const int emtBuildPrev_Y = -20 ;
const int emtBuildPrev_FRAME_X = 1 ;
const int emtBuildPrev_FRAME_Y = 2 ;

const int emtBuild_X = 20 ;
const int emtBuild_Y = 20 ;

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

const int emtDestroyBuilding_X = 167 ;
const int emtDestroyBuilding_Y = 5 ;
const int emtDestroyBuilding_FRAME_X = 4 ;
const int emtDestroyBuilding_FRAME_Y = 2 ;

const int emtShowTerritory_X = 4 ;
const int emtShowTerritory_Y = 36 ;
const int emtShowTerritory_FRAME_X = 3 ;
const int emtShowTerritory_FRAME_Y = 2 ;

const int emtBuildingEnable_X = 4 ;
const int emtBuildingEnable_Y = 36 ;
const int emtBuildingEnable_FRAME_X = 5 ;
const int emtBuildingEnable_FRAME_Y = 2 ;
//...
//---------------------------------------------------------------------------
void DummyFunction(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // пустышка

void OnNodeSetDirectionU_click  (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Верх
void OnNodeSetDirectionUUL_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Верх-Верх-Лево
void OnNodeSetDirectionUL_click (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Верх-Лево
void OnNodeSetDirectionULL_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Верх-Лево-Лево
void OnNodeSetDirectionL_click  (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Лево
void OnNodeSetDirectionDLL_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Низ-Лево-Лево
void OnNodeSetDirectionDL_click (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Низ-Лево
void OnNodeSetDirectionDDL_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Низ-Низ-Лево
void OnNodeSetDirectionD_click  (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Низ
void OnNodeSetDirectionDDR_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Низ-Низ-Право
void OnNodeSetDirectionDR_click (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Низ-Право
void OnNodeSetDirectionDRR_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Низ-Право-Право
void OnNodeSetDirectionR_click  (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Право
void OnNodeSetDirectionURR_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Верх-Право-Право
void OnNodeSetDirectionUR_click (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Верх-Право
void OnNodeSetDirectionUUR_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // сменить направление на Верх-Верх-Право

void OnBuildNext_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // прокрутка зданий для постройки
void OnBuildPrev_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // прокрутка зданий для постройки

void OnBuildMine_click   (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // строить шахту
void OnBuildFactory_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // строить завод
void OnBuildNode_click   (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // строить маяк
void OnBuildSpeed_click  (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // строить ускоритель
void OnBuildCharge_click (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ; // строить перезарядку

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
    c_Element *emtNodeSetDirectionU,
              *emtNodeSetDirectionUUR,
              *emtNodeSetDirectionUR,
              *emtNodeSetDirectionURR,
              *emtNodeSetDirectionR,
              *emtNodeSetDirectionDRR,
              *emtNodeSetDirectionDR,
              *emtNodeSetDirectionDDR,
              *emtNodeSetDirectionD,
              *emtNodeSetDirectionDDL,
              *emtNodeSetDirectionDL,
              *emtNodeSetDirectionDLL,
              *emtNodeSetDirectionL,
              *emtNodeSetDirectionULL,
              *emtNodeSetDirectionUL,
              *emtNodeSetDirectionUUL,

              *emtBuildNext,  // building scroll
              *emtBuildPrev , // building scroll

              *emtBuildNode,
              *emtBuildFactory,
              *emtBuildMine,
              *emtBuildCharge,
              *emtBuildSpeed,

              *emtDestroyBuilding,

              *emtShowTerritory,

              *emtBuildingEnable;
    //... more elements
  public :
    int action,param[hiveelements_param_COUNT] ;
    c_HiveElements(c_World *w,s_mouse *m,c_Sprite *s,
                   int bpx,int bpy,int cpx,int cpy,
                   c_Sprite *font_sprite,int pID,FILE *log_file=NULL) ;
    void Turn(char key,FILE *log_file=NULL) ;
    void CheckAction(FILE *log_file=NULL) ;
    int GetBuildScreenPanel() {return build_screen_panel;};
    int GetCommonScreenPanel(){return common_screen_panel;};
    HRESULT Draw(IDirectDrawSurface *DDSSurface,FILE *log_file=NULL) ;
    void Release(FILE *log_file=NULL) ;
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
  emtNodeSetDirectionU  =new c_Element(sprite,emtNodeSetDirectionU_X+build_panel_x,emtNodeSetDirectionU_Y+build_panel_y,
                                       0,0,emtNodeSetDirection_FRAME_X,emtNodeSetDirection_FRAME_Y,
                                       &OnNodeSetDirectionU_click,&DummyFunction,log_file) ;
  emtNodeSetDirectionUUR=new c_Element(sprite,emtNodeSetDirectionUUR_X+build_panel_x,emtNodeSetDirectionUUR_Y+build_panel_y,
                                       0,0,emtNodeSetDirection_FRAME_X,emtNodeSetDirection_FRAME_Y,
                                       &OnNodeSetDirectionUUR_click,&DummyFunction,log_file) ;
  emtNodeSetDirectionUR =new c_Element(sprite,emtNodeSetDirectionUR_X+build_panel_x,emtNodeSetDirectionUR_Y+build_panel_y,
                                       0,0,emtNodeSetDirection_FRAME_X,emtNodeSetDirection_FRAME_Y,
                                       &OnNodeSetDirectionUR_click,&DummyFunction,log_file) ;
  emtNodeSetDirectionURR=new c_Element(sprite,emtNodeSetDirectionURR_X+build_panel_x,emtNodeSetDirectionURR_Y+build_panel_y,
                                       0,0,emtNodeSetDirection_FRAME_X,emtNodeSetDirection_FRAME_Y,
                                       &OnNodeSetDirectionURR_click,&DummyFunction,log_file) ;
  emtNodeSetDirectionR  =new c_Element(sprite,emtNodeSetDirectionR_X+build_panel_x,emtNodeSetDirectionR_Y+build_panel_y,
                                       0,0,emtNodeSetDirection_FRAME_X,emtNodeSetDirection_FRAME_Y,
                                       &OnNodeSetDirectionR_click,&DummyFunction,log_file) ;
  emtNodeSetDirectionDRR=new c_Element(sprite,emtNodeSetDirectionDRR_X+build_panel_x,emtNodeSetDirectionDRR_Y+build_panel_y,
                                       0,0,emtNodeSetDirection_FRAME_X,emtNodeSetDirection_FRAME_Y,
                                       &OnNodeSetDirectionDRR_click,&DummyFunction,log_file) ;
  emtNodeSetDirectionDR =new c_Element(sprite,emtNodeSetDirectionDR_X+build_panel_x,emtNodeSetDirectionDR_Y+build_panel_y,
                                       0,0,emtNodeSetDirection_FRAME_X,emtNodeSetDirection_FRAME_Y,
                                       &OnNodeSetDirectionDR_click,&DummyFunction,log_file) ;
  emtNodeSetDirectionDDR=new c_Element(sprite,emtNodeSetDirectionDDR_X+build_panel_x,emtNodeSetDirectionDDR_Y+build_panel_y,
                                       0,0,emtNodeSetDirection_FRAME_X,emtNodeSetDirection_FRAME_Y,
                                       &OnNodeSetDirectionDDR_click,&DummyFunction,log_file) ;
  emtNodeSetDirectionD  =new c_Element(sprite,emtNodeSetDirectionD_X+build_panel_x,emtNodeSetDirectionD_Y+build_panel_y,
                                       0,0,emtNodeSetDirection_FRAME_X,emtNodeSetDirection_FRAME_Y,
                                       &OnNodeSetDirectionD_click,&DummyFunction,log_file) ;
  emtNodeSetDirectionDDL=new c_Element(sprite,emtNodeSetDirectionDDL_X+build_panel_x,emtNodeSetDirectionDDL_Y+build_panel_y,
                                       0,0,emtNodeSetDirection_FRAME_X,emtNodeSetDirection_FRAME_Y,
                                       &OnNodeSetDirectionDDL_click,&DummyFunction,log_file) ;
  emtNodeSetDirectionDL =new c_Element(sprite,emtNodeSetDirectionDL_X+build_panel_x,emtNodeSetDirectionDL_Y+build_panel_y,
                                       0,0,emtNodeSetDirection_FRAME_X,emtNodeSetDirection_FRAME_Y,
                                       &OnNodeSetDirectionDL_click,&DummyFunction,log_file) ;
  emtNodeSetDirectionDLL=new c_Element(sprite,emtNodeSetDirectionDLL_X+build_panel_x,emtNodeSetDirectionDLL_Y+build_panel_y,
                                       0,0,emtNodeSetDirection_FRAME_X,emtNodeSetDirection_FRAME_Y,
                                       &OnNodeSetDirectionDLL_click,&DummyFunction,log_file) ;
  emtNodeSetDirectionL  =new c_Element(sprite,emtNodeSetDirectionL_X+build_panel_x,emtNodeSetDirectionL_Y+build_panel_y,
                                       0,0,emtNodeSetDirection_FRAME_X,emtNodeSetDirection_FRAME_Y,
                                       &OnNodeSetDirectionL_click,&DummyFunction,log_file) ;
  emtNodeSetDirectionULL=new c_Element(sprite,emtNodeSetDirectionULL_X+build_panel_x,emtNodeSetDirectionULL_Y+build_panel_y,
                                       0,0,emtNodeSetDirection_FRAME_X,emtNodeSetDirection_FRAME_Y,
                                       &OnNodeSetDirectionULL_click,&DummyFunction,log_file) ;
  emtNodeSetDirectionUL =new c_Element(sprite,emtNodeSetDirectionUL_X+build_panel_x,emtNodeSetDirectionUL_Y+build_panel_y,
                                       0,0,emtNodeSetDirection_FRAME_X,emtNodeSetDirection_FRAME_Y,
                                       &OnNodeSetDirectionUL_click,&DummyFunction,log_file) ;
  emtNodeSetDirectionUUL=new c_Element(sprite,emtNodeSetDirectionUUL_X+build_panel_x,emtNodeSetDirectionUUL_Y+build_panel_y,
                                       0,0,emtNodeSetDirection_FRAME_X,emtNodeSetDirection_FRAME_Y,
                                       &OnNodeSetDirectionUUL_click,&DummyFunction,log_file) ;
  emtNodeSetDirectionU->DSetElementCoord  (7,7);
  emtNodeSetDirectionUUR->DSetElementCoord(7,7);
  emtNodeSetDirectionUR->DSetElementCoord (7,7);
  emtNodeSetDirectionURR->DSetElementCoord(7,7);
  emtNodeSetDirectionR->DSetElementCoord  (7,7);
  emtNodeSetDirectionDRR->DSetElementCoord(7,7);
  emtNodeSetDirectionDR->DSetElementCoord (7,7);
  emtNodeSetDirectionDDR->DSetElementCoord(7,7);
  emtNodeSetDirectionD->DSetElementCoord  (7,7);
  emtNodeSetDirectionDDL->DSetElementCoord(7,7);
  emtNodeSetDirectionDL->DSetElementCoord (7,7);
  emtNodeSetDirectionDLL->DSetElementCoord(7,7);
  emtNodeSetDirectionL->DSetElementCoord  (7,7);
  emtNodeSetDirectionULL->DSetElementCoord(7,7);
  emtNodeSetDirectionUL->DSetElementCoord (7,7);
  emtNodeSetDirectionUUL->DSetElementCoord(7,7);
  emtNodeSetDirectionU->SetElementSize  (5,5);
  emtNodeSetDirectionUUR->SetElementSize(5,5);
  emtNodeSetDirectionUR->SetElementSize (5,5);
  emtNodeSetDirectionURR->SetElementSize(5,5);
  emtNodeSetDirectionR->SetElementSize  (5,5);
  emtNodeSetDirectionDRR->SetElementSize(5,5);
  emtNodeSetDirectionDR->SetElementSize (5,5);
  emtNodeSetDirectionDDR->SetElementSize(5,5);
  emtNodeSetDirectionD->SetElementSize  (5,5);
  emtNodeSetDirectionDDL->SetElementSize(5,5);
  emtNodeSetDirectionDL->SetElementSize (5,5);
  emtNodeSetDirectionDLL->SetElementSize(5,5);
  emtNodeSetDirectionL->SetElementSize  (5,5);
  emtNodeSetDirectionULL->SetElementSize(5,5);
  emtNodeSetDirectionUL->SetElementSize (5,5);
  emtNodeSetDirectionUUL->SetElementSize(5,5);
///////////////////////////////////////
  emtBuildNext = new c_Element(sprite,emtBuildNext_X+build_panel_x,emtBuildNext_Y+build_panel_y,0,0,
                               emtBuildNext_FRAME_X,emtBuildNext_FRAME_Y,
                               &OnBuildNext_click,&DummyFunction,log_file) ;
  emtBuildPrev = new c_Element(sprite,emtBuildPrev_X+build_panel_x,emtBuildPrev_Y+build_panel_y,0,0,
                               emtBuildPrev_FRAME_X,emtBuildPrev_FRAME_Y,
                               &OnBuildPrev_click,&DummyFunction,log_file) ;
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
///////////////////////////////////////
  emtDestroyBuilding = new c_Element(sprite,emtDestroyBuilding_X+common_panel_x,emtDestroyBuilding_Y+common_panel_y,
                                     0,0,emtDestroyBuilding_FRAME_X,emtDestroyBuilding_FRAME_Y,
                                     &OnDestroyBuilding_click,&DummyFunction,log_file) ;
///////////////////////////////////////
  emtShowTerritory = new c_Element(sprite,emtShowTerritory_X+common_panel_x,emtShowTerritory_Y+common_panel_Y,
                                   0,0,emtShowTerritory_FRAME_X,emtShowTerritory_FRAME_Y,
                                   &OnShowTerritory_click,&DummyFunction,log_file) ;
///////////////////////////////////////
  emtBuildingEnable = new c_Element(sprite,emtBuildingEnable_X+common_panel_x,emtBuildingEnable_Y+common_panel_Y,
                                    0,0,emtBuildingEnable_FRAME_X,emtBuildingEnable_FRAME_Y,
                                    &OnBuildingEnable_click,&DummyFunction,log_file) ;
} ;
//---------------------------------------------------------------------------
void c_HiveElements::Release(FILE *log_file)
{
  if(log_file)fprintf(log_file,"START c_HiveElements::Release\n") ;
  if(log_file)fprintf(log_file,"   releasing...\n") ;

  delete emtNodeSetDirectionU;
  delete emtNodeSetDirectionUUL;
  delete emtNodeSetDirectionUL;
  delete emtNodeSetDirectionULL;
  delete emtNodeSetDirectionL;
  delete emtNodeSetDirectionDLL;
  delete emtNodeSetDirectionDL;
  delete emtNodeSetDirectionDDL;
  delete emtNodeSetDirectionD;
  delete emtNodeSetDirectionDDR;
  delete emtNodeSetDirectionDR;
  delete emtNodeSetDirectionDRR;
  delete emtNodeSetDirectionR;
  delete emtNodeSetDirectionURR;
  delete emtNodeSetDirectionUR;
  delete emtNodeSetDirectionUUR;

  delete emtBuildNext ;
  delete emtBuildPrev ;

  delete emtBuildNode ;
  delete emtBuildMine ;
  delete emtBuildFactory ;
  delete emtBuildCharge ;
  delete emtBuildSpeed ;

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
      emtNodeSetDirectionU->CheckState(mouse,world,action,player_ID) ;
      emtNodeSetDirectionUUL->CheckState(mouse,world,action,player_ID) ;
      emtNodeSetDirectionUL->CheckState(mouse,world,action,player_ID) ;
      emtNodeSetDirectionULL->CheckState(mouse,world,action,player_ID) ;
      emtNodeSetDirectionL->CheckState(mouse,world,action,player_ID) ;
      emtNodeSetDirectionDLL->CheckState(mouse,world,action,player_ID) ;
      emtNodeSetDirectionDL->CheckState(mouse,world,action,player_ID) ;
      emtNodeSetDirectionDDL->CheckState(mouse,world,action,player_ID) ;
      emtNodeSetDirectionD->CheckState(mouse,world,action,player_ID) ;
      emtNodeSetDirectionDDR->CheckState(mouse,world,action,player_ID) ;
      emtNodeSetDirectionDR->CheckState(mouse,world,action,player_ID) ;
      emtNodeSetDirectionDRR->CheckState(mouse,world,action,player_ID) ;
      emtNodeSetDirectionR->CheckState(mouse,world,action,player_ID) ;
      emtNodeSetDirectionURR->CheckState(mouse,world,action,player_ID) ;
      emtNodeSetDirectionUR->CheckState(mouse,world,action,player_ID) ;
      emtNodeSetDirectionUUR->CheckState(mouse,world,action,player_ID) ;
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
  } ;
  switch(common_screen_panel)
  {
    case screen_panel_COMMON_BUILDING :
      emtDestroyBuilding->CheckState(mouse,world,action,player_ID) ;
      emtBuildingEnable->CheckState(mouse,world,action,player_ID) ;
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
HRESULT c_HiveElements::Draw(IDirectDrawSurface *DDSSurface,FILE *log_file)
{
  HRESULT res;
  res=font->Draw(DDSSurface,(world->player[player_ID]).resurce_count,font_RESURCE_X,font_RESURCE_Y,0) ;//вывести кол-во ресурсов
  if(res!=DD_OK)return res;
  switch(build_screen_panel)
  {
    case screen_panel_BUILD_NODE :
      res = emtNodeSetDirectionU->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res = emtNodeSetDirectionUUL->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res = emtNodeSetDirectionUL->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res = emtNodeSetDirectionULL->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res = emtNodeSetDirectionL->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res = emtNodeSetDirectionDLL->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res = emtNodeSetDirectionDL->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res = emtNodeSetDirectionDDL->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res = emtNodeSetDirectionD->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res = emtNodeSetDirectionDDR->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res = emtNodeSetDirectionDR->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res = emtNodeSetDirectionDRR->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res = emtNodeSetDirectionR->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res = emtNodeSetDirectionURR->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res = emtNodeSetDirectionUR->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res = emtNodeSetDirectionUUR->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
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
    //...
  } ;
  switch(common_screen_panel)
  {
    case screen_panel_COMMON_NO :
      res=emtShowTerritory->Draw(DDSSurface,log_file) ;
      if(res!=DD_OK)return res;
      res=font->Draw(DDSSurface,"The Hive",8,font_common_X+common_panel_x,font_common_Y+common_panel_y,2) ;
      if(res!=DD_OK)return res;
      //...
    break;
    case screen_panel_COMMON_BUILDING :
    {
      int x=param[0],y=param[1];
      switch((world->building[x][y]).type)
      {
        case building_type_MAIN :
          res=font->Draw(DDSSurface,"MAIN core",9,font_common_X+common_panel_x,font_common_Y+common_panel_y,2) ;
          if(res!=DD_OK)return res;
          //... out building info
        break;
        case building_type_BASE :
          res=font->Draw(DDSSurface,"Base",4,font_common_X+common_panel_x,font_common_Y+common_panel_y,2) ;
          if(res!=DD_OK)return res;
          //... out building info
        break;
        case building_type_NODE :
          res=font->Draw(DDSSurface,"Node",4,font_common_X+common_panel_x,font_common_Y+common_panel_y,2) ;
          if(res!=DD_OK)return res;

          res=emtDestroyBuilding->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
          if((world->building[x][y]).enable==0) emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y+1);
          else                                  emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y);
          res=emtBuildingEnable->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
          //... out building info
        break;
        case building_type_FACTORY :
          res=font->Draw(DDSSurface,"Factory",7,font_common_X+common_panel_x,font_common_Y+common_panel_y,2) ;
          if(res!=DD_OK)return res;
          //... out building info
          res=emtDestroyBuilding->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
          if((world->building[x][y]).enable==0) emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y+1);
          else                                  emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y);
          res=emtBuildingEnable->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
        break;
        case building_type_SPEED :
          res=font->Draw(DDSSurface,"Speed",5,font_common_X+common_panel_x,font_common_Y+common_panel_y,2) ;
          if(res!=DD_OK)return res;
          //... out building info
          res=emtDestroyBuilding->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
          if((world->building[x][y]).enable==0) emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y+1);
          else                                  emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y);
          res=emtBuildingEnable->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
        break;
        case building_type_MINE :
          res=font->Draw(DDSSurface,"Mine",4,font_common_X+common_panel_x,font_common_Y+common_panel_y,2) ;
          if(res!=DD_OK)return res;
          //... out building info
          res=emtDestroyBuilding->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
          if((world->building[x][y]).enable==0) emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y+1);
          else                                  emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y);
          res=emtBuildingEnable->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
        break;
        case building_type_CHARGE :
          res=font->Draw(DDSSurface,"Charge",6,font_common_X+common_panel_x,font_common_Y+common_panel_y,2) ;
          if(res!=DD_OK)return res;
          //... out building info
          res=emtDestroyBuilding->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
          if((world->building[x][y]).enable==0) emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y+1);
          else                                  emtBuildingEnable->SetFrameY(emtBuildingEnable_FRAME_Y);
          res=emtBuildingEnable->Draw(DDSSurface,log_file) ;
          if(res!=DD_OK)return res;
        break;
        case building_type_CONSTRUCTING :
          switch((int)((world->building[x][y]).param[0]))
          {
            case building_type_FACTORY :
              res=font->Draw(DDSSurface,"Build Factory",13,font_common_X+common_panel_x,font_common_Y+common_panel_y,2) ;
              if(res!=DD_OK)return res;
            break;
            case building_type_MINE :
              res=font->Draw(DDSSurface,"Build Mine",10,font_common_X+common_panel_x,font_common_Y+common_panel_y,2) ;
              if(res!=DD_OK)return res;
            break;
            case building_type_CHARGE :
              res=font->Draw(DDSSurface,"Build Charge",12,font_common_X+common_panel_x,font_common_Y+common_panel_y,2) ;
              if(res!=DD_OK)return res;
            break;
            case building_type_SPEED :
              res=font->Draw(DDSSurface,"Build Speed",11,font_common_X+common_panel_x,font_common_Y+common_panel_y,2) ;
              if(res!=DD_OK)return res;
            break ;
          } ;
          res=font->Draw(DDSSurface,(int)((world->building[x][y]).param[1]),font_common_X*4+common_panel_x,font_common_Y*2+common_panel_y,2) ;
          if(res!=DD_OK)return res;
          //... out building info
        break;
        case building_type_MINERAL :
          res=font->Draw(DDSSurface,"Mineral",7,font_common_X+common_panel_x,font_common_Y+common_panel_y,2);
          if(res!=DD_OK)return res;
          res=font->Draw(DDSSurface,(int)((world->building[x][y]).param[0]),font_common_X*4+common_panel_x,font_common_Y*2+common_panel_y,2) ;
          if(res!=DD_OK)return res;
      } ;
    };
    break;
    //...
  } ;
  res=emtBuildNext->Draw(DDSSurface,log_file) ;
  if(res!=DD_OK)return res;
  res=emtBuildPrev->Draw(DDSSurface,log_file) ;
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
    if(build_screen_panel==screen_panel_BUILD_NODE)
    {
      emtNodeSetDirectionU  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionULL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionL  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDLL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionD  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDRR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionR  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionURR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
    } ;
    return ;
  } ;
  switch(action)
  {
    case action_BUILD_NEXT :
      emtBuildNext->SetFrameY(emtBuildNext_FRAME_Y) ;
      if(build_screen_panel<4)build_screen_panel++;
      action=action_NO ;
    break;
    case action_BUILD_PREV :
      emtBuildPrev->SetFrameY(emtBuildPrev_FRAME_Y) ;
      if(build_screen_panel>0)build_screen_panel--;
      action=action_NO ;
    break;
    case action_BUILD_NODE_U :
      //emtNodeSetDirectionU  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionULL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionL  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDLL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionD  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDRR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionR  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionURR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
    break ;
    case action_BUILD_NODE_UUL :
      emtNodeSetDirectionU  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      //emtNodeSetDirectionUUL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionULL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionL  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDLL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionD  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDRR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionR  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionURR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
    break ;
    case action_BUILD_NODE_UL :
      emtNodeSetDirectionU  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      //emtNodeSetDirectionUL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionULL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionL  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDLL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionD  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDRR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionR  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionURR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
    break ;
    case action_BUILD_NODE_ULL :
      emtNodeSetDirectionU  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      //emtNodeSetDirectionULL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionL  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDLL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionD  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDRR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionR  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionURR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
    break ;
    case action_BUILD_NODE_L :
      emtNodeSetDirectionU  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionULL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      //emtNodeSetDirectionL  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDLL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionD  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDRR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionR  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionURR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
    break ;
    case action_BUILD_NODE_DLL :
      emtNodeSetDirectionU  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionULL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionL  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      //emtNodeSetDirectionDLL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionD  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDRR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionR  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionURR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
    break ;
    case action_BUILD_NODE_DL :
      emtNodeSetDirectionU  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionULL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionL  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDLL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      //emtNodeSetDirectionDL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionD  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDRR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionR  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionURR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
    break ;
    case action_BUILD_NODE_DDL :
      emtNodeSetDirectionU  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionULL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionL  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDLL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      //emtNodeSetDirectionDDL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionD  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDRR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionR  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionURR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
    break ;
    case action_BUILD_NODE_D :
      emtNodeSetDirectionU  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionULL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionL  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDLL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      //emtNodeSetDirectionD  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDRR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionR  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionURR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
    break ;
    case action_BUILD_NODE_DDR :
      emtNodeSetDirectionU  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionULL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionL  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDLL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionD  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      //emtNodeSetDirectionDDR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDRR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionR  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionURR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
    break ;
    case action_BUILD_NODE_DR :
      emtNodeSetDirectionU  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionULL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionL  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDLL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionD  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      //emtNodeSetDirectionDR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDRR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionR  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionURR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
    break ;
    case action_BUILD_NODE_DRR :
      emtNodeSetDirectionU  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionULL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionL  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDLL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionD  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      //emtNodeSetDirectionDRR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionR  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionURR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
    break ;
    case action_BUILD_NODE_R :
      emtNodeSetDirectionU  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionULL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionL  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDLL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionD  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDRR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      //emtNodeSetDirectionR  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionURR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
    break ;
    case action_BUILD_NODE_URR :
      emtNodeSetDirectionU  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionULL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionL  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDLL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionD  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDRR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionR  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      //emtNodeSetDirectionURR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
    break ;
    case action_BUILD_NODE_UR :
      emtNodeSetDirectionU  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionULL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionL  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDLL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionD  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDRR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionR  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionURR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      //emtNodeSetDirectionUR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
    break ;
    case action_BUILD_NODE_UUR :
      emtNodeSetDirectionU  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUUL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionULL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionL  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDLL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDL ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionD  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDDR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionDRR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionR  ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionURR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      emtNodeSetDirectionUR ->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
      //emtNodeSetDirectionUUR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
    break ;
    case action_BUILDING_CLICK :
      action=action_NO ;
      common_screen_panel=screen_panel_COMMON_BUILDING;
    break ;
    case action_DESTROY_BUILDING :
      action=action_NO ;
      emtDestroyBuilding->SetFrameY(emtDestroyBuilding_FRAME_Y) ;
      common_screen_panel = screen_panel_COMMON_NO ;
      {
        int x=param[0],y=param[1];
        (world->building[x][y]).type = building_type_NO ;
      } ;
    break;
    case action_SHOW_TERRITORY :
      action=action_NO ;
      if((world->player[player_ID]).show_territory==0) (world->player[player_ID]).show_territory=1;
      else                                             (world->player[player_ID]).show_territory=0;
    //...
    break;
    case action_BUILDING_ENABLE :
      action=action_NO ;
      {
        int x=param[0],y=param[1];
        if((world->building[x][y]).enable == 0)(world->building[x][y]).enable=1;
        else                                   (world->building[x][y]).enable=0; 
      } ;
    break;
  } ;
  if(mouse->button==mouse_button_LEFT&&mouse->y_frame==building_y_frame_GOODPLACE)
  {
    switch(action)
    {
      case action_BUILD_NODE_U :
        emtNodeSetDirectionU->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
        action=action_NO ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_NODE ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame = building_y_frame_NODE_U ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=building_NODE_RANGE;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=-2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=building_NODE_SKIPENABLE_COUNT;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        {  // добавление территории вокруг здания
          int start_x=mouse->cell_x-building_territory_ADD_COUNT,
              end_x  =mouse->cell_x+building_territory_ADD_COUNT,
              start_y=mouse->cell_y-building_territory_ADD_COUNT,
              end_y  =mouse->cell_y+building_territory_ADD_COUNT;
          if(start_x<0)start_x=0;
          if(end_x>=world_X_COUNT)end_x=world_X_COUNT-1;
          if(start_y<0)start_y=0;
          if(end_y>=world_Y_COUNT)end_y=world_Y_COUNT-1;
          for(int x=start_x;x<=end_x;x++)
            for(int y=start_y;y<=end_y;y++)
              if((world->building[x][y]).territory==building_territory_NEUTRAL)
                (world->building[x][y]).territory=player_ID ;
        } ;
      break ;
      case action_BUILD_NODE_UUL :
        emtNodeSetDirectionUUL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
        action=action_NO ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_NODE ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame = building_y_frame_NODE_UUL ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=building_NODE_RANGE;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=-1;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=-2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=building_NODE_SKIPENABLE_COUNT;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        {  // добавление территории вокруг здания
          int start_x=mouse->cell_x-building_territory_ADD_COUNT,
              end_x  =mouse->cell_x+building_territory_ADD_COUNT,
              start_y=mouse->cell_y-building_territory_ADD_COUNT,
              end_y  =mouse->cell_y+building_territory_ADD_COUNT;
          if(start_x<0)start_x=0;
          if(end_x>=world_X_COUNT)end_x=world_X_COUNT-1;
          if(start_y<0)start_y=0;
          if(end_y>=world_Y_COUNT)end_y=world_Y_COUNT-1;
          for(int x=start_x;x<=end_x;x++)
            for(int y=start_y;y<=end_y;y++)
              if((world->building[x][y]).territory==building_territory_NEUTRAL)
                (world->building[x][y]).territory=player_ID ;
        } ;
      break ;
      case action_BUILD_NODE_UL :
        emtNodeSetDirectionUL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
        action=action_NO ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_NODE ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame = building_y_frame_NODE_UL ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=building_NODE_RANGE;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=-2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=-2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=building_NODE_SKIPENABLE_COUNT;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        {  // добавление территории вокруг здания
          int start_x=mouse->cell_x-building_territory_ADD_COUNT,
              end_x  =mouse->cell_x+building_territory_ADD_COUNT,
              start_y=mouse->cell_y-building_territory_ADD_COUNT,
              end_y  =mouse->cell_y+building_territory_ADD_COUNT;
          if(start_x<0)start_x=0;
          if(end_x>=world_X_COUNT)end_x=world_X_COUNT-1;
          if(start_y<0)start_y=0;
          if(end_y>=world_Y_COUNT)end_y=world_Y_COUNT-1;
          for(int x=start_x;x<=end_x;x++)
            for(int y=start_y;y<=end_y;y++)
              if((world->building[x][y]).territory==building_territory_NEUTRAL)
                (world->building[x][y]).territory=player_ID ;
        } ;
      break ;
      case action_BUILD_NODE_ULL :
        emtNodeSetDirectionULL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
        action=action_NO ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_NODE ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame = building_y_frame_NODE_ULL ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=building_NODE_RANGE;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=-2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=-1;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=building_NODE_SKIPENABLE_COUNT;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        {  // добавление территории вокруг здания
          int start_x=mouse->cell_x-building_territory_ADD_COUNT,
              end_x  =mouse->cell_x+building_territory_ADD_COUNT,
              start_y=mouse->cell_y-building_territory_ADD_COUNT,
              end_y  =mouse->cell_y+building_territory_ADD_COUNT;
          if(start_x<0)start_x=0;
          if(end_x>=world_X_COUNT)end_x=world_X_COUNT-1;
          if(start_y<0)start_y=0;
          if(end_y>=world_Y_COUNT)end_y=world_Y_COUNT-1;
          for(int x=start_x;x<=end_x;x++)
            for(int y=start_y;y<=end_y;y++)
              if((world->building[x][y]).territory==building_territory_NEUTRAL)
                (world->building[x][y]).territory=player_ID ;
        } ;
      break ;
      case action_BUILD_NODE_L :
        emtNodeSetDirectionL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
        action=action_NO ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_NODE ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame = building_y_frame_NODE_L ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=building_NODE_RANGE;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=-2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=building_NODE_SKIPENABLE_COUNT;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        {  // добавление территории вокруг здания
          int start_x=mouse->cell_x-building_territory_ADD_COUNT,
              end_x  =mouse->cell_x+building_territory_ADD_COUNT,
              start_y=mouse->cell_y-building_territory_ADD_COUNT,
              end_y  =mouse->cell_y+building_territory_ADD_COUNT;
          if(start_x<0)start_x=0;
          if(end_x>=world_X_COUNT)end_x=world_X_COUNT-1;
          if(start_y<0)start_y=0;
          if(end_y>=world_Y_COUNT)end_y=world_Y_COUNT-1;
          for(int x=start_x;x<=end_x;x++)
            for(int y=start_y;y<=end_y;y++)
              if((world->building[x][y]).territory==building_territory_NEUTRAL)
                (world->building[x][y]).territory=player_ID ;
        } ;
      break ;
      case action_BUILD_NODE_DLL :
        emtNodeSetDirectionDLL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
        action=action_NO ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_NODE ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame = building_y_frame_NODE_DLL ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=building_NODE_RANGE;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=-2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=1;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=building_NODE_SKIPENABLE_COUNT;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        {  // добавление территории вокруг здания
          int start_x=mouse->cell_x-building_territory_ADD_COUNT,
              end_x  =mouse->cell_x+building_territory_ADD_COUNT,
              start_y=mouse->cell_y-building_territory_ADD_COUNT,
              end_y  =mouse->cell_y+building_territory_ADD_COUNT;
          if(start_x<0)start_x=0;
          if(end_x>=world_X_COUNT)end_x=world_X_COUNT-1;
          if(start_y<0)start_y=0;
          if(end_y>=world_Y_COUNT)end_y=world_Y_COUNT-1;
          for(int x=start_x;x<=end_x;x++)
            for(int y=start_y;y<=end_y;y++)
              if((world->building[x][y]).territory==building_territory_NEUTRAL)
                (world->building[x][y]).territory=player_ID ;
        } ;
      break ;
      case action_BUILD_NODE_DL :
        emtNodeSetDirectionDL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
        action=action_NO ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_NODE ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame = building_y_frame_NODE_DL ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=building_NODE_RANGE;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=-2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=building_NODE_SKIPENABLE_COUNT;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        {  // добавление территории вокруг здания
          int start_x=mouse->cell_x-building_territory_ADD_COUNT,
              end_x  =mouse->cell_x+building_territory_ADD_COUNT,
              start_y=mouse->cell_y-building_territory_ADD_COUNT,
              end_y  =mouse->cell_y+building_territory_ADD_COUNT;
          if(start_x<0)start_x=0;
          if(end_x>=world_X_COUNT)end_x=world_X_COUNT-1;
          if(start_y<0)start_y=0;
          if(end_y>=world_Y_COUNT)end_y=world_Y_COUNT-1;
          for(int x=start_x;x<=end_x;x++)
            for(int y=start_y;y<=end_y;y++)
              if((world->building[x][y]).territory==building_territory_NEUTRAL)
                (world->building[x][y]).territory=player_ID ;
        } ;
      break ;
      case action_BUILD_NODE_DDL :
        emtNodeSetDirectionDDL->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
        action=action_NO ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_NODE ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame = building_y_frame_NODE_DDL ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=building_NODE_RANGE;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=-1;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=building_NODE_SKIPENABLE_COUNT;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        {  // добавление территории вокруг здания
          int start_x=mouse->cell_x-building_territory_ADD_COUNT,
              end_x  =mouse->cell_x+building_territory_ADD_COUNT,
              start_y=mouse->cell_y-building_territory_ADD_COUNT,
              end_y  =mouse->cell_y+building_territory_ADD_COUNT;
          if(start_x<0)start_x=0;
          if(end_x>=world_X_COUNT)end_x=world_X_COUNT-1;
          if(start_y<0)start_y=0;
          if(end_y>=world_Y_COUNT)end_y=world_Y_COUNT-1;
          for(int x=start_x;x<=end_x;x++)
            for(int y=start_y;y<=end_y;y++)
              if((world->building[x][y]).territory==building_territory_NEUTRAL)
                (world->building[x][y]).territory=player_ID ;
        } ;
      break ;
      case action_BUILD_NODE_D :
        emtNodeSetDirectionD->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
        action=action_NO ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_NODE ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame = building_y_frame_NODE_D ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=building_NODE_RANGE;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=building_NODE_SKIPENABLE_COUNT;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        {  // добавление территории вокруг здания
          int start_x=mouse->cell_x-building_territory_ADD_COUNT,
              end_x  =mouse->cell_x+building_territory_ADD_COUNT,
              start_y=mouse->cell_y-building_territory_ADD_COUNT,
              end_y  =mouse->cell_y+building_territory_ADD_COUNT;
          if(start_x<0)start_x=0;
          if(end_x>=world_X_COUNT)end_x=world_X_COUNT-1;
          if(start_y<0)start_y=0;
          if(end_y>=world_Y_COUNT)end_y=world_Y_COUNT-1;
          for(int x=start_x;x<=end_x;x++)
            for(int y=start_y;y<=end_y;y++)
              if((world->building[x][y]).territory==building_territory_NEUTRAL)
                (world->building[x][y]).territory=player_ID ;
        } ;
      break ;
      case action_BUILD_NODE_DDR :
        emtNodeSetDirectionDDR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
        action=action_NO ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_NODE ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame = building_y_frame_NODE_DDR ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=building_NODE_RANGE;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=1;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=building_NODE_SKIPENABLE_COUNT;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        {  // добавление территории вокруг здания
          int start_x=mouse->cell_x-building_territory_ADD_COUNT,
              end_x  =mouse->cell_x+building_territory_ADD_COUNT,
              start_y=mouse->cell_y-building_territory_ADD_COUNT,
              end_y  =mouse->cell_y+building_territory_ADD_COUNT;
          if(start_x<0)start_x=0;
          if(end_x>=world_X_COUNT)end_x=world_X_COUNT-1;
          if(start_y<0)start_y=0;
          if(end_y>=world_Y_COUNT)end_y=world_Y_COUNT-1;
          for(int x=start_x;x<=end_x;x++)
            for(int y=start_y;y<=end_y;y++)
              if((world->building[x][y]).territory==building_territory_NEUTRAL)
                (world->building[x][y]).territory=player_ID ;
        } ;
      break ;
      case action_BUILD_NODE_DR :
        emtNodeSetDirectionU->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
        action=action_NO ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_NODE ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame = building_y_frame_NODE_DR ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=building_NODE_RANGE;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=building_NODE_SKIPENABLE_COUNT;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        {  // добавление территории вокруг здания
          int start_x=mouse->cell_x-building_territory_ADD_COUNT,
              end_x  =mouse->cell_x+building_territory_ADD_COUNT,
              start_y=mouse->cell_y-building_territory_ADD_COUNT,
              end_y  =mouse->cell_y+building_territory_ADD_COUNT;
          if(start_x<0)start_x=0;
          if(end_x>=world_X_COUNT)end_x=world_X_COUNT-1;
          if(start_y<0)start_y=0;
          if(end_y>=world_Y_COUNT)end_y=world_Y_COUNT-1;
          for(int x=start_x;x<=end_x;x++)
            for(int y=start_y;y<=end_y;y++)
              if((world->building[x][y]).territory==building_territory_NEUTRAL)
                (world->building[x][y]).territory=player_ID ;
        } ;
      break ;
      case action_BUILD_NODE_DRR :
        emtNodeSetDirectionDRR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
        action=action_NO ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_NODE ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame = building_y_frame_NODE_DRR ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=building_NODE_RANGE;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=1;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=building_NODE_SKIPENABLE_COUNT;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        {  // добавление территории вокруг здания
          int start_x=mouse->cell_x-building_territory_ADD_COUNT,
              end_x  =mouse->cell_x+building_territory_ADD_COUNT,
              start_y=mouse->cell_y-building_territory_ADD_COUNT,
              end_y  =mouse->cell_y+building_territory_ADD_COUNT;
          if(start_x<0)start_x=0;
          if(end_x>=world_X_COUNT)end_x=world_X_COUNT-1;
          if(start_y<0)start_y=0;
          if(end_y>=world_Y_COUNT)end_y=world_Y_COUNT-1;
          for(int x=start_x;x<=end_x;x++)
            for(int y=start_y;y<=end_y;y++)
              if((world->building[x][y]).territory==building_territory_NEUTRAL)
                (world->building[x][y]).territory=player_ID ;
        } ;
      break ;
      case action_BUILD_NODE_R :
        emtNodeSetDirectionR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
        action=action_NO ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_NODE ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame = building_y_frame_NODE_R ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=building_NODE_RANGE;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=building_NODE_SKIPENABLE_COUNT;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        {  // добавление территории вокруг здания
          int start_x=mouse->cell_x-building_territory_ADD_COUNT,
              end_x  =mouse->cell_x+building_territory_ADD_COUNT,
              start_y=mouse->cell_y-building_territory_ADD_COUNT,
              end_y  =mouse->cell_y+building_territory_ADD_COUNT;
          if(start_x<0)start_x=0;
          if(end_x>=world_X_COUNT)end_x=world_X_COUNT-1;
          if(start_y<0)start_y=0;
          if(end_y>=world_Y_COUNT)end_y=world_Y_COUNT-1;
          for(int x=start_x;x<=end_x;x++)
            for(int y=start_y;y<=end_y;y++)
              if((world->building[x][y]).territory==building_territory_NEUTRAL)
                (world->building[x][y]).territory=player_ID ;
        } ;
      break ;
      case action_BUILD_NODE_URR :
        emtNodeSetDirectionURR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
        action=action_NO ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_NODE ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame = building_y_frame_NODE_URR ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=building_NODE_RANGE;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=-1;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=building_NODE_SKIPENABLE_COUNT;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        {  // добавление территории вокруг здания
          int start_x=mouse->cell_x-building_territory_ADD_COUNT,
              end_x  =mouse->cell_x+building_territory_ADD_COUNT,
              start_y=mouse->cell_y-building_territory_ADD_COUNT,
              end_y  =mouse->cell_y+building_territory_ADD_COUNT;
          if(start_x<0)start_x=0;
          if(end_x>=world_X_COUNT)end_x=world_X_COUNT-1;
          if(start_y<0)start_y=0;
          if(end_y>=world_Y_COUNT)end_y=world_Y_COUNT-1;
          for(int x=start_x;x<=end_x;x++)
            for(int y=start_y;y<=end_y;y++)
              if((world->building[x][y]).territory==building_territory_NEUTRAL)
                (world->building[x][y]).territory=player_ID ;
        } ;
      break ;
      case action_BUILD_NODE_UR :
        emtNodeSetDirectionUR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
        action=action_NO ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_NODE ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame = building_y_frame_NODE_UR ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=building_NODE_RANGE;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=-2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=building_NODE_SKIPENABLE_COUNT;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        {  // добавление территории вокруг здания
          int start_x=mouse->cell_x-building_territory_ADD_COUNT,
              end_x  =mouse->cell_x+building_territory_ADD_COUNT,
              start_y=mouse->cell_y-building_territory_ADD_COUNT,
              end_y  =mouse->cell_y+building_territory_ADD_COUNT;
          if(start_x<0)start_x=0;
          if(end_x>=world_X_COUNT)end_x=world_X_COUNT-1;
          if(start_y<0)start_y=0;
          if(end_y>=world_Y_COUNT)end_y=world_Y_COUNT-1;
          for(int x=start_x;x<=end_x;x++)
            for(int y=start_y;y<=end_y;y++)
              if((world->building[x][y]).territory==building_territory_NEUTRAL)
                (world->building[x][y]).territory=player_ID ;
        } ;
      break ;
      case action_BUILD_NODE_UUR :
        emtNodeSetDirectionUUR->SetFrameY(emtNodeSetDirection_FRAME_Y) ;
        action=action_NO ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_NODE ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame = building_y_frame_NODE_UUR ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=building_NODE_RANGE;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=1;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=-2;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=building_NODE_SKIPENABLE_COUNT;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        {  // добавление территории вокруг здания
          int start_x=mouse->cell_x-building_territory_ADD_COUNT,
              end_x  =mouse->cell_x+building_territory_ADD_COUNT,
              start_y=mouse->cell_y-building_territory_ADD_COUNT,
              end_y  =mouse->cell_y+building_territory_ADD_COUNT;
          if(start_x<0)start_x=0;
          if(end_x>=world_X_COUNT)end_x=world_X_COUNT-1;
          if(start_y<0)start_y=0;
          if(end_y>=world_Y_COUNT)end_y=world_Y_COUNT-1;
          for(int x=start_x;x<=end_x;x++)
            for(int y=start_y;y<=end_y;y++)
              if((world->building[x][y]).territory==building_territory_NEUTRAL)
                (world->building[x][y]).territory=player_ID ;
        } ;
      break ;
      case action_BUILD_FACTORY :
        action=action_NO ;
        emtBuildFactory->SetFrameY(emtBuildFactory_FRAME_Y) ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_CONSTRUCTING ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame=0 ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=building_type_FACTORY ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=building_FACTORY_BUILD_TIME ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=mouse->cell_x+building_exit_coord_X ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=mouse->cell_y+building_exit_coord_Y ;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        (world->building[mouse->cell_x][mouse->cell_y]).enable=1;
      break;
      case action_BUILD_MINE :
        action=action_NO ;
        emtBuildMine->SetFrameY(emtBuildMine_FRAME_Y) ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_CONSTRUCTING ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame=0 ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=building_type_MINE ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=building_MINE_BUILD_TIME ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=mouse->cell_x+building_exit_coord_X ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=mouse->cell_y+building_exit_coord_Y ;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        (world->building[mouse->cell_x][mouse->cell_y]).enable=1;
      break;
      case action_BUILD_CHARGE :
        action=action_NO ;
        emtBuildCharge->SetFrameY(emtBuildCharge_FRAME_Y) ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_CONSTRUCTING ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame=0 ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=building_type_CHARGE ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=building_CHARGE_BUILD_TIME ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=mouse->cell_x+building_exit_coord_X ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=mouse->cell_y+building_exit_coord_Y ;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        (world->building[mouse->cell_x][mouse->cell_y]).enable=1;
      break;
      case action_BUILD_SPEED :
        action=action_NO ;
        emtBuildSpeed->SetFrameY(emtBuildSpeed_FRAME_Y) ;
        mouse->x_frame = building_type_SELECT ;
        (world->building[mouse->cell_x][mouse->cell_y]).type=building_type_CONSTRUCTING ;
        (world->building[mouse->cell_x][mouse->cell_y]).y_frame=0 ;
        (world->building[mouse->cell_x][mouse->cell_y]).r=0;
        (world->building[mouse->cell_x][mouse->cell_y]).param[0]=building_type_SPEED ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[1]=building_SPEED_BUILD_TIME ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[2]=mouse->cell_x+building_exit_coord_X ;
        (world->building[mouse->cell_x][mouse->cell_y]).param[3]=mouse->cell_y+building_exit_coord_Y ;
        (world->building[mouse->cell_x][mouse->cell_y]).owner=player_ID;
        (world->building[mouse->cell_x][mouse->cell_y]).enable=1;
      break;
      //...
    } ;
  } ;
} ;
//---------------------------------------------------------------------------
void DummyFunction(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element){} ;
//---------------------------------------------------------------------------
void OnNodeSetDirectionU_click  (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_NODE]>0)//проверка на наличие прототипа здания
    if((world->player[player_ID]).resurce_count>=resurce_NODE_PRICE)//проверка на наличие ресурсов у игрока для постройки
    {
      (world->player[player_ID]).buildings_count[player_buildings_NODE]--;
      (world->player[player_ID]).resurce_count-=resurce_NODE_PRICE ;
      action=action_BUILD_NODE_U ;
      mouse->x_frame=building_type_BUILDPLACE ;
      element->SetFrameY(emtNodeSetDirection_FRAME_Y+1);
    };
};
void OnNodeSetDirectionUUL_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_NODE]>0)//проверка на наличие прототипа здания
    if((world->player[player_ID]).resurce_count>=resurce_NODE_PRICE)//проверка на наличие ресурсов у игрока для постройки
    {
      (world->player[player_ID]).buildings_count[player_buildings_NODE]--;
      (world->player[player_ID]).resurce_count-=resurce_NODE_PRICE ;
      action=action_BUILD_NODE_UUL ;
      mouse->x_frame=building_type_BUILDPLACE ;
      element->SetFrameY(emtNodeSetDirection_FRAME_Y+1);
    };
};
void OnNodeSetDirectionUL_click (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_NODE]>0)//проверка на наличие прототипа здания
    if((world->player[player_ID]).resurce_count>=resurce_NODE_PRICE)//проверка на наличие ресурсов у игрока для постройки
    {
      (world->player[player_ID]).buildings_count[player_buildings_NODE]--;
      (world->player[player_ID]).resurce_count-=resurce_NODE_PRICE ;
      action=action_BUILD_NODE_UL ;
      mouse->x_frame=building_type_BUILDPLACE ;
      element->SetFrameY(emtNodeSetDirection_FRAME_Y+1);
    };
};
void OnNodeSetDirectionULL_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_NODE]>0)//проверка на наличие прототипа здания
    if((world->player[player_ID]).resurce_count>=resurce_NODE_PRICE)//проверка на наличие ресурсов у игрока для постройки
    {
      (world->player[player_ID]).buildings_count[player_buildings_NODE]--;
      (world->player[player_ID]).resurce_count-=resurce_NODE_PRICE ;
      action=action_BUILD_NODE_ULL ;
      mouse->x_frame=building_type_BUILDPLACE ;
      element->SetFrameY(emtNodeSetDirection_FRAME_Y+1);
    };
};
void OnNodeSetDirectionL_click  (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_NODE]>0)//проверка на наличие прототипа здания
    if((world->player[player_ID]).resurce_count>=resurce_NODE_PRICE)//проверка на наличие ресурсов у игрока для постройки
    {
      (world->player[player_ID]).buildings_count[player_buildings_NODE]--;
      (world->player[player_ID]).resurce_count-=resurce_NODE_PRICE ;
      action=action_BUILD_NODE_L ;
      mouse->x_frame=building_type_BUILDPLACE ;
      element->SetFrameY(emtNodeSetDirection_FRAME_Y+1);
    };
};
void OnNodeSetDirectionDLL_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_NODE]>0)//проверка на наличие прототипа здания
    if((world->player[player_ID]).resurce_count>=resurce_NODE_PRICE)//проверка на наличие ресурсов у игрока для постройки
    {
      (world->player[player_ID]).buildings_count[player_buildings_NODE]--;
      (world->player[player_ID]).resurce_count-=resurce_NODE_PRICE ;
      action=action_BUILD_NODE_DLL ;
      mouse->x_frame=building_type_BUILDPLACE ;
      element->SetFrameY(emtNodeSetDirection_FRAME_Y+1);
    };
};
void OnNodeSetDirectionDL_click (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_NODE]>0)//проверка на наличие прототипа здания
    if((world->player[player_ID]).resurce_count>=resurce_NODE_PRICE)//проверка на наличие ресурсов у игрока для постройки
    {
      (world->player[player_ID]).buildings_count[player_buildings_NODE]--;
      (world->player[player_ID]).resurce_count-=resurce_NODE_PRICE ;
      action=action_BUILD_NODE_DL ;
      mouse->x_frame=building_type_BUILDPLACE ;
      element->SetFrameY(emtNodeSetDirection_FRAME_Y+1);
    };
};
void OnNodeSetDirectionDDL_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_NODE]>0)//проверка на наличие прототипа здания
    if((world->player[player_ID]).resurce_count>=resurce_NODE_PRICE)//проверка на наличие ресурсов у игрока для постройки
    {
      (world->player[player_ID]).buildings_count[player_buildings_NODE]--;
      (world->player[player_ID]).resurce_count-=resurce_NODE_PRICE ;
      action=action_BUILD_NODE_DDL ;
      mouse->x_frame=building_type_BUILDPLACE ;
      element->SetFrameY(emtNodeSetDirection_FRAME_Y+1);
    };
};
void OnNodeSetDirectionD_click  (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_NODE]>0)//проверка на наличие прототипа здания
    if((world->player[player_ID]).resurce_count>=resurce_NODE_PRICE)//проверка на наличие ресурсов у игрока для постройки
    {
      (world->player[player_ID]).buildings_count[player_buildings_NODE]--;
      (world->player[player_ID]).resurce_count-=resurce_NODE_PRICE ;
      action=action_BUILD_NODE_D ;
      mouse->x_frame=building_type_BUILDPLACE ;
      element->SetFrameY(emtNodeSetDirection_FRAME_Y+1);
    };
};
void OnNodeSetDirectionDDR_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_NODE]>0)//проверка на наличие прототипа здания
    if((world->player[player_ID]).resurce_count>=resurce_NODE_PRICE)//проверка на наличие ресурсов у игрока для постройки
    {
      (world->player[player_ID]).buildings_count[player_buildings_NODE]--;
      (world->player[player_ID]).resurce_count-=resurce_NODE_PRICE ;
      action=action_BUILD_NODE_DDR ;
      mouse->x_frame=building_type_BUILDPLACE ;
      element->SetFrameY(emtNodeSetDirection_FRAME_Y+1);
    };
};
void OnNodeSetDirectionDR_click (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_NODE]>0)//проверка на наличие прототипа здания
    if((world->player[player_ID]).resurce_count>=resurce_NODE_PRICE)//проверка на наличие ресурсов у игрока для постройки
    {
      (world->player[player_ID]).buildings_count[player_buildings_NODE]--;
      (world->player[player_ID]).resurce_count-=resurce_NODE_PRICE ;
      action=action_BUILD_NODE_DR ;
      mouse->x_frame=building_type_BUILDPLACE ;
      element->SetFrameY(emtNodeSetDirection_FRAME_Y+1);
    };
};
void OnNodeSetDirectionDRR_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_NODE]>0)//проверка на наличие прототипа здания
    if((world->player[player_ID]).resurce_count>=resurce_NODE_PRICE)//проверка на наличие ресурсов у игрока для постройки
    {
      (world->player[player_ID]).buildings_count[player_buildings_NODE]--;
      (world->player[player_ID]).resurce_count-=resurce_NODE_PRICE ;
      action=action_BUILD_NODE_DRR ;
      mouse->x_frame=building_type_BUILDPLACE ;
      element->SetFrameY(emtNodeSetDirection_FRAME_Y+1);
    };
};
void OnNodeSetDirectionR_click  (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_NODE]>0)//проверка на наличие прототипа здания
    if((world->player[player_ID]).resurce_count>=resurce_NODE_PRICE)//проверка на наличие ресурсов у игрока для постройки
    {
      (world->player[player_ID]).buildings_count[player_buildings_NODE]--;
      (world->player[player_ID]).resurce_count-=resurce_NODE_PRICE ;
      action=action_BUILD_NODE_R ;
      mouse->x_frame=building_type_BUILDPLACE ;
      element->SetFrameY(emtNodeSetDirection_FRAME_Y+1);
    };
};
void OnNodeSetDirectionURR_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_NODE]>0)//проверка на наличие прототипа здания
    if((world->player[player_ID]).resurce_count>=resurce_NODE_PRICE)//проверка на наличие ресурсов у игрока для постройки
    {
      (world->player[player_ID]).buildings_count[player_buildings_NODE]--;
      (world->player[player_ID]).resurce_count-=resurce_NODE_PRICE ;
      action=action_BUILD_NODE_URR ;
      mouse->x_frame=building_type_BUILDPLACE ;
      element->SetFrameY(emtNodeSetDirection_FRAME_Y+1);
    };
};
void OnNodeSetDirectionUR_click (s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_NODE]>0)//проверка на наличие прототипа здания
    if((world->player[player_ID]).resurce_count>=resurce_NODE_PRICE)//проверка на наличие ресурсов у игрока для постройки
    {
      (world->player[player_ID]).buildings_count[player_buildings_NODE]--;
      (world->player[player_ID]).resurce_count-=resurce_NODE_PRICE ;
      action=action_BUILD_NODE_UR ;
      mouse->x_frame=building_type_BUILDPLACE ;
      element->SetFrameY(emtNodeSetDirection_FRAME_Y+1);
    };
};
void OnNodeSetDirectionUUR_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  if((world->player[player_ID]).buildings_count[player_buildings_NODE]>0)//проверка на наличие прототипа здания
    if((world->player[player_ID]).resurce_count>=resurce_NODE_PRICE)//проверка на наличие ресурсов у игрока для постройки
    {
      (world->player[player_ID]).buildings_count[player_buildings_NODE]--;
      (world->player[player_ID]).resurce_count-=resurce_NODE_PRICE ;
      action=action_BUILD_NODE_UUR ;
      mouse->x_frame=building_type_BUILDPLACE ;
      element->SetFrameY(emtNodeSetDirection_FRAME_Y+1);
    };
};
//---------------------------------------------------------------------------
void OnBuildNext_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  action=action_BUILD_NEXT ;
  element->SetFrameY(emtBuildNext_FRAME_Y+1) ;
} ;
void OnBuildPrev_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  action=action_BUILD_PREV ;
  element->SetFrameY(emtBuildPrev_FRAME_Y+1) ;
} ;
//---------------------------------------------------------------------------
void OnBuildNode_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{/*MUST BE DUMMY*/} ;
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
  if(element->GetFrameY()==emtShowTerritory_FRAME_Y)
    element->SetFrameY(emtShowTerritory_FRAME_Y+1) ;
  else
    element->SetFrameY(emtShowTerritory_FRAME_Y) ;
  //... перерасчет территорий игрока
} ;
//---------------------------------------------------------------------------
void OnBuildingEnable_click(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)
{
  action = action_BUILDING_ENABLE ;
} ;
//---------------------------------------------------------------------------
#endif
