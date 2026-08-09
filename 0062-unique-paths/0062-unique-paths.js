/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
function element(row, col, array) {
  if (row == 0 && col == 0) return 1;
  let right = 0;
  let top = 0;
  if (col - 1 >= 0) top = array[row][col - 1];
  if (row - 1 >= 0) right = array[row - 1][col];
  return top + right;
}

var uniquePaths = function (m, n) {
  let top = 0;
  let array = new Array(m).fill(null).map(() => new Array(n).fill(0));
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      top = array[i][j] = element(i, j, array);
    }
  }
  return top;
};
//  let count the tc
//  we will go to the each block the block size is
//  time complxecity = O(m*n) and space also
