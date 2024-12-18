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
    int* lista_tranzactii; // vector alocat dinamic
    int nr_tranzactii;

    void adaugaTranzactia(int suma){
             // suma sa fie adaugata in lista de tranzactii
        if (nr_tranzactii > 0){

            int *temp = new int[nr_tranzactii+1];
            for (int i = 0; i < nr_tranzactii; i++)
            {
               temp[i] = lista_tranzactii[i];
            }
            temp[nr_tranzactii] = suma;
            
            delete[] lista_tranzactii;
            lista_tranzactii = temp;

        } else {
            lista_tranzactii = new int[1];
            lista_tranzactii[0] = suma;
        }
        nr_tranzactii++;
    }


public:
    static int taxaRetragere;
    ContBancar(string detinator, int balanta = 0):detinator(detinator), balanta(balanta){
        lista_tranzactii = nullptr;
        nr_tranzactii = 0;
    }

    friend ostream& operator<<(ostream& consola, ContBancar& cb){ 
        consola << cb.detinator << " are " << cb.balanta << " lei" << endl;
        consola << "Tranzactii:";
        for (int i = 0; i < cb.nr_tranzactii; i++)
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

    ~ContBancar(){
        delete[] lista_tranzactii;
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
        if (index < 0 || index > nr_tranzactii){
            cout << "Index gresit";
        }
        return lista_tranzactii[index];
    }

    int get_tranzactia_cu_numarul(int index) {
         if (index < 0 || index > nr_tranzactii){
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