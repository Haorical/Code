/*
213. 打家劫舍 II
https://leetcode-cn.com/problems/house-robber-ii/
难度：中等
和上题类似，首尾相连只需要将环拆成两个就行，一个从0开始，一个从1开始，长度都是n-1
对这两个情况分别求，注意特殊情况即可
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[102];
        memset(dp,0,sizeof(dp));
        int len=nums.size()-1;
        if(len==0) return nums[0];//这里需要加个特判，只有一个数直接返回
        int m,n;
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=len;i++){
            dp[i]=max(dp[i-2]+nums[i-1],dp[i-1]);
        }
        m=dp[len];
        memset(dp,0,sizeof(dp));
        dp[0]=0;
        dp[1]=nums[1];
        for(int i=2;i<=len;i++){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        n=dp[len];
        return max(m,n);        
    }
};
int main(){
    Solution s;
    vector<int> nums={1};
    cout<<s.rob(nums);
    system("pause");
    return 0;
}