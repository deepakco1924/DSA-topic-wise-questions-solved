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


vector<int>longest_prefix(string s){
     int n=sz(s);
  vector<int>ans(n,0);
 
  for(int i=1;i<n;i++){
    int j=ans[i-1];
     while(j>0 and s[i]!=s[j]){
      j=ans[j-1];
     }
     if(s[i]==s[j]){
      j++;
     }
     ans[i]=j;
  }
  return ans;
}


void KMP(){
  string txt;
  string pattern;
  cin>>txt;
  cin>>pattern;
  vector<int>lps=longest_prefix(pattern);
  int i=0;
  int j=0;
  int n=txt.length();
  int m=pattern.length();
  vi ans;
  while(i<n){
    if(txt[i]==pattern[j]){
      i++;
      j++;
    }

    else{
      if(j!=0){
        j=lps[j-1];
      }
      else{
        i++;
      }
    }
    if(j==m){
      ans.pb(i-j);
    }
  }
  debug(ans)

}
int computeHash(string s){

  const int m=1e9+9;
  int hash=0;
  int x=1;
  const int p=31;//use p as 31 if small letters but capital is there use 53
  for(int i=0;i<sz(s);i++){
    hash+=((s[i]-'a'+1)*x)%m;
    x=(x*p)%m;
    hash=hash%m;
  }
  return hash;
  //probability having two string have same hash is 1/m 
}
vector<int>hashArray(string s){

    const int m=1e9+9;
  int hash=0;
  int x=1;
  vector<int>ans;
  const int p=31;//use p as 31 if small letters but capital is there use 53
  for(int i=0;i<sz(s);i++){
    hash+=((s[i]-'a'+1)*x)%m;
    x=(x*p)%m;
    hash=hash%m;
    ans.push_back(hash);
  }
  return ans;
}
vector<int>findprefix(string s){
  int n=s.length();
  vector<int>ans(n,0);
  for(int i=1;i<n;i++){
    int j=ans[i-1];
    while(j>0 and s[i]!=s[j]){
      j=ans[j-1];
    }
     if(s[i]==s[j])
  {
    j++;
  }
  ans[i]=j;
  }
  return  ans;
}

vector<int>Rabin_karp(string s,string t){
  vector<int>ans;
  const int m=1e9+9;
  const int p=31;
  int st=sz(s);
  int tt=sz(t);
  vector<int>p_pow(tt);
  p_pow[0]=1;
  for(int i=1;i<tt;i++){
    p_pow[i]=(p_pow[i-1]*p)%m;
  }
    int hasval=0;
  for(int i=0;i<st;i++){
    hasval=(hasval+(s[i]-'a'+1)*p_pow[i])%m;
    hasval%=m;
  }
  vector<int>hast(tt+1,0);
  for(int i=0;i<tt;i++){
    hast[i+1]=(hast[i]+(t[i]-'a'+1)*p_pow[i])%m;
  }
  for(int i=0;i+st-1<tt;i++){
    int j=i+st;
    int val=(hast[j]+m-hast[i])%m;
    int leftans=(hasval*p_pow[i])%m;
    if(val==leftans)
    {
      ans.pb(i);
    }
  }


}

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

//suffix array
vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;

     vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}
vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    // sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}
vector<int> lcp_construction(string s, vector<int> const& p) {
    s+="$";
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}
void solve(){

  
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