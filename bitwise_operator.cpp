#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
#define zerobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define sp(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

// thier are five operator
//AND operator &   or | operator  xor^ operator   ~ operator flip the bits  <<left shift >>right shift
//1&1==1       1|1=1          1^1=0
//1&0==0        0|1=1          0^0=1
//0&1==0        1|0=1           1^0=0
//0&0==0        0|0=0           0^1=0

//xor of same nmbers are is zero always
//a<<b means multiply a by 2^b
//a>>b means divide a by 2^b
//xor of number and zero is number



//1,quetion is you have 2n+1 element but 1 one number is unique find that number
int solve_unique1(int *arr,int n)
{
    int ans=0;
    for(int i=1;i<n;i++)
    {
        ans=ans^arr[i];

    }
    return ans;

}

//now we have to check the number is even or odd
//(number&1)==1 if number is odd and if zero then is even
bool isodd(int num)
{
    return (num&1);
}
int getbit(int num,int i)
{
    // int mask=(1<<i);
    // int ans=(num&mask);
    // if(ans!=0)
    // {
    //     return 1;
    // }
    // return 0;
    return (num&(1<<i))>0?1:0;

}
void set_bit(int &num,int i)
{
    int mask=(1<<i);
    num=num|mask;   
    return ; 
}
void update_bit(int &num,int i,int v)
{
    //we have to pdate the  ith bit solve by v v is 1 or 0
    //firt clear the ith bit and then or with 000000v00000000 mask
    int mask=~(1<<i);
    num=num&mask;
    int new_mask=(v<<i);
    num=num|new_mask;
    return ;

}
void clear_ith_bit(int &num,int i)
{
    int mask=~(1<<i);
    num=num&mask;
    return ;
}
void clear_the_rangeofbit_from_rigth(int num,int i)
{
    int mask(-1<<i);
    num=num&mask;
}
void clear_the_range_ofbit(int &num,int i,int j)
{
    int a=(-1<<(j+1));
    int b=(1<<i)-1;
    int mask=a|b;
    num=num&mask;
    return ;
}
//question of bitmasking to sovle the 
//you are given two 32 bit numbers n,m ans two position i,j
//set all the range of i to j in N same have M
void question_of_range(int N,int M,int i,int j)
{
    //first you have to clear the range of N from i to j
    //and mask of m and or with N
    int a=(-1<<(j+1));
    int b=(1<<i)-1;
    int mask=a|b;
    N=N&mask;
    N=N|(M<<i);
    return ;
}
void count_set_bit(int num)
{
    //basic approch is
    int count=0;
    while(num!=0)
    {
        int last_bit=(num&1);
        if(last_bit)
        {
            count++;
        }
        num=num>>1;

    }


    //2nd apprch is fast then another apperochj
    int ans=0;
    while (num>0)
    {
        num=num&(num-1);
        ans++;
        /* code */
    }
    

    //3 apprch inbuilt in function
    ans=setbits(num);

    
}
void decimal_to_binary(int num)
{
    int ans=0;
    int p=1;
    while(num>0)
    {
        int last_bit=(num&1);
        ans+=(last_bit*p);
        p=p*10;
        num=num>>1;
    }
    cout<<"binary_represnation is "<<ans<<endl;

}
void solve_unique2(int *arr,int n)
{
    int result=0;
    for(int i=0;i<n;i++)
    {
        result=result^arr[i];
        
    }
    int temp;
    temp=result;
    int pos=0;
    while((temp&1)!=1)
    {
        pos++;
        temp=temp>>1;

    }
    int mask=(1<<pos);
    temp=0;
    for(int i=0;i<n;i++)
    {
        if((arr[i]&mask)>0)
        {
            temp=temp^arr[i];

        }
    }
    result=result^temp;
    cout<<temp<<endl;
    cout<<result<<endl;

}
void solve_unique_3()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];


    int cnt[64];
    clr(arr); 
    for(int i=0;i<n;i++)
    {
        int num=arr[i];
        int j=0;
        while(num>0)
        {
            cnt[j]+=(num&1);
            j++;
            num=num>>1;
        }
    }
    int p=1;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        arr[i]=arr[i]%3;
        ans+=arr[i]*p;
        p=p*2;
    }
    cout<<ans<<endl;
    return ;

}
void expoenttiaion(int a,int n)
{
    int ans=1;
    while(n>0)
    {
        int last_bit=(n&1);
        if(last_bit)
        {
            ans=ans*a;
        }
        a=a*a;
        n=n>>1;
    }
    cout<<ans<<endl;
}
void findprint(int i,string s)
{
    int j=0;
    while(i>0)
    {
        if(i&1)
        {
            cout<<s[j];
        }
        j++;
        i=i>>1;
    }
    cout<<endl;
    return ;
}
int toogel_the_ith_bit(int num,int i)
{
    return num^=(1<<i);
    
}
int get_lsb(int n)
{
    //postione not index
    return log2(n&(-n));
}
void substring(string s) 
{
    //in this we find all the subset of the string 
    // if the string n charachter ther are 2*n-1 subset in excluding the null subset
    int n=s.length();
    for(int i=1;i<(1<<n);i++)
    {
        findprint(i,s);

    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
int n;
cin>>n;
int ans=log2(n);
cout<<ans<<endl;
return 0;


}