#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>

typedef int DATA;

typedef struct {
 	DATA elems[MAX];
	int count;
	int max;
} List;

void initList(List *list);
List newList(int max);
void displayList(List list);
bool insertFront(List *list, DATA item);
bool insertRear(List *list, DATA item);
bool insertSorted(List *list, DATA item);
bool insertAt(List *list, DATA item, int loc);
bool searchItem(List list, DATA key);
int getItem(List list, DATA key);
bool deleteFront(List *list);
bool deleteRear(List *list);
int deleteAt(List *list, int loc);
bool deleteItem(List *list, DATA key);
int deleteAllItem(List *list, DATA key);

#endif

void initList(List *list)
{
     list->count = 0;
     
     int i;
     for(i=0; i < list->max; i++)
        {
           list->elems[i] = -1;
        }
     
     printf("SUCCESSFULLY INITIALIZED");
}

List newList(int max)
{
     List newL;
     newL.max = max;
     
     initList(&newL);
      printf("SUCCESSFULLY CREATED");
}

void displayList(List list)
{
     if(list.count > 0)
       {
          int i;
          for(i = 0; i < list.max; i++)
            {
                printf("%d ", list.elems[i]);
            }
       }
}

bool insertFront(List *list, DATA item)
{
     bool retval = false;
     if(list->count < list->max )
       {
          if(list->elems[0] == -1)
               {
                  list->elems[0] = item;
                  list->count++;
                  retval = true;
               }             
               
          else
              {
                  int x, i;
                  for(x = 0; x != -1; x++){}       
                  for(i = x; i > 0; i--)
                     {
                          list->elems[i] = list->elems[i-1];
                     }           
                   list->elems[0] = item;
                   list->count++;   
                   retval = true;
              }
       }
     return retval;
}

bool insertRear(List *list, DATA item)
{
      bool retval = false;
     if(list->count < list->max)
       { 
          if(list->elems[list->max - 1] == -1)
               {
                  list->elems[list->max - 1] = item;
                  list->count++;
                  retval = true;
               }             
               
          else
              {
                  int x, i;
                  for(x = list->max - 1; x != -1; x--){}     
                  
                  for(i = x; i < list->max - 1; i++)
                     {              
                          list->elems[i] = list->elems[i+1];
                     }           
                   list->elems[list->max - 1] = item;
                   list->count++;   
                   retval = true;
              }
       }
       
     return retval;
}

bool insertSorted(List *list, DATA item)
{
      bool retval = false;
     if(list->count < list->max)
         {
           int x;
           for(x = 0; list->elems[x] < item; x++){}
           
           int i;
           for(i = x; i != -1; i++){}
           
           while(i > x)
                   {
                       list->elems[i] = list->elems[i-1];
                       i--;
                   }    
            list->elems[x] = item;
            list->count++;
            retval = true;
         }
     return retval;
}

bool insertAt(List *list, DATA item, int loc)
{
      bool retval = false;
     if(list->count < list->max)
          {
            if(list->elems[loc] == -1)
               {
                  list->elems[loc] = item;
                  list->count++;
                  retval = true;
               }
            else
               {
                  int i;
                  for(i = loc; i != -1; i++){}
                  
                  while(i > loc) //shifting of elements
                      {
                          list->elems[i] = list->elems[i-1];
                          i--;
                      }
                  list->elems[loc] = item;
                  list->count++;
                  retval = true;
               } 
          }
     return retval;
}

bool searchItem(List list, DATA key)
{
     int i;
     bool retval = false;
     for(i = 0; i < list.max ;i++)
        {
             if(list.elems[i] == key)
                 {
                    return retval = true;
                 
                 }
        }
      return retval;     
}

int getItem(List list, DATA key)
{
    int val = -1;
    if(list.count != 0)
      {
         int x;        
         for(x = 0; list.elems[x] != key;x++){}
         
         val = list.elems[x];
         return val;      
      }
    return val;
}

bool deleteFront(List *list)
{
     bool retval = false;
     if(list->elems[0] != -1)
        {
          list->elems[0] = -1;
          list->count--;
          retval = true;             
        }
     return retval;
}

bool deleteRear(List *list)
{
       bool retval = false;
     if(list->elems[list->max - 1] != -1)
        {
           list->elems[list->max - 1] = -1;
           list->count--;
           retval = true;
        }
     return retval;
}
int deleteAt(List *list, int loc)
{
    int retval = -1;
    if(list->elems[loc] != -1)
      {
         retval = list->elems[loc];       
         list->elems[loc] = -1;
         list->count--;
      }
    return retval;
}

bool deleteItem(List *list, DATA key)
{
          bool retval = false;
     if(list->count != 0)
         {
            int i;
            for(i = 0; i < list->max; i++)
              {
                  if(list->elems[i] == key)
                     {
                        list->elems[i] = -1;
                        list->count--;
                        return retval = true;
                     }
              }    
         }
     return retval;
}

int deleteAllItem(List *list, DATA key)
{
    int retval = 0; 
    if(list->count != 0)
      {
         int i;
         for(i = 0; i < list->max;)
             {
               if(list->elems[i] == key)
                  {
                      list->elems[i] = -1;
                      list->count--;
                      retval++;
                  }  
               else
                   {
                      i++;
                   }
               
             }
      }
    return retval;
}
