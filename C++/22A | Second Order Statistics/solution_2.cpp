#include <iostream>
#include <algorithm>
 
#define INF 1000000007
 
template <class T>
class Splay_Tree
{
    int sz;
    struct Node
    {
        T value;
        Node *left, *right, *parent;
 
        Node(const T &val = T(), Node *l = nullptr, Node *r = nullptr, Node *p = nullptr)
        : value(val), left(l), right(r), parent(p) {}
 
    } *root;
 
    void left_rotate(Node *p)
    {
        Node *g = p->parent;
        Node *x = p->right;
        if(g)
        {
            if(g->left == p)
                g->left = x;
            else
                g->right = x;
        }
        Node *b = x->left;
        if(b)
            b->parent = p;
        p->right = b;
        x->parent = g;
        p->parent = x;
        x->left = p;
    }
 
    void right_rotate(Node *p)
    {
        Node *g = p->parent;
        Node *x = p->left;
        if(g)
        {
            if(g->left == p)
                g->left = x;
            else
                g->right = x;
        }
        Node *b = x->right;
        if(b)
            b->parent = p;
        p->left = b;
        x->parent = g;
        p->parent = x;
        x->right = p;
    }
 
    void splay(Node *x)
    {
        while(x->parent)
        {
            Node *p = x->parent;
            Node *g = p->parent;
            if(!g)
            {
                if(p->left == x)
                    right_rotate(p);
                else
                    left_rotate(p);
            }
            else if(g->left == p && p->left == x)
            {
                right_rotate(g);
                right_rotate(p);
            }
            else if(g->right == p && p->right == x)
            {
                left_rotate(g);
                left_rotate(p);
            }
            else if(g->left == p && p->right == x)
            {
                left_rotate(p);
                right_rotate(g);
            }
            else
            {
                right_rotate(p);
                left_rotate(g);
            }
        }
        root = x;
    }
 
    Node *find_nearest(const T &x) const
    {
        Node *cur = root;
        Node *prev = nullptr;
        while(cur)
        {
            prev = cur;
            if(x < cur->value)
                cur = cur->left;
            else if(x > cur->value)
                cur = cur->right;
            else
                return cur;
        }
        return prev;
    }
 
    Node *find_parent(const T &x) const
    {
        Node *cur = root;
        Node *prev = nullptr;
        while(cur)
        {
            prev = cur;
            if(x < cur->value)
                cur = cur->left;
            else
                cur = cur->right;
        }
        return prev;
    }
 
    Node *find_max(Node *rt) const
    {
        Node *cur = rt;
        while(cur->right)
            cur = cur->right;
        return cur;
    }
 
    Node *find_max() const
    {
        return find_max(root);
    }
 
    Node *find_min(Node *rt) const
    {
        Node *cur = rt;
        while(cur->left)
            cur = cur->left;
        return cur;
    }
 
    void delete_tree(Node *cur)
    {
        if(!cur)
            return ;
        delete_tree(cur->left);
        delete_tree(cur->right);
        delete cur;
        cur = nullptr;
    }
 
    void join(Node *left, Node *right)
    {
        if(!left)
        {
            root = right;
        }
        else if(!right)
        {
            root = left;
        }
        else
        {
            Node *found = find_max(left);
            splay(found);
            found->right = right;
            if(right)
                right->parent = found;
        }
    }
 
public:
 
    Splay_Tree() : root(nullptr), sz(0) {}
 
    ~Splay_Tree() { delete_tree(root); }
 
    inline int size() const { return sz; }
 
    inline bool empty() const { return !sz; };
 
    T find_min() const
    {
        Node *found = find_min(root);
        if(found)
            return found->value;
        return T(INF);
    }
 
    void insert(const T &x)
    {
        Node *node = new Node(x);
 
        if(!sz)
        {
            root = node;
            sz++;
            return ;
        }
 
        Node *found = find_parent(x);
 
        node->parent = found;
        if(x < found->value)
            found->left = node;
        else
            found->right = node;
 
        splay(node);
        sz++;
    }
 
    void erase(const T &x)
    {
        if(!sz)
            return ;
 
        Node *found = find_nearest(x);
        splay(found);
        if(found->value != x)
            return ;
 
        Node *left = found->left;
        Node *right = found->right;
        delete found;
        if(left)
            left->parent = nullptr;
        if(right)
            right->parent = nullptr;
 
        join(left,right);
 
        sz--;
    }
 
};
 
int main()
{
    int n, a;
    std::cin >> n;
    Splay_Tree<int> spt;
    for(int i=0; i<n; i++)
    {
        std::cin >> a;
        spt.insert(a);
    }
    bool found = false;
    int min_val = spt.find_min(), cur_min;
    while(!spt.empty() && !found)
    {
        cur_min = spt.find_min();
        if(cur_min != INF && cur_min != min_val)
            found = true;
        spt.erase(cur_min);
    }
    
    if(found)
        std::cout << cur_min << std::endl;
    else 
        std::cout << "NO" << std::endl;
    
    return 0;
}