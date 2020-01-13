//---------- prithvianilk's BST template ----------//
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Inserts a new node in the BST whose root is known and value to be added is val.
Node* insert(Node* root, int val)
{
    if(root == NULL) return new Node(val);
    else
    {
        if(val < root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
        return root;
    }
}

// Node* del(Node* root, int val)
// {

// }

// Returns node having same value as value to be searched. If NULL, node is absent.
Node* search(Node* root, int& val)
{
    if(root == NULL || root->data == val) return root;
    if(val < root->data)
        return search(root->left, val);
    else
        return search(root->right,val);
}

// Inorder (Left, Root, Right)
void inorder(Node* root)
{
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder (Root, Left, Right)
void preorder(Node* root)
{
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder (Left, Right, Root)
void postorder(Node* root)
{
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << (root->data) << " ";
}

// Returns the node corresponding to the minimum value in the BST whose root is known. 
Node* minBST(Node* root)
{
    if(root == NULL) return root;
    if(root->left == NULL) return root;
    return minBST(root->left);
}

// Returns the node corresponding to the maximum value in the BST whose root is known. 
Node* maxBST(Node* root)
{
    if(root->right == NULL) return root;
    return maxBST(root->right);
}
