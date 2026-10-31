// Stack ADT via Singly Linked List (Infix to Postfix)

#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
    Node* top;
public:
    Stack() { top = nullptr; }
    void push(char val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }
    char pop() {
        if (!top) return '#';
        char val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
    char peek() { return top ? top->data : '#'; }
    bool isEmpty() { return top == nullptr; }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') postfix += s.pop();
            s.pop(); 
        } else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) postfix += s.pop();
            s.push(c);
        }
    }
    while (!s.isEmpty()) postfix += s.pop();
    return postfix;
}

int main() {
    string infix = "A+(B*C-(D/E^F)*G)*H";
    cout << "Infix: " << infix << "\n";
    cout << "Postfix: " << infixToPostfix(infix) << "\n";
    // For prefix, reverse the infix, swap brackets, run postfix logic, then reverse the result.
    return 0;
}