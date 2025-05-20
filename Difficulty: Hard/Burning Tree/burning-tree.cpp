//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
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
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int findtime(map<Node*,Node*> mpp,Node* newroot){
        int cnt=0;
        queue<Node*> q;
        q.push(newroot);
        map<Node*,bool> vis;
        vis[newroot]=1;
        while(!q.empty()){
            int sz = q.size();
            bool flg = false;
            for(int i=0;i<sz;i++){
                Node* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    flg=true;
                    vis[curr->left]=1;
                    q.push(curr->left);
                }
                if(curr->right && !vis[curr->right]){
                    flg = true;
                    vis[curr->right]=1;
                    q.push(curr->right);
                }
                if(mpp[curr] && !vis[mpp[curr]]){
                    flg = true;
                    vis[mpp[curr]]=1;
                    q.push(mpp[curr]);
                }
            }
            if(flg) cnt++;
        }
        return cnt;
    }
    void bfs(Node* root, map<Node*,Node*>& mpp,Node* &newroot,int target){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* parentNode = q.front();
            if(parentNode->data==target)    newroot = parentNode;
            q.pop();
            if(parentNode->left){
                mpp[parentNode->left] = parentNode;
                q.push(parentNode->left);
            }
            if(parentNode->right){
                mpp[parentNode->right] = parentNode;
                q.push(parentNode->right);
            }
        }
    }
    int minTime(Node* root, int target) {
        map<Node*,Node*> parpoi;
        Node* newroot = root;
        bfs(root,parpoi,newroot,target);
        return findtime(parpoi,newroot);
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends