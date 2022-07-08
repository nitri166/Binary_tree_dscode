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
    cout << "Enter the data for the node " << endl;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for the left side of the node : " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for the right side of the node : " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
pair<int, int> diameterHeight(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterHeight(root->left);
    pair<int, int> right = diameterHeight(root->right);

    int op1 = left.first;
    int op2 = right.first;

    int op3 = left.second + right.second + 1; // display and calculate height for a node

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}

int main()
{

    node *root = NULL;
    root = buildTree(root);

    cout << "Diameter of the binary tree : " << endl;

    cout << diameterHeight(root).first;

    return 0;
}