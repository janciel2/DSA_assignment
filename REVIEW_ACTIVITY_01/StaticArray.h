#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H


#include <stdbool.h>

#define MAX 10

typedef int DATA;

typedef struct {
	DATA elems[MAX];
	int count;
} List;

void initList(List *list); //
List newList(); // 
void displayList(List list); //
bool insertFront(List *list, DATA item);//
bool insertRear(List *list, DATA item);//
bool insertSorted(List *list, DATA item);//
bool insertAt(List *list, DATA item, int loc); //
bool searchItem(List list, DATA key);//
int getItem(List list, DATA key); //
bool deleteFront(List *list);//
bool deleteRear(List *list);//
int deleteAt(List *list, int loc);//
bool deleteItem(List *list, DATA key);//
int deleteAllItem(List *list, DATA key);

#endif

void initList(List *list)
{
     int i;
     list->count = 0;
     for(i = 0; i < MAX; i++)
             {
                 list->elems[i] = -1;
             }
     printf("\nSUCCESSFULLY INITIALIZE");
}

List newList()
{
     List newDef;
     initList(&newDef);
     printf("\nSUCCESSFULLY CREATED");
     return newDef;
}

void displayList(List list)
{
     int i;
     for(i = 0; i < MAX; i++)
             {
               printf("%d ", list.elems[i]);
             }
}

bool insertFront(List *list, DATA item)
{
     bool retval = false;
     if(list->count < MAX )
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
     if(list->count < MAX )
       { 
          if(list->elems[MAX - 1] == -1)
               {
                  list->elems[MAX - 1] = item;
                  list->count++;
                  retval = true;
               }             
               
          else
              {
                  int x, i;
                  for(x = MAX - 1; x != -1; x--){}     
                  
                  for(i = x; i < MAX - 1; i++)
                     {              
                          list->elems[i] = list->elems[i+1];
                     }           
                   list->elems[MAX - 1] = item;
                   list->count++;   
                   retval = true;
              }
       }
     return retval;
}

bool insertSorted(List *list, DATA item)
{
     bool retval = false;
     if(list->count < MAX)
         {
           int x;
           for(x = 0; list->elems[x] < item; x++){}
           
           int i;
           for(i = x; i != -1; i++){}
           
           while(i > x)
                   {
                       list->elems[i] = list->elems[i-1];
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
     if(list->count < MAX)
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
     for(i = 0; i < MAX ;i++)
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
    if(list.count != 0)
      {
         int val,x;        
         for(x = 0; list.elems[x] != key;x++){}
         
         val = list.elems[x];
         return val;      
      }
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
     if(list->elems[MAX - 1] != -1)
        {
           list->elems[MAX - 1] = -1;
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
            for(i = 0; i < MAX; i++)
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

int deleteAllItem(List *list, DATA key) //
{
    int retval = 0;
    if(list->count != 0)
      {
         int i;
         for(i = 0; i < MAX; )
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





     
