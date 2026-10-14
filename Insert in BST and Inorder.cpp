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
void inorder(Node*root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}
int main(){
    Node*root=NULL;
    int n,value;
    cout<<"Enter number of elements: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter value: ";
        cin>>value;
        root=insertNode(root,value);
    }
cout<<"Inorder Traversal: ";
inorder(root);
cout<<'\n';
return 0;
}
