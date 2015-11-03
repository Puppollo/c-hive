//---------------------------------------------------------------------------
#ifndef c_grObjectH
#define c_grObjectH
#include <stdio.h>
#include <ddraw.h>
#include "c_sprite.h"
//---------------------------------------------------------------------------
//###########################################################################
class c_grObject
{// graphics object
  private :
    int x, y,               // object(sprite on screen) coordinates
        fx, fy ;            // frame coordinates
        c_Sprite *sprite ;  // object sprite
    bool visible ;          // is object visible
  public :
    c_grObject(c_Sprite *s,int xx,int yy,FILE *log_file=NULL) ;
    void SetVisible(bool vis=true)    {visible=vis;} ;
    bool GetVisible()                 {return visible;};
    void SetFrame(int x_num,int y_num){fx=x_num;fy=y_num;} ;
    void SetFrameX(int x_num)         {fx=x_num; } ;
    void SetFrameY(int y_num)         {fy=y_num ;} ;
    void SetCoordX(int xx)            {x=xx;};
    void SetCoordY(int yy)            {y=yy;};
    void SetCoord(int xx,int yy)      {x=xx;y=yy;};
    void DSetCoord(int dx,int dy)     {x+=dx;y+=dy;};
    void SetSprite(c_Sprite *s)       {sprite=s ;};
    c_Sprite *GetSprite()             {return sprite;};
    int GetCoordX()                   {return x;};
    int GetCoordY()                   {return y;};
    int GetXSize()                    {return sprite->GetXSize();};
    int GetYSize()                    {return sprite->GetYSize();}; 
    HRESULT Draw(IDirectDrawSurface *DDSSurface,FILE *log_file=NULL) ;
    HRESULT DrawClip(RECT screen,IDirectDrawSurface *DDSSurface,FILE *log_file=NULL) ;
} ;
//###########################################################################
//---------------------------------------------------------------------------
c_grObject::c_grObject(c_Sprite *s,int xx,int yy,FILE *log_file)
{
  if(log_file)fprintf(log_file,"START c_grObject::c_grObject\n") ;
  visible = true ;
  sprite = s ;
  x=xx;y=yy;
  fx=0;fy=0;
  if(log_file)fprintf(log_file,"   coord(%3d;%3d)\n",x,y) ;
  if(log_file)fprintf(log_file,"END   c_grObject::c_grObject\n") ;
} ;
//---------------------------------------------------------------------------
HRESULT c_grObject::Draw(IDirectDrawSurface *DDSSurface,FILE *log_file)
{
  if(log_file)fprintf(log_file,"START c_grObject::Draw\n") ;
  if(log_file)fprintf(log_file,"   visible = %d\n",visible) ;
  HRESULT res = DD_OK ;
  if(visible)res=sprite->Draw(DDSSurface,x,y,fx,fy,log_file) ;
  if(log_file)fprintf(log_file,"END   c_grObject::Draw\n") ;
  return res;
} ;
//---------------------------------------------------------------------------
HRESULT c_grObject::DrawClip(RECT screen,IDirectDrawSurface *DDSSurface,FILE *log_file)
{
  if(log_file)fprintf(log_file,"START c_grObject::Draw\n") ;
  if(log_file)fprintf(log_file,"   visible = %d\n",visible) ;
  HRESULT res = DD_OK ;
  if(visible)res=sprite->DrawClip(DDSSurface,x,y,fx,fy,screen,log_file) ;
  if(log_file)fprintf(log_file,"END   c_grObject::Draw\n") ;
  return res;
} ;
//---------------------------------------------------------------------------
#endif
