// Construiti clasa ContBancar care sa reprezinte un cont bancar cu următoarele proprietăți
    // deținător - un vector alocat dinamic
    // balanță - valoarea din portofel
    // taxaRetragere -cat se plateste cand scoti bani 
// Clasa deţine următoarele implementari cu verificarile necesare:
    // retragere - se scot bani din portofel
    // adaugaBani - se adaga bani in portofel
    // arataBalanta - se printeaza balanta curenta

#include <iostream>
using namespace std;



class ContBancar{
    private:
    // CE ARE
        // deținător - un vector alocat dinamic
        char* detinator;
        // balanță - valoarea din portofel
        double balanta;
        
    public:
        // taxaRetragere -cat se plateste cand scoti bani 
        static double taxaRetragere;

        ContBancar(const char *detinator, double balantaInitiala):balanta(balantaInitiala){
            // alocarea spatiului in memorie [_, _, _, _ ]
            this->detinator = new char[strlen(detinator)+1]; // lungimea + '\0'
            // strcpy -> ['I', 'O', 'N', '\0'] -> [_, _, _, _ ] -> ['I', 'O', 'N', '\0']
            strcpy(this->detinator, detinator);
        }
        ~ContBancar(){
            delete[] this->detinator;
        }


    // CE FACE
        void  retragere(double suma){
            if (suma <=0){
                cout << "Suma invalida pentru retragere" << endl;
                return;
            }
            double sumaDebitata = suma + taxaRetragere;
            if (sumaDebitata > balanta){
                cout << "Fonduri insuficiente"  << endl;
                return;
            }
            balanta -= sumaDebitata;

        }

        void adaugaBani(double suma){
             if (suma <=0){
                cout << "Suma invalida pentru retragere";
                return;
            }
            balanta += suma;
        }

        // ++ -> operator unar
        // obiect++ sau ++obiect
 
        // ++obiectul  -> prefix
        ContBancar& operator++ (){
            balanta += 1;
            return *this;
        }

        // obiectul++ -> postfix
        ContBancar& operator++ (int){
            balanta += 1;
            return *this;
        }
        // obiect += 10
        ContBancar&  operator+= (double suma){
            if (suma <=0){
                cout << "Suma invalida pentru retragere";
                return *this;
            }
            balanta += suma;
            return *this;
        }
        // obiect -= 10
        ContBancar&  operator-= (double suma){
            if (suma <=0){
                cout << "Suma invalida pentru retragere" << endl;
                return *this;
            }
            double sumaDebitata = suma + taxaRetragere;
            if (sumaDebitata > balanta){
                cout << "Fonduri insuficiente"  << endl;
                return *this;
            }
            balanta -= sumaDebitata;
            return *this;
        }
        void arataBalanta(){
            cout << "Balanta =" << balanta << endl;
        }
        // operator binar 
        // cout << obiect
        friend ostream&  operator<<(ostream& out, ContBancar& cont){
            out << "Am suprascris operatorul operator<<" << endl;
            out << cont.detinator << " are " << cont.balanta << "lei" << endl;
            return out;
        }

        friend istream&  operator>>(istream& in, ContBancar& cont){ 
            cout << "Introduceti numele utilizatorului" << endl;

            char temp[100];
            in >> temp;

            delete[] cont.detinator;
            cont.detinator = new char[strlen(temp) + 1];   //[i, o, n, _, _, _, _, _]
            strcpy(cont.detinator, temp);

            return in;
        }
};

double ContBancar::taxaRetragere = 3;



int main(){
    ContBancar cont_ion("Ion", 0);
    ContBancar cont_maria("Maria", 10);

    cont_ion.arataBalanta();
    cont_ion.retragere(10);
    cont_ion.adaugaBani(30);

    cont_ion.arataBalanta();
    cout << cont_ion;
    
    cout << cont_maria;

    // cin >> cont_ion;
    cout << cont_ion;

    ++cont_ion; // ContBancar& operator++
    cont_ion++;
    cout << cont_ion; 

    cont_ion += 600;
    cout << cont_ion;

    cont_ion -= 30;
    cout << cont_ion;


}

