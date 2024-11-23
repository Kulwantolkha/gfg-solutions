//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        int ans = 0;
        int low = 1;
        int high = n;
        while(low<=high){
            int mid = (low+high)/2;
            if(mid*mid==n){
                return mid;
                break;
            }
            if(mid*mid > n){
                high = mid-1;
            }
            else if(mid*mid < n){
                ans = mid;
                low = mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends