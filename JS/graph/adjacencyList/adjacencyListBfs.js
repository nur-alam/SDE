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

let level = [];
let parent = [];

function getPath(node) {
	let path = [];
	path.push(node);
	while (parent[node] !== -1) {
		node = parent[node];
		path.unshift(node);
	}
	console.log(path);
}

function bfs(adjList, startNode = 0, N) {
	let visited = [...Array(N)].fill(0);
	let q = [];
	let bfsTraversal = [];
	visited[startNode] = 1;
	q.push(startNode);
	parent[startNode] = -1;
	while (q.length) {
		let currentNode = q.shift();
		bfsTraversal.push(currentNode);
		for (let child of adjList[currentNode]) {
			if (!visited[child]) {
				q.push(child);
				visited[child] = 1;
				parent[child] = currentNode;
				level[child] = level[child] + 1;
			}
		}
	}
	console.log('bfsTraversal ', bfsTraversal);
}

function main() {
	let [N, E] = readLine().split(' ').map(Number);
	let adjList = [...Array(N)].map(() => new Array());
	level = [...Array(N)].fill(0);
	parent = [...Array(N)].fill(0);
	for (let i = 0; i < E; i++) {
		let [u, v] = readLine().split(' ').map(Number);
		adjList[u].push(v);
		adjList[v].push(u);
	}
	console.log(adjList);
	bfs(adjList, 0, N);
	getPath(3);
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
