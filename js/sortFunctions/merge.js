const mergeIntercala = (vet, aux, ini, meio, fin) => {
    let atual, fimEsq, n, i
    atual = ini
    fimEsq = meio - 1
    n = fin - ini + 1

    while ((ini <= fimEsq) && (meio <= fin)) {
        if (vet[ini] <= vet[meio]) {
            aux[atual++] = vet[ini++]
        } else {
            aux[atual++] = vet[meio++]
        }
    }

    while (ini <= fimEsq) {
        aux[atual++] = vet[ini++]
    }

    while (meio <= fin) {
        aux[atual++] = vet[meio++]
    }

    for (i = 0; i < n; i++) {
        vet[fin] = aux[fin]
        fin--
    }
}

const mergeDivide = (vet, aux, ini, fin) => {
    let meio
    if (fin > ini) {
        meio = Math.floor((fin + ini) / 2)
        mergeDivide(vet, aux, ini, meio)
        mergeDivide(vet, aux, meio + 1, fin)
        mergeIntercala(vet, aux, ini, meio + 1, fin)
    }
}

const merge = async (vet, n) => {
    const start = new Date().getTime();

    await mergeDivide(vet, [], 0, n - 1)

    const finish = new Date().getTime()
    const time = finish - start
    console.log(`Merge ${n} - time: `, time)
    if (n === 100000) {
        console.log('-----------------')
    }
}

module.exports = {
    merge
}