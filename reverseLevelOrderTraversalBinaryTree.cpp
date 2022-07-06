#include <iostream>
#include <stack>
#include<queue>
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

void reverseLevelOrderTraversal(node *root)
{
    stack<node *> s;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        s.push(temp);

        if(temp -> right){
            q.push(temp -> right);
        }

        if(temp -> left){
            q.push(temp -> left);
        }
    }

    while(!s.empty()){

        root = s.top();
        cout<< root->data << " ";
        s.pop();

    }



        
}



node *buildTree(node *root)
{

    cout << "Enter the data for the node :" << endl;
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << " enter the left node to the data " << data << endl;
    root->left = buildTree(root->left);
    cout << " enter the right node to the data " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

int main()
{
    node *root = NULL;

    root = buildTree(root);

    cout << "Reverse level order traversal is : " << endl;

    reverseLevelOrderTraversal(root);

    return 0;
}
