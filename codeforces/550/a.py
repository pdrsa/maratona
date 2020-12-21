n = int(input())
for i in range(n):
    s = input()
    s = list(s)

    if s[0]=="a" and s[-1] == "z":
        print("NO")
        continue
    if len(set(s)) < len(s):
        print("NO")
        continue
    
    ant = s[0];
    flag = False
    for c in s[1:-1]:
        if ord(ant)==ord(c)+1 or ord(ant)==ord(c)-1:
            print("NO")
            flag = True
            break
            
        ant = c

    if flag:
        continue
    print("YES")
    