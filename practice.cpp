#include <bits/stdc++.h>
#include <stdio.h>
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
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int mod = 1000000007LL;
int lim=10000000LL;
vector<bool> arr(lim + 2, true);
vector<int> primefact;
void prime_sieve()
{
 
    for (int i = 2; i <= lim; i += 2)
    {
        arr[i] = false;
    }
    primefact.pb(2);
    for (int i = 3; i <= lim; i += 2)
    {
        if (arr[i])
        {
            primefact.push_back(i);
            for (int j = i * i; j <= lim; j += 2 * i)
            {
                arr[j] = false;
            }
        }
    }
}
 
int power(int x, int y,int mod)
{
    if (y == 0)
    {
        return 1;
    }
    if (y == 1)
        return x;
    int q = power(x, y / 2,mod)%mod;
    q = (q * 1LL * q) %mod;
    if (y & 1)
        q = (q * 1LL * x) %mod;
    return q%mod;
}
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return a * b / __gcd(a, b);
}
void extgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    int x1, y1;
    extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return;
}
int inversmod(int a, int m)
{
    if (__gcd(a, m) != 1)
    {
        return -1;
    }
    int x, y;
    extgcd(a, m, x, y);
    x = (x + m) % m;
    return x;
}
bool checking_dvisible(string a,string b)
{
    int len1=a.length();
    int len2=b.length();
    if(len1%len2!=0) return false;
    //checkig for the is theirs is wrignt to get the answer
    while(a.length()>0)
    {
        if(a.length()>=b.length()){
        string temp=a.substr(0,b.length());
        if(temp!=b)
        {
            return false;
        }
        a.erase(0,b.length());
        }
        else{
            return false;
        }
    }
    return true;
 
}
void  solve()
{
    string s,t;
    cin>>s>>t;
    string temp1,temp2;
    if(s.length()>=t.length())
    {
        temp1=s;
        temp2=t;
    }
    else{
        temp1=t;
        temp2=s;
    }
    bool ans=checking_dvisible(temp1,temp2);
    if(ans) 
    {
        cout<<temp1<<endl;
        return ;
    }
    int k1=temp1.length();
    int k2=temp2.length();
    int l=k1*(k2/__gcd(k1,k2));
    string result=temp1;
    l=l/k1;
    for(int i=1;i<l;i++)
    {
        result+=temp1;
    }
    bool canget=checking_dvisible(result,temp2);
    if(canget)
    {
        cout<<result<<endl;
        return ;
    }
    cout<<"-1"<<endl;
    return ;





}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
int t;
cin>>t;
while(t--)
{
    solve();
}
    
 
return 0;
 
 
}