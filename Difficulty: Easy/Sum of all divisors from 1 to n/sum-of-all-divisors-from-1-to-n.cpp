//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        // Write Your Code here
        // long long sum = 0;
        // for(int i=1;i<=N;i++){
        //     for(int j=1;j<=i;j++){
        //         if(i%j==0){
        //             sum=sum+j;
        //         }    
        //     }
        // }
        // return sum;
        
        long long sum=0;
        for(int i=1;i<=N;i++){
            for(int j=i;j<=N;j=j+i){
                sum=sum+i;
            }
        }
        return sum;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends