#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

struct Character {
    Character() {
        Name = "Default";
        Health = 100.f;
    }
    Character(string name, float health) {
        Name = name;
        Health = health;
    }
    string Name;
    float Health;
};

int main() {
    // random for loop just to run it a few times
    for (int i = 0; i < 10; i++) {
        // Character struct on the stack
        Character StackChar;
        Character* PtrToHeapChar;
        if (i % 2 == 0) {
            // new allocates memory on the heap and returns a pointer
            PtrToHeapChar = new Character();
        } else {
            PtrToHeapChar = new Character("Drew", 87.f);
        }
        //cout << PtrToHeapChar->Name << " " << PtrToHeapChar->Health << "; ";
        // TIL below: std::string is very much different from char arrays _and_
        // the format for rounding/truncating floats is %.2f not %f.2
        //printf("New Character Name: %s Health: %f.2; ", PtrToHeapChar->Name, PtrToHeapChar->Health);
        printf(
            "New Character\n  Name: %s\n  Health: %.2f\n",
            PtrToHeapChar->Name.c_str(),
            PtrToHeapChar->Health
        );
        delete PtrToHeapChar;
    }
    cout << endl;
}