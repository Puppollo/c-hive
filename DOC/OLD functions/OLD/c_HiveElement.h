/*
 * c_HiveElements class
 * Имитирует кнопки и др. win элементы в HIVE_p
 *
 * version 1.4
 */
#ifndef c_ElementsH
#define c_ElementsH
//---------------------------------------------------------------------------
#include <stdio.h>
#include <DDraw.h>
#include <c_grObject.h>
#include "HiveMain.h"
//---------------------------------------------------------------------------
const int mouse_button_NO    = 0 ;
const int mouse_button_LEFT  = 1 ;
const int mouse_button_RIGHT = 2 ;
//---------------------------------------------------------------------------
class c_Element:public c_grObject
{
  private :
    void (*OnClickFunction)(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ;
    void (*OnMoveFunction)(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element) ;
    int visible ;
    int enable ;
    int x,y,width,height ;
  public :
    c_Element(c_Sprite *s,int xx,int yy,int w=0,int h=0,int fx=0,int fy=0,
              void (*OnClickF)(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)=NULL,
              void (*OnMoveF)(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element)=NULL,
              FILE *log_file=NULL) ;
    int CheckState(s_mouse *mouse,c_World *world,int &action,int player_ID) ;
    void SetVisible(int v=1);
    void SetEnable (int e=1);
    void SetElementCoord(int xx,int yy){x=xx;y=yy;} ;
    void DSetElementCoord(int dx,int dy){x+=dx;y+=dy;} ;
    void SetElementSize(int w,int h){width=w;height=h;};
    int GetVisible(){return visible;};
    int GetEnable() {return enable;};
} ;
//---------------------------------------------------------------------------
c_Element::c_Element(c_Sprite *s,int xx,int yy,int w,int h,int fx,int fy,
                     void (*OnClickF)(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element),
                     void (*OnMoveF)(s_mouse *mouse,c_World *world,int &action,int player_ID,c_Element *element),
                     FILE *log_file)
:c_grObject(s,xx,yy)
{
  x=xx;y=yy;
  SetFrame(fx,fy) ;
  OnClickFunction = OnClickF ;
  OnMoveFunction = OnMoveF;
  visible = 1 ;
  enable = 1 ;
  c_grObject::SetVisible(visible) ;
  if(w<=0)width=GetSprite()->GetXSize() ;
  else width=w;
  if(h<=0)height=GetSprite()->GetYSize() ;
  else height=h ;
} ;
//---------------------------------------------------------------------------
void c_Element::SetVisible(int v)
{
  if(v!=0)visible=1;
  else visible=0;
  c_grObject::SetVisible(visible);
} ;
//---------------------------------------------------------------------------
void c_Element::SetEnable (int e)
{
  if(e!=0)enable=1;
  else enable =0;
} ;
//---------------------------------------------------------------------------
int c_Element::CheckState(s_mouse *mouse,c_World *world,int &action,int player_ID)
{
  if(enable)
    if(mouse->x>x && mouse->x<x+width && mouse->y>y && mouse->y<y+height)
    {
      OnMoveFunction(mouse,world,action,player_ID,this) ;
      if(mouse->button!=mouse_button_NO)
        OnClickFunction(mouse,world,action,player_ID,this);
    } ;
} ;
//---------------------------------------------------------------------------
#endif
