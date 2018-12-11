mod = 1000000007
H, W, A, B = map(int, raw_input().split())

factorial = [1]
for n in xrange(1, H+W):
    factorial.append(factorial[n-1]*n%mod)

def power(x, y):
    if   y == 0     : return 1
    elif y == 1     : return x % mod
    elif y % 2 == 0 : return power(x, y/2)**2 % mod
    else            : return power(x, y/2)**2 * x % mod

inverseFactorial = [0] * (H+W)
inverseFactorial[H+W-1] = power(factorial[H+W-1], mod-2)
for n in xrange(H+W-2, -1, -1):
    inverseFactorial[n] = inverseFactorial[n+1] * (n+1) % mod

def combi(n, m):
    return factorial[n] * inverseFactorial[m] * inverseFactorial[n-m] % mod

sum = 0
for i in xrange(B+1, W+1):
    sum = (sum + combi(H-A-1+i-1, i-1) * combi(A-1+W-i, W-i)) % mod
print sum