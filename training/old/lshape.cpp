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

int l;
int z = 0;
int m[2048][2048];

void solve(int i, int j, int n, int r, int c){
	if(n == 1) return;

	int qr = n/2 + r*n;
	int qc = n/2 + c*n;
	
	z++;

	r *= 2;
	c *= 2;
	if(i < n/2){
		m[qr][qc-1] = z;
		m[qr][qc] = z;
		if(j < n/2){
			m[qr-1][qc] = z;
			solve(n/2-1, 0, n/2, r, c+1);
		}
		else{
			m[qr-1][qc-1] = z;
			solve(n/2-1, n/2-1, n/2, r, c);
		}
		solve(0, 0, n/2, r+1, c+1);
		solve(0, n/2-1, n/2, r+1, c);
	}
	else{
		m[qr-1][qc-1] = z;
		m[qr-1][qc] = z;
		if (j < n/2){
			m[qr][qc] = z;
			solve(0, 0, n/2, r+1, c+1);
		}
		else{
			m[qr][qc-1] = z;
			solve(0, n/2-1, n/2, r+1, c);
		}

		solve(n/2-1, 0, n/2, r, c+1);
		solve(n/2-1, n/2-1, n/2, r, c);
	}
	
	if(i >= n/2) r++;
	if(j >= n/2) c++;
	i %= (n/2); j %= (n/2);

	solve(i, j, n/2, r, c);
}


int main(){ _
	int x, y;
	cin >> l >> x >> y;
	x--; y--;
	m[x][y] = -1;
	solve(x, y, l, 0, 0);
	char r[1400000];
	memset(r, 'a', sizeof r);
	int cont = 0;
	int act = 0, acti;
	for(int i = 0; i < l; i++){
		if(i % 4 == 0) acti = 0;
		
		for(int j = 0; j < l; j++){
			if(act % 4 == 0) act = 0;

			if(m[i][j] == -1){
				cout << '.';
			}
			else{
				if(r[ (m[i][j]) ] == 'a'){
					r[ m[i][j] ] = 'A' + acti + act;
					act++;
					cont++;
				}
				cout << r[ m[i][j] ];
			}
		}

		acti += 4;
		cout << endl;
	}

	exit(0);
}
