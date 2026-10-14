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
bool searchNode(Node*root,int key){
    if(root==NULL)return false;
    if(root->data==key)return true;
    if(key<root->data)return searchNode(root->left,key);
    return searchNode(root->right,key);
}
int main(){
    Node*root=NULL;
    int values[]={50,30,70,20,40,60,80};
    for(int i=0;i<7;i++)root=insertNode(root,values[i]);
    int key;
    cout<<"Enter value to search: ";
    cin>>key;
    if(searchNode(root,key))cout<<"Element found\n";
    else cout<<"Element not found\n";
    return 0;
}
