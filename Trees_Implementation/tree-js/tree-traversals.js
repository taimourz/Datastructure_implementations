const { Tree } = require('./tree-main');

Tree.prototype.levelOrder = function(node = this.root) {
    if (!node) return [];
    const result = [];
    const queue = [node];
    while (queue.length > 0) {
        const current = queue.shift();
        result.push(current.val);
        if (current.left) queue.push(current.left);
        if (current.right) queue.push(current.right);
    }
    return result;
};

Tree.prototype.inorder = function(node = this.root) {
    if (!node) return [];
    const result = [];
    result.push(...this.inorder(node.left));
    result.push(node.val);
    result.push(...this.inorder(node.right));
    return result;
};

Tree.prototype.preorder = function(node = this.root) {
    if (!node) return [];
    const result = [node.val];
    result.push(...this.preorder(node.left));
    result.push(...this.preorder(node.right));
    return result;
};

Tree.prototype.postorder = function(node = this.root) {
    if (!node) return [];
    const result = [];
    result.push(...this.postorder(node.left));
    result.push(...this.postorder(node.right));
    result.push(node.val);
    return result;
};