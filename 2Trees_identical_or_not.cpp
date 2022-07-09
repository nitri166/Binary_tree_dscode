#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node* left;
    node * right;

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
    cout << "Enter the data for the node : " << endl;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << " Enter data for inserting in left of  " << data << endl;
    root->left = buildTree(root->left);
    cout << " Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

bool isIdentical(node  * r1, node * r2){

     if(r1==NULL && r2 == NULL){
            return true;
        }
        
        if((r1==NULL) && r2!=NULL){
            return false;
        }
        if(r1!= NULL && r2==NULL){
            return false;
        }
        bool left = isIdentical(r1->left, r2-> left);
        bool right = isIdentical(r1->right, r2->right);

        bool value = r1->data == r2->data; // this checks whether the data of the node is identical or not

        if(left && right && value ){
            return true;
        }
        else{return false;}
    
}

int main()
{


    cout<< "Creating first tree:"<<endl;
    node* tree1 =NULL;
    tree1 = buildTree(tree1);

    cout<< "Creating second tree:"<<endl;

    node * tree2 = NULL;
    tree2 = buildTree(tree2);


    cout<< "Are the two trees identical? : "<<endl;
    cout<< isIdentical(tree1, tree2);

    // if result is equal to 1 means both the trees are identical else not.
    
    return 0;
}