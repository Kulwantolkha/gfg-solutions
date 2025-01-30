//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void bitManipulation(int num, int i) {
        int bit = num & (1 << (i-1));
        if (bit != 0)
            cout << "1 ";
        else
            cout << "0 ";
        int setBit = num | (1 << (i-1));
        cout << setBit << " ";
        if(bit==0){
            cout<< num;
        }
        else{
            int newbit = num ^ bit;
            cout<< newbit;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends