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

    /*To define a copy constructor, the syntax is simple*/
    myClass(myClass &obj){
        /*here, the variable obj is the object to be copied.
        If I copy using an '=' operator, "obj" will be on the 
        right hand side of the equation*/

        this->myNum = obj.myNum;
        this->myChar = obj.myChar;
        /*Copying normal stack variables is fine, but I must
        also take care to copy the array correctly*/
        this->array = new int[this->myNum];                     // allocate new memory
        for(int i = 0; i < myNum; i++) array[i] = obj.array[i]; // move elements one by one
        
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


    cout << "Note that the error will no longer occur now.\n";
    /*the error is gone since we allcoate new memory for each copied object
    so when the objects go out of scope, different memory is deallocated 
    each time so we don't get the double free errors*/
    return 0;    
}