/*
*  c_Font class
*  Класс для вывода текста
*  в DirectDraw
*  возможен вывод типа *char и long
*
*  version 1.0
*/

#ifndef c_FontH
#define c_FontH
//---------------------------------------------------------------------------
#include <windows.h>
#include <windowsx.h>
#include <ddraw.h>
#include <stdio.h>
#include "c_Sprite.h"
#include "c_grObject.h"
//---------------------------------------------------------------------------
#define font_STD_X_COUNT  32
#define font_STD_Y_COUNT  5
//---------------------------------------------------------------------------
class c_Font:public c_grObject
{
  private :
    int type_count ; // кол-во типов шрифтов (по цвету, кадрам,...)
  public :
    c_Font(c_Sprite *s,int tc=1) ;
    HRESULT Draw(IDirectDrawSurface *DDSSurface,char *string,int N,int x,int y,int type=0,FILE *log_file=NULL) ;
    HRESULT Draw(IDirectDrawSurface *DDSSurface,long string,int x,int y,int type=0,FILE *log_file=NULL) ;
} ;
//---------------------------------------------------------------------------
c_Font::c_Font(c_Sprite *s,int tc)
:c_grObject(s,0,0)
{
  type_count=tc ;
} ;
//---------------------------------------------------------------------------
HRESULT c_Font::Draw(IDirectDrawSurface *DDSSurface,char *string,int N,int x,int y,int type,FILE *log_file)
{
  if(log_file)fprintf(log_file,"START c_Font::Draw\n") ;
  if(log_file)fprintf(log_file,"   string %s\n",string) ;
  int done=0;
  SetCoord(x,y) ;
  if(type>type_count*5 || type<0)type=0;
  for(int ch=0;ch<N;ch++)
  {
    char string_char=string[ch] ;
    if(log_file)fprintf(log_file,"   string_char %d-%c\n",string_char,string_char) ;
    if(string_char>=48 && string_char<=57) // цифры
    {
      if(log_file)fprintf(log_file,"   цифры\n") ;
      SetFrame(string_char-48,type);
      done=1;
    }
    else
    if(string_char>=65 && string_char<=90) // заглавные английские
    {
      if(log_file)fprintf(log_file,"   заглавные англ.\n") ;
      SetFrame(string_char-65,type+1) ;
      done=1;
    }
    else
    if(string_char>=97 && string_char<=122) // прописные английские
    {
      if(log_file)fprintf(log_file,"   прописные англ.\n") ;
      SetFrame(string_char-97,type+2);
      done=1;
    }
    else
    if(string_char>=128 && string_char<=159) // заглавные русские
    {
      if(log_file)fprintf(log_file,"   заглавные русск.\n") ;
      SetFrame(string_char-128,type+3);
      done=1;
    }
    else
    if((string_char>=160 && string_char<=175)||(string_char>=224 && string_char<=239)) // прописные русские
    {
      if(log_file)fprintf(log_file,"   прописные русск.\n") ;
      //...
    }
    else
    if(string_char==13) // enter
      SetCoord(x,GetCoordY()+(GetSprite()->GetYSize())) ;
    if(done)
    {
      done = 0 ;
      HRESULT res=c_grObject::Draw(DDSSurface);
      if(res!=DD_OK)return res ;
    } ;
    DSetCoord((GetSprite()->GetXSize()),0) ;
  } ;
  if(log_file)fprintf(log_file,"END   c_Font::Draw\n") ;
  return DD_OK ;
} ;
//---------------------------------------------------------------------------
HRESULT c_Font::Draw(IDirectDrawSurface *DDSSurface,long string,int x,int y,int type,FILE *log_file)
{
  if(log_file)fprintf(log_file,"START c_Font::Draw\n") ;
  if(log_file)fprintf(log_file,"   string %d\n",string) ;

  SetCoord(x,y);
  long num=string,stage0,stage1,stage2 ;
  int done=1;
  while(done)
  {
    stage0=num%10;
    stage1=num-stage0;
    stage2=stage1/10;
    num=stage2;
    SetFrame(stage0,type) ;
    HRESULT res=c_grObject::Draw(DDSSurface,log_file) ;
    if(res!=DD_OK)return res;
    DSetCoord(-(GetSprite()->GetXSize()),0) ;
    if(num==0)break;
  } ;

  if(log_file)fprintf(log_file,"END   c_Font::Draw\n") ;
  return DD_OK ;
} ;
//---------------------------------------------------------------------------
#endif