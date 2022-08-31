#include <iostream>
#include <string>

using namespace std;


// code below initializes the enum but does not create a variable
// also, enum members (is that the right term?) are initialized to
// integer values beginning with 0 and incrementing by 1
// not used for arithmetic, but you can if you want or need to
// (i.e. PS_Crouched + PS_Walking == PS_Running)
enum PlayerStatus {
    PS_Crouched,
    PS_Standing,
    PS_Walking,
    PS_Running,
    PS_Sprinting
};

void PrintStatus(PlayerStatus status);

int main() {
    PlayerStatus status;
    status = PS_Crouched;
    PrintStatus(status);
    status = PS_Sprinting;
    PrintStatus(status);
    
}

void PrintStatus(PlayerStatus status) {
    switch (status) {
        case PS_Crouched:
            cout << "Crouched" << endl;
            break;
        case PS_Standing:
            cout << "Standing" << endl;
            break;
        case PS_Walking:
            cout << "Walking" << endl;
            break;
        case PS_Running:
            cout << "Running" << endl;
            break;
        case PS_Sprinting:
            cout << "Sprinting" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
}