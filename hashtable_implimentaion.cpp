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
#define zerobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define sp(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//hastable
//it take insertaion ,searching and deletion in average o(1) time
//it is based on key value pair (key is mapped with value)

//for making the hastabl
//key compaents
// 1.hashfuntion
// 2.hastable
// 3.collision handle scheme

//hastable
//it is the array of fixed size
//each bucket have some key value mapping
//hasfuntion is requred to find the buket of key in which i present

//collision when diiferen key have same hashfuntion ouptput integer

//good hashfuntion reduced the collsion
//it should be fast to convert key into integer
//is uniformly distrubute over the hastable
//better to take hastable size of prime

//hash[key]=key%tablesize

//how to handle to string
//the schime to make key is add all the asci valye of string and make %tablesize
//but this fail if string have anagram beacuse anagram have same characters
///we use 27 first 3 character base key but it not handle prefix string
//so we use
//base any like prime 37
//and we use for base 37 for all characters and each time tablesize

//collsion hanle scheme
//1.seperate chaining or open hashing (in stl)
//2.close hsing open addresing
//liner or ouadratic
//3. double hashing

//separate chaining
//it made by the liked list
//each bukket of hastable connect to linked list

template <typename T>
class node
{
public:
    string key;
    T value;
    node<T> *next;
    node(T v, string s)
    {
        key = s;
        value = v;
        next = NULL;
    }
    ~node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};
template <typename T>
class hastable
{
    node<T> **table;
    int curentsize;
    int tablesize;
    int hasfuntion(string s)
    {
        int key = 0;
        int p = 1;
        for (int i = 0; s[i] != '\0'; i++)
        {
            key += (p * s[i]) % tablesize;
            p = (p * 37) % tablesize;
            key = (key) % tablesize;
        }
        return key;
    }

public:
    hastable(int defaultsize = 19)
    {
        tablesize = defaultsize;
        table = new node<T> *[defaultsize];
        curentsize = 0;
        for (int i = 0; i < tablesize; i++)
        {
            table[i] = NULL;
        }
    }
    void rehashing()
    {
        node<T> **oldtable = table;
        int oldsize = tablesize;
        tablesize = 2 * tablesize;
        table = new node<T> *[tablesize];
        for (int i = 0; i < tablesize; i++)
        {
            table[i] = NULL;
        }
        //shift elements
        curentsize = 0;
        for (int i = 0; i < oldsize; i++)
        {
            node<T> *temp = oldtable[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->value);
                temp = temp->next;
                curentsize++;
            }
            if (oldtable[i] != NULL)
            {
                delete oldtable[i];
            }
        }
        delete[] oldtable;
    }
    int size()
    {
        return curentsize;
    }
    void insert(string s, T val)
    {
        int key = hasfuntion(s);
        node<T> *n = new node<T>(val, s);
        n->next = table[key];
        table[key] = n;
        curentsize++;
        //if lenght of linked list increses then we have to use rehasing we have to double the
        //size of table or rehashing
        //then we have to make new table of size 2*x and shift the node into this
        //delete old one

        float loadfactor = (float)curentsize * 1.0 / tablesize;
        if (loadfactor > 0.95)
        {
            rehashing();
        }
    }
    T *search(string key)
    {
        int idx = hasfuntion(key);
        node<T> *temp = table[idx];
        while (temp != NULL)
        {
            if (key == temp->key)
            {
                return &temp->value;
            }
            temp = temp->next;
        }
        return NULL;
    }
    void erase(string key)
    {
        int idx = hasfuntion(key);
        node<T> *temp = table[idx];
        //their are three cases
        //node on head
        //middle pr tail
        if (temp != NULL && temp->key == key)
        {
            //it is head
            table[idx] = temp->next;
            temp->next = NULL;
            delete temp;
            return;
        }
        //it means it is on middle or at tail;
        node<T> *prev = NULL;
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                prev->next = temp->next;
                temp->next = NULL;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        return;
    }

    void print_table()
    {
        for (int i = 0; i < tablesize; i++)
        {
            node<T> *temp = table[i];
            cout << i << ":: ";
            while (temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->value << ")"
                     << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    T &operator[](string key)
    {
        T *f = search(key);
        if (f == NULL)
        {
            T gorabage;
            insert(key, gorabage);
            f = search(key);
        }
        return *f;
    }
};
class student
{
public:
    string firstname;
    string lastname;
    int rn;
    student(int a, string f, string l)
    {
        firstname = f;
        lastname = l;
        rn = a;
    }
    bool operator==(const student &a) const
    {
        return this->rn == a.rn;
    }
};
class hasfn
{
public: //size_t it is unig=sned int used for size in bytes
    size_t operator()(const student &s) const
    {
        return s.firstname.length() + s.lastname.length();
    }
};
void stl_part()
{
    //map is made of self balancing tree
    //it may be red black
    //sorted accoring to thier key
    // map<string,int>mp;
    // mp["rahul"]=10;
    // mp["pardjan"]=204;
    // mp["kaulurdjan"]=243240;
    // mp["arfean"]=24230;
    // mp["dedjan"]=24430;
    // mp["parerdjan"]=230;
    // for(auto cp:mp)
    // {
    //     cout<<cp.first<<" "<<cp.second<<endl;
    // }
    // //it is unique keys

    // //multimap;
    // multimap<string,int>mp;
    // // mp["rahul"]=343;
    // // mp["degrahul"]=3643; you cannot like this
    // // mp["rahul"]=233;
    // // mp["mahal"]=35343;
    // // mp["aruna"]=3143;
    // // mp["aruna"]=33443;
    // // mp["rahul"]=346233;
    // mp.insert({"rahul",34});
    // mp.insert({"rahul",434});
    // mp.insert({"ahul",36434});
    // mp.insert({"ahul",346});
    // mp.insert({"depeahul",334});
    // mp.insert({"majahul",3478});
    // mp.insert({"juul",354});
    // mp.insert({"zhul",348});
    // auto ans=mp.lower_bound("rahul");
    // for(auto cp:mp)
    // {
    //     cout<<cp.first<<" "<<cp.second<<endl;
    // }

    // //unorder_map
    // //it is best if you don not want ordering in the key
    // //so best inerstion/deleetion/searching take o(1) time
    // //but avereg case o(1) but worst case take o(n) time if load factor increase by 1
    // unordered_map<string,int>p;
    // cout<<endl;
    // p["ahuj"]=342;
    // p["aeuj"]=34342;
    // p["afehuj"]=3242;
    // p["fhuj"]=3342;
    // p["agrhuj"]=35242;
    // p["hgrhuj"]=3452;
    // p["fhuj"]=34562;
    // p["hhuj"]=3242;
    // for(auto  cp:p)
    // {
    //     cout<<cp.first<<" "<<cp.second<<endl;
    // }

    //fro used define object you have to make custom hasfuction to solve the prgorbale
    //define your own hasfunion
    //operatpr overllading == in object;
    unordered_map<student, int, hasfn> mp;
    student s1(25, "parteen", "narang");
    student s2(24, "deepak", "pal");
    student s3(6, "aman", "kumar");
    student s4(41, "kanishaka", "salaria");
    student s5(42, "luvprett", "singh");
    student s6(43, "sarik", "khan");
    student s7(30, "harshit", "atri");
    mp[s1] = 20;
    mp[s2] = 432;
    mp[s3] = 53;
    mp[s4] = 432;
    mp[s5] = 42;
    mp[s6] = 41;
    mp[s7] = 32;
    for (auto xp : mp)
    {
        student s = xp.first;
        int mark = xp.second;
        cout << s.firstname << " " << s.lastname << " " << s.rn << " " << mark << endl;
    }
    cout << endl
         << endl
         << mp[s4] << endl;
}

//exapme of hashucntion
//phinebook
void phonebook()
{
    //makeing phoebook
    //like rajjev 342,3423,43,23,342,34234,3423,43
    //deepak 234324'.342434342.434324234.234324.3423
    unordered_map<string, vector<string>> phone;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        int count;
        cin >> name >> count;
        for (int j = 0; j < count; j++)
        {
            string num;
            cin >> num;
            phone[name].push_back(num);
        }
    }
    for (auto xp : phone)
    {
        cout << xp.first << " ";
        for (auto x : xp.second)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
//expample vertical order
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node *build_tree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    Node *root = new Node(d);
    root->left = build_tree();
    root->right = build_tree();
    return root;
}
void traversel(Node *root, int k, map<int, vector<int>> &hp)
{
    if (root == NULL)
    {
        return;
    }
    hp[k].push_back(root->data);
    traversel(root->left, k - 1, hp);
    traversel(root->right, k + 1, hp);
    return;
}
void vertical_order_print(Node *root)
{
    map<int, vector<int>> hp;
    traversel(root, 0, hp);
    for (auto c : hp)
    {
        for (auto vec : c.second)
        {
            cout << vec << " ";
        }
        cout << endl;
    }
}
bool subbray_with_sum_zero(int *arr,int n)
{
    unordered_map<int,int>hp;
    //apprch 1
    //find the all the subarray and  and get sum it take o(n^3)

    //apprch 2:
    ///we can use commukative sum
    //complesity o(n^2)


    //approch 3:
    ///use of commulatice sum sum(i,j)=cum(j)-cum(i-1);
    //since sum(i,j)==0;
    int cum[n];
    cum[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        cum[i]=cum[i-1]+arr[i];
    }
    for(int i=0;i<n;i++)
    {
        if(hp.count(cum[i]))
        {
            for(int k=hp[cum[i]]+1;k<=i;k++)
            {
                cout<<arr[k]<<" ";
            }
            return true;
        }
        hp[cum[i]]=i;
    }
    return false;

}
int lenght_of_longest_subbarary(int *arr,int n)
{
     unordered_map<int,int>hp;

       int cum[n];
    cum[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        cum[i]=cum[i-1]+arr[i];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(cum[i]==0)
        {
            ans=max(ans,i+1);
        }
        else if(hp.count(cum[i]))
        {
            ans=max(ans,i-hp[cum[i]]);
        }
        else{
            hp[cum[i]]=i;
        }
    }
    return ans;
    
}
//aother type of quesiton is that subarray with sum is zero
int sum_k(int *arr,int n,int k)
{
    
     unordered_map<int,int>hp;

       int cum[n];
    cum[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        cum[i]=cum[i-1]+arr[i];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(cum[i]==k)
        {
            ans=max(ans,i+1);
        }
        else if(hp.count(cum[i]-k))
        {
            ans=max(ans,i-hp[cum[i]]);
        }
        else{
            hp[cum[i]]=i;
        }
    }
    return ans;

}
//length of longest consecutive eleemnts
int longest_longes_subsequence(int *arr,int n)
{
    //1.appoch is that sort the array
    //and then interate over array
    //making window
    //it take the nlong

    //2.approxh find the min and maximum element 
    //add all element into map
    //iterate ofver the i=min i<-max 
    //increase the count
    // for(int i=min;i<=max;i++)
    // {
    //     if(map.count(arr[i]))
    //     {
    //         count++;
    //     }
    //     else{
    //         ans=max(ans,count);
    //         count=0;
    //     }
    // }
    //time complexity is o(max-min)


    //3.aaproch use of the strik
    // unordered_map<int,int>m;
    // for(int i=0;i<n;i++)
    // {
    //     int no=arr[i];
    //     if(m.count(no-1)==0&&m.count(no+1)==0)
    //     {
    //         m[no]=1;

    //     }
    //     else if(m.count(no-1)&&m.count(no+1))
    //     {
    //         int left=m[no-1];
    //         int right=m[no+1];
    //         m[no]=left+right+1;
    //         m[no-left]=left+right+1;
    //         m[no+right]=left+right+1;

    //     }
    //     else if(m.count(no-1)==0&&m.count(no+1))
    //     {
    //         int rigth=m[no+1];
    //         m[no]=right+1;
    //         m[no+rigth]=rigth+1;
    //     }
    //     else{
    //         int left=m[no-1];
    //         m[no]=left+1;
    //         m[no-left]=left+1;
    //     }
    // }
    // int ans=0;
    // for(auto c:m)
    // {
    //     ans=max(ans,c.second);
    // }
    // cout<<ans<<endl;


    //anothe approh is
    ////using unorderser set 
    //add all number into set 
    //iterator over the array if arr[i]-1 present in it then
    //we skip else we start strik
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(s.find(arr[i]-1)==s.end())
        {
            //then arr[i] is starting strink
            int next=arr[i]+1;
            int strik=1;
            while(s.find(next)!=s.end())
            {
                next++;
                strik++;
            }
            ans=max(ans,strik);

        }
    }
    return ans;



}
//length of the smallest window withich contain all teh characters of pattern
string lenght_pattern(string str,string pattern)
{
    //handle the corner case
    if(pattern.length()>str.length())
    {
        return 0;
    }
    //make freqy array or map for pattern
    int fs[256]={0};//elelment freeucy or window frequncy
    int fp[256]={0};//pattern frequncy 
    for(int i=0;i<pattern.length();i++)
    {
        fp[pattern[i]]++;
    }
    //3sliding teachinque  contraction and expansion and updating of length
    int minlen=INT_MAX;
    int start=0;
    int count=0;
    int startindx=-1;
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        fs[ch]++;
        if(fp[ch]!=0&&fs[ch]<=fp[ch])
        {
            count++;
        }
        if(count==pattern.length())
        {
            //contraction
            char temp=str[start];
            while(fp[temp]==0||fs[temp]>fp[temp])
            {
                fs[temp]--;
                start++;
                temp=str[start];
            }
            int windowlenght=i-start+1;
            if(windowlenght<minlen)
            {
                minlen=windowlenght;
                startindx=start;
            }
        }
    }
    if(startindx==-1)
    {
        return "None";
    }
    string a=str.substr(startindx,minlen);
    return a;
}

//right angles traingle
//given n charater poitns in 2d palin
//hoe may right angled traingle are thier in such that
//parpendicular or base are parralel to x axi and y axis
int find_right_traigle(pair<int,int>*p,int n)
{
    unordered_map<int,int>x;
    unordered_map<int,int>y;
    for(int i=0;i<n;i++)
    {
        x[p[i].first]++;
        y[p[i].second]++;
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        int nx=x[p[i].first]-1;
        int ny=y[p[i].second]-1;
        count+=(nx*ny);
    }
    return count;
}
//tou are give n paoints
//you have to find the number of parraleld rectangle can formed
class point
{
    public:
    int x,y;
    point(int x,int y)
    {
        this->x=x;
        this->y=y;
    }

};
class comparison
{
    public:
    bool operator()( point a, point b)
    {
        if(a.x==b.x)
        {
            return a.y<b.y;
        }
        return a.x<b.x;

    }

};
int find_reactangles()
{
    //1.approch 
    //make all 4 pointer comibantion and check it will make rectangle
    //it wil take o(n^4)
    
    //2/approch hash all the point use unorderst_set<pair<int,int>>
    //make all 2 pair combiantion of point or digoanal point noew chekc other 
    //diognal points are theri in set than recatanle formed
    // it take o(n^2)
    //then ans is divided by 2 beacuse each time we count 2 times
    vector<point>vec;
    int t;
    cin>>t;
    while (t--)
    {
        int x,y;
        cin>>x>>y;
        point p(x,y);
        vec.push_back(p);
        /* code */
    }
    set<point,comparison>s;
    for(auto cp:vec)
    {
        s.insert(cp);
    }
    int ans=0;
    for(auto it=s.begin();it!=prev(s.end());it++)
    {
        for(auto jt=next(it);jt!=s.end();jt++)
        {
            point p1=*it;
            point p2=*jt;
            if(p1.x==p2.x or p1.y==p2.y)
            {
                continue;
            }
            point p3(p1.x,p2.y);
            point p4(p2.x,p1.y);
            if(s.find(p3)!=s.end()&&s.find(p4)!=s.end())
            {
                ans++;
            }
        }
    }
    return ans/2; ///divide by 2 beacuse we have to avoid symmetric cases 
    //lets se exampl p1 and p2 point then other rectabgel p3 and p4
    //then when get p3 and p4 point we get p1 and p2
    //then we add same answer 2 times
    

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
    // hastable<int>price_menu;
    //      price_menu.insert("burger",100);
    //      price_menu.insert("nodeles",30);
    //      price_menu.insert("drinlk",15);
    //      price_menu.insert("momo",10);
    //      price_menu.insert("golgappa",12);
    //      price_menu.insert("samosa",174);
    //      price_menu.insert("maggi",80);
    //      price_menu.insert("chpips",20);
    //      price_menu.insert("pepsi",75);
    //      price_menu.insert("daru",300);
    //      price_menu.insert("freid rice",15);
    //      price_menu.insert("chesee pakode",14);
    //      price_menu.insert("tawa chhiked",24);
    //      price_menu.insert("biryanoi",234);
    //      price_menu.insert("lacha paratha",14);
    //      price_menu.insert("panner pakofa",14543);
    //     //  price_menu.insert("BCAA ",1424);
    //     //  price_menu.insert("creatine",1564);
    //     //  price_menu.insert("glutamine",164);
    //     //  price_menu.insert("protein",3414);
    //     string key;
    //     cin>>key;
    //     cout<<price_menu["chpips"]<<endl;
    //     price_menu["tawa chhiked"]+=10023;
    //     cout<<price_menu["tawa chhiked"]<<endl;
    //price_menu.print_table();
    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++)
    // {
    //     cin>>arr[i];
    // }
    // int ans=lenght_of_longest_subbarary(arr,n);
    // if(ans==0)
    // {
    //     cout<<"no aray sum zero";
    // }
    // else{
    //     cout<<"longest length is "<<ans<<endl;
    // }
    string str,pattern;
    getline(cin,str);
    getline(cin,pattern);
    string ans=lenght_pattern(str,pattern);
    if(ans=="None")
    {
        cout<<"no string";
    }
    else{
        cout<<ans<<endl;
    }
    return 0;

}