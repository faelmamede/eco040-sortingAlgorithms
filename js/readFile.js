const fs = require('fs')
const readline = require('readline');

const numbersArray = []
const readNumbersFile = new Promise(async (resolve, reject) => {
    console.log('Reading file...')
    const fileStream = fs.createReadStream(`./../assets/1000000numeros.txt`);
  
    const rl = readline.createInterface({
      input: fileStream,
      crlfDelay: Infinity
    });
  
    for await (const number of rl) {
      numbersArray.push(parseInt(number))
    }
    console.log('---------------------')
    resolve(numbersArray)
})

module.exports = { readNumbersFile: readNumbersFile }