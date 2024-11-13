// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// Creati o clasa Culoare pentru a reprezenta o culoare de tip RGB. 
// Culoarea va avea 3 atribute: rosu, verde, albastru.

class Culoare {
private:
    int rosu;
    int verde;
    int albastru;
    bool isValidValue(int newValue) {
        return ((newValue >= 0) && (newValue <= 255));
    }

public:
   
    int getRosu() {
         return rosu;
    }
    void setRosu(int newValue) {
        if (isValidValue(newValue))
            rosu = newValue;
    }
    int getAlbastru() {
        return albastru;
    }
    void setAlbastru(int newValue) {
        if (isValidValue(newValue))
            albastru = newValue;
    }
    int getVerde() {
        return verde;
    }
    void setVerde(int newValue) {
        if (isValidValue(newValue))
            verde = newValue;
    }
    // constructor - cu 3 parametri
   Culoare(int rosu, int verde, int albastru) {
       if (isValidValue(rosu))
            this->rosu = rosu;
       if (isValidValue(verde))
            this->verde = verde;
       if (isValidValue(albastru))
            this->albastru = albastru;
    }


    // Construiti o functie de validare valorilor. Ele trebuie sa fie intre 0 si 255
   /*Culoare(int r, int v, int a):rosu(r), verde(v), albastru(a) {
      
   }*/
    // constructor - default / fara parametri
    Culoare() {
        rosu = 0;
        verde = 0;
        albastru = 0;
    }
};

// Construiti setter si getter
int main()
{   // Construiti 2 obiecte de tipul Culoare
    Culoare c1(1, 1, 2);
    Culoare c2(2, 2, 3);
    Culoare neagra;
    cout << "Culoarea neagra" << neagra.getRosu() << neagra.getVerde() << neagra.getAlbastru() << endl;


    cout << "Rosu" << c1.getRosu() << endl;
    cout << "Verde" << c1.getVerde() << endl;
    cout << "Albastru" << c1.getAlbastru() << endl << endl;
    
    c1.setRosu(30000);
    cout << "Rosu" << c1.getRosu() << endl;
    c1.setVerde(40);
    cout << "Verde" << c1.getVerde() << endl;
    c1.setAlbastru(50);
    cout << "Albastru" << c1.getAlbastru() << endl;


    //c1.rosu = 30; - nu mai poate fi folosit fiindca este privat
    //cout << "Rosu=" << c1.rosu << endl;
}


