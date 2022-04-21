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
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

//DOUBle linked list
// The advantage of a doubly linked list (also called two – way linked list) is that given a node in
// the list, we can navigate in both directions. A node in a singly linked list cannot be removed
// unless we have the pointer to its predecessor. But in a doubly linked list, we can delete a node
// even if we don’t have the previous node’s address (since each node has a left pointer pointing to
// the previous node and can move backward).
// The primary disadvantages of doubly linked lists are:
// • Each node requires an extra pointer, requiring more space.
// • The insertion or deletion of a node takes a bit longer (more pointer operations)

class node
{
    public:
    int data;
    node* next;
    node* prev;
    node(int d)
    {
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
};
void insert_at_head(node*& head,int d)
{
    if(head==NULL)
    {
        head=new node(d);
        return ;
    }
    node* n=new node(d);
    n->next=head;
    head->prev=n;
    head=n;
    return ;


}
void insert_at_end(node* &head,int d)
{
    if(head==NULL)
    {
        head=new node(d);
        return ;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node* n=new node(d);
    temp->next=n;
    n->prev=temp;
    return ;

}
void print_list(node* head)
{
    if(head==NULL)
    {
        return;
    }
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    return; 
}
int lenght(node* head)
{
    int cnt=0;
    while(head!=NULL)
    {
        cnt++;
        head=head->next;
    }
    return cnt;
}
void insert_at_pos(node* &head,int d,int pos)
{
    if(head==NULL||pos>=lenght(head))
    {
        insert_at_end(head,d);
        return ;

    }
    if(pos==0)
    {
        insert_at_head(head,d);
        return ;
    }
    node *temp=head;
    for(int i=0;i<pos;i++)
    {
        temp=temp->next;

    }
    node* n=new node(d);
    n->next=temp;
    temp->prev->next=n;
    n->prev=temp->prev;
    temp->prev=n;
    return ;
}
void delete_from_head(node* &head)
{
    if(head==NULL)
    {
        return ;
    }
    head=head->next;
    delete head->prev;
    head->prev=NULL;
    return ;
}
void deelte_from_end(node* &head)
{
    if(head==NULL)
    {
        return ;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;

    }
    temp=temp->prev;
    delete temp->next;
    temp->next=NULL;
    return ;
}
void delete_from_pos(node* &head,int pos)
{
    if(head==NULL||pos>=lenght(head))
    {
        return ;
    }
    if(pos==0)
    {
        delete_from_head(head);
        return ;
    }
    node* temp=head;
    for(int i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    node* n=NULL;
    if(temp->next->next!=NULL)
    {
        n=temp->next->next;

    }
    delete temp->next;
    temp->next=n;
    if(n!=NULL)
    {
    n->prev=temp;
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
    node* head=NULL;
    insert_at_end(head,1);
    insert_at_end(head,2);
    insert_at_end(head,3);
    insert_at_end(head,4);
    insert_at_end(head,5);
    insert_at_end(head,6);
    insert_at_end(head,7);
    cout<<lenght(head)<<endl;
    print_list(head);
    cout<<endl;
    delete_from_pos(head,6);
    print_list(head);


    return 0;


}