#ifndef HiveTerrainH
#define HiveTerrainH
#include "HiveMain.h"
//---------------------------------------------------------------------------
const int sprite_TERRAIN_X_FRAME_COUNT    =12;
const int sprite_TERRAIN_Y_FRAME_COUNT    = 4 ;

const int terrain_type_FULL_CLEAR_U       = 0 ;
const int terrain_type_FULL_TUBE_U        = 1 ;
const int terrain_type_FULL_CLEAR_D       = 2  ;
const int terrain_type_1_CROSS            = 3  ;
const int terrain_type_2_CROSS            = 4  ;
const int terrain_type_LUR_TUBE_U         = 5 ;
const int terrain_type_URD_TUBE_U         = 6  ;
const int terrain_type_LDR_TUBE_U         = 7  ;
const int terrain_type_LUD_TUBE_U         = 8  ;
const int terrain_type_LU_TUBE_U          = 9  ;
const int terrain_type_UR_TUBE_U          = 10 ;
const int terrain_type_DR_TUBE_U          = 11 ;
const int terrain_type_LD_TUBE_U          = 12 ;
const int terrain_type_LR_TUBE_U          = 13 ;
const int terrain_type_UD_TUBE_U          = 14 ;
const int terrain_type_L_CLEAR_U          = 15;
const int terrain_type_R_CLEAR_U          = 16;
const int terrain_type_D_CLEAR_U          = 17;
const int terrain_type_U_CLEAR_U          = 18;
const int terrain_type_LD_CLEAR_U         = 19;
const int terrain_type_LU_CLEAR_U         = 20;
const int terrain_type_UR_CLEAR_U         = 21;
const int terrain_type_DR_CLEAR_U         = 22;
const int terrain_type_U_TUBE_LD_CLEAR_U  = 23 ;
const int terrain_type_U_TUBE_DR_CLEAR_U  = 24 ;
const int terrain_type_D_TUBE_RD_CLEAR_U  = 25 ;
const int terrain_type_D_TUBE_UL_CLEAR_U  = 26 ;
const int terrain_type_R_TUBE_LU_CLEAR_U  = 27 ;
const int terrain_type_L_TUBE_UR_CLEAR_U  = 28 ;
const int terrain_type_R_TUBE_LD_CLEAR_U  = 29 ;
const int terrain_type_L_TUBE_DR_CLEAR_U  = 30 ;
const int terrain_type_UR_TUBE_LD_CLEAR_U = 31 ;
const int terrain_type_LU_TUBE_DR_CLEAR_U = 32 ;
const int terrain_type_DR_TUBE_LU_CLEAR_U = 33 ;
const int terrain_type_LD_TUBE_UR_CLEAR_U = 34 ;
const int terrain_type_SINGLE_U           = 35 ;
const int terrain_type_LU_CLEAR_D         = 36 ;
const int terrain_type_RU_CLEAR_D         = 37 ;
const int terrain_type_LD_CLEAR_D         = 38 ;
const int terrain_type_RD_CLEAR_D         = 39 ;
const int terrain_type_L_TUBE_U           = 40 ;
const int terrain_type_R_TUBE_U           = 41 ;
const int terrain_type_U_TUBE_U           = 42 ;
const int terrain_type_D_TUBE_U           = 43 ;
const int terrain_type_L_TUBE_R_CLEAR_U   = 44 ;
const int terrain_type_R_TUBE_L_CLEAR_U   = 45 ;
const int terrain_type_U_TUBE_D_CLEAR_U   = 46 ;
const int terrain_type_D_TUBE_U_CLEAR_U   = 47 ;

const int terrain_type_FULL_CLEAR_U_FRAME_X      = 0 ;
const int terrain_type_FULL_CLEAR_U_FRAME_Y      = 0 ;
const int terrain_type_FULL_TUBE_U_FRAME_X       = 0 ;
const int terrain_type_FULL_TUBE_U_FRAME_Y       = 2 ;
const int terrain_type_LUR_TUBE_U_FRAME_X        = 4 ;
const int terrain_type_LUR_TUBE_U_FRAME_Y        = 0 ;
const int terrain_type_URD_TUBE_U_FRAME_X        = 4  ;
const int terrain_type_URD_TUBE_U_FRAME_Y        = 1  ;
const int terrain_type_LDR_TUBE_U_FRAME_X        = 4  ;
const int terrain_type_LDR_TUBE_U_FRAME_Y        = 2  ;
const int terrain_type_LUD_TUBE_U_FRAME_X        = 4  ;
const int terrain_type_LUD_TUBE_U_FRAME_Y        = 3  ;
const int terrain_type_LU_TUBE_U_FRAME_X         = 5  ;
const int terrain_type_LU_TUBE_U_FRAME_Y         = 1  ;
const int terrain_type_UR_TUBE_U_FRAME_X         = 5  ;
const int terrain_type_UR_TUBE_U_FRAME_Y         = 0  ;
const int terrain_type_DR_TUBE_U_FRAME_X         = 5  ;
const int terrain_type_DR_TUBE_U_FRAME_Y         = 2  ;
const int terrain_type_LD_TUBE_U_FRAME_X         = 5  ;
const int terrain_type_LD_TUBE_U_FRAME_Y         = 3  ;
const int terrain_type_LR_TUBE_U_FRAME_X         = 9  ;
const int terrain_type_LR_TUBE_U_FRAME_Y         = 1  ;
const int terrain_type_UD_TUBE_U_FRAME_X         = 9  ;
const int terrain_type_UD_TUBE_U_FRAME_Y         = 0  ;
const int terrain_type_L_CLEAR_U_FRAME_X         = 1 ;
const int terrain_type_L_CLEAR_U_FRAME_Y         = 1 ;
const int terrain_type_R_CLEAR_U_FRAME_X         = 1 ;
const int terrain_type_R_CLEAR_U_FRAME_Y         = 0 ;
const int terrain_type_D_CLEAR_U_FRAME_X         = 1 ;
const int terrain_type_D_CLEAR_U_FRAME_Y         = 3 ;
const int terrain_type_U_CLEAR_U_FRAME_X         = 1 ;
const int terrain_type_U_CLEAR_U_FRAME_Y         = 2 ;
const int terrain_type_LD_CLEAR_U_FRAME_X        = 2 ;
const int terrain_type_LD_CLEAR_U_FRAME_Y        = 3 ;
const int terrain_type_LU_CLEAR_U_FRAME_X        = 2 ;
const int terrain_type_LU_CLEAR_U_FRAME_Y        = 2 ;
const int terrain_type_UR_CLEAR_U_FRAME_X        = 2 ;
const int terrain_type_UR_CLEAR_U_FRAME_Y        = 0 ;
const int terrain_type_DR_CLEAR_U_FRAME_X        = 2 ;
const int terrain_type_DR_CLEAR_U_FRAME_Y        = 1 ;
const int terrain_type_U_TUBE_LD_CLEAR_U_FRAME_X = 6  ;
const int terrain_type_U_TUBE_LD_CLEAR_U_FRAME_Y = 3  ;
const int terrain_type_U_TUBE_DR_CLEAR_U_FRAME_X = 6  ;
const int terrain_type_U_TUBE_DR_CLEAR_U_FRAME_Y = 1  ;
const int terrain_type_D_TUBE_RD_CLEAR_U_FRAME_X = 6  ;
const int terrain_type_D_TUBE_RD_CLEAR_U_FRAME_Y = 2  ;
const int terrain_type_D_TUBE_UL_CLEAR_U_FRAME_X = 6  ;
const int terrain_type_D_TUBE_UL_CLEAR_U_FRAME_Y = 0  ;
const int terrain_type_R_TUBE_LU_CLEAR_U_FRAME_X = 7  ;
const int terrain_type_R_TUBE_LU_CLEAR_U_FRAME_Y = 1  ;
const int terrain_type_L_TUBE_UR_CLEAR_U_FRAME_X = 7  ;
const int terrain_type_L_TUBE_UR_CLEAR_U_FRAME_Y = 3  ;
const int terrain_type_R_TUBE_LD_CLEAR_U_FRAME_X = 7  ;
const int terrain_type_R_TUBE_LD_CLEAR_U_FRAME_Y = 0  ;
const int terrain_type_L_TUBE_DR_CLEAR_U_FRAME_X = 7  ;
const int terrain_type_L_TUBE_DR_CLEAR_U_FRAME_Y = 2  ;
const int terrain_type_UR_TUBE_LD_CLEAR_U_FRAME_X= 8  ;
const int terrain_type_UR_TUBE_LD_CLEAR_U_FRAME_Y= 3  ;
const int terrain_type_LU_TUBE_DR_CLEAR_U_FRAME_X= 8  ;
const int terrain_type_LU_TUBE_DR_CLEAR_U_FRAME_Y= 1  ;
const int terrain_type_DR_TUBE_LU_CLEAR_U_FRAME_X= 8  ;
const int terrain_type_DR_TUBE_LU_CLEAR_U_FRAME_Y= 2  ;
const int terrain_type_LD_TUBE_UR_CLEAR_U_FRAME_X= 8  ;
const int terrain_type_LD_TUBE_UR_CLEAR_U_FRAME_Y= 0  ;
const int terrain_type_SINGLE_U_FRAME_X          = 0  ;
const int terrain_type_SINGLE_U_FRAME_Y          = 3  ;
const int terrain_type_LU_CLEAR_D_FRAME_X        = 3  ;
const int terrain_type_LU_CLEAR_D_FRAME_Y        = 0 ;
const int terrain_type_RU_CLEAR_D_FRAME_X        = 3  ;
const int terrain_type_RU_CLEAR_D_FRAME_Y        = 2 ;
const int terrain_type_LD_CLEAR_D_FRAME_X        = 3  ;
const int terrain_type_LD_CLEAR_D_FRAME_Y        = 1 ;
const int terrain_type_RD_CLEAR_D_FRAME_X        = 3  ;
const int terrain_type_RD_CLEAR_D_FRAME_Y        = 3 ;
const int terrain_type_1_CROSS_FRAME_X           = 9  ;
const int terrain_type_1_CROSS_FRAME_Y           = 2 ;
const int terrain_type_2_CROSS_FRAME_X           = 9  ;
const int terrain_type_2_CROSS_FRAME_Y           = 3 ;
const int terrain_type_FULL_CLEAR_D_FRAME_X      = 0 ;
const int terrain_type_FULL_CLEAR_D_FRAME_Y      = 1 ;
const int terrain_type_L_TUBE_U_FRAME_X          = 10 ;
const int terrain_type_L_TUBE_U_FRAME_Y          = 2 ;
const int terrain_type_R_TUBE_U_FRAME_X          = 10 ;
const int terrain_type_R_TUBE_U_FRAME_Y          = 3 ;
const int terrain_type_U_TUBE_U_FRAME_X          = 10 ;
const int terrain_type_U_TUBE_U_FRAME_Y          = 1 ;
const int terrain_type_D_TUBE_U_FRAME_X          = 10 ;
const int terrain_type_D_TUBE_U_FRAME_Y          = 0 ;
const int terrain_type_L_TUBE_R_CLEAR_U_FRAME_X   = 11 ;
const int terrain_type_L_TUBE_R_CLEAR_U_FRAME_Y   = 1 ;
const int terrain_type_R_TUBE_L_CLEAR_U_FRAME_X   = 11 ;
const int terrain_type_R_TUBE_L_CLEAR_U_FRAME_Y   = 3 ;
const int terrain_type_U_TUBE_D_CLEAR_U_FRAME_X   = 11 ;
const int terrain_type_U_TUBE_D_CLEAR_U_FRAME_Y   = 2 ;
const int terrain_type_D_TUBE_U_CLEAR_U_FRAME_X   = 11 ;
const int terrain_type_D_TUBE_U_CLEAR_U_FRAME_Y   = 0 ;
//---------------------------------------------------------------------------
void GenLandscape    (int landscape[world_X_COUNT][world_Y_COUNT]) ;  // сгенерировать ландшафт
void GenMineral      (s_building building[world_X_COUNT][world_Y_COUNT]) ; // сгенерировать минералы
void MineralExtend   (s_building building[world_X_COUNT][world_Y_COUNT]) ; // расширение минеральных жил
void SelectFrame     (s_building building[world_X_COUNT][world_Y_COUNT],int landscape[world_X_COUNT][world_Y_COUNT]) ; // выбрать соответсвующий кадр для клетки ландшафта
//void SelectFrameSinge(s_building building[world_X_COUNT][world_Y_COUNT],int landscape[world_X_COUNT][world_Y_COUNT],int x,int y) ; in recycling
//---------------------------------------------------------------------------
void GenLandscape(int landscape[world_X_COUNT][world_Y_COUNT])
{
  for(int x=0;x<world_X_COUNT;x++)
    for(int y=0;y<world_Y_COUNT;y++)
      if(x==0 || y==0 || x==world_X_COUNT-1 || y==world_Y_COUNT-1)
        landscape[x][y]=0 ;
      else
      {
        int r = random(100) ;
        if(r<terrain_LANDSCAPE_RANDOM)landscape[x][y]=0;
        else                          landscape[x][y]=1 ;
      } ;
} ;
//---------------------------------------------------------------------------
void SelectFrame(s_building building[world_X_COUNT][world_Y_COUNT],int landscape[world_X_COUNT][world_Y_COUNT])
{
  //  int H=1;
  for(int H=1;H<=terrain_H_COUNT;H++)
  {
    int h=H-1;
    for(int x=1;x<world_X_COUNT-1;x++)
      for(int y=1;y<world_Y_COUNT-1;y++)
      {
        int UL = landscape[x-1][y-1],
            U  = landscape[x  ][y-1],
            UR = landscape[x+1][y-1],
            L  = landscape[x-1][y  ],
            C  = landscape[x  ][y  ],
            R  = landscape[x+1][y  ],
            DL = landscape[x-1][y+1],
            D  = landscape[x  ][y+1],
            DR = landscape[x+1][y+1];
        if( UL==H && U==H && UR==H &&
            L ==H && C==H && R ==H &&
            DL==H && D==H && DR==H )   // full clear u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_FULL_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_FULL_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_FULL_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( /*-*/    U==h && /*-*/
            L ==H && C==H && R ==h &&
            DL==H && D==H    /*-*/ )   // ld clear u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_LD_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_LD_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_LD_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==H  && U==H && /*-*/
            L ==H  && C==H && R ==h &&
            /*-*/     D==h    /*-*/ )   // lu clear u
        {
 //         building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_LU_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_LU_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_LU_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( /*-*/    U==h && /*-*/
            L ==h && C==H && R ==H &&
            /*-*/    D==H && DR==H )   // rd clear u
        {
 //         building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_DR_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_DR_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_DR_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( /*-*/    U==H && UR==H &&
            L ==h && C==H && R ==H &&
            /*-*/    D==h    /*-*/ )   // ru clear u
        {
 //         building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_UR_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_UR_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_UR_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==H && U==H && /*-*/
            L ==H && C==H && R ==h &&
            DL==H && D==H    /*-*/ )   // l clear u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_L_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_L_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_L_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( /*-*/    U==H && UR==H &&
            L ==h && C==H && R ==H &&
            /*-*/    D==H && DR==H )   // r clear u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_R_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_R_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_R_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==H && U==H && UR==H &&
            L ==H && C==H && R ==H &&
            /*-*/    D==h    /*-*/ )   // u clear u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_U_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_U_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_U_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( /*-*/    U==h && /*-*/
            L ==H && C==H && R ==H &&
            DL==H && D==H && DR==H )   // d clear u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_D_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_D_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_D_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==H && U==H && UR==H &&
            L ==H && C==H && R ==H &&
            DL==H && D==H && DR==h )   // lu clear d
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_LU_CLEAR_D ;
          building[x][y].terrain.x_frame = terrain_type_LU_CLEAR_D_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_LU_CLEAR_D_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==H && U==H && UR==h &&
            L ==H && C==H && R ==H &&
            DL==H && D==H && DR==H )   // ld clear d
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_LD_CLEAR_D ;
          building[x][y].terrain.x_frame = terrain_type_LD_CLEAR_D_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_LD_CLEAR_D_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==H && U==H && UR==H &&
            L ==H && C==H && R ==H &&
            DL==h && D==H && DR==H )   // ru clear d
        {
 //         building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_RU_CLEAR_D ;
          building[x][y].terrain.x_frame = terrain_type_RU_CLEAR_D_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_RU_CLEAR_D_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==h && U==H && UR==H &&
            L ==H && C==H && R ==H &&
            DL==H && D==H && DR==H )   // rd clear d
        {
 //         building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_RD_CLEAR_D ;
          building[x][y].terrain.x_frame = terrain_type_RD_CLEAR_D_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_RD_CLEAR_D_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==h && U==H && UR==H &&
            L ==H && C==H && R ==H &&
            DL==h && D==H && DR==H )   // l tube r clear u
        {
 //         building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_L_TUBE_R_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_L_TUBE_R_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_L_TUBE_R_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==h && U==H && UR==h &&
            L ==H && C==H && R ==H &&
            DL==H && D==H && DR==H )   // u tube d clear u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_U_TUBE_D_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_U_TUBE_D_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_U_TUBE_D_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==H && U==H && UR==h &&
            L ==H && C==H && R ==H &&
            DL==H && D==H && DR==h )   // r tube l clear
        {
 //         building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_R_TUBE_L_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_R_TUBE_L_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_R_TUBE_L_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==H && U==H && UR==H &&
            L ==H && C==H && R ==H &&
            DL==h && D==H && DR==h )   // d tube u clear u
        {
 //         building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_D_TUBE_U_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_D_TUBE_U_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_D_TUBE_U_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( /*-*/    U==h && /*-*/
            L ==h && C==H && R ==h &&
            /*-*/    D==h    /*-*/ )   // single
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_SINGLE_U ;
          building[x][y].terrain.x_frame = terrain_type_SINGLE_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_SINGLE_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==h && U==H && UR==h &&
            L ==H && C==H && R ==H &&
            DL==h && D==H && DR==h )   // full tube u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_FULL_TUBE_U ;
          building[x][y].terrain.x_frame = terrain_type_FULL_TUBE_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_FULL_TUBE_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( /*-*/    U==H && UR==h &&
            L ==h && C==H && R ==H &&
            /*-*/    D==H && DR==h )   // urd tube u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_URD_TUBE_U ;
          building[x][y].terrain.x_frame = terrain_type_URD_TUBE_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_URD_TUBE_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==h && U==H && UR==h &&
            L ==H && C==H && R ==H &&
            /*-*/    D==h    /*-*/ )   // lur tube u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_LUR_TUBE_U ;
          building[x][y].terrain.x_frame = terrain_type_LUR_TUBE_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_LUR_TUBE_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==h && U==H && /*-*/
            L ==H && C==H && R ==h &&
            DL==h && D==H    /*-*/ )   // lud tube u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_LUD_TUBE_U ;
          building[x][y].terrain.x_frame = terrain_type_LUD_TUBE_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_LUD_TUBE_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( /*-*/    U==h && /*-*/
            L ==H && C==H && R ==H &&
            DL==h && D==H && DR==h )   // ldr tube u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_LDR_TUBE_U ;
          building[x][y].terrain.x_frame = terrain_type_LDR_TUBE_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_LDR_TUBE_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( /*-*/    U==H && /*-*/
            L ==h && C==H && R ==h &&
            /*--*/   D==h    /*-*/ )   // u tube u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_U_TUBE_U ;
          building[x][y].terrain.x_frame = terrain_type_U_TUBE_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_U_TUBE_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( /*-*/    U==h && /*-*/
            L ==h && C==H && R ==h &&
            /*-*/    D==H    /*-*/ )   // d tube u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_D_TUBE_U ;
          building[x][y].terrain.x_frame = terrain_type_D_TUBE_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_D_TUBE_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( /*-*/    U==h && /*-*/
            L ==H && C==H && R ==h &&
            /*-*/    D==h    /*-*/ )   // l tube u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_L_TUBE_U ;
          building[x][y].terrain.x_frame = terrain_type_L_TUBE_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_L_TUBE_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( /*-*/    U==h && /*-*/
            L ==h && C==H && R ==H &&
            /*-*/    D==h    /*-*/ )   // r tube u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_R_TUBE_U ;
          building[x][y].terrain.x_frame = terrain_type_R_TUBE_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_R_TUBE_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( /*-*/    U==h && /*-*/
            L ==H && C==H && R ==h &&
            DL==h && D==H    /*-*/ )   // ld tube u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_LD_TUBE_U ;
          building[x][y].terrain.x_frame = terrain_type_LD_TUBE_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_LD_TUBE_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==h && U==H && /*-*/
            L ==H && C==H && R ==h &&
            /*-*/    D==h    /*-*/ )   // lu tube u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_LU_TUBE_U ;
          building[x][y].terrain.x_frame = terrain_type_LU_TUBE_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_LU_TUBE_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( /*-*/    U==h && /*-*/
            L ==h && C==H && R ==H &&
            /*-*/    D==H && DR==h )   // rd tube u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_DR_TUBE_U ;
          building[x][y].terrain.x_frame = terrain_type_DR_TUBE_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_DR_TUBE_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( /*-*/    U==H && UR==h &&
            L ==h && C==H && R ==H &&
            /*-*/    D==h    /*-*/ )   // ru tube u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_UR_TUBE_U ;
          building[x][y].terrain.x_frame = terrain_type_UR_TUBE_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_UR_TUBE_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( /*-*/    U==h && /*-*/
            L ==H && C==H && R ==H &&
            /*-*/    D==h    /*-*/ )   // lr tube u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_LR_TUBE_U ;
          building[x][y].terrain.x_frame = terrain_type_LR_TUBE_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_LR_TUBE_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( /*-*/    U==H && /*-*/
            L ==h && C==H && R ==h &&
            /*-*/    D==H    /*-*/ )   //  ud tube u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_UD_TUBE_U ;
          building[x][y].terrain.x_frame = terrain_type_UD_TUBE_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_UD_TUBE_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==h && U==H && /*-*/
            L ==H && C==H && R ==h &&
            DL==H && D==H    /*-*/ )   // u tube ld clear u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_U_TUBE_LD_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_U_TUBE_LD_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_U_TUBE_LD_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( /*-*/    U==H && UR==h &&
            L ==h && C==H && R ==H &&
            /*-*/    D==H && DR==H )   // u tube dr clear u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_U_TUBE_DR_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_U_TUBE_DR_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_U_TUBE_DR_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==H && U==H && /*-*/
            L ==H && C==H && R ==h &&
            DL==h && D==H    /*-*/ )   // d tube rd clear u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_D_TUBE_RD_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_D_TUBE_RD_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_D_TUBE_RD_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( /*-*/    U==H && UR==H &&
            L ==h && C==H && R ==H &&
            /*-*/    D==H && DR==h )   // d tube ul clear u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_D_TUBE_UL_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_D_TUBE_UL_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_D_TUBE_UL_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==H && U==H && UR==h &&
            L ==H && C==H && R ==H &&
            /*-*/    D==h    /*-*/ )   // r tube lu clear u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_R_TUBE_LU_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_R_TUBE_LU_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_R_TUBE_LU_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==h && U==H && UR==H &&
            L ==H && C==H && R ==H &&
            /*-*/    D==h    /*-*/ )   // l tube ur clear
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_L_TUBE_UR_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_L_TUBE_UR_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_L_TUBE_UR_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( /*-*/    U==h && /*-*/
            L ==H && C==H && R ==H &&
            DL==H && D==H && DR==h )   // r tube ld clear u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_R_TUBE_LD_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_R_TUBE_LD_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_R_TUBE_LD_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( /*-*/    U==h && /*-*/
            L ==H && C==H && R ==H &&
            DL==h && D==H && DR==H )   // l tube dr clear u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_L_TUBE_DR_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_L_TUBE_DR_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_L_TUBE_DR_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==h && U==H && UR==h &&
            L ==H && C==H && R ==H &&
            DL==H && D==H && DR==h )   // ur tube ld clear u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_UR_TUBE_LD_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_UR_TUBE_LD_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_UR_TUBE_LD_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==h && U==H && UR==h &&
            L ==H && C==H && R ==H &&
            DL==h && D==H && DR==H )   // lu tube dr clear u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_LU_TUBE_DR_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_LU_TUBE_DR_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_LU_TUBE_DR_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==H && U==H && UR==h &&
            L ==H && C==H && R ==H &&
            DL==h && D==H && DR==h )   // dr tube lu clear u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_DR_TUBE_LU_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_DR_TUBE_LU_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_DR_TUBE_LU_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==h && U==H && UR==H &&
            L ==H && C==H && R ==H &&
            DL==h && D==H && DR==h )   // ld tube ur clear u
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_LD_TUBE_UR_CLEAR_U ;
          building[x][y].terrain.x_frame = terrain_type_LD_TUBE_UR_CLEAR_U_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_LD_TUBE_UR_CLEAR_U_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==h && U==H && UR==H &&
            L ==H && C==H && R ==H &&
            DL==H && D==H && DR==h )   // 1 cross
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_1_CROSS ;
          building[x][y].terrain.x_frame = terrain_type_1_CROSS_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_1_CROSS_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( UL==H && U==H && UR==h &&
            L ==H && C==H && R ==H &&
            DL==h && D==H && DR==H )   // 2 cross
        {
//          building[x][y].terrain.h = H ;
          building[x][y].terrain.type = terrain_type_2_CROSS ;
          building[x][y].terrain.x_frame = terrain_type_2_CROSS_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_2_CROSS_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        }
        else
        if( H<=1/* && ( U==H || L ==H || R==H || D==H )*/&&(C==h))
        {
//          building[x][y].terrain.h = h ;
          building[x][y].terrain.type = terrain_type_FULL_CLEAR_D ;
          building[x][y].terrain.x_frame = terrain_type_FULL_CLEAR_D_FRAME_X ;
          building[x][y].terrain.y_frame = terrain_type_FULL_CLEAR_D_FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
        } ;
        //...
      /*TEMP else
      if( UL==H && U==H && UR==H &&
          L ==H && C==H && R ==H &&
          DL==H && D==H && DR==H )   //
      {
        building[x][y].terrain.type = terrain_type_ ;
        building[x][y].terrain.x_frame = terrain_type__FRAME_X ;
        building[x][y].terrain.y_frame = terrain_type__FRAME_Y+(h*sprite_TERRAIN_Y_FRAME_COUNT) ;
      }*/
    } ;
  } ;
} ;
//---------------------------------------------------------------------------
// void SelectFrameSingle(...) ...
//---------------------------------------------------------------------------
void GenMineral(s_building building[world_X_COUNT][world_Y_COUNT])
{
  FILE *f=fopen("LOG\\GenMineral.log","w+") ;
  for(int x=0;x<world_X_COUNT;x++)
    for(int y=0;y<world_Y_COUNT;y++)
    {
      fprintf(f,"(%d;%d).terrain.type=%d\n",x,y,building[x][y].terrain.type) ;
      if(building[x][y].terrain.type==terrain_type_FULL_CLEAR_U)
      {
        int mr = random(100) ;
        if(mr<world_MINERAL_RANDOM)
        {
          fprintf(f,"set mineral\n") ;
          building[x][y].type=building_type_MINERAL ;
          building[x][y].maxHP = building_MINERAL_HP ;
          building[x][y].HP = building_MINERAL_HP ;
          building[x][y].param[0] = world_MINERAL_PARAM+random((world_MINERAL_PARAM_VARIATION<<1)+1)-world_MINERAL_PARAM_VARIATION ;
        };
      } ;
    };
  fclose(f);
} ;
//---------------------------------------------------------------------------
void MineralExtend(s_building building[world_X_COUNT][world_Y_COUNT])
{
  // расширение минеральных жил
  for(int x=0;x<world_X_COUNT;x++)
    for(int y=0;y<world_Y_COUNT;y++)
      if(building[x][y].type==building_type_MINERAL)
      {
        if(x>0 && building[x-1][y].terrain.type==terrain_type_FULL_CLEAR_U)
        {
          int r=random(100) ;
          if(r<world_MINERAL_IN_RANDOM)
          {
            if((building[x-1][y].type!=building_type_MAIN) && (building[x-1][y].type!=building_type_MAIN))
            {
              if(building[x-1][y].type!=building_type_NO)
              {
                building[x-1][y].type=building_type_BLOW;
                building[x-1][y].y_frame=0;
              }
              else
              {
                building[x-1][y].type=building_type_MINERAL ;
                building[x-1][y].maxHP = building_MINERAL_HP ;
                building[x-1][y].HP = building_MINERAL_HP ;
                building[x-1][y].param[0] = world_MINERAL_PARAM+random((world_MINERAL_PARAM_VARIATION<<1)+1)-world_MINERAL_PARAM_VARIATION ;
                continue;
              };
            };
          };
        };
        if(x<world_X_COUNT-1 && building[x+1][y].terrain.type==terrain_type_FULL_CLEAR_U)
        {
          int r=random(100) ;
          if(r<world_MINERAL_IN_RANDOM)
          {
            if(building[x+1][y].type!=building_type_MAIN && building[x+1][y].type!=building_type_MAIN)
            {
              if(building[x+1][y].type!=building_type_NO)
              {
                building[x+1][y].type=building_type_BLOW;
                building[x+1][y].y_frame=0;
              }
              else
              {
                building[x+1][y].type=building_type_MINERAL ;
                building[x+1][y].maxHP = building_MINERAL_HP ;
                building[x+1][y].HP = building_MINERAL_HP ;
                building[x+1][y].param[0] = world_MINERAL_PARAM+random((world_MINERAL_PARAM_VARIATION<<1)+1)-world_MINERAL_PARAM_VARIATION ;
                continue;
              };
            };
          };
        };
        if(y>0 && building[x][y-1].terrain.type==terrain_type_FULL_CLEAR_U)
        {
          int r=random(100) ;
          if(building[x][y-1].type!=building_type_MAIN && building[x][y-1].type!=building_type_MAIN)
          {
            if(r<world_MINERAL_IN_RANDOM)
            {
              if(building[x][y-1].type!=building_type_NO)
              {
                building[x][y-1].type=building_type_BLOW;
                building[x][y-1].y_frame=0;
              }
              else
              {
                building[x][y-1].type=building_type_MINERAL ;
                building[x][y-1].maxHP = building_MINERAL_HP ;
                building[x][y-1].HP = building_MINERAL_HP ;
                building[x][y-1].param[0] = world_MINERAL_PARAM+random((world_MINERAL_PARAM_VARIATION<<1)+1)-world_MINERAL_PARAM_VARIATION ;
                continue;
              } ;
            };
          };
        };
        if(y<world_Y_COUNT-1 && building[x][y+1].terrain.type==terrain_type_FULL_CLEAR_U)
        {
          int r=random(100) ;
          if(building[x][y+1].type!=building_type_MAIN && building[x][y+1].type!=building_type_MAIN)
          {
            if(r<world_MINERAL_IN_RANDOM)
            {
              if(building[x][y+1].type!=building_type_NO)
              {
                building[x][y+1].type=building_type_BLOW;
                building[x][y+1].y_frame=0;
              }
              else
              {
                building[x][y+1].type=building_type_MINERAL ;
                building[x][y+1].maxHP = building_MINERAL_HP ;
                building[x][y+1].HP = building_MINERAL_HP ;
                building[x][y+1].param[0] = world_MINERAL_PARAM+random((world_MINERAL_PARAM_VARIATION<<1)+1)-world_MINERAL_PARAM_VARIATION ;
                continue;
              };
            };
          };
        };
      } ;
} ;
//---------------------------------------------------------------------------
#endif