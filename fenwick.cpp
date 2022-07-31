class FenwickTree {
    vi ft;
 
public:    
    FenwickTree(int n) {
        ft.assign(n + 1, 0);
    }
 
    ll rsq(int b) { // sum of freq. of pos 1 to pos b
        ll sum = 0;
        while (b > 0) {
            sum += ft[b];
            b -= b & (-b);
        }
        return sum;
    }
    
    ll rsq(int a, int b) {  // sum of freq. of pos a to pos b
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }
    
    void add(int k, ll v) { // add freq. v to pos k
        while (k < ft.size()) {
            ft[k] += v;
            k += k & (-k);
        }
    }
 
    int find(int k) {   // kth order statistic
        int l = 1, r = ft.size() - 1;
        int pos = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (rsq(mid) >= k) {
                pos = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return pos;
    }
};
