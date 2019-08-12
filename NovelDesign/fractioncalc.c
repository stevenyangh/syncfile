typedef struct{
    int pos;
    int up;
    int down;
} frac;

int abs(int a);
int gcd(int a, int b);
int lcf_smp(int a, int b, int gcdab);
int lcf(int a, int b);

void printfrac(frac x);
frac fracint(int num);
frac reduct(frac x);
frac makefrac_nogcd(int nup, int ndown);
frac makefrac(int nup, int ndown);

frac add(frac x, frac y);
frac neg(frac x);
frac mns(frac x, frac y);

frac mul(frac x, frac y);
frac rpc(frac x);
frac dvd(frac x, frac y);

int abs(int a){
    if(a >= 0)
    {
        return a;
    }
    else
    {
        return -a;   
    }
}
int gcd(int a, int b){
    int temp_exch;
    if(a == 0 || b == 0)
    {
        return 0;
        printf("/n**    Warnng, 0 has no GCD.    **/n");
    }
    else
    {
        a = abs(a);
        b = abs(b);
        while(b != 0)
        {
            a = a % b;
            temp_exch = a;
            a = b;
            b = temp_exch;
        }
        return a;
    }
}
int lcf_smp(int a, int b, int gcdab){
    if(gcdab != 0)
    {
        if(gcdab == 1)
        {
            return abs(a * b);
        }
        else
        {
            return abs(a / gcdab * b);
        }
    }
    else
    {
        return 0;
    }
}
int lcf(int a, int b){
    return lcf_smp(a, b, gcd(a, b));
}

void outputfrac(frac x){
    if(x.pos = 0 && x.up != 0)
    {
        printf("-%d/%d", x.up, x.down);
    }
    else
    {
        printf("%d/%d",  x.up, x.down);
    }
}
frac fracint(int num){
    frac newf;
    newf.pos = num > 0;
    newf.up = abs(num);
    newf.down = 1;
    return newf;
}
frac reduct(frac x){
    int gcdud;
    if(x.up == 0 || x.down == 0)
    {
        printf("\n***   Error, 0 can not be reducted. A 0/1 has been put into return.   ***\n");
        return fracint(0);
    }
    else
    {
        gcdud = gcd(x.up, x.down);
        x.up = x.up / gcdud;
        x.down = x.down / gcdud;
        return x;
    }
    
}
frac makefrac_nogcd(int nup, int ndown){
    frac newf = fracint(0);
    if(ndown == 0)
    {
        printf("\n***   Error, 0 can not be used as divisor. A 0/1 has been put into return.   ***\n");
        return newf;
    }
    else if(nup == 0)
    {
        return newf;
    }
    else 
    {
        newf.up = nup;
        newf.down = ndown;
        newf.pos = nup > 0 == ndown > 0;
        return newf;
    }
}
frac makefrac(int nup, int ndown){
    frac newf = makefrac_nogcd(nup, ndown);
    if(nup != 0 && ndown != 0)
    {
        newf = reduct(newf);
    }
    return newf;
}

frac add(frac x, frac y){
    frac result = fracint(0);

    int gcdd, lcfd;
    int prodxu, prodyu;
    int msum, gcdMsumGcdd;
    if(x.up == 0)
    {
        return y;
    }
    else if(y.up == 0)
    {
        return x;
    }
    else 
    {
        gcdd = gcd(x.down, y.down);
        lcfd = lcf(x.down, y.down, gcdd);
        prodxu = y.down / gcdd * x.up;
        prodyu = x.down / gcdd * y.up;
        if(x.pos == y.pos)
        {
            msum = prodxu % lcfd + prodyu % lcfd;   
        }   
        else
        {
            msum = prodxu % lcfd - prodyu % lcfd;
        }
        gcdMsumGcdd = gcd(msum, lcfd);
        if(gcdMsumGcdd > 1)
        {
            lcfd = lcfd / gcdMsumGcdd;
            prodxu = prodxu / gcdMsumGcdd;
            prodyu = prodyu / gcdMsumGcdd;

            result.down = lcfd;
            if(x.pos == y.pos)
            {
                result.up = prodxu + prodyu + 1;
                result.pos = x.pos;
            }
            else
            {
                result.up = abs(prodxu - prodyu);
                result.pos = result.up != 0 && x.pos == result.up > 0;
            }
        }
        else
        {
            if(x.pos == 0)
            {
                prodxu = - prodxu;
            }
            if(y.pos == 0)
            {
                prodyu = - prodyu;
            }
            result = makefrac_nogcd(prodxu + prodyu, lcfd);
        }
        return result;
    }    
}
frac neg(frac x){
  if(x.up == 0)
  {
      return x;
  }
  else
  {
      x.pos = !x.pos;
      return x;
  }
}
frac mns(frac x, frac y)
{
    return add(x, neg(y));
}

frac mul(frac x, frac y)
{
    
}
frac rpc(frac x);
frac dvd(frac x, frac y);



