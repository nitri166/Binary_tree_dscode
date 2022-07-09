#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){ // constructor
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }

};
node* buildTree(node* root){

    cout<< "Enter the data for Node:  "<<endl;
    int data ;
    cin>>data;
    root = new node(data);

    if(data ==-1){
        return NULL;
    }

    cout<< " Enter data for the inserting in left : "<<data<< endl;
    root-> left = buildTree(root->left);
    cout<< " Enter data for the inserting in right : "<<data<<endl;
    root-> right = buildTree(root->right);
    return root;




}
pair<bool,int> isSumTreeorNot(node * root){

    //base condition 1
    if(root== NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    //base conditon 2
    if(root->left==NULL && root->right == NULL){

        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftAns = isSumTreeorNot(root->left);
    pair<bool,int> rightAns = isSumTreeorNot(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool condition = root->data == leftAns.second+rightAns.second;



    pair<bool,int> ans;
    if(left && right && condition){
        ans.first= true;
        ans.second = 2*root->data;    }
    else{
        ans.first= false;
    }    

    return ans;
}

int main(){

    node* root= NULL;  

    //creating a tree

    root = buildTree(root);

    cout<<" Is the above tree a sum tree or not? : "<<endl;
    cout<< isSumTreeorNot(root).first;
// if output is equal to 1 means the above tree is a sum tree

    return 0;
}
