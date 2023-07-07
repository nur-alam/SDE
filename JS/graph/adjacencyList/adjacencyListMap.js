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

function addEdge(graph, u, v) {
	graph.get(u).add(v);
	graph.get(v).add(u);
}

function main() {
	const [N, E] = readLine().split(' ').map(Number);
	const graph = new Map();
	for (let i = 0; i < N; i++) {
		graph.set(i, new Set());
	}
	for (let i = 0; i < E; i++) {
		const [u, v] = readLine().split(' ').map(Number);
		graph.get(u).add(v);
		graph.get(v).add(u);
	}
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 3);
	addEdge(graph, 1, 2);
	addEdge(graph, 2, 3);
	console.log(graph);
}
