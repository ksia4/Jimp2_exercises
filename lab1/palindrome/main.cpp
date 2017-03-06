//
// Created by kasia on 05.03.17.
// Zadanie - Palindrom - Katarzyna Rugiełło, Jakub Kleszcz
//

#include <iostream>
#include <string.h>
#include "Palindrome.h"

using namespace std;
int main() {
    int wy;
    cout << "WItam w programie sprawdzającym czy podany napis jest palindromem \nAby wpisać palindrom wciśnij 1\n Aby zakończyć wciśnij0\n";
    cin>>wy;
    cin.sync();
    string text;
    //bool czy;
    while(wy == 1){
        cout << "Proszę wpisać tekst\n";
        cin.sync();
        getline(cin,text,' ');
        if(is_palindrome(text)){
            cout << text << " Jest palindromem\n";
        }
        else{
            cout << text << " Nie jest palindromem\n";
        }
        cout << "Aby sprawdzić kolejny palindrom wciśnij 1, by zakończyć wciśnij 0\n";
        cin >> wy;
    }
    return 0;
}