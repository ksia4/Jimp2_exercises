//
// Created by kasia i kuba on 05.04.17.
//

#include "Matrix.h"
#include <sstream>
#include <iostream>
using namespace algebra;

Matrix::Matrix() {

}

Matrix::Matrix(int wiersze, int kolumny) {

}

Matrix::~Matrix() {

}

Matrix Matrix::Add(Matrix m2) const{
    Matrix wynik;
    for(int i = 0 ; i<macierz_.size() ; ++i){
        wynik.macierz_.push_back(std::vector<std::complex<double>>());
        for(int j = 0 ; j < macierz_[i].size() ; ++j){
            wynik.macierz_[i].push_back(macierz_[i][j] + m2.macierz_[i][j]);
        }
    }
    return wynik;
}

Matrix Matrix::Sub(Matrix m2) {
    Matrix wynik;
    for(int i = 0 ; i<macierz_.size() ; ++i){
        wynik.macierz_.push_back(std::vector<std::complex<double>>());
        for(int j = 0 ; j < macierz_[i].size() ; ++j){
            wynik.macierz_[i].push_back(macierz_[i][j] - m2.macierz_[i][j]);
        }
    }
    return wynik;
}

Matrix Matrix::Mul(Matrix m2) {
    Matrix wynik;
    if(macierz_[0].size() == m2.macierz_.size()) {
        for (int i = 0; i < macierz_.size(); ++i) {
            wynik.macierz_.push_back(std::vector<std::complex<double>>());
            for (int j = 0; j < m2.macierz_[0].size(); ++j) {
                std::complex<double> tempsum = {0 + 0i};
                for (int k = 0; k < macierz_[i].size(); ++k) {
                    tempsum = tempsum + ((macierz_[i][k]) * (m2.macierz_[k][j]));
                }
                wynik.macierz_[i].push_back(tempsum);
            }
        }
    }
        return wynik;
}

Matrix Matrix::Mul(std::complex<double> wzmocnienie) {
    Matrix wynik;
    for(int i = 0 ; i<macierz_.size() ; ++i){
        wynik.macierz_.push_back(std::vector<std::complex<double>>());
        for(int j = 0 ; j < macierz_[i].size() ; ++j){
            wynik.macierz_[i].push_back(wzmocnienie*macierz_[i][j]);
        }
    }
    return wynik;
}

Matrix Matrix::Pow(int potega) {
    Matrix wynik;
    if(potega == 0){
        for(int i = 0 ; i<macierz_.size() ; ++i){
            wynik.macierz_.push_back(std::vector<std::complex<double>>());
            for(int j = 0 ; j < macierz_[i].size() ; ++j){
                if(i==j)
                    wynik.macierz_[i].push_back({1 + 0i});
                else
                    wynik.macierz_[i].push_back({0 + 0i});
            }
        }
    }
    else{
        wynik.macierz_ = macierz_;
        for(int i = 0 ; i<potega-1 ; ++i){
            wynik = wynik.Mul(*this);
        }
    }
    return wynik;
}

std::string Matrix::Print() const{
    std::string matlab = "[";
    std::stringstream conv;
    if(macierz_.size() != 0) {
        for (int i = 0; i < macierz_.size(); ++i) {
            for (int j = 0; j < macierz_[i].size(); ++j) {
                conv << macierz_[i][j].real();
                matlab = matlab + conv.str() + "i";
                conv.str("");
                conv << macierz_[i][j].imag();
                matlab = matlab + conv.str();
                conv.str("");
                if (j == macierz_[i].size() - 1 && i != macierz_.size() - 1)
                    matlab = matlab + "; ";
                else if (j == macierz_[i].size() - 1 && i == macierz_.size() - 1)
                    matlab = matlab + "]";
                else
                    matlab = matlab + ", ";
            }
        }
        return matlab;
    }
    else{
        return "[]";
    }
}

std::pair<size_t, size_t> Matrix::Size() {
    std::pair<size_t, size_t > rozmiar;
    size_t wiersze = macierz_.size();
    size_t kolumny = 0;
    if(wiersze == 0)
        kolumny = 0;
    else
        kolumny = macierz_[0].size();
    rozmiar = {wiersze,kolumny};
    return rozmiar;
}

