#include <bits/stdc++.h> 
using namespace std;

int a[15]={0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 
1358657, 2504881, 13482720};

int main(){
 int k;
 while(cin>>k){
 if(k==0)
 break;
 cout<<a[k]<<endl;
 }
 return 0;
}