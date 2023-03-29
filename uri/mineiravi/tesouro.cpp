//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
// #define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll,ll> iill;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


typedef double ld;
const ld DINF = 1e18;
const ld eps = 1e-9;

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

struct pt { // ponto
	ld x, y;
	pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (!eq(x, p.x)) return x < p.x;
		if (!eq(y, p.y)) return y < p.y;
		return 0;
	}
	bool operator == (const pt p) const {
		return eq(x, p.x) and eq(y, p.y);
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ld c) const { return pt(x*c  , y*c  ); }
	pt operator / (const ld c) const { return pt(x/c  , y/c  ); }
	ld operator * (const pt p) const { return x*p.x + y*p.y; }
	ld operator ^ (const pt p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

// 7ab617
struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};

ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

ld get_t(pt v, line r) { // retorna t tal que t*v pertence a reta r
	return (r.p^r.q) / ((r.p-r.q)^v);
}

pt inter(line r, line s) { // r inter s
	if (eq((r.p - r.q) ^ (s.p - s.q), 0)) return pt(DINF, DINF);
	r.q = r.q - r.p, s.p = s.p - r.p, s.q = s.q - r.p;
	return r.q * get_t(r.q, s) + r.p;
}

bool isinseg(pt p, line r) {
	pt a = r.p - p, b = r.q - p;
	return eq((a ^b), 0) and (a * b) < eps;
}

ld polarea(vector<pt> v) {
	ld ret = 0;
	for(int i = 0; i < v.size(); i++)
		ret += sarea(pt(0, 0), v[i], v[(i+1) % v.size()]);
	return abs(ret);
}

int inpol(vector<pt>& v, pt p) { // O(n)
	int qt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (p == v[i]) return 2;
		int j = (i+1)%v.size();
		if (eq(p.y, v[i].y) and eq(p.y, v[j].y)) {
			if ((v[i]-p)*(v[j]-p) < eps) return 2;
			continue;
		}
		bool baixo = v[i].y+eps < p.y;
		if (baixo == (v[j].y+eps < p.y)) continue;
		auto t = (p-v[i])^(v[j]-v[i]);
		if (eq(t, 0)) return 2;
		if (baixo == (t > eps)) qt += baixo ? 1 : -1;
	}
	return qt != 0;
}

int main(){ _
	pt root(0, 0);
	pt sd; cin >> sd;
	pt a, b; cin >> a >> b;

	line top({0, sd.y}, sd), left(root, {0, sd.y}), right(sd, {sd.x, 0}), bottom({sd.x, 0}, root);

	pt dist_vect = b - a;
	pt meio = a + (dist_vect/2);
	pt ortogonal(dist_vect.y, -dist_vect.x);
	line linhazona(meio, meio + ortogonal);

	// cout <<"meio: " << meio.x << " " << meio.y << endl;
	// cout << "linha:" << linhazona.p.x << " " << linhazona.p.y << " " << linhazona.q.x << " " << linhazona.q.y << endl;

	vector<pt> pontos;
	vector<line> linhas;
	linhas.pb(top);
	linhas.pb(right);
	linhas.pb(bottom);
	linhas.pb(left);

	// cout << "top: " << top.p.x << " " << top.p.y << " " << top.q.x << " " << top.q.y << endl;
	// cout << "left: " << left.p.x << " " << left.p.y << " " << left.q.x << " " << left.q.y << endl;

	pt inter_top = inter(linhazona, top);
	pt inter_left = inter(linhazona, left);
	pt inter_right = inter(linhazona, right);
	pt inter_bottom = inter(linhazona, bottom);


	pontos.pb(inter_top);
	pontos.pb(inter_right);
	pontos.pb(inter_bottom);
	pontos.pb(inter_left);

	// for(auto [x, y] : pontos) cout << x << " " << y << endl;

	vector<int> verdadeiros;
	if(isinseg(inter_top, top)) verdadeiros.pb(0);
	if(isinseg(inter_right, right)) verdadeiros.pb(1);
	if(isinseg(inter_bottom, bottom)) verdadeiros.pb(2);
	if(isinseg(inter_left, left)) verdadeiros.pb(3);

	// cout << "size: " << verdadeiros.size() << endl;


	if (verdadeiros.size() > 2)
		verdadeiros.erase(verdadeiros.begin() + 1);

	if (verdadeiros.size() > 2)
		verdadeiros.pop_back();

	vector<pt> poli;
	poli.push_back(pontos[verdadeiros[0]]);
	poli.push_back(linhas[verdadeiros[0]].q);
	for (int i = verdadeiros[0] + 1; i < verdadeiros[1]; i++)
		poli.push_back(linhas[i].p),
		poli.push_back(linhas[i].q);
	poli.push_back(linhas[verdadeiros[1]].p);
	poli.push_back(pontos[verdadeiros[1]]);

	ld bla = polarea(poli) / (sd.x * sd.y);
	ld bla2 = 1.0 - bla;

	if(not inpol(poli, a)) swap(bla, bla2);

	cout << fixed << setprecision(6) << bla << " " << bla2 << endl;

	exit(0);
}
