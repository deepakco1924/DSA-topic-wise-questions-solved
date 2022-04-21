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
//GREDDy _algorgithm
//it is most inuitive algorithm
//first we se any question first apply greedy algorithm
//it is simple and easy to apply


//greedy approch chossing the step best at that moment
//which is locally optimum


//queation indian coin change progble
//coin change progrlam is indian crreuncya apply greddy
//but foreign currecy fail
int cioin_change(int money)
{
    int count=0;
    int coins[]={1,2,5,10,20,50,100,200,500,2000};
    int n=sizeof(coins)/sizeof(int);
    //coins are in sorted order
    while(money>0)
    {
        int idx=upper_bound(coins,coins+n,money)-1-coins;
        count++;
        cout<<coins[idx]<<" + ";
        money=money-coins[idx];
    }
    cout<<endl;
    return count;
}


///activity selection problem
//sort according to ending time
//not for starting time

bool compare(pii a,pii b)
{
    return a.second<b.second;
}
int solve()
{
        int n;
        cin>>n;
        pair<int,int>activity[100001];
        for(int i=0;i<n;i++)
        {
            int s;
            int e;
            cin>>s>>e;
            activity[i]=make_pair(s,e);
        }
        sort(activity,activity+n,compare);
        int count=1;
        int prev=activity[0].second;
        for(int i=1;i<n;i++)
        {
            if(prev<=activity[i].first)
            {
                count++;
                prev=activity[i].second;
            }

        }
        return count;


}

//quesiton connecting wire problem
//we sort black dts and whits dots 
//connect correspodint like ans+=abs(white[i]-black[i])

int solve_rank()
{
    int n;
    cin>>n;
    pair<int,string>p[n];
    for(int i=0;i<n;i++)
    {
        string s;
        int pos;
        cin>>s>>pos;
        p[i]=make_pair(pos,s);
    
    }
    int ans=0;
    sort(p,p+n);
    for(int i=0;i<n;i++)
    {
        ans+=abs(p[i].first-(i+1));

    }
    return  ans;
}


//load balancer question
//find the number ofrounds  to equall all cell
void solve_load_balancer()
{
        int arr[100001];
        int n;
    while(1)
    {
        memset(arr,0,sizeof(arr));
        cin>>n;
        if(n==-1)
        {
            break;
        }
        int laod=0;
        int maxload=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            laod+=arr[i];
        }
        if(laod%n!=0)
        {
            cout<<"-1"<<endl;
            continue;
        }
        laod=laod/n;
        int dif=0;
        for(int i=0;i<n;i++)
        {
            dif+=(arr[i]-laod);
            maxload=max(maxload,abs(dif));


        }
        cout<<maxload<<endl;

    }
} 

//solve the defkin quesiton spoj
//apprch area is badsically dx*dy
//you want to maximum the dx as well dy
int defkin()
{
    // int w,h;
    // cin>>w>>h;
    // int n;
    // cin>>n;
    // int ax[40001]={0};
    // int ay[40001]={0};
    // for(int i=0;i<=n;i++)
    // {
    //    cin>>ax[i]>>ay[i];
    // }
    // sort(ax,ax+n);
    // sort(ay,ay+n);
    // int dx=0;
    // int dy=0;
    // int prevx=0;
    // int prevy=0;
    // for(int i=1;i<n;i++)
    // {
    //    dx = max(dx, ax[i] - prevx - 1);
    //     prevx = ax[i];
    //     dy = max(dy, ay[i] - prevy - 1);
    //     prevy = ay[i];

    // }
    //   dx = max(dx, w- prevx);
    // dy = max(dy, h- prevy);
    // return dy * dx;
      int x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    int arrx[n];
    int arry[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arrx[i] >> arry[i];
    }
    sort(arrx, arrx + n);
    sort(arry, arry + n);
    int dfx;
    int dfy;
    dfx = dfy = 0;
    int prevx = 0;
    int prevy = 0;
    for (int i = 0; i < n; i++)
    {
        dfx = max(dfx, arrx[i] - prevx - 1);
        prevx = arrx[i];
        dfy = max(dfy, arry[i] - prevy - 1);
        prevy = arry[i];

    }
    dfx = max(dfx, x - prevx);
    dfy = max(dfy, y - prevy);
    return dfy * dfx;


}

//chopstick
//codechef
int solve_stick()
{
    int n,d;
    cin>>n>>d;
    int arr[100001];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int count=0;
    sort(arr,arr+n);
    for(int i=0;i<n;)
    {
        if(abs(arr[i+1]-arr[i])<=d)
        {
            count++;
            i+=2;
        }
        else{
            i++;
        }
    }
    return count;
}
bool comp(pii a,pii b)
{
    return a.first>b.first;
}
//expediation
//spoj
int  solve_expedi()
{
    int n;
    cin>>n;
    vector<pair<int,int>>vec;
    for(int i=0;i<n;i++)
    {
        int d,f;
        cin>>d>>f;
        vec.push_back(make_pair(d,f));
    }
    sort(vec.begin(),vec.end(),comp); //sort the fuel station which is nearest to truck
    int D,F;
    cin>>D>>F;
    for(int i=0;i<n;i++)
    {
        vec[i].first=D-vec[i].first;
    }
    priority_queue<int>pq; //queue add fuel station which have till now visisted
    int x=0;
    int ans=0;
    int prev=0;
    bool flag=false;
    while(x<n)
    {
        if(F>=(vec[x].first-prev))//distanve of current fuel station to next staiton if you have enought
         {//fuel to go to the next fuel station then good to go add cuurent fuel staiton fuel to quees
            F=F-(vec[x].first-prev);//change your previpus to this staion 
            prev=vec[x].first;
            pq.push(vec[x].second);
            x++;

        }
        else{
            if(pq.empty())//else means you have not enough fuel to reach next fuel staion
            {//remove from the queeu add to fuel and remain pop fuel till you get ennoug fuel to reach next
                flag=true;//if you have not fuel oin quee then reutrn zero means not possible
                return -1;
            }
            F+=pq.top();
            ans++;
            pq.pop();
        }
    }
    if(flag==true)//flag zero means you not reached to n fuel 
    {
        return -1;

    }
    //you reached end of the final fuel destination
    //now you have to handle the case of town and last fuel
    D=D-vec[n-1].first;
    if(F>=D)
    {
        return ans;
    }
    //that means you have to get the fuel from station
    while(F<D)
    {
        if(pq.empty())
        {
            flag=true;
            return -1;
        }
        F+=pq.top();
        pq.pop();
        ans++;
    }
    return ans;
    

}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    w(x)
    {
       cout<< solve_expedi()<<endl;
    }

return 0;


}