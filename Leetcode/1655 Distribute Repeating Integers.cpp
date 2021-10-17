/*
dp 状态压缩
1655. 分配重复整数
难度：太他妈难了
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> cache;
        for (int x: nums) {
            cache[x]++;
        }
        vector<int> cnt;
        for (auto& kv: cache) {
            cnt.push_back(kv.second);
        }
        
        int n = cnt.size(), m = quantity.size();
        vector<int> sum(1 << m, 0);
        for (int i = 1; i < (1 << m); i++) {
            for (int j = 0; j < m; j++) {
                if ((i & (1 << j)) != 0) {
                    int left = i - (1 << j);
                    sum[i] = sum[left] + quantity[j];
                    break;
                }
            }
        }
        
        vector<vector<bool>> dp(n, vector<bool>(1 << m, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (1 << m); j++) {
                if (i > 0 && dp[i-1][j]) {
                    dp[i][j] = true;
                    continue;
                }
                for (int s = j; s != 0; s = ((s - 1) & j)) { // 子集枚举，详见 https://oi-wiki.org/math/bit/#_14
                    int prev = j - s; // 前 i-1 个元素需要满足子集 prev = j-s
                    bool last = (i == 0) ? (prev == 0): dp[i-1][prev]; // cnt[0..i-1] 能否满足子集 prev
                    bool need = sum[s] <= cnt[i]; // cnt[i] 能否满足子集 s
                    if (last && need) {
                        dp[i][j] = true;
                        break;
                    }
                }
            }
        }
        return dp[n-1][(1<<m)-1];
    }
};

int main(){
    vector<int> nums={1,1,1,1,1}, quantity = {2,3};
    Solution s;
    cout<<s.canDistribute(nums,quantity);
    system("pause");
    return 0;
}