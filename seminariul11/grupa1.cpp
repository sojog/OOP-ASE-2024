

#include <iostream>
using namespace std;


/*
1. Creați o clasa Animal care are o greutate și varsta. Creati operatorul de afișare <<
2. Creați o clasă derivata Caine. Creati doua obiecte de tipul Animal si Caine.
3. Apelați operatorul de afișare pentru cele două obiecte
4. Suprascrieti operatorul in clasa caine
5. Adaugati un nou atribut nume si refaceti constructorul clasei Caine
6. Creati o noua clasa pisica, faceti mostenire protected
7. Adăugați un nou atribut nume si refaceti constructorul pentru clasa Pisica.
*/

/*
public - accesibil peste tot (in clasa, in clasa mostenita, in afara clasei)
protected - accesibil in clasa, in clasa mostenita
private - accesibil in clasa 

*/



class Animal {
protected:
    float greutate;
    int varsta;
public:
    Animal(float greutate, int varsta) : greutate(greutate), varsta(varsta) {};

    friend ostream&  operator<<(ostream& consola, Animal& obiect) {

        consola << "Operatorul este apelat din clasa Animal" << endl;
        consola << "Animalul are " << obiect.greutate << " kg " << obiect.varsta << " ani " << endl;

        return consola;
    }
};

class AnimalDomestic : public Animal {
protected:
    string nume;
public:
    AnimalDomestic(string nume, float greutate, int varsta) : Animal(greutate, varsta), nume(nume) {};

};



/*
* protected:
    float greutate; -> raman protected
    int varsta; -> raman protected
   public:
     friend ostream&  operator<<(ostream& consola, Animal& obiect) -> public
*/
class Caine : public AnimalDomestic {

public:
    Caine(string nume, float greutate, int varsta) : AnimalDomestic(nume, greutate, varsta) {};
    // Suprascriere
    friend ostream& operator<<(ostream& consola, Caine& obiect) {

        consola << "Operatorul este apelat din clasa Caine" << endl;
        consola << "Cainele " << obiect.nume <<  " are " << obiect.greutate << " kg " << obiect.varsta << " ani " << endl;

        return consola;
    }

};
class CaineBichon : public Caine {
public:
    void descriere() {
        cout << "Cainele Bichon are " << greutate << " kg";


    }
};

/*
* protected:
    float greutate; -> raman protected
    int varsta; -> raman protected
   public:
     friend ostream&  operator<<(ostream& consola, Animal& obiect) -> protected
*/

class Pisica : protected AnimalDomestic {

public:
    Pisica(string nume, float greutate, int varsta) : AnimalDomestic(nume, greutate, varsta) {};
    // Suprascriere
    friend ostream& operator<<(ostream& consola, Pisica& obiect) {

        consola << "Operatorul este apelat din clasa Caine" << endl;
        consola << "Cainele " << obiect.nume << " are " << obiect.greutate << " kg " << obiect.varsta << " ani " << endl;

        return consola;
    }

};

class PisicaSfinx : public Pisica {
public:
    void descriere() {
        cout << "Pisica Sfinx are " << greutate << " kg";


    }
};


/*
* protected:
    float greutate; -> devin private
    int varsta; -> devin private
   public:
     friend ostream&  operator<<(ostream& consola, Animal& obiect) -> private
*/
class Peste : private AnimalDomestic {

public:
    Peste(string nume, float greutate, int varsta) : AnimalDomestic(nume, greutate, varsta) {};
    // Suprascriere
    friend ostream& operator<<(ostream& consola, Peste& obiect) {

        consola << "Operatorul este apelat din clasa Peste" << endl;
        consola << "Peste " << obiect.nume << " are " << obiect.greutate << " kg " << obiect.varsta << " ani " << endl;
        return consola;
    }
};

class PesteApartament : public Peste {

public:
    void descriere() {
        //cout << "Peste de apartament are " << greutate << " kg";


    }
};





int main()
{
    Animal animal1(10, 2);
    AnimalDomestic domestic("Baiatu", 20, 2);

    Caine caine("Rex", 8, 3);

    cout << animal1;
    cout << caine;

    Pisica pisica("Tom", 5, 1);

    cout << pisica;

    Peste peste("Nemo", 1, 1);
    cout << peste;

}
