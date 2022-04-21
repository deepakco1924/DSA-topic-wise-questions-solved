#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using pbds= tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef pair<int,pair<int,int>> node;
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define endl "\n"
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,0,sizeof(x))
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
#define zerobits(x)      __builtin_ctzll(x)
#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define mod             1000000007
#define inf             1e18
#define sp(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

//biginterger to solve the number 
//we use factorial number
void multiplay(int *arr,int num,int &n)
{
    int carry=0;
    for(int i=0;i<n;i++)
    {
        int prodcut=arr[i]*num+carry;
        arr[i]=prodcut%10;
        carry=prodcut/10;
    }
    while(carry)
    {
        arr[n]=carry%10;
        carry=carry/10;
        n++;
    }
}
void factorial_big(int num)
{
    int arr[1000]={0};
    arr[0]=1;
    int n=1;
    for(int i=2;i<=num;i++)
    {
        multiplay(arr,i,n);//the answer is stored in the reverse number


    }
    for(int i=n-1;i>=0;i--)
    {
        cout<<arr[i];
    }
    cout<<endl;
    return ;

}
vi divide_by_2(vi  a)
{
    vi ans;
    int rem=0;
    for(int i=0;i<a.size();i++)
    {
        if(rem)
        {
            rem=rem*10+a[i];
            ans.push_back(rem/2);
            rem=rem%2;
        }
        else{
            if(a[i]<2)
            {
                rem+=a[i];
                ans.push_back(0);
            }
            else{
                rem=a[i]%2;
                ans.push_back(a[i]/2);

            }
        }

    }
    vi result;
    int i=0;
    while(ans[i]==0)i++;
    for(;i<ans.size();i++)
    {
        result.pb(ans[i]);
    }
    return result;
}
vi adding_bignumber(vector<int> a,vector<int> b)
{
    reverse(all(a));
    reverse(all(b));
    int len=min(a.size(),b.size());
    vi ans;
    int cary=0;
    for(int i=0;i<len;i++)
    {
        int sum=a[i]+b[i]+cary;
        ans.push_back(sum%10);
        cary=sum/10;
    }
    if(a.size()>len)
    {
        for(int i=len;i<a.size();i++)
        {
            int sum=a[i]+cary;
            ans.push_back(sum%10);
            cary=sum/10;
        }

    }
    if(b.size()>len)
    {
        for(int i=len;i<b.size();i++)
        {
              int sum=b[i]+cary;
            ans.push_back(sum%10);
            cary=sum/10;

        }
    }
    reverse(all(ans));
    return ans;

}


void solve_xor_hail()
{
    int n,x;
    cin>>n>>x;
    int a[100000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int fg,i=0,r,o;
    for( int g=x;g>0 && i<n-1;g--)
     {
         fg=0;
          int p=log(a[i])/log(2);
         r=pow(2,p);
         a[i]=a[i]^r;
         for( int j=i+1;j<n;j++){
             if((a[j]^r) < a[j]){
                 a[j]= a[j]^r;
                 fg=1;
                 break;
             }
         }
         if(fg==0){
             a[n-1]^=r;
         }
         while(a[i] <= 0){
           i++; 
         }
         o=g+1;
     }
     if(o>0){
         if(n<3&&o%2>0){
             a[n-2] ^= 1;
             a[n-1] ^= 1;
         }
     }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
     
        return ;
   
}
vi sub_tract(vi x,vi y)
{
    reverse(all(x));
    reverse(all(y));
    int len=y.size();
    vi ans;

    for(int i=0;i<len;i++)
    {
        if(x[i]<y[i])
        {
            x[i+1]--;
            ans.push_back(x[i]+10-y[i]);
        }
        else{
            ans.pb(x[i]-y[i]);
        }
    }
    if(x.size()>len)
    {
        for(int i=len;i<x.size();i++)
        {
            if(x[i]<0)
            {
                x[i+1]--;
                ans.push_back(x[i]+10);
            }
            else{
                ans.push_back(x[i]);
            }
        }
    }
    reverse(all(ans));
    vi result;
    int i=0;
    while(ans[i]==0)i++;
    for(;i<ans.size();i++)
    {
        result.pb(ans[i]);
    }
    return result;

    return ans;
}
void solve_julka()
{
    string a,b;
    cin>>a>>b;
    vi s1,s2;
    for(int i=0;i<a.length();i++)
    {
        s1.pb(a[i]-'0');

    }
    for(int i=0;i<b.length();i++)
    {
        s2.push_back(b[i]-'0');
    }
    vi ans=adding_bignumber(s1,s2);
    vi div=divide_by_2(ans);
     vi ami=sub_tract(s1,div);
     for(auto c:div)
     {
         cout<<c;
     }
     cout<<endl;
     for(auto c:ami)
     {
         cout<<c;
     }
    return ;

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


