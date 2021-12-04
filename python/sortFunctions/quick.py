import datetime

def __partition(vet, esq, dir):
    pivo = vet[dir]
    i = (esq - 1)

    j = esq
    while (j <= dir - 1):
        if (vet[j] < pivo):
            i += 1
            x = vet[i]
            vet[i] = vet[j]
            vet[j] = x
        j += 1

    x = vet[i+1]
    vet[i+1] = vet[dir]
    vet[dir] = x

    return (i + 1)

def __quickRecursive(vet, esq, dir):
    if (esq < dir):
        aux = __partition(vet, esq, dir)
        __quickRecursive(vet, esq, aux - 1)
        __quickRecursive(vet, aux + 1, dir)

def quick(vet, n):
    start = datetime.datetime.now()

    __quickRecursive(vet, 0, n-1)

    finish = datetime.datetime.now()
    time = finish - start
    print(f'Quick {n} - time: {time.total_seconds() * 1000}')