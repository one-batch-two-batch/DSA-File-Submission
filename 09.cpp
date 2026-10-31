// File Handling

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "student_data.txt";

    // 1. Create and Write
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error creating file!\n";
        return 1;
    }
    outFile << "ID: 101, Name: Pranjal, Dept: Comp Engg\n";
    outFile << "ID: 102, Name: Aditya, Dept: IT\n";
    outFile.close();
    cout << "Data written to file successfully.\n";

    // 2. Read
    ifstream inFile(filename);
    string line;
    cout << "\nReading from file:\n";
    while (getline(inFile, line)) {
        cout << line << "\n";
    }
    inFile.close();

    // 3. Delete
    if (remove(filename.c_str()) == 0) {
        cout << "\nFile deleted successfully.\n";
    } else {
        cout << "\nError deleting file.\n";
    }

    return 0;
}