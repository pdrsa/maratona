from decimal import *
getcontext().prec = 200
tt = int(input())
for i in range(tt):
	
	a, b, c = map(Decimal, input().split())
	ans = Decimal((a+b)/c)
	pr = str(ans)
	if(ans == int(ans)): pr += "."
	pr += str("0" * 50)
	
	counter = 0
	start   = False
	for c in pr:
		print(c, end = "")
		if(c == "."):
			start = True
		if(start): counter += 1
		if(counter == 51): break

	print()
