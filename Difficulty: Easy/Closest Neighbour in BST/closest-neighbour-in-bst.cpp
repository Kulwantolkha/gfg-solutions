/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void smallestnum(Node* root, int k, int& ans){
        if(!root)   return;
        if(root->data <= k && root->data > ans){
            ans = root->data;
        }
        if(root->data > k){
            smallestnum(root->left,k,ans);
        }
        else{
            smallestnum(root->right,k,ans);
        }
    }
    int findMaxFork(Node* root, int k) {
        int ans = -1;
        smallestnum(root,k,ans);
        return ans;
    }
};