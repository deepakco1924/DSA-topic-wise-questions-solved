#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<int, pair<int, int>> node;
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(x) scanf("%s",&s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(x) printf("%s\n",x)
#define endl "\n"
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,0,sizeof(x)) 
#define f               first
#define s               second
#define int           long long
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
const int MAXN = 2222222LL;



//BINARY SEARCH always using when the function is monotonic means strictly incresing
//or decreasing then or thier is some search space for findign the solution


//in this question we find the first qccurence of the element in array
// it is simple methdod of binary search simple modification is that never stop at value fo to left as
//possible 
int first_occerence(int *arr,int n,int key)
{
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==key)
        {
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]>key)
        {
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}
int last_occerence(int *arr,int n,int key)
{
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==key)
        {
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]>key)
        {
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}


int binarysearch(int *arr,int n,int key)
{
    int s=0;
    int e=n-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]>key)
        {
            e-mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
    //time complwxity of the alogrithm is o(log(n))
    //becacuse each time we discard half of the array
}
//question is that the finding the pivot element or finding the element in sorted and rottated araray
int finding_pivot(int *arr,int n,int key)
{
    int s=0;
    int e=n-1;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        if(arr[mid]==key)
        {
            return mid;

        }
        else if(arr[s]<=arr[mid])
        {
            if(key>=arr[s]&&key<=arr[mid])
            {
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        else{
            if(key>=arr[mid]&&key<=arr[e])
            {
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }

    }
    return -1;
}

void solve_squareroot()
{
    int x;
    cin>>x;
    float ans=-1;
    int s=0;
    int e=x;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        if(mid*mid<=(float)x)
        {
            ans=(float)mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    // for the floting point
    // let take the presceiseon=5;
    int p=5;
    float inc=0.1;
    for(int i=0;i<=p;i++)
    {
        while(ans*ans<=(float)x)
        {
            ans+=inc;
        }
        ans=(float)ans-inc;
        inc=inc/10.0;

    }
    cout<<"the value of square root is  "<<ans<<endl;
    return ;
}
//this is the aggreasive cow question of spoj

bool ispossible(int *arr,int c,int n,int mid)
{
    int count=1;
    int prev=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]-prev>=mid)
        {
            prev=arr[i];
            count++;

        }
        if(count==c)
        {
            return true;
        }

    }
    return false;
}
int solvecow_aggresive(int *arr,int n,int c)
{
    int ans=0;
    sort(arr,arr+n);
    int s=0;
    int e=arr[n-1]-arr[0];
    while (s<=e)
    {
        int mid=(s+e)/2;
        if(ispossible(arr,c,n,mid))
        {
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;

        }
        /* code */
    }
    return ans;
    

}
//QUESITON  the book alocation problem

bool ispossiblebook(int *arr,int n,int m,int mid)
{
    int pages=0;
    int students=1;
    for(int i=0;i<n;i++)
    {
        if(pages+arr[i]>mid)
        {
            students++;
            pages=arr[i];
            if(students>m)
            {
                return false;
            }
        }
        else{
            pages+=arr[i];
        }
    }
    return true;
}
int solvebook(int *arr,int n,int m)
{
    if(n<m)
    {
        return -1;
    }
    int sum=0;
    int s=arr[n-1];
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    int e=sum;
    int ans=INT_MAX;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        if(ispossiblebook(arr,n,m,mid))
        {
            ans=min(ans,mid);
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;

}

//Question
//solve the paratha problem in spoj


bool ispossibleparatha(int *rank,int n,int p,int time)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int current_paratha=0;
        int time_taken=0;
        int no=1;
        while(time_taken+no*rank[i]<=time)
        {
            current_paratha++;
            if(current_paratha>=p)
            {
                return true;
            }
            time_taken+=no*rank[i];
            no++;
        }
        sum+=current_paratha;
        if(sum>=p)
        {
            return true;
        }
    }
    return false;


}
int solveparatha(int *rank,int n,int p)
{
    sort(rank,rank+n);
    int ans=INT_MAX;
    int s=0;
    int e=((p*(p+1))/2)*rank[n-1];
    while(s<=e)
    {
        int mid=(s+e)>>1;
        if(ispossibleparatha(rank,n,p,mid))
        {
            ans=min(ans,mid);
            e=mid-1;
        }
        else{
            s=mid+1;
        }

    }
    return ans;


}

//@uestion
//solve the painters partiion problem
int ispossible_paint(int *arr,int k,int n,int time)
{
    int painters=1;//we find the time taken required for all the given midean time
    int time_taken=0;
    for(int i=0;i<n;i++)
    {
      time_taken+=arr[i];
        if(time_taken>time)
        {
            time_taken=arr[i];
            painters++;
        }
//this function return the minimum painters required to paint the boards in given time
    }
    return painters;

}
int solve_paintersproblem(int k,int n,int *arr,int sum)
{
    sort(arr,arr+n);
    int s=arr[n-1]; //the minimum time is maximum value beacause each painter is assign to each board
    int e=sum;//maximum value is the sum of all boards unit if one painters assign only
    int ans=INT_MAX;
    while(s<=e)
    {
        int mid=(s+e)/2;
        int painters=ispossible_paint(arr,k,n,mid);
        if(painters>k)
        {
            
            s=mid+1;
        }
        else{
            ans=min(ans,mid);
            e=mid-1;
        }
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

// int n;
// cin>>n;
// int arr[n];
// for(int i=0;i<n;i++)
// {
//     cin>>arr[i];
// }
// int ket;
// cin>>ket;
// int ans=finding_pivot(arr,n,ket);
// if(ans==-1)
// {
//     cout<<"element is not present\n";
// }
// else{
//     cout<<"element is present at "<<ans<<endl;
// }



return 0;


}
 