import heapq

def procesar_caso(n, ema, otto):

    ema = [-x for x in ema]
    heapq.heapify(ema)
    heapq.heapify(otto)

    turnos = 0
    while ema and otto:
        ema_max = -heapq.heappop(ema)
        otto_min = heapq.heappop(otto)
        resultado = ema_max + otto_min

        if resultado % 2 == 1:
            heapq.heappush(otto, resultado)
        else:
            heapq.heappush(ema, -(resultado // 2))
        turnos += 1

    ganador = "Otto" if not ema else "Emma"
    return f"{turnos} {ganador}"

def juego(casos, datos):
    return [procesar_caso(n, ema, otto) for n, ema, otto in datos]

if __name__ == "__main__":
    casos = int(input())
    datos = []
    for _ in range(casos):
        n = int(input())
        ema = list(map(int, input().split()))
        otto = list(map(int, input().split()))
        datos.append((n, ema, otto))
    
    resultados = juego(casos, datos)
    print("\n".join(resultados))