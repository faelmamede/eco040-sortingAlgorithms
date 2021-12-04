const shell = (vector, len) => {
    const start = new Date().getTime();

    let j, h, aux
    for (h = len / 2; h > 0; h /= 2) {
        for (i = h; i < len; i++) {
            aux = vector[i]
            for (j = i; j >= h && vector[j - h] > aux; j -= h)
                vector[j] = vector[j - h]
            vector[j] = aux
        }
    }
    
    const finish = new Date().getTime()
    const time = finish - start
    console.log(`Shell ${len} - time: `, time)
    if (len === 100000) {
        console.log('-----------------')
    }
}

module.exports = {
    shell
}