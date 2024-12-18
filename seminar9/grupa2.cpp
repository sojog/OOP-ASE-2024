#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


class Angajat {

    char* nume;
    double salariu;
    int varsta;

public:
    Angajat(const char* nume, double salariu, int varsta) :salariu(salariu), varsta(varsta) {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    }

    ~Angajat() {
        delete[] nume;
    }
    friend ostream& operator<< (ostream& ostr, Angajat& ang);
   
    
    // ++obj - pre incrementare
    Angajat& operator++() {
        ++salariu;
        return *this;
    }

    // obj++ - post incrementare
    Angajat& operator++(int ) {
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


int main()
{
    Angajat mickey("Mickey Mouse", 3500, 22);
    cout << mickey;

    // pre incrementare
    ++mickey; 
    cout << mickey;

    // post incrementare
    mickey++; // obiect ++ 
    cout << mickey;


    mickey += 100;
    cout << mickey;

    double salariu_getter = mickey.getSalariu();
    cout << salariu_getter << endl;

    double salariu_cast = mickey;
    cout << salariu_cast << endl;

    int varsta = mickey;
    cout << varsta << endl;

    Angajat donald("Donald Duck", 4000, 22);
    cout << donald;

    int a = 3;
    int b = 5;
    a = b;

    cout << "a=" << a;

    // this = sursa;
    
    // Operator de copiere - obiectul in care se copie exista deja
    mickey = donald;
    cout <<"Dupa copiere " << mickey << endl;

    int x = 3;
    int y = x;
    // Constructor de copiere - obiectul este creat in momentul copierii
    Angajat minnie = donald;
    cout << "Dupa constructorul de copiere" << minnie << endl;
}
