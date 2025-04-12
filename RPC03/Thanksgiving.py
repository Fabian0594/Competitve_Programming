def solver():
    n = int(input())
    tells_to = list(map(int, input().split()))

    tells_to_me = [[] for _ in range(n + 1)]
    for i in range(1, n + 1):
        recipient = tells_to[i - 1] 
        tells_to_me[recipient].append(i)
    
    queue = []
    heard_gossip = [False] * (n + 1)
    heard_gossip[1] = True
    count = 1

    while queue:
        current = queue.pop(0)

        for teller in tells_to_me[current]:
            if not heard_gossip[teller]:
                heard_gossip[teller] = True
                queue.append(teller)
                count += 1
                
    return count

print(solver())