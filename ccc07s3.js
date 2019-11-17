function search(friendList, x, y) {
  let queue = [];
  let visited = [];
  queue.push([x, 0]);
  visited[x] = true;

  while (queue.length > 0) {
    [x, dist] = queue.shift();
    if (x === y) {
      return dist;
    }

    friendList[x].forEach(friend => {
      if (!visited[friend]) {
        visited[friend] = true;
        queue.push([friend, dist+1]);
      }
    });
  }
  return -1;
}


const gets = () => require('readline-sync').question();
const print = (x) => console.log(x);
const numStudents = Number(gets());


let friends = {};

for (let i = 0; i < numStudents; i++) {
  let [x, y] = gets().split(' ').map(n => Number(n));
  if (friends[x]) friends[x].push(y);
  else friends[x] = [y];
}

let [searchX, searchY] = gets().split(' ').map(n => Number(n));

while (searchX !== 0 && searchY !== 0) {
  let distance = search(friends, searchX, searchY);
  if (distance >= 0) print('Yes ' + (distance-1));
  else print('No');
  [searchX, searchY] = gets().split(' ').map(n => Number(n));
}