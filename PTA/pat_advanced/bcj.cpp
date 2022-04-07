/*
1. 初始化
2. 查找（递推）
3. 合并
*/
#include<bits/stdc++.h>
using namespace std;
int father[100];
void init(){
    for(int i=0;i<100;i++){
        father[i]=i;
    }
}
int find(int x){
    int a=x;
    while(x!=father[x]){
        x=father[x];
    }
    while(a!=father[a]){
        int z=a;
        a=father[a];//a回溯父亲节点
        father[z]=x;//将原a的父亲改为x
    }
    return x;
}

int find2(int x){
    if(x==father[x]) return x;
    int r=find2(father[x]);
    father[x]=r;
    return r;
}

void Union(int a,int b){
    int fa=find(a);
    int fb=find(b);
    if(fa!=fb){
        father[fa]=fb;
    }
}
int main(){

    system("pause");
    return 0;
}