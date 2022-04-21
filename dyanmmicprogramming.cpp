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
#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define repi(i,a,b)     for(int i=a;i>=b;i--)
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define sp(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define cell(x)         sizeof(x)/sizeof(x[0])
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

//dyanmic prgramming 
//dyanmmic prgramming used to solve the mainy prgeblems easy
//where allpy dyamnimc prgraomming

//1. optimal substrucute means your ans represnt into subproblem or dividing problem into smaller problem
//2.overlapping subproblem 

//top down approch 
//means recusrsion +memorization

//bottom up approch
//means start from base case climb upto bigger problem



//first solve the fibonnic number
//fining the nth fibonnic number
int fibo(int n)
{
    if(n==0||n==1)
    {
        return n;
    }
    return fibo(n-1)+fibo(n-2);
    //time compixty of the this recurrsio n is 2^n
}
int dp[1000]={0};//we can use hasmap for the larger calue of n
int fibonacci_with_dp(int n)
{
    if(n==0||n==1)
    {
        return n;
    }
    else if(dp[n]!=0)
    {
        return dp[n];
    }
    int ans= fibonacci_with_dp(n-1)+fibonacci_with_dp(n-2);
    return dp[n]=ans;
    //time compixty of the this recurrsio n is 2^n
}
//bottom up approch
int fibo_bottom_up(int n)
{
    int dp[10000]={0};
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
//space optimized
int fibo_space(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    int first=0;
    int second=1;
    int ans;
    for(int i=2;i<=n;i++)
    {
        ans=first+second;
        second=first;
        first=ans;
    }
    return ans;
}

//miniimum step to one 
//if n%3==0 n=n/3
//if n%2==0 then n=n/2
//e;se n=n-1;
int minimum_step_to_one(int n)
{
    if(n==1)
    {
        return 0;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;
    if(n%3==0)
    {
        op1=minimum_step_to_one(n/3)+1;
    }
    if(n%2==0)
    {
        op2=minimum_step_to_one(n/2)+1;
    }
    op3=minimum_step_to_one(n-1)+1;
    int ans=min(op1,min(op2,op3));
    return dp[n]=ans;
}

int minimum_step_to_one_bottom(int n)
{
    int dp[1000]={0};
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        int op1,op2,op3;
        op1=op2=op3=INT_MAX;
        if(i%3==0)
        {
            op1=dp[i/3];
        }
        if(i%2==0)
        {
            op2=dp[i/2];
        }
        op3=dp[i-1];
        dp[i]=min(op1,min(op2,op3))+1;
    }
    return dp[n];
}
//minimu conis change problem to take chain mimnimum step
//it greedy will fail if applu theon this quesiton
//if indian rupees are theri then greedy will pass
//but currencyh of certian denom,ination then greedy will fail
int solve_the_minimum_coins_change_problem(int n,int *coins,int T)
{
    if(n==0)
    {
        return 0;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    int ans=INT_MAX;
    for(int i=0;i<T;i++)
    {
        if(n-coins[i]>=0)
        {
            int subproblem=solve_the_minimum_coins_change_problem(n-coins[i],coins,T)+1;
            ans=min(ans,subproblem);
        }
    }
    dp[n]=ans;
    return dp[n];
}
int bottom_up_minimum_coins(int num)
{
     int n;
    int coins[]={1,2,5,10,20,50,100,200,500,2000};
    n=sizeof(coins)/sizeof(int);
    int dp[100000]={0};
    for(int i=1;i<=num;i++)
    {
        int ans=INT_MAX;
        for(int j=0;j<n;j++)
        {
            if(i-coins[j]>=0)
            {
                ans=min(ans,dp[i-coins[j]]);
            }
            
        }
        dp[i]=ans+1;
        
    }
    return dp[num];

}
int wines[1000][1000]={0};
int wines_problem(int year,int *arr,int s,int e)
{
    if(s>e)
    {
        return 0;

    }
    if(wines[s][e]!=0)
    {
        return wines[s][e];
    }
    //have two cases to solve the anserr first will select the first element and secons ieill select 
    //the last element
    int op1=year*arr[s]+wines_problem(year+1,arr,s+1,e);
    int op2=year*arr[e]+wines_problem(year+1,arr,s,e-1);
    int ans=max(op1,op2);
    return wines[s][e]=ans;

}
int wines_bottom_up(int *arr,int n)
{
    int dp[1000][100]={0};
    for(int i=0;i<n;i++)
    {
        dp[i][i]=arr[i]*n;
    }
    for(int j=0;j<n;j++)
    {
        int yr=n-1;
        for(int i=n-1;i>=0;i--)
        {
            if(i>=j)
            {
                continue;
            }
            int op1=0;
            int op2=0;
            if(i+1<=n)
            {
                op1=dp[i+1][j]+arr[i]*yr;
            }
            if(j-1>=0)
            {
                op2=dp[i][j-1]+arr[j]*yr;
            }
            yr--;
            dp[i][j]=max(op1,op2);
        }
    }
    return dp[0][n-1];
    
}
//maximum subraay sum 
//you can have kandanlse algorithm
//but now we apply dp
//apprcoh n^3 thre loop for i and j and computing the sun
//approch make cu,mmaltice sum also and the (n^2)
//approch thre use the kadanese algorithm
void maximum_subrray(int *arr,int n)
{
    int dp[1000]={0};
    int maxsorfar=0;
    dp[0]=arr[0]>0?arr[0]:0;
    for(int i=1;i<n;i++)
    {
        dp[i]=dp[i-1]+arr[i];
        if(dp[i]<0)
        {
            dp[i]=0;
        }
        maxsorfar=max(maxsorfar,dp[i]);
    }
    cout<<maxsorfar<<endl;
    maxsorfar=arr[0];
    int current=arr[0];
    for(int i=1;i<n;i++)
    {
        current=max(current+arr[i],arr[i]);
        maxsorfar=max(current,maxsorfar);
    }
    cout<<maxsorfar<<endl;
}
int ladder[10000]={0};
int ladder_problem_top_down(int n,int k)
{
    if(n==0)
    {
        return 1;
    }
    if(ladder[n]!=0)
    {
        return ladder[n];
    }
    int ans=0;
    for(int i=1;i<=k;i++)
    {
        if(n-i>=0)
        {
        ans+=ladder_problem_top_down(n-i,k);
        }
    }
    ladder[n]=ans;
    return ladder[n];

}
int ladder_bootome(int n,int k)
{
    int dp[10000]={0};
    dp[0]=1;
    rep(i,1,n)
    {
        int ways=0;
        rep(j,1,k)
        {

            if(i-j>=0)
            {
                ways+=dp[i-j];
                
            }
        }
        dp[i]=ways;
    }
    return dp[n];
}
int optimized_ladder(int n,int k)
{
    int dp[1000]={0};
    dp[0]=dp[1]=1;
    rep(i,2,k)
    {
        dp[i]=dp[i-1]*2;
    }
    rep(i,k+1,n)
    {
        dp[i]=2*dp[i-1]-dp[i-k-1];
    }
    return dp[n];
}
int ropes_cut(int len,int *prices,int n)
{
    if(len<=0)
    {
        return 0;
    }
    int ans=INT_MIN;
    rep(i,0,n-1)
    {
        int currentlen=i+1;
        if(len-currentlen>=0)
        {
       int current=prices[i]+ropes_cut(len-currentlen,prices,n);
       ans=max(ans,current);
        }
    }
    return dp[len]=ans;
}

//longest common subsequence 
int lcs_top_down(string a,string b,int i,int j,vector<vector<int>>&dp)
{
    if(i==a.length()||j==b.length())
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(a[i]==b[j])
    {
        return 1+lcs_top_down(a,b,i+1,j+1,dp);
    }
  
      int op1= lcs_top_down(a,b,i+1,j,dp);
      int op2= lcs_top_down(a,b,i,j+1,dp);
      return dp[i][j]=max(op1,op2);
}

//longest increasing subsequence
//apporch dp1 
//aproch dp2 tricky
//aproch dpp with binary search
//approch dp with with segemnt tree


//apptoch 1 
//what thime compplextiy of this qpporch is o(n^2)
//dp[i]=max(dp[j])+1 j<i and arr[j]<arr[i]
int lis_using_dp1(int *arr,int n)
{
    int dp[100001]={0};
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        int ans=0;
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
            {
            ans=max(ans,dp[j]);
            }
        }
        dp[i]=ans+1;
    }
    rep(i,0,n-1)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    return dp[n-1];
}
int lis_using_dp2(int *arr,int n)
{
    int dp[n+1];
    dp[0]=INT_MIN;
    for(int i=1;i<=n;i++) dp[i]=INT_MAX;
    for(int i=0;i<n;i++)
    {
        for(int length=0;length<n;length++)
        {
            if(dp[length]<arr[i]&&dp[length+1]>arr[i])
            {
                dp[length+1]=arr[i];
            }
        }
    }
    int lis=0;
    for(int i=1;i<=n;i++)
    {
        if(dp[i]!=INT_MAX)
        {
            cout<<dp[i]<<" ";
            lis=i;
        }
    }
    cout<<endl;
    return lis;
}
//in the approch we can apply the binary search for finding the dp[;enghth]<arr[i]&&dp[lenght+1]>arr[i]
//so dp[lenght]to dp[lengt+1] is monotinoic in nature
int lis_using_dp3(int *arr,int n)
{
    int dp[n+1];
    dp[0]=INT_MIN;
    for(int i=1;i<=n;i++) dp[i]=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int idx=lower_bound(dp,dp+n+1,arr[i])-dp;
        //this nlogn aporch 
        dp[idx]=arr[i];
    }
    int lis=0;
    for(int i=1;i<=n;i++)
    {
        if(dp[i]!=INT_MAX)
        {
            cout<<dp[i]<<" ";
            lis=i;
        }
    }
    cout<<endl;
    return lis;
}


// hackerblocks meltosis
int cell_metosis_parteek(int n,int x,int y,int z)
{
    int dp[100001]={0};
    for(int i=2;i<=n;i++)
    {
    //     x== use for the doub;ling 
    //     y== uise for the incremnt 
    //     z= is ue for the decrement
        if(i%2==0)
        {
            //if my i is multple of 2 that means eithir it comes from the doubling or incereament 
            //but we can use the degerement fromt beaycs ewe do  not find the 
            dp[i]=min(dp[i/2]+x,dp[i-1]+y);
        }
        else{
            dp[i]=min(dp[i-1]+y,dp[(i+1)/2]+x+z);
        }

    }
    return dp[n];
}



//matrix chain mulitiplication 
//findign the minimum number of ooperation to muliplay many matrix
//so if one matrix of order is i*k and another matrix is k*j then resultant marix is i*J and 
//number of operation requyired is i*j*K

//bereking of the marix in the part
//scuh that i to k to j
//so f(i,j)=f(i,k)+f(k+1,j)+cost Of combining arr[i-1]*arr[k]*arr[j]

//this is over;aplling subproblem then aplly the dyanmic programinng 
int tdp[100][100];

int matrix_multitiplay(int *arr,int i,int j)
{
    if(i==j){
        tdp[i][j]=0;
        return 0;
    }
    if(tdp[i][j]!=-1)
    {
        return tdp[i][j];
    }
    int ans=inf;
    for(int k=i;k<j;k++)
    {
        int temp=matrix_multitiplay(arr,i,k)+matrix_multitiplay(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        ans=min(ans,temp);
    }
    return tdp[i][j]= ans;
}
//now we apply bootom up aproch
int bootom_up_matrix(int *arr,int n)
{
    int dp[100][100]={-1};
    int i,j,k,l;
    rep(i,0,n-1)
    {
        dp[i][i]=0;
    }
    for(int l=2;l<=n-1;l++)
    {
        for(int i=1;i<=n-l;i++)
        {
            int j=i+l-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]);

            }
        }

    }
    return dp[1][n-1];

}

void imput_of_matrix()
{
    int arr[]={18,19};
    int n=cell(arr);
  memset(tdp,-1,sizeof(tdp));
    
    int ans=matrix_multitiplay(arr,1,n-1)%100;
    cout<<ans<<endl;


}
int arr[1000];
int ttdp[1000][1000];
 int sum_solve(int s,int e)
{
	 int sum=0;
	for(int i=s;i<=e;i++)
	{
		sum+=arr[i];
		sum=sum%100;
	}
	return sum;
}
 int solve_cell(int i,int j)
{
	if(i>=j)
	{
		return 0;
	}
	if(ttdp[i][j]!=-1)
	{
		return ttdp[i][j];
	}
	ttdp[i][j]=INT_MAX;
	for(int k=i;k<=j;k++)
	{
		ttdp[i][j]=min(ttdp[i][j],solve_cell(i,k)+solve_cell(k+1,j)+(sum_solve(i,k)*sum_solve(k+1,j)));
		
	}

	return  ttdp[i][j];
}
int solve_game(int *arr,int i,int j,int n,int tdp[100][100])
{
    if(i>j)
    {
        return 0;
    }
    if(tdp[i][j]!=0)
    {
        return tdp[i][j];
    }
    //thier are two cases 
    //if mode select from the first element then
    int op1=arr[i]+min(solve_game(arr,i+2,j,n,tdp),solve_game(arr,i+1,j-1,n,tdp));
    int op2=arr[j]+min(solve_game(arr,i+1,j-1,n,tdp),solve_game(arr,i,j-2,n,tdp));
    return tdp[i][j]= max(op1,op2);
}




//grid based dp
//minuimu cost and maximum cost
//wasy to reach to the cell from the soruce

//the question first sas that finding the cost of reachigng to end of the matrix
//you should reach to right and down
int matrix_solve_path(int r,int c)
{
    int dp[100][100];
    int cost[100][100];//given the cost matrix
    memset(dp,0,sizeof(dp));
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i==0 and j==0)
            {
                dp[i][j]=cost[i][j];
            }
            else if(i==0)
            {
                dp[i][j]=dp[i][j-1]+cost[i][j];

            }
            else if(j==0)
            {
                dp[i][j]=dp[i-1][j]+cost[i][j];
            }
            else{
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+cost[i][j];
            }

        }
    }
    return dp[r-1][c-1];
}
int solve_codechef_matrix()
{
    int m,n,p;
    cin>>m>>n>>p;
    int dp[100][100];
    memset(dp,0,sizeof(dp));
    while(p--)
    {
        int i,j;
        cin>>i>>j;
        dp[i-1][j-1]=-1;
    }
    if(dp[0][0]==-1) 
    {
        return 0;
    }
    for(int i=0;i<m;i++)
    {
        if(dp[i][0]==-1)
        {
            break;
        }
        dp[i][0]=1;

    }
    for(int i=0;i<n;i++)
    {
        if(dp[0][i]==-1)
        {
            break;
        }
        dp[0][i]=1;

    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(dp[i][j]==-1)
            {
                continue;
            }
            dp[i][j]=0;
            if(dp[i][j-1]!=-1)
            {
                dp[i][j]=dp[i][j-1]%mod;
            }
            if(dp[i-1][j]!=-1)
            {
                dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
            }
        }
    }
    if(dp[m-1][n-1]==-1)
    {
        return 0;
    }
    return dp[m-1][n-1];
 
}

int32_t main()
{
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    int ans=(int)solve_codechef_matrix();
    cout<<ans<<endl;



            return 0;


}


