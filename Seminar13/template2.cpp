#include <iostream>
#include  <string>
using namespace std;


template <int N>
class Student{
    int note[N];
public:   
    int nrNote(){
        return N;
    }
};


int main()
{
    Student<5> stud1_cu_5_note;
    cout << "Cate note are " << stud1_cu_5_note.nrNote() << endl;

    Student<8> stud1_cu_8_note;
    cout << "Cate note are " << stud1_cu_8_note.nrNote() << endl;

}

