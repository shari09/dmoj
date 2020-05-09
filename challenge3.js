const gets = require('readline-sync').question;
const print = console.log;

const findSum = (num) => num.split('').reduce((acc, cur) => Number(acc) + Number(cur));

const q = Number(gets());

for (let t = 0; t < q; t++) {
  let [n, m] = gets().split(' ');
  let maxSum = findSum(m);
  for (let i = 1; i < m.length; i++) {
    if (m.length <= 1 || m.length <= i) break;
    m = (Number(m.slice(0, -i))-1).toString()+'9'.repeat(i);
    if (Number(m) < Number(n)) break;
    maxSum = Math.max(maxSum, findSum(m));
  }
  print(maxSum);
}