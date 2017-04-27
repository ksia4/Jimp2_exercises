//
// Created by usuryjskij on 26.04.17.
//

#include <iostream>
#include <Point3D.h>

int main(void){

    /*ZADANIE 5
     W pierwszej kolejnosci wywoluja sie konstruktory klasy bazowej - tutaj klasy Point
     Nastepnie wywolywane sa konstruktory klasy pochodnej - tutaj klasy Point3D
     Destruktowy wywolywane sa w odwrotnej kolejnosci
     Dzieje sie tak, poniewaz klasa pochodna jest jednoczesnie klasa bazowa, dlatego nie mozna
     utworzyc jej obiektu bez wczesniejszego utworzenia obiektu klasy bazowej*/

    Point3D punkt1(1,1,1);
    Point3D punkt2(0,0,0);
    std::cout << punkt1.Distance(punkt2) << std::endl;

    /*ZADANIE 6
     Ponizszy kod spowoduje obliczenie dystansu pomiedzy punktem 2D i wspolrzednymi X i Y punktu 3D
     Dzieje sie tak, poniewaz obiekt punkt3d jest tak naprawde obiektem klasy Point (2D) z dobudowanymi
     metodami i polami klasy Point3D
     wywolanie metody punkt3d.Distance(punkt2d) nie jest mozliwe, gdyz punkt2d nie jest obiektem klasy Punkt3D*/
    Point punkt2d(0,0);
    Point3D punkt3d(1,1,1);
    std::cout << punkt2d.Distance(punkt3d) << std::endl;

    /*ZADANIE 7
     Analogicznie do poprzedniego zadania:
     Obiekt klasy Punkt3D jest jednoczesnie obiektem klasy Point, wiec przeciazenie zadziala identycznie
     jak dla obiektu klasy Point - wypisane zostana koordynaty X i Y*/
    Point3D p3d(1,2,3);
    std::cout << p3d << std::endl;

    
    return 0;
}