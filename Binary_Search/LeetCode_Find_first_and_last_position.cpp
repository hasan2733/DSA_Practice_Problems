class Solution {
public:
    int upperBound(vector<int>& nums,int target)
    {
        int left = 0, right = nums.size()-1,ans = nums.size();
        while(left<=right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid]>target)
            {
                ans = mid;
                right = mid - 1;
            }
            else 
             left = mid +1 ;
        }
        return ans;
    }

    int lowerBound(vector<int>& nums,int target)
    {
        int left = 0, right = nums.size()-1,ans = nums.size();
        while(left<=right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid]>=target)
            {
                ans = mid;
                right = mid - 1;
            }
            else 
             left = mid + 1 ;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums,target);
        int last = upperBound(nums,target) - 1;

        if(first < nums.size() && nums[first]==target)
         return {first,last};
        return {-1,-1};
    }
};
