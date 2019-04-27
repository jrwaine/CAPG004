#include "comp_exp.h"

ulong naive(ulong q, ulong x, ulong n)
{
    int i;
    ulong r = 1;
    for (i = 0; i < x; i++) {
        r = (r * q);
        //if(r < 0)
            //return -1;
    }
    return r % n;
}

ulong improved(ulong q, ulong x, ulong n)
{
    int i;
    ulong r = 1;
    for (i = 0; i < x; i++) {
        r = (r * q) % n;
        //if(r < 0)
            //return -1;
    }
    return r;
}

ulong square_mult(ulong q, ulong x, ulong n)
{
    ulong r = 1;
    while (x > 0) {
        if ((x % 2) == 1) {
            r = (r * q) % n; /*Multiply (MUL)*/
        }
        x /= 2;
        q = (q * q) % n; /*Square (SQ)*/
        //if(q < 0)
            //return -1;
    }
    return r;

}