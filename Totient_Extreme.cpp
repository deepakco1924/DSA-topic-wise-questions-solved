#include<bits/stdc++.h>
using namespace std;
#define int long long
int phi[10001];
int MAXN=10001;
int mat[10001][10001];
void phi_1_to_n( )
 {
     memset(phi,0,sizeof(phi));
     
    
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <MAXN; i++)
        phi[i] = i;

    for (int i = 2; i < MAXN; i++) {
        if (phi[i] == i) {
            for (int j = i; j <MAXN; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
void again_precomoute()
{
    memset(mat,0,sizeof(mat));
    for(int i=1;i<MAXN;i++)
    {
        for(int j=i;j<MAXN;j++)
        {
            mat[i][j]=2*phi[i]*phi[j]+mat[i][j-1];
        }
    }
    for(int i=1;i<MAXN;i++)
    {
        for(int j=2;j<=i;j++)
        {
            mat[j][i]+=mat[j-1][i];
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
           #ifndef ONLINE_JUDGE
           freopen("input.txt", "r", stdin);
           freopen("output.txt", "w", stdout);
           #endif
    phi_1_to_n();
    again_precomoute();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<mat[n][n]<<endl;
    }
}