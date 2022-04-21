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
int mod;

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
int extgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
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

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = extgcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}

int32_t main()
{
  
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        //    #ifndef ONLINE_JUDGE
        //    freopen("input.txt", "r", stdin);
        //    freopen("output.txt", "w", stdout);
        //    #endif

          int a,b,c;
          cin>>a>>b>>c;
          int g=__gcd(a,b);

          if(c%g==0)
          {
              cout<<"Yes"<<endl;
          }
          else{
              cout<<"No"<<endl;
          }
 
}