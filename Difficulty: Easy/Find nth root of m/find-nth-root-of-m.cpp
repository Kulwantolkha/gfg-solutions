//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int nthRoot(int n, int m) {
        int low = 1;
        int high = m;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int mid1 = pow(mid,n);
            // cout<<mid<<":"<<mid1<<":"<<high<<":"<<low<<endl;
            if(mid1==m){
                ans = mid;
                break;
            }
            if(mid1>m){
                high = mid-1;
            }
            else if(mid1<m){
                low = mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends