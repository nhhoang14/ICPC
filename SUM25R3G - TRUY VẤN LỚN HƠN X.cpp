#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<vector<int>> tree;

    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = {arr[start]};
        } else {
            int mid = (start + end) / 2;
            build(arr, node * 2, start, mid);
            build(arr, node * 2 + 1, mid + 1, end);
            tree[node].resize(tree[node*2].size() + tree[node*2+1].size());
            merge(tree[node*2].begin(), tree[node*2].end(),
                  tree[node*2+1].begin(), tree[node*2+1].end(),
                  tree[node].begin());
        }
    }

    void update(int node, int start, int end, int idx, int oldVal, int newVal) {
        auto it = lower_bound(tree[node].begin(), tree[node].end(), oldVal);
        if (it != tree[node].end() && *it == oldVal) tree[node].erase(it);
        tree[node].insert(lower_bound(tree[node].begin(), tree[node].end(), newVal), newVal);

        if (start != end) {
            int mid = (start + end) / 2;
            if (idx <= mid) update(node * 2, start, mid, idx, oldVal, newVal);
            else update(node * 2 + 1, mid + 1, end, idx, oldVal, newVal);
        }
    }

    int query(int node, int start, int end, int l, int r, int x) {
        if (r < start || end < l) return -1;
        if (l <= start && end <= r) {
            auto it = upper_bound(tree[node].begin(), tree[node].end(), x);
            return (it == tree[node].end()) ? -1 : *it;
        }
        int mid = (start + end) / 2;
        int left_res = query(node * 2, start, mid, l, r, x);
        int right_res = query(node * 2 + 1, mid + 1, end, l, r, x);
        if (left_res == -1) return right_res;
        if (right_res == -1) return left_res;
        return min(left_res, right_res);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    SegmentTree st(a);

    while (m--) {
        int status;
        cin >> status;
        if (status == 1) {
            int idx, val;
            cin >> idx >> val;
            idx--;
            st.update(1, 0, n - 1, idx, a[idx], val);
            a[idx] = val;
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            l--; r--;
            cout << st.query(1, 0, n - 1, l, r, x) << "\n";
        }
    }
    return 0;
}
