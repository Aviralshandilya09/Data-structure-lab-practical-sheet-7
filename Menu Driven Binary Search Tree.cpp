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
void preorder(Node*root){
    if(root==NULL)return;
    cout<<root->data<<' ';
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node*root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<' ';
}
int height(Node*root){
    if(root==NULL)return 0;
    int l=height(root->left);
    int r=height(root->right);
    return 1+(l>r?l:r);
}
int countNodes(Node*root){
    if(root==NULL)return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}
int main(){
    Node*root=NULL;
    int choice,value;
    do{
        cout<<"\n1. Insert\n2. Search\n3. Inorder\n4. Preorder\n5. Postorder\n6. Delete\n7. Height\n8. Count Nodes\n9. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"Enter value: ";
            cin>>value;
            root=insertNode(root,value);
            break;
            case 2:
            cout<<"Enter value to search: ";
            cin>>value;
            if(searchNode(root,value))cout<<"Element found\n";
            else cout<<"Element not found\n";
            break;
            case 3:
            cout<<"Inorder: ";
            inorder(root);
            cout<<'\n';
            break;
            case 4:
            cout<<"Preorder: ";
            preorder(root);
            cout<<'\n';
            break;
            case 5:
            cout<<"Postorder: ";
            postorder(root);
            cout<<'\n';
            break;
            case 6:
            cout<<"Enter value to delete: ";
            cin>>value;
            root=deleteNode(root,value);
            break;
            case 7:
            cout<<"Height: "<<height(root)<<'\n';
            break;
            case 8:
            cout<<"Total nodes: "<<countNodes(root)<<'\n';
            break;
            case 9:
            cout<<"Program ended\n";
            break;
            default:
            cout<<"Invalid choice\n";
        }
}while(choice!=9);
return 0;
}
