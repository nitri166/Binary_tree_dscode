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
    cout << "Enter the data : " << endl;
    cin >> data;

    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << " Enter the data to the left of the node" << data << endl;
    root->left = buildTree(root->left);
    cout << " Enter the data to the right of the node" << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{

    node *root = NULL;
    // build a tree
    root = buildTree(root);

    // post order traversal

    cout << " Print postorder traversal of the tree: "<<endl;
    postorder(root);

    return 0;
}