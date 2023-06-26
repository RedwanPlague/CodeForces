#include <iostream>
 
using namespace std;
 
typedef long long ll;
 
const int MX = 100005;
const ll INF = (1LL<<62);
 
struct Node
{
    int id;
    ll dist;
    Node() {}
    Node(int idx, ll dst) : id(idx), dist(dst) {}
    bool operator<(const Node &other) const
    {
        return (dist > other.dist);
    }
};
 
template <class T>
class LinkedList
{
    T *ar;
    int length, capacity;
 
public:
 
    LinkedList()
    {
        capacity = 1;
        ar = new T[capacity];
        length = 0;
    }
 
    LinkedList(int sz)
    {
        length = capacity = sz;
        ar = new T[capacity];
    }
 
    ~LinkedList() { delete[] ar; }
 
    void add(T value)
    {
        if(length == capacity)
        {
            capacity *= 2;
            if(capacity > MX)
                capacity = MX;
            T *temp = new T[capacity];
            for(int i=0; i<length; i++)
                temp[i] = ar[i];
            delete[] ar;
            ar = temp;
        }
        ar[length++] = value;
    }
 
    inline int size() const { return length; }
 
    T& operator[](const int idx) const
    {
        if(idx >= length)
        {
            cout << "Invalid Access at " << idx << ", length only " << length << " ";
            return ar[0];
        }
        return ar[idx];
    }
 
};
 
template <class T>
class Heap
{
    T *a;
    int *pos;
    int capacity, len;
public:
 
    Heap()
    {
        capacity = 4;
        a = new T[capacity+1];
        pos = new int[capacity+1];
        len = 0;
    }
 
    Heap(T *ar, int n)
    {
        capacity = n + 1;
        a = new T[capacity+1];
        pos = new int[capacity+1];
        len = n;
        for(int i=1; i<=n; i++)
        {
            a[i] = ar[i-1];
            pos[i] = i;
        }
        for(int i=n/2; i>=1; i--)
            sift_down(i);
    }
 
    ~Heap() { delete[] a; delete[] pos; }
    inline int size() const { return len; }
    inline bool empty() const { return !len; }
 
    void sift_down(int idx)
    {
        int left = idx<<1;
        int right = left+1;
        int mx = idx;
        if(left <= len && a[mx] < a[left])
            mx = left;
        if(right <= len && a[mx] < a[right])
            mx = right;
        if(mx != idx)
        {
            swap(a[idx], a[mx]);
            pos[a[idx].id] = idx;
            pos[a[mx].id] = mx;
            sift_down(mx);
        }
    }
 
    void sift_up(int idx)
    {
        while(idx > 1 && a[idx/2] < a[idx])
        {
            swap(a[idx], a[idx/2]);
            pos[a[idx].id] = idx;
            pos[a[idx/2].id] = idx/2;
            idx /= 2;
        }
    }
 
    inline T get_front() const { return a[1]; }
 
    void delete_front()
    {
        pos[a[1].id] = -1;
        a[1] = a[len];
        pos[a[1].id] = 1;
        len--;
        sift_down(1);
    }
 
    bool decrease(int idx, ll new_dist)
    {
        idx = pos[idx];
        if(idx == -1)
            return false;
        ll prev = a[idx].dist;
        if(new_dist < prev)
        {
            //cout << "changing " << a[idx].id << " to " << new_dist << "\n";
            a[idx].dist = new_dist;
            sift_up(idx);
            return true;
        }
 
        return false;
    }
};
 
void dijkstra(const int src, const LinkedList< LinkedList<Node> > &adj, ll *dist, int *par)
{
    int n = adj.size()-1;
    Node *ar = new Node[n];
    for(int i=0; i<n; i++)
    {
        ar[i].id = i+1;
        ar[i].dist = dist[i+1] = INF;
        par[i+1] = -1;
    }
    ar[src-1].dist = dist[src] = 0;
    Heap<Node> que(ar,n);
    while(!que.empty())
    {
        Node u = que.get_front();
        que.delete_front();
        //cout << u.id << " ber hoise\n";
        dist[u.id] = u.dist;
        for(int i=0; i<adj[u.id].size(); i++)
        {
            Node v = adj[u.id][i];
            //cout << v.id << " paisi\n";
            bool change = que.decrease(v.id, dist[u.id] + v.dist);
            if(change)
                par[v.id] = u.id;
        }
    }
}
 
void path_print(int dest, const int *par)
{
    LinkedList<int> path;
    while(dest != -1)
    {
        path.add(dest);
        dest = par[dest];
    }
    for(int i=path.size()-1; i>0; i--)
    {
        cout << path[i] << " ";
    }
    cout << path[0] << endl;
}
 
int main()
{
    int n, m; // n = number of nodes, m = number of edges
    int u, v;
    ll w;
 
    cin >> n >> m;
 
    if(m == 0)
    {
        cout << -1 << endl;
        return 0;
    }
 
    LinkedList< LinkedList<Node> > adj(n+1);
    for(int i=0; i<m; i++)
    {
        cin >> u >> v >> w;
        adj[u].add(Node(v,w));
        adj[v].add(Node(u,w));
    }
 
    ll *dist = new ll[n+1];
    int *parent = new int[n+1];
 
    dijkstra(1, adj, dist, parent);
 
    /*for(int i=1; i<=n; i++)
    {
        cout << i << " -> " << dist[i] << "\n";
    }
    cout << "\n";
    for(int i=1; i<=n; i++)
    {
        cout << i << " -> " << parent[i] << "\n";
    }*/
 
    if(dist[n] == INF)
    {
        cout << -1 << endl;
    }
    else
        path_print(n, parent);
 
    return 0;
}