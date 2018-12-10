 #include "SeqListheader.hpp"

int main(){

    Sqlist l;
    InitList_sq(l);
    
    l.ElemLength = 7;
    for(int i = 0, a[7] = {12, 21, 34, 47, 58, 62, 79}; i < 7; i ++)
	l.elem[i] = a[i];

    for(int i = 1; i <= 3; i++)
	ListInsert_sq(l, i + , 12345);

    PrintList_sq(l);
    PrintAll_sq(l);

    ListDelete_sq(l, 9);

    PrintAll_sq(l);
    
    DestroyList_sq(l);

    PrintAll_sq(l);
    return 0;
}
