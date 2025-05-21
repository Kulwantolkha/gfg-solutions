class Solution {
  public:
    bool whichsmaller(int m,int n, int k, int num){
        int c = 0;
        for(int i=1;i<=m;i++){
            c += min(n,num/i);
        }
        return c>=k;
    }
    int kthSmallest(int m, int n, int k) {
        int low = 1;
        int high = m*n;
        while(low<high){
            int mid = (low+high)/2;
            if(whichsmaller(m,n,k,mid)) high=mid;
            else    low = mid+1;
        }
        return low;
    }
};
