/*
杨辉三角
https://leetcode-cn.com/problems/pascals-triangle/
用的dp写的，不得不说，真的爽
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int a[32][32];
    vector<vector<int>> generate(int numRows) {
        a[1][1]=1;
        vector<vector<int>> x;
        for(int i=1;i<=numRows;i++){
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
        return x;
    }
};

int main(){
    Solution s;
    vector<vector<int>> x=s.generate(5);
    for(int i=0;i<x.size();i++){
        vector<int> p=x[i];
        for(int j=0;j<p.size();j++){
            cout<<p[j]<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}