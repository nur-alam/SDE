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

let visited = [];
let dfsTraversal = [];

function dfs(adjList, startNode = 0) {
	visited[startNode] = 1;
	dfsTraversal.push(startNode);
	for (let child of adjList[startNode]) {
		if (!visited[child]) {
			dfs(adjList, child);
		}
	}
}

function main() {
	const [N, E] = readLine().split(' ').map(Number);
	visited = [...Array(N)].fill(0);
	const adjList = [...Array(N)].map(() => new Array());
	for (let i = 0; i < E; i++) {
		const [u, v] = readLine().split(' ').map(Number);
		adjList[u].push(v);
		adjList[v].push(u);
	}
	console.log(adjList);
	dfs(adjList, 0);
	console.log('dfsTraversal ', dfsTraversal);
}


// example 1
// 5 4
// 0 1
// 0 2
// 0 3
// 2 4
// output
// dfs traversal  [ 0, 1, 2, 4, 3 ]

// example 2
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// output
// dfs traversal  [ 0, 1, 2, 3 ]
