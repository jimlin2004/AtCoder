import math

n = int(input())

res = -1

for i in range(1, int(math.sqrt(n)) + 1):
    if (i ** i == n):
        res = i
        break

print(res)