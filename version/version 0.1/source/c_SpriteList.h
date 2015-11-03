/*
 *   SpriteList class
 *   Класс для работы с линейным списком
 *   объектов c_Sprite
 *
 *   vesrion 1.0
 */
#ifndef c_SpriteListH
#define c_SpriteListH
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <ddraw.h>
#include <string.h>
#include "c_Sprite.h"
//---------------------------------------------------------------------------
//###########################################################################
struct s_SpriteListNode
{
  c_Sprite *sprite ;
  s_SpriteListNode *next,*prev;
  char *path ;
  int ID ;
} ;
//###########################################################################
class c_SpriteList
{
  private :
    s_SpriteListNode *beg,*end ;
    int ID_count ;
    int sprite_count ;
  public :
    c_SpriteList() ;
    void Add(IDirectDraw *DDraw,LPCSTR path,unsigned x_count,unsigned y_count,FILE *log_file=NULL) ;
    c_Sprite *Find(int ID) ;
    c_Sprite *Find(LPCSTR path) ;
    HRESULT RestoreAll(FILE *log_file=NULL) ;
    void ReleaseAll(FILE *log_file=NULL) ;
} ;
//###########################################################################
//---------------------------------------------------------------------------
c_SpriteList::c_SpriteList()
{
  sprite_count = 0 ;
  beg = NULL ;
  end = NULL ;
  ID_count = 0 ;
} ;
//---------------------------------------------------------------------------
void c_SpriteList::Add(IDirectDraw *DDraw,LPCSTR path,unsigned x_count,unsigned y_count,FILE *log_file)
{
  if(log_file)fprintf(log_file,"START c_SpriteList::Add\n") ;
  s_SpriteListNode *node = new s_SpriteListNode ;
  node->sprite = NULL ;
  node->prev = NULL ;
  node->next = NULL ;
  node->sprite = new c_Sprite(DDraw,path,x_count,y_count,log_file) ;
  //strcpy(node->path,path) ;
  node->ID = ID_count ;
  if(sprite_count==0)
  {
    beg = node ;
    end = beg ;
  } ;
  node->prev = end ;
  end->next = node ;
  end = node ;
  end->next=NULL ;
  if(log_file)fprintf(log_file,"   add : ID %d, path %s\n",node->ID,path) ;
  ID_count++ ;
  sprite_count++ ;
  if(log_file)fprintf(log_file,"END   c_SpriteList::Add\n") ;
} ;
//---------------------------------------------------------------------------
c_Sprite *c_SpriteList::Find(int ID)
{
  s_SpriteListNode *node = beg ;
  while(node)
  {
    if(node->ID==ID)break;
    node=node->next ;
  } ;
  return node->sprite ;
} ;
//---------------------------------------------------------------------------
c_Sprite *c_SpriteList::Find(LPCSTR path)
{
  s_SpriteListNode *node = beg ;
  while(node)
  {
    if(strcmp(node->path,path)==0)break;
    node=node->next ;
  } ;
  return node->sprite ;
} ;
//---------------------------------------------------------------------------
HRESULT c_SpriteList::RestoreAll(FILE *log_file)
{
  if(log_file)fprintf(log_file,"START c_SpriteList::RestoreAll\n") ;
  HRESULT res=DD_OK ;
  s_SpriteListNode *node = beg ;
  while(node)
  {
    if(log_file)fprintf(log_file,"   restore ID %d\n",node->ID) ;
    res = (node->sprite)->Restore() ;
    if(res!=DD_OK)break;
    node=node->next ;
  } ;
  if(log_file)fprintf(log_file,"END   c_SpriteList::RestoreAll\n") ;
  return res ;
} ;
//---------------------------------------------------------------------------
void c_SpriteList::ReleaseAll(FILE *log_file)
{
  if(log_file)fprintf(log_file,"START c_SpriteList::ReleaseAll\n") ;
  s_SpriteListNode *node = beg ;
  while(node)
  {
    if(log_file)fprintf(log_file,"   release ID %d\n",node->ID) ;
    (node->sprite)->Release() ;
    node=node->next ;
  } ;
  if(log_file)fprintf(log_file,"END   c_SpriteList::ReleaseAll\n") ;
} ;
//---------------------------------------------------------------------------
#endif