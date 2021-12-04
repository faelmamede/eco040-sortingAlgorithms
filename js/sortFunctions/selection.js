const selection = (vector, len) => {
    const start = new Date().getTime();

    let smaller, aux, i, j
    for (i = 0; i < (len - 1); i++) {
        smaller = i
        for (j = (i + 1); j < len; j++) {
            if (vector[j] < vector[smaller])
                smaller = j
        }
        aux = vector[i]
        vector[i] = vector[smaller]
        vector[smaller] = aux
    }

    const finish = new Date().getTime()
    const time = finish - start
    console.log(`Selection ${len} - time: `, time)
    if (len === 100000) {
        console.log('-----------------')
    }
}

module.exports = {
    selection
}