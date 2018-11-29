#ifndef _SEQLIST_HPP

#include<new>
#include<string>
#include<iostream>

#define DATATYPE int
#define EMPTY 0
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10

typedef struct{
    DATATYPE *elem;
    int StorageLength;
    int ElemLength;
}Sqlist;

void Error(std::string s){
    std::cout << s << std::endl;
    exit(1);
}

void InitList_sq(Sqlist &L){
    L.elem = new DATATYPE[LIST_INIT_SIZE];
    if(!L.elem)
	Error("Overflow");
    L.StorageLength = LIST_INIT_SIZE;
    L.ElemLength = 0;
} // Init list L.

void DestroyList_sq(Sqlist &L){
    delete []L.elem;
    L.StorageLength = 0;
    L.ElemLength = 0;
    L.elem = nullptr;
} // Destroy list L.

void ClearList_sq(Sqlist &L){
    L.ElemLength = 0;
} // Clearlist L

int ListLength_sq(Sqlist L){
    return L.ElemLength;
}

void GetElem_sq(Sqlist L, int i, DATATYPE &e){
    if(i >= 1 && i <= L.ElemLength)
	e = L.elem[i - 1];
    else
	Error("Wrong position!");
}

void PrintList_sq(Sqlist L)
{
    if(!L.elem)
	Error("List does not exist.");
    DATATYPE *p = L.elem;
    std::cout << std::endl << "List:" << std::endl;
    for(int i = 1; i <= L.ElemLength; i++, p++)
	std::cout << *p << " ";
    std::cout << "end." << std::endl;
} 

void PrintAll_sq(Sqlist L)
{
    if(!L.elem)
	Error("List does not exist.");
    DATATYPE *p = L.elem;
    std::cout << std::endl << "All: " << L.StorageLength << std::endl << L.ElemLength << " in list -> ";    
    for(int i = 1; i <= L.ElemLength; i++, p++)
	std::cout << *p << " ";
    std::cout  << "end." <<std::endl << L.StorageLength - L.ElemLength << " in storage -> ";
    for(int i = L.ElemLength; i < L.StorageLength; i++, p++)
	std::cout << *p << " ";
    std::cout << "end."<< std::endl;
    
}

int LocateElem_sq(Sqlist L, DATATYPE e){
    DATATYPE *p = L.elem;
    int i;
    for(i = 1; i <= L.ElemLength && *p != e; i++, p++);
    if(i > L.ElemLength)
	return 0;
    else
	return i;
}// This can be enhanced. 

void Increment(Sqlist &L)
{
    DATATYPE *newlist = new DATATYPE[L.StorageLength + LIST_INCREMENT];
    if(!newlist)
	Error("Overflow");
    for(int i = 0; i < L.ElemLength; i++)
	newlist[i] = L.elem[i];
    delete []L.elem;
    L.elem = newlist;
    L.StorageLength += LIST_INCREMENT;
}

void ListInsert_sq(Sqlist &L, int i, DATATYPE e)
{
    if(i < 1 || i > L.StorageLength)
	Error("Position error");
    if(L.ElemLength >= L.StorageLength)
	Increment(L);
    DATATYPE *p = &L.elem[i - 1];
    for(DATATYPE *q = &(L.elem[L.ElemLength]); q > p; q--)
	*q = *(q - 1);
    *p = e;
    L.ElemLength++;
}

DATATYPE ListDelete_sq(Sqlist &L, int i)
{
    if(i < 1 || i > L.ElemLength)
	Error("Position error");

    DATATYPE *p = &(L.elem[i - 1]);
    DATATYPE temp = *p;
    
    for(int j = i; j < L.ElemLength; p++, j++)
	*p = *(p + 1);

    *p = EMPTY;
    L.ElemLength--;
    return temp;
}

DATATYPE ListTraverse_sq(Sqlist L)
{
    std::cout << "List length:" << L.ElemLength << std::endl;

    DATATYPE *p = l.elem;
    for(int i = 1; i < L.ElemLength; i++, p++)
	std::cout << *p << " ";
    std::cout << *p << std::endl << std::endl;
}

#endif
