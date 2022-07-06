#include <iostream>
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
        this->right = NULL;
    }
};

node *buildTree(node *root)
{

    int data;
    cout << "Enter the data " << endl;
    cin >> data;

    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << " Enter the data to the left of the node" <<data << endl;
    root->left = buildTree(root->left);
    cout << " Enter the data to the right of the node"<<data << endl;
    root->right = buildTree(root->right);
    return root;
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{

    node *root = NULL;
    root = buildTree(root);

    cout << "Print the Preorder traversal for the tree " << endl;
    preorder(root);

    return 0;
}