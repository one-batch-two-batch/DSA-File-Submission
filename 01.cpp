// Student Database

#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float cgpa;
};

void bubbleSortByName(Student* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].name > arr[j + 1].name) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSortByCGPA(Student* arr, int n) {
    for (int i = 1; i < n; i++) {
        Student key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].cgpa > key.cgpa) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int linearSearch(Student* arr, int n, int targetID) {
    for (int i = 0; i < n; i++) {
        if (arr[i].id == targetID) return i;
    }
    return -1;
}

int binarySearch(Student* arr, int n, int targetID) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].id == targetID) return mid;
        if (arr[mid].id < targetID) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    
    Student* students = new Student[n]; // Dynamically allocated memory
    for(int i=0; i<n; i++) {
        cout << "Enter ID, Name, CGPA: ";
        cin >> students[i].id >> students[i].name >> students[i].cgpa;
    }

    bubbleSortByName(students, n);
    cout << "\nSorted by Name (Bubble Sort):\n";
    for(int i=0; i<n; i++) cout << students[i].name << " - " << students[i].cgpa << "\n";

    delete[] students;
    return 0;
}