#include <iostream>
#include  <string>
using namespace std;

// MOSTENIRE -> ESTE
// FOSTBALISTUL este SPORTIV (mostenire)

// ARE
// ECHIPA are SPORTIV(i)

class Sportiv {
    string nume;
    int varsta;
public:
    // Inline  - cand sunt constante
    Sportiv(string nume = "Anonim", int varsta = 18):nume(nume), varsta(varsta) {
       // aici cand sunt alocate dinamic
    }

    // Sportiv obj1;
    // Sportiv obj2;
    // obj2 = obj1;

    Sportiv&  operator=(Sportiv& other){
        this->nume = other.nume;
        this->varsta = other.varsta;
        return *this;
    }

    friend ostream&   operator<< (ostream& consola,  Sportiv& obiect) {

        cout << "Sportivul " << obiect.nume << " are " << obiect.varsta << " ani" << endl;

        return consola;
    }

};

template <int N_Membri>
class Echipa {
  
    Sportiv* membri;

public:

    Echipa(){
        this->membri = nullptr;
    }

    Echipa(Sportiv* membri) {
        this->membri = new Sportiv[N_Membri];
        for (int i =0; i <N_Membri ; i ++ ){
            this->membri[i] = membri[i];
        }

    }
    ~Echipa(){
        delete[] membri;
    }
    int getNumarJucator(){
        return N_Membri;
    }

    friend ostream&   operator<< (ostream& consola,  Echipa<N_Membri>& echipa) {
        for (int i =0; i < N_Membri ; i ++ ){
            cout << "Jucatorul de pe pozitia " <<  i << " este " << echipa.membri[i] << endl;
        }
        return consola;
    }

};

class EchipaFotbal: public  Echipa<11>{

};

class EchipaHandbal: public Echipa<7>{

};

class LotFotbal: public  Echipa<28>{

};


int main()
{
    Sportiv sp_anonim;
    cout << sp_anonim;

    Sportiv sp_tiriac("Ion Tiriac", 90);
    cout << sp_tiriac;  

    // Se creeaza un vector 2 obiect de tip Sportiv cu valori implicite
    // [sportiv_anonim, sportiv_anonim];
    Sportiv* membri = new Sportiv[4];


    // membri[0] = sp_anonim;
    membri[2] = sp_tiriac;



    Echipa<3>  romania(membri);
    cout << romania << endl;

    EchipaFotbal fotbal;
    cout << fotbal.getNumarJucator() << endl;

}

