#include <bits/stdc++.h>

using namespace std;

struct SegTree{
    long long size;
    vector<long long> val;
    
    long long NEUTRAL_ELEMENT = 0;

    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        val.assign(2*size, 0LL);
    }
 
    long long merge(long long a, long long b){
        return a + b;
    }
 
    void set(int i, long long v, int x, int lx, int rx){
        if (rx-lx == 1){
            val[x] = v;
            return;
        }
 
        int m = (lx+rx)/2;

        if (i < m){
            set(i, v, (x*2)+1, lx, m);
        }else{
            set(i, v, (x*2)+2, m, rx);
        }

        val[x] = merge(val[(x*2)+1], val[(x*2)+2]);
    }
 
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }

    long long query(int l, int r, int x, int lx, int rx){
        if (min(r, rx) - max(l, lx) <= 0){
            return NEUTRAL_ELEMENT;
        }
        else if (lx >= l && rx <= r){
            return val[x];
        }
        int m = (lx + rx) / 2;
        return merge(query(l, r, (x*2)+1, lx, m), query(l, r, (x*2)+2, m, rx));
    }
 
    long long query(int l, int r){
        return query(l, r, 0, 0, size);
    }
};


void solve(){
    int n;
    cin >> n;

    vector<vector<int>> a(2*n);
    for(int i{}; i < n; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        if (t < f) swap(f, t);
        a[f].push_back(t);
    }

    SegTree st;
    st.init(2*n);

    long long total = 0;
    for(int i{}; i < 2*n; i++){
        st.set(i, 0);
        for(auto& j : a[i]){
            total += st.query(0, j);
        }
        for(auto& j : a[i]){
            st.set(j, st.query(j, j+1) + 1);
        }
    }

    cout << total << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
