// Binary Search Tree (BST)

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) { data = val; left = right = nullptr; }
};

class BST {
public:
    Node* root;
    BST() { root = nullptr; }

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int val) {
        if (!node) return node;
        if (val < node->data) node->left = deleteNode(node->left, val);
        else if (val > node->data) node->right = deleteNode(node->right, val);
        else {
            if (!node->left) { Node* temp = node->right; delete node; return temp; }
            else if (!node->right) { Node* temp = node->left; delete node; return temp; }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    int depth(Node* node) {
        if (!node) return 0;
        return max(depth(node->left), depth(node->right)) + 1;
    }

    void leafNodes(Node* node) {
        if (!node) return;
        if (!node->left && !node->right) cout << node->data << " ";
        leafNodes(node->left);
        leafNodes(node->right);
    }
    
    void displayLevelWise(Node* node) {
        if (!node) return;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << "\n";
    }
};

int main() {
    BST tree;
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 70);
    
    cout << "Inorder: "; tree.inorder(tree.root); cout << "\n";
    cout << "Depth: " << tree.depth(tree.root) << "\n";
    cout << "Level Wise: "; tree.displayLevelWise(tree.root);
    return 0;
}