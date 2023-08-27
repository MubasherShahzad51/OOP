#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void addEntry(string filename)
{
    // for writing data to file
    ofstream file; 
    // open file in append mode and write data next to it
    file.open(filename, ios::app); 
    string entry;
    cout << "Enter your journal entry: ";
    getline(cin, entry);
    file << entry << endl;
    file.close();
    cout << "Entry added successfully!" << endl;
}

void displayJournal(string filename)
{
    // for reading file data
    ifstream file; 
    file.open(filename);
    if (!file)
    {
        cout << "Journal not found!" << endl;
        return;
    }
    string line;
    cout << "Journal entries: " << endl;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}

int main()
{
    string filename = "journal.txt";
    int choice;
    while (true)
    {
        cout << endl
             << "Menu:" << endl;
        cout << "1. Add an entry to the journal" << endl;
        cout << "2. Display the journal" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // ignore the newline character in input buffer
        switch (choice)
        {
        case 1:
            addEntry(filename);
            break;
        case 2:
            displayJournal(filename);
            break;
        case 3:
            cout << "Exit" << endl;
            return 0;
        default:
            cout << "Invalid choice! Try again." << endl;
            break;
        }
    }
    return 0;
}