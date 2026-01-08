#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    void inorder(Node* root, vector<int>& ans) {
        if (!root) return;

        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

    vector<int> merge(Node* root1, Node* root2) {
        vector<int> ans1, ans2;
        inorder(root1, ans1);
        inorder(root2, ans2);

        vector<int> ans;
        int i = 0, j = 0;

        while (i < ans1.size() && j < ans2.size()) {
            if (ans1[i] < ans2[j])
                ans.push_back(ans1[i++]);
            else
                ans.push_back(ans2[j++]);
        }

        while (i < ans1.size())
            ans.push_back(ans1[i++]);

        while (j < ans2.size())
            ans.push_back(ans2[j++]);

        return ans;
    }
};

int main() {
    /*
        Tree 1:
              3
             / \
            1   5

        Tree 2:
              4
             / \
            2   6
    */

    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    Solution obj;
    vector<int> result = obj.merge(root1, root2);

    cout << "Merged BST elements: ";
    for (int x : result)
        cout << x << " ";

    return 0;
}
