//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long sumOfSeries(long long n) {
        // code here
        // if(n==1){
        //     return 1;
        // }
        // return pow(n,3)+sumOfSeries(n-1);
        long long sum = (n * (n + 1)) / 2; // Sum of first n natural numbers
        return sum * sum;
   }

        
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.sumOfSeries(N) << "\n";
    }
}
// } Driver Code Ends