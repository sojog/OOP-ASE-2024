#define _CRT_SECURE_NO_WARNINGS
/* iostream = ostream + istream */
#include <iostream>

/* file stream */
#include <fstream>

/* string stream */
#include  <sstream>

using namespace std;


class Angajat {
protected:
    char* nume;
    double salariu;
    int varsta;

public:

    // Constructor default
    Angajat() {
        this->nume = new char[strlen("Fara nume") + 1];
        strcpy(this->nume, "Fara nume");
        varsta = 18;
        salariu = 0;
    }


    // Constructor cu parametri
    Angajat(const char* nume, double salariu, int varsta) :salariu(salariu), varsta(varsta) {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    }

    // Destructor
    ~Angajat() {
        delete[] nume;
    }

    friend ostream& operator<< (ostream& ostr, Angajat& ang);
    friend istream& operator>> (istream& istr, Angajat& ang);

    // ++obj - pre incrementare
    Angajat& operator++() {
        ++salariu;
        return *this;
    }

    // obj++ - post incrementare
    Angajat& operator++(int) {
        ++salariu;
        return *this;
    }
    // obiect += 100
    Angajat& operator+= (int suma) {

        salariu += suma;
        return *this;
    }

    double getSalariu() {
        return salariu;
    }

    double getVarsta() {
        return varsta;
    }

    // operator cast
    operator double() {
        return salariu;
    }
    operator int() {
        return varsta;
    }

    // operator de copiere 
    Angajat& operator= (Angajat& sursa) {
        cout << "Operatorul de atribuire este apelat" << endl;
        this->salariu = sursa.salariu;
        this->varsta = sursa.varsta;

        delete[] this->nume;

        this->nume = new char[strlen(sursa.nume) + 1];
        strcpy(this->nume, sursa.nume);

        return *this;
    }

    // constructor de copiere
    Angajat(Angajat& sursa) {
        cout << "Constructorul de copiere este apelat" << endl;
        this->salariu = sursa.salariu;
        this->varsta = sursa.varsta;

        this->nume = new char[strlen(sursa.nume) + 1];
        strcpy(this->nume, sursa.nume);

    }
};
// cout << obj
ostream& operator<< (ostream& ostr, Angajat& ang) {
    ostr << "Angajatul " << ang.nume << " are " << ang.varsta << " ani " << ang.salariu << endl;
    return ostr;
}

istream& operator>> (istream& istr, Angajat& ang) { 

    cout << "Introduceti varsta" << endl;
    istr >> ang.varsta;

    cout << "Introduceti salariul" << endl;
    istr >> ang.salariu;

    char buffer[100];

    cout << "Introduceti numele" << endl;
    istr >> buffer;

    delete[] ang.nume;

    ang.nume = new char[strlen(buffer) + 1];
    strcpy(ang.nume, buffer);


    return istr;
}

/* Mostenire -> Relatii de tipul ESTE / IS A */
/* Angajat -> clasa de baza */
/* AngajatIt -> clasa derivata */

class AngajatIT : public Angajat {

    int reducere;

public:
    AngajatIT() {
        reducere = 10;
    }

    // Constructor cu parametri
    AngajatIT(const char* nume, double salariu, int varsta, int reducere){
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);

        this->salariu = salariu;
        this->varsta = varsta;

        this->reducere = reducere;
    }
    int getReducere() {
        return reducere;
    }
};

int main() {
   
    AngajatIT itist;
    cout << itist;

    cout << itist.getSalariu() << endl;
    cout << itist.getVarsta() << endl;

    AngajatIT carlo("Carlo Ancelotti", 59, 5555, 10);
    cout << carlo << endl;

    Angajat special("Jose Mourinho", 6000, 60);
    cout << special.getReducere() << endl;


}


void lucru_operatori()
{   
    // Constructor cu parametri
    Angajat m10("Messi", 1000, 38);
    cout << m10;

    // Constructor de copiere
    Angajat yamal = m10;
    cout << "Obiectul creat prin constructor de copiere " << yamal;

    // Operatorul de atribuire
    Angajat ansu("Ansu Fati", 333, 20);
    cout << "Obiectul inainte de a folosi operatorul = " << ansu;

    ansu = m10;
    cout << "Obiectul dupa de a folosi operatorul = " << ansu;

    ofstream fisier("angajat.txt");
    if (fisier.is_open()) {

        fisier << "Acesta este un text de test" << endl;
        fisier << ansu << endl;

        fisier.close();
    }

    ofstream fisierScriere("obiect.txt");
    if (fisierScriere.is_open()) {

        fisierScriere << ansu.getSalariu() << endl;
        fisierScriere << ansu.getVarsta() << endl;
        fisierScriere.close();
    }

    ifstream fisierCitire("obiect.txt");
    if (fisierCitire.is_open()) {
        
        string linie;
        getline(fisierCitire, linie);

        double salariu = stod(linie);
        cout << "Salariul citit din fisier este:" << salariu << endl;

        getline(fisierCitire, linie);
        int varsta = stoi(linie);
        cout << "Varsta citita din fisier este:" << varsta << endl;

        fisierCitire.close();
    }




 /*   cin >> ansu; */
    cout << ansu;

}



