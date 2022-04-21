

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

//int this we learn about the vectors it 
//it is dyanmic array it grow and shrink in size
void vectors_method()
{
    //first take the intializaiotn
    vector<int>b{2,1,2,32,323};//it create the vector b and intialize the vector with numbers give 
    vector<int>s(14,10);// its crate the vector s and icnitlize with 14 times 10
    vector<int>vec(b.begin(),b.end());// it simple copye the content of vector 

    //iteratrate over the vector
    for(int i=0;i<vec.size();i++)
    {
        //operatiom
    }
    for(auto  it=vec.begin();it!=vec.end();it++)
    {
        //operatiom
    }
    for(auto cp:vec)
    {
        //operation
    }


    //during the expanding of vector
    //basicalyy at memory level when the vector is full
    // then it create another vector of size doubel and copy the content of older one
    //cpying the element is expensive operation
    //TO Avoid the doubling we use vector.reserve(cells nedded)
    vec.reserve(100);// it reserve the vector of cell 100 so doubling not heappend till 100

    vec.capacity();//it return the size of underlinging array
    vec.push_back(5);//add number at the end
    vec.emplace_back(42);// it also add numebr at back but it is faster than pushback
    vec.clear();// it clear the  vector it do not delete memory
    vec.pop_back();//remove element from the end
    vec.front();//give front element
    vec.back();//give the last element
    vec.insert(vec.begin()+3,100);//it add number 100 at index
    vec.insert(vec.begin()+5,4,100);// it add start at index from 5 and 4 times 100
    vec.erase(vec.begin()+3);// it eraase the element at index 3
    vec.erase(vec.begin()+3,vec.begin()+7);//it remove the element from index 3 to 6 not 7

}
bool compare(pair<string,pair<int,int>>a,pair<string,pair<int,int>>b)
{
    int dis1=a.ss.ff*a.ss.ff+a.ss.ss*a.ss.ss;
    int dis2=b.ss.ff*b.ss.ff+b.ss.ss*b.ss.ss;
    return dis1<dis2;

}
void quesion_based_onsort()
{
    int n;
    cin>>n;
    vector<pair<string,pair<int,int>>>vec;
    for(int i=0;i<n;i++)
    {
        string s;
        int x,y;
        cin>>s;
        cin>>x>>y;
        vec.pb({s,{x,y}});
    }
    sort(vec.begin(),vec.end(),compare);
    for(auto xp:vec)
    {
        int dis=xp.second.first*xp.second.first+xp.second.second*xp.second.second;
        double distance=sqrt(dis);
        cout<<xp.first<<" " <<sp(distance,4)<<endl;
    }
}
//lets deigne the container for the vector
class Vector
{
    //have some data memebers and funcitons
    //we have to maintain two varaible
    //current-size and maximum size if current size is greater than maximum size 
    //than we have greate new array and copy older content of array delete old one
    int *arr;
    int cs;
    int max_size;
    public:
    Vector(int default_size=4)
    {
        max_size=default_size;
        cs=0;
        arr=new int[default_size];

    }
    void Push_back(int num)
    {
        //if my current size id equall to maxsize we perform doubling
        if(cs==max_size)
        {
            int *oldarray=arr;
            arr=new int[2*max_size];
            max_size=2*max_size;
            for(int i=0;i<cs;i++)
            {
                arr[i]=oldarray[i];
            }
            //now we have to delete older array
            delete [] oldarray;
        }
        arr[cs]=num;
        cs++;

    }
    bool empty()
    {
        return cs==0;
    }
    void Pop_back()
    {
        if(cs>0)
        {
            cs--;
        }
    }
    void print_Vector()
    {
        if(!empty())
        {
            for(int i=0;i<cs;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

    }
    int get(int i)
    {
        return arr[i];
    }
    int size()
    {
        return cs;
    }
    //now we have to do operator overlodding
    int& operator[](int i)
    {
        return arr[i];
    }

};
    ostream& operator << (ostream &os,Vector v)
    {
        v.print_Vector();
        return os;
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
    Vector v;
    for(int i=0;i<6;i++)
    {
        v.Push_back(i*i);
    }
    v.print_Vector();
    v.Pop_back();
    cout<<v.get(3)<<endl;
    v.print_Vector();
    return 0;
}
