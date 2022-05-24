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
//GRAPH
//it is liner not liner data strucure
//it is newtwork the data strucutre
//many graph problem easy in interview
//but contest have many diifcult

//application of graph around us

//google maps if we consider verticses as city or coutry and roads and flight are edges then finding shortest path
//socila newtork libke facebook,instagram ,linkdan (instagram linked you are nodes all freind can se your post)
//circut designing reduced the metal
//netwrok router of server
//topological sort (api call )/software installation
//learnig in deep learning and vertices are nurons and connection between them
//framework like tensor flow build computaion graph for optmising calculation
//web document (dom tree) used in making web application
//image processin and segmentin /colir paingint
//using pixel and connection between them

//thier are two types of edges
//directed edges and biderical edges
//means directed eges x--->y
//in bidirectional x---->y and y--->X

//represetation of graph
//1.adjaxentry matrix
//make boolen matrix
//if their edge between any vertices mat[x][y]=true if it is bidirectional mat[x][y]=ture and mat[y][x]=true
//it make lokup in o(1);
//but disadvantagwe is meomory requiremnet of(o(n^2)) and if you want to find the number of connection of given vertices
//you have to traverse whole the columns o(n)

//2.method edgle list you vector of vertices and
//edges of vector pair(vectice,vectiecs);

//3.adjentry list
//make the hasmap of like <int,vector> add vertices and key valye pair if edge between key and value
//advantage is it is memory efficent if you have e edges o(edges) meory space
//it take finding the connvection of o(edges of that vetcies)

//finidn the edges
//if every vertices connvected every other vertcies than you have n^c^2 edges
//min edges is zero
//if every vertices connected with using edge that you have n-1 edges if n vertices is their

class adjlist
{
public:
    int v;
    list<int> *l;
    adjlist(int size = 10)
    {
        l = new list<int>[size];
        v = size;
    }
    void addedge(int x, int y, bool bidrectinal = false)
    {
        l[x].push_back(y);
        if (bidrectinal)
        {
            l[y].push_back(x);
        }
    }
    void printlist()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << "->";
            for (auto c : l[i])
            {
                cout << "(" << c << "), ";
            }
            cout << endl;
        }
    }
};
template <typename T>
class graph
{
public:
    unordered_map<T, list<pair<T, int>>> l;
    void addedge(T x, T y, int wt = 0, bool birectional = false)
    {
        l[x].push_back(make_pair(y, wt));
        if (birectional)
        {
            l[y].push_back(make_pair(x, wt));
        }
    }
    void printlist()
    {
        for (auto xp : l)
        {
            cout << xp.first << "->";
            for (auto cp : xp.second)
            {
                cout << "(" << cp.first << "," << cp.second << ")->";
            }
            cout << endl;
        }
    }
    //graph tranversal\\ws
    //it is way of visiting all the verticves of graph
    //thier are two types of traversal bfs and dfs

    //bfs is the itreative way
    void BFS(T src)
    {
        //we need two data strcuture
        //queeu and vissted araray or hastabel
        unordered_map<T, bool> visited;
        queue<T> q;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            T temp = q.front();
            cout << temp << " ";
            q.pop();
            for (auto nbr : l[temp])
            {
                if (visited[nbr.first] == false)
                {
                    q.push(nbr.first);
                    visited[nbr.first] = true;
                }
            }
        }
    }
    //single source shortest path from the src
    //means finding the shortest path from the srch to all other node
    //distance calluated by the BFS if graph has unwated means each edge have unit wait
    int BFS_shortest_path(T src, T destination)
    {
        //we need two data strcuture
        //queeu and vissted araray or hastabel
        unordered_map<T, int> visited; //this map containg the distance of node from the src node
        queue<T> q;
        //we may also get the path well
        unordered_map<T, T> parent;
        parent[src] = src;
        q.push(src);
        for (auto sp : l)
        {
            visited[sp.first] = INT_MAX;
        }
        visited[src] = 0;

        while (!q.empty())
        {
            T temp = q.front();
            q.pop();
            for (auto nbr : l[temp])
            {
                if (visited[nbr.first] == INT_MAX)
                {
                    q.push(nbr.first);
                    visited[nbr.first] = visited[temp] + 1;
                    parent[nbr.first] = temp;
                }
            }
        }
        // for(auto nbr:visited)
        // {
        //     if(nbr.first!=src)
        //     {
        //         cout<<nbr.first<<"->"<<nbr.second<<endl;///this for loop print all the node shortes distance fro the source

        //     }
        // }
        T temp = destination;
        while (temp != src)
        {
            cout << temp << "->";
            temp = parent[temp];
        }
        cout << src;
        cout << endl;

        return visited[destination];
    }
    //now to we have to learn about
    //DFS
    //depth first search
    void dfs_helper(T src, unordered_map<T, bool> &visited)
    {
        cout << src << " ";
        visited[src] = true;
        for (auto nbr : l[src])
        {
            if (visited[nbr.first] == false)
            {
                dfs_helper(nbr.first, visited);
            }
        }
    }
    void DFS(T src)
    {
        unordered_map<T, bool> visited;
        for (auto node : l)
        {
            visited[node.first] = false;
        }
        dfs_helper(src, visited);
    }
    //finding the connected componets in the grapg
    //the apprcoh is that call the dfs on all node
    void find_connected_components()
    {
        unordered_map<T, bool> visited;
        for (auto node : l)
        {
            visited[node.first] = false;
        }
        int count = 0;
        for (auto node : l)
        {
            if (visited[node.first] == false)
            {
                cout << "components" << count << " ->";
                dfs_helper(node.first, visited);
                count++;
                cout << endl;
            }
        }
        return;
    }

    //toplogocal sort
    //we cannot sort cyclic grapgh
    //the grapgh should have directed acylic graph
    //we can use dfs to solve this just vistit all node so that node which have no dpeendences
    //when you visted all nbr and return from current node and current node to list
    void dfs_sort_toplogical_helper(T src, unordered_map<T, bool> &visited, list<T> &order)
    {
        visited[src] = true;
        for (auto nbr : l[src])
        {
            if (visited[nbr.first] == false)
            {
                dfs_sort_toplogical_helper(nbr.first, visited, order);
            }
        }
        order.push_front(src);
        return;
    }
    void toplogical_sort_using_dfs()
    {
        unordered_map<T, bool> visted;
        list<T> order;
        for (auto node : l)
        {
            visted[node.first] = false;
        }
        for (auto node : l)
        {
            if (visted[node.first] == false)
            {
                dfs_sort_toplogical_helper(node.first, visted, order);
            }
        }
        for (auto c : order)
        {
            cout << c << endl;
        }
    }
    //topoligical sort using bfs
    //we term defines indegreee means number of incomeing degree
    void topoogical_sort_using_bfs()
    {
        //make array or unorderes_map which  contian the in degree
        unordered_map<T, int> indegree;
        for (auto node : l)
        {
            indegree[node.first] = 0;
        }
        //we can update while traversing all nodes
        for (auto node : l)
        {
            T x = node.first;
            for (auto nbr : node.second)
            {
                indegree[nbr.first]++;
            }
        }
        queue<T> q;
        for (auto node : l)
        {
            if (indegree[node.first] == 0)
            {
                q.push(node.first);
            }
        }
        while (!q.empty())
        {
            T temp = q.front();
            cout << temp << endl;
            q.pop();
            for (auto nbr : l[temp])
            {
                indegree[nbr.first]--;
                if (indegree[nbr.first] == 0)
                {
                    q.push(nbr.first);
                }
            }
        }
        return;
    }
    //cycle detection in undirected graph
    bool is_tree(T src)
    {
        unordered_map<T, T> parent;
        unordered_map<T, bool> visited;
        for (auto node : l)
        {
            visited[node.first] = false;
            parent[node.first] = node.first;
        }
        //beacuse we use bfs we have first node as src where we start
        queue<T> q;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            for (auto xp : l[node])
            {
                T nbr = xp.first;
                if (visited[nbr] == true and parent[node] != nbr)
                {
                    return true;
                }
                else if (visited[nbr] == false)
                {
                    visited[nbr] = true;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }
        return false;
    }

    ///finding the cycle detection using dfs is best we can find the
    //cycle in both directed and undirected graph
    //now we use dfs and find the ecyle is directed graph
    //if thier is back edge in the path than their is cycel
    //what is back edge whne you visite the nbr of currentn node than nbr is in the current path then thier is back edge
    bool cycle_helper(T node, unordered_map<T, bool> &visited, unordered_map<T, bool> &path)
    {
        visited[node] = true; //visiing the current node
        path[node] = true;    //add current node to the path
        for (auto x : l[node])
        {
            T nbr = x.first;       //go to the neigboures of the current node
            if (path[nbr] == true) //if the nbr is already in the path than it is the backedge
            {
                return true; //return called true
            }
            else if (visited[nbr] == false) //that means the current node is not in the path so no check the current element node visiste then go to visist
            {
                bool cycle_mila = cycle_helper(nbr, visited, path); //now check the cuurent nbr have cyle
                if (cycle_mila)
                {
                    return true;
                }
            }
        }
        path[node] = false; //now you leaving the current node remove from the path
        return false;
    }
    bool conatin_cyle_in_directed()
    {
        unordered_map<T, bool> visited;
        unordered_map<T, bool> path;
        for (auto node : l)
        {
            visited[node.first] = false;
        }
        for (auto x : l)
        {
            T node = x.first;
            if (visited[node] == false)
            {
                bool cycle_mila = cycle_helper(node, visited, path);
                if (cycle_mila)
                {
                    return true;
                }
            }
        }
        return false;
    }

    // the question finding the path ccyle detection in undirected graph using dfs
    bool helper_dfs_undirected(T node, unordered_map<T, bool> &visited, unordered_map<T, T> &parent)
    {
        visited[node] = true;
        for (auto x : l[node])
        {
            T nbr = x.first;
            if (visited[nbr] == true and parent[node] != nbr)
            {
                return true;
            }
            else if (visited[nbr] == false)
            {
                parent[nbr] = node;
                bool cycle_mila = helper_dfs_undirected(nbr, visited, parent);
                if (cycle_mila)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool find_undirectiod_cyle(T src)
    {
        unordered_map<T, bool> visited;
        unordered_map<T, T> parent;
        for (auto x : l)
        {
            T node = x.first;
            visited[node] = false;
            parent[node] = node;
        }
        return helper_dfs_undirected(src, visited, parent);
    }

    //dijkastra algorithm
    //finding the shortset path in the wighted graph
    //it may be unidreceted and directed also
    void Dijkastra(T src)
    {
        unordered_map<T, int> distance;
        for (auto x : l)
        {
            T node = x.first;
            distance[node] = INT_MAX;
        }
        distance[src] = 0;
        set<pair<int, T>> s; //first parameter is distance and other node
        s.insert(make_pair(0, src));
        while (!s.empty())
        {
            auto p = *(s.begin());
            s.erase(s.begin());
            T node = p.second;
            int nodedist = p.first;
            //iteratca over the nbrs of current node
            for (auto child : l[node])
            {
                T nbr = child.first;
                if (nodedist + child.second < distance[nbr])
                {
                    //now we have to update the distance of nbr node and add to the set
                    auto f = s.find(make_pair(distance[nbr], nbr));
                    if (f != s.end())
                    {
                        s.erase(f);
                    }
                    distance[nbr] = nodedist + child.second;
                    s.insert(make_pair(distance[nbr], nbr));
                }
            }
        }
        for (auto node : distance)
        {
            cout << "distance of " << node.first << " is " << node.second << endl;
        }
        return;
    }
};

//snake and ladder
//we have to find the minimu number of dice throw so that it reached at findal destination
//and we have to print path also
void solve_snakes_ladder()
{
    int board[50] = {0};
    //here is jump of ladder or snake
    //if jump is positive means it is ladder
    //else it is the snakes
    //meand if you fall inot the 2 then you directly go to node 15 by ladder jump 13
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;
    //add all edges into the grapgh
    graph<int> g;
    for (int i = 0; i <= 36; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int j = i + dice;
            j += board[j];
            if (j <= 36)
            {
                g.addedge(i, j, 0, false);
            }
        }
    }
    g.addedge(36, 36);
    int ans = g.BFS_shortest_path(0, 36);
    cout << ans << endl;
    return;
}

//flooad fill algorithm
//it is simple vareiant of bfs and dfs used for the paint of various connected componenet
//it generly perform to implicit graph (2d matrix)
//strt from current node we call dfs
//neibours are left right up and down
void helper_flood_algo(char mat[][100], char ch, char boundary, int i, int j, int n)
{
    if (i >= n || j >= n || i < 0 || j < 0)
    {
        return;
    }
    if (mat[i][j] != boundary)
    {
        return;
    }
    mat[i][j] = ch;
    helper_flood_algo(mat, ch, boundary, i + 1, j, n);
    helper_flood_algo(mat, ch, boundary, i - 1, j, n);
    helper_flood_algo(mat, ch, boundary, i, j + 1, n);
    helper_flood_algo(mat, ch, boundary, i, j - 1, n);
}
void flood_fill_algo()
{
    int n;
    cin >> n;
    char mat[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    helper_flood_algo(mat, '@', '.', 3, 0, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
}
//question of icpc trip
//edge of is shows price of flight and train
//minimize the total wair such that you can use only one aerplacne;
//you have to case
//case 1 when do note use plane  find the simple dijkastra and find the destination cost
//case2 use when we plane
//we do not now which aerplane use
//we find all possible case
//source------y----z------w
//we use y z as a plne
//apply dijakstra fron source to y and dijasktra to destination  to z
//i will find the min of case 1 and case 2 allo y and z edge
class icpc
{
    public:
    unordered_map<string,list<pair<string,pair<int,int>>>>mt;
    void addedge(string a,string b,int costrain,int costplane)
    {
        mt[a].push_back({b,{costrain,costplane}});
        mt[b].push_back({a,{costrain,costplane}});
    }
    unordered_map<string,int> dikastra(string src)
    {
        unordered_map<string,int>destination;
        for(auto x:mt)
        {
            string node=x.first;
            destination[node]=INT_MAX;
        }
        destination[src]=0;
        set<pair<int,string>>s;
        s.insert(make_pair(0,src));
        while(!s.empty())
        {
            auto p=*(s.begin());
            s.erase(s.begin());
            int des=p.first;
            string node=p.second;
            for(auto x:mt[node])
            {
                string nbr=x.first;
                int nbrvalue=x.second.first;
                if(des+nbrvalue<destination[nbr])
                {
                    auto f=s.find({destination[nbr],nbr});
                    if(f!=s.end())
                    {
                        s.erase(f);
                    }
                    destination[nbr]=des+nbrvalue;
                    s.insert({destination[nbr],nbr});

                }
            }
        }
        return destination;

    }
};


class city_of
{
    public:
    string x;
    string y;
    int cost;
    city_of(string a,string b,int value)
    {
        x=a;
        y=b;
        cost=value;
    }

};
int solve_icpc()
{
  int n;
  cin>>n;
  icpc g;
  vector<city_of>vec;
  for(int i=0;i<n;i++)
  {
      string a,b;
      int costplane;
      int costtrain;
      cin>>a>>b>>costtrain>>costplane;
      city_of n(a,b,costplane);
      vec.push_back(n);
      g.addedge(a,b,costtrain,costplane);

  }
  unordered_map<string,int>case1=g.dikastra("amrit");
  int ans1=case1["bhopal"];
  unordered_map<string,int>case2=g.dikastra("bhopal");
  int ans2=INT_MAX;
  for(auto c:vec)
  {
      ans2=min(ans2,case1[c.x]+c.cost+case2[c.y]);

  }
  int ans=min(ans1,ans2);
  return ans;

}



//another data  structure DISjoINTset
//disjoint set are the set which nothin common 
//we have to learn 
//find funtion it returen name of set where this element is present
//union it union the set

//we can solve and impliment using the dsu
//the quesiton is finding the cycle in undirected graph
class Graph
{
    public:
    int v;   
    list<pair<int,int>>edges;
    Graph(int b)
    {
        this->v=b;



    }
    void addedge(int x,int y)
    {
        edges.push_back(make_pair(x,y));
    }
    int find_set(int i,int parent[])
    {
        if(parent[i]==-1)
        {
            return i;
        }
        // return find_set(parent[i],parent);
        //    now we have to use path compreesion optimisiton
        //when the find_set call then 
        //we dirctly add the i with its is parrent eache time 
        //this will reduce the time path each time
        return parent[i]=find_set(parent[i],parent);

    }


    // void union_set(int x,int y,int parent[])
    // {
    //     int s1=find_set(x,parent);
    //     int s2=find_set(y,parent);
    //     if(s1!=s2)
    //     {
    //         parent[s1]=s2;
    //     }
    // }

    //we can optimize the union fucntion  alsoe
    //by applying the union rank optimization
    //wehat shoult i do the each set have its rank which means the size of set
    //so we choin two element the smaller rank will join with bigger rank
    void union_set(int x,int y,int parent[],int rank[])
    {
        int s1=find_set(x,parent);
        int s2=find_set(y,parent);
        if(s1!=s2)
        {
            if(rank[s1]>rank[s2])
            {
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
            else{
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
        }
    }
    bool contain_cycle()
    {
        int *parent=new int[v];
        int *rank=new int[v];
        for(int i=0;i<v;i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }
        for(auto p:edges)
        {
            int x=p.first;
            int y=p.second;
            int s1=find_set(x,parent);
            int s2=find_set(y,parent);
            if(s1!=s2)
            {
                union_set(x,y,parent,rank);
            }
            else{
                return true;
            }
        }
        delete [] parent;
        return false;
    }
    


};

class DSU
{
    int v;
    int *parent;
    int *rank;
    public:
    DSU(int x)
    {
        this->v=x;
        rank=new int[v+1];
        parent=new int[v+1];
        for(int i=0;i<=v;i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }
    }
    int find_set(int  i)
    {
        if(parent[i]==-1)
        {
            return i;
        }
        return parent[i]=find_set(parent[i]);//path compressiom
    }
    void union_set(int x,int y)
    {
        int s1=find_set(x);
        int s2=find_set(y);
        if(s1!=s2)
        {
            if(rank[s1]>rank[s2])
            {
                parent[s2]=s1;
                rank[s1]+=rank[s2];
             
            }
            else{
                parent[s1]=s2;
                rank[s2]+=rank[s1];
              
            }
        }
    }
};

//now we learn about the minimum spannig tree
    //defiantion of spanning tree
    //means if n vertices of graph make them tree of n-1 edges
    //and minmum spannig tee is trree having the minimum sum of edges in spanning tree


    //we user kruskals algortihm to fing the miminmum spannning tree
    // apprcoh 
    //1.sort the all edges of graph acocorfing to wight of edges
    //2.join two vertoves if joing weill no made the cyclw
int kruskal_alogrithm(vector<vector<int>>&edges)
{
    //first we will take the input of edges and wegiht
    //the vetor edges conitn the edges between x and y and wight
    //1.step to sort the edges list according to the wieght
    //the edges v[0] is the wieght and v[1] and v[2] is vertices
    DSU g(1000);
    sort(edges.begin(),edges.end());
    int ans=0;
    //2 setep chose the minmum edges of weight joint them if they no tbelong to the same set
    for(auto edge:edges)
    {
        int w=edge[0];
        int x=edge[1];
        int y=edge[2];
        if(g.find_set(x)!=g.find_set(y))
        {
            g.union_set(x,y);
            ans+=w;
        }
    }
    return ans;

}

//--------------------------------------------------------------------------------
//prims algorithm
//MST set set contain the vertices of nodes till now 
//active edge =edges from vertex in MST set to set of vertices
//MST edge =edge that inculde in the mst so far


//algortihm
//start form the vertex start exploring the active edges 
//out of all active edges chosse with the smallest wieght
//and the node y into the mst 
//add the edges into active edges  from y
//now reapet 2 all time agin
class graph_for_prim
{
    vector<pair<int,int>>*l;
    int v;
    public:
    graph_for_prim(int n)
    {
        this->v=n;
        l=new vector<pair<int,int>>[n];

    }
    void addedge(int x,int y,int w)
    {
        l[x].push_back({y,w});
        l[y].push_back({x,w});
    }
    void prims_alogrthim()
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        //visited array that donate the array that contian the nodes which in mst
        bool *visited=new bool[v]{false};
        int ans=0;
        //add the source  into the priorty quue with wieght
        //in the prrioty quue the first eleemnt is wight and 2nd eleemnt is node
        pq.push({0,0});//source in this casae is zero
        while(!pq.empty())
        {
            auto best=pq.top();
            pq.pop();
            int to=best.second;
            int weight=best.first;
            if(visited[to]==true) //if the  node that you reaching is visited means it is in the mst do noting 
            {
                continue;
            }
            ans+=weight;
            visited[to]=true;
            for(auto x:l[to])
            {
                if(visited[x.first]==false)
                {
                    pq.push({x.second,x.first});
                }
            }

        }
    }


};




//shortest algoritthm
//1.single sorce shotyest path
//1;bfs o(v+e)  unwighted graph
//2.dijkastra o(Elog(v))   wighted but edges are postive meand wight should be 0 or positive
//3/bellmon ford o(VE)   graph should be wighted and directed and it handle the case of negative case as well


//belmon ford alogrithm
//approch
//initliaze of vertixes to be infinity
//disatance of soource node =0
//relax all edges v-1 times
// check for  the graph contain negative weight cycle
vector<int> bellmon_ford(int v,int src,vector<vector<int>>&edges)
{
    vector<int>distance(v+1,INT_MAX);
    distance[src]=0;
    for(int i=1;i<=v-1;i++)
    {
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            if(distance[u]!=INT_MAX and distance[u]+w<distance[v])
            {
                distance[v]=distance[u]+w;
            }
        }
    }
    for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            if(distance[u]!=INT_MAX and distance[u]+w<distance[v])
            {
                cout<<"thier is negative cycle\n";
                exit(0);
            }
        }
    return distance;
}

void belmon_ford_input_helper()
{
    int v,m; //v is number of vertices and m is number of edges
    cin>>v>>m;
    vector<vector<int>>edges;//each contain the edges and weight last element of each verctore is weight of edges

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});

    }
    vector<int>distance=bellmon_ford(v,1,edges);
    for(int i=1;i<=v;i++)
    {
        cout<<"distanc of "<<i<<" is "<<distance[i]<<endl;
    }

}

//floyd warshal alogrithm
//it alpgorithm give you all pair shortest path
//the alterante of floyd warshel algo is you can use can be make v times dijasktra time compleit is v*elogV
//this handle negative edges as well
//also detect to negative cycle 
//complity is oV^3
// we can go to v number of faces at each face we ralax the distance 
//in each face go to each cell and relaxing distance
//it is dp baced solution 
//first make the matrix of order v 
//mark the matrix with each nodes distance if it is not their mark as infinty
vector<vector<int>> floyd_warshal(vector<vector<int>>gr)//graph as a input
{
    vector<vector<int>>distance(gr);
    int v=gr.size();
    for(int k=0;k<v;k++)
    {
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(distance[i][j]>distance[i][k]+distance[k][j])
                {
                    distance[i][j]=distance[i][k]+distance[k][j];
                }
            }
        }
    }
      for(int i=0;i<v;i++)
        {
          if(distance[i][i]<0)
          {
              cout<<"negative wight cycle\n";
              exit(0);
          }
        }
        return distance;
}


//hamiltonion cycle 
//is the cycle in which start from any node adn travel from all node back to start node
//this application have one question traveeling salesman problem
//we have to minimize the  hamiltonion cycle
//brute forace 
//a--b--c--d--e
//make all permution find the path of each time cploixty is n!*n
int dist[10][10]={{0,20,42,25},
                    {20,0,30,34},
                    {42,30,0,10,},
                    {25,34,10,0}};
int n=4;
int dp[16][4];
int visted_all=(1<<n)-1;
void intialize_dp()
{
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j]=-1;

        }
    }
}
int travelling_salesman(int mask,int pos)
{
    if(mask==visted_all)
    {
        return dist[pos][0];
    }
    if(dp[mask][pos]!=-1)
    {
        return dp[mask][pos];
    }
    int ans=INT_MAX;
    for(int city=0;city<n;city++)
    {
        if((mask&(1<<city))==0)
        {
            int new_ans=dist[pos][city]+travelling_salesman((mask|(1<<city)),city);
            ans=min(ans,new_ans);
        }
    }
    return dp[mask][pos]= ans;
}



//holiday accomadation solve
class accomadation
{
    int v;
    list<pair<int,int>>*vec;
    public:
    accomadation(int d)
    {
        this->v=d;
        vec=new list<pair<int,int>>[v+1];
    }
    void addedge(int x,int y,int w)
    {
        vec[x].push_back({y,w});
        vec[y].push_back({x,w});
    }
    int dfs_helper(int node,bool *visited,int *count,int &ans)
    {
        visited[node]=true;
        count[node]=1;
        for(auto x:vec[node])
        {
            int nbr=x.first;
            int w=x.second;
            if(visited[nbr]==false)
            {
                count[node]+=dfs_helper(nbr,visited,count,ans);
                int nx=count[nbr];
                int ny=v-nx;
                ans+=min(nx,ny)*2*w;
            }
        }
        return count[node];

    }
    int  dfs_solve_holiday()
    {
        bool *vistited=new bool[v+1]{false};
        int *count=new int[v+1]{0};
        int ans=0;
        dfs_helper(1,vistited,count,ans);
        return ans;
    }
};
int solve_holdiday_accomadation()
{
    int v;
    cin>>v;
    accomadation g(v);
    for(int i=0;i<v-1;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        g.addedge(x,y,w);
    }
    return g.dfs_solve_holiday();


}


//bapartied chceck of the graph
//bapartie  means ti divide the into two set such that all vertices from set 1 to set2 
//tree is alwauys bipartte graph with no cycle is tree

//simple approch is that start from parent mark them one colour and childrenwith different colour
//if the children already visited and and have same colr
bool bipartee_checker(int node,int colour,int *visited,vector<int>*gr,int parent)
{
    visited[node]=colour;
    for(auto nbr:gr[node] )
    {
        if(visited[nbr]==0)
        {
            bool mila=bipartee_checker(nbr,3-colour,visited,gr,node);
            if(mila==false)
            {
                return false;
            }
        }
        else if(nbr!=parent and visited[nbr]==colour)
        {
            return false;
        }
    }
    return true;
}
void solve_bipartee()
{
    int n;
    cin>>n;
    vector<int>gr[n];
    int m;
    cin>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].pb(x);
    }
    //i will use one aray for coliur as a well as viisted also
    int *visited=new int[n]{0};
    //0 means node is not viisted yet 1 measn visted and coloiur is 1 and 2 means vised and coloir 2
    bool ans=bipartee_checker(0,1,visited,gr,-1);//parent 0 lets suppose -1
    if(ans)
    {
        cout<<"yes it can divided inot to set \n";
    }
    else{
        cout<<"it can't divided itnot to part"<<endl;
    }

}

//kosarajus alogriithm
//finding the number of connected components in directed graph
//step one make dfs on enitre graph
//may in first dfs all nodes are visited then dfs call eith all nodes
//when you living the node add to stack
//now trapose te enitre graph meand reverse the edges
//now pop stack eleemen one one by one and make dfs call to transposed graph
//in each dfs you get one connected componenet
//you have to maintin the viisted array type
void solve_kasoraju_helper(int node,vector<int>gr[],bool *visited,stack<int>&s,bool dalna=true)
{
    visited[node]=true;
    if(dalna==false)
    {
        cout<<node<<" ";
    }
    for(auto nbr:gr[node])
    {
        if(visited[nbr]==false)
        {
            solve_kasoraju_helper(nbr,gr,visited,s,dalna);
        }
    }
    if(dalna){
    s.push(node);
    }
    return;

}
// void kosaraju_on_tranpose(int node,vector<int>gr[],bool *visited)
// {
//     visited[node]=true;
//     cout<<node<<" ";
//     for(auto nbr:gr[node])
//     {
//         if(visited[nbr]==false)
//         {
//             kosaraju_on_tranpose(nbr,gr,visited);
//         }
//     }

// }
void kosaraju_alogrithm()
{
    int n;
    cin>>n;
    vector<int>gr[n];
    vector<int>rev[n];
    int m;
    cin>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);//directed graph 
        rev[y].push_back(x);//reverse of the graph
    }
    bool *visted=new bool[n]{false};
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        if(visted[i]==false)
        {
            solve_kasoraju_helper(i,gr,visted,s,true); //i will use same helper funciton for both dfs using the operting bu variabel dalna
        }
    }
    for(int i=0;i<n;i++)
    {
        visted[i]=false;
    }
    int ans=0;
    while(!s.empty())
    {
        int node=s.top();
        s.pop();
        if(visted[node]==true)
        {
            continue;
        }
        solve_kasoraju_helper(node,rev,visted,s,false);
        cout<<endl;
        ans++;
        
    }
    cout<<endl<<endl;
    cout<<"thier are "<<ans<<" connected component in the graph"<<endl;
    return;

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
kosaraju_alogrithm();

    return 0;
}