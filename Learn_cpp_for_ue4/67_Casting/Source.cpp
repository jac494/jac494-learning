#include <iostream>
using namespace std;




class P {
public:
    // need virtual here for downcasting and cross-casting to work
    virtual void f() {}
};

class A : virtual public P {};
class B : virtual public P {};
class C : public A, public B {};


class Object {
public:
    virtual void BeginPlay();

    void ObjectFunction() {
        cout << "ObjectFunction() called." << endl;
    }
};

class Actor : public Object {
public:
    virtual void BeginPlay() override;

    void ActorFunction() {
        cout << "ActorFunction() called." << endl;
    }
};

class Pawn: public Actor {
public:
    virtual void BeginPlay() override;

    void PawnFunction() {
        cout << "PawnFunction() called." << endl;
    }
};




int main() {
    // implicit type conversion
    float f = 5.0;
    int i = f; // i == 5

    // C-style explicit type casting
    // no checks to see if conversion is reasonable
    // ptr or arithmetic -> int
    // arithmetic -> float
    // ptr or arithmetic -> another ptr
    float g = 3.52;
    int j = (int)(g);

    // C++ Dynamic casting
    // used with casting from between base classes and derived classes
    // parent must have at least one virtual member function,
    // should also use virtual inheritance for this to work well
    // dynamic casts also perform runtime type checking that assures
    // the casting is legit
    P* p1;
    C* c = new C;
    // dynamic_cast<value to cast to>(variable)
    p1 = dynamic_cast<P*>(c);  // not really even necessary
    p1 = c;                    // you can just do this since C is a P
    delete c;

    // if I try to follow the dry-erase board example from
    // the video lecture *exactly* it results in a segfault
    // fixed by creating p2, c2, and creating a B object, not just
    // the null pointer to B
    P* p2;
    A* a;
    B* b = new B;   // this was just `B* b;` which was null and
                    // caused the segfault on the cross-cast
    C* c2 = new C;
    p2 = dynamic_cast<P*>(c2);
    a = dynamic_cast<A*>(p2);   // downcast
    a = dynamic_cast<A*>(b);    // cross-cast
    delete b;
    delete c2;


    // other casts in C++
    // static_cast
    // casts one pointer to another without the runtime type checking
    // can be used with non-polymorphic classes (no virtual function)
    // const_cast
    // used to remove the const-ness of an expression (rarely used)
    // reinterpret_cast
    // used to cast one pointer to another with absolutely no checks,
    // just does it (YOLO cast lol)

    // casting example

    Object* ptr_to_object = new Object;
    Actor* ptr_to_actor = new Actor;
    Pawn* ptr_to_pawn = new Pawn;

    // since Actor and Pawn both inherit from Object,
    // it is valid to create an array of pointers to Object
    // class instances but also place within it pointers to
    // instances of Actor and Pawn
    Object* ObjectArray[] = {
        ptr_to_object,
        ptr_to_actor,
        ptr_to_pawn
    };

    for (int i = 0; i < 3; i++) {
        ObjectArray[i]->BeginPlay();
        ObjectArray[i]->ObjectFunction();

        // can't call ActorFunction() since Object has no member ActorFunction()
        // ObjectArray[i]->ActorFunction();

        Object* obj = ObjectArray[i];
        obj->BeginPlay();
        obj->ObjectFunction();

        // can use dynamic casting to "check" and see if this specific object is an actor
        // if cast is not successful, this will be a null pointer
        Actor* act = dynamic_cast<Actor*>(obj);

        if (act) {  // if act is null pointer, this evaluation will be false
            // also note that when you run this, called twice because Pawn calls it as well
            act->ActorFunction();
        }

        Pawn* pwn = dynamic_cast<Pawn*>(obj);

        if (pwn) {
            pwn->PawnFunction();
        }
        cout << endl;
    }

    delete ptr_to_object;
    delete ptr_to_actor;
    delete ptr_to_pawn;

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