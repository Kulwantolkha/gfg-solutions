class Solution {
  public:
    vector<int> prefSum(vector<int> &arr) {
        int sum = 0;
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            ans.push_back(sum);
        }
        return ans;
    }
};