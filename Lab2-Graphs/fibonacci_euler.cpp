//fibonacci.cpp
#include <iostream>
#include <iomanip>      // std::setprecision
#include <stdlib.h>
#include <ctime>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <fstream>

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

float time_func(uint16_t n, const char *name) {
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
    else if (! strcmp(name, "euler1")) {
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
        std::cout << "Invalid function call" << val << std::endl;

    }

    float output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;;
    return output;
}

int main(int argc, char**argv) {
    if (argc != 3) {
        std::cout << "Usage: ./fib <n <alg\n";
        std::cout << "\t<n\tn-th term to be calculated\n";
        std::cout << "\t<alg\talgorithm to be used (fib_r or fib_i or euler1 or euler2)\n";
        return 0;
    }

    uint16_t Max_Number = (uint16_t) atoi(argv[1]);
    std::ofstream myfile;
    
    myfile.open(std::to_string(Max_Number)+ "_" + (char *)argv[2]+".csv");

    myfile << "input" << "," << "time" << '\n';

    for (int i = 0; i <= Max_Number; i++){
        float function_time = time_func(i, argv[2]);
        myfile << i << "," << std::fixed << std::setprecision(8) << function_time<<'\n';
        
    }
    myfile.close();
    return 0;
}