def construir_diccionario():
    teclas = {
        '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
        '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'
    }
    diccionario = {}
    for numero, letras in teclas.items():
        for letra in letras:
            diccionario[letra] = numero
    return diccionario

def palabra_a_numero(palabra, diccionario):
    return ''.join([diccionario[letra] for letra in palabra])

def main():
    n, m = map(int, input().strip().split())
    palabras = [input().strip() for _ in range(n)]
    numeros = [input().strip() for _ in range(m)]

    diccionario = construir_diccionario()

    representaciones = {}
    for palabra in palabras:
        numero = palabra_a_numero(palabra, diccionario)
        if numero not in representaciones:
            representaciones[numero] = []
        representaciones[numero].append(palabra)

    for numero in numeros:
        if numero in representaciones:
            palabras_validas = sorted(representaciones[numero])
            print(len(palabras_validas), ' '.join(palabras_validas))
        else:
            print(0)

if __name__ == "__main__":
    main()
