#include<iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        this->data=val;
        left=right=NULL;
    }
};
node* insert(node* root, int target){
    if(!root){
        node* newnode=new node(target);
        return newnode;
    }
    if(target<root->data)
    root->left=insert(root->left,target);
    else
    root->right=insert(root->right,target);
}
bool search(node* root, int target){
    if(!root)
    return 0;
    if(target==root->data)
    return 1;
    if(target<root->data)
    return search(root->left,target);
    else
    return search(root->right,target);
}
int main(){
    int arr[]={6,3,17,5,11,18,2,1,20,14};
    node* root=NULL;
    for(int i=0;i<10;i++)
    root=insert(root,arr[i]);
    cout<<endl;
    //searching operation
    cout<<search(root,2)<<endl;
}