import {createWriteStream, readFileSync} from 'fs';
import { fileURLToPath } from 'url';
import { dirname, join } from 'path';
import nodemon from 'nodemon';

const __filename = fileURLToPath(import.meta.url);
const __dirname = dirname(__filename);



// process.stdin.resume();
// process.stdin.setEncoding('utf-8');

let inputString = readFileSync(join(__dirname, 'yo.txt'), 'utf-8');
inputString = inputString.trim().split('\n').map(line => line.trim());
let currentLine = 0;

// process.stdin.on('data', function (inputStdin) {
//     // console.log(inputStdin);
//     inputString += inputStdin;
// });

// process.stdin.on('end', function() {
//     inputString = inputString.trim().split('\n').map(line => {
        
//         return line.trim();
//     });
//     main();
// });

main();

function readLine() {
    return inputString[currentLine++];
}

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

function extraLongFactorials(n) {
    // Write your code here
    return n;
}


nodemon({
    script: join(__dirname, 'index1.js'),
    stdout: false // important: this tells nodemon not to output to console
}).on('readable', function () { // the `readable` event indicates that data is ready to pick up
    this.stdout.pipe((e) => console.log('hi', e));
  });

function main() {
    const n1 = readLine().split(" ").map(Number);
    const n2 = readLine().split(" ").map(Number);

    console.log({n1, n2})
    // const n = parseInt(readLine().trim(), 10);
    // const n1 = parseInt(readLine().trim(), 10);
    // console.log('main function', n);
    // console.log('main function', n1);
    // extraLongFactorials(n);
}