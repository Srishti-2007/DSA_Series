#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    TreeNode* BST(vector<int>& preorder, int &index, int l, int u) {
        if (index == preorder.size() || preorder[index] < l || preorder[index] > u)
            return NULL;

        TreeNode* root = new TreeNode(preorder[index++]);

        root->left = BST(preorder, index, l, root->val);
        root->right = BST(preorder, index, root->val, u);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return BST(preorder, index, INT_MIN, INT_MAX); // ✅ FIX
    }
};

// ---------- DRIVER CODE ----------
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Solution obj;
    TreeNode* root = obj.bstFromPreorder(preorder);

    cout << "Inorder traversal of constructed BST: ";
    inorder(root);

    return 0;
}
