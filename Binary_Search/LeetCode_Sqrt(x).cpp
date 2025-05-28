class Solution {
public:
    int mySqrt(int x) {
        if(x<2)  
         return x;
        int left = 1 , right = x/2, res = 0;

        while(left<=right)
        {
            int mid = left + (right-left)/2;
            long long sqr = (long long) mid*mid;
            if(x==sqr)
             return mid;
            else if(sqr<x)
            {
                res = mid;
                left = mid+1;
            }
            else
             right = mid-1;
        }
        return res;
    }
};
