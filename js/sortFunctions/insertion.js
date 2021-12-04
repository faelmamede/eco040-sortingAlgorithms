const insertion = (vector, len) => {
    const start = new Date().getTime();

    let aux, i, j;
    for (i = 1; i < len; i++) {
        aux = vector[i];
        j = i - 1;
        while (j >= 0 && vector[j] > aux) {
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = aux;
    }
    
    const finish = new Date().getTime()
    const time = finish - start
    console.log(`Insertion ${len} - time: `, time)
    if (len === 100000) {
        console.log('-----------------')
    }
}

module.exports = {
    insertion
}