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
vi b,c;
int k,p;

vii multiplay(vii A,vii B)
{
    vii temp(k+2,vi(k+2));
    for(int i=1;i<=k+1;i++)
    {
        for(int j=1;j<=k+1;j++)
        {
            for(int x=1;x<=k+1;x++)
            {
               temp[i][j]=(temp[i][j]+(A[i][x]*B[x][j])%p)%p;
            }
        }
    }
    return temp;
}
vii power(vii A,int r)
{
    if(r==1)
    {
        return A;
    }
    if(r&1)
    {
        return multiplay(A,power(A,r-1));
    }
    vii temp=power(A,r/2);
    return multiplay(temp,temp);
}
int compute(int n,int m)
{
    vi f(k+2);
    f[1]=0;
    for(int i=0;i<k;i++)
    {
        f[1]=(f[1]+b[i])%p;
    }
    for(int i=2;i<=k+1;i++)
    {
        f[i]=b[i-2];

    }

     vii T(k+2,vi(k+2));//one base indexing
    for(int i=1;i<=k+1;i++)
    {
        for(int j=1;j<=k+1;j++)
        {
            if(i==1)
            {
                if(j==1)
                {
                    T[i][j]=1;
                }
                else{
                    T[i][j]=c[k-j+1];
                }

            }
            if(i>1 and i<k+1)
            {
                if(j=i+1)
                {
                    T[i][j]=1;
                }
                else{
                    T[i][j]=0;
                }

            }
            else{
                if(j==1)
                {
                    T[i][j]=0;
                }
                else{
                    T[i][j]=c[k-j+1];

                }

            }

        }
    }
    vii temp1(k+2,vi(k+2));
    temp1=power(T,n);
    int r=0;
    for(int i=1;i<=k+1;i++ )
    {
        r=(r+(temp1[1][i]*f[i])%p)%p;
    }
    int l=0;
    if(m<=k)
    {
        for(int i=0;i<m;i++)
        {
            l=(l+b[i])%p;
        }
    
    }
    else{
        vii temp(k+2,vi(k+2));
        power(T,m-1);
        for(int i=1;i<=k+1;i++)
        {
            l=(l+(temp[1][i]*f[i])%p)%p;

        }
    }
    int result=(r-l+p)%p;
    return result;

}
int32_t main()
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
        int  num;
        for(int i=0;i<k;i++)
        {
            cin>>num;
            b.pb(num);

        }
        for(int i=0;i<k;i++)
        {
            cin>>num;
            c.pb(num);
        }
        int n,m;
        cin>>n>>m>>p;
        int ans=0;
        if(n<=k)
        {
            for(int i=m-1;i<n;i++)
            {
                ans=(ans+b[i])%p;
            }
            cout<<ans<<endl;
            continue ;
        
        }
        cout<<compute(n,m)%p<<endl;

        b.clear();
        c.clear();



    }
    return 0;
        
}
 //seq question 

// vector<int>a,b,c;
// int k;
// vii multiplay(vii A,vii B)
// {
//     vii temp(k+1,vi(k+1));
//     for(int i=1;i<=k;i++)
//     {
//         for(int j=1;j<=k;j++)
//         {
//             for(int x=1;x<=k;x++)
//             {
//                temp[i][j]=(temp[i][j]+(A[i][x]*B[x][j])%MOD)%MOD;
//             }
//         }
//     }
//     return temp;
// }
// vii power_find(vii A,int p)
// {
//     if(p==1)
//     {
//         return A;
//     }
//     if(p&1)
//     {
//         return multiplay(A,power_find(A,p-1));
//     }
//     vii result=power_find(A,p/2);
//     return multiplay(result,result);

// }
// int compute(int n)
// {
//     //step one to make the F1 vector;
//     if(n==0)
//     {
//         return 0;
//     }
//     if(n<=k)
//     {
//         return b[n-1];
//     }
//     vector<int>f(k+1);
//     for(int i=1;i<=k;i++)
//     {
//         f[i]=b[i-1];//it is 1 base indexing
//     }
//     //now we have to make the trasformation matriz
//     vii T(k+1,vi(k+1));
//     for(int i=1;i<=k;i++)
//     {
//         for(int j=1;j<=k;j++)
//         {
//             if(i<k)
//             {
//                 if(j==i+1)
//                 {
//                     T[i][j]=1;
//                 }
//                 else{
//                     T[i][j]=0;
//                 }

//             }
//             else{
//                 T[i][j]=c[k-j];

//             }
//         }
//     }
//     T=power_find(T,n-1);
//     int ans=0;
//     for(int i=1;i<=k;i++)
//     {
//         ans=(int)(ans+(T[1][i]*f[i])%MOD)%MOD;
    
//     }
//     return (int)ans;




// }
 