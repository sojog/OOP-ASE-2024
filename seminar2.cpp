// seminar2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int adunare(int a, int b) {
    return a + b;
}
void incrementare_valori(int a, int b) {
    a += 10;
    b += 10;
    cout << "a din functie " << a << endl;
    cout << "b din functie" << b << endl;
}

void incrementare_prin_referinta(int* a, int* b) {
    cout << "a din functie " << a << endl;
    cout << "b din functie" << b << endl;
    *a += 10;
    *b += 10;
    cout << "valoare lui a din functie " << *a << endl;
    cout << "valoarea lui b din functie" << *b << endl;
}

void interschimbare(int* a, int* b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;

}

int main()
{
    cout << "Hello World!\n";

    //pointer
    int *pointer;
    // valoare
    int valoare = 30;
    cout << "valoare=" << valoare << endl;

    pointer = &valoare;
    cout << "Pointer=" << pointer << endl;
    
    int valoare2;
    valoare2 = valoare;
    cout << "valoare 2 = " << valoare2 << endl;

    int vector[] = { 11, 22, 33, 44, 55 };
    int* p_vect = vector;

    cout << "Valoarea de la primul element" << vector[0] << endl;
    cout << "Adresa primului element" << p_vect << endl; // ex: 000000BFDC4FF7F8
    cout << "Valoarea de la primul element" << *p_vect << endl;

    cout << "Valoarea de la elementul al 3lea " << * (p_vect + 2) << endl;


    cout << "Adresa primului element" << p_vect << endl;

    p_vect = p_vect + 2;
    cout << "valoarea de la noua adresa a pointerului este: " << *p_vect << endl;
    
    cout << "size of int " << sizeof(int) << endl;


    int vector2[] = { 11, 22, 33, 44, 55 };
    cout << "Adresa primului element" << vector2 << endl;
    cout << "Adresa primului element" << &vector2[0] << endl;
    cout << "Adresa elementului 2" << &vector2[1] << endl;


    int a;
    a = 10;
    int* b = &a;
    *b = 9;
    cout << "a=" << a << endl;
    cout << "b=" << *b << endl;

    cout << "adresa lui a" << &a << endl;
    cout << "adresa lui b" << b << endl;

    a = 20;

    cout << "a=" << a << endl;
    cout << "b=" << *b << endl;

    cout << "adresa lui a" << &a << endl;
    cout << "adresa lui b" << b << endl;



    cout << adunare(10, 20) << endl;
    cout << adunare(a, *b) << endl;


    cout << "a=" << a << endl;
    cout << "b=" << *b << endl;
    incrementare_valori(a, *b);
    cout << "a=" << a << endl;
    cout << "b=" << *b << endl;

    incrementare_prin_referinta(&a, b);
    cout << "a=" << a << endl;
    cout << "b=" << *b << endl;

    int num1 = 10;
    int num2 = 30;

    cout << "num1=" << num1 << endl;
    cout << "num2=" << num2 << endl << endl;

    //interschimbare
    interschimbare(&num1, &num2);
    cout << "num1=" << num1 << endl;
    cout << "num2=" << num2 << endl << endl;

    int* add1;
    int* add2;
    add1 = &num1;
    add2 = &num2;
    //interschimbare
    interschimbare(add1, add2);
    cout << "num1=" << num1 << endl;
    cout << "num2=" << num2 << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
semin