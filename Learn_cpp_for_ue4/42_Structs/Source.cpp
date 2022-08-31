#include <iostream>
#include <string>

using namespace std;

struct Character {
    // not used in this example, but C++ structs
    // can have static members, while C structs
    // CANNOT have static members. I wonder: why?
    string Name;
    float Health;
    int Level;
    float Damage;
    // C-structures do not allow
    // member functions, only possible in C++
    void Attack() {
        cout << Name << " does "
        << Damage << " damage!"
        << endl;
    }
};

int main() {
    Character Joe;
    Joe.Name = "Joe";
    Joe.Health = 100.f;
    Joe.Level = 1;
    Joe.Damage = 2.5f;
    Joe.Attack();

    Character Lisa = {
        "Lisa", 100.f, 3, 15.f
    };
    Lisa.Attack();
}