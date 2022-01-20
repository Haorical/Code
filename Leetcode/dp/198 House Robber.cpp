/*
198. 打家劫舍
https://leetcode-cn.com/problems/house-robber/
难度：中等
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[102];
    int rob(vector<int>& nums) {
        int len=nums.size();
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=len;i++){
            dp[i]=max(dp[i-2]+nums[i-1],dp[i-1]);
            /*
            dp[i]表示前i间房能偷盗的最大总金额
            nums[i-1]表示投第i间房（下标0开始造成）
            */
        }
        return dp[len];
    }
};

