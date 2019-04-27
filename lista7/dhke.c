#include <stdio.h>
#include <stdlib.h>
#include "comp_exp.h"

// DHKE (Diffie-Hellman Key Exchange)
int main()
{
    ulong q, p; 
    ulong pv_a, pv_b; // private keys
    ulong A, B; // A and B are public messages
    ulong key_a, key_b; // key is evaluated privately
    
    p = 826669; // prime 6 digits
    q = 342534; // rand in [2, p-2]

    pv_a = 826665; // rand in [2, p-2]
    pv_b = 234543; // rand in [2, p-2]

    A = square_mult(q, pv_a, p);
    B = square_mult(q, pv_b, p);

    key_a = square_mult(B, pv_a, p);
    key_b = square_mult(A, pv_b, p);

    printf("      Public:    q=%lld\t  p=%lld\n", q, p);
    printf("   Private A: pv_b=%lld\t  A=%lld\n", pv_a, A);
    printf("   Private B: pv_b=%lld\t  B=%lld\n", pv_b, B);
    printf("Private keys:  k_a=%lld\tk_b=%lld\n", key_a, key_b);
    return 1;
}