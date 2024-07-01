n = int(input())
s = input()

ok = False
for i in range(0, len(s) - 1):
    if (s[i] == 'a'):
        if (s[i + 1] == 'b'):
            ok = True
    elif (s[i] == 'b'):
        if (s[i + 1] == 'a'):
            ok = True
if (ok):
    print("Yes")
else:
    print("No")