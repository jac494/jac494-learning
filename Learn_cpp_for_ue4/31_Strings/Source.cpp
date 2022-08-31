#include <iostream>
#include <string>

using namespace std;

int main() {
    string FirstName("Drew");
    string LastName("Conner");
    string full = FirstName + " " + LastName;
    cout << "hello, " << full << endl;
    cout << "Your first name is " << FirstName;
    cout << " and your last name is " << LastName << endl;
}