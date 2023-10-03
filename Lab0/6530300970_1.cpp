#include <iostream>
using namespace std;

// Written by Pawit Thongkum
// ID : 6530300970
// HW : 1

int main() {
    
    // Declare variable
    float celcius;
    float fahrenheit;

    // Get input
    cout << "Celcius : " ;
    cin >> celcius;

    // Equation for calculate fahrenheit to celcius
    fahrenheit = celcius * 9/5 + 32;

    // Show output
    cout << fahrenheit ;
    return 0;
    
}