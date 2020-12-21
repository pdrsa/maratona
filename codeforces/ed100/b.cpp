//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		vector<int> a(n);
		for(int i= 0; i < n; i++) cin >> a[i];
		
		vector<int> b1(n);
			vector<int> b2(n);
		
		for(int i = 0; i < n; i++){
			if(i % 2 == 1) b1[i] = 1;
			else b1[i] = a[i];

			if(i % 2 == 0) b2[i] = 1;
			else b2[i] = a[i];
		}

		ll s1 = 0, s2 = 0, s3 = 0;;
		for(int i = 0; i < n; i++){
			s1 += abs(b1[i] - a[i]);
			s2 += abs(b2[i] - a[i]);
			s3 += a[i];
		}
		
		//cout << s1 << " " << s2 << " " << s3 << endl;
		
		if(s1 > s2){
			for(auto u: b2) cout << u << " ";
			cout << endl;
		}
		else{
			for(auto u: b1) cout << u << " ";
			cout << endl;
		}
	}
	exit(0);
}
