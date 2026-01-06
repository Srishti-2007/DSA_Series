#include <iostream>
#include <queue>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

/* Insert in BST */
node* insert(node* root, int target) {
    if (!root) {
        return new node(target);
    }

    if (target < root->data)
        root->left = insert(root->left, target);
    else
        root->right = insert(root->right, target);

    return root;   // ⭐ VERY IMPORTANT
}

/* Lowest Common Ancestor in BST */
node* LCA(node* root, node* p, node* q) {
    if (!root)
        return NULL;

    if (root->data > p->data && root->data > q->data)
        return LCA(root->left, p, q);

    if (root->data < p->data && root->data < q->data)
        return LCA(root->right, p, q);

    return root;
}

/* Print tree level-wise (tree like structure) */
void printTree(node* root) {
    if (!root) return;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            node* curr = q.front();
            q.pop();

            if (curr) {
                cout << curr->data << " ";
                q.push(curr->left);
                q.push(curr->right);
            } else {
                cout << "N ";
            }
        }
        cout << endl;
    }
}

/* Search node (to get p & q pointers) */
node* search(node* root, int key) {
    if (!root || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

int main() {
    int arr[] = {6, 3, 17, 5, 11, 18, 2, 1, 20, 14};
    int n = 10;

    node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    cout << "BST Tree (Level Wise):\n";
    printTree(root);

    // nodes whose LCA we want
    node* p = search(root, 1);
    node* q = search(root, 14);

    node* ans = LCA(root, p, q);

    if (ans)
        cout << "\nLCA of " << p->data << " and " << q->data << " is: " << ans->data;
    else
        cout << "\nLCA not found";

    return 0;
}
