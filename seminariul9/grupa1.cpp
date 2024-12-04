// Seminar9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Creați clasa Angajat  in C++ de urmatoarele atribute: nume(char *), varsta(int), salariu(double)
Creati constructor, constructor default, destructor
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Angajat {
    char* nume;
    int varsta;
    double salariu;

public:

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

    friend ostream& operator<< (ostream& os, Angajat& ang) {
        os << "Angajatul " << ang.nume << " are " << ang.varsta << " ani si " << ang.salariu << "salariu" << endl;

        return os;
    }

    Angajat& operator++() {
        ++salariu;
        return *this;
    }

    Angajat& operator++(int) {
        ++salariu;
        return *this;
    }

    // getter pentru varsta 
    int getVarsta() {
        return varsta;
    }

    operator int() {
        return varsta;
    }

    operator double() {
        return salariu;
    }

    Angajat&  operator+= (double suma) {
        salariu += suma;
        return *this;
    }
};

int main()
{
    Angajat cr7("Ronaldo", 18, 1000);
    cout << cr7;
   
    
    // pre
    ++cr7;
    cout << cr7;

    // post
    cr7++;
    cout << cr7;

    // varianta cu getter
    int varsta_cr7 = cr7.getVarsta();
    cout << "Varsta lui CR7 este " << varsta_cr7 << endl;

    int varsta_convertita_cr7 = cr7;
    cout << "Varsta lui CR7 este " << varsta_convertita_cr7 << endl;

    double salariu = cr7;

    cout << "Salariul lui CR7 este " << salariu << endl;


    cr7 += 1000; // cr7 = cr7 + 1000
    cout << cr7;

    // Constructor de copiere - copiere in momentul construirii
    Angajat mbappe = cr7;
    
    cout <<"Obiectul Mbappe copiat: " << mbappe;

    Angajat messi("Messi", 17, 2222);
    cout << messi;

    // operator de atribuire
    messi = cr7;

    cout << "Messi dupa atribuire " << messi;

		int y = 5;
	
		
	

int s;
	int n;
	s = (y++ + ++y); 
	cout << "Introduceti va rog frumos raspunsul ala prost din capul dumneavoastra: \n";
	cin >> n;
	if (n!= s)
		cout << "Asa cum credeam esti bou!!!!! \n";
	else
		cout << "Neasteptat!";

}



   