#include "SeqListheader.hpp"

int main(){

    Sqlist l;
    InitList_sq(l);

    l.ElemLength = 7;
    for(int i = 0, a[7] = {12, 21, 34, 47, 58, 62, 79}; i < 7; i ++)
	l.elem[i] = a[i];

    DestroyList_sq(l);
    return 0;
}
