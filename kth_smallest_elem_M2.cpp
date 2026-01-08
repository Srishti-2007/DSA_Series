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
   return root;
}
int check(node* root, int &k){
    if(root==NULL){
        return -1;
    }
   int left =check(root->left,k);
   if(left !=-1) return left;
    k--;
    if(k==0){
        return root->data;
    }
   return check(root->right,k);
}
int main(){
    int arr[]={6,3,17,5,11,18,2,1,20,14};
    node* root=NULL;
    for(int i=0;i<10;i++){
        root=insert(root,arr[i]);
    }
    int k=21;
    cout<<"Kth smallest element : ";
    cout<<check(root,k);
}