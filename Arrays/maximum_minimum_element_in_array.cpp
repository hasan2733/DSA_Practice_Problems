//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        pair<int,int>res;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<mini)
             mini = arr[i];
        }
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>maxi)
             maxi = arr[i];
        }
        res.first = mini;
        res.second = maxi;
        return res;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        pair<int, int> pp = ob.getMinMax(arr);
        cout << pp.first << " " << pp.second << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
