#include<iostream>
#include<vector>
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
bool is_bst(node* root,int &prev){
    if(root==NULL)
    return 1;
    bool l=is_bst(root->left,prev);
    if(l==0)
    return 0;
    if(root->data<=prev)
    return 0;
    prev=root->data;
    return is_bst(root->right,prev);
}
int main(){
    int arr[]={6,3,17,5,11,18,2,1,20,14};
    node* root=NULL;
    for(int i=0;i<10;i++){
        root=insert(root,arr[i]);
    }
    //check bst
     int prev=-1;
    cout<<is_bst(root,prev);
}