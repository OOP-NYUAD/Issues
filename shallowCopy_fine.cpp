#include <iostream>

using namespace std;

class myClass{
    int myNum;
    char myChar;

public:
    /*Shallow copies are performed when no copy constructors are defined.
    In which case, all stack variables are just copied over to the new
    object.*/
    myClass(int n = 0, char c = '0'){
        myNum = n;
        myChar = c;
    }

    void print(){
        cout << "Number: " << myNum << '\n';
        cout << "Character: " << myChar << '\n';
    }
};

int main(){
    myClass obj1(2, 'Z');
    myClass obj2 = obj1;    // this is one way to do a copy
    myClass obj3(obj1);     // this is another way to do a copy

    obj1.print();
    obj2.print();
    obj3.print(); // these will all output the same thing

    return 0;
}