//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string str) {
        string ans = "";
        int i = str.length()-1;
        stack<string> st;
        while(i>=0){
            if(isalpha(str[i]) || isdigit(str[i])){
                st.push(string(1,str[i]));
            }
            else{
                string c1 = st.top();
                st.pop();
                string c2 = st.top();
                st.pop();
                string temp =c1+c2+str[i];
                st.push(temp);
            }
            i--;
        }
        return (st.top());
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends