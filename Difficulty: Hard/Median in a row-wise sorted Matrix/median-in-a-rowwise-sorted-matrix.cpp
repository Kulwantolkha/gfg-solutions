//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int totalSize = n*n;
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans.push_back(mat[i][j]);
            }
        }
        sort(ans.begin(),ans.end());
        int mid = ans.size()/2;
        int median = ans[mid];
        return median;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends