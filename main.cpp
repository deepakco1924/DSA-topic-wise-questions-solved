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

const int MAXN = 2222222;

 
int fact[MAXN], inv[MAXN], Tn;
int arr[MAXN];
int freq[MAXN];
int lastocuur[MAXN];
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
 
int power (int x, int y) {
	if (y == 1)
		return x;
	int q = power(x, y / 2);
	q = (q * 1LL * q) % mod;
	if (y & 1)
		q = (q * 1LL * x) % mod;
	return q;
}
 
int C (int n, int k) {

	return (((fact[n] * 1LL * inv[k]) % mod) * 1LL * inv[n - k]) % mod;
}
bool check_prime(int j)
{
  if(j==2)
  {
    return true;
  }
  for(int i=2;(int)i*i<=j;i++)
  {
    if(j%i==0)
    {
      return  false;
    }
  }
  return true;
}
int lcm(int a,int b)
{
  return a*b/__gcd(a,b);
}

void segment_seive(int l,int r)
{
  //first make the prime seive uptop r;
  int lim=sqrt(r);
  vector<int>primes;
  vector<bool>mark(lim+1,true);
  for(int i=2;i<=lim;i++)
  {
    if(mark[true])
    {
      primes.emplace_back(i);
      for(int j=i*i;j<=lim;j+=i)
      {
        mark[j]=false;
      }
    }
  }
  vector<bool>segment(r-l+1,true);
  for(auto x:primes)
  {
    for(int j=max((x*x),(l+x-1)/x*x);j<=r;j+=x)
    {
      segment[j-l]=false;
    }
  }
  for(int i=l;i<=r;i++)
  {
    if(segment[i-l]==true and i!=1)
    {
      cout<<i<<" ";
    }

  }


  
  cout<<endl;
  
}
void extgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return ;
    }
    int x1,y1;
    extgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return ;
      

}
int inversmod(int a)
{
    if(__gcd(a,mod)!=1)
    {
        return -1;
    }
    int x,y;
    extgcd(a,mod,x,y);
    x=(x+mod)%mod;
    return x;
}
int modular_exponetion(int a,int b,int n)
 {
     int res=1;
     while(b)
     {
         if(b&1LL)
         {
             res=(res*a)%n;
         }
         b=b>>1;
         a=(a*a)%n;
     }
     return res;
 }

void solve_codechef()
{
  int n;
  cin>>n;
  string s;
  cin>>s;
  int cnt=0;
  for(int i=0;i<s.length();i++)
  {
    if(s[i]=='1')
    {
      cnt++;
    }
  }
  int remaindays=120-n;
  if(remaindays+cnt>=90)
  {
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
  return ;
}
void solve_polvise()
{
    int t;
           cin>>t;
           while(t--)
           {
             int x,y,n,k;
             cin>>x>>y>>k>>n;
             int ans=abs(x-y);
             if(k==1)
             {
               if(ans&1)
               {
                 cout<<"NO"<<endl;
               }
               else{
                 cout<<"YES"<<endl;
               }

             }
             else{
             if( ans%k==0 and (ans/k)%2==0)
             {
               cout<<"YES"<<endl;
             }
             else{
               cout<<"NO"<<endl;
             }
             }
           }
}
bool ispossible(int mid,int n,int m,vector<int>spell)
{
  int cnt=0;
  for(int i=0;i<spell.size();)
  {
    int x=spell[i];
    if(n%x==0 ||x%n==0)
    {
      i++;
      continue;

    }
    else{
      n--;
      cnt++;
      if(cnt>=mid)
      {
        return true;
      }
    }
  }
  return false;
}
int solve_circle()
{
  int n,m;
  cin>>n>>m;
  vector<int>spell(m);
  while(m--){
    cout<<"depak"<<endl;
    int num;
    cin>>num;
    spell.push_back(num);
  }

  if(n==1)return 0;
  
  sort(all(spell));
  int s=0;
  int e=n-1;
  int ans=INT_MIN;
  while(s<=e)
  {
    int mid=(s+e)/2;
    if(ispossible(mid,n,m,spell))
    {
      cout<<"deepak"<<endl;
      ans=max(ans,mid);
        s=mid+1;
    }
    else{
      e=mid-1;
    }
  }

  return ans;
}
void competitive_programmer()
{
  int n;
  cin>>n;
  while(n--)
  {
    string s;
    cin>>s;
    int sum=0;
    int even=0;
    int zero=0;
    for(int i=0;i<s.length();i++)
    {
      if(s[i]=='0') zero++;
      if((s[i]-'0')%2==0 ) 
      {
        even++;
      }
      int dig=(int)(s[i]-'0');
      sum+=dig;


    }
    if((sum%3==0 and even>=1 and zero>=1)|| (sum==0))
    {
      cout<<"red"<<endl;
    }
    else{
      cout<<"cyan"<<endl;
    }
    s.clear();

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
           competitive_programmer();
           return 0;
 
}