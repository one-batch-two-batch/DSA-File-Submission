// Telephone Directory (Hash Table)

#include <iostream>
#include <string>
using namespace std;

struct Entry {
    string name;
    string phone;
    bool isOccupied = false;
};

class HashTable {
    Entry* table;
    int size;
public:
    HashTable(int s) {
        size = s;
        table = new Entry[size];
    }
    int hashFunction(string key) {
        int hash = 0;
        for (char c : key) hash += c;
        return hash % size;
    }
    void insert(string name, string phone) {
        int index = hashFunction(name);
        while (table[index].isOccupied) {
            index = (index + 1) % size; // Linear probing
        }
        table[index].name = name;
        table[index].phone = phone;
        table[index].isOccupied = true;
    }
    void search(string name) {
        int index = hashFunction(name);
        int startIndex = index;
        while (table[index].isOccupied) {
            if (table[index].name == name) {
                cout << "Found: " << name << " -> " << table[index].phone << "\n";
                return;
            }
            index = (index + 1) % size;
            if (index == startIndex) break;
        }
        cout << "Record not found.\n";
    }
};

int main() {
    HashTable ht(10);
    ht.insert("Pranjal", "9876543210");
    ht.insert("Amit", "9123456780");
    
    ht.search("Pranjal");
    return 0;
}