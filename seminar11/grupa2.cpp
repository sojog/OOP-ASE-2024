/*
1. Creați o clasa Animal care are o greutate și varsta. Creati operatorul de afișare <<
2. Creați o clasă derivata Caine. Creati doua obiecte de tipul Animal si Caine.
3. Apelați operatorul de afișare pentru cele două obiecte


6. Creati o noua clasa pisica, faceti mostenire protected
7. Adăugați un nou atribut nume si refaceti constructorul pentru clasa Pisica.
*/

/*
public    -  accesibil in clasa, in clasa mostenita, in afara clasei
protected -  accesibil in clasa, in clasa mostenita
private   -  accesibil in clasa
*/

/* https://dontpad.com/oop11 */

#include <iostream>
using namespace std;

/* Clasa de baza, clasa din care se mosteneste, clasa parinte */
class Animal {
protected:
	float greutate;
	int varsta;
public:
	
	Animal(float greutate, int varsta) : greutate(greutate), varsta(varsta) {
		cout << "Constructorul din Animal este apelat" << endl;
	}

	// aici este public
	friend ostream& operator<< (ostream& consola, Animal& obiect) {

		cout << "operatorul<< este apelat pe Obiectul Animal" << endl;
		cout << "Are " << obiect.greutate << " kg si " << obiect.varsta << " ani" << endl;

		return consola;
	}
	
	void descriere() {
		cout << "descriere este apelata in animal";
	}
};


/* Clasa care mosteneste, derivata, clasa copil */
class Caine : public Animal {

	string nume;

public:
	Caine(string nume, float greutate, int varsta) : Animal(greutate, varsta), nume(nume) {
		cout << "Constructorul din Caine este apelat" << endl;
	}

	// suprascriere - overwriting
	friend ostream& operator<< (ostream& consola, Caine & obiect) {
		cout << "operatorul<< este apelat pe Obiectul Caine" << endl;
		cout << obiect.nume << " are " << obiect.greutate << " kg si " << obiect.varsta << " ani" << endl;
		return consola;
	}
};

class Pisica : protected Animal {
	string	nume;
public:
	Pisica(string nume, float greutate, int varsta) : Animal(greutate, varsta), nume(nume) {
		cout << "Constructorul din Pisica este apelat" << endl;
	}

	 //suprascriere - overwriting
	friend ostream& operator<< (ostream& consola, Pisica& obiect) {
		cout << "operatorul<< este apelat pe Obiectul Pisica" << endl;
		cout << obiect.nume << " are " << obiect.greutate << " kg si " << obiect.varsta << " ani" << endl;
		obiect.descriere();
		return consola;
	}
};

class Peste : private Animal {
	string nume;
public:
	Peste(string nume, float greutate, int varsta) : Animal(greutate, varsta), nume(nume) {
		cout << "Constructorul din Peste este apelat" << endl;
	}

	//suprascriere - overwriting
	friend ostream& operator<< (ostream& consola, Peste& obiect) {
		cout << "operatorul<< este apelat pe Obiectul Peste" << endl;
		cout << obiect.nume << " are " << obiect.greutate << " kg si " << obiect.varsta << " ani" << endl;
		obiect.descriere();
		return consola;
	}
};

class PesteDeApartament : public Peste {

public:
	//void test() {
	//	descriere();  - nu este accesibil
	//}

};

int main()
{
   
	Animal animal(32, 5);
	cout << animal;
	animal.descriere();

	Caine caine("Rex", 10, 2);
	cout << caine;

	caine.descriere();

	Pisica pisica("Tom", 3, 20);
	cout << pisica;
	// pisica.descriere(); - nu o pot folosi, este protected

	Peste peste("Nemo", 1, 1);
	cout << peste;
	//peste.descriere(); - nu o pot folosi este private

}
