#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<int, pair<int, int>> node;
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(x) scanf("%s",&s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(x) printf("%s\n",x)
#define endl "\n"
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,0,sizeof(x)) 
#define f               first
#define s               second
#define int          long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vii             vector<vector<int>>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define sp(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MAXN = 2222222;
const int MOD=1000000000;
//solving power of z^n in log(n)
int modpow(int x, int n) 
{
    if (n == 0) return 1%mod;
    int  u = modpow(x,n/2);
    u = (u*u)%mod;
    if (n%2 == 1) u = (u*x)%mod;
    return u;
}

vector<int>a,b,c;
int k;
vii multiplay(vii A,vii B)
{
    vii temp(k+1,vi(k+1));
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            for(int x=1;x<=k;x++)
            {
               temp[i][j]=(temp[i][j]+(A[i][x]*B[x][j])%MOD)%MOD;
            }
        }
    }
    return temp;
}
vii power_find(vii A,int p)
{
    if(p==1)
    {
        return A;
    }
    if(p&1)
    {
        return multiplay(A,power_find(A,p-1));
    }
    vii result=power_find(A,p/2);
    return multiplay(result,result);

}
int compute(int n)
{
    //step one to make the F1 vector;
    if(n==0)
    {
        return 1;
    }
    if(n<=k)
    {
        return b[n-1];
    }
    vector<int>f(k+1);
    for(int i=1;i<=k;i++)
    {
        f[i]=b[i-1];//it is 1 base indexing
    }
    //now we have to make the trasformation matriz
    vii T(k+1,vi(k+1));
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i<k)
            {
                if(j==i+1)
                {
                    T[i][j]=1;
                }
                else{
                    T[i][j]=0;
                }

            }
            else{
                T[i][j]=c[k-j];

            }
        }
    }
    T=power_find(T,n-1);
    int ans=0;
    for(int i=1;i<=k;i++)
    {
        ans=(int)(ans+(T[1][i]*f[i])%MOD)%MOD;
    
    }
    return (int)ans;




}
void solve_liner_recursion()
{
           
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif


        int t;
        cin>>t;
        while(t--)
        {
            
            cin>>k;
            for(int i=0;i<k;i++)
            {
                int num;
                cin>>num;
                b.pb(num);

            }
            for(int i=0;i<k;i++)
            {
                int x;
                cin>>x;
                c.pb(x);
            }
            int n;
            cin>>n;
            cout<<compute(n)<<endl;
            b.clear();
            c.clear();
        }

                
                
        return ;


}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif
        int n;
        cin>>n>>k;
        for(int i=0;i<k;i++)
        {
            int num;
            cin>>num;
            b.push_back(num);
        }
        for(int i=0;i<k;i++)
        {
            int x;
            cin>>x;
            c.push_back(x);
        }
        cout<<compute(n)<<endl;
}
 