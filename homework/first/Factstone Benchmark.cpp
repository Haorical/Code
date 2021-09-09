#include<bits/stdc++.h>
using namespace std;

int qpow(int a, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
        return qpow(a, n - 1) * a;
    else
    {
        int temp = qpow(a, n / 2);
        return temp * temp;
    }
}

int main(){
    int y;
    while(cin>>y){
        if(!y) break;
        else{
            int tmp=(y-1960)/10;
            tmp=qpow(2,tmp+2);
            double sum=0.0;
            int cnt=1;
            while(sum<tmp){
                sum+=log(cnt)/log(2);
                cnt++;
            }
            cout<<cnt-2<<endl;
        }
    }
    system("pause");
    return 0;
}