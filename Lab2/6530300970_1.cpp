#include <iostream>
using namespace std;

// Written by Pawit Thongkum
// ID : 6530300970
// NO : 1

struct record 
{
    int value;
    struct record *next;
};

int main() {
    struct record *p;
    int input;

    cout << "Enter : ";
    cin >> input;

    p -> value = input;
    cout << "Value=" << p -> value;

    return 0;
}