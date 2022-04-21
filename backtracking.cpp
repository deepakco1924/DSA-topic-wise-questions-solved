#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using new_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
//backtraking is the way to solve prgogbalem in recusion
// when you reach back you have to solve the strategy

//first question is rate in maze you have to 
//print all path of way of rate of no. of paths
//rat can go in right and down only each step m-1,n,  or m,n-1
void print_path(int output[10][10],int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    return ;
}
bool solve_rate_in_maze(char maz[][10],int output[][10],int i,int j,int m,int n)
{
    //base case
    if(i==m-1&&j==n-1)
    {
        output[i][j]=1;
        print_path(output,m,n);
        return true;

    }
    //corner cases
    if(j>=n||j<0||i>=m||i<0)
    {
        return false;
    }
    if(maz[i][j]=='x')
    {
        return false;
    }
    output[i][j]=1;
    //recursiove part
    bool right_mila=solve_rate_in_maze(maz,output,i,j+1,m,n);
    bool down_mila=solve_rate_in_maze(maz,output,i+1,j,m,n);

    //backtracking
    output[i][j]=0;
    if(right_mila||down_mila)
    {
        return true;
    }
    return false;



}
//QUESITON 
//solve the or make the all possible permutation of string
void permutations_of_string(string input,int i)
{
    //base case
    if(input[i]=='\0')
    {
        cout<<input<<endl;
        return ;
    }
    for(int j=i;input[j]!='\0';j++)
    {
        //recusrive case
        swap(input[j],input[i]);
        permutations_of_string(input,i+1);
        //backtraking to make origrnal string
        swap(input[j],input[i]);
    }
    return ;
}
//function to get unique permutaions using set
void uniquepermutations_of_string(string input,int i,set<string>&s)
{
    //base case
    if(input[i]=='\0')
    {
        s.insert(input);
        return ;
    }
    for(int j=i;input[j]!='\0';j++)
    {
        //recusrive case
        swap(input[j],input[i]);
        uniquepermutations_of_string(input,i+1,s);
        //backtraking to make origrnal string
        swap(input[j],input[i]);
    }
    return ;
}
bool is_safe_place_queen(int maz[10][10],int i,int j,int n)
{
    //check foor the colowm
    for(int row=0;row<i;row++)
    {
        if(maz[row][j]==1)
        {
            return false;
        }
    }
    //check for the left dignowl
    int x=i-1;
    int y=j-1;
    while(x>=0&&j>=0)
    {
        if(maz[x][y]==1)
        {
            return false;
        }
        x--;
        y--;
    }
    //check for the right dignole
    x=i-1;
    y=j+1;
    while(x>=0&&j<n)
    {
        if(maz[x][y]==1)
        {
            return false;
        }
        x--;
        y++;
    }
    return true;
}
bool nqueen_problem(int i,int n,int maz[][10])
{
    if(i==n)
    {
        //base case when reach all rows that means you will all rows 
        //yoou have to print the configration
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(maz[i][j]==1)
                {
                    cout<<'Q'<<" ";
                }
                else{
                    cout<<"_"<<" ";
                }
                
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        return false; //if it is true then it can make onlye one configuraion but if yoou want to more than return false
    }
    for(int j=0;j<n;j++)
    {
        if(is_safe_place_queen(maz,i,j,n))
        {
            maz[i][j]=1;
            bool agemila_kya=nqueen_problem(i+1,n,maz);
            if(agemila_kya)
            {
                return true;
            }
            //backtrack case
            maz[i][j]=0;

        }
    }
    return false;

}
bool canpalce(int mat[][9],int i,int j,int n,int num)
{
    for(int x=0;x<9;x++)
    {
        if(mat[x][j]==num||mat[i][x]==num)
        {
            return false;
        }
    }
    int rt=sqrt(n);
    int sx=(i/rt)*rt;
    int sy=(j/rt)*rt;
    for(int x=sx;x<sx+rt;x++)
    {
        for(int y=sy;y<sy+rt;y++)
        {
            if(mat[x][y]==num)
            {
                return false;
            }
        }
    }
    return true;

}
bool solvethesudoko(int mat[][9],int i,int j,int n)
{
    if(i==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<mat[i][j]<<" ";

            }
            cout<<endl;
        }
        return true;
    }
    if(j==n)
    {
        return solvethesudoko(mat,i+1,0,n);
    }
    if(mat[i][j]!=0)
    {
        return solvethesudoko(mat,i,j+1,n);
    }
    for(int num=1;num<=9;num++)
    {
        if(canpalce(mat,i,j,n,num))
        {
            mat[i][j]=num;
            bool checksolvekrpaye=solvethesudoko(mat,i,j+1,n);
            if(checksolvekrpaye)
            {
                return true;
            }
        }
    }
    mat[i][j]=0;
    return false;
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
    int n;
    cin>>n;
    int maz[9][9]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>maz[i][j];
        }
    }
    solvethesudoko(maz,0,0,n);

    return 0;
}
