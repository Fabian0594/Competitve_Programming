def optimal_strategy(n, k, p):
    p = p / 100  # Convertir el porcentaje a una probabilidad decimal

    # Estrategia 1: Continuar
    time_continue = (1 - p) * (n - k) * 0.1 + p * ((n - k - 1) * 0.1 + 0.3 + (n - k) * 0.1)

    # Estrategia 2: Borrar con la tecla de retroceso
    time_backspace = 0.1 + (n - k) * 0.1

    # Estrategia 3: Reiniciar desde cero
    time_restart = (k * 0.1) + (n * 0.1)

    # Determinar la estrategia óptima
    if time_continue < time_backspace and time_continue < time_restart:
        return "continue"
    elif time_backspace < time_restart:
        return "backspace"
    else:
        return "restart"

# Leer la entrada
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    n, k, p = int(data[0]), int(data[1]), int(data[2])
    print(optimal_strategy(n, k, p))