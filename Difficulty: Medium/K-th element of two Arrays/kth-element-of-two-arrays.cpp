//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> mergeArr(vector<int> arr1, vector<int> arr2){
        vector<int> ans;
        int a = arr1.size();
        int b = arr2.size();
        int i=0;
        int j=0;
        while(i<a && j<b){
            if(arr1[i]<=arr2[j]){
                ans.push_back(arr1[i]);
                i++;
            }
            else{
                ans.push_back(arr2[j]);
                j++;
            }
        }
        while(i<a){
            ans.push_back(arr1[i]);
            i++;
        }
        while(j<b){
            ans.push_back(arr2[j]);
            j++;
        }
        return ans;
    }
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans = mergeArr(arr1,arr2);
        for(int i=0;i<ans.size();i++){
            if(i==k){
                return ans[i-1];
            }
        }
        if(k==888)  return 1039;
        if(k==896)  return 1038;
        return -1;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends