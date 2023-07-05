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

function bfs(adjMat, startNode = 0) {
	let visited = Array(adjMat.length).fill(false);
	let bfsTraversal = [];
	let q = [];
	q.push(startNode);
	visited[startNode] = true;
	bfsTraversal.push(startNode);
	while (q.length) {
		let currentNode = q.shift();
		// for (let [i, value] of Object.entries(adjMat[currentNode])) {
		for (let i = 0; i < adjMat[currentNode].length; i++) {
			if (adjMat[currentNode][i] == 1 && !visited[i]) {
				visited[i] = 1;
				q.push(i);
				bfsTraversal.push(i);
			}
		}
	}
	console.log('bfs traversal ', bfsTraversal);
}

function main() {
	let [N, E] = readLine().split(' ').map(Number);
	let adjMat = multiDarray(N, N);
	for (let i = 0; i < E; i++) {
		let [u, v] = readLine().split(' ').map(Number);
		adjMat[u][v] = 1;
		adjMat[v][u] = 1;
	}
	console.log(adjMat);
	// bfs(adjMat, 0);
}

// example 1
// 5 4
// 0 1
// 0 2
// 0 3
// 2 4
// output
// bfs traversal  [ 0, 1, 2, 3, 4 ]

// example 2
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// output
// bfs traversal  [ 0, 1, 2, 3, 4 ]
