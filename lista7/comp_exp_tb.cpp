#include <iostream>
#include "comp_exp.h"
#include <chrono>
#include "seconds.h"

using namespace std;

// Testbench for "comp_exp.h" algorithms
int main()
{
    double inic = seconds();
    // 5 inputs of 3 values each (q, x, n)
    ulong inp[5][3] = {
        {5, 6, 23},
        {5, 15, 23},
        {5, 36, 97},
        {5, 58, 97},
        {98, 100000000, 65},
    };
    
    // inputs time for each algorithm (naive, improved, sq_mult)
    chrono::duration<double, std::nano> sec[5][3];
    chrono::high_resolution_clock::time_point aux, aux2;

    for(int i = 0; i < 5; i++)
    {
        // naive
        aux = chrono::high_resolution_clock::now();
        naive(inp[i][0], inp[i][1], inp[i][2]);
        aux2 = chrono::high_resolution_clock::now();
        sec[i][0] = aux2 - aux;

        // improved
        aux = chrono::high_resolution_clock::now();
        improved(inp[i][0], inp[i][1], inp[i][2]);
        aux2 = chrono::high_resolution_clock::now();
        sec[i][1] = aux2 - aux;

        // sq_mult
        aux = chrono::high_resolution_clock::now();
        square_mult(inp[i][0], inp[i][1], inp[i][2]);
        aux2 = chrono::high_resolution_clock::now();
        sec[i][2] = aux2 - aux;
    }

    for(int i = 0; i < 5; i++)
    {
        printf      ("         Inputs: q=%lld\tx=%lld\tn=%lld\n", inp[i][0], inp[i][1], inp[i][2]);
        std::cout << "          Naive: " << sec[i][0].count() << " (ns)\n";
        std::cout << "       Improved: " << sec[i][1].count() << " (ns)\n";
        std::cout << "Square Multiply: " << sec[i][2].count() << " (ns)\n";
    }
    
    printf("Tempo total: %f (s)", seconds()-inic);
    return 1;


}