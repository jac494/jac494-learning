// taking a look at diamond inheritance
// where two child classes inherit the same
// member function from a common parent
// then a grandchild inherits from the two child classes
// which function gets called from the grandchild?

class P {
public:
    void f() {}
};

class A : public P {};
class B : public P {};
class C : public A, public B {};

class D : virtual public P {};
class E : virtual public P {};
class F : public D, public E {};

int main() {
    C c;
    // the line below causes an error if left in place
    // c.f() can't tell which f() to call
    // "C::f() is ambiguous"
    // c.f();
    c.A::f();  // explicitly stating which f() is fine
    c.B::f();  // explicitly stating which f() is fine

    // also can use 'virtual' keyword above and call F.f() directly
    // it is calling the f() defined in P ultimately, not really calling the one
    // in either D or E
    F f;
    f.f();
}