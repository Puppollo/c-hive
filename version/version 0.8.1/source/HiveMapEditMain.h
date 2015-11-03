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
  int H=(world->building[mouse.cell_x][mouse.cell_y]).terrain.h;
  if(mouse.cell_x>0 && mouse.cell_x<world_X_COUNT-1 && mouse.cell_y>0 && mouse.cell_y<world_Y_COUNT-1)
  {
    int UL = world->landscape[mouse.cell_x-1][mouse.cell_y-1],
        U  = world->landscape[mouse.cell_x  ][mouse.cell_y-1],
        UR = world->landscape[mouse.cell_x+1][mouse.cell_y-1],
        L  = world->landscape[mouse.cell_x-1][mouse.cell_y  ],
        C  = world->landscape[mouse.cell_x  ][mouse.cell_y  ],
        R  = world->landscape[mouse.cell_x+1][mouse.cell_y  ],
        DL = world->landscape[mouse.cell_x-1][mouse.cell_y+1],
        D  = world->landscape[mouse.cell_x  ][mouse.cell_y+1],
        DR = world->landscape[mouse.cell_x+1][mouse.cell_y+1];
    switch(mouse.button)
    {
      case mouse_LEFT :
        /*if(H<terrain_H_COUNT &&
           UL==H && U==H && UR==H &&
           L ==H && C==H && R ==H &&
           DL==H && D==H && DR==H )
        {
          world->SetLandscapePoint(mouse.cell_x,mouse.cell_y,H+1) ;
          SelectFrame(world->building,world->landscape) ;
        }
        else*/
          world->SetLandscapePoint(mouse.cell_x,mouse.cell_y,1) ;
      break;
      case mouse_RIGHT :
        if(H>0)
          world->SetLandscapePoint(mouse.cell_x,mouse.cell_y,H-1) ;
      break;
    } ;
  };
} ;
//---------------------------------------------------------------------------
#endif
