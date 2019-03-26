#include "aleatorio.h"

int aleatorio (void) {
  next = (next * 1103515245 + 12345) & 0x7fffffff;
  return next;
}

void semente (unsigned seed) {
  next = seed;
}


