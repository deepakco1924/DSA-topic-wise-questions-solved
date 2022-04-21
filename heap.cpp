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


// HEAP
//it is elemeent come out with highest priorty 
//getting min/and max eleemnt in o(1) time
//what container chose for the making the prioruty_ uee
//               array    sortedarray  list   BST   heap
// 1.insert/push    o(1)      o(n)        o(n)   o(h)   log(n)
// 2.pop()          o(n)      o(1)        o(n)   o(h)   log(N)
// 3.get()          o(n)      o(1)        o(n)   o(h)    o(1)


//what is heap
//1/.heap is binary tree
//2.it is complete binar tree  tree having the all leveel willed and excep last one which can be willed from left to right
//3.it have some heap order property    it may be max .or min 


//fro making the heap we do not 
//use binary tree as node beaxuse insertion will take o(n) beaucse we have to use levelorder traversel for mainting propertu number 2
//so we use array form of binary tree
//if any node at i 
//then left child is at 2*i and right part at 2*i+1
//if any node n then its parrent at n/2


//isnertion will take
 //log(n) tiome iinserrt
 //first we will add node at the tree end and then hapify so that it come to it right possition
 class heap
 {
     vector<int>vec;
     bool minheap;
     bool compare(int a,int b)
     {
         if(minheap)//if it is mineahp
         {
             return a>b;
         }
         return a<b;
     }
     void heapify_the_array(int idx)
     {
         int last=vec.size()-1;
         int left=2*idx;
         int right=left+1;
         int minindex=idx;
         if(left<=last&&compare(vec[idx],vec[left]))
         {
             minindex=left;
         }
         if(right<=last&&compare(vec[minindex],vec[right]))
         {
             minindex=right;
         }
         if(minindex!=idx)
         {
             swap(vec[idx],vec[minindex]);
             heapify_the_array(minindex);
         }
     }
     public:
     heap(int defaultsize=10,bool type=true)//default size heap is 10 and default heap is min heap
     {
         vec.reserve(defaultsize);
         vec.push_back(-1);//block the index 0
         minheap=type;
     }
     void push(int data)
     {
         vec.push_back(data);
         int idx=vec.size()-1;
         int parent=idx/2;
         while(idx>1&&compare(vec[parent],vec[idx]))
         {
             swap(vec[parent],vec[idx]);
             idx=parent;
             parent=parent/2;
         }      
     }
     int get()
     {
         return vec[1];
     }
     void pop()
     {
         //first swap the last and top eleemnt and delete the last eleemnt and than hepiy it
         int lastindex=vec.size()-1;
         swap(vec[1],vec[lastindex]);
         vec.pop_back();
         heapify_the_array(1);
     }
     bool empty()
     {
         return vec.size()==1;
     }
 };


 //converting the array or heap into array
 //convert into mazx heap
 void convert_into_heap(vector<int>&vec)//time complizty is nlong(n)
 {
     for(int i=2;i<vec.size();i++)
     {
        int idx=i;
        int parent=i/2;
        while(idx>1&&vec[parent]<vec[idx])
        {
            swap(vec[idx],vec[parent]);
            idx=parent;
            parent=parent/2;
        }
     }
 }
 //optimiszed apprcoh to make it in o(N)
 //we do not touch leaf node and we hapfy only non leaf node
  void heapify_the_array(int idx,vector<int>&vec)
     {
         int last=vec.size()-1;
         int left=2*idx;
         int right=left+1;
         int maxindex=idx;
         if(left<=last&&vec[idx]<vec[left])
         {
            maxindex=left;
         }
         if(right<=last&&vec[right]>vec[maxindex])
         {
            maxindex=right;
         }
         if(maxindex!=idx)
         {
             swap(vec[idx],vec[maxindex]);
             heapify_the_array(maxindex,vec);
         }
     }
 void chhangetoheap(vector<int>&vec)
 {
     int n=vec.size()-1;
     for(int i=n/2;i>=1;i--)
     {
         heapify_the_array(i,vec);
     }
 }
 void helper(vector<int>&vec,int idx,int size)
 {
     int last=size-1;
     int left=idx*2;
     int right=left+1;
     int maxindex=idx;
         if(left<=last&&vec[idx]<vec[left])
         {
            maxindex=left;
         }
         if(right<=last&&vec[right]>vec[maxindex])
         {
            maxindex=right;
         }
         if(maxindex!=idx)
         {
             swap(vec[idx],vec[maxindex]);
             helper(vec,maxindex,size);
         }

 }
void heapsort(vector<int>&vec)
{
    //indexing of heap wil start from 1 
    //we first make the heap and than remove top item into last and then again follow heap
    int n=vec.size();
    chhangetoheap(vec);

    while(n>1)
    {
        swap(vec[n-1],vec[1]);
        n--;
        helper(vec,1,n);
        

    }

}
class person
{
    public:
    string name;
    int age;
    person()
    {

    }
    person(string a,int b)
    {
        name=a;
        age=b;
    }
};
class compareperson
{
    public:
    bool operator()(person a,person b)
    {
        return a.age>b.age; //this will make the minheap and other wil make < the max heap 
        //remember it
    }

};


//Quesion 
//joining the ropes
int join_rope(int *arr,int n)
{
    pqs pq;
    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
    }
    int sum=0;
    while(pq.size()>1)
    {
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        sum+=(a+b);
        pq.push(a+b);


    }
    return sum;
}
void stl_part()
{
    // priority_queue<int>pq;//bedefault it is max heap
    // priority_queue<int,vector<int>,greater<int>>sq;
    // for(int i=1;i<10;i++)
    // {
    //     sq.push(i*i);
    //     pq.push(i);
    // }
    // while(!sq.empty())
    // {
    //     cout<<sq.top()<<" "<<pq.top()<<endl;
    //     sq.pop();
    //     pq.pop();
    // }
    priority_queue<person,vector<person>,compareperson>pq;//passing person compare clss or oewn comaprtor
    for(int i=1;i<6;i++)
    {
        string a;
        int b;
        cin>>a>>b;
        person p(a,b);
        pq.push(p);
    }
    while(!pq.empty())
    {
        cout<<pq.top().name<<","<<pq.top().age<<endl;
        pq.pop();
    }

}
void meadian_ruuningstream()
{
    pqb left;
    pqs right;
    int x;
    cin>>x;
    double median=(double)x;
    left.push(x);
    cout<<median<<", ";
    cin>>x;
    while(x!=-1)
    {
        if(left.size()>right.size())
        {
            if(x<median)
            {
                right.push(left.top());
                left.pop();
                left.push(x);
            }
            else{
                right.push(x);
            }
            median=(left.top()+right.top())/2.0;
        }
        else if(left.size()==right.size())
        {
            if(x<median)
            {
                left.push(x);
                median=(double)left.top();
            }
            else{
                right.push(x);
                median=(double)right.top();
            }
        }
        else{
            if(x>median)
            {
                left.push(right.top());
                right.pop();
                right.push(x);
            }
            else{
                left.push(x);
            }
            median=(left.top()+right.top())/2.0;
        }
        cout<<median<<",";
        cin>>x;

    }
}
//mergeKsordetd array

void mergesorted_array()
{
    vector<vector<int>>vec{{2,6,12,15},{1,3,14,19},{3,5,8,10}};
    priority_queue<node,vector<node>,greater<node>>pq;

    for(int i=0;i<vec.size();i++)
    {
        pq.push({vec[i][0],{i,0}});
    }
    vector<int>arr;
    while(!pq.empty())
    {
        pair<int,pair<int,int>>p=pq.top();
        pq.pop();
        arr.push_back(p.first);
        int x=p.second.first;
        int y=p.second.second;
        if(y<vec[0].size()-1)
        {
            y++;
            pq.push({vec[x][y],{x,y}});
        }

    }
    for(auto c:arr)
    {
        cout<<c<<"->";
    }
    return ;
}
//findin the kth smallest element in row wise and colomns wise sorted matrix
void find_the_ele()
{
    vector<vector<int>>vec{{10, 15, 30, 40}, 
                    {15, 25, 35, 45}, 
                    {25, 29, 37, 48}, 
                    {32, 33, 39, 50} };
    priority_queue<node,vector<node>,greater<node>>pq;
    for(int i=0;i<vec[0].size();i++)
    {
        pq.push({vec[0][i],{0,i}});
    }
    int k;
    cin>>k;
    int ans;
    for(int i=0;i<k;i++)
    {
        node a=pq.top();
        pq.pop();
        ans=a.first;
        int x=a.second.first;
        int y=a.second.second;
        int next;
        if(x+1<vec.size())
        {
            next=vec[x+1][y];

        }
        else{
            next=INT_MAX;
        }
        pq.push({next,{x+1,y}});

    }
    cout<<ans<<endl;
    return ;

}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
find_the_ele();

return 0;


}