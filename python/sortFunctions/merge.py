import numpy
import datetime
import math

def __mergeIntercala(vet, aux, ini, meio, fin):
    atual = ini
    fimEsq = meio - 1
    n = fin - ini + 1

    while ((ini <= fimEsq) and (meio <= fin)):
        if (vet[ini] <= vet[meio]):
            aux[atual] = vet[ini]
            atual += 1
            ini += 1
        else:
            aux[atual] = vet[meio]
            atual += 1
            meio += 1

    while (ini <= fimEsq):
        aux[atual] = vet[ini]
        atual += 1
        ini += 1
    
    while (meio <= fin):
        aux[atual] = vet[meio]
        atual += 1
        meio += 1

    i = 0
    while (i < n):
        vet[fin] = aux[fin]
        fin -= 1
        i += 1

def __mergeDivide(vet, aux, ini, fin):
    if (fin > ini):
        meio = math.floor((fin + ini) / 2)
        __mergeDivide(vet, aux, ini, meio)
        __mergeDivide(vet, aux, meio + 1, fin)
        __mergeIntercala(vet, aux, ini, meio + 1, fin)


def merge (vet, n):
    start = datetime.datetime.now()

    aux = numpy.empty(n, dtype=int)
    __mergeDivide(vet, aux, 0, n - 1)

    finish = datetime.datetime.now()
    time = finish - start
    print(f'Merge {n} - time: {time.total_seconds() * 1000}')