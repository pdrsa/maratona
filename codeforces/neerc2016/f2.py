import sys
from fractions import Fraction as frac

def gauss(a, b):
    n = len(a)
    m = len(a[0])
    for i in range(n): a[i].append(b[i])
    where = [-1]*m
    col = -1
    row = 0
    while col < m-1 and row < n:
        col += 1
        sel = row
        for i in range(row, n):
            if abs(a[i][col]) > abs(a[sel][col]): 
                sel = i
        if a[sel][col] == 0: 
            continue
        for i in range(col, m+1):
            a[sel][i], a[row][i] = a[row][i], a[sel][i]
        where[col] = row

        for i in range(n):
            if i != row:
                c = a[i][col] / a[row][col]
                for j in range(col, m+1):
                    a[i][j] -= a[row][j] * c
        row += 1

    ans = [0]*m
    for i in range(m):
        if where[i] != -1:
            ans[i] = a[where[i]][m] / a[where[i]][i]
    return ans


import sys
from fractions import Fraction as frac

string = 'val = 0\n' + open("fygon.in").read().replace('lag', 'val += 1')
values = []
for n in range(0, 8):
    exec(string)
    values.append(frac(val))

n = 8
M = [0] * n
for i in range(n): 
    M[i] = [0] * n
    for j in range(n):
        M[i][j] = frac(i**j)

coef = gauss(M, values)
outfile = open('fygon.out', 'w')
for i in range(n):
    if i == 0:
        print(coef[i], end = " ", file=outfile)
    else:
        print('+', coef[i], '* n', end="", file=outfile)
        for j in range(i-1):
            print('*n', end = "", file=outfile)
        print(" ", end = "", file = outfile)
print(file=outfile)
