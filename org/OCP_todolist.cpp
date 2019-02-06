#include<stdio.h>

typedef struct DATE{
    int yy;
    int mm;
    int dd;
    int M;
    int cycle;
  int openNum;
  int dailyStatus;
  int optionStatus;
}date;

void readDate(FILE *pfile, &today);
void initDate(&todat);

int main()
{
    date today, rec;
    int v, w, x, y, z;

    initDay(today);
    
    FILE *pfile = fopen("record", "rb");
    if(pfile != nullptr)
    {
	if(feof(pfile))
	{
	    initDate(rec);
	}
	else
	{
	    readDate(pfile, rec);
	}
	fclose(pfile);
    }
    else
    {
	printf("[Error when opening the file. (READ)]\n");
	return 1;
    }

    //basic task
    dice(v);
    dice(w);
    dice(x);
    p_daily(v, w, x);
    
    //optional task
    dice(y);
    dice(z);
    if(rec.M == 0 && rec.cycle == 0)
    {
	p_first_day(y, z);
	
	b_end(rec, today);
    }
    else
    {
	int index = rec.M * (y + z);
	if(index == 0)
	{
	    dice(v);
	    dice(w);
	    dice(x);
	    
	    p_extra(v, w, x);
	    b_end(rec, today);
	}
	else if(index > 0 && index <= 125)
	{
	    dice(v);
	    dice(w);
	    dice(x);
	    dice(y);
	    dice(z);
	    p_siss();
		b_end();
	}
	else if(index > 125 && index <= 249)
	{
	    
	}
	else if(index > 250)
	{
	    
	}
	else
	{
	    printf("Error.\n");
	}
    }
	
    pfile = fopen("record", "rw");
    if(pfile != nullptr)
    {
        writeDate(pfile, today);
	fclose(pfile);
	return 0;
    }
    else
    {
	printf("[Error when opening the file. (WRITE)]\n");
	return 1;
    }
    
    return -1;
}
