def gcd(a, b):
    """Calcula el máximo común divisor de a y b."""
    while b:
        a, b = b, a % b
    return a

def resolver_juego(n):
    """Simula el juego con n estudiantes y devuelve el número del ganador."""
    # Excluimos al estudiante 1 y formamos el círculo con los demás
    estudiantes = list(range(2, n + 1))
    
    # Si solo queda un estudiante después de excluir al 1
    if len(estudiantes) <= 1:
        return estudiantes[0] if estudiantes else 0
    
    # El estudiante 2 comienza la primera ronda
    indice_actual = 0  # Índice del estudiante 2 en la lista
    
    # Mientras quede más de un estudiante
    while len(estudiantes) > 1:
        # El estudiante actual escribe su número en la hoja
        numero_hoja = estudiantes[indice_actual]
        
        # Empezamos a pasar la hoja a la izquierda
        indice_siguiente = (indice_actual + 1) % len(estudiantes)
        encontrado = False
        
        # Buscamos al primer estudiante que será eliminado
        while not encontrado and indice_siguiente != indice_actual:
            estudiante_siguiente = estudiantes[indice_siguiente]
            
            # Calculamos el MCD
            mcd_resultado = gcd(numero_hoja, estudiante_siguiente)
            
            # Si el MCD > 1, este estudiante será eliminado
            if mcd_resultado > 1:
                # El nuevo indice_actual será el estudiante a la izquierda del eliminado
                indice_actual = (indice_siguiente + 1) % len(estudiantes)
                # Eliminamos al estudiante
                estudiantes.pop(indice_siguiente)
                # Ajustamos el índice actual si es necesario
                if indice_siguiente < indice_actual:
                    indice_actual -= 1
                encontrado = True
            else:
                # Pasamos al siguiente estudiante
                indice_siguiente = (indice_siguiente + 1) % len(estudiantes)
        
        # Si nadie fue eliminado, el siguiente estudiante comienza la próxima ronda
        if not encontrado:
            indice_actual = (indice_actual + 1) % len(estudiantes)
    
    # El último estudiante que queda es el ganador
    return estudiantes[0]

def main():
    t = int(input())  # Número de casos de prueba
    
    for _ in range(t):
        n = int(input())  # Número de estudiantes
        ganador = resolver_juego(n)
        print(ganador)

if __name__ == "__main__":
    main()