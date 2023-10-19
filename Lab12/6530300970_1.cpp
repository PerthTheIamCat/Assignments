#include <iostream>
#include <fstream>

// Writen By Pawit Thongkum
// ID : 6530300970
// NO : 1

using namespace std;

struct record 
{
    long long stdID;
    string stdName;
    struct record *next;
};

// Insert for Struct Record
struct record *insert(struct record *head, string id, string name)
{
    if (head == NULL)
    {
        head = new struct record;
        head -> stdID = stoll(id);
        head -> stdName = name;
        head -> next = NULL;
    }
    else
    {
        // Insert Last
        struct record *node = new struct record;
        struct record *p;
        node -> stdID = stoll(id);
        node -> stdName = name;
        node -> next = NULL;
        p = head;
        while (p -> next != NULL)
        {
            p = p -> next;
        }
        p -> next = node;
    }
    return head;
}

// Function : Show menu and get the choosen input
int menu(void)
{
    int choose = 0;
    cout << "===========MENU===========\n";
    cout << "1. Separate Chaining\n";
    cout << "2. Linear Probling\n";
    cout << "3. Quardratic Probling\n";
    cout << "4. Double Hashing\n";
    cout << "5. Exit\n";
    cout << "\tPlease Choose > ";
    cin >> choose;
    return choose;
}

// Function : Hashing the key
int hashValue(string key, int tableSize, int countRepeat)
{
    return (stoll(key) + countRepeat) % tableSize;
}

// Function : Hashing the key for Double Hashing 
int hashValue2(string key, int tableSize)
{
    return 3 - (stoll(key) % tableSize);         // formular for separate the data : (Prime - (Key % tableSize) ; Prime < tableSize)
}

// Function : Separate the data by Chaining
void separateChaining(int tableSize)
{
    int index = 0;
    struct record *separateChainingRecord[tableSize];
    struct record *p;
    string name, id;
    ifstream readFile("ADT.txt");
    // Initialize the pointer for struct record to NULL
    for (int i = 0; i < tableSize; i++)
    {
        separateChainingRecord[i] = NULL;
    }
    // Read File and Add to Table
    while (readFile >> id >> name)
    {
        index = hashValue(id, tableSize, 0);
        separateChainingRecord[index] = insert(separateChainingRecord[index], id, name);
    }
    readFile.close();
    // Show data in the table
    cout << "\n\nIndex\tID\n\n";
    for (int i = 0; i < tableSize; i++)
    {
        cout << i << "\t";
        p = separateChainingRecord[i];
        while (p != NULL)
        {
            cout << p -> stdID << "\t" << p -> stdName << endl << "\t"; 
            p = p -> next;
        }
        cout << "\n\n";
    }
}

// Function : Separate the data by Linear Probling
void linearProbling(int tableSize)
{
    int index = 0;
    int countRepeat = 0;
    struct record *linearProblingRecord[tableSize];
    struct record *p;
    string name, id;
    ifstream readFile("ADT.txt");
    // Initialize the pointer for struct record to NULL
    for (int i = 0; i < tableSize; i++)
    {
        linearProblingRecord[i] = NULL;
    }
    // Read File and Add to Table
    while (readFile >> id >> name)
    {
        index = hashValue(id, tableSize, countRepeat);
        while (linearProblingRecord[index] != NULL && countRepeat <= 100)
        {
            countRepeat++;
            index = hashValue(id, tableSize, countRepeat);      // Index = Hash + countRepeat
        }
        if (countRepeat > 100)
        {
            cout << "\n\nError, Can not insert data!\n\n";
            break;
        }
        linearProblingRecord[index] = insert(linearProblingRecord[index], id, name);
        countRepeat = 0;
    }
    readFile.close();
    // Show data in the table
    cout << "\n\nIndex\tID\n\n";
    for (int i = 0; i < tableSize; i++)
    {
        cout << i << "\t";
        p = linearProblingRecord[i];
        while (p != NULL)
        {
            cout << p -> stdID << "\t" << p -> stdName << endl << "\t"; 
            p = p -> next;
        }
        cout << "\n\n";
    }
}

// Function : Separate the data by QuardraticProbling
void quardraticProbling(int tableSize)
{
    int index = 0;
    int countRepeat = 0;
    struct record *quardraticRecord[tableSize];
    struct record *p;
    string name, id;
    ifstream readFile("ADT.txt");
    // Initialize the pointer for struct record to NULL
    for (int i = 0; i < tableSize; i++)
    {
        quardraticRecord[i] = NULL;
    }
    // Read File and Add to Table
    while (readFile >> id >> name)
    {
        index = hashValue(id, tableSize, countRepeat);
        while (quardraticRecord[index] != NULL && countRepeat <= 100)
        {
            countRepeat++;
            index = hashValue(id, tableSize, countRepeat * countRepeat);        // Index = Hash + countRepeat^2
        }
        if (countRepeat > 100)
        {
            cout << "\n\nError, Can not insert data!\n\n";
            break;
        }
        quardraticRecord[index] = insert(quardraticRecord[index], id, name);
        countRepeat = 0;
    }
    readFile.close();
    // Show data in the table
    cout << "\n\nIndex\tID\n\n";
    for (int i = 0; i < tableSize; i++)
    {
        cout << i << "\t";
        p = quardraticRecord[i];
        while (p != NULL)
        {
            cout << p -> stdID << "\t" << p -> stdName << endl << "\t"; 
            p = p -> next;
        }
        cout << "\n\n";
    }
}

// Function : Separate the data by Dounle Hashing
void doubleHashing(int tableSize)
{
    int index = 0;
    int countRepeat = 0;
    struct record *doubleHashingRecord[tableSize];
    struct record *p;
    string name, id;
    ifstream readFile("ADT.txt");
    // Initialize the pointer for struct record to NULL
    for (int i = 0; i < tableSize; i++)
    {
        doubleHashingRecord[i] = NULL;
    }
    // Read File and Add to Table
    while (readFile >> id >> name)
    {
        index = hashValue(id, tableSize, countRepeat);
        while (doubleHashingRecord[index] != NULL && countRepeat <= 100)
        {
            countRepeat++;
            // Index = Hash + countRepeat * Hash2 % tablesize
            index = (hashValue(id, tableSize, 0) + countRepeat * hashValue2(id, tableSize)) % tableSize;
        }
        if (countRepeat > 100)
        {
            cout << "\n\nError, Can not insert data!\n";
            break;
        }
        doubleHashingRecord[index] = insert(doubleHashingRecord[index], id, name);
        countRepeat = 0;
    }
    readFile.close();
    // Show data in the table
    cout << "\n\nIndex\tID\n\n";
    for (int i = 0; i < tableSize; i++)
    {
        cout << i << "\t";
        p = doubleHashingRecord[i];
        while (p != NULL)
        {
            cout << p -> stdID << "\t" << p -> stdName << endl << "\t"; 
            p = p -> next;
        }
        cout << "\n\n";
    }
}

int main()
{
    int tableSize = 5;
    int input = 0;
    do
    {
        input = menu();
        switch (input)
        {
        case 1:
            separateChaining(tableSize);
            break;
        
        case 2:
            linearProbling(tableSize);
            break;

        case 3:
            quardraticProbling(tableSize);
            break;
        
        case 4:
            doubleHashing(tableSize);
            break;

        case 5:
            cout << "OK, Goodbye !!! \n";
            break;

        default:
            cout << "Invalid input !!! Please Choose Again !!!\n";
            break;
        }
    } while (input != 5);
    
}