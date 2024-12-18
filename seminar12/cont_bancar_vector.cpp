/*
Construiti clasa ContBancar care sa reprezinte un cont bancar cu următoarele proprietăți
deținător - string
balanță - valoarea din portofel
listă_tranzactii - vector alocat dinamic (int) [30, -3, 15, 23, 55]
taxaRetragere -cat se plateste cand scoti bani 
Creați constructorul cu parametri și destructorul
Suprascrieti operatorul <<
Suprascrieti operatorii += si -= pentru a adaugă bani în cont 
Suprascrieti operatorul [] pentru a lua o anumită operație
*/

#include <iostream>
using namespace std;

class ContBancar{
    string detinator; // inlocuitor pentru char*
    int balanta;
    vector<int> lista_tranzactii; // vector din STL


    void adaugaTranzactia(int suma){
             // suma sa fie adaugata in lista de tranzactii
        lista_tranzactii.push_back(suma);
    }

public:
    static int taxaRetragere;
    ContBancar(string detinator, int balanta = 0):detinator(detinator), balanta(balanta){
               
    }

    friend ostream& operator<<(ostream& consola, ContBancar& cb){ 
        consola << cb.detinator << " are " << cb.balanta << " lei" << endl;
        consola << "Tranzactii:";
        for (int i = 0; i < cb.lista_tranzactii.size(); i++)
        {
            cout << cb.lista_tranzactii[i] << " ";
        }
        
        return consola;
    }
    // obiect += 20 
    // obiect = obiect + 20
    ContBancar& operator+= (int suma){
        balanta += suma;

       adaugaTranzactia(suma);

        return (*this);
    }


        // obiect += 30
     ContBancar& operator-= (int suma){
        balanta -= suma;

        // suma sa fie adaugata in lista de tranzactii

       adaugaTranzactia(-suma);

        return (*this);
    }

    // obiect [3] -> int
    int operator[] (int index){
        // lista_tranzactii.size -> intoarce numarul total de tranzactii
        if (index < 0 || index >  lista_tranzactii.size()){
            cout << "Index gresit";
        }
        return lista_tranzactii[index];
    }

    int get_tranzactia_cu_numarul(int index) {
         // lista_tranzactii.size -> intoarce numarul total de tranzactii
         if (index < 0 || index > lista_tranzactii.size()){
            cout << "Index gresit";
        }
        return lista_tranzactii[index];
    }

};
int ContBancar::taxaRetragere = 10;

int main(){

    ContBancar cont1("Ion"); // balanta = 0 
    cout << cont1;
    ContBancar cont2("Maria", 30);

    cout << cont2;



    cont2 += 50; //[50] -> lista_tranzactii
    cout << cont2;


    cont2 += 40; // [50, 40] -> lista_tranzactii
    cout << cont2;

    cont2 -= 15; // [50, 40, -15] -> lista_tranzactii
    cout << cont2 << endl;

    int index = 2;
    cout << "Tranzactia de la indexul " << index << " este: " << cont2[index] << endl;
    cout << "Tranzactia de la indexul " << index << " este: " << cont2.get_tranzactia_cu_numarul(index) << endl;
}

// lista_tranzactii

// [50, 40] -> [50, 40, -15]
// [ _, _, _] -> [ 50, 40, _] -> [50, 40, -15]