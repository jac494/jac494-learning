#include <iostream>
using namespace std;

int MyFunction(int Param_one, int Param_two) {
    int local_variable;
    local_variable = Param_one + Param_two;
    cout << "The local variable is " << local_variable << endl;
    return local_variable;
}

int main() {
    int var_in_main = MyFunction(2, 3);
    int Another_Var = MyFunction(var_in_main, 4);
    MyFunction(var_in_main, Another_Var);
    return 0;
}