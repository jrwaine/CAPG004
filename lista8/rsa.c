#include <stdio.h>
#include <math.h>

typedef long long int ulong;

ulong square_multiply (ulong q, ulong x, ulong n){
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

int main () {

    /*Geracao de chaves!*/
    ulong p, q, a, b;       // p: prime 1 - q: prime 2 - a,b: aux variables
    ulong n, phi_n, e, d;   // n: "mod n" - phi_n = phi(n)
                            // e: public number - d: private number
                            // private key: (d, n)
                            // public key: (e, n)
    
    ulong msg_plain, msg_crypt, msg_dcrypt;
    msg_plain = 0;    

    p = 0; q = 0; a = 0; b = 0;
    //printf("Completar parte de geração de chaves!\n");
    
    n = p*q;
    phi_n = (p-1)*(q-1);
    for(e = 0; e < phi_n; e++)
    {
        if(euclides_estendido(phi_n, e, &a, &b) == 1)
            break;
    }

    while(b < 0)
        b += phi_n;

    d = b % phi_n;
    

    
    /*Cifrar*/
    //printf("Faça um teste para cifrar com RSA!\n");
    msg_crypt = sq_mult(msg_plain, e) % n;
    
    /*Decifrar*/
    //printf("Faça um teste para decifrar com RSA!\n");
    msg_dcrypt = sq_mult(msg_crypt, d) % n;

    return 0;
}
