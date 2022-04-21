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
#define rep(a,b)          for(int i=a;i<=b;i++)
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

//stack in this 
//learn about the stack
//STACK
// Stack is a linear data structure which follows a particular order in which the operations are performed. 
// The order may be LIFO(Last In First Out) or FILO(First In Last Out).
//------------------------------------------------------------------------
//IMPLIMENTAIon
//impimentation of stack
//1.we can imliment using thea  aray and vector
//2.we can use linked list 
//if it sinngle llinked list thain insert take o(1) but we use 
//two pointer head and tail but pop function take o(n) time which is inefficint
//or what can we do we use doubli linked list it have pointer to prev
//but most efficent method is we insert element at the head only
//and pop from  head as well this take pop and push both o(1) time
template<typename T>
class stack_container
{
    vector<T>vec;
    public:
    void push(T data)
    {
        vec.push_back(data);
        return ;
    }
    bool empty()
    {
        return vec.size()==0;
    }
    void  pop()
    {
        if(!vec.empty())
        {
            vec.pop_back();
        }


    }
    T top()
    {
        return vec[vec.size()-1];
    }
};
void reverstack(stack<int>&s)
{
    int n=s.size();
    stack<int>temp;
    for(int i=1;i<n;i++)
    {
        int x=s.top();
        s.pop();
        for(int j=1;j<=n-i;j++)
        {
            temp.push(s.top());
            s.pop();
        }
        s.push(x);
        while(!temp.empty())
        {
            s.push(temp.top());
            temp.pop();
        }

    }
    return ;

}
void insert_at_bottom(stack<int>&s,int x)
{
    if(s.empty())
    {
        s.push(x);
        return ;
    }
    int y=s.top();
    s.pop();
    insert_at_bottom(s,x);
    s.push(y);
    return ;
}
void recursion_reverse(stack<int>&s)
{
    if(s.empty())
    {
        return ;
    }
    int x=s.top();
    s.pop();
    recursion_reverse(s);
    insert_at_bottom(s,x);
    return ;

}
bool check_balanced_paranthiss(char input[])
{
    stack<char>s;
    for(int i=0;input[i]!='\0';i++)
    {
        char ch=input[i];
        if(ch=='(')
        {
            s.push(ch);
            continue ;
        }
        else if(ch==')')
        {
            if(s.empty())
            {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();

}
void minimum_span_problem(int *arr,int n,int *span)
{
    stack<int>s;
    //span of 1frist number is 1
    span[0]=1;
    for(int i=1;i<n;i++)
    {
        int currentprice=arr[i];
        while(!s.empty()&&currentprice>=arr[s.top()])
        {
            s.pop();
        }
        if(!s.empty())
        {
            span[i]=i-s.top();

        }
        else{
            span[i]=i+1;
        }
        s.push(i);
    }

}
//larget histogram area using the stack
//algorthim
//we add the bar in stack if current bar is greater than stack top
//if it is leass than than wwe pop till stack top is leass than or equal to cuurent bar
// in both the cases we find the area assumaing current bar have the minimum height
int histogram_area(int *arr,int n)
{
    int i=0;
    stack<int>s;
    int area=0;
    while(i<n)
    {
        int currentans=0;
        if(s.empty() || arr[i]>arr[s.top()] )
        {
            s.push(i);
            i++;
            continue;
        }
        int x=s.top();
        s.pop();
        if(s.empty())
        {
            currentans=arr[x]*i;
        }
        else
        {
            currentans=arr[x]*(i-s.top()-1);
        }
        area=max(area,currentans);
        
    }
    while(!s.empty())
    {
        int x=s.top();
        s.pop();
        if(!s.empty())
        {
        area=max(area,arr[x]*(i-s.top()-1));
        }
        else{
            area=max(area,arr[x]*i);
        }

    }
    return area;
}
//making the special stack which give me min and max in o(1) time 
class minmaxdtsck
{
    vector<int>Stack_org;
    vector<int>minstack;
    vector<int>maxstack;
    public:
    int top()
    {
        return Stack_org[Stack_org.size()-1];
    }
    void push(int d)
    {
        int currentmin=d;
        int currentmax=d;
        if(minstack.size())
        {
            currentmin=min(d,minstack[minstack.size()-1]);
            currentmax=max(d,maxstack[maxstack.size()-1]);
        }
        minstack.push_back(currentmin);
        maxstack.push_back(currentmax);
        Stack_org.push_back(d);

    }
    int getmin()
    {
        return minstack[minstack.size()-1];
    }
    int getmax()
    {
        return minstack[minstack.size()-1];
    }
    void pop()
    {
        Stack_org.pop_back();
        minstack.pop_back();
        maxstack.pop_back();
    }
    bool empty()
    {
        return Stack_org.size()==0;
    }
};


//minstack createign using the o(1) space and time compleixt is also o(1)
class minstack
{
    stack<int>s;
    int minelement=-1;
    public:
    int top()
    {
        if(s.top()>=minelement)
        {
            return s.top();
        }
        return 2*minelement-s.top();
    }
    void push(int d)
    {
        if(s.empty())
        {
            s.push(d);
            minelement=d;
        }
        else if(d>=minelement)
        {
            s.push(d);
        }
        else{
            s.push(2*d-minelement);
            minelement=d;
        }
        
    }
    void pop()
    {
        if(s.top()>=minelement)
        {
            s.pop();
        }
        else{

            minelement=2*minelement-s.top();
            s.pop();
        }
        return ;

    }
    bool empty()
    {
        return s.empty();

    }
    int getmin()
    {
        if(s.empty())
        {
            minelement=-1;
            return -1;
        }
        return minelement;

    }
    int size_of_stack()
    {
        return s.size();

    }

};
//of matrix  to solve the problem
// 0 and 1 use for this can please
void getpermutiation(int i,int j,int matrix[][10],int n)
{
    if(i==n)
    {
        //prinet the matrix
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        return ;
    }
    if(j==n)
    {
         return getpermutiation(i+1,0,matrix,n);
    }
    matrix[i][j]=0;
    getpermutiation(i,j+1,matrix,n);
    matrix[i][j]=1;
    getpermutiation(i,j+1,matrix,n);
    return ;

}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
// minstack s;
// s.push(18);
// s.push(19);
// s.push(29);
// s.push(15);
// s.push(16);
// cout<<s.top()<<endl;
// cout<<s.getmin()<<endl;
// s.pop();
// cout<<s.top()<<endl<<s.getmin()<<endl;
// s.pop();
// cout<<s.top()<<endl<<s.getmin()<<endl;



return 0;


}