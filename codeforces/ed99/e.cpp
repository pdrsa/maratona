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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int dist(ii a, ii b){
	return abs(a.f - b.f) + abs(a.s - b.s);
}

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		vector<ii> p(4);
		for(int i = 0; i < 4; i++) cin >> p[i].f >> p[i].s;	
		int ans = INF;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4 and j != i; j++){
			int acta, actb;
			// come to my x
			acta = 0, actb = 0;
			acta += abs(p[i].f - p[j].f);
			ii aux = {p[i].f, p[j].s};
			
			//acima
			actb = acta;
			for(int k = 0; k < 4 and k != i and k != j; k++){
				actb += dist({aux.f, aux.s + acta}, p[k]);
				break;
			}
			for(int k = 3; k >= 0 and k != i and k != j; k--){
				actb += dist({p[i].f, p[i].s + acta}, p[k]);
				break;
			}
			ans = min(actb, ans);

			actb = acta;
			for(int k = 3; k >= 0 and k != i and k != j; k--){
				actb += dist({aux.f, aux.s + acta}, p[k]);
				break;
			}
			for(int k = 0; k < 4 and k != i and k != j; k++){
				actb += dist({p[i].f, p[i].s + acta}, p[k]);
				break;
			}
			ans = min(actb,ans);
	
			// abaixo
			actb = acta;
			for(int k = 0; k < 4 and k != i and k != j; k++){
				actb += dist({aux.f, aux.s - acta}, p[k]);
				break;
			}
			for(int k = 3; k >= 0 and k != i and k != j; k--){
				actb += dist({p[i].f, p[i].s - acta}, p[k]);
				break;
			}
			ans = min(actb, ans);

			actb = acta;
			for(int k = 3; k >= 0 and k != i and k != j; k--){
				actb += dist({aux.f, aux.s - acta}, p[k]);
				break;
			}
			for(int k = 0; k < 4 and k != i and k != j; k++){
				actb += dist({p[i].f, p[i].s - acta}, p[k]);
				break;
			}
			ans = min(actb,ans);
			
			// come to my y
			
			acta = 0, actb = 0;
			acta += abs(p[i].s - p[j].s);
			aux = {p[j].f, p[i].s};
			
			//direita
			actb = acta;
			for(int k = 0; k < 4 and k != i and k != j; k++){
				actb += dist({aux.f + acta, aux.s}, p[k]);
				break;
			}
			for(int k = 3; k >= 0 and k != i and k != j; k--){
				actb += dist({p[i].f + acta, p[i].s}, p[k]);
				break;
			}
			ans = min(actb, ans);

			actb = acta;
			for(int k = 3; k >= 0 and k != i and k != j; k--){
				actb += dist({aux.f + acta, aux.s}, p[k]);
				break;
			}
			for(int k = 0; k < 4 and k != i and k != j; k++){
				actb += dist({p[i].f + acta, p[i].s}, p[k]);
				break;
			}
			ans = min(actb,ans);
	
			// abaixo
			actb = acta;
			for(int k = 0; k < 4 and k != i and k != j; k++){
				actb += dist({aux.f - acta, aux.s}, p[k]);
				break;
			}
			for(int k = 3; k >= 0 and k != i and k != j; k--){
				actb += dist({p[i].f - acta, p[i].s}, p[k]);
				break;
			}
			ans = min(actb, ans);

			actb = acta;
			for(int k = 3; k >= 0 and k != i and k != j; k--){
				actb += dist({aux.f - acta, aux.s}, p[k]);
				break;
			}
			for(int k = 0; k < 4 and k != i and k != j; k++){
				actb += dist({p[i].f - acta, p[i].s}, p[k]);
				break;
			}
			ans = min(actb,ans);
			}
		}
		
		cout << ans << endl;
	}
	exit(0);
}
