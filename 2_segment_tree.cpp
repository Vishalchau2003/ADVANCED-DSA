#include<bits/stdc++.h>
using namespace std;

int seg[4 * 100];   // safe size
int arr[100];

void build(int ind, int low, int high) {

    if (low == high) {
        seg[ind] = arr[low];
        return;
    }

    int mid = (low + high) / 2;

    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);   // FIX

    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int query(int idx, int low, int high, int l, int r) {

    // complete overlap
    if (low >= l && high <= r) {
        return seg[idx];
    }

    // no overlap
    if (high < l || low > r) {
        return INT_MIN;
    }

    // partial overlap
    int mid = (low + high) / 2;

    int left = query(2 * idx + 1, low, mid, l, r);
    int right = query(2 * idx + 2, mid + 1, high, l, r);

    return max(left, right);
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(0, 0, n - 1);

    int q;
    cin >> q;   // number of queries

    while (q--) {
        int l, r;
        cin >> l >> r;

        cout << query(0, 0, n - 1, l, r) << endl;
    }

    return 0;
}
