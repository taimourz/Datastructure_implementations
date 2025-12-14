const { Tree } = require('./tree-main');

Tree.prototype.height = function(node = this.root) {
    if (!node) return 0;
    const leftHeight = this.height(node.left);
    const rightHeight = this.height(node.right);
    return Math.max(leftHeight, rightHeight) + 1;
};

Tree.prototype.maxDepth = function(node = this.root) {
    if (!node) return 0;
    const leftDepth = 1 + this.maxDepth(node.left);
    const rightDepth = 1 + this.maxDepth(node.right);
    return Math.max(leftDepth, rightDepth);
};

Tree.prototype.getHeight = function() {
    console.log("Height:     ", this.height());
};

Tree.prototype.getDepth = function() {
    console.log("Max Depth:  ", this.maxDepth());
};