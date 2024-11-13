#include <iostream>
using namespace std;


// 1. Creați o clasă AudioBook care să conțină: 
//  durata în minute (număr întreg)
//  număr de review-uri (întreg) 
//  vector alocat dinamic cu notele primite (numere întregi între 1-5) 
//  o valoare care să contorizeze numărul total de cărți audio din bibliotecă

// 2. Creați constructorul cu parametri și cel default (fără parametri). Inițializați 2 obiecte

// Locatie veche[4, 2, 3, 4]
// Locatie noua [_, _, _, _]

// 3. Adăugați o metodă care calculează rating-ul ca fiind media aritmetică a tuturor review-urilor
// 4. Adăugați la clasă și titlul cărții (șir de caractere alocat dinamic). Schimbați constructorul

class AudioBook{
private:
    char* titlu;
    int durata;
    int nr_note;
    int* note; // memorie alocata dinamic

    //[4, 4, 5, 5]
    // [4, 4, 5, 5, 3]
    
public:
    // static - inseamna ca este o valoarea la nivel de clasa
    static int nr_total;

    // Constructor
    // "Atomic"
    AudioBook(const char* titlu, int durata, int nr_note, int *note): durata(durata), nr_note(nr_note){
        this->titlu = new char[strlen(titlu)+1]; // "Atomic\0"
        strcpy(this->titlu, titlu);

        this->note = new int[nr_note]; // Alocarea spatiului in vectorul meu de note
        for(int i=0;i<nr_note;i++){
            this->note[i] = note[i];
        }
        nr_total++;
        cout << "Constructorul se apeleaza" << endl;
    }
    // Destructor
    ~AudioBook(){
        delete[] note; // Eliberare memorie vector note
        delete[] titlu; // Eliberare memorie vector titlu
        nr_total--;
         cout << "Destructorul se apeleaza" << endl;
    }
    void adaugaNota(int nota_noua){
      // initial [4, 4, 5, 5]

         // aloc un vector cu o marime mai mare decat note (initial)
        int* note_noi =  new int[nr_note + 1]; // [_, _, _, _, _]
       
        for(int i=0;i<nr_note;i++){ 
            note_noi[i] = note[i];  //[4, 4, 5, 5, _]
        }

        note_noi[nr_note] = nota_noua; //[4, 4, 5, 5, 3]
        nr_note++;

        /// initial [4, 4, 5, 5]
        //  nou array [4, 4, 5, 5, 3]

        delete[] note; // Stergere vector initial
        /// initial - null
        //  nou array [4, 4, 5, 5, 3]
        note = note_noi;
    }

    float rating(){
        if (nr_note == 0){
            return 0;
        } 
        float suma = 0;
        for(int i=0;i<nr_note;i++){
            suma += this->note[i]; 
        }
        return suma/nr_note;
    }
        // cout << 10
    friend ostream& operator<<(ostream& os, AudioBook& book);
  
};

ostream& operator<<(ostream& os, AudioBook& book){
        os << "Am suprascris operatorul<< pentru clasa AudioBook" << endl;
        os << "Cartea cu titlul" << book.titlu << endl;
        os << "Cartea cu durata" << book.durata << endl;
        os << "Note";
         for(int i=0;i<book.nr_note;i++){
            os << book.note[i] << " ";
        }
        return os;
}

// fiind la nivel de clasa, nu are nevoie de obiect
int AudioBook::nr_total = 0;


int main(){

     // functie(cout, item2)
    // operator<<
    // cout << item2 << endl;


  

    int note[] = {4, 5, 4, 4, 5, 5}; // array cu 6 elemente
    int durata = 10;
    int nr_elemente = 6;

    cout << "Numar de obiect INAINTE de crearea item1: " << AudioBook::nr_total << endl;

    AudioBook item1("Atomic", durata,nr_elemente, note);

    cout << "Rating:" << item1.rating() << endl;

    cout << "Numar de obiect DUPA de crearea item1: " << AudioBook::nr_total << endl;

    AudioBook item2("University", durata,nr_elemente, note);

    cout << "Numar de obiect DUPA de crearea item2: " << AudioBook::nr_total << endl;

    // functie(cout, item2);
    // functie(cout, endl);
    cout << item2 << endl;
   

    return 0;
}