#ifndef c_ElementsH
#define c_ElementsH
//---------------------------------------------------------------------------
#include <stdio.h>
#include <DDraw.h>
#include "c_grObject.h"
//---------------------------------------------------------------------------
const int mouse_button_NO    = 0 ;
const int mouse_button_LEFT  = 1 ;
const int mouse_button_RIGHT = 2 ;
//---------------------------------------------------------------------------
class c_Element:public c_grObject
{
  private :
    void (*OnClickFunction)(int mouse_x,int mouse_y,int mouse_button) ;
    int visible ;
    int enable ;
    int ID ;
    int width,height ;
  public :
    c_Element(c_Sprite *s,int xx,int yy,int w,int h,
              void (*OnClickF)(int mouse_x,int mouse_y,int mouse_button)=NULL,
              FILE *log_file=NULL) ;
    int CheckState(int mouse_x,int mouse_y,int mouse_button) ;
    void SetVisible(int v=1);
    void SetEnable (int e=1);
    int GetVisible(){return visible;};
    int GetEnable() {return enable;};
} ;
//---------------------------------------------------------------------------
c_Element::c_Element(c_Sprite *s,int xx,int yy,int w,int h,
                     void (*OnClickF)(int mouse_x,int mouse_y,int mouse_button),
                     FILE *log_file)
:c_grObject(s,xx,yy) 
{
  OnClickFunction = OnClickF ;
  visible = 0 ;
  enable = 0 ;
  c_grObject::SetVisible(visible) ;
  width=w;
  height=h ;
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
int c_Element::CheckState(int mouse_x,int mouse_y,int mouse_button)
{
  if(enable)
    if(mouse_x>GetCoordX() && mouse_x<GetCoordX()+width && mouse_y>GetCoordY() && mouse_y<GetCoordY()+height && mouse_button!=mouse_button_NO)
      OnClickFunction(mouse_x,mouse_y,mouse_button);
} ;
//---------------------------------------------------------------------------
#endif
