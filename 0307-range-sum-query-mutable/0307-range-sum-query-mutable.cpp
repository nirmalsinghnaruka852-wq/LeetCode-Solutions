using vi = vector<int>;

class NumArray {
public:
    vi tree;
    int n;

    int build(int index, int left, int right, vi& arr) {
        if (left == right)
            return tree[index] = arr[left];

        int mid = left + (right - left) / 2;

        return tree[index] =
            build(index * 2 + 1, left, mid, arr) +
            build(index * 2 + 2, mid + 1, right, arr);
    }

    int query(int index, int left, int right, int ql, int qr) {
        if (right < ql || left > qr)
            return 0;

        if (ql <= left && right <= qr)
            return tree[index];

        int mid = left + (right - left) / 2;

        return query(index * 2 + 1, left, mid, ql, qr) +
               query(index * 2 + 2, mid + 1, right, ql, qr);
    }

    int valueUpdate(int index, int left, int right, int index2, int value) {
        if (left == right)
            return tree[index] = value;

        int mid = left + (right - left) / 2;

        if (index2 <= mid)
            valueUpdate(index * 2 + 1, left, mid, index2, value);
        else
            valueUpdate(index * 2 + 2, mid + 1, right, index2, value);

        return tree[index] =
            tree[index * 2 + 1] + tree[index * 2 + 2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n, 0);
        build(0, 0, n - 1, nums);
    }

    void update(int index, int val) {
        valueUpdate(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};