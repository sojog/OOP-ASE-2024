// Seminar3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// https://dontpad.com/sem3oop
//Trebuie creată clasa Calculator cu două proprietăţi : 
// operand1 şi operand2.
// Clasa deţine următoarele metode :
//add - ca rezultat returnează suma celor doi operanzi;
// sub - ca rezultat returnează diferenţa celor doi operanzi;
// mul - ca rezultat returnează produsul celor doi operanzi;
// div - ca rezultat returnează împărțirea celor doi operanzi.



class Calculator {
private:
    int operand1;
    int operand2;
public:

    void setOperand1(int op1) {
        operand1 = op1;
            
    }
    void setOperand2(int op2) {
        operand2 = op2;
    }

    int add(){
        return operand1 + operand2;
    }
    int sub() {
        return operand1 - operand2;
    }
    int mul() {
        return operand1 * operand2;
    }
    float div() {
        return operand1 / operand2;
    }
};





// Clasa este un sablon/template;
// conventie - clasa cu litera mare
class Student {
    bool isMale;
public:
    // atribute  - variabile ale obiectului
    // ce ARE obiectul
    // conventie - atributele incep cu litera mica
    int varsta_std;
    float media_std;

    // metoda = functie a obiectului
    // ce FACE obiectul
    // conventie - metodele incep cu litera mica
    void printStudentSilitor() {
        if (media_std > 8.5) {
            cout << "Studentul este silitor" << endl;
        }
        else {

            cout << "Studentul mai trebuie sa invete" << endl;
        }

    }

    // setter
    void setIsMale(bool newValue) {
        isMale = newValue;

    }

    //getter 
    bool getIsMale() {
        return isMale;
    }

    bool promoveaza() {
        return  (media_std >= 5);


       //return  (media_std >= 5) ? true : false;
        
       /* if (media_std >= 5) {
            return true;
        }
        else {
            return false;
        }*/
    }


};


int main()
{  
    Calculator calc;
    calc.setOperand1(10);
    calc.setOperand2(5);

    cout << "Adunare: " << calc.add() << endl;
    cout << "Scadere: " << calc.sub() << endl;
    cout << "Inmultire: " << calc.mul () << endl;
    cout << "Impartire: " << calc.div() << endl;


}


void logica_student(){

    // Variabile globale
    int varsta = 24;
    int media;
    media = 7.5;
    cout << "Varsta =" << varsta << endl;
    cout << "Media =" << media << endl;

    // obiect/instanta - concretizarea clasei 
    Student stud1;
    stud1.varsta_std = 19;
    cout << "Varsta studentului 1 este" << stud1.varsta_std << endl;
    stud1.media_std = 9.2;
    cout << "media primului student este" << stud1.media_std << endl;

    Student stud2;
    stud2.varsta_std = 22;
    cout << "Varsta studentului 2 este" << stud2.varsta_std << endl;
    stud2.media_std = 4.2;
    cout << "media primului student este" << stud2.media_std << endl;



    stud1.printStudentSilitor();
    stud2.printStudentSilitor();

    stud1.setIsMale(true);
    stud2.setIsMale(false);

    
    cout << "Studentul 1 este male?" << stud1.getIsMale() << endl;
    cout << "Studentul 2 este male?" << stud2.getIsMale() << endl;

    cout << "Studentul 1 promoveaza??" << stud1.promoveaza() << endl;
    cout << "Studentul 2 promoveaza??" << stud2.promoveaza() << endl;

}
