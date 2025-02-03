//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int f(int i){
        if(i%4==1)  return 1;
        if(i%4==2)  return i+1;
        if(i%4==3)  return 0;
        if(i%4==0)  return i;
    }
    int findXOR(int l, int r) {
        return f(l-1) ^ f(r);
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends