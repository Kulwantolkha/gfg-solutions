class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        vector<int> elements;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                elements.push_back(matrix[i][j]);
            }
        }
        sort(elements.begin(),elements.end());
        return elements[k-1];
    }
};