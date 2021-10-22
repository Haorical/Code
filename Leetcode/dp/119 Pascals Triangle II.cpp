/*
119. 杨辉三角 II
https://leetcode-cn.com/problems/pascals-triangle-ii/
还是用的第一次的代码，只是改了改返回值就行，不过速度有点慢
然后看了题解优化了一下
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int a[32][32];
    vector<int> generate(int numRows) {
        a[1][1]=1;
        vector<vector<int>> x;
        for(int i=1;i<=numRows+1;i++){
            vector<int> y;
            a[i][1]=1;
            y.push_back(1);
            for(int j=2;j<i;j++){
                a[i][j]=a[i-1][j]+a[i-1][j-1];
                y.push_back(a[i][j]);
            }
            a[i][i]=1;
            if(i!=1) y.push_back(1);
            x.push_back(y);
        }
        return x[numRows];
    }
};
//利用滚动数组的方式优化
class Solution2 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pre, cur;
        for (int i = 0; i <= rowIndex; ++i) {
            cur.resize(i + 1);
            cur[0] = cur[i] = 1;
            for (int j = 1; j < i; ++j) {
                cur[j] = pre[j - 1] + pre[j];
            }
            pre = cur;
        }
        return pre;
    }
};


int main(){
    Solution s;
    vector<int> x=s.generate(3);
    for(auto i:x){
        cout<<i<<endl;
    }
    system("pause");
    return 0;
}