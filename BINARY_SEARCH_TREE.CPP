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

//BINARY SEARCH TREE
//it special type of tree
//which all element which is less than or equal to root goes left side of root
//and greter then root go to the right of tree
//and this property hold for all node
//advantage is seravhing will make log(n) time to search
//but wors case colmleity is still o(n) beacuse of skew tree
class node
{
    public:
    int data;
    node* left;
    node* right;
    node( int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }

};
node* insert_in_bst(node* root,int d)
{
    //it gettling root and return new root
    if(root==NULL)
    {
        return  new node(d);
    }
    if(d<=root->data)
    {
        root->left=insert_in_bst(root->left,d);
    }
    else{
        root->right=insert_in_bst(root->right,d);
    }
    return root;
}
node* build_BST()
{
    int d;
    cin>>d;
    node* root=NULL;
    while(d!=-1)
    {
        root=insert_in_bst(root,d);
        cin>>d;

        
    }
    return root;
}
void print_inorder( node* root)
{
    //inorder of BST is alwyas sorted in nature 
    if(root==NULL)
    {
        return ;
    }
    print_inorder(root->left);
    cout<<root->data<<",";
    print_inorder(root->right);
    return ;
}
bool search_node( node* root,int key)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==key)
    {
        return true;
    }
    if(root->data>=key)
    {
        return search_node(root->left,key);
    }
    else{
         return search_node(root->right,key);
    }
    return false;
}
void bfs(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
//deletion of node
//thier are 3 cases
//1.node have 0 childeres  in this go to the node delete node return NULL to parent
//2.node have 1 childere in this store the child of node to temperory node delete the current node return 
//the temprory node to its parent of current node
//3.mnode have 2 chld
//if their are 2 child then if delete current node then how have potenital to become new node
//eitheri find the maxelement in left or find the minimum element on right 
//and replace the node now we have two elemnt of same value
//now we have to recursive call to delete the replace node either left or right
node* delete_node(node* root,int key)
{
    if(root==NULL)
    {  
        return NULL;
    }
    else if(key<root->data)
    {
        root->left=delete_node(root->left,key);
        return  root;
    }
    else if(root->data==key)
    {
        //thier are 3 cases we have to handle
        //1.case when it is left node
        if(root->left==NULL&&root->right==NULL)
        {
            delete root;
            return NULL;
        }
        //2. case when it have one child
        if(root->left!=NULL&&root->right==NULL)
        {
            node* temp=root->left;
            delete root;
            return temp;
        }
        if(root->right!=NULL&&root->left==NULL)
        {
            node* temp=root->right;
            delete root;
            return temp;
        }

        //3.case when it have 2 childrens
        node* replacenode=root->right;
        while(replacenode->left!=NULL)
        {
            replacenode=replacenode->left;
        }
        root->data=replacenode->data;
        root->right=delete_node(root->right,replacenode->data);
        return root;
    }

        root->right=delete_node(root->right,key);
        return root;
    

}
//checking for the BST
//the apprch is bottome up
//each node return mmax element in left and min element in left and and boolen value itself is bst or not
//and cheking each node by taking the condition that is root_.data is grater than left max and smaller than right max
//and left is and right is bst than true else fasle
pair<bool,pair<int,int>> check_BSt(node* root)
{
    pair<bool,pair<int,int>>p;
    if(root==NULL)
    {
        p.first=true;
        p.ss.ff=INT_MIN;
        p.ss.ss=INT_MIN;
        return p;
    }
    pair<bool,pair<int,int>>leftans=check_BSt(root->left);
    pair<bool,pair<int,int>>rightans=check_BSt(root->right);
    pair<bool,pair<int,int>>result;
    if(leftans.first&&rightans.first&&root->data>=leftans.second.first&&root->data<rightans.second.second)
    {
        result.first=true;
    }
    else{
        result.first=false;
    }
    result.second.second=max(leftans.second.second,rightans.second.second);
    if(leftans.second.first==INT_MIN &&rightans.second.first==INT_MIN)
    {
        result.second.first=root->data;
    }
    else if(leftans.second.first==INT_MIN&&rightans.second.first!=INT_MIN)
    {
        result.second.first=rightans.second.first;
    }
    else if(leftans.second.first!=INT_MIN&&rightans.second.first==INT_MIN)
    {
        result.second.first=leftans.second.first;
    }
    else{
        result.second.first=min(leftans.second.first,rightans.second.first);
    }
    result.second.second=max(leftans.second.second,rightans.second.second);
    return result;


}
//better apprcoh
bool check_bst_topdown(node* root,int minvalue=INT_MIN,int max_value=INT_MAX)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data>=minvalue&&root->data<max_value&&check_bst_topdown(root->left,minvalue,root->data)&&check_bst_topdown(root->right,root->data,max_value))
    {
        return true;
    }
    return false;

}

//flatten the bst 
//conver the bst into the sorted linked list
//each we use postorder tracversel means we make left part as a bst and right part as bst 
//and make attach current node left linked list and rightlinked list
class linked_list
{
    public:
    node* head;
    node* tail;

};
linked_list flattenlist(node * root)
{
    linked_list l;
    if(root==NULL)
    {
        l.head=NULL;
        l.tail=NULL;
        return l;

    }
    //if leaf node
    if(root->left==NULL&&root->right==NULL)
    {
        l.head=root;
        l.tail=root;
        return l;
    }
    //if left is not null
    if(root->left!=NULL&&root->right==NULL)
    {
        linked_list leftlist=flattenlist(root->left);
        l.head=leftlist.head;
        leftlist.tail->right=root;
        l.tail=root;
        return l;


    }
    if(root->right!=NULL&&root->left==NULL)
    {
        linked_list rightlist=flattenlist(root->right);
        l.tail=rightlist.tail;
        l.head=root;
        l.head->right=rightlist.head;
        return l;
    }
    linked_list leftlist=flattenlist(root->left);
    linked_list rightlist=flattenlist(root->right);
    leftlist.tail->right=root;
    root->right=rightlist.head;
    l.head=leftlist.head;
    l.tail=rightlist.tail;
    return l;
}

//buidligng bst using preordder
//the aprpcoh is find the inorder traversal and make the bst
node* build_bst_preorder(int *pre ,int *inr,int s,int e)
{
    static int i=0;
    if(s>e)
    {
        return  NULL;
    }
    int element=pre[i];
    int j=s ;
    for(;j<=e;j++)
    {
        if(inr[j]==element)
        {
            break;
        }
    }
    node* root=new node(element);
    i++;
    root->left=build_bst_preorder(pre,inr,s,j-1);
    root->right=build_bst_preorder(pre,inr,j+1,e);
    return root;

}

//catalian number
//catailina number can derived using the special question of the bst
//catalian number is 2nCn/n+1
//and the quesiton is saying that find the number of bst or unbalanced binarry treeyou can formed using the 1,2,3,=----------n
//element supoose at any ith pos 
//ith element is root and i-1 element go to the left and n-i element go to the right of ith elemebt
//let the fucntion f(n) which return the number bst make using n natural number
//from left part you make f(i-1) bst
//eight parth make f(n-i) bst
//and root is fixed
//seleceting 1 bst from left and selecting 1 bst from right
//the number of combination of bst formebd is xC1 *1*yC1
//which is equal to f(i-1)*f(n-i)
//so to get overal aswer we have to submission from 1 ro n
//f(n)=sumbmiasion of i from 1 to n f(i-1)*f(n-1)
//which is also wqual to catalian number

//we can use the memoeixation or synamic programinfg 
int dp[100000]={0};
int find_number_bst(int n)
{
    if(n==0||n==1)
    {
        return 1;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=find_number_bst(i-1)*find_number_bst(n-i);
    }
    return dp[n]=sum;
    //if quesion says find the the number if bunarrh tree then simply multiply the catallan number
    //by n! facroieal

    

}
class compare
{
    public:
    bool operator()(const pii &a,const pii &b)const
    {
        if(a.first==b.first)
        {
            return a.second>b.second;
        }
        return a.first<b.first;
    }
};
class moneycomapre
{
    public:
    bool operator()(pair<string,int>a,pair<string,int>b)
    {
        return a.second<b.second;
    }

};
void stl_part()
{
    //set is made by the bst
    //it contain the unique element in sorted order
    set<int>s;
    s.insert(1);
    s.insert(8);
    s.insert(6);
    s.insert(4);
    s.insert(5);
    for(auto c:s)
    {
        cout<<c<<",";
    }
    //tou can also make set of pair
    set<pii>m;
    m.insert({2,3});
    m.insert({2,5});
    m.insert({2,4});
    m.insert({5,3});
    m.insert({1,2});
    m.insert({7,3});

    set<pii,compare>g;//addtional comaprtor fucntion use for the cusitmmxe comaprixzen
    g.insert({2,3});
    g.insert({2,5});
    g.insert({2,4});
    g.insert({5,3});
    g.insert({1,2});
    g.insert({7,3});
    for(auto c:g)
    {
        cout<<c.ff<<","<<c.ss<<endl;
    }
    multiset<int>mul;
    int arr[]={23,4,4,23,4,6,3,4,6,7,8,9,1};
    int n=sizeof(arr)/sizeof(int);
    mul.insert(arr,arr+n);
    cout<<endl;
    mul.erase(mul.find(4));
    for(auto xp:mul)
    {
        cout<<xp<<",";
    }
    pair<multiset<int>::iterator,multiset<int>::iterator>p=mul.equal_range(4);
    cout<<endl;
    for(auto it=p.first;it!=p.second;it++)
    {
        cout<<(*it)<<" ";
    }
    //customcomparisopm
    cout<<endl;
    pair<string,int>p1=make_pair("deepak",10032);
    pair<string,int>p2=make_pair("raji",3492);
    pair<string,int>p3=make_pair("nabu",3443);
    pair<string,int>p4=make_pair("rajaesj",324);
    pair<string,int>p5=make_pair("manu",342);
    pair<string,int>p6=make_pair("called",342);
    multiset<pair<string,int>,moneycomapre>mp; //if comaprtor not gicven then we sort accoprign to first element
    mp.insert(p1);
    mp.insert(p2);
    mp.insert(p3);
    mp.insert(p4);
    mp.insert(p5);
    mp.insert(p6);
    for(auto cp:mp)
    {
        cout<<cp.first<<","<<cp.second<<endl;
    }




}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
stl_part();


// cout<<endl;
// pair<bool,int>result=check_for_height_balacace(root);
// if(result.first)
// {
//     cout<<"yes\n";
// }
// else{
//     cout<<"No";
// }



return 0;


}

