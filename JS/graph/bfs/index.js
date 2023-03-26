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

function bfs(N, adj) {
    let visited = new Array(N).fill(0);
    let bfsTraversal = [];
    let q = [];
    q.push(0);
    visited[0] = 1;
    bfsTraversal.push(0);
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
    console.log(bfsTraversal);
}

function main() {
    let t = parseInt(readLine());
    for (let i = 0; i < t; i++) {
        let [N, E] = readLine().split(' ');
        let adj = new Array(N);
        for (let i = 0; i < N; i++) {
            adj[i] = new Array();
        }
        for (let i = 0; i < E; i++) {
            let input_line = readLine().split(' ');
            let u = parseInt(input_line[0]);
            let v = parseInt(input_line[1]);
            adj[u].push(v);
            // adj[v].push(u);
        }
        // console.log(adj);
        // for (let i = 0; i < N; i++) {
        //     let arr = [];
        //     for (let v of adj[i]) {
        //         arr.push(v);
        //     }
        //     console.log(arr);
        // }
        bfs(N, adj);
        // console.table(adj);
    }
}