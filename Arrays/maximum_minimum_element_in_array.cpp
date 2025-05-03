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
