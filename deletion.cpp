#include<iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        left=right=NULL;
    }
};
node* insert(node* root, int target){
    if(!root){ //only first case when rrot is null, means first element to be inserted
        node* newnode=new node(target);
        return newnode;
    }
    if(target<root->data) //left side
    root->left=insert(root->left,target);
    else //right side
   root->right= insert(root->right,target);
}
void inorder(node* root) {
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
 node* delNode(node* root, int target) {
        // code here
        //base conditions
        if(!root)
        return NULL;
        if(root->data>target){
        root->left=delNode(root->left,target);
            return root;
        }
       else if(root->data<target){
        root->right=delNode(root->right,target);
           return root;
       }
        else{
            //leaf node
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            else if(!root->right) //left child exist
            {
                node* temp=root->left;
                delete root;
                return temp;
            }
            else if(!root->left) //right child exist
            {
                node* temp=root->right;
                delete root;
                return temp;
            }
            //2 child exist
            else{
                node* child=root->left;
                node* parent=root;
                while(child->right)
                {
                    parent=child;
                child=child->right;
                }
                if(root!=parent){
                    parent->right=child->left;
                    child->left=root->left;
                    child->right=root->right;
                    delete root;
                    return child;
                }
                else{
                    child->right=root->right;
                    delete root;
                    return child;
                }
            }
        }
    }
    int main() {
    int arr[] = {6, 3, 17, 5, 11, 18, 2, 1, 20, 14};
    node* root = NULL;

    // Insert elements into BST
    for(int i = 0; i < 10; i++) {
        root = insert(root, arr[i]);
    }

    cout << "BST before deletion: ";
    inorder(root);
    cout << endl;

    // Delete a node
    int target = 17;
    root = delNode(root, target);

    cout << "BST after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
