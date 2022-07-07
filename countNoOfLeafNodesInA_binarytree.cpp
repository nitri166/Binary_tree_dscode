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
    cout << "Enter the data for tha node " << endl;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the left node for the node " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the right node for the node " << data << endl;
    root->right = buildTree(root->right);

    return root;
}
void countNoOfleaf(node *root, int &count)
{
    // here we want to keep the state of count saved in every call so we pass refereance

    if (root == NULL)
    {
        return;
    }
    countNoOfleaf(root->left, count);
    if (root->left == NULL && root->right == NULL)
    {
        count = count + 1;
    }
    countNoOfleaf(root->right, count);
}

int main()
{
    int count = 0;
    node *root = NULL;
    root = buildTree(root);

    countNoOfleaf(root, count);
    cout << "No of leaf nodes in the tree are : " << count << endl;

    return 0;
}