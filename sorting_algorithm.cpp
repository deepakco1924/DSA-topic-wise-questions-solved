#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define endl "\n"
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define int long long
#define ff first
#define ss second
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define sp(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x)   int x; cin >> x; while (x--)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//MERGE SORT ALOGRTIHM
//it is divide and conqure 
//it is the fastest alogtihm
//o(nlong(n)) approch
void merge(int *arr,int s,int e)
{
    int mid=(s+e)>>1;
    int temp[100];
    int i=s;
    int j=mid+1;
    int k=s;
    while(i<=mid&&j<=e)
    {
        if(arr[i]<arr[j])
        {
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while (i<=mid)
    {
        temp[k++]=arr[i++];
        /* code */
    }
    while (j<=e)
    {
        temp[k++]=arr[j++];
        /* code */
    }
    for(int i=s;i<=e;i++)
    {
        arr[i]=temp[i];
    }
    
    
}
void solve_merge(int arr[],int s,int e)
{
    if(s>=e)
    {
        //if we have one or no element we not need to sort the array
        return ;

    }
    int mid=(s+e)>>1;
    solve_merge(arr,s,mid);
    solve_merge(arr,mid+1,e);
    merge(arr,s,e);
}
void solve_inversion_count_optimization(int *arr ,int n)
{
    int count=0;
    pbds<int>s;
    for(int i=0;i<n;i++)
    {
        count+=s.size()-s.order_of_key(arr[i]);
        s.insert(arr[i]);

    }
    cout<<count<<endl;
    return ;
}

//inversion count solve using best approcj using the merge sort
int  merge_forinversion(int *arr ,int s,int e)
{
    int mid=(s+e)/2;
    int temp[1000];
    int cnt=0;
    int i=s;
    int k=s;
    int j=mid+1;
    while(i<=mid&&j<=e)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            cnt+=mid-i+1;
        }
    }
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=e)
    {
        temp[k++]=arr[j++];
    }
    for(int i=s;i<=e;i++)
    {
        arr[i]=temp[i];
    }
    return cnt;



    
}
int  solve_inversion(int *arr,int s,int e)
{
    if(s>=e)
    {
        return 0;
    }
    int mid=(s+e)/2;
    //sorting will not change the cross inverisopn
   int x= solve_inversion(arr,s,mid);
   int y= solve_inversion(arr,mid+1,e);
   int z= merge_forinversion(arr,s,e);
   return (x+y+z);
}


//Quikstart algorihtm to solve the sorting
//worst case complixitu of algortihm is o(n2);
//avergae case is o(nlogn);


//algorithm-----
//i.choose the pivot
//some element are less than pivot and some greater then pivot
int partition_of_array(int *arr,int s,int e)
{
    int i=s-1;
    int j=s;
    int pivot=arr[e];
    for(int j=s;j<e;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}
int partition(int *arr,int s,int e)
{
    srand(time(NULL));
    int r=s+rand()%(e-s);
    swap(arr[r],arr[e]);
    return partition_of_array(arr,s,e);
}
void quiksort(int *arr,int s,int e)
{
    if(s>=e)
    {
        return ;
    }
    int pivot=partition(arr,s,e);
    quiksort(arr,s,pivot-1);
    quiksort(arr,pivot+1,e);
    return ;
}

//counting sort alogritm 
//if you have number in range 
//then you solve the quiksort
// the time compleixti (o(n+range))
void counting_sort(int *arr,int n)
{
    //assuming elements are greater than zero
    int range=*max_element(arr,arr+n);
    int *freq=new int[range+1]{0};
    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }
    //put element in to arrayback;
    int j=0;
    for(int i=0;i<=range;i++)
    {
        while(freq[i]!=0)
        {
            arr[j]=i;
            j++;
            freq[i]--;
        }

    }
    delete [] freq;
    return ;
}


//bucket sort to solve the 
class student
{
    public:
    int marks;
    string name;

};
void bucket_sort(student s[],int n)
{
    //time complizty is o(n)
    vector<student>vec[101];
    for(int i=0;i<n;i++)
    {
        int mark=s[i].marks;
        vec[i].push_back(s[i]);
    }
    for(int i=100;i>=0;i--)
    {
        for(auto it=vec[i].begin();it!=vec[i].end();it++)
        {
            cout<<it->name<<" "<<it->marks<<endl;
        }
    }

}

//algrothim to sort o,1,2 int o(n) time
//dnf sort
void DNFsort(int *arr,int n)
{
    int mid=0;
    int low=0;
    int high=n-1;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }

    }
}
//wave print of the array
//important quesion 
//one approch sort the array and do parwise swaping alternate or swap last and first element last-- and first++
//
void wave_sort(int *arr,int n)
{
    for(int i=0;i<n;i+=2)
    {
        if(i>0&&arr[i]<arr[i-1])
        {
            swap(arr[i],arr[i-1]);
        }
        if(i+1<n&&arr[i]<arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }

    }
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


    return 0;
}