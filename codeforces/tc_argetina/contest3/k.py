from decimal import *
a, b = list(map(int, input().split()))
getcontext().prec = 600
c = str(Decimal(a).sqrt())
d = c.split(".")
print(d[0], end="")
print(".", end="")
if(len(d) > 1):
	print(d[1][:b])
else:
	print("0"*b)
