//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        int i = 0;
        stack<string> st;
        string ans = "";
        while(i<exp.length()){
            if(isalpha(exp[i]) || isdigit(exp[i])){
                st.push(string(1,exp[i]));
            }
            else{
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                string temp = "("+s2+exp[i]+s1+")";
                st.push(temp);
            }
            i++;
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
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    fclose(stdout);

    return 0;
}

// } Driver Code Ends