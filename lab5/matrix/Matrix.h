//
// Created by kasia i kuba on 05.04.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <complex>
#include <vector>
#include <initializer_list>

namespace algebra {

    class Matrix {
    public:
        Matrix();
        Matrix(int wiersze, int kolumny);
        Matrix(const std::initializer_list<std::vector<std::complex<double>>> &element) : macierz_(element){

        }
        ~Matrix();
        Matrix Add(Matrix m2) const;
        Matrix Sub(Matrix m2);
        Matrix Mul(Matrix m2);
        Matrix Mul(std::complex<double> wzmocnienie);
        //Tu powinno byc Div ale na razie odpuszczamy
        Matrix Pow(int potega);
        std::string Print() const;
        std::pair<size_t , size_t > Size();
    private:
        std::vector<std::vector<std::complex<double>>> macierz_;
    };
}
#endif //JIMP_EXERCISES_MATRIX_H
