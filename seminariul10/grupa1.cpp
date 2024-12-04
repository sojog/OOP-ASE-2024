// Seminar10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
/* 
    ostream + istream = iostream

    ostream - output stream
    istream - input stream
*/
#include <iostream>

/* fstream - file stream */
#include <fstream>

/* string stream */
#include <sstream>

using namespace std;

class Angajat {
protected:
    char* nume;
    int varsta;
    double salariu;

public:

    // Constructor fara parametri
    Angajat() {
        this->nume = new char[strlen("Fara nume") + 1];
        strcpy(this->nume, "Fara nume");
        varsta = 18;
        salariu = 100;
    }


    // Constructor cu parametri
    Angajat(const char* nume, int varsta, double salariu) : varsta(varsta), salariu(salariu) {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    }

    // Constructor de copiere
    // Angajat mbappe = cr7;
    Angajat(const Angajat& sursa) {
        this->varsta = sursa.varsta;
        this->salariu = sursa.salariu;
        this->nume = new char[strlen(sursa.nume) + 1];
        strcpy(this->nume, sursa.nume);
    }

    // mbapp = cr7;
    Angajat& operator= (const Angajat& sursa) {

        delete[] this->nume;

        this->varsta = sursa.varsta;
        this->salariu = sursa.salariu;
        this->nume = new char[strlen(sursa.nume) + 1];
        strcpy(this->nume, sursa.nume);

        return *this;
    }


    ~Angajat() {
        delete[] nume;
    }

   

    // prefixare
    // ++obiect
    Angajat& operator++() {
        ++salariu;
        return *this;
    }

    // postfixare
    // obiect++
    Angajat& operator++(int) {
        ++salariu;
        return *this;
    }

    // getter pentru varsta 
    int getVarsta() {
        return varsta;
    }

    // getter pentru salariu
    double getSalariu() {
        return salariu;
    }

    // conversie sau cast? - catre int
    operator int() {
        return varsta;
    }

    // conversie catre double
    operator double() {
        return salariu;
    }

    // ex: obiect += 100
    Angajat& operator+= (double suma) {
        salariu += suma;
        return *this;
    }

    // cout << obiect
    friend ostream& operator<< (ostream& os, Angajat& ang) {
         os << "Angajatul " << ang.nume << " are " << ang.varsta << " ani si " << ang.salariu << "salariu" << endl; 

        //os << ang.nume << endl << ang.varsta << endl << ang.salariu << endl;

        return os;
    }

    // cin >> obiect
    friend istream& operator>> (istream& consola, Angajat& ang) { 
        
        char buffer[100];

        cout << "Introduceti numele " << endl;

        consola >> buffer;
        delete[] ang.nume;

        ang.nume = new char[strlen(buffer) + 1];
        strcpy(ang.nume, buffer);

        cout << "Introduceti varsta " << endl;

        consola >> ang.varsta;

        cout << "Introduceti salariul " << endl;

        consola >> ang.salariu;

        return consola;
    }

};

/* Mostenire -> pe o relatie de tipul ESTE / IS A */
class AngajatIT : public Angajat {

    int reducere;

public:

    AngajatIT() {

    }

    AngajatIT(const char* nume, int varsta, double salariu, int reducere) {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
        this->salariu = salariu;
        this->reducere = reducere;
  
    }

    int getReducere() {
        return reducere;
    }

};

int main()
{ 
    AngajatIT obiect;
    cout << obiect;
    obiect++;
    cout << obiect;

    int varsta = obiect.getVarsta();
    cout << varsta;

    AngajatIT carlo("Carlo Ancelotti", 59, 55555, 10);
    cout << "Reducerea IT" << carlo.getReducere();

    Angajat mourinho("Jose Mourinho", 60, 666);
}



void logica_operatori()
{
    // Constructor cu parametri
    Angajat m10("Messi", 37, 1000);

    // Constructor de copiere
    Angajat yamine = m10;
    cout << yamine << endl;

    // Operator de asignare?
    Angajat ansu("Ansu Fati", 18, 100);
    cout << "Obiectul inainte de asignare " << ansu << endl;

    ansu = m10;
    cout << "Obiectul dupa de asignare " << ansu << endl;

    /* crearea unui file handler */
    ofstream fisier("angajat.txt");
    
    if (fisier.is_open()) {
        cout << "Fisierul a putut fi deschis" << endl;
        
        //fisier << m10 << endl;

        fisier << m10.getVarsta() << endl;
        fisier << m10.getSalariu() << endl;

        fisier.close();
    }

     /* Citire din fisier */
    ifstream fisierCitire("angajat.txt");
    if (fisierCitire.is_open()) {
        
        string linie;
        getline(fisierCitire, linie);

        int varsta = stoi(linie);
        cout << "Varsta citita din fisier este:" << varsta << endl;

        getline(fisierCitire, linie);
        double salariu = stod(linie);
        cout << "Salariul citita din fisier este:" << salariu << endl;
    }



    // cin >> obiect

    //cin >> ansu;

    cout << ansu;

}
