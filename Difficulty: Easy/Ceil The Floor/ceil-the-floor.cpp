//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int k, vector<int> &arr) {
        int floor=INT_MIN;
        int ceil=INT_MAX;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=k){
                // floor = arr[i];
                floor = max(floor,arr[i]);
            }
            if(arr[i]>=k){
                // ceil = arr[i];
                ceil = min(ceil,arr[i]);
            }
        }
        if(floor==INT_MIN)  floor=-1;
        if(ceil==INT_MAX)  ceil=-1;
        ans.push_back(floor);
        ans.push_back(ceil);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends