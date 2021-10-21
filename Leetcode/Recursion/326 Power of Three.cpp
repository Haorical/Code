/*
326. 3的幂
https://leetcode-cn.com/problems/power-of-three/
暴力 递归 迭代 打表
难度：入门
*/
// 暴力
class Solution {
public:
    bool isPowerOfThree(int n) {
        long long sum=1;
        for(int i = 0; i < n; i++){
            
            if(sum == n) return true;
            else if(sum > n) return false;
            sum*=3;
        }
        return false;
    }
};

//递归
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1) return true;
        else if(n==0) return false;
        return n%3==0?isPowerOfThree(n/3):false;
    }
};