// Merge Sort
//
// Complexities:
// Time: O(n log(n))
// Space O(n) 

long long merge_sort(int l, int r, vector<int> &t) {
    if (l >= r) return 0;
    int m = (l+r)/2;
    auto ans = merge_sort(l, m, t) + merge_sort(m+1, r, t);
    static vector<int> aux;
    if (aux.size() != t.size()) aux.resize(t.size());
    for (int i = l; i <= r; i++) aux[i] = t[i];

    int i_l = l, i_r = m+1, i = l;
    auto move_l = [&](){ t[i++] = aux[i_l++]; };
    auto move_r = [&](){ t[i++] = aux[i_r++]; };

    while (i <= r) {
        if (i_l > m) move_r();
        else if (i_r > r) move_l();
        else {
            if (aux[i_l] <= aux[i_r]) move_l();
            else move_r(), ans += m - i_l + 1;
        }
    }
    return ans;
}

// Inversions to turn r into l

template<typename T> ll inv_count(vector<T> &r, vector<T> &l) {
    int n = l.size();
    map<T, int> occ;
    map<pair<T, int>, int> rk;
    for (int i = 0; i < n; i++) rk[make_pair(l[i], occ[l[i]]++)] = i;
    occ.clear();
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = rk[make_pair(r[i], occ[r[i]]++)];
    return merge_sort(0, n-1, v);
}
