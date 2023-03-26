// let yo = new Array(10).fill(0);
let adj = new Map();
for (let i = 0; i < 3; i++) {
    adj.set(i, new Set());
}
adj.get(0).add(2);
adj.get(0).add(2);
adj.get(0).add(1);
console.log(adj.get(0));