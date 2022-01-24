import sys
string = 'val = 0\n' + open("fygon.in").read().replace('lag', 'val += 1')

def mList(x, l):
	return [v*x for v in l]

def addList(x, y):
	return [x[i]+y[i] for i in range(len(x))]

v = []
for n in range(0, 8):
    exec(string)
    v.append(val)

res =  mList(v[0], [1,-21,175,-753,1624,-1764,720]) 
res = addList(res, mList(v[1], [-6,120,-930,3480,-6264,4320,0])) 
res = addList(res, mList(v[2], [15,-285,2055,-6915,10530,-5400,0])) 
res = addList(res, mList(v[3], [-20,360,-2420,7440,-10160,4800,0]))
res = addList(res, mList(v[4], [15,-255,1605,-4605,5940,-2700,0]))
res = addList(res, mList(v[5], [-6,96,570,1560,-1944,864,0]))
res = addList(res, mList(v[6], [1,-15,85,-255,274,-120,0]))


print("1/720*(", end = "")
for i in range(7):
	print(v[6-i], end="")
	for j in range(i):
		print("*n", end="")
	if(i != 6):
		print(" + ", end="")

print(")")
