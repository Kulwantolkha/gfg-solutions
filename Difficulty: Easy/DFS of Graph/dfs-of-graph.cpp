//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs1(vector<vector<int>> adj, vector<int>& ans, vector<bool>& vis, int i){
        if(vis[i]==true)   return;
        vis[i]=true;
        ans.push_back(i);
        for(auto it : adj[i]){
                if(vis[it]==false){
                    dfs1(adj,ans,vis,it);
                }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> vis(n,false);
        vector<int> ans;
        int i=0;
        dfs1(adj,ans,vis,i);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends