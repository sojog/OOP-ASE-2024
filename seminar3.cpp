// Seminar3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;



// Clasa este un sablon (template)
// Conventie - litera mare
class Student {
private:
    bool isMale;
public:
    // atribute -> CE ARE
    // Conventie - litera mica
    int varsta_std;
    float media_std;

    // metode (functii ale obiectului) -> CE FACE
    // Conventie - litera mica
    void printStudentSilitor() {

        if (media_std > 8.5) {
            cout << "Studentul este silitor pentru ca media lui este" << media_std << endl;
        }
        else {
            cout << "Studentul trebuie sa mai invete pentru ca media lui este" << media_std << endl;
       
        }
    }
    //setter
    void setIsMale(bool newValue) {
        isMale = newValue;
    }
    // getter
    bool getIsMale() {
        return isMale;
    }
    bool promoveaza() {
        return media_std >= 5;
        //return media_std >= 5 ? true : false;

        /*     if (media_std >= 5) {
                 return true;
             }
             else {
                 return false;
             }*/
    }
};


/*
Trebuie creată clasa Calculator cu două proprietăţi : operand1 şi operand2.Clasa deţine următoarele metode :
add - ca rezultat returnează suma celor doi operanzi;
sub - ca rezultat returnează diferenţa celor doi operanzi;
mul - ca rezultat returnează produsul celor doi operanzi;
div - ca rezultat returnează împărțirea celor doi operanzi.

*/


class Calculator {
    int operand1;
    int operand2;
public:

   
    int add() {
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
    void setOperand1(int op1) {
        operand1 = op1;
    }
    void setOperand2(int op2) {
        operand2 = op2;
    }
}; 
int main()
{

    Calculator calc;
    calc.setOperand1(10);
    calc.setOperand2(5);
    cout << "Adunare" << calc.add() << endl;
    cout << "Scadere" << calc.sub() << endl;


}

void logica_student(){
    int varsta;
    float media; 
    
    varsta = 19;
    media = 7.5;

    cout << "varsta =" << varsta << endl;
    cout << "media = " << media << endl;

    // Obiect/Instanta
    Student std1;
    std1.varsta_std = 20;
    cout << "Student 1 are varsta" << std1.varsta_std << endl;
    std1.media_std = 8.9;
    cout << "Student 1 are media " << std1.media_std << endl;

    Student std2;
    std2.varsta_std = 23;
    cout << "Student 2 are varsta" << std2.varsta_std << endl;
    std2.media_std = 6.9;
    cout << "Student 2 are media " << std2.media_std << endl;


    std1.printStudentSilitor();
    std2.printStudentSilitor();

    std1.setIsMale(true);
    std2.setIsMale(false);

    cout << "Studentul 1 este baiat?? " << std1.getIsMale() << endl;
    cout << "Studentul 2 este baiat?? " << std2.getIsMale() << endl;

    cout << "studentul 1 promoveaza? " << std1.promoveaza() << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln fileu
