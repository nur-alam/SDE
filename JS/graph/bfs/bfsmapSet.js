'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.trim().split('\n').map( string => string.trim() );
    main();
});

function readLine() {
    return inputString[currentLine++];
}
function printGraph(adj) {
    for (let i = 0; i < adj.size; i++) {
        console.log(adj.get(i));
    }
}

function bfs(N, adj, startNode) {
    const visited = new Set();
    const q = [];
    q.push(startNode);
    visited.add(startNode);
    while (q.length) {
        const currentNode = q.shift();
        for (let neighbour of adj.get(currentNode)) {
            if (!visited.has(neighbour)) {
                q.push(neighbour);
                visited.add(neighbour);
            }
        }
    }
    console.log(visited);
}

function main() {
    let t = parseInt(readLine());
    for (let i = 0; i < t; i++) {
        let [N, E] = readLine().split(' ');
        let adj = new Map();
        for (let i = 0; i < N; i++) {
            adj.set(i, new Set());
        }
        for (let i = 0; i < E; i++) {
            let input_line = readLine().split(' ');
            let u = parseInt(input_line[0]);
            let v = parseInt(input_line[1]);
            adj.get(u).add(v);
        }
        // console.log(adj);
        // printGraph(adj);
        bfs(N, adj, 0);
    }
}