// JP - Not in Kansas Anymore
// Baseado em: https://github.com/brunomaletta/Biblioteca/blob/master/Codigo/Grafos/centroid-decomp.cpp

// Centroid decomposition
// O(n log(n))

int n;
vector<vector<int>> g(MAX);
vector<int> subsize(MAX);
vector<bool> rem(MAX);

void dfs(int k, int prev) {
	subsize[k] = 1;
	for (int i : g[k])
		if (i != prev and !rem[i]) {
			dfs(i, k);
			subsize[k] += subsize[i];
		}
}

int centroid(int k, int prev, int size) {
	for (int i : g[k]) {
		if (rem[i] or i == prev) continue;
		if (subsize[i] > size / 2)
			return centroid(i, k, size);
	}

	// K = Centroid
	return k;
}

// Use this DFS to compute whatever you nedd

//vector<int> dist[MAX];
//void dfs_dist(int k, int prev, int d=0) {
//    dist[k].push_back(d);
//   for (int j : g[k]) if (j != prev and !rem[j])
//        dfs_dist(j, k, d+1);
//}

void decomp(int k) {
	dfs(k, k);

	// Find and get Centroid
	int c = centroid(k, k, subsize[k]);
	rem[c] = true;
	
	// You should compute what you need here {
	// }

	// Recursion for subtrees
	for (int i : g[c]) if (!rem[i]) decomp(i);
}

void go() {
	rem.assign(MAX, false);
	decomp(0);
	//for (int i = 0; i < n; i++) reverse(dist[i].begin(), dist[i].end());
}
