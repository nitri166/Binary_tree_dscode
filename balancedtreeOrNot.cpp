#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right == NULL;
    }
};

node *buildTree(node *root)
{
    int data;
    cout << "Enter the data for the node " << endl;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for left node of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for right node of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
int height(node *root){
        if(root == NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        int ans= max(left,right)+1;
        return ans;
        
    }

bool isBalanced(node *root)
    {
        //  Your Code here
        if(root == NULL){
            return true;
        }
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        bool diff = abs(height(root->left)- height(root->right))<= 1;
        
        if(left && right && diff){
            return true;
            
        }
        else{
            return false;
        } 
    }   
int main(){
    node *root = NULL;
    root = buildTree(root);

    cout << "The tree is balanced or not: " << endl;

    cout << isBalanced(root);

    return 0;
}
