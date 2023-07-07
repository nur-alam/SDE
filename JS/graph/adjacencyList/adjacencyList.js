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

function bfs(adjList, startNode = 0, N) {
	const visited = [...Array(N)].fill(0);
	const q = [];
	const bfsTraversal = [];
	visited[startNode] = 1;
	q.push(startNode);
	while (q.length) {
		const currentNode = q.shift();
		bfsTraversal.push(currentNode);
		for (let child of adjList[currentNode]) {
			if (!visited[child]) {
				q.push(child);
				visited[child] = 1;
			}
		}
	}
	console.log('bfsTraversal ', bfsTraversal);
}

function main() {
	const [N, E] = readLine().split(' ').map(Number);
	const adjList = [...Array(N)].map(() => new Array());
	for (let i = 0; i < E; i++) {
		const [u, v] = readLine().split(' ').map(Number);
		adjList[u].push(v);
		adjList[v].push(u);
	}
	console.log(adjList);
	// bfs(adjList, 0, N);
}
