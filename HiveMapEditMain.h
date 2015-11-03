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
    int UL = world->building[mouse.cell_x-1][mouse.cell_y-1].terrain.h,
        U  = world->building[mouse.cell_x  ][mouse.cell_y-1].terrain.h,
        UR = world->building[mouse.cell_x+1][mouse.cell_y-1].terrain.h,
        L  = world->building[mouse.cell_x-1][mouse.cell_y  ].terrain.h,
        C  = world->building[mouse.cell_x  ][mouse.cell_y  ].terrain.h,
        R  = world->building[mouse.cell_x+1][mouse.cell_y  ].terrain.h,
        DL = world->building[mouse.cell_x-1][mouse.cell_y+1].terrain.h,
        D  = world->building[mouse.cell_x  ][mouse.cell_y+1].terrain.h,
        DR = world->building[mouse.cell_x+1][mouse.cell_y+1].terrain.h;
    int ULt = world->building[mouse.cell_x-1][mouse.cell_y-1].terrain.type,
        Ut  = world->building[mouse.cell_x  ][mouse.cell_y-1].terrain.type,
        URt = world->building[mouse.cell_x+1][mouse.cell_y-1].terrain.type,
        Lt  = world->building[mouse.cell_x-1][mouse.cell_y  ].terrain.type,
        Ct  = world->building[mouse.cell_x  ][mouse.cell_y  ].terrain.type,
        Rt  = world->building[mouse.cell_x+1][mouse.cell_y  ].terrain.type,
        DLt = world->building[mouse.cell_x-1][mouse.cell_y+1].terrain.type,
        Dt  = world->building[mouse.cell_x  ][mouse.cell_y+1].terrain.type,
        DRt = world->building[mouse.cell_x+1][mouse.cell_y+1].terrain.type;
    switch(mouse.button)
    {
      case mouse_LEFT :
        if(H<terrain_H_COUNT &&
           UL>=H && U>=H && UR>=H &&
           L >=H && C>=H && R >=H &&
           DL>=H && D>=H && DR>=H 
           /*ULt==terrain_type_FULL_CLEAR_U && Ut==terrain_type_FULL_CLEAR_U && URt==terrain_type_FULL_CLEAR_U &&
            Lt==terrain_type_FULL_CLEAR_U && Ct==terrain_type_FULL_CLEAR_U &&  Rt==terrain_type_FULL_CLEAR_U &&
           DLt==terrain_type_FULL_CLEAR_U && Dt==terrain_type_FULL_CLEAR_U && DRt==terrain_type_FULL_CLEAR_U*/ )
        {
          world->SetLandscapePoint(mouse.cell_x,mouse.cell_y,H+1) ;
          SelectFrame(world->building,world->landscape) ;
        }
        else
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
