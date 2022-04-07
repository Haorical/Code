/*
#include<bits/stdc++.h>
using namespace std;
int n;
int f[30][30]; //状态
int st[30];
int ed[30];
int tmp[30];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tmp[i];
        st[tmp[i]]=i;
    }
    while(!cin.eof()){
        for(int i=1;i<=n;i++){
            cin>>tmp[i];
            ed[tmp[i]]=i;
        }
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=max(f[i-1][j],f[i][j-1]);
                if(st[i]==ed[j]) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
            }
        }
        cout<<f[n][n]<<endl;
    }
    system("pause");
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int f[30][30];
    int st[30];
    int ed[30];
    int tmp[30];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp[i];
        st[tmp[i]] = i;
    }
    for(int i=1;i<=n;i++){
            cout<<st[i]<<" ";
        }
    cout<<endl;
    while (!cin.eof())
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> tmp[i];
            ed[tmp[i]] = i;
        }
        for(int i=1;i<=n;i++){
            cout<<ed[i]<<" ";
        }
        cout<<endl;
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (st[i] == ed[j])
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
        cout << f[n][n] << endl;
    }
    system("pause");
}