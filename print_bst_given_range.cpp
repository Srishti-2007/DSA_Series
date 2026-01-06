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
void range(node* root,int n1 , int n2){
    if(!root)
    return;
    if(root->data>n1 && root->data>n2)
    range(root->left,n1,n2);
    else if(root->data<n1&&root->data<n2)
    range(root->right,n1,n2);
    else{
        range(root->left,n1,n2);
        cout<<root->data<<" ";
        range(root->right,n1,n2);
    }
}
int main(){
    int arr[]={6,3,17,5,11,18,2,1,20,14};
    node* root=NULL;
    for(int i=0;i<10;i++){
        root=insert(root,arr[i]);
    }
    cout<<"range data";
    range(root,10,20);
}