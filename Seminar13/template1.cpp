#include <iostream>
#include  <string>
using namespace std;




/* O functie template */
template <typename  T>
void printVar(T  varibila) {
    cout  << "Varibila printata este: " << varibila  << endl;
}

int main()
{
    int a = 6430 ;
    printVar(a);

    float b = 32.032;
    printVar(b);

    string c = "hello";
    printVar(c);


    double d = 34.53;
    printVar<double>(d);

    bool f = false;
    printVar<>(f);

}

