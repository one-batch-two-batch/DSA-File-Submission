// Circular Queue

#include <iostream>
#define SIZE 5
using namespace std;

class CircularQueue {
    int arr[SIZE];
    int front, rear;
public:
    CircularQueue() { front = -1; rear = -1; }
    
    void enqueue(int val) {
        if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1))) {
            cout << "Queue is Full!\n";
            return;
        }
        if (front == -1) front = rear = 0;
        else if (rear == SIZE - 1 && front != 0) rear = 0;
        else rear++;
        arr[rear] = val;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Deleted: " << arr[front] << "\n";
        if (front == rear) front = rear = -1;
        else if (front == SIZE - 1) front = 0;
        else front++;
    }

    void display() {
        if (front == -1) { cout << "Empty Queue\n"; return; }
        cout << "Queue elements: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        } else {
            for (int i = front; i < SIZE; i++) cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++) cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(10); cq.enqueue(20); cq.enqueue(30);
    cq.display();
    cq.dequeue();
    cq.display();
    return 0;
}