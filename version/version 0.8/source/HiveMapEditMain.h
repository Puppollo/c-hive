#ifndef HiveMpaEditMainH
#define HiveMapEditMainH
//---------------------------------------------------------------------------
#include "HiveMain.h"
#include "c_HiveWorld.h"
//---------------------------------------------------------------------------
const int font_EditInfo_X = 26 ;
const int font_EditInfo_Y = 40 ;
//---------------------------------------------------------------------------
struct s_EditInfo
{
  int current_player ;
  int current_building_type ;
} ;
//---------------------------------------------------------------------------
void CheckAction(s_mouse mouse,s_EditInfo EditInfo,c_World *world) ;
//---------------------------------------------------------------------------
void CheckAction(s_mouse mouse,s_EditInfo EditInfo,c_World *world)
{
  if(mouse.button==mouse_LEFT)
    if(mouse.cell_x>0 && mouse.cell_x<world_X_COUNT-1 && mouse.cell_y>0 && mouse.cell_y<world_Y_COUNT-1)
       world->SetLandscapePoint(mouse.cell_x,mouse.cell_y,1) ;
  else
  if(mouse.button==mouse_RIGHT)
    if(mouse.cell_x>0 && mouse.cell_x<world_X_COUNT-1 && mouse.cell_y>0 && mouse.cell_y<world_Y_COUNT-1)
       world->SetLandscapePoint(mouse.cell_x,mouse.cell_y,0) ;
} ;
//---------------------------------------------------------------------------
#endif
