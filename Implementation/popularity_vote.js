const fs = require('fs');
const stdin = (process.platform === 'linux' ? fs.readFileSync('/dev/stdin').toString() : `4
3
10
21
10
3
20
10
10
3
10
10
10
4
15
15
15
45
`).split('\n');
const input = (() => {
	let line = 0;
	return () => stdin[line++];
})();

let T = parseInt(input());
let ans = ["majority winner ", "minority winner ", "no winner"];
while(T--) {
	let n = parseInt(input());
	let arr = [];
	let sumVal = 0;
	for (let i = 0 ; i < n ; i++){
		let a = parseInt(input());
		arr.push([a, i + 1]);
		sumVal += a;
	}
	arr.sort((a,b) => a[0] - b[0]);
	if (arr[arr.length-1][0] === arr[arr.length-2][0]) console.log(ans[2]);
	else if (parseInt(sumVal / 2) < arr[arr.length - 1][0]) console.log(ans[0] + String(arr[arr.length - 1][1]));
	else
		console.log(ans[1] + String(arr[arr.length - 1][1]));
}
