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
//BINARAY TREE 

//it is hericircal data structure
//exapmle of data strucute
//information in mycomputer
//drive a b c d and have some folders and each folders have some files
//in binaray tree have 2 nodes

// Main applications of trees include:
// 1. Manipulate hierarchical data.
// 2. Make information easy to search (see tree traversal).
// 3. Manipulate sorted lists of data.
// 4. As a workflow for compositing digital images for visual effects.
// 5. Router algorithms
// 6. Form of a multi-stage decision-making (see business chess).



// 1) The maximum number of nodes at level ‘l’ of a binary tree is 2l. 
// Here level is the number of nodes on the path from the root to the node (including root and node). Level of the root is 0. 
// This can be proved by induction. 
// For root, l = 0, number of nodes = 20 = 1 
// Assume that the maximum number of nodes on level ‘l’ is 2l 
// Since in Binary tree every node has at most 2 children, next level would have twice nodes, i.e. 2 * 2l 

// 2) The Maximum number of nodes in a binary tree of height ‘h’ is 2h – 1. 
// Here the height of a tree is the maximum number of nodes on the root to leaf path. Height of a tree with a single node is considered as 1. 
// This result can be derived from point 2 above. A tree has maximum nodes if all levels have maximum nodes. So maximum number of nodes in a binary tree of height h is 1 + 2 + 4 + .. + 2h-1. This is a simple geometric series with h terms and sum of this series is 2h – 1. 
// In some books, the height of the root is considered as 0. In this convention, the above formula becomes 2h+1 – 1 

// 3) In a Binary Tree with N nodes, minimum possible height or the minimum number of levels is? Log2(N+1) ?   
// This can be directly derived from point 2 above. If we consider the convention where the height of a leaf node is considered as 0, then above formula for minimum possible height becomes? Log2(N+1) ? – 1 

// 4) A Binary Tree with L leaves has at least? Log2L? + 1   levels 
// A Binary tree has the maximum number of leaves (and a minimum number of levels) when all levels are fully filled. Let all leaves be at level l, then below is true for the number of leaves L. 

// 5) In Binary tree where every node has 0 or 2 children, the number of leaf nodes is always one more than nodes with two children.

//lets impliment the tree
class node
{
    public:
    int data;
    node* left;
    node* right;

    node( int d)
    {
        this->data=d;
        left=NULL;
        right=NULL;
    }

};
node* build_tree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL ;
    }
    node* root=new node(d);
    root->left=build_tree();
    root->right=build_tree();
    return root;

}
//TRAVERSEL IN BINARAY TREE
// 1.leverl order
// 2.postorder left right and parent
// 3.preorder node left and then right
// 4.inorder left node and then right
void   print_postorder(node* root)
{
    //in postorder traversal you first go to left and then right and than back to node
    //means first print the left part and then right part and then node itself
    if(root==NULL)
    {
        return ;
    }
   print_postorder(root->left);
   print_postorder(root->right);
    cout<<root->data<<" ";
    return ;

}
void print_inorder(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    print_inorder(root->left);
    cout<<root->data<<" ";
    print_inorder(root->right);
    return ;
}
void print_pretorder(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    print_pretorder(root->left);
    print_pretorder(root->right);
    return ;
}
//level order traversal using recursion 
//the approch is simple find the height of tree 
//make recurisive function which print the kthe levele node from i=1;i<k;i++
int find_the_hight(node* root)
{
    //i am takig root as  1 height 
    if(root==NULL)
    {
        return 0;
    }
    int leftheight=find_the_hight(root->left);
    int rightheight=find_the_hight(root->right);
    return 1+max(leftheight,rightheight);
}
void print_the_kth_level(node* root,int k)
{
    //time complizity of this solutin is o(n^2) beacuse the skew symetrix tree take o(n)time
    //to calculat the height and n time to print the level
    //but if thre tree is complete than it take nlog(n) time
    if(root==NULL)
    {
        return ;
    }
    if(k==1)
    {
        cout<<root->data<<" ";
        return ;
    }
    print_the_kth_level(root->left,k-1);
    print_the_kth_level(root->right,k-1);
    return ;

}
void level_order(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    int k=find_the_hight(root);
    for(int i=1;i<=k;i++)
    {
        print_the_kth_level(root,i);
        cout<<endl;
    }

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
//find the number of nodes in the tree
int count(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lefcount=count(root->left);
    int rightocunt=count(root->right);
    return 1+lefcount+rightocunt;
}
//findting the sum;
int sum_of_nodes(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftsum=sum_of_nodes(root->left);
    int rightsum=sum_of_nodes(root->right);
    return root->data+leftsum+rightsum;
}
int diameter(node* root)
{
    if(root=NULL)
    {
        return 0;
    }
    int h1=find_the_hight(root->left);
    int h2=find_the_hight(root->right);
    int op1=h1+h2;
    int op2=diameter(root->left);
    int op3=diameter(root->right);
    return max(op1,max(op2,op3));


}
pair<int,int> find_the_diameter(node* root)
{
    //first element take the diameter and other take height;
    pair<int,int>a;
    if(root==NULL)
    {   
        a.first=0;
        a.second=0;
        return a;
    }
   pair<int,int>left= find_the_diameter(root->left);
   pair<int,int>right= find_the_diameter(root->right);
   pair<int,int>result;
   int diameter=left.second+right.second;
   result.second=1+max(left.second,right.second);
   result.first=max(diameter,max(left.first,right.first));
   return result;


}
//change every node with it sum if left nodes
void chang_the_tree_bysibling(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    chang_the_tree_bysibling(root->left);
    chang_the_tree_bysibling(root->right);
    if(root->left!=NULL&&root->right!=NULL)
    {
        root->data=root->data+root->left->data+root->right->data;
    }
    else if(root->left==NULL&&root->right==NULL)
    {
        return ;
    }
    else if(root->left==NULL)
    {
        root->data+=root->right->data;
    }
    else if(root->right==NULL)
    {
        root->data+=root->left->data;
    }
    return ;
}
//
int solve_sibling_sum(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL&& root->right==NULL)
    {
        return root->data;
    }
    int left=solve_sibling_sum(root->left);
    int right=solve_sibling_sum(root->right);
    int temp=root->data;
    root->data=left+right;
    return temp+left+right;
}


//HIEGHT BALANCED TREE
//the height balance tree the tree in which at every
//node the diffrence of heights from left and right part should be less then 1
//h1 -h2<=1
pair<bool,int> check_for_height_balacace(node* root)
{
    pair<bool,int>a;
    if(root==NULL)
    {
        a.first=true;
        a.second=0;
        return a;
    }
    pair<bool,int>left=check_for_height_balacace(root->left);
    pair<bool,int>right=check_for_height_balacace(root->right);
    if(left.first&&right.first)
    {
        if(abs(left.second-right.second)<=1)
        {
            a.first=true;
        }
        else{
            a.first=false;
        }
    }
    a.second=max(left.second,right.second)+1;
    return a;
}
node* build_tree_from_array(int *arr,int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    int mid=(s+e)>>1;
    node* root=new node(arr[mid]);
    root->left=build_tree_from_array(arr,s,mid-1);
    root->right=build_tree_from_array(arr,mid+1,e);
    return root;

    

}

//genertaing the tree from preorder and inorder
//remen=ber if you have preordfer +inorfer or postorder +inorder then always their is one unique binary tree
//the approch 
//find traverse the preorder find the corresponfig element in the inorder
//after find the root in inorder left part go to the left and right part go to the right
node* make_tree_from_preorder_inorder(int *inorder,int *preorder,int s,int e)
{
    static int i=0;
    if(s>e)
    {
        return  NULL;
    }
    int element=preorder[i];
    int j=s ;
    for(;j<=e;j++)
    {
        if(inorder[j]==element)
        {
            break;
        }
    }
    node* root=new node(element);
    i++;
    root->left=make_tree_from_preorder_inorder(inorder,preorder,s,j-1);
    root->right=make_tree_from_preorder_inorder(inorder,preorder,j+1,e);
    return root;





}
//question to solve right view of tree
//approch
//make the level order traversel the
//trick is when the next node is NULL then print the current node
void right_view_using_BFS(node* root)
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
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            if(q.front()==NULL)
            {
                cout<<temp->data<<",,";
            }
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
void right_view(node* root,int level)
{
    static int maxlevel=-1;
    if(root==NULL)
    {
        return ;
    }
    if(level>maxlevel)
    {
        cout<<root->data<<",";
    maxlevel=level;
    }
    right_view(root->right,level+1);
    right_view(root->left,level+1);
    return ;

}
void helper_at_k_level(node* root,int k)
{
    if(root==NULL)
    {
        return ;
    }
    if(k==0)
    {
        cout<<root->data<<",";
    }
    helper_at_k_level(root->left,k-1);
    helper_at_k_level(root->right,k-1);
    return ;
}
int print_kTH_distance_from_the_target(node* root,node* target,int k)
{


    //each node return the distanc of target node from himself
    if(root==NULL)
    {
        return -1;
    }
    if(root==target)
    {
        helper_at_k_level(root,k); //simple if current node is target then print all element 
        //which are at a diostance of k from the current node
        return 0;
    }
    int DL=print_kTH_distance_from_the_target(root->left,target,k);
    //checking from the left part of the current  node
    if(DL!=-1)//if target present at left part
    {
        if(DL+1==k)//check for the current node is present at distance from target
        {
            cout<<root->data<<",";
        }
        else if((k-2-DL)>=0)//else print the remaing distance to the riht part of current node
        {
            helper_at_k_level(root->right,k-2-DL);
        }
        return DL+1;//return the current distance of target himself
    }
    int DR=print_kTH_distance_from_the_target(root->right,target,k);//same case going on herer
    if(DR!=-1)
    {
        if(DR+1==k)
        {
            cout<<root->data<<",";
        }
        else if((k-2-DR)>=0)
        {
            helper_at_k_level(root->left,k-2-DR);
        }
        return DR+1;
    }
    return -1;//returning -1 means target is not presnt at left and right

}
//quesiton finding the lowewst common ancistor
node* LCA(node* root,int a,int b)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==a or root->data==b)
    {
        return root;
    }
    node* leftans=LCA(root->left,a,b);
    node* rightans=LCA(root->right,a,b);
    if(leftans && rightans)
    {
        return root;

    }
    if(leftans)
    {
        return leftans;
    }
    return rightans;
}
//itierative approch
//finding the path of A and B
//finding the last elembt wich is common both path
bool finding_the_path(node* root,int a,list<int>&l)
{
    if(root==NULL)
    {
        return false ;
    }
    if(root->data==a)
    {
        l.push_front(a);
        return true;
    }
    bool leftans=finding_the_path(root->left,a,l);
    bool rightans=finding_the_path(root->right,a,l);
    if(leftans==true)
    {
        l.push_front(root->data);
        return true;
    }
    if(rightans==true)
    {
        l.push_front(root->data);
        return true;
    }
    return false;


}
int find_lca(node * root,int a,int b)
{
    if(root==NULL)
    {
        return -1;
        //tree is not thier
    }
    list<int>l1;
    list<int>l2;
    finding_the_path(root,a,l1);
    finding_the_path(root,b,l2);
    int ans=-1;
    while(!l1.empty()&&!l2.empty())
    {
        if(l1.front()!=l2.front())
        {
            break;
        }
        ans=l1.front();
        l1.pop_front();
        l2.pop_front();

    }
    return ans;

}
//the question is finding the maximum sum path of the tree
//approch is
//the possible casess is 
//sum will pass thoruugh root node
//second sum will is in left
//third is sum is present in right
//the asnwer is sum of all three cases

//each node have possible
//root->data
//root->data+ls
//root->data+rs
//root->data+ls+rs
//resturn is maxmimm path sum and maximim brach sum
pii maximum_sum_path(node* root)
{
    pii a;//firdst element is maxium sum and sexond element is brach sum
    if(root==NULL)
    {
        a.ff=0;
        a.ss=0;
        return a;

    }
    //first eleemnt is maximim sim and second element is brach sum
    //recursion case 
    pii left=maximum_sum_path(root->left);
    pii right=maximum_sum_path(root->right);
    //finding the current node
    //maximum sum
    int op1=root->data;  
    int op2=root->data+left.second;
    int op3=root->data+right.second;
    int op4=root->data+right.second+left.second;
    int op5=max(op1,max(op2,max(op3,op4)));

    //comapring for the left sum ,right sum ,and current maximum sum
    a.first=max(op5,max(left.first,right.first));

    //finding the branch sum of current nod;
    int op6=max(left.second,right.second);
    a.second=max(op6,(int)0)+root->data;
    return a;
}
//finding the smallest distance between two node
//1.arrpoch
//find the path of a and path of b
//let l1=the distance path of a and l2 is distnace path of b
//and l3= is the common path
//return l1+l2-2*l3

//2/.approch
//make helper function which return level of node from root
//find the lca of a and b
//find the level a from lac p1
//din the levele b form lca p2
//return p1+p2
int seach_level(node* root,int key ,int level) //by default level of root node is 0
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->data==key)
    {
        return level;
    }
    int left=seach_level(root->left,key,level+1);
    int right=seach_level(root->right,key,level+1);
    if(left!=-1)
    {
        return left;
    }
    if(right!=-1)
    {
        return right;
    }
    return -1;
}
int find_shortest_distance(node* root,int a,int b)
{
    node* lca=LCA(root,a,b);
    int p1=seach_level(lca,a,0);
    int p2=seach_level(lca,b,0);
    return p1+p2;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    node* root=build_tree();
    bfs(root);
    cout<<endl;
    int ans=find_shortest_distance(root,10,-25);
    cout<<ans<<endl;


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