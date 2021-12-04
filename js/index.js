const readFile = require('./readFile')

const bubble = require('./sortFunctions/bubble').bubble
const selection = require('./sortFunctions/selection').selection
const insertion = require('./sortFunctions/insertion').insertion
const shell = require('./sortFunctions/shell').shell
const merge = require('./sortFunctions/merge').merge
const quick = require('./sortFunctions/quick').quick

let numbers
readFile.readNumbersFile.then((vector) => {
    numbers = vector
}).then(() => {
    const interval = [1000, 5000, 10000, 50000, 100000]
    const shortFunctions = [bubble,selection,insertion,shell,merge,quick]

    shortFunctions.forEach(func => {
        for (let i = 0; i < interval.length; i++) {
            func([...numbers], interval[i]) 
        }
    })
})