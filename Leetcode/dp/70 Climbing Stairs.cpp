/*
70. 爬楼梯
https://leetcode-cn.com/problems/climbing-stairs/
正好今天补题的时候碰到个类似的，用搜索就超时，用dp相当快
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：5.8 MB, 在所有 C++ 提交中击败了77.11%的用户
用递归会超时，要用记忆化搜索
难度：入门      
*/
#include<bits/stdc++.h>
using namespace std;
int f[100002];
int climbStairs_dp(int n) {
    f[0]=1;
    f[1]=1;
    for(int i=2;i<=n;i++)
        f[i]=f[i-1]+f[i-2];
    return f[n];
}
int climbStairs_dg(int n) {
    if(n<=1) return 1;
    f[n]=(f[n-1]==-1?climbStairs_dg(n-1):f[n-1])+(f[n-2]==-1?climbStairs_dg(n-2):f[n-2]);//用了记忆化搜索
    return f[n];
}
int main(){
    int n;
    cin>>n;
    memset(f,-1,sizeof(f));
    cout<<climbStairs_dg(n);
    system("pause");
    return 0;
}