//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends

/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    Node* buildcompleteTree(vector<int> inorder,int insrt,int inend,vector<int> postorder,int postsrt,int postend,map<int,int> mpp){
        if(insrt>inend || postsrt>postend)  return nullptr;
        Node* root = new Node(postorder[postend]);
        int inRoot = mpp[root->data];
        int numsLeft = inRoot - insrt;
        root->left = buildcompleteTree(inorder,insrt,inRoot-1,postorder,postsrt,postsrt+numsLeft-1,mpp);
        root->right = buildcompleteTree(inorder,inRoot+1,inend,postorder,postsrt+numsLeft,postend-1,mpp);
        return root;
    }
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        int n = postorder.size();
        int m = inorder.size();
        if(n==0 || m==0)    return NULL;
        map<int,int> mpp;
        for(int i=0;i<m;i++){
            mpp[inorder[i]] = i;
        }
        Node* root = buildcompleteTree(inorder,0,m-1,postorder,0,n-1,mpp);
        return root;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> inorder;
        int number;
        while (ss >> number) {
            inorder.push_back(number);
        }

        getline(cin, input);
        stringstream ss2(input);
        vector<int> postorder;
        while (ss2 >> number) {
            postorder.push_back(number);
        }
        Solution obj;
        Node* root = obj.buildTree(inorder, postorder);
        preOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends