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
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define inf 1e18
 const int MAXN = 2222222;
#define sp(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x) \
  int x;     \
  cin >> x;  \
  while (x--)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 const int mod= 1000000007;

//combiantrices math chapter
//birthday perodex
void birthday_paradxo()
{
    int num=365;
    int denom=365;
    int people=0;
    float n=1.0;
    float p;
    cin>>p;
    if(p==1.0)
    {
        cout<<"366"<<endl;
        return ;

    }
    float x=1.0; //progblityh of the having the same not same birthday 
    while(x>1-p)
    {
        x=x*(float)(num/denom);
        num--;
        people++;
    }
    cout<<people<<endl;
    return ;

}
//void soltion of power of k to x such that divisibel by k^x
// the obesaevaiton of is n! is diviisbale is divisible by every element
int fact_pow (int n, int k) {
    int res = 0;
    while (n) {
        n /= k;
        res += n;
    }
    return res;
}
//modulo inverse mod 

// C function for extended Euclidean Algorithm 
void gcdExtended(int a, int b, int &x, int  &y) 
{ 
	// Base Case 
	if (a == 0) 
	{ 
		x = 0, y = 1; 
		return ; 
	} 

	int x1, y1; // To store results of recursive call 
gcdExtended(b % a, a, x1, y1); 

	// Update x and y using results of recursive 
	// call 
	x = y1 - (b / a) * x1; 
	y = x1; 

} 
int  modInverse(int a, int m) 
{ 
	int x, y; 
  if(__gcd(a,mod)!=1)
  {
		return -1;
  }

		// m is added to handle negative x 
    gcdExtended(a,m,x,y);
		int res = (x % m + m) % m; 
    return res;
	 
	
} 
int fact[MAXN];
int inv[MAXN];
void intialize_cofficent()
{
  fact[0]=1;
  for(int i=1;(int)i<2000000;i++ )
  {
    fact[i]=(fact[i-1]*i)%mod;
  }
  inv[1]=1;
  for(int i=2;(int)i<2000000;i++)
  {
    inv[i]=((mod-(mod/i))*(inv[mod%i]))%mod;

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
      intialize_cofficent();
      int n,k;
      cin>>n>>k;
      int ans=fact[n]*(inv[n-k]%mod)*(inv[k]%mod);
      cout<<ans<<endl;
 
   
  
  
}
