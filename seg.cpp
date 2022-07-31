#define ll long long
struct SegTree {
      vector<ll> sum;
      vector<int> mini;
      vector<int> maxa;
      int size;
      void build(int n) {
            sum.resize(4 * n);
            mini.resize(4 * n, INT_MAX);
            maxa.resize(4 * n, INT_MIN);
            size = n;
      }
      void assign(vector<ll>  &a, int node = 1, int l = 0, int r = -1) {
            if(r < 0)
                  r = size - 1;
            if (l == r) {
                  sum[node] = a[l];
                  mini[node] = a[l];
                  maxa[node] = a[l];
                  return;
            }
            int mid = (l + r) / 2;
            assign(a, 2 * node, l, mid);
            assign(a, 2 * node + 1, mid + 1, r);
            sum[node] = sum[2 * node] + sum[2 * node + 1];
            mini[node] = min(mini[2 * node], mini[2 * node + 1]);
            maxa[node] = max(maxa[2 * node], maxa[2 * node + 1]);
      }
      void update(int ind, int val, int l = 0, int r = -1, int node = 1) {
            if(r < 0)
                  r = size - 1;
            if (l == r) {
                  sum[node] = val;
                  mini[node] = val;
                  maxa[node] = val;
                  return ;
            }
            int mid = (l + r) / 2;
            if (mid < ind)
                  update(ind, val, mid + 1, r, 2 * node + 1);
            else
                  update(ind, val, l, mid, 2 * node);
            sum[node] = sum[2 * node] + sum[2 * node + 1];
            mini[node] = min(mini[2 * node], mini[2 * node + 1]);
            maxa[node] = max(maxa[2 * node], maxa[2 * node + 1]);
      }
      ll query(int lx, int rx, int l = 0, int r = -1, int node = 1) {
            if(r < 0)
                  r = size - 1;
            if (l > rx || r < lx) {
                  return 0;
            }
            if (l >= lx && r <= rx) {
                  return sum[node];
            }
            int mid = (l + r) / 2;
            return (ll)query(lx, rx, l, mid, 2 * node) + (ll)query(lx, rx, mid + 1, r, 2 * node + 1);
      }
      int minimum(int lx, int rx, int l = 0, int r = -1, int node = 1) {
            if(r < 0)
                  r = size - 1;
            if (l > rx || r < lx) {
                  return INT_MAX;
            }
            if (l >= lx && r <= rx) {
                  return mini[node];
            }
            int mid = (l + r) / 2;
            return min(minimum(lx, rx, l, mid, 2 * node), minimum(lx, rx, mid + 1, r, 2 * node + 1));
      }
      int maximum(int lx, int rx, int l = 0, int r = -1, int node = 1) {
            if(r < 0)
                  r = size - 1;
            if (l > rx || r < lx) {
                  return INT_MIN;
            }
            if (l >= lx && r <= rx) {
                  return maxa[node];
            }
            int mid = (l + r) / 2;
            return max(maximum(lx, rx, l, mid, 2 * node), maximum(lx, rx, mid + 1, r, 2 * node + 1));
      }
};
