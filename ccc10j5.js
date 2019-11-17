function valid(x, y) {
  if (1 <= x && x <= 8 && 1 <= y && y <= 8) {
    return true;
  }
  return false;
}

function Square(x, y, move) {
  this.x = x;
  this.y = y;
  this.move = move;
}

function solve(start, end) {
  const xMove = [2, 2, -2, -2, 1, 1, -1, -1];
  const yMove = [1, -1, 1, -1, 2, -2, 2, -2];

  let queue = [];
  let visited = new Array(9).fill(false).map(row => {
    return new Array(9).fill(false);
  });

  queue.push(new Square(start[0], start[1], 0));

  while (queue.length > 0) {
    const pos = queue.shift();

    if (pos.x === end[0] && pos.y === end[1]) {
      return pos.move;
    }

    for (let i = 0; i < 8; i++) {
      const x = pos.x + xMove[i];
      const y = pos.y + yMove[i];
      if (valid(x, y) && !visited[x][y]) {
        visited[x][y] = true;
        queue.push(new Square(x, y, pos.move+1));
      }
    }
  } 
}

const [x1, y1, x2, y2] = [1, 1, 8, 8];
// const line1 = gets();
// const line2 = gets();
// const x1 = Number(line1[0]);
// const y1 = Number(line1[2]);
// const x2 = Number(line2[0]);
// const y2 = Number(line2[2]);

console.log(solve([x1, y1], [x2, y2]));