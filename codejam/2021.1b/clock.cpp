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
const ll NANO = 1e9;
const ll HDAY = 43200 * NANO;

bool f = false;
ll ht;

void check(ll h, ll m, ll s){
	if(f) return;
	//cout << (h % (60 * NANO)) << endl;
	//cout << (h % (3600 * NANO)) << endl;

	if(m != (h % (3600 * (NANO))) * 12) return;
	if(s != (h % (60 * (NANO))) * 720) return;
	//if(h % NANO != 0) return;

	f = true;
	//cout << h << " " << m << " " << s << endl;
	ht = h;
}

int main(){ _
	int ttt; cin >> ttt;
	for(int tt = 1; tt <= ttt; tt++){ 
		f = false;
		ll p1, p2, p3; cin >> p1 >> p2 >> p3;
		check(p1, p2, p3);
		check(p1, p3, p2);
		check(p2, p1, p3);
		check(p2, p3, p1);
		check(p3, p1, p2);
		check(p3, p2, p1);

		p1 -= (p1 % NANO), p2 -= (p2 % NANO), p3 -= (p3 % NANO);
		//cout << p1 << " " << p2 << " " << p3;
		// Testset 2
		for(int i = 0; i < 100000 and !f; i++){
			p1 += NANO, p2 += NANO, p3 += NANO;
			p1 %= HDAY, p2 %= HDAY, p3 %= HDAY;

			check(p1, p2, p3);
			check(p1, p3, p2);
			check(p2, p1, p3);
			check(p2, p3, p1);
			check(p3, p1, p2);
			check(p3, p2, p1);
		}
		/*if(!f){
			cout << "QUEBROU!" << endl;
			exit(0);
		}*/
		ll hans, mans, sans;
		hans = (ht / (3600 * (NANO)));
		ht -= hans * 3600 * NANO;
		mans = (ht / (60 * (NANO)));
		ht -= mans * 60 * NANO;
		sans = ht/(NANO);
		ht -= sans * NANO;
		cout << "Case #" << tt << ": " << hans << " " << mans << " " << sans << " " << ht << endl;
	}
	exit(0);
}
