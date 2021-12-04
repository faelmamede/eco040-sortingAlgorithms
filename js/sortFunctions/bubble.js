const bubble = (vector, len) => {
    const start = new Date().getTime();

    let aux, i, j
    for (i = 0; i < len; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            if (vector[j + 1] < vector[j]) {
                aux = vector[j]
                vector[j] = vector[j + 1]
                vector[j + 1] = aux
            }
        }
    }
    
    const finish = new Date().getTime()
    const time = finish - start
    console.log(`Bubble ${len} - time: `, time)
    if (len === 100000) {
        console.log('-----------------')
    }
}

module.exports = {
    bubble
}