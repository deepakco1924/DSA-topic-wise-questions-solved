#include <bits/stdc++.h>
#include<stdio.h>
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

const int MAXN = 100005LL;

 
int fact[MAXN], inv[MAXN], Tn;
int arr[MAXN];
int freq[MAXN];
int lastocuur[MAXN];
bitset<MAXN>prime;
bitset<MAXN>net;
vector<int>primefactor;
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
 
int power (int x, int y)
 {
     if(y==0)
     {
         return 1;
     }
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
pair<int,int> solve_liner_diaphontine(int a,int b,int c)
{
    pair<int,int>p;
    if(c%__gcd(a,b)!=0)
    {
        p.first=-1;
        p.second=-1;
        return p;

    }
    int k=c/__gcd(a,b);
    int x,y;
    extgcd(a,b,x,y);
    x=k*x;
    y=k*y;
    if(a<0)x=-x;
    if(b<0)y=-y;
    p.first=x;
    p.second=y;
    return p;
}
//fidninign the range of soltuion of linerar diophontine equatio

int gcd(int a,int b)
{
    if(b==0)
    {
        return   a;
    }
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
  return a*b/__gcd(a,b);
}
int inversmod(int a,int m)
{
    if(__gcd(a,m)!=1)
    {
        return -1;
    }
    int x,y;
    extgcd(a,m,x,y);
    x=(x+m)%m;
    return x;
}
//number theroy first solve the prime of eronthisis
void prime_seive()
{
    prime.set();
    int n =MAXN;
   prime[0] = prime[1] = false;
   for(int i=2;i<=n;i+=2)
   {
       prime[i]=false;
   }
   prime[2]=1;
   primefactor.pb(2);
for (int i = 3; i <= n; i+=2) {
    if (prime[i]) {
        primefactor.pb(i);
        for (int j = i * i; j <= n; j += i)
            prime[j] = false;
    }
}
}
// if number is big to check the prime
bool check_prime(int n)
{
    if((int)n<MAXN)
    {
        return prime[n]?true: false;
    }
    int lim=sqrt(n);
  for(int i=2;i<=lim;i++)
  {
      if(n%i==0)
      {
          return false;
      }
  }
    return true;
}
//solve almost prime are thier
void solve_almost_prime(int n)
{
    int prime[4000]={0};
    for(int i=2;i<=n;i++)
    {
        
        if(prime[i]==0)
        {
            for(int j=2*i;j<=n;j=j+i)
            {
                prime[j]++;
            }
        }
    }
    int ans=0;
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==2)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return;
}
//segmented sieve
//it use for the the generating the prime number betwween the tow numbers
vector<bool> segmentedSieve(int L, int R) {
    // generate all primes up to sqrt(Rint lim = sqrt(R);
    int lim=sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<int> primes;
    for (int i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (int j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }
    vector<bool> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;

 
}
vector<pair<int,int>> sieve_primefactors(int m)
{
    vector<pair<int,int>> ans;
    ans.clear();
    int i=0;
    int p=primefactor[0];
    int count=1;
    while(p*p<=m)
    {
        if(m%p==0)
        {
            int cnt=0;
            while(m%p==0){
            m/=p;
            cnt++;
            }
            ans.push_back(make_pair(p,cnt));
            count=count*(cnt+1);
        }
        i++;
        p=primefactor[i];
    }
    if(m!=1)
    {
        ans.push_back(make_pair(m,1));
        count=count*2;
    }
    return ans;

}
void factorial_problem()
{
    int n,k;
    int ans=INT_MAX;
    cin>>n>>k;
    for(int i=2;i*i<=k;i++)
    {
        if(k%i==0)
        {
            int occur=0;
            while(k%i==0)
            {
                occur++;
                k/=i;
            }
            int num=n;
            int temp=0;
            while(num)
            {
                num=num/i;
                temp+=num;
            }
            ans=min(ans,temp/occur);
        }
    }
    if(k!=1)
    {
        int temp=0;
        while(n)
        {
            n=n/k;
            temp+=n;
        }
        ans=min(ans,temp);
    }
    if(ans==INT_MAX)
    {
        cout<<"0"<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    return ;
}
string converthemod(string &s)
{
    reverse(all(s));
    string result;
    int p=1;
    for(int i=0;i<s.length();i++)
    {
        int x=s[i]-'0';
        int ans=power(x,p);
        p=(p*p)%mod;
        result.push_back(ans+'0');
    }
    reverse(all(result));
    return result;
}
//cycle property of the mod to solve in range is called 
//in the main in ragen is sove ut w uif  at   ah  f
// intth4r ====
//in th range is cvaledf fgir 
//it solve the in range is called,
int solve_helper(int a,int b,int r,int count )
{
      int x=(r/(a*b))*count;
        for(int i=0;i<=r%(a*b);i++)
        {
            if(arr[i]==1)
            {
                x++;
            }
 
        }
        return x;

}
void solve_count()
{
    int a,b;
    cin>>a>>b;
    int q;
    cin>>q;
    clr(arr);
    int count=0;
    for(int i=0;i<a*b;i++)
    {
        int x=((i%a)%b);
        int y=((i%b)%a);
        if(x!=y)
        {
            arr[i]=1;
            count++;
        }
 
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int x=solve_helper(a,b,r,count);
        int y=solve_helper(a,b,l-1,count);
   
        cout<<(x-y)<<" ";
 
    }
 
 
}


 bool check_perfect(int x)
 {
     long double sr=sqrt(x);
      return ((sr - floor(sr)) == 0); 
 }
 void solve_football()
 {
     int n,p,w,d;
     cin>>n>>p>>w>>d;
     int g=__gcd(w,d);
     if(p%g!=0)
     {
         cout<<"-1"<<endl;
         return ;
     }
     //if hwe wins all the mathces;
     if(n*w<p)
     {
         cout<<"-1"<<endl;
         return ;
     }
     //now theri is the solvtuion
 
     p=p/g;
     w=w/g;
     d=d/g;
     mod=w;

     int y=((p%mod)*inversmod(d,mod))%mod;
     int x=(p-y*d)/w;
     if(x<0 || x+y>n)
     {
         cout<<"-1"<<endl;
         return ;
     }
     int z=n-x-y;
     cout<<x<<" "<<y<<" "<<z<<endl;
     return; 
 }
 //miler rabin test to check thr number is prime of order 10^18
 int modular_multiplication(int a,int b,int n)
 {
     int res=0;
     while(b)
     {
         if(b&1LL)
         {
             res+=(a)%n;

         }
         b=b>>1;
         a=(2*a)%n;
     }
     return res;

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
 //rilzwe is called for this 
 //man in nature is to solve
 //the factorial is to one move is called for this is nature is
 //in nature is called for this man
 //takeing 
 bool miler_rabin(int n)
 {
     if(n==1)return false;
     if(n==2)return true;
     if(n%2==0) return false;
     //now fromt his my number is odd and checking for the prime
     int d=n-1;
     int s=0;
     while(d%2==0)
     {
         d=d/2;
         s++;
     }
     vector<int>a{2,3,5,7,11,13,17,19,23,29,31,37,41,43};
     for(int i=0;i<a.size();i++)
     {
         if(a[i]>n-2) continue;
         int ad=modular_exponetion(a[i],d,n);
         if(ad%n==1) continue;
         //now check for the other values;
         bool primemila=false;
         for(int r=0;r<=s-1;r++)
         {
             int rr=modular_exponetion(2,r,n);
             int add=modular_exponetion(ad,rr,n);
             if(add%n==n-1)
             {
                primemila=true;
                break;
             }
         }
         if(primemila==false)
         {
             return false;
         }
     }
     return true;
 }
 vi calculate_mobious()
 {
     //calculte the mobious for n
     int n=MAXN;
     vi prime_count(n+1,0);
     vi arr(n+1,1);
     vi mobious(n+1);  
     for(int i=1;i<=n;i++)
     {
         arr[i]=1;
     }
     for(int i=2;i<=n;i++)
     {
         if(prime_count[i]) continue;
         for(int j=i;j<=n;j+=i)
         {
             prime_count[j]++;
             arr[j]=arr[j]*i;
         }

     }
     for(int i=1;i<=n;i++)
     {
         if(arr[i]==i)
         {                                                                                                                                                                                                                                  
             if(prime_count[i]%2==1)
             {
                 mobious[i]=-1;
             }
             else{
                 mobious[i]=1;
             }

         }
         else{
             mobious[i]=0;
         }
     }
     return mobious;
  
 }
 void calutation_coprime_subaquuwnce()
 {
     int ans=0;
     vi mob=calculate_mobious();
     int n;
     cin>>n;
     vector<int>p2(MAXN);
     clr(freq);
     for(int i=0;i<n;i++)
     {
         cin>>arr[i];
         freq[arr[i]]++;
     }
     p2[0]=1;
     for(int i=1;i<MAXN;i++)
     {
         p2[i]=(p2[i-1]*2)%mod;
     }
     for(int i=1;i<MAXN;i++)
     {
         int cnt=0;
         for(int j=i;j<MAXN;j+=i)
         {
             cnt+=freq[j];

         }
         int total=p2[cnt]-1;
         ans+=(mob[i]*total)%mod;
         if(ans<0)
         {
             ans=(ans+mod)%mod;
         }
     }
     cout<<ans%mod<<endl;

 }
 void borring_factorial()
 {
        int t;
           cin>>t;
           while(t--)
           {
               int n,p;
               cin>>n>>p;
               if(n>=p)
               {
                   cout<<"0"<<endl;
                   continue;
               }
               int res=-1;
               for(int i=n+1;i<=p-1;i++)
               {
                   int temp=modular_exponetion(i,p-2,p);
                   res=(res*temp)%p;
               }
               res=(res+p)%p;
               cout<<res<<endl;
           }
 }


//fibonici numebrs is easly by the binary exponention 
//their is the hack on the codefoece to clatulca the nthe fiboncci numbers
map<int, int> F;
int fibo(int n) {
	if (F.count(n)) return F[n];
	int k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (fibo(k)*fibo(k) + fibo(k-1)*fibo(k-1)) % mod;
	}  // n=2*k+1
		return F[n] = (fibo(k)*fibo(k+1) + fibo(k-1)*fibo(k)) % mod;
	
}


//chinese remainder theoram
//to solve the x%p=k
//
int crt_new(vector<pair<int,int>>v)
{

    int n=v.size();

    int  prod=1;

    for(int i=0;i<n;i++)
    {
        prod*=v[i].second;
    }



        int ret=0;

    for(int i=0;i<n;i++)
    {
        int now=prod/v[i].second;

        int zz=(v[i].first*inversmod(now,v[i].second))%prod;

        zz=(zz*now)%prod;

        ret=(ret+zz)%prod;
    }

    return ret;

}
int chinece_remainder_theroma(vector<pair<int,int>>v)
{
    int n=v.size();
    int m=1;
    for(int i=0;i<n;i++)
    {
        m*=v[i].first;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int t=1;
        for(int j=0;j<i;j++)
        {
            t*=v[j].first;
            t*=inversmod(v[j].first,v[i].first);
            t%=m;
        }
        ans+=(v[i].second-ans+m)*t;
        ans%=m;
    }
    return ans;

}
int pasacl[1001][1001];
void making_pascal_traingle()
{
    memset(pasacl,0,sizeof(pasacl));
    pasacl[0][0]=1;
    for(int i=1;i<1001;i++)
    {
        pasacl[i][0]=1;
        for(int j=1;j<1001;j++)
        {
            pasacl[i][j]=(pasacl[i-1][j]+pasacl[i-1][j-1])%mod;
        }

    }
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            cout<<pasacl[i][j]<<" ";
        }
        cout<<endl;
    }

}
int power_ans(int x,int y)
{
    if(y==0) return 1;
    if(y==1) return x;
    int q=power_ans(x,y/2);
    q=q*q;
    if(y&1)
    {
        q=q*x;

    }
    return q;
}
int give_me_sum_of_all_divisors(int n)
{
    int p=primefactor[0];
    int i=0;
    int c=0;
    while(n%2==0)
    {
        c++;
        n/=2;
    }
    int ans=1LL;
    if(c>0)
    {
        ans=power_ans(2,c+1)-1;

    }
    i++;
    p=primefactor[i];
    while(p*p<=n)
    {
        if(n%p==0)
        {
            int times=0;
            while(n%p==0)
            {
                times++;
                n/=p;
            }
            int numentor=power_ans(p,times+1)-1;
            int denom=p-1;
            int crrent=numentor/denom;
            ans=ans*crrent;
        }

        i++;
        p=primefactor[i];

    }
    if(n>1)
    {
        ans=ans*(n+1);
    }
    return ans;
  
    
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
          return  0;

 
}