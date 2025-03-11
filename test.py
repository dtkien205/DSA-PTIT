import math

def catalan(n):
    return math.factorial(2 * n) // (math.factorial(n) * math.factorial(n + 1))

T = int(input())

for _ in range(T):
    n = int(input())
    print(catalan(n))  
