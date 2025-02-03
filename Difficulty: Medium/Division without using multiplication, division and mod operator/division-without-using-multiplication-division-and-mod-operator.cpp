//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long n, long long d) 
    {
        if(n==0)    return 0;
        int sign = (n<0) ^ (d<0) ? -1:1;
        long long nabs = abs(n);
        long long dabs = abs(d);
        long long q = 0;
        while(nabs>=dabs){
            int cnt = 0;
            while((dabs<<(cnt+1))<=nabs){
                cnt++;
            }
            nabs-=(dabs<<cnt);
            q+=(1<<cnt);
        }
        return q*sign;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	
cout << "~" << "\n";
}

	return 0;
}

// } Driver Code Ends