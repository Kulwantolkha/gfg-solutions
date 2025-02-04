//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

bool pairWiseConsecutive(stack<int> s);

// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        stack<int> s;
        int n, tmp;
        cin>>n;
        while(n--){
            cin>>tmp;
	        s.push(tmp);
	    }
	    if (pairWiseConsecutive(s))cout << "Yes" << endl;
	    else cout << "No" << endl;
	    /*while (s.empty() == false)
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout<<endl;*/
    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends


//User function Template for C++
bool pairWiseConsecutive(stack<int> s)
{
    if(s.size()%2!=0)   s.pop();
    while(s.empty()!=true){
        int t1 = s.top();
        s.pop();
        int t2 = s.top();
        s.pop();
        if(abs(t1-t2)!=1){
            return false;
        }
    }
    return true;
}