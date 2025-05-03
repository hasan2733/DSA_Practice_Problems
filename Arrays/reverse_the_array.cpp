class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        vector<int>temp;
        for(int i=arr.size()-1;i>=0;i--)
        {
            temp.push_back(arr[i]);
        }
        for(int i=0;i<arr.size();i++)
        {
            arr[i] = temp[i];
        }
        
    }
};

