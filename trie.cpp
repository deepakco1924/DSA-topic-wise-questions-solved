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





//trie data structure
//prefix tree
//appluication
//you can make the contact list
//or suggestion in browser
//if few contact then go for the hashmap //beacuse collsion happen
//else huge data go for the trie

class node
{
    public:
    char data;
    unordered_map<char,node*>children;
    bool terminal;
    node(char d)
    {
        data=d;
        terminal=false;
    }

};



class Trie
{
    public:
    node* root;
    int cnt;
    Trie()
    {
        root=new node('\0');
        cnt=0;
    }
    void insert(char *w)
    {
        node* temp=root;
        for(int i=0;w[i]!='\0';i++)
        {
            char ch=w[i];
            if(temp->children.count(ch))
            {
                temp=temp->children[ch];
            }
            else{
                node* n=new node(ch);
                temp->children[ch]=n;
                temp=n;
            }
        }

        temp->terminal=true;
        cnt++;
    }
    int size()
    {
        return cnt;
    }
    bool find(char *w)
    {
        node* temp=root;
        for(int i=0;w[i]!='\0';i++)
        {
            char ch=w[i];
            if(temp->children.count(ch)==0)
            {
                return false;
            }
            else{
                temp=temp->children[ch];
            }
            
        }
        return temp->terminal;
    }
};
class snode
{
    public:
    char data;
    int freq;
    bool terminal;
    unordered_map<char,snode*>children;
    snode(char d)
    {
        data=d;
        terminal=false;
        freq=1;
    }

};
class special_trie//
{
    public:
    snode* root;
    int cnt;
    special_trie()
    {
        root=new snode('\0');
        cnt=0;
    }
    void insert_word(char *w)
    {
        snode* temp=root;
        for(int i=0;w[i]!='\0';i++)
        {
            char ch=w[i];
            if(temp->children.count(ch))
            {
                temp=temp->children[ch];
                temp->freq++;
            }
            else{
                snode* n=new snode(ch);
                temp->children[ch]=n;
                temp=n;
            }
        }
        temp->terminal=true;
        cnt++;
    }
    void print_prefix(char words[][10],int n)
    {
        for(int i=0;i<n;i++)
        {
            insert_word(words[i]);
        }
            for(int i=0;i<n;i++)
           {
                // char output[10];
                // memset(output,'\0',sizeof(output));
                snode* temp=root;
                bool flag=false;
                vector<char>vec;
                vec.clear();
                for(int j=0;words[i][j]!='\0';j++)
                {
                    char ch=words[i][j];
                    vec.push_back(ch);
                    if(temp->children[ch]->freq>1)
                    {
                        temp=temp->children[ch];

                    }
                    else{
                       
                        flag=true;
                        break;
                    }
                }
                if(flag==true)
                {
                    for(auto c:vec)
                    {
                        cout<<c;
                    }
                    cout<<endl;
                }
                else{
                    cout<<"-1"<<endl;
                }
           }
 
    }

};
void print_unique_prefix(char words[][10],int n)
{
    special_trie t;


}
class bnode
{
    public:
    vector<string>vec;
    bnode* left;
    bnode* rigth;


};
class tr
{
    public:

    bnode* root;
    tr()
    {
        root=new bnode();

    }
    void insert(int n)
    {
        bnode* temp=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i)&1;
            if(bit==0)
            {
                if(temp->left==NULL)
                {
                    temp->left=new bnode();

                }
                temp=temp->left;

            }
            else{
                if(temp->rigth==NULL)
                {
                    temp->rigth=new bnode();
                }
                temp=temp->rigth;
            }
        }
    }
    int xor_till_now(int n)
    {
        bnode* temp=root;
        int currentans=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i)&1;
            if(bit==0)
            {
                if(temp->rigth!=NULL)
                {
                    temp=temp->rigth;
                    currentans+=(1<<i);

                }
                else{
                    temp=temp->left;
                }

            }
            else{
                if(temp->left!=NULL)
                {
                    temp=temp->left;
                    currentans+=(1<<i);
                }
                else{
                    temp=temp->rigth;
                }
            }
        }
        return currentans;
    }


};
int maximum_xor_pair(int *arr,int n)
{
    tr t;
    int ans=0;
    for (size_t i = 0; i < n; i++)
    {
        t.insert(arr[i]);
        int current=t.xor_till_now(arr[i]);
        cout<<current<<" ";
        ans=max(ans,current);

        /* code */
    }
    cout<<endl;
    return ans;


}


    //another variety of quesiton that 
    //fidning the mazimum zor progrvlem

    //1.approch
    // o(n^3)
    //make all pair subaray from i and j and make xor of from i to j get maximum answer
    //2.approch
    // o(n^2)
    //reduce time complizxty of approch by using commulative xor array
    //3.apprich is trie
    //first make the co,,ualtve xor find the maximim pair
    //time complizty is oN
int mazimum_xor_subarray(int *arr,int n)
{
    int cum[n];
    cum[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        cum[i]=cum[i-1]^arr[i];
    }
    int ans=maximum_xor_pair(cum,n);
    return ans;
}

//code to generate all string which have prefix
//given


// class node
// {
//     public:
//     char data;
//     vector<string>vec;
//     unordered_map<char,node*>children;
//     int freq;
//     bool terminal;
//     node(char d)
//     {
//         data=d;
//         freq=1;
//         vec.clear();
//     }
    
// };
// class Trie
// {
//     public:
//     node* root;
//     Trie()
//     {
//         root=new node('\0');
//     }
//     void insert(string w)
//     {
//         node* temp=root;
//         for(int i=0;i<w.length();i++)
//         {
//             char ch=w[i];
//             if(temp->children.count(ch))
//             {
//                 temp=temp->children[ch];
//                 temp->freq++;
//                 temp->vec.push_back(w);
//             }
//             else{
//                 node* n=new node(ch);
//                 temp->children[ch]=n;
//                 temp=n;
//                 temp->vec.push_back(w);
//             }
//         }
//     }
//     void prefix(string w)
//     {
    
//         node* temp=root;
//         for(int i=0;i<w.length();i++)
//         {
//             char ch=w[i];
//             temp=temp->children[ch];
//         }
//         for(auto c:temp->vec)
//         {
//             cout<<c<<endl;
//         }
//     }
// };
int32_t main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    cout<<"namespace "<<endl;
    int s=34;
    cout<<s<<endl;

return 0;


}