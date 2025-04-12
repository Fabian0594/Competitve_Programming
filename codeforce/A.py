def is_ideal_generator(k):
    return "YES" if k % 2 != 0 else "NO"

t = int(input())
results = []

for _ in range(t):
    k = int(input())
    results.append(is_ideal_generator(k))

print("\n".join(results))
