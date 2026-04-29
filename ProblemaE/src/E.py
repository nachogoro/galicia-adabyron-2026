def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


n = int(input())
v = [int(n) for n in input().split()]

l = 0
r = 0
p = 1
count = 0

while l < n:
    if r < n and gcd(p, v[r]) == 1:
        # Can grow to the right
        p = p * v[r]
        r += 1
    else:
        # Must decrease
        count += (r - l)
        p /= v[l]
        l += 1
        if l > r:
            r = l

print(count)
