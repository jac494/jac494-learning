#include <iostream>
using namespace std;

void AddOne(int Num);
void AddOneRef(int& Num);

int main() {
    int a = 1;
    AddOne(a);
    cout << a << endl;

    AddOneRef(a);
    cout << a << endl;
}

void AddOne(int Num) {
    Num++;
}

void AddOneRef(int& Num) {
    Num++;
}