#ifndef SQLIST_DATASTRUCT_H
#define SQLIST_DATASTRUCT_H

#include <iostream>
#include <stdlib.h>

#define list_init_size 100
#define list_increment 10
#define elemtype int
#define objexist true
#define loopnumberlimit 10

using namespace std;
void error(const char *s){
  cout << s << endl;
  exit(1);
}
void warn(const char *s){
  cout << s << endl;
}

typedef struct{
elemtype *elem;
int lenth;
int size;
}sqlist;//sequencial list

//pointer to functions
typedef void (*fls)(sqlist &l);
typedef void (*fle)(sqlist &l,int i); 
typedef void (*fps)(sqlist &l,int lstart,int lend);
typedef void (*fpd)(sqlist &l,int lstart,int lend,sqlist &m,int mstart,int mend);

//judge on condition
bool jls(sqlist &l,bool reqexist,int loopnumber){}
bool jle(sqlist &l,int i,bool reqexist,int loopnumber){}
bool jps(sqlist &l,int lstart,int lend,bool reqexist){}
bool jpd(sqlist &l,int lstart,int lend,sqlist &m,int mstart,int mend){}

//jae: judge and then execute
void jaelists(fls f,sqlist &l,bool reqexist){}
void jaelistelem(fle f,sqlist &l,int i,bool reqexist){}
void jaepieces(fps f,sqlist &l,int lstart,int lend,bool reqexist){}
void jaepieced(fpd f,sqlist &l,int lstart,int lend,sqlist &m,int mstart,int mend){}

//basic function that shuoldn't be involved with jae/j functions.
pureinitlist(sqlist &l){}
puredestroylist(sqlist &l){}
pureclearlist(sqlist &l){}
listlenth(sqlist &l){}
fixlist(sqlist &l){}
puregetelem(sqlist l,int i,elemtype &e){}
increnumber(int i,int rec){}
pureincrement(sqlist &l,int i){}

//black-boxed operations, safe & intuitional
initlist(sqlist &l){}
destroylist(sqlist &l){}
clearlist(sqlist &l){}
getelem(sqlist l,int i,elemtype &e){}
#endif
