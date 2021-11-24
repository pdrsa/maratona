// Matrix Fast Exponentiation 
// (A^exp)(mod MOD) in O(log(exp)*(A.size()))^3)

typedef vector<vector<ll>> matrix;

matrix id(int size) { // Identity
	matrix A(size, vector<ll>(size, 0));
	for(int i = 0; i < size; i++) A[i][i] = 1;
	return A;
}

matrix mult(matrix& A, matrix& B, ll mod) {
	if(A[0].size() != B.size()) throw invalid_argument("Invalid size on matrices!");

	int n = A.size(), m = B[0].size(), u = A[0].size();
	matrix C(n, vector<ll>(m, 0));

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			for(int k = 0; k < A[0].size(); k++)
				C[i][j] += A[i][k] * B[k][j], C[i][j] %= mod;
	
	return C;
}

matrix fexp(matrix A, ll exp, ll mod) {
	
	if(exp == 0) return id(A.size());
	matrix B = fexp(mult(A, A, mod), exp / 2, mod); // A squared^(exp / 2)

	if(exp % 2) B = mult(B, A, mod); // If exp'is odd
	return B; 
}
