//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        vector<int> ans(arr.size(),0);
        stack<int> st1;
        stack<int> st2;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st1.empty() && st1.top()<=arr[i]){
                st2.push(st1.top());
                st1.pop();
            }
            ans[i] = st1.empty() ? 0 : st1.size();
            st1.push(arr[i]);
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
        }
        vector<int> f(queries,0);
        for(int i=0;i<queries;i++){
            f[i] = ans[indices[i]];
        }
        return f;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> v1(n);
       for(int i = 0;i<n;i++) cin >> v1[i];
        int q; cin >> q;
        vector<int> v2(q);
        for(int i = 0;i<q;i++) cin >> v2[i];

        Solution obj;
        vector<int> ans = obj.count_NGE(n,v1,q,v2);

        for(int i = 0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends