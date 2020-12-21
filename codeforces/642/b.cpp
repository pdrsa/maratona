#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		vector<int> a(n);
		vector<int> b(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		
		while(k--){
			int maior = 0, mai;
			int menor = INF, mei;
			for (int i = 0; i < n; i++){
				if (b[i] > maior){
					maior = b[i];
					mai = i;
				}
			}

			for (int i = 0; i < n; i++){
				if (a[i] < menor){
					menor = a[i];
					mei = i;
				}
			}
			
			if (maior > menor){
				a[mei] = maior;
				b[mai] = menor;
			}
		}

		int ans = 0;
		for (auto u: a) ans += u;

		cout << ans << endl;
	}
	exit(0);
}
