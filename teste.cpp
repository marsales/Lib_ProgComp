#include <bits/stdc++.h>
using namespace std;

// ========================== SEGMENT TREE ==========================
struct SegmentTree {
    int n;
    vector<long long> tree;

    SegmentTree(const vector<int>& v) {
        n = v.size();
        tree.resize(4 * n);
        build(v, 1, 0, n - 1);
    }

    void build(const vector<int>& v, int node, int l, int r) {
        if (l == r) {
            tree[node] = v[l];
            return;
        }
        int mid = (l + r) / 2;
        build(v, 2 * node, l, mid);
        build(v, 2 * node + 1, mid + 1, r);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0; // fora do intervalo
        if (ql <= l && r <= qr) return tree[node]; // totalmente dentro
        int mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr) +
               query(2 * node + 1, mid + 1, r, ql, qr);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2 * node, l, mid, idx, val);
        else update(2 * node + 1, mid + 1, r, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    long long query(int l, int r) { return query(1, 0, n - 1, l, r); }
    void update(int idx, int val) { update(1, 0, n - 1, idx, val); }
};


// ================================ DSU ================================
struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n+1);
        size.assign(n+1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false; // já estão no mesmo conjunto
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};



// ==================================== FENWICK ====================================
template <class T>
struct Fenwick {
    int n; vector<T> bit; // 1-indexed
    Fenwick() {}
    explicit Fenwick(int n): n(n), bit(n+1, T{}) {}
    explicit Fenwick(const vector<T>& a): n((int)a.size()), bit(n+1, T{}) {
        for (int i = 1; i <= n; ++i) {
            bit[i] += a[i-1];
            int j = i + (i & -i);
            if (j <= n) bit[j] += bit[i];
        }
    }
    void add(int i, T delta) { // i in [1..n]
        for (; i <= n; i += i & -i) bit[i] += delta;
    }
    T sumPrefix(int i) const {
        T r = T{};
        for (; i > 0; i -= i & -i) r += bit[i];
        return r;
    }
    T sumRange(int l, int r) const {
        if (l > r) return T{};
        return sumPrefix(r) - sumPrefix(l-1);
    }
    // menor idx com soma prefixo >= k (freqs >= 0)
    int kth(T k) const {
        int idx = 0, p = 1;
        while ((p<<1) <= n) p <<= 1;
        for (int step = p; step; step >>= 1) {
            int nxt = idx + step;
            if (nxt <= n && bit[nxt] < k) { k -= bit[nxt]; idx = nxt; }
        }
        return idx + 1;
    }
};
