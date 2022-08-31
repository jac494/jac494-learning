#include <iostream>
#include <string>

using namespace std;


struct Container {
    string Name;
    int X;
    int Y;
    int Z;
};


int main() {
    // declaring and initializing an integer
    int a = 100;
    // declaring an integer pointer
    int* intPtr;
    // initializing the integer pointer to
    // the address of (using ampersand) the int a
    intPtr = &a;

    // prints the memory address of aPtr
    cout << intPtr << endl;

    // prints the actual integer value using
    // the dereference operator (asterisk)
    cout << *intPtr << endl;

    int b = 50;
    intPtr = &b;
    cout << intPtr << endl;
    cout << *intPtr << endl;

    int numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* NumPtr = numbers;
    // proving that NumPtr right now references the memory location
    // of the first item in the array 'numbers'
    cout << *NumPtr << endl;

    for (int i=0; i<=10; i++) {
        int* numMem = NumPtr + i;
        cout << "The integer at memory address "
        << numMem << " is " << *numMem << endl;
    }
    // we didn't modify NumPtr, so it still points to the first
    // memory address in the array 'numbers'
    cout << *NumPtr << endl;

    Container container = {"Sam", 5, 6, 7};
    Container* PtrToCont = &container;
    cout << (*PtrToCont).Name << endl;
    cout << (*PtrToCont).X << endl;
    cout << (*PtrToCont).Y << endl;
    cout << (*PtrToCont).Z << endl;

    // syntactic sugar for the parens above
    // don't have to dereference because the arrow does this for us
    cout << PtrToCont->Name << endl;
    cout << PtrToCont->X << endl;
    cout << PtrToCont->Y << endl;
    cout << PtrToCont->Z << endl;

}