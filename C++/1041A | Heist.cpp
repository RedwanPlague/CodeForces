#include <iostream>
 
using namespace std;
 
template < class T, typename Comparator = std::less<T> >
class binomial_heap
{
    int sz;
    Comparator comp;
 
    struct binomial_tree
    {
        T value;
        int order;
        binomial_tree *first, *last, *next;
 
        binomial_tree(const T x = T())
        : value(x), order(0), first(0), last(0), next(0) {}
 
        binomial_tree(const binomial_tree &obj)
        : value(obj.value), order(obj.order), next(0)
        {
            if(obj.order)
            {
                this->first = new binomial_tree(*obj.first);
                binomial_tree *cur = this->first;
                binomial_tree *obj_cur = obj.first->next;
 
                while(obj_cur)
                {
                    cur->next = new binomial_tree(*obj_cur);
                    cur = cur->next;
                    obj_cur = obj_cur->next;
                }
                this->last = cur;
            }
        }
 
        ~binomial_tree()
        {
            delete_tree();
        }
 
        void delete_tree()
        {
            binomial_tree *nxt, *cur = first;
            while(cur)
            {
                nxt = cur->next;
                delete cur;
                cur = nxt;
            }
        }
 
        // empties obj
        void unite(binomial_tree *obj)
        {
            next = obj->next = 0; // separating them from the chain
            if(!last)
            {
                first = last = obj;
            }
            else
            {
                last->next = obj;
                last = obj;
            }
            order++;
            obj = 0;
        }
 
    }
    *start;
 
public:
 
    binomial_heap() : sz(0), start(0) {}
 
    binomial_heap(const binomial_heap &obj)
    : sz(obj.sz)
    {
        if(obj.sz)
        {
            this->start = new binomial_tree(*obj.start);
            binomial_tree *cur = this->start;
            binomial_tree *obj_cur = obj.start->next;
 
            while(obj_cur)
            {
                cur->next = new binomial_tree(*obj_cur);
                cur = cur->next;
                obj_cur = obj_cur->next;
            }
        }
    }
 
    ~binomial_heap()
    {
        binomial_tree *nxt, *cur = start;
        while(cur)
        {
            nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }
 
    inline int size() { return sz; }
 
    inline bool empty() { return !sz; }
 
    // empties obj
    void merge(binomial_heap &obj)
    {
        if(!obj.sz)
            return ;
 
        if(!this->sz)
        {
            this->sz = obj.sz;
            this->start = obj.start;
            obj.sz = 0;
            obj.start = 0;
            return ;
        }
 
        binomial_tree *sum, *carry = 0, *t1, *t2, *cur, *nxt, *temp;
        t1 = this->start;
        t2 = obj.start;
        this->start = 0;
        obj.start = 0;
        this->sz += obj.sz;
        obj.sz = 0;
        while(t1 || t2)
        {
            if(carry && (!t1 || (carry->order < t1->order)) && (!t2 || (carry->order < t2->order)))
            {
                sum = carry;
                carry = 0;
            }
            else if(!t2 || (t1 && t1->order < t2->order))
            {
                if(carry)
                {
                    sum = 0;
                    nxt = t1->next;
                    if(comp(t1->value,carry->value))
                    {
                        temp = carry;
                        carry = t1;
                        t1 = temp;
                    }
                    carry->unite(t1);
                    t1 = nxt;
                }
                else
                {
                    sum = t1;
                    t1 = t1->next;
                }
            }
            else if(!t1 || (t2 && t2->order < t1->order))
            {
                if(carry)
                {
                    sum = 0;
                    nxt = t2->next;
                    if(comp(t2->value,carry->value))
                    {
                        temp = carry;
                        carry = t2;
                        t2 = temp;
                    }
                    carry->unite(t2);
                    t2 = nxt;
                }
                else
                {
                    sum = t2;
                    t2 = t2->next;
                }
            }
            else
            {
                if(carry)
                {
                    nxt = t1->next;
                    if(comp(t1->value,carry->value))
                    {
                        temp = carry;
                        carry = t1;
                        t1 = temp;
                    }
                    carry->unite(t1);
                    t1 = nxt;
                    sum = t2;
                    t2 = t2->next;
                }
                else
                {
                    sum = 0;
                    if(comp(t1->value,t2->value))
                    {
                        carry = t1;
                        t1 = t1->next;
                        nxt = t2->next;
                        carry->unite(t2);
                        t2 = nxt;
                    }
                    else
                    {
                        carry = t2;
                        t2 = t2->next;
                        nxt = t1->next;
                        carry->unite(t1);
                        t1 = nxt;
                    }
                }
            }
            if(sum)
            {
                if(!start)
                {
                    start = sum;
                    cur = start;
                }
                else
                {
                    cur->next = sum;
                    cur = cur->next;
                }
            }
        }
        if(carry)
        {
            if(!start)
                start = carry;
            else
                cur->next = carry;
        }
    }
 
    void insert(const T x)
    {
        binomial_heap<T,Comparator> temp;
        temp.sz = 1;
        temp.start = new binomial_tree(x);
        this->merge(temp);
    }
 
    T top()
    {
        if(!sz)
        {
            std::cout << "Invalid access, heap empty\n";
            return T();
        }
        binomial_tree *found = start, *cur = start->next;
        while(cur)
        {
            if(comp(cur->value,found->value))
                found = cur;
            cur = cur->next;
        }
        return found->value;
    }
 
    T extract()
    {
        if(!sz)
        {
            std::cout << "Invalid extract, heap empty\n";
            return T();
        }
        T ret;
        binomial_tree *found = start, *fprev = 0, *prev = start, *cur = start->next;
        while(cur)
        {
            if(comp(cur->value,found->value))
            {
                found = cur;
                fprev = prev;
            }
            prev = cur;
            cur = cur->next;
        }
        ret = found->value;
 
        if(!fprev) // disconnect found from the chain
            start = found->next;
        else
            fprev->next = found->next;
 
        this->sz -= (1<<(found->order));
 
        if(found->order)
        {
            binomial_heap<T,Comparator> temp;
            temp.sz = (1<<(found->order))-1;
            temp.start = found->first;
            this->merge(temp);
        }
 
        found->first = 0;
        delete found;
 
        return ret;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, a;
    cin >> n;
    
    if(n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    
    binomial_heap<int> bh;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        bh.insert(a);
    }
    
    int mn = bh.extract();
    
    while(bh.size()>1)
        bh.extract();
        
    int mx = bh.extract();
    
    cout << mx - mn + 1 - n << endl;
    
    return 0;
}