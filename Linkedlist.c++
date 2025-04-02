#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;
    
    BinaryTree() {
        root = nullptr;
    }
    

    Node* insert(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }
        
        if (value < root->data) {
            root->left = insert(root->left, value);
        } else {
            root->right = insert(root->right, value);
        }
        return root;
    }
    

    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
};

int main() {
    BinaryTree tree;
    

    tree.root = tree.insert(tree.root, 10);
    tree.insert(tree.root, 5);
    tree.insert(tree.root, 15);
    
    cout << "Inorder traversal:" << endl;
    tree.inorder(tree.root);
    
    return 0;
}
