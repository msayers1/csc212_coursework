//fibonacci.cpp
#include <iostream>
#include <iomanip>      // std::setprecision
#include <stdlib.h>
#include <ctime>
#include <cstring>
#include <stdio.h>
#include <string.h>


uint64_t fib_r(uint16_t n) {
    if (n < 2) {
        return n;

    } 
    else {
        return fib_r(n-1) + fib_r(n-2);

    }
}

uint64_t fib_i(uint16_t n) {

    uint64_t sum;
    uint64_t prev[] = {0, 1};

    if (n < 2) {
        return n;

    }

    for (uint16_t i = 2 ; i <= n ; i++ ) {
        sum = prev[0] + prev[1];
        prev[0] = prev[1];
        prev[1] = sum;

    }
    return sum;
}

void time_func(uint16_t n, const char *name) {
    uint64_t val;
    unsigned long c_start, c_end;
    if (! strcmp(name, "fib_i")) {
        c_start = std::clock();
        val = fib_i(n);
        c_end = std::clock();

    }
    else if (! strcmp(name, "fib_r")) {
        c_start = std::clock();
        val = fib_r(n);
        c_end = std::clock();

    }
    else{
        std::cout << "Invalid function call" << std::endl;
        return;

    }
    
    float output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    std::cout << name << " fib(" << n << "):\t";
    std::cout << std::fixed << std::setprecision(4) << output << " Output: " << val << std::endl;
}

int main(int argc, char**argv) {
    if (argc != 3) {
        std::cout << "Usage: ./fib <n <alg\n";
        std::cout << "\t<n\tn-th term to be calculated\n";
        std::cout << "\t<alg\talgorithm to be used (fib_r or fib_i)\n";
        return 0;
        
    }

    uint16_t n = (uint16_t) atoi(argv[1]);
    time_func(n, argv[2]);
}