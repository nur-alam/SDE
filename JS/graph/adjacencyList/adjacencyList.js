'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
	inputString += inputStdin;
});

process.stdin.on('end', function () {
	inputString = inputString
		.trim()
		.split('\n')
		.map((string) => string.trim());
	main();
});

function readLine() {
	return inputString[currentLine++];
}

function multiDarray(row, col) {
	return [...Array(row)].map(() => Array(col).fill(0));
}

function main() {
	let [N, E] = readLine().split(' ').map(Number);
	let adjList = [...Array(N)].map(() => new Array());
	for (let i = 0; i < E; i++) {
		let [u, v] = readLine().split(' ').map(Number);
		adjList[u].push(v);
		adjList[v].push(u);
	}
    console.log(adjList);
}