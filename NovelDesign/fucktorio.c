#include "fractioncalc.c"

typedef struct{
    prodnode *item;
    float num;
} itemstack;

typedef struct{
    char *name;
    int ID;
    float productivity;
    itemstack *ingradient;
} prodnode;

frac fracint();
frac add();
frac neg();
frac rpc();
frac mul();

prodnode *read_itemlist();
prodnode *make_order(itemstack *items);

int main()
{

}