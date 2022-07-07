#include <iostream>
#include <queue>
using namespace std;

// printing nodes in level order traversal
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

void levelOrderTraversal(node *root)
{
    // we are pushing all nodes in a queue so that we can print them in
    // level order traversal
    queue<node *> q;
    q.push(root);
    q.push(NULL); // seperator after the 1st root element

    while (!q.empty())
    {
        node *temp = q.front();

        

        q.pop();

        if (temp == NULL)
        {
            cout << endl; 
            if (!q.empty())
            {
                q.push(NULL); // seperator for each level
            }
        }

        else
        {
            cout<<temp -> data<< " ";
            if (temp->left)
            {

                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
node *buildTree(node *root)
{
    cout << "Enter the data :" << endl;
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for the left part of the node " << data << endl;
    root->left = buildTree(root->left);
    cout << " Enter the data for the right part of the node " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

int main()
{

    node *root = NULL;
    // Creating tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // Printing tree in level order traversal

    levelOrderTraversal(root);

    // we have to use seperator which will show output level wise
    return 0;
}
