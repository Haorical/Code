/*
746. 使用最小花费爬楼梯
https://leetcode-cn.com/problems/min-cost-climbing-stairs/
难度：简单
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[1002];
    int minCostClimbingStairs(vector<int>& cost) {
        dp[0]=dp[1]=0;
        int len=cost.size();
        for(int i=2;i<=len;i++){
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
            /*
            dp[i]表示到达i的最小花费
            我们从地上开始走，走到第0，1阶时不花钱，dp[0]=dp[1]=0
            cost[i]表示从第i阶出发花的钱
            cost的数量len就是阶梯的数量
            dp[len]即是到达顶时的结果
            */
        }
        return dp[len];
    }
};
int main(){
    Solution s;
    vector<int> v={1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout<<s.minCostClimbingStairs(v);
    system("pause");
    return 0;
}