#include<bits/stdc++.h>
using namespace std;


int u[1000002];
int su[1000002];

// 埃氏筛
int as(int n){
    int i, j, num = 0;
    for(i = 2; i <= n; i++) u[i] = true;
    for (i = 2; i <= n; i++)
    {
        if(u[i]){
            for (j = 2; j*i <= n; j++)
            {
                u[j*i] = false;
            }
            
        }
    }
    for (i = 2; i <= n; i++)
    {
        if(u[i]) su[num++] = i;
    }
    
    return num;
}

// 欧拉筛
void os(int n){
    int i, j, num = 1;
    memset(u, true, sizeof(u));
    for (i = 2; i <= n; i++)
    {
        if(u[i]) su[num++] = i;
        for(j = 1; j < num; j++){
            if(i*su[j] > n) break;
            u[i*su[j]] = false;
            if(i%su[j] == 0) break;
        }
    }
    
}


int main(){
    memset(su, 0, sizeof(su));
    os(10);
    int cnt = 0;
    for(int i = 1; su[i]; i++) {
        cout<<su[i]<<endl;
        cnt++;
    }
    cout<<cnt;
    system("pause");
    return 0;
}