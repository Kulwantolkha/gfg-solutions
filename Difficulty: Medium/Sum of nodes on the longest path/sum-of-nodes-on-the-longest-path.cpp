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
    void dfs(Node* root,int templen,int sum,int& len, int& ans){
        if(!root)   return;
        templen++;
        sum+=root->data;
        if(!root->left && !root->right){
            if(templen>len){
                len = templen;
                ans = sum;
            }
            else if(templen==len && sum>ans){
                ans = sum;
            }
        }
        dfs(root->left,templen,sum,len,ans);
        dfs(root->right,templen,sum,len,ans);
    }
    int sumOfLongRootToLeafPath(Node *root) {
        int len=0 , ans = 0;
        dfs(root,0,0,len,ans);
        return ans;
    }
};