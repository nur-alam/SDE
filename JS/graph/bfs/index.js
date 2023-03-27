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
function printGraph(adj) {
	for (let i = 0; i < adj.length; i++) {
		let arr = [];
		for (let v of adj[i]) {
			arr.push(v);
		}
		console.log(arr);
	}
}

function bfs(N, adj, startNode = 0) {
	let visited = new Array(N).fill(0);
	let bfsTraversal = [];
	let q = [];
	q.push(startNode);
	visited[startNode] = 1;
	bfsTraversal.push(startNode);
	while (q.length) {
		let u = q[0];
		q.shift();
		for (let v of adj[u]) {
			if (!visited[v]) {
				visited[v] = 1;
				q.push(v);
				bfsTraversal.push(v);
			}
		}
	}
	console.log('bfs traversal ', bfsTraversal);
}

function main() {
	let t = parseInt(readLine());
	for (let i = 0; i < t; i++) {
		let [N, E] = readLine().split(' ').map(Number);
		let adj = [...Array(N)].map(() => Array());
		for (let i = 0; i < E; i++) {
			let input_line = readLine().split(' ');
			let u = parseInt(input_line[0]);
			let v = parseInt(input_line[1]);
			adj[u].push(v);
			// adj[v].push(u);
		}
		bfs(N, adj);
		// printGraph(adj);
	}
}
