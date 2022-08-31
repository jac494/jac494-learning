#include <iostream>
using namespace std;

void welcome();

char getYesNo();

void printResponse(char responseToPrint);

void AskYesOrNoQuestion();

int main() {
    cout << "yoooo\n";
    AskYesOrNoQuestion();
}

void welcome() {
    cout << "Welcome!\n";
}

char getYesNo() {
    cout << "Please answer: y or n.\n";
    char response;
    cin >> response;
    return response;
}

void printResponse(char responseToPrint) {
    cout << "Your answer was: " << responseToPrint << endl;
}

void AskYesOrNoQuestion() {
    welcome();
    char answer = getYesNo();
    printResponse(answer);
}