#include<stdio.h>

typedef struct{
    int cyc;
    int res;
    int odp;
    int evp;
    long acc;
} sta;

sta nextCycSta(sta thisCycSta);
void outputSta(sta status);

int main(){
    sta a = {0, 5, 0, 0, 5};
    printf("cyc     res     odp     evp     acc\n");
    for(int i = 0; i < 100; i++)
    {
        outputSta(a);
        a = nextCycSta(a);
    }
    return 0;
}

sta nextCycSta(sta thisCycSta){
    sta temp;
    temp.cyc = thisCycSta.cyc + 1;
    if((thisCycSta.cyc % 2) == 0)
    {
        temp.odp = thisCycSta.odp + thisCycSta.res / 5;
        temp.evp = thisCycSta.evp;
        temp.res = thisCycSta.res % 5 + thisCycSta.odp;
        temp.acc = thisCycSta.acc + thisCycSta.odp;
    }
    else
    {
        temp.evp = thisCycSta.evp + thisCycSta.res / 5;
        temp.odp = thisCycSta.odp;
        temp.res = thisCycSta.res % 5 + thisCycSta.evp;
        temp.acc = thisCycSta.acc + thisCycSta.evp;
    }
    return temp;
}

void outputSta(sta status){
    printf("%-8d%-8d%-8d%-8d%-10ld\n", status.cyc, status.res, status.odp, status.evp, status.acc);
}
