//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        vector<int> uni;
        int i=0;
        int j=0;
        int last_element = -1;
        while(i<a.size() && j<b.size()){
            if(a[i]<b[j]){
                if(a[i]!=last_element){
                    uni.push_back(a[i]);
                    last_element=a[i];
                }
                i++;
            }
            else if(a[i]==b[j]){
                if(a[i]!=last_element){
                    uni.push_back(a[i]);
                    last_element=a[i];
                }
                i++;
                j++;
            }
            else{
                if(b[j]!=last_element){
                    uni.push_back(b[j]);
                    last_element=b[j];
                }
                j++;
            }
        }
        while(i<a.size()){
            if(a[i]!=last_element){
                uni.push_back(a[i]);
                last_element=a[i];
            }
            i++;
        }
        while(j<b.size()){
            if(b[j]!=last_element){
                uni.push_back(b[j]);
                last_element=b[j];
            }
            j++;
        }
        return uni;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends