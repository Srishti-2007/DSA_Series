#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* BST(int post[], int &index, int l, int u) {
    if (index < 0 || post[index] < l || post[index] > u)
        return NULL;

    Node* root = new Node(post[index--]);  // index-- for postorder

    // IMPORTANT: right first, then left
    root->right = BST(post, index, root->data, u);
    root->left  = BST(post, index, l, root->data);

    return root;
}

Node* constructTree(int post[], int size) {
    int index = size - 1;
    return BST(post, index, INT_MIN, INT_MAX);
}

// ---------- Utility to check ----------
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int post[] = {1, 7, 5, 50, 40, 10};
    int size = sizeof(post) / sizeof(post[0]);

    Node* root = constructTree(post, size);

    cout << "Inorder traversal of constructed BST: ";
    inorder(root);

    return 0;
}