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
Node*deleteOneChild(Node*root,int key){
    if(root==NULL)return NULL;
    if(key<root->data)root->left=deleteOneChild(root->left,key);
    else if(key>root->data)root->right=deleteOneChild(root->right,key);
    else{
        if(root->left==NULL&&root->right!=NULL){
            Node*temp=root->right;
            delete root;
            return temp;
        }
    if(root->right==NULL&&root->left!=NULL){
        Node*temp=root->left;
        delete root;
        return temp;
    }
cout<<"Node does not have exactly one child\n";
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
    int values[]={50,30,70,20,40,60,80,65};
    for(int i=0;i<8;i++)root=insertNode(root,values[i]);
    int key;
    cout<<"Enter node with one child to delete (try 60): ";
    cin>>key;
    root=deleteOneChild(root,key);
    cout<<"BST after deletion: ";
    inorder(root);
    cout<<'\n';
    return 0;
}
