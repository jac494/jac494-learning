#include <iostream>
using namespace std;

class Weapon {
public:
    Weapon() {
        cout << "A weapon was created!" << endl;
    }
    ~Weapon() {
        cout << "A weapon was destroyed!" << endl;
    }
};

class Character {
public:
    Character();
    ~Character();

    int* CharacterAge;
    float* CharacterHealth;
};

int main() {
    Weapon* wep = new Weapon();
    delete wep;
    Character* Char = new Character;
    delete Char;
}

Character::Character() {
    cout << "A new character was created.\n";

    CharacterAge = new int(1);
    CharacterHealth = new float(100.f);
}

Character::~Character() {
    cout << "Character destroyed.\n";

    delete CharacterAge;
    delete CharacterHealth;
}
