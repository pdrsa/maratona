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
		
		if(n == 2){
			if(a[0] > a[1]) cout << a[0] << " 1" << endl;
			else cout << "1 " << a[1] << endl;
			continue;
		}

		// Try1
		vector<int> b1(n), b2(n);
		
		int mdc, mmc;
		for(int i = 0; i < n; i += 3){
			if(i + 2 < n){
				b1[i] = a[i]; b1[i+2] = a[i+2];
				mdc = __gcd(a[i], a[i+2]);
				mmc = a[i] * a[i+2] / mdc;
				if(abs(a[i+1] - mdc) <= abs(a[i+1] - mmc)) b1[i+1] = mdc;
				else b1[i+1] = mmc;
			}

			else{
				if(i != n - 1){
					b1[i+1] = a[i+1];
					mdc = __gcd(a[i+1], a[i-1]);
					mmc = a[i+1] * a[i-1] / mdc;
					if(abs(a[i] - mdc) <= abs(a[i] - mmc)) b1[i] = mdc;
					else b1[i] = mmc;
				}

				else{
					mdc = __gcd(a[i], a[i-1]);
					mmc = a[i] * a[i-1] / mdc;
					if(abs(a[i] - mdc) <= abs(a[i] - mmc)) b1[i] = mdc;
					else b1[i] = mmc;
				}
			}
		}

		// Try2
		
		mdc = __gcd(a[0], a[1]);
		mmc = a[0] * a[1] / mdc;
		
		if(abs(a[0] - mdc) <= abs(a[0] - mmc)) b2[0] = mdc;
		else b2[0] = mmc;

		for(int i = 1; i < n; i += 3){
			if(i + 2 < n){
				b2[i] = a[i]; b2[i+2] = a[i+2];
				mdc = __gcd(a[i], a[i+2]);
				mmc = a[i] * a[i+2] / mdc;
				if(abs(a[i+1] - mdc) <= abs(a[i+1] - mmc)) b2[i+1] = mdc;
				else b2[i+1] = mmc;
			}

			else{
				if(i != n - 1){
					b2[i+1] = a[i+1];
					mdc = __gcd(a[i+1], a[i-1]);
					mmc = a[i+1] * a[i-1] / mdc;
					if(abs(a[i] - mdc) <= abs(a[i] - mmc)) b2[i] = mdc;
					else b2[i] = mmc;
				}

				else{
					mdc = __gcd(a[i], a[i-1]);
					mmc = a[i] * a[i-1] / mdc;
					if(abs(a[i] - mdc) <= abs(a[i] - mmc)) b2[i] = mdc;
					else b2[i] = mmc;
				}
			}
		}

		int s1 = 0, s2 = 0, s3 = 0;;
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
