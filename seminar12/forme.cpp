/*
Construiți o clasa Paralelogram, care are o inaltime, o latime si un unghi si o metoda de calculat aria. Creeaza clasele mostenite Dreptunghi, Romb si Patrat.
*/
#include <iostream>
using namespace std;

class Paralelogram {

protected:
    int inaltime;
    int latime;
    int unghi;

public:

    Paralelogram(int inaltime, int latime, int unghi): inaltime(inaltime), latime(latime), unghi(unghi){
    }


    virtual int aria(){
        cout << "Aria este chemata din clasa Paralelogram" << endl;
        return inaltime * latime;
    }

    int perimetru(){
        return 2 * (inaltime + latime);
    }

    // in spate creeaza o tabela Vtable 
    virtual void printeaza(){
        cout << "Obiectul de tip Paralelogram are latimea:" << latime << " inaltimea: " << inaltime << " unghiul: " << unghi << endl;  
    }

    virtual void calcul(){
        cout << "Obiectul Paralelogram are aria: " << this->aria() <<  " si perimetrul " << this->perimetru() << endl;
    }

};




class Dreptunghi: public Paralelogram {

public:
    Dreptunghi(int inaltime, int latime): Paralelogram(inaltime, latime, 90) {
    }

    // Overwriting
    int aria(){
        cout << "Aria este chemata din clasa Dreptunghi" << endl;
        return inaltime * latime;
    }

    // Overwriting - suprascriere
    void printeaza() override {
        cout << "Obiectul de tip Dreptunghi are latimea:" << latime << " inaltimea: " << inaltime << endl;  
    }

     virtual void calcul(){
        cout << "Obiectul Dreptunghi are aria: " << this->aria() <<  " si perimetrul " << this->perimetru() << endl;
    }

};

class Romb: public Paralelogram{
public:
    Romb(int latura, int unghi): Paralelogram(latura, latura, unghi) {
    }

        // Overwriting - suprascriere
    void printeaza() override{
        cout << "Obiectul de tip Romb are latura:" << latime << " si unghiul: " << unghi << endl;  
    }

     virtual void calcul(){
        cout << "Obiectul Romb are aria: " << this->aria() <<  " si perimetrul " << this->perimetru() << endl;
    }
};

class Patrat: public Paralelogram{
public:
    Patrat(int latura):Paralelogram(latura, latura, 90){

    }
    void printeaza() override{
        cout << "Obiectul de tip Patrat are latura:" << latime << endl;  
    }
};


// Conceptul de polimorfism  -> poli=mai multe  ; morphos -> forma
// conversie de la Un tip mostenit la un tip de baza
// printeazaObiect(patrat) -> Conversie de la Patrat la Paralelogram
void printeazaObiect(Paralelogram& obiect){
    obiect.printeaza();
}


/* Creati o functie globala care sa printeze aria si perimetrul obiectelor de tip Paralelogram (aici includem si Patrat/Dreptunghi/Romb)*/

int main()
{
    Paralelogram paralel(10, 10, 78);
    Dreptunghi drep1 (20, 30);

    Romb romb(20, 120);
    Patrat patrat(30);

    //printeazaObiect(patrat);

    drep1.calcul();



    // cout << d1.aria() << endl;
    // cout << romb.aria() << endl;
    // cout << patrat.aria() << endl;




    return 0;
}
