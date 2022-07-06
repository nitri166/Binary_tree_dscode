#include<iostream>
using namespace std;

class node{

    public:
    int data;
    node *left;
    node *right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
        }




};

node *buildTree(node* root){
    int data;
    cout<< "Enter the data : "<< endl;
    cin >> data;

    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<< "Enter the data for inserting in left of node "<< data<<endl;
    root-> left = buildTree(root-> left);
    cout<< "Enter the data for inserting in right of node "<< data<<endl;
    root-> right = buildTree(root-> right);
    return root;


    
}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<< root-> data<< " ";
    inorder(root->right);
}
int main(){

    node * root = NULL;
    root = buildTree(root);
    
    cout<< "Print the inorder traversal:- "<<endl;

    inorder(root);
    return 0;
}