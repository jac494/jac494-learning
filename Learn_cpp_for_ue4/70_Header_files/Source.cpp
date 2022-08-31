#include <iostream>
#include "Object.h"
#include "Actor.h"
#include "Pawn.h"

using namespace std;

// refactored ../64_Polymorphism/Source.cpp
// into header files and includes
// ok so I ran into the issue below:
/*
$ g++ Source.cpp && ./a.out
/usr/bin/ld: /tmp/ccMEsJOw.o: in function `Object::Object()':
Source.cpp:(.text._ZN6ObjectC2Ev[_ZN6ObjectC5Ev]+0xf): undefined reference to `vtable for Object'
/usr/bin/ld: /tmp/ccMEsJOw.o: in function `Actor::Actor()':
Source.cpp:(.text._ZN5ActorC2Ev[_ZN5ActorC5Ev]+0x1f): undefined reference to `vtable for Actor'
/usr/bin/ld: /tmp/ccMEsJOw.o: in function `Pawn::Pawn()':
Source.cpp:(.text._ZN4PawnC2Ev[_ZN4PawnC5Ev]+0x1f): undefined reference to `vtable for Pawn'
collect2: error: ld returned 1 exit status
*/
// and the fix was to use: `g++  *.cpp -o a.out`
/*
$ g++ *.cpp -o a.out && ./a.out
Object BeginPlay() called.
Actor BeginPlay() called.
Pawn BeginPlay() called.
*/


int main() {
    Object* ptr_to_object = new Object;
    Actor* ptr_to_actor = new Actor;
    Pawn* ptr_to_pawn = new Pawn;

    Object* ObjectArray[] = {
        ptr_to_object,
        ptr_to_actor,
        ptr_to_pawn
    };

    for (int i = 0; i < 3; i++) {
        ObjectArray[i]->BeginPlay();
    }

    delete ptr_to_object;
    delete ptr_to_actor;
    delete ptr_to_pawn;
}