class Node {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
  }
}
const createTree = () => {
  const D = new Node("D");
  const E = new Node("E");
  const T = new Node("T");
  const K = new Node("K");
  const S = new Node("S");
  const J = new Node("J");
  const B = new Node("B");
  const Y = new Node("Y");
  const H = new Node("H");
  D.left = E;
  D.right = T;
  E.left = Y;
  Y.right = H;
  T.left = K;
  K.left = B;
  T.right = S;
  S.right = J;

  return D;
};

const root = createTree();

const depthFirstValues = (root) => {
  if (root === null) return [];

  const stack = [root];
  const result = [];
  while (stack.length != 0) {
    const current = stack.pop();
    result.push(current.value);

    if (current.right) stack.push(current.right);
    if (current.left) stack.push(current.left);
  }

  return result;
};

const depthFirstValuesRecursion = (node) => {
  if (node === null) return [];

  const leftSide = depthFirstValues(node.left);
  const rightSide = depthFirstValues(node.right);

  return [node.value, ...leftSide, ...rightSide];
};

const depth2 = (node) => {
  if (node === null) return;
  console.log(node.value);
  depth2(node.left);
  depth2(node.right);
};

const breadthFirstValues = (root) => {
  const result = [];
  if (root === null) return result;

  const queue = [root];

  while (queue.length != 0) {
    const current = queue.shift();
    result.push(current.value);

    if (current.left) queue.push(current.left);
    if (current.right) queue.push(current.right);
  }

  return result;
};

const tree = ["", "D", "A", "F", "E", "B", "R", "T", "G", "Q", "", "", "V", "", "J", "L"];

const getRightChild = (idx) => {
  let new_idx = 2 * idx + 1;
  if (tree[idx] !== "" && new_idx < tree.length) {
    return new_idx;
  }
  return -1;
};

const getLeftChild = (idx) => {
  let new_idx = 2 * idx;
  if (tree[idx] !== "" && new_idx < tree.length) {
    return new_idx;
  }
  return -1;
};

const inorder = (i) => {
  if (tree[i] !== "" && i > 0) {
    inorder(getLeftChild(i));
    console.log(tree[i]);
    inorder(getRightChild(i));
  }
};
