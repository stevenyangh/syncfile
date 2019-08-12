#include "fractioncalc.c"
#include <stdio.h>

void foutputfrac(FILE *pfile, frac x);
void outputequ(FILE *pfile, frac a, frac b); 

int main(){
    int limit;
    frac a, b, sum;
    FILE *pfile;
    pfile = fopen("test.txt","w");
    scanf("%d", &limit);
    if(limit > 0)
    {
        for(int i = -limit; i <= limit; i++)
        {
            for(int j = -limit; j <= limit; j++)
            {
                for(int k = -limit; k <= limit; k++)
                {
                    for(int l = -limit; l <= limit; l++)
                    {
                        a = makefrac(i, j);
                        b = makefrac(k, l);
                        fprintf(pfile, "%d, %d, %d, %d:\n", i, j, k, l);
                        outputequ(pfile, a, b);
                        fprintf(pfile, "\n");
                    }
                }
            }
        }
    }
    else
    {
        printf("Limit must be greater than 0.\n");
    }
    fclose(pfile);
    return 0;
}

void foutputfrac(FILE *pfile, frac x){
    if(x.pos == 0 && x.up != 0)
    {
        fprintf(pfile, "-%d/%d", x.up, x.down);
    }
    else
    {
        fprintf(pfile, "%d/%d",  x.up, x.down);
    }
}

void outputequ(FILE * pfile, frac a, frac b){
    foutputfrac(pfile, a);
    fprintf(pfile, " + ");
    foutputfrac(pfile, b);
    fprintf(pfile, " = ");
    foutputfrac(pfile, add(a, b));
    fprintf(pfile, "\n");

    foutputfrac(pfile, a);
    fprintf(pfile, " - ");
    foutputfrac(pfile, b);
    fprintf(pfile, " = ");
    foutputfrac(pfile, mns(a,b));
    fprintf(pfile, "\n");

    foutputfrac(pfile, a);
    fprintf(pfile, " * ");
    foutputfrac(pfile, b);
    fprintf(pfile, " = ");
    foutputfrac(pfile, mul(a, b));
    fprintf(pfile, "\n");

    foutputfrac(pfile, a);
    fprintf(pfile, " / ");
    foutputfrac(pfile, b);
    fprintf(pfile, " = ");
    foutputfrac(pfile, dvd(a, b));
    fprintf(pfile, "\n");
}
