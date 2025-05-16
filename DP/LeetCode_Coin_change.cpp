class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount<1)
        return 0;
        vector<int>mindp(amount+1,INT_MAX);
        mindp[0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(int coin:coins)
            {
                if(coin<=i && mindp[i-coin]!=INT_MAX)
                {
                    mindp[i]=min(mindp[i],mindp[i-coin]+1);
                }
            }
        }
        if(mindp[amount]==INT_MAX)
        {
            return -1;
        }
        return mindp[amount];
    }
};
