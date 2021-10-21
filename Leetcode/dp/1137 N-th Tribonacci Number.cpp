/*
1137. 第 N 个泰波那契数
https://leetcode-cn.com/problems/n-th-tribonacci-number/
直接dp，不用辅助数组了，只维护3个变量就行
dp真香
难度：入门
*/
class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        else if(n<3) return 1;
        int a,b,c,d;
        a=0;
        b=1;
        c=1;
        for(int i=3;i<=n;i++){
            d=a+b+c;
            a=b;
            b=c;
            c=d;
        }
        return d;
    }
};