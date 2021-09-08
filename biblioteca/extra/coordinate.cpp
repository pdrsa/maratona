// Coordinate Compression on v

vector<int> ov = v;
sort(ov.begin(), ov.end());
ov.resize(unique(ov.begin(), ov.end()) - ov.begin());
for (int& i : v)
	i = lower_bound(ov.begin(), ov.end(), i) - ov.begin();
