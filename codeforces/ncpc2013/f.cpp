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

void boom(){
	cout << "BOOM!!" << endl;
	exit(0);
}

int main(){ _
	vector<string> c(5);
	for(int i = 0; i < 5; i++) getline(cin, c[i]);

	//for(int i = 0; i < 5; i++) cout << endl << c[i];
	int n = c[0].size();
	vector<int> ans;

	for(int i = 0; i < n; i += 4){
		int aux = 0;
		//cout << i << endl;
		for(int j = 0; j < 5; j++){
			if(c[j][i] == '*') aux++;
			if(c[j][i+1] == '*') aux++;
			if(c[j][i+2] == '*') aux++;
		}

		if(c[1][i+1] == '*') boom();
		if(c[3][i+1] == '*') boom();

		if(aux == 5){
			for(int j = 0; j < 5; j++){
				if(c[j][i] == '*') boom();
				if(c[j][i+1] == '*') boom();
			}
			ans.pb(1);
		}

		else if(aux == 7){
			for(int j = 1; j < 5; j++){
				if(c[j][i] == '*') boom();
				if(c[j][i+1] == '*') boom();
			}
			ans.pb(7);
		}

		else if(aux == 9){
			if(c[0][i+1] == '*') boom();
			if(c[1][i+1] == '*') boom();
			for(int j = 3; j < 5; j++){
				if(c[j][i] == '*') boom();
				if(c[j][i+1] == '*') boom();
			}
			ans.pb(4);
		}

		else if(aux == 11){
			if(c[1][i] == '*') ans.pb(5);
			else if(c[3][i+2] == '*') ans.pb(3);
			else ans.pb(2);
		}	
		
		else if(aux == 12){
			if(c[2][i+1] == '*'){
				if(c[1][i+2] == '*') ans.pb(9);
				else ans.pb(6);
			}
			else ans.pb(0);
		}
		else if(aux == 13) ans.pb(8);
		
		else boom();

	}
	
	ll m = 1;
	ll ansN = 0;

	for(int i = ans.size() - 1; i >= 0; i--){
		//cout << ans[i];
		ansN += ans[i] * m;
		m *= 10;
	}
	//cout << endl;
	if(ansN % 6 == 0) cout << "BEER!!" << endl;
	else cout << "BOOM!!" << endl;

	exit(0);
}
