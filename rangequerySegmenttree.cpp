#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
 
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define triple pair<pair<int,int>,int>
#define MOD 1000000007
#define MOD1 998244353
#define clr(x, y) memset(x, y, sizeof(x))
#define pii pair<int, int>
#define vi vector<int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define node_pair pair<pair<int,int>,int>
#define INF 1e18
#define MINF LLONG_MIN
#define endl "\n"
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define vii vector<vector<int>>
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define int long long
#define sp(x,y) fixed<<setprecision(y)<<x
#define w(x) \
  int x;     \
  cin >> x;  \
  while (x--)
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T>
void _print(pbds<T> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/



struct node
{
    ll sum;
    ll setAll;
    ll increment;
    bool setAllValid;
    node()
    {
       sum = 0;
       setAllValid = 0;
       increment = 0;
    }
    void Reset()
    {
       setAllValid = increment = 0;
    }
};
 
class segtree
{
    int range;
    vector<node> tree;
public:
    void build(vector<int>& v)
    {
        range = v.size();
        tree.assign(4*range, node());
        build_recur(v, 0, range-1, 0);
    }
    void build_recur(vector<int>& v, int l, int r, int node_no)
    {
        if(l == r){
            if(l < v.size())
                tree[node_no].sum = v[l];
            else tree[node_no].sum = 0;
            return;
        }
        int mid = (l+r)/2;
        build_recur(v, l, mid, 2*node_no + 1);
        build_recur(v, mid + 1, r, 2*node_no + 2);
        tree[node_no].sum = tree[2*node_no + 1].sum + tree[2*node_no + 2].sum;
    }
    ll range_query(int L, int R)
    {
        return range_query_recur(0, 0, range - 1, L, R);
    }
 
    void incUpdate_recur(int node, int l, int r, int& L, int& R, int& X)
    {
        if(r < L || R < l || l >= range)
            return;
        if(L <= l && R >= r)
        {
            tree[node].increment += X;
            return;
        }
        applyAggr(node,l,r);
        int mid = (l+r)/2;
        incUpdate_recur(2*node+1,l,mid,L,R,X);
        incUpdate_recur(2*node+2,mid+1,r,L,R,X);
        applyAggr(2*node+1, l, mid);
        applyAggr(2*node+2, mid+1, r);
        tree[node].sum = tree[2*node+1].sum + tree[2*node+2].sum;
    }
 
    void incUpdate(int L, int R, int X)
    {
        incUpdate_recur(0,0,range-1,L,R,X);
    }
 
    void setUpdate_recur(int node, int l, int r, int& L, int& R, int& X)
    {
        if(r < L || R < l || l >= range)
            return;
        if(L <= l && R >= r)
        {
            tree[node].setAllValid = 1;
            tree[node].setAll = X;
            tree[node].increment = 0;
            return;
        }
        applyAggr(node,l,r);
        int mid = (l+r)/2;
        setUpdate_recur(2*node+1,l,mid,L,R,X);
        setUpdate_recur(2*node+2,mid+1,r,L,R,X);
        applyAggr(2*node+1, l, mid);
        applyAggr(2*node+2, mid+1, r);
        tree[node].sum = tree[2*node+1].sum + tree[2*node+2].sum;
    }
 
    void setUpdate(int L, int R, int X)
    {
        setUpdate_recur(0,0,range-1,L,R,X);
    }
 
    void compose(int par, int child)
    {
        if(tree[par].setAllValid){
            tree[child].setAllValid = 1;
            tree[child].setAll = tree[par].setAll;
            tree[child].increment = tree[par].increment;
        }
        else tree[child].increment += tree[par].increment;
    }
 
    void applyAggr(int node, int l, int r)
    {
        if(tree[node].setAllValid)
            tree[node].sum = (r-l+1)*tree[node].setAll;
 
        tree[node].sum += (r-l+1)*tree[node].increment;
 
        if(l != r){
            compose(node, 2*node + 1);
            compose(node, 2*node + 2);
        }
 
        tree[node].Reset();
    }
 
    ll range_query_recur(int node, int l, int r, int& L, int& R)
    {
        if(r < L || R < l || l >= range)
            return 0;
        applyAggr(node, l, r);
        if(L <= l && R >= r)
            return tree[node].sum;
        int mid = (l+r)/2;
        return range_query_recur(2*node + 1, l, mid, L, R) + range_query_recur(2*node + 2, mid+1, r, L, R);
    }
};

void solve(){
  int n;
  cin>>n;
  cout<<n<<" "<<"dee"<<endl;
}
  

int32_t main() {
 
#ifndef ONLINE_JUDGE
  freopen("error.txt", "w", stderr);
#endif
 
  fastio();
  auto start1 = high_resolution_clock::now();
  int t = 1;
  // cin >> t;
 
  while (t--)solve();
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
  cerr << "Time: " << duration . count() / 1000 << endl;
#endif
  return 0;
}