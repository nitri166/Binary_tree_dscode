#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    { // constructor
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildTree(node *root)
{

    cout << "Enter the data for Node:  " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << " Enter data for the inserting in left : " << data << endl;
    root->left = buildTree(root->left);
    cout << " Enter data for the inserting in right : " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
vector<int> zigzagTraversal(node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }

    queue<node *> q;
    q.push(root);

    bool leftToRight = true; // this flag is used to identify the direction of traversal

    while (!q.empty())
    {
        int size = q.size();
        vector<int> answer(size);
        // Processing a level
        for (int i = 0; i < size; i++)
        {

            node *temp = q.front();
            q.pop();

            // Then we will insert the elements of the level in the array answer after checking the value of flag
            int index = leftToRight ? i : size - i - 1;
            answer[index] = temp->data;

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        leftToRight = !leftToRight;
        for (auto i : answer)
        {
            result.push_back(i);
        }
    }
}

int main()
{

    node *root = NULL;

    // creating a tree

    root = buildTree(root);

    cout << " The zig zag traversal of this tree is: " << endl;
    vector<int> res;
    res = zigzagTraversal(root);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
