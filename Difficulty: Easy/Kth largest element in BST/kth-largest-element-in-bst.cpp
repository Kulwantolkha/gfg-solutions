//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    int sizeofTree(Node* root, int& n){
        if(!root)   return n;
        if(root)    n++;
        sizeofTree(root->left,n);
        sizeofTree(root->right,n);
        return n;
    }
    int traversal(Node* root,int k, int& cnt, bool& found){
        if(!root)   return 0;
        int left = traversal(root->left,k,cnt,found);
        if(found)   return left;
        cnt++;
        if(cnt==k){
            found = true;
            return root->data;
        }
        return traversal(root->right,k,cnt,found);
    }
    int kthLargest(Node *root, int k) {
        int cnt = 0 ;
        bool found = false;
        int z = 0;
        int n = sizeofTree(root,z);
        return traversal(root,n-k+1,cnt,found);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    getchar();

    while (t--) {
        string s;
        getline(cin, s);
        Node* head = buildTree(s);

        int k;
        cin >> k;
        getchar();

        Solution ob;
        cout << ob.kthLargest(head, k) << endl;

        cout << "~"
             << "\n";
    }
    return 1;
}
// } Driver Code Ends