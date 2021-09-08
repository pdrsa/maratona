tt = int(input())
for i in range(tt):
	
	a, b, c = map(int, input().split())
	d = a+b;
	print(d//c, end = "")
	print(".", end = "")

	d -= (d//c) * c
	for i in range(50):
		d *= 10
		print(d//c, end = "")
		d -= (d//c) * c
	print()
