// let yo = new Array(10).fill(0);
// let adj = new Map();
// for (let i = 0; i < 3; i++) {
//     adj.set(i, new Set());
// }
// adj.get(0).add(2);
// adj.get(0).add(2);
// adj.get(0).add(1);
// console.log(adj.get(0));
// const zeros = (m, n) => [...Array(m)].map((e) => Array(n).fill(0));
// // console.log(zeros(3, 4));
// console.log(
// 	Array(2)
// 		.fill(0)
// 		.map((e) => Array(2).fill(0))
// );

let yo = [...Array(2)].map((n) => Array(2).fill(0));
let visited = Array(3);
visited[0] = 1;
visited[1] = 2;
visited[2] = 3;
visited.push(0);
visited.push(1);
visited.push(2);
// console.log(visited);
for (let [i, index] of visited.entries()) {
	console.log(i, index);
}
