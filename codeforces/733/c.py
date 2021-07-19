t = int(input())
for test in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	a.sort(reverse = True)
	b.sort(reverse = True)
	for i in range(1, n):
		a[i] += a[i-1]
		b[i] += b[i-1]
	
	m = n

	while(1):
		t = m - int(m/4)
		sa = min(t, (m-n)) * 100
		t -= (m-n)
		if(t > 0):
			sa += a[t-1]
		sb = b[min(t-1, n-1)]

		if(sa >= sb): break
		else: m += 1

	print(m-n)
