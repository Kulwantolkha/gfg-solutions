//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*You are required to complete this method */

class Solution {
  public:
    int josephus(int n, int k) {
        vector<int> person(n);
        iota(person.begin(),person.end(),1);
        int index = 0;
        while(person.size()!=1){
            int killIndex = (index+(k-1))%person.size();
            person.erase(person.begin()+killIndex);
            if(killIndex<person.size()) index = killIndex;
            else    index = 0;
        }
        return person[index];
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t; // testcases
    while (t--) {
        int n, k;
        cin >> n >> k; // taking input n and k

        // calling josephus() function
        Solution ob;
        cout << ob.josephus(n, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends