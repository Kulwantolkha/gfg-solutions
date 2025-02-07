//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string str) {
        int i = 0;
        string ans = "";
        stack<string> st;
        while(i<str.length()){
            if(isalpha(str[i]) || isdigit(str[i])){
                st.push(string(1,str[i]));
            }
            else{
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                string temp = str[i]+s2+s1;
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
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends