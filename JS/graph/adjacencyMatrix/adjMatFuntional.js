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

let adjMat;

function removeEdge(u, v) {
	adjMat[u][v] = 0;
	adjMat[v][u] = 0;
}

function addEdge(u, v) {
	adjMat[u][v] = 1;
	adjMat[v][u] = 1;
}

function removeLastRowCol() {
	for (let i = 0; i < adjMat.length; i++) {
		adjMat[i].pop();
	}
	adjMat.pop();
}

function removeNode(node) {
	let totalNode = adjMat.length;
	while (node < totalNode - 1 && node >= 0) {
		for (let i = 0; i < totalNode; i++) {
			adjMat[i][node] = adjMat[i][node + 1];
		}
		for (let i = 0; i < totalNode - 1; i++) {
			adjMat[node][i] = adjMat[node + 1][i];
		}
		node++;
	}
	totalNode--;
	removeLastRowCol();
}

function addNode(node) {
	for (let i = 0; i < adjMat.length; i++) {
		adjMat[i].push(0);
	}
	adjMat.push(Array(adjMat.length + 1).fill(0));
}

function main() {
	let [N, E] = readLine().split(' ').map(Number);
	adjMat = multiDarray(N, N);
	addEdge(0, 1);
	addEdge(0, 2);
	addNode(5);
	addNode(6);
	addEdge(5, 1);
	addEdge(6, 1);
	removeNode(5);
	console.table(adjMat);
	console.table(adjMat.length);
}