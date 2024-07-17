#User function Template for python3

class Solution:
    def getPairsCount(self, arr, sum):
        # code here
        count=0
        freq = {}
        for num in arr:
            if sum-num in freq:
                count = count + freq[sum - num]
            
            if num in freq:
                freq[num] += 1
            else:
                freq[num] = 1
        return count
                


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input().strip())

    while tc > 0:
        k = int(input().strip())
        arr = list(map(int, input().strip().split()))

        ob = Solution()
        ans = ob.getPairsCount(arr, k)
        print(ans)

        tc -= 1

# } Driver Code Ends