//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int priority(char ch){
        if(ch=='^'){
            return 3;
        }
        else if(ch=='+'|| ch=='-'){
            return 1;
        }
        else if(ch=='*' || ch== '/'){
            return 2;
        }
        return -1;
    }
    string infixToPostfix(string& s) {
        string str = "";
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i]) || isdigit(s[i])){
                str.push_back(s[i]);
            }
            else if(s[i]=='(' || s[i]==')'){
                if(s[i]=='('){
                    st.push(s[i]);
                }
                else{
                    while(!st.empty() && st.top()!='('){
                        str.push_back(st.top());
                        st.pop();
                    }
                    if(!st.empty()) st.pop();
                }
            }
            else{
                while(!st.empty() && priority(s[i]) <= priority(st.top())){
                    str.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            str.push_back(st.top());
            st.pop();
        }
        return str;
    }
};

//{ Driver Code Starts.
//  Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends