//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* divide(Node* head) {
        Node* dNo = NULL;
        Node* dNe = NULL;
        Node* temp = head;
        Node* t1 = NULL;
        Node* t2 = NULL;
        while(temp!=NULL){
            if(temp->data % 2 == 0){
                if(dNe==NULL){
                    dNe = temp;
                    t1 = dNe;
                }
                else{
                    t1->next = temp;
                    t1 = t1->next;
                }
            }
            else{
                if(dNo==NULL){
                    dNo = temp;
                    t2 = dNo;
                }
                else{
                    t2->next = temp;
                    t2 = t2->next;
                }
            }
            temp = temp->next;
        }
        // Ensure the last node of both lists points to NULL
        if(t1) t1->next = NULL;  // End of even list
        if(t2) t2->next = NULL;  // End of odd list
        
        if(dNo==NULL)   return dNe;
        if(dNe==NULL)   return dNo;
        
        t1->next = dNo;
        return dNe;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty())
            continue;

        int data = arr[0];
        int N = arr.size();
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 1; i < N; ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(head);
        printList(ans);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends