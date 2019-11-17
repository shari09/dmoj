function solve(comparisons, height, target) {
  let queue = [];
  queue.push(height);
  while(queue.length > 0) {
    height = queue.shift();
    if (height === target) {
      return true;
    }
    comparisons[height].forEach(shorter => queue.push(shorter));
  }
}


const gets = () => require('readline-sync').question();
const print = (x) => console.log(x);

const [numS, numCompared] = gets().split(' ').map(n => Number(n));

let x, y;
let comparisons = {};
for (let i = 0; i < numCompared; i++) {
  [x, y] = gets().split(' ').map(n => Number(n));
  if (comparisons[x]) comparisons[x].push(y);
  else comparisons[x] = [y];
  if (!comparisons[y]) comparisons[y] = [];
}

const [p, q] = gets().split(' ').map(n => Number(n));
if (solve(comparisons, p, q)) print('yes');
else if (solve(comparisons, q, p)) print('no');
else print('unknown');