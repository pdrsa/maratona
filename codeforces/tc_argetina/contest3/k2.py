from decimal import *
a,b =map(int,input().split())
getcontext().prec=600
s=str(Decimal.sqrt(Decimal(a)))
zeros="0"*500
zeros="."+zeros
pt=0
for i in range (len(s)):
    if s[i] == ".":
        pt=i
        break
if b == 0:
    print(s[0:pt+1])
elif pt + 1 == len(s):
    print(s[0:pt+1] + zeros[0:b+1])
else:
    print(s[0:pt]+s[pt:b+pt+1])
