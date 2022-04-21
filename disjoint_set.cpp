#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using pbds= tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;




#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define endl "\n"
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,0,sizeof(x))
#define int long long 
#define f              first
#define s              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define sp(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

class DSU
{
    public:
    int v;
    int *parent;
    int *rank;
    DSU(int x)
    {
        this->v=x;
        rank=new int[v+1];
        parent=new int[v+1];
        for(int i=0;i<=v;i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }
    }
    int find_set(int  i)
    {
        if(parent[i]==-1)
        {
            return i;
        }
        return parent[i]=find_set(parent[i]);//path compressiom
    }
    void union_set(int x,int y)
    {
        int s1=find_set(x);
        int s2=find_set(y);
        if(s1!=s2)
        {
            if(rank[s1]>rank[s2])
            {
                parent[s2]=s1;
                rank[s1]+=rank[s2];
             
            }
            else{
                parent[s1]=s2;
                rank[s2]+=rank[s1];
              
            }
        }
    }
    int size(int x)
    {
        return rank[find_set(x)];
    }
};
void solve()
{
    //coding bokcs paring probelm we will learn how man
    int n;
    cin>>n;
    int m;
	cin>>m;
    DSU g(n);
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		g.union_set(x,y);
	}
	int total=0;
	for(int i=0;i<n;i++)
	{
		total+=n-g.rank[g.find_set(i)];
	}
	total=total/2;
	cout<<total<<endl;
}
int32_t main()
{
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
   


            return 0;


}


