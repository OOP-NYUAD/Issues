#include <iostream>

using namespace std;

class myClass{
    int myNum;
    char myChar;
    int *array;

public:
    /*Shallow copies are performed when no copy constructors are defined.
    In which case, all stack variables are just copied over to the new
    object.*/
    myClass(int n = 0, char c = '0'){
        myNum = n;
        myChar = c;
        array = new int[myNum];    // here we dynamically allocate some memory.
        for(int i = 0; i < myNum; i++) array[i] = i;
    }

    void print(){
        cout << "Number: " << myNum << '\n';
        cout << "Character: " << myChar << '\n';
    }

    /*Since we allocate memory, we must deallocate it when we destroy the object
    Note that the destructor gets called automatically when the object goes
    out of scope if its statically allocated or when you delete it if its 
    dynamically allocated*/
    ~myClass(){
        delete[] array;
    }
};

int main(){
    myClass obj1(2, 'Z');
    myClass obj2 = obj1;    // this is one way to do a copy
    myClass obj3(obj1);     // this is another way to do a copy

    obj1.print();
    obj2.print();
    obj3.print(); // these will all output the same thing


    cout << "Note that an error will occur when I run the program.\n";
    /*this error occurs since obj1 and obj2 have copies of the *pointers*!
    Not the dynamically allocated arrays. This means all of them have pointers
    to the same memory location. This also means that when the first object
    goes out of scope, the memory is deallocated, then, when the second object
    goes out of scope, the program will crash as I try to free memory that I 
    already freed*/
    return 0;    
}