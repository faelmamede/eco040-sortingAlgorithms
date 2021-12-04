fs = require('fs')
const size = 1000000;
const numbersArray = [];

function getRandomNumber(min, max) {
    min = Math.ceil(min);
    max = Math.floor(max);
    return Math.floor(Math.random() * (max - min)) + min;
  }

let i
for(i = 0; i < size; i++) {
    numbersArray.push(getRandomNumber(0,size))
}

words = numbersArray.join("\n");

fs.writeFile(`./../assets/${size}numeros.txt`, words, function (err,data) {
  if (err) {
    return console.log(err);
  }
});