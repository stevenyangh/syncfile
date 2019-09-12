#include "fractioncalc.c"

typedef struct{
    prodnode *item;
    frac numb;
    itemstack *next;
} itemstack;

typedef struct{
    char *name;
    int ID;
    frac productivity;
    int nature;
    itemstack *ingradient;
} prodnode;



prodnode *read_itemlist();
prodnode *make_order(itemstack *items);

int main()
{
    prodnode node1 = {"iron_ore", 1, makefrac(2, 1), 1, NULL};
    prodnode node2 = {"copper_ore", 2, makefrac(2, 1), 1, NULL};
    prodnode node3 = {"stone", 3, makefrac(2, 1), 1, NULL};
    prodnode node4 = {"coal", 4, makefrac(2, 1), 1, NULL};
    prodnode node5 = {"iron_plate", 5, makefrac(), 0, NULL};
    prodnode node6 = {"copper_plate", 6, makefrac(), 1, NULL};
}

 prodnode *read_itemlist(FILE *configure, FILE *process_chart){
     return NULL;
 }

 itemstack *count_item();