#ifndef COMP_EXP_H
#define COMP_EXP_H

typedef long long int ulong;

// Functions to evaluate q^x mod n
ulong naive(ulong q, ulong x, ulong n);
ulong improved(ulong q, ulong x, ulong n);
ulong square_mult(ulong q, ulong x, ulong n);

#endif // !COMP_EXP_H