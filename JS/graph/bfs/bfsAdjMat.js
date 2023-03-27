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

// let adjMat;
let visited;
let parent;
let level;

function bfs(adjMat, startNode = 0) {
	let bfsTraversal = [];
	let q = [];
	q.push(startNode);
	visited[startNode] = 1;
	parent[startNode] = -1;
	level[startNode] = 0;
	bfsTraversal.push(startNode);
	while (q.length) {
		let currentNode = q.shift();
		bfsTraversal.push();
		for (let [index, value] of adjMat[currentNode].entries()) {
			if (value == 1 && visited[index] == 0) {
				q.push(index);
				visited[index] = 1;
				level[index] = level[currentNode] + 1;
				parent[index] = currentNode;
				bfsTraversal.push(index);
			}
		}
		// for (let i = 0; i < adjMat[currentNode].length; i++) {
		// 	if (adjMat[currentNode][i] == 1 && visited[i] == 0) {
		// 		q.push(i);
		// 		visited[i] = 1;
		// 		level[i] = level[currentNode] + 1;
		// 		parent[i] = currentNode;
		// 		bfsTraversal.push(i);
		// 	}
		// }
	}
	console.log(bfsTraversal, 'bfs traversal');
	console.log(visited, 'visited');
	console.log(parent, 'parent');
	console.log(level, 'level');
}

function main() {
	let [N, E] = readLine().split(' ').map(Number);
	let adjMat = multiDarray(N, N);
	visited = Array(N).fill(0);
	parent = Array(N).fill(0);
	level = Array(N).fill(0);
	for (let i = 0; i < E; i++) {
		let [u, v] = readLine().split(' ').map(Number);
		adjMat[u][v] = 1;
		adjMat[v][u] = 1;
	}
	bfs(adjMat, 0);
	// console.log(adjMat);
}
