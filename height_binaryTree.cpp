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

    cout << "Enter the data for left node of the tree " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for right node of the tree " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);

    cout << "Print the height of the binary tree : " << endl;
    cout << height(root);

    return 0;
}