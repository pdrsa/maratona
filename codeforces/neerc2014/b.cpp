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

double dist(double a, double b){
	return (abs(a-b) * abs(a-b)) + 1;
}

int main(){ //_
	int n, m, ra; cin >> n >> m >> ra;
	ra *= ra;
	vector<double> c(n), w(m);
	string s;
	for(double &i: c){
		cin >> s;
		i = stod(s);
	}
	
	for(double &i: w){
		cin >> s;
		i = stod(s);
	}
	
	double ans = 0;
	int p = 0;
	for(double i: w){
		//cout << "Calc in: " << i << endl;
		if(dist(i, c[p]) <= ra) continue;
		
		// Go Left
		if(i < c[p]){
			//cout << "Going left" << endl;

			int r = p;
			int l = upper_bound(c.begin(), c.end(), i) - c.begin();
			int pnow;

			if(dist(c[l], i) > ra) pnow = l - 1;
			else{
				while(l < r){
					int mid = (r+l+1) / 2;
					if(dist(c[mid], i) > ra) r = mid - 1;
					else l = mid;
				}
				pnow = l;
			}

			ans += abs(c[p] - c[pnow]);
			p = pnow;
		}

		// Go Right
		else{
			//cout << "Going right" << endl;
			int l = p;
			int r;
			if(upper_bound(c.begin(), c.end(), i) == c.end()) r = n - 1;
			else r = upper_bound(c.begin(), c.end(), i) - c.begin() - 1;
			
			int pnow;

			if(dist(c[r], i) > ra) pnow = r+1;
			else{
				while(l < r){
					int mid = (r+l) / 2;
					if(dist(c[mid], i) > ra) l = mid + 1;
					else r = mid;
				}
				pnow = l;
			}
			ans += abs(c[p] - c[pnow]);
			p = pnow;
		}

		//cout << "I'm at : " << c[p] << endl;
	}

	cout << fixed << setprecision(1) << ans << endl;

	exit(0);
}
