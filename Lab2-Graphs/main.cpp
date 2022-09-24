//main.cpp
#include <iostream>
#include <iomanip>      // std::setprecision
#include <stdlib.h>
#include <ctime>
#include <stdio.h>
#include <string.h>

long double euler1(int n) {
    long double sum = 0;
    long double fact;
    for (int i = 0 ; i <= n ; i ++) {
        fact = 1;
        for (int j = 2 ; j <= i ; j++) {
            fact *= j;
        }
        sum += (1.0 / fact);
    }

    return sum;
}

long double euler2(int n) {
    long double sum = 0;
    long double fact = 1;

    for (int i = 0 ; i <= n ; i++) {
        sum += (1.0 / fact);
        fact *= (i+1);
    }

    return sum;
}

void time_func(uint16_t n, const char *name) {

    uint64_t val;

    unsigned long c_start, c_end;

    if (! strcmp(name, "euler1")) {
        c_start = std::clock();
        val = euler1(n);
        c_end = std::clock();

    }
    else if (! strcmp(name, "euler2")) {
        c_start = std::clock();
        val = euler2(n);
        c_end = std::clock();

    }
    else{
        std::cout << "Invalid function call" << std::endl;

    }

    float output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    std::cout << name << " euler(" << n << "):\t";
    std::cout << std::fixed << std::setprecision(4) << output << " Output: " << val << std::endl;
}

int main(int argc, char**argv) {
    if (argc != 3) {
        std::cout << "Usage: ./euler <n <alg\n";
        std::cout << "\t<n\tn-th term to be calculated\n";
        std::cout << "\t<alg\talgorithm to be used (euler1 or euler2)\n";
        return 0;
        
    }

    uint16_t n = (uint16_t) atoi(argv[1]);
    time_func(n, argv[2]);
}