#include "sqlistconf.hpp"


//basic operatoin to list
void pureinitlist(sqlist &l){
  int i;
  l.elem=new elemtype[list_init_size] ;
  if(!l.elem) error("overflow");
  l.lenth=0;
  l.listsize=list_init_size;
}
void initlist(sqlist &l){
  fls f=pureinitlist;
  jaelists(f,l,!objexist)
}

void puredestroylist(sqlist &l){
  delete []l.elem;
  l.lenth=0;
  l.listsize=0;
}
void destroylist(sqlist &l){
  fls f=puredestroylist;
  jaelists(f,l,objexist);
}

void pureclearlist(sqlist &l){
  l.listsize=0;
}
void clearlist(sqlist &l){
  fls f=pureclearlist;
  jaelists(f,l,objexist;)
}

int listlenth(sqlist &l){
  return l.lenth;
}

void fixlist(sqlist &l){
  jls(l,objexist);
}


//basic operation to elements
void puregetelem(sqlist l,int i,elemtype &e){
  e=l.elem[i-1];
}
void getelem(sqlist l,int i,elemtype &e){
  if(jle(l,i)){
    puregetelem(l,i,e);
  }
  else{
    warn("operation wrong");
  }
}

int increnumber(int i,int rec){
  if(i<=list_init_size){
    return rec; 
  }
  else{
    i-=list_increment;
    return increnumber(i,rec++);
  }
}
void pureincrement(sqlist &l,int i){
  int *newlist;
  i=i*list_increment;
  l.listsize+=i;
  newlist = new elemtype[l.listsize];
  if(!newlist){
    error("oveflow");
  }
  for(i=0;i<l.lenth;i++){
    newlist[i]=l.elem[i];
  }
  delete []l.elem;
  l.elem=newlist;
}

void moveelem(){
  void (*p)(bool judge,sqlist &l,int i,int m);
  if(judge) 
  (*p)=move;
  judgeandexcute((*p),sqlist &);
}
void pureswitchelem(sqlist &l,int i,int j){
  int temp;
  if((i>=0)&&(i<=l.lenth)&&(j>=0)&&(j<=l.lenth)){
    temp=l.elem[i];
    l.elem[i]=l.elem[j];
    l.elem[j]=temp;
  }
  else{
    error("position wrong");
  } 
}

//basic operation to piece
void purelocateelem(sqlist l,int e,int &i){
XC
}
int locateelem(sqlist l, int e){
  int i=0;
  int *p= l.elem;
  while((i<=l.lenth)&&(*p++ != e))
    i++;
  if(i<=l.lenth)
    return i;
  else
    return 0;
}


void pureinvertpiece(sqlist &l,int i,int j){
  if(i=<j){
    for(;i>=j;i++,j--)
      switchelem(l,i,j);
  }
  else{
    invertpiece(l,j,i);
  }
}

void puretraversallist(sqlist &l){
  int i;
  for(i=0;i<l.lenth,)
}
void traversallist(sqlist l){
  
}
 
