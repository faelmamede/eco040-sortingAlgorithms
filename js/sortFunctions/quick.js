const partition = (vet, esq, dir) => {
    let x, j, i, pivo
    pivo = vet[dir]
    i = (esq - 1);

    for (j = esq; j <= dir - 1; j++) {
        if (vet[j] < pivo) {
            i++
            x = vet[i]
            vet[i] = vet[j]
            vet[j] = x
        }
    }

    x = vet[i+1]
    vet[i+1] = vet[dir]
    vet[dir] = x

    return (i + 1)
}

const quickRecursive = (vet, esq, dir) => {
    if (esq < dir) {
        aux = partition(vet, esq, dir)
        quickRecursive(vet, esq, aux - 1)
        quickRecursive(vet, aux + 1, dir)
    }
}

const quick = async (vet, n) => {
    const start = new Date().getTime()

    await quickRecursive(vet, 0, n-1)

    const finish = new Date().getTime()
    const time = finish - start
    console.log(`Quick ${n} - time: `, time)
    if (n === 100000) {
        console.log('-----------------')
    }
}

module.exports = {
    quick
}