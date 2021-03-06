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
    msg_plain = 181;

    p = 41; q = 17; e = 5;
    
    descobre_primos(6326693, &p, &q);
    
    a = 0; b = 0;
    //printf("Completar parte de geração de chaves!\n");
    
    n = p*q;
    phi_n = (p-1)*(q-1);
    
    /*
    for(e = 2; e < phi_n; e++)
    {
        if(euclides_estendido(phi_n, e, &a, &b) == 1)
            break;
    }
    */

    if(euclides_estendido(phi_n, e, &a, &b) != 1)
    {
        printf("Invalid e!\n");
        return -1;
    }

    while(b < 0)
        b += phi_n;

    d = b % phi_n;
    

    
    /*Cifrar*/
    //printf("Faça um teste para cifrar com RSA!\n");
    msg_crypt = sq_mult(msg_plain, e, n);
    msg_crypt = 1632643;

    /*Decifrar*/
    //printf("Faça um teste para decifrar com RSA!\n");
    msg_dcrypt = sq_mult(msg_crypt, d, n);
    

    printf("n: %lld\npriv. key: %lld\npubl. key: %lld\n", n, d, e);
    printf("msg. plain: %lld\nmsg. crypt: %lld\nmsg. dcrypt: %lld\n", msg_plain, msg_crypt, msg_dcrypt);

    return 0;
}
