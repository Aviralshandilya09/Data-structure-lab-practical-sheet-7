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
void display(Node*root,int space=0){
    if(root==NULL)return;
    space+=5;
    display(root->right,space);
    cout<<'\n';
    for(int i=5;i<space;i++)cout<<' ';
    cout<<root->data<<'\n';
    display(root->left,space);
}
int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    cout<<"Binary Tree structure:\n";
    display(root);
    return 0;
}
