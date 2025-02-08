import numpy as np

n, m = [int(i) for i in input().split()]
mtrx = np.zeros((m, n), dtype=int)
weights = np.empty([0])

for i in range(m):
    u, v, w = [int(j) for j in input().split()]
    mtrx[i, u - 1] = -1
    mtrx[i, v - 1] = 1
    weights = np.append(weights, w)


inv_mtrx = np.linalg.pinv(mtrx)
x = inv_mtrx.dot(weights)

print(mtrx)
print(weights)

print(inv_mtrx)
print(*x)


print(" ".join(map(str, map(int, x))))
