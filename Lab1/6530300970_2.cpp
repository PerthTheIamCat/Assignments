#include <iostream>
using namespace std;

// Written by Pawit Thongkum
// ID : 6530300970
// NO : 2

bool have_first_value(int count)
{
    if (count == 0)
    {   
        cout << "ERR >> Not have first value yet!!" << endl;
        return false;
    }
    return true;
}

void show_data(int data[], int count, int start)
{
    for (int i = start; i < count; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main() 
{   
    int input, count = 0, arr[10], temp, i;

    while (input!=-1)
    {
        cout << "\n===========MENU===========\n" << endl;
        cout << "1) Insert the first value" << endl;
        cout << "2) Insert front" << endl;
        cout << "3) Insert last" << endl;
        cout << "4) Insert middle" << endl;
        cout << "5) Exit (-1)" << endl;
        cout << "\nPlease choose > ";
        cin >> input;

        switch (input)
        {
        case 1: // Insert the first value
            if (count > 0)
            {
                cout << "ERR >> You are already have \"first value\"!!" << endl;
                break;
            } else {
                cout << "Enter data : ";
                cin >> arr[0];
                count++;
                cout << "Data in list = ";
                show_data(arr, count, 0);
                break;
            }
        case 2: // Insert front
            if (have_first_value(count))
            {
                cout << "Enter data : ";
                cin >> temp;
                cout << "Move = " << count << " Position" << endl;
                cout << "Data move = ";
                show_data(arr, count, 0);
                for (i = count; i >= 0; i--)
                {
                    arr[i] = arr[i-1];
                }
                arr[0] = temp;
                count++;
                cout << "Data in list = ";
                show_data(arr, count, 0);
                break;
            } else {
                break;
            }
        case 3: // Insert last
            if (have_first_value(count))
            {
                cout << "Enter data : ";
                cin >> arr[count];
                count++;
                cout << "Data in list = ";
                show_data(arr, count, 0);
                break;
            } else {
                break;
            }
        case 4: // Insert middle
            if (have_first_value(count))
            {
                cout << "Enter data : ";
                cin >> temp;
                cout << "Move = " << count/2 << " Position" << endl;
                cout << "Data move = ";
                show_data(arr, count, count/2);
                for (i = count; i >= count/2; i--)
                {
                    arr[i] = arr[i-1];
                }
                arr[count/2] = temp;
                count++;
                cout << "Data in list = ";
                show_data(arr, count, 0);
                break;
            } else {
                break;
            }
        case -1: // Insert
            cout << "Output = Bye" << endl;
            break;
        default:
            cout << "ERR >> Invalid!! Please Try again!!" << endl;
            break;
        }   
    }   
    return 0;
}