//
// Created by kasia i kuba on 05.04.17.
//

#include <iostream>
#include <vector>
#include <complex>

int main(){
    std::vector<std::vector<std::complex<double>>> Kasia;
    std::complex<double> element = {0 + 0i};
    std::complex<double> a = {0 + 1i};
    std::complex<double> b = {1.0 + 0i};
    for(int i = 0 ; i<10 ; ++i){
        Kasia.push_back(std::vector<std::complex<double>>());
        for(int j = 0; j<5 ; ++j){
            Kasia[i].push_back(element);
            element = element + a;
        }
        element = element + b;
    }
    std::cout << Kasia[1][2].imag();
    return 0;
}