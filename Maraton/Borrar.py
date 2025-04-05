def borrar(cadena, eliminar):

    eliminar = {c for c in eliminar if ord(c) != 91 and ord(c) != 93}  
    
    resultado = []
    for c in cadena:
        if c not in eliminar:
            if not resultado or c != resultado[-1]:  
                resultado.append(c)
    
    return ''.join(resultado)

cadena = input().strip()
eliminar = input().strip()

resultado = borrar(cadena, eliminar)
print(resultado.strip(), end="\n")

