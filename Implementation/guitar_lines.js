const fs = require('fs');
const stdin = (process.platform === 'linux' ? fs.readFileSync('/dev/stdin').toString() : `7 2
10 100
100 5
`).split('\n');
 
const input = (() => {
    let line = 0;
    return () => stdin[line++];
})();

let [N, M] = input().split(' ').map(Number);
let A = [];
let B = [];
for (let i = 0 ; i < M ; i++) {
	let [a, b] = input().split(' ').map(Number);
	B.push(a);
	A.push(b);
}
A.sort((a,b) => a - b);
B.sort((a,b) => a - b);
if (A[0] * 6 < B[0]) B[0] = 6 * A[0];
let ans = B[0] * Math.floor(N / 6) + (B[0] > A[0] * parseInt(N % 6) ? A[0] * parseInt(N % 6) : B[0]);
console.log(ans);
