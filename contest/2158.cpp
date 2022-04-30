#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        string str,ts;
        cin>>str;
        int i=0,j=n-1;
        int tn=n;
        while(i <= j)
        {
            bool flag = false;
            for(int k = 0; i+k < j-k; k++)
            {
                if(str[i+k] < str[j-k])
                {
                    flag = true;
                    break;
                }
                if(str[i+k] > str[j-k]) break;
            }
            if(flag) printf("%c",str[i++]);
            else printf("%c",str[j--]);
        }
        cout<<ts<<endl;
    }
    system("pause");
    return 0;
}