//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define t3 tuple<int,int,int>

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<t3> a(n), z(n);
		
		for(int i = 0; i < n; i++){
			int h, w; cin >> h >> w;
			z[i] = {h,w,i};
		}
		
		a = z;
		sort(a.begin(), a.end());
		for(int i = 1; i < n; i++){
			auto[p1,p2,p3]     = a[i-1];
			auto &[a1, a2, a3] = a[i];

			if(p2 < a2){
				a2 = p2;
				a3 = p3;
			}
		}

		for(auto [h, w, act]: z){
			int ans = -1;

			for(int tttt = 0; tttt < 2; tttt++){
				t3 search = {h, -INF, -INF};
				int i = lower_bound(a.begin(), a.end(), search) - a.begin();
				
				if(i > 0){
	
					auto[hf, wf, idx] = a[i-1];
					if(wf < w){
						ans = idx + 1;
						break;
					}
				}
				
				swap(h,w);
			}

			cout << ans << " ";
		}

		cout << endl;
	}
	exit(0);
}
