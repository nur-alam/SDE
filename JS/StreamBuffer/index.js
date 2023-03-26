// const fs = require('fs')

// const ourReadStream = fs.createReadStream(`${__dirname}/input.txt`, 'utf-8');

// ourReadStream.on('data', (data) => {
//     console.log(data);
//     // console.log(data);
// })

// process.stdin.on('data', data => {
//     console.log(`You typed ${data.toString()}`);
//     process.exit();
// });
  
process.stdin.on('readable', () => {
    let chunk;
    // Use a loop to make sure we read all available data.
    while ((chunk = process.stdin.read()) !== null) {
     process.stdout.write(`data: ${chunk}`);
    }
  });
