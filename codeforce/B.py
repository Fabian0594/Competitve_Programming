from itertools import combinations

def solve_case(s):
    n = len(s)
    best_cost = float('inf')
    min_deletions = n

    # 1. Subsec de longitud 1 a 7 (cubre casos pequeños como "666")
    for length in range(1, min(8, n+1)):
        for indices in combinations(range(n), length):
            sub = ''.join(s[i] for i in indices)
            if sub[0] == '0':
                continue
            digit_sum = sum(int(c) for c in sub)
            if digit_sum == 0:
                continue
            value = int(sub)
            cost = value / digit_sum
            deletions = n - length
            if cost < best_cost or (abs(cost - best_cost) < 1e-9 and deletions < min_deletions):
                best_cost = cost
                min_deletions = deletions

    # 2. Heurística rápida (para longitudes más grandes)
    for i in range(n):
        if s[i] == '0':
            continue
        current = s[i]
        digit_sum = int(s[i])
        for j in range(i + 1, min(i + 20, n)):
            current += s[j]
            digit_sum += int(s[j])
            if digit_sum == 0 or current[0] == '0':
                continue
            cost = int(current) / digit_sum
            deletions = n - len(current)
            if cost < best_cost or (abs(cost - best_cost) < 1e-9 and deletions < min_deletions):
                best_cost = cost
                min_deletions = deletions

    return min_deletions

# Leer entrada
t = int(input())
for _ in range(t):
    s = input().strip()
    print(solve_case(s))
