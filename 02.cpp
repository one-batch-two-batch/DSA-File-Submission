// Merge Sort for Online Orders

#include <iostream>
using namespace std;

struct Order {
    int orderID;
    int deliveryTime;
};

void merge(Order arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Order* L = new Order[n1];
    Order* R = new Order[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].deliveryTime <= R[j].deliveryTime) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(Order arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    Order orders[] = {{101, 45}, {102, 15}, {103, 30}, {104, 10}};
    int n = 4;
    mergeSort(orders, 0, n - 1);
    
    cout << "Orders sorted by Delivery Time:\n";
    for(int i=0; i<n; i++) cout << "Order ID: " << orders[i].orderID << ", Time: " << orders[i].deliveryTime << " mins\n";
    return 0;
}