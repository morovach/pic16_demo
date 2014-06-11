#include <stdio.h>
#include <math.h>
#include <string.h>

#include "misc.h"


int itoh(int n){
    int i=0;
    int tot=0;
    while (n!=0)
    {
        tot+=pow(10,i)*(n%16);
        n /= 16;
        n = trunc(n);
        i++;
    }
}
