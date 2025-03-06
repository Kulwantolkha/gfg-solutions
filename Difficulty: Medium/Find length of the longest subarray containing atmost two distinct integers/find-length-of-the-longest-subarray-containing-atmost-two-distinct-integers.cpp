//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int maxi = 0;
        set<int> st;
        for(int i=0;i<arr.size();i++){
            int cnt = 0;
            for(int j=i;j<arr.size();j++){
                if(st.find(arr[j])==st.end()){
                    st.insert(arr[j]);
                }
                if(st.size()>2){
                    st.clear();
                    break;
                }
                cnt+=1;
                maxi = max(maxi,cnt);
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalElements(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends