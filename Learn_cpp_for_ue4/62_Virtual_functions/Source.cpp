#include <iostream>

using namespace std;

class Object {
public:
    // virtual keyword allows it to be overridden
    // in child classes
    virtual void BeginPlay();
};

class Actor : public Object {
public:
    // virtual keyword not needed here, but generally added
    // as a visual signal to other programmers that this can be and
    // is potentially being overridden
    // override keyword is again not necessary, but provides
    // visual signal that this is overriding a parent class
    virtual void BeginPlay() override;
};

class Pawn : public Actor {
public:
    virtual void BeginPlay() override;
};

int main() {
    Object* obj = new Object;
    obj->BeginPlay();

    Actor* act = new Actor;
    act->BeginPlay();

    Pawn* pwn = new Pawn;
    pwn->BeginPlay();

    delete obj;
    delete act;
    delete pwn;
}

void Object::BeginPlay() {
    cout << "Object BeginPlay() called." << endl;
}

void Actor::BeginPlay() {
    cout << "Actor BeginPlay() called." << endl;
}

void Pawn::BeginPlay() {
    cout << "Pawn BeginPlay() called." << endl;
}