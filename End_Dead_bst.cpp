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
bool dead(node* root, int l, int u){
    if(root==NULL)
    return 0;
    //leaf case and check is it end dead?
    if(!root->left&&!root->right){
        if(root->data-l==1&&u-root->data==1)
        return 1;
        else 
        return 0;
    }
    return dead(root->left,l,root->data)||dead(root->right,root->data,u);
}
int main(){
    int arr[]={6,3,17,5,11,18,2,1,20,14};
    node* root=NULL;
    for(int i=0;i<10;i++){
        root=insert(root,arr[i]);
    }
    //dead case
    cout<<dead(root,0,50);
}