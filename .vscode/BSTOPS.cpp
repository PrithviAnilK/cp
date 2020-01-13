#include <bits/stdc++.h>
#define debug(num) cerr << #num << " " << num << endl;
#define F(itr,limit) for(int itr=0;itr<limit;itr++) 
#define Fll(itr,limit) for(long long itr=0;itr<limit;itr++) 
#define coutarr(list_name) F(i,list_name.size()) cout<<list_name[i]<<" "
#define cinarr(list_name) F(i, list_name.size()) cin>>list_name[i]
#define ll long long
#define pb push_back
using namespace std;

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

Node* insert(Node* root, int val)
{
    if(root == NULL) return new Node(val);
    else
    {
        if(val < root->data)
        {
            root->left = insert(root->left, val);
        }
        else
        {
            root->right = insert(root->right, val);
        }
        return root;
    }
}

Node *del(Node* root, int val)
{
    if(root == NULL) return root;
    if(root->data < val)
    {
        root->left = del(root->left, val);
    }
    else if(root->data > val)
    {
        root->right = del(root->right, val);
    }
    else
    {
        
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    Node* root = NULL;
    while (t--)
    {
        char id;
        int n;
        cin >> id >> n;
        root = (id=='i' ? insert(root, n) : del(root, n));
    }
	return 0;
}