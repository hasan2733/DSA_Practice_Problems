class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        vector<pair<int,int>>ans;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back({nums[i],i});
        }
        sort(ans.rbegin(),ans.rend());
        return ans[0].second;
    }
};
