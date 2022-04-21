#include <bits/stdc++.h>
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
const int MAXN = 1000005;
int phi[1000005];
int lcmsum[1000005];
int freq[1000005];
 int modular_exponetion(int a,int b)
 {
     int res=1;
     while(b)
     {
         if(b&1LL)
         {
             res=(res*a);
         }
         b=b>>1;
         a=(a*a);
     }
     return res;
 }
vii multiplay(vii A,vii B)
{
    vii temp(4,vi(4));
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            for(int x=1;x<=3;x++)
            {
               temp[i][j]=(temp[i][j]+(A[i][x]*B[x][j])%mod)%mod;
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
void findi_init_lcm()
{
    memset(lcmsum,0,sizeof(lcmsum));
    for(int i=1;i<MAXN;i++)
    {
        for(int j=i;j<MAXN;j+=i)
        {
            lcmsum[j]+=(i*phi[i]);
        }
    }

}
vector<vi> find_divisors(int n)
{
    vector<vi>v(n+1);
    v[0].push_back(0);
    int arr[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        v[i].push_back(1);
        arr[i]=1;

    }
    for(int i=2;i<=n;i++)
    {
        if(arr[i]==1){
        for(int j=i;j<=n;j+=i)
        {
            v[j].push_back(i);
        }
        }
    }
    return v;


}
void intia_gcd()
{
    memset(lcmsum,0,sizeof(lcmsum));
    for(int i=1;i<MAXN;i++)
    {
        for(int j=2*i;j<MAXN;j+=i)
        {
            lcmsum[j]+=i*phi[j/i];
        }
    }
    for(int i=2;i<MAXN;i++)
    {
        lcmsum[i]+=lcmsum[i-1];
    }

}
string convert_int_tostring(int a)
{
    stringstream ss;
ss << a;
string str = ss.str();
return str;

}
bool check_permuation(int a,int b)
{
    string str=convert_int_tostring(a);
    string ptr=convert_int_tostring(b);
    if(str.length()!=ptr.length()) return false;
    int count1[256] = {0}; 
    int count2[256] = {0}; 
    int i; 
  
    // For each character in input strings,  
    // increment count in the corresponding  
    // count array 
    for (i = 0; str[i] && ptr[i];  i++) 
    { 
        count1[str[i]]++; 
        count2[ptr[i]]++; 
    } 
  
    // If both strings are of different length.  
    // Removing this condition will make the 
    // program fail for strings like "aaca" 
    // and "aca"
  
    // Compare count arrays 
    for (i = 0; i < 256; i++) 
        if (count1[i] != count2[i]) 
            return false; 
  
    return true; 


}
void solve_the_precompute()
{
   memset(freq,0,sizeof(freq));
    int val=21;
    double value=(double)21/12.0;
    for(int i=22;i<MAXN;i++)
    {
        bool ans=check_permuation(phi[i],i);
        if(ans==true)
        {
            double cur=(double)i*1.0/phi[i];
            if(cur<=value)
            {
                val=i;
            }

        }
        freq[i]=val;
    }
    return ;

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
      solve_the_precompute();
      int t;
      cin>>t;
      while(t--)
      {
          int m;
          cin>>m;
          if(m<=21)
          {
              cout<<"No solution."<<endl;
          }
          else{

              cout<<freq[m]<<endl;
          }
      }
      
  
           return 0;
 
}