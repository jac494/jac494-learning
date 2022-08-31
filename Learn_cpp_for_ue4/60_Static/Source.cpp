#include <iostream>
using namespace std;

class Item {
public:
    static int item_count;
    Item() {
        item_count++;
        cout << "An item has been created!      ";
        cout << " There are " << item_count << " item(s).\n";
    };
    ~Item() {
        item_count--;
        cout << "An item has been destroyed!    ";
        cout << " There are " << item_count << " item(s).\n";
    };
};

// cannot initialize a static class member variable from within
// the class
int Item::item_count = 0;

void update_count() {
    int count_local = 0;
    count_local++;
    cout << "  count_local is " << count_local << endl;
    static int count_static = 0;
    count_static++;
    cout << "  count_static is " << count_static << endl;
}

int main() {
    for (int i=0; i<10; i++) {
        cout << "i is " << i << endl;
        update_count();
    }

    cout << endl;
    
    {
        // Notice when you run that two items are
        // created at the beginning of this scoped block
        Item localitem;
        static Item item;
        // but only one item was destroyed at the exit
    }
    // if I try to actually access `item` from here
    // it would fail because it is inaccessible outside
    // of the above scope even though it is still 'alive' in memory
    // but I can access the static class member
    cout << "Still in main, about to exit...";
    cout << " There are " << Item::item_count << " item(s).\n";

}