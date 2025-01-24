//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // int additionofsubset(vector<int>& arr,vector<int>& subset,vector<int>& ans,int index){
    //     for(int i=index;i<arr.size();i++){
    //         subset.push_back(arr[i]);
    //         ans.push_back(arr[i]);
    //         additionofsubset(arr,subset,ans,index+1);
    //         if(subset.size()>1){
    //             int sum = 0;
    //             for(int j=0;j<subset.size();j++){
    //                 sum+=subset[j];
    //             }
    //             ans.push_back(sum);
    //         }
    //         subset.pop_back();
    //         return 0;
    //     }
    // }
    int picknotpick(vector<int>& arr,vector<int>& ans,int sum,int index){
        if(index==arr.size()){
            ans.push_back(sum);
            return 0;
        }
        picknotpick(arr,ans,sum+arr[index],index+1);
        picknotpick(arr,ans,sum,index+1);
        
    }
    vector<int> subsetSums(vector<int>& arr) {
        // vector<int> subset;
        vector<int> ans;
        int index = 0;
        picknotpick(arr,ans,0,index);
        // additionofsubset(arr,subset,ans,index);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input

    while (t--) {
        vector<int> inputArray;
        string inputLine;

        // Input format: first number n followed by the array elements
        getline(cin, inputLine);
        stringstream inputStream(inputLine);
        int num;
        while (inputStream >> num) {
            inputArray.push_back(num); // Read the array elements from input string
        }

        Solution solutionObject;
        vector<int> result = solutionObject.subsetSums(inputArray);
        sort(result.begin(), result.end());

        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout
            << endl
            << "~\n"; // Print results in list format with new line after each test case
    }

    return 0;
}

// } Driver Code Ends