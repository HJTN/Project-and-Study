var fs = require('fs');
/*
console.log('A');
var result = fs.readFileSync('./syntax/sample.txt', 'utf8'); // 동기 처리 방식
console.log(result);
console.log('C');
*/
console.log('A');
fs.readFile('./syntax/sample.txt', 'utf8', function(err, result) { // 비동기 처리 방식
		console.log(result);
});
console.log('C');