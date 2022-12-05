// const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}


function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const n = parseInt(readLine(), 10); // Read and integer like this

    // Read an array like this
    const c = readLine().split(' ').map(cTemp => parseInt(cTemp, 10));

    let result; // result of some calculation as an example

    ws.write(result + "\n");

    ws.end();
}


// process.stdin.on('readable', () => {
//     let chunk;
//     // Use a loop to make sure we read all available data.
//     while ((chunk = process.stdin.read()) !== null) {
//         process.stdout.write(`data: ${chunk}`);
//     }
// });

// Node.js program to demonstrate the 
// process.stdin Property 
  
// Enter any texts ( User input)
// process.stdin.on('data', data => {
//     console.log(`You typed ${data.toString()}`);
//     process.exit();
//   });