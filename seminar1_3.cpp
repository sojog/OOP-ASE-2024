# include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    
    int a = 3;
    cout << a << endl << "size of a=" << sizeof(a) << endl;

    float b = 3.0;
    cout << b << endl << "size of b=" << sizeof(b) << endl;

    double c = 4.5;
    cout << c << endl << "size of c=" << sizeof(c) << endl;

    return 0;
}

// 1  byte = 1 octet = 8 bits
// bit
// 000  - 0
// 001 - 1
// 010  - 2
// 011 - 3
// 100 - 4
// 101 - 5
// 110 - 6
// 111 - 7
// 1000 - 8
4 * 8 - 1000