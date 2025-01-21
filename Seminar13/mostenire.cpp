// https://github.com/sojog/OOP-ASE-2024

#include <iostream>
#include  <string>
using namespace std;

// MOSTENIRE -> ESTE
// FOSTBALISTUL este SPORTIV (mostenire)

// ARE
// ECHIPA are SPORTIV(i)


// Clasa sportiv este ABSTRACTA
class Sportiv {
    string nume;
    int varsta;
public:
    // Inline  - cand sunt constante
    Sportiv(string nume = "Anonim", int varsta = 18):nume(nume), varsta(varsta) {
       // aici cand sunt alocate dinamic
             cout << "Constructorul Sportiv se apeleaza" << endl;
    }
    Sportiv&  operator=(Sportiv& other){
        this->nume = other.nume;
        this->varsta = other.varsta;
        return *this;
    }
    friend ostream&   operator<< (ostream& consola,  Sportiv& obiect) {
        cout << "Sportivul " << obiect.nume << " are " << obiect.varsta << " ani" << endl;
        return consola;
    }
    // Functie virtuala pura - > functia acesta nu are o implementare
    virtual string sportul() = 0;

};

// Clasa Fotbalist este CONCRETA
class Fotbalist: public Sportiv{
    int nr_tricou;
    string pozitie;
public:
    Fotbalist(string nume = "Anonim", int varsta = 18, int nr_tricou=99, string pozitie ="Mijlocas"): Sportiv(nume, varsta) , nr_tricou(nr_tricou), pozitie(pozitie){
        cout << "Constructorul Fotbalist se apeleaza" << endl;
    }
    string sportul(){
        return "Fotbal";
    }

};

class Handbalist:public Sportiv{

public:
    string sportul(){
        return "Handbal";
    }
};

int main()
{ 

    // Sportiv sp_anonim; -> sportivul devine ABSTRACT
    // cout << sp_anonim.sportul() << endl;
    Fotbalist fb_anomin;
    cout << fb_anomin.sportul() << endl;
    Handbalist hb_anomin;
    cout << hb_anomin.sportul() << endl;




}