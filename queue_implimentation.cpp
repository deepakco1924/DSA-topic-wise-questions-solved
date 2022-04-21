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
#define rap(i,a,b)      for(int i=a;i<=b;i++)
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

//in this we lwarn aboou the quueu
//it is linser data sturcuture
//it is fifo order
// appliation
// it is whatsapp chats first massage will send first and last will send last
//operating system to make schduling programs
// it is used to impleiment in graph  and tree

//IIMPLIMENTAION USING THE FRONT AND REAR OR USING THE CIRCULAR 
class Queue
{
    int *arr;
    int fs,re,cs,ms;
    public:
    Queue(int d=5)
    {
        arr=new int[d];
        cs=0;
        fs=0;
        ms=d;
        re=ms-1;

    }
    bool full()
    {
        return cs==ms;
    }
    bool empty()
    {
        return cs==0;
    }
    int size()
    {
        return cs;
    }
    void push(int data)
    {
        if(!full())
        {
            re=(re+1)%ms;
            arr[re]=data;
            cs++;

        }
    }
    void pop()
    {
        if(!empty())
        {
            fs=(fs+1)%ms;
            cs--;
        }
    }
    int front()
    {
        if(!empty())
        {
            return arr[fs];
        }
        return -1;
    }
    ~Queue()
    {
        if(arr!=NULL)
        {
            delete [] arr;
            arr=NULL;
        }


    }

};


//imlimneting queeu using the 

class node
{
    public:
    int data;
    node *next;   ///the whole class is one node
                    //in which one data and pointer to the next node
    node(int  d)
    {
        this->data=d;
        this->next=NULL;
    }


};
void insert_at_tail(node* &head,node* &tail,int d)
{
    if(head==NULL)
    {
        head=new node(d);
        tail=head;
        return ;
    }
    node* n=new node(d);
    tail->next=n;
    tail=tail->next;
    return ;
}
void delete_from_haid(node* &head,node* &tail)
{
    if(head==NULL||head->next==NULL)
    {
        node* temp=head;
        delete temp;
        head=NULL;
        tail=NULL;
        return ;
    }
    node* temp=head;
    head=head->next;
    delete temp;
    return ;
}
class queelsist
{
    node* head=NULL;
    node* tail=NULL;
    int cs=0;
    public:
    queelsist()
    {
        cout<<"deepak pal\n";
        return ;
    }
    int size()
    {
        return cs;
    }
    int empty()
    {
        return cs==0;

    }
    void push(int d)
    {
        insert_at_tail(head,tail,d);
        cs++;
        return ;
    }
    void pop()
    {
        if(!empty())
        {
            delete_from_haid(head,tail);
            cs--;
        }
        return ;
    }
    int front()
    {
        if(!empty())
        {
            return head->data;

        }
        return -1;
    }

};
//approcj 
// we use the queue and undordermap to
//to solve this question
// each time ans in at front of the queue
void solve_first_non_preating_character()
{
    queue<char>q;
    unordered_map<char,int>mp;
    char ch;
    while(cin>>ch)
    {
        q.push(ch);
        mp[ch]++;
        while(!q.empty()&&mp[q.front()]>1)
        {
            q.pop();
        }
        if(!q.empty())
        {
            cout<<q.front()<<" ";
        }
        else{
            cout<<"-1"<<" ";
        }
    }
    return ;

}

//stack using two quue
class STack
{
    queue<int>a;//always take this element
    queue<int>b;//always empty
    public:
    bool empty()
    {
        return a.empty();

    }
    int size()
    {
        return a.size();

    }
    int top()
    {
        if(a.empty())
        {
            return -1;
        }
        while(a.size()>1)
        {
            b.push(a.front());
            a.pop();
        }
        int x=a.front();
        b.push(a.front());
        a.pop();
        swap(a,b);
        return x;

    }
    void push(int d)
    {
        a.push(d);

    }
    void pop()
    {
          if(!a.empty())
        {
        
        while(a.size()>1)
        {
            b.push(a.front());
            a.pop();
        }
        a.pop();
        swap(a,b);
        }

    }
    

};


//learn  about DEQUEUE
//it is douubly eneded queue
//it is add element front and ended in o(1)

//question find the greastest element in the k window
void solve_max_element(int *arr,int n,int k)
{
    k=k%n;
    deque<int>q;
    int i=0;
    for( i=0;i<k;i++)
    {
         while (!q.empty()&&arr[i]>arr[q.back()])
        {
            q.pop_back();
            
        } 
        q.push_back(i);
    }
    for(;i<n;i++)
    {
        cout<<arr[q.front()]<<" ";
        //remove which are are not part of new window
        while(!q.empty()&&q.front()<=i-k)
        {
            q.pop_front();

        }
        //rempve eleent which useless and part of window
        while(!q.empty()&&arr[i]>=arr[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);


        //push element in queue
    }
        cout<<arr[q.front()];
        
}
//quesiton longest substringg with have non repeating character
//brute force appraocj
//make all possible substring i and j and o(n) time to fing have substring non repating charachter complizty is o(n^3)
//efficent approch
int solve_the_longest(char *arr)
{
    int n=strlen(arr);
    int currenlen=1;
    int maxlen=1;
    int visited[256]={-1};
    visited[arr[0]]=0;
    for(int i=1;i<n;i++)
    {
        int lastvisit=visited[arr[i]];
        //expansion
        if(lastvisit==-1||lastvisit<=i-currenlen)
        {
            currenlen++;
        }
        //expansion as well as contraction casr
        else{
            maxlen=max(maxlen,currenlen);
            currenlen=i-lastvisit;
        }
        visited[arr[i]]=i;
    }
    maxlen=max(currenlen,maxlen);
    return maxlen;
}
void findnge(int *arr,int n)
{
    int nge[n];
    stack<int>s;
    //s.push(0);
    for(int i=0;i<n;i++)
    {
        while(!s.empty()&&arr[i]>arr[s.top()])
        {
            int x=s.top();
            nge[x]=arr[i];
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())
    {
        nge[s.top()]=-1;
        s.pop();
    }
    for(int i=0;i<n;i++)
    {
        cout<<nge[i]<<" ";
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
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++) cin>>arr[i];
findnge(arr,n);

return 0;


}