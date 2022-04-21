#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<typename T>
using new_set= tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define endl "\n"
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,0,sizeof(x))
#define int long long 
#define ff               first
#define ss               second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
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
void solve()
{
    //in this quesiton we find the inversion count of the array
    //it is called using the policy based data strcuture
    int n;
    cin>>n;
    int arr[n];
    new_set<int>s;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int count=0;
    
    for(int i=0;i<n;i++)
    {
        count+=s.size()-s.order_of_key(arr[i]);
        s.insert(arr[i]);

    }
    cout<<"the inversion count is "<<count<<endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

solve();
//policy based data strcuture work like the
//the set but it has special functionlaity
//find_by_order(k)-----it return the kth largest element
//order_of_key(k)---it return the number of element which are striclty less than value of key
//both operation work in log(n)

// new_set <int>s;
// int n;
// cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         int num;
//         cin>>num;
//         s.insert(num);
//     }
//     for(auto c:s)
//     {
//         cout<<c<<" ";
//     }
//     cout<<endl;
//     cout<<s.order_of_key(100);

    

return 0;


}