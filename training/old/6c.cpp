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
	int n;
	cin >> n;
	int c[n];
	for (int i = 0; i < n; i++){
		cin >> c[i];
	}
	
	if (n == 1){
		cout << "1 0" << endl;
		exit(0);
	}

	int l = 0, r = n-1;
	int ta, tb, a=0, b=0;
	
	ta = c[l];
	tb = c[r];
	
	while (1){
		if (ta > tb){
			b++;
			r--;
			if (r == l){
				a++;
				break;
			}
			ta -= tb;
			tb = c[r];
		}
		if (tb > ta){
			a++;
			l++;
			if (l == r){
				b++;
				break;
			}
			tb -= ta;
			ta = c[l];
		}
		if (ta == tb){
			a++;
			l++;
			r--;
			b++;
			ta = c[l];
			tb = c[r];
			if(l == r){
				a++;
				break;
			}
			if (l>r)
				break;
		}
	}

	cout << a << " " << b << endl;
	exit(0);
}
