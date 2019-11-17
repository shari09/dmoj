function Island(num, time, destruction, totalTime=0, hullHeight=0, visited=[]) {
  this.num = num;
  this.time = time;
  this.destruction = destruction;
  this.totalTime = totalTime;
  this.hullHeight = hullHeight;
  this.visited = visited;
}

function minTime(routes, hullHeight, start, end) {
  let queue = [];
  queue.push(new Island(start, 0, 0, 0, 0, [start]));

  let bestTime = Number.MAX_SAFE_INTEGER;
  let pos;
  let found = false;

  while (queue.length > 0) {
    pos = queue.shift();
    
    while (pos.hullHeight >= hullHeight && queue.length > 0) {
      pos = queue.shift();
    }

    if (pos.num === end && pos.hullHeight < hullHeight) {
      // console.log(pos);
      found = true;
      bestTime = Math.min(pos.totalTime, bestTime);
    }
    
    routes[pos.num].forEach(next => {
      if (pos.visited.indexOf(next.num) === -1) {
        queue.push(new Island(next.num, 
                              next.time, 
                              next.destruction, 
                              pos.totalTime + next.time, 
                              pos.hullHeight + next.destruction,
                              [...next.visited, ...pos.visited, next.num]));
      }
    });
  }
  if (found) return bestTime;
  else return -1;
}


const gets = () => require('readline-sync').question();
const print = (x) => console.log(x);
const getNum = () => gets().split(' ').map(n => Number(n));

const [hullHeight, numIslands, numRoutes] = getNum();

let routes = {};

for (let i = 0; i < numRoutes; i++) {
  let [a, b, time, destruction] = getNum();
  if (routes[a]) routes[a].push(new Island(b, time, destruction));
  else routes[a] = [new Island(b, time, destruction)];

  if (routes[b]) routes[b].push(new Island(a, time, destruction));
  else routes[b] = [new Island(a, time, destruction)];
}

const [start, end] = getNum();
print(minTime(routes, hullHeight, start, end));