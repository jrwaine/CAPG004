#include <stdio.h>
#include <math.h>

typedef long long int ulong;

ulong sq_mult (ulong q, ulong x, ulong n){
    ulong r = 1;
    while (x > 0) {
        if ((x % 2) == 1) {
            r = (r * q) % n; /*Multiply (MUL)*/
            if (r < 0) { printf("overflow"); return -1; }
        }
        x /= 2;
        q = (q * q) % n; /*Square (SQ)*/
        if (q < 0) { 
            printf("overflow"); 
            return -1; 
        }
    }
    return r;
}

ulong euclides_estendido (ulong m, ulong n, ulong *a, ulong *b) {
    ulong d;
    if (n == 0) {
        *a = 1;
        *b = 0;
        return m;
    }
    else {
        d = euclides_estendido (n, m % n, a, b);
        ulong e = *a, f = *b;
        *a = f;
        *b = e - f*(m/n);
        return d;
    }
}

void descobre_primos(ulong n, ulong* p, ulong* q)
{
    ulong i;    
    for(i = 2; i <= sqrt((double)n); i++)
    {
        double div = (double)n/i;
        if(floor(div) == ceil(div))
        {
            *p = n/i;
            *q = i;
        }
    }
}


int main () {

    /*Geracao de chaves!*/
    ulong p, q, a, b;       // p: prime 1 - q: prime 2 - a,b: aux variables
    ulong n, phi_n, e, d;   // n: "mod n" - phi_n = phi(n)
                            // e: public number - d: private number
                            // private key: (d, n)
                            // public key: (e, n)
    
    ulong msg_plain, msg_crypt, msg_dcrypt;
    ulong assin_x, assin_xl;
    
    ulong crypt_assin_A, crypt_A, A;
    
    crypt_assin_A = 51859;
    
    // public Alice
    n = 127273;
    e = 14641;

    crypt_A = sq_mult(crypt_assin_A, e, n);
    
    // private Bob
    n = 135379;
    d = 57251;
    
    A = sq_mult(crypt_A, d, n);

    printf("crypt_assin_A: %lld\ncrypt_A: %lld\nA: %lld\n", crypt_assin_A, crypt_A, A);

    return 0;
}
