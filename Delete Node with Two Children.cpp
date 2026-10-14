#include <iostream>
using namespace std;
struct Node{
    int data;
    Node*left;
    Node*right;
    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};
Node*insertNode(Node*root,int value){
    if(root==NULL)return new Node(value);
    if(value<root->data)root->left=insertNode(root->left,value);
    else if(value>root->data)root->right=insertNode(root->right,value);
    return root;
}
Node*minimumNode(Node*root){
    while(root!=NULL&&root->left!=NULL)root=root->left;
    return root;
}
Node*deleteNode(Node*root,int key){
    if(root==NULL)return NULL;
    if(key<root->data)root->left=deleteNode(root->left,key);
    else if(key>root->data)root->right=deleteNode(root->right,key);
    else{
        if(root->left==NULL){
            Node*temp=root->right;
            delete root;
            return temp;
        }
    if(root->right==NULL){
        Node*temp=root->left;
        delete root;
        return temp;
    }
Node*temp=minimumNode(root->right);
root->data=temp->data;
root->right=deleteNode(root->right,temp->data);
}
return root;
}
void inorder(Node*root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}
int main(){
    Node*root=NULL;
    int values[]={50,30,70,20,40,60,80};
    for(int i=0;i<7;i++)root=insertNode(root,values[i]);
    int key;
    cout<<"Enter node with two children to delete (try 50): ";
    cin>>key;
    root=deleteNode(root,key);
    cout<<"BST after deletion: ";
    inorder(root);
    cout<<'\n';
    return 0;
}
