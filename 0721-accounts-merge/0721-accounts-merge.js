/**
 * @param {string[][]} accounts
 * @return {string[][]}
 */
function init(n) {
  let arr = new Array(n);

  for (let i = 0; i < n; i++)
    arr[i] = i;

  return arr;
}

function find(x, parent) {
  if (parent[x] !== x)
    parent[x] = find(parent[x], parent);

  return parent[x];
}

function union(a, b, parent) {
  let rootA = find(a, parent);
  let rootB = find(b, parent);

  if (rootA !== rootB)
    parent[rootA] = rootB;
}
var accountsMerge = function (accounts) {
  let parentArr = init(accounts.length);
  let map = new Map();
  for (let i = 0; i < accounts.length; i++) {
    for (let j = 1; j < accounts[i].length; j++) {
      if (map.has(accounts[i][j]))
        union(map.get(accounts[i][j]), i, parentArr);
      else
        map.set(accounts[i][j], i);
    }
  }
  let result = new Array(accounts.length).fill(null);

  for (let [email, index] of map) {

    let root = find(index, parentArr);

    if (result[root] === null)
      result[root] = [email];
    else
      result[root].push(email);
  }
   console.log(result);
  let ans = new Array();
   for(let i =0 ; i < result.length ;i++){
    if(result[i] == null ) continue;
    let ans1 = []
    // ans1.push(accounts[i][0]);
    for(let j =0 ; j < result[i].length;j++){
          ans1.push(result[i][j])
    }
    ans1.sort();
    ans.push([accounts[i][0],...ans1])
   } 
  return ans;
};