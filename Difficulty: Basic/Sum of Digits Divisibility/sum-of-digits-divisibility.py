#User function Template for python3

class Solution:
    def isDivisible(self,N):
        #code here
        sum = 0
        new = N
        while(N>0):
            n = N%10
            sum = sum+N%10
            N//=10
        if(new%sum==0):
            return 1
        else:
            return 0

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        N=int(input())
        ob=Solution()
        print(ob.isDivisible(N))
# } Driver Code Ends