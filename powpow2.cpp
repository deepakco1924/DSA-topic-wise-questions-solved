#include <bits/stdc++.h>
#include<stdio.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<int, pair<int, int>> node;
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define endl "\n"
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define ff first
#define ss second
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define inf 1e18
#define sp(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x) \
  int x;     \
  cin >> x;  \
  while (x--)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int mod=1000000007;

const int MAXN = 100005LL;

 
int fact[MAXN], inv[MAXN], Tn;
int arr[MAXN];
int freq[MAXN];
int lastocuur[MAXN];
bitset<MAXN>prime;
bitset<MAXN>net;
vector<int>primefactor;
void intialize_cofficent()
{
  fact[0]=1;
  for(int i=1;(int)i<=2000012;i++ )
  {
    fact[i]=(fact[i-1]*i)%mod;
  }
  inv[0]=inv[1]=1;
  for(int i=2;(int)i<=2000012;i++)
  {
    inv[i]=((mod-(mod/i))*(inv[mod%i]))%mod;

  }
  for(int i=1;i<=2000012;i++) inv[i] = (inv[i-1] * inv[i])%mod;

}
int crt(int n)
{
    //we just find the prime factors
    int m1=2;
    int m2=1681;
    int m3=148721;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
}
void solve_taste()
{
    int a,b,n;
    cin>>a>>b>>n;
    if(a==0 and b==0)
    {
        cout<<"1"<<endl;
        return ;
    }
    else if(a==0||a==1)
    {
        cout<<a<<endl;
        return ;
    }
    else if(b==0)
    {
        cout<<"1"<<endl;
        return ;
    }
    //now we have the cases first find the 


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
           int t;
           cin>>t;
           while(t--)
           {
               solve_taste();
           }
          return  0;

 
}