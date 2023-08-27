//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
// #define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main(){ _
	int tt; cin >> tt;
    while(tt--){
        int n, k; cin >> n >> k;
        vector<ll> f(n), d(n);
        for(auto &i: f) cin >> i;
        for(auto &i: d) cin >> i;
        

        int best = 0;
        for(int i = 0; i < n; i++){
            // Candidates
            
            int MAX = 3*n + 10;
            tuple<ll, int, bool> ph[MAX];
            ll px = d[i] * f[i];
            
            int idx = 0;
            for(int j = 0; j < n; j++){
                if(px/f[j] > 0){
                    ph[idx] = {px/f[j] * f[j], j, 0}; // Chão do Ótimo
                    idx++;
                }
                ph[idx] = {(px/f[j] + 1) * f[j], j, 0}; // ~Teto do Ótimo
                idx++;
                ph[idx] = {d[j] * f[j], j, 1}; // Não Muda
                idx++;
            }

            sort(ph, ph+idx);

            // Two Pointers
            vector<int> count_uni(n);
            vector<int> count_unc(n);
            int uni = 0;
            int unc = 0;

            for(int l = 0, r = 0; r < idx; r++){
                auto [phr, idxr, uncr] = ph[r];
                
                // Make it Valid
                auto [phl, idxl, uncl] = ph[l];
                
                while(phr - phl > k){
                    count_uni[idxl]--;
                    if(count_uni[idxl] == 0)
                        uni--;

                    if(uncl){
                        count_unc[idxl]--;
                        if(count_unc[idxl] == 0)
                            unc--;
                    }

                    l++;
                    tie(phl, idxl, uncl) = ph[l];
                }
                
                // Add
                if(count_uni[idxr] == 0)
                    uni++;
                count_uni[idxr]++;
                if(uncr){
                    if(count_unc[idxr] == 0)
                        unc++;
                    count_unc[idxr]++;
                }
                if(uni == n) best = max(best, unc);
            }

        }    
        cout << n - best << endl;
    }
    exit(0);
}
