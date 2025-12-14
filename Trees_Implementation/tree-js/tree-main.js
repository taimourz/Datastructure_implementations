class TreeNode {
    constructor(val = 0, left = null, right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Tree {
    constructor(root = null) {
        if (root === null) {
            this.root = null;
        } else if (root instanceof TreeNode) {
            this.root = root;
        } else if (Array.isArray(root)) {
            this.root = this.buildFromArray(root);
        } else {
            throw new Error("Root must be an array, TreeNode, or null");
        }
    }

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *                     buildFromArray
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * 
 *
 *     Example:
 *             [1, 2, 3, null, 4, null, 5]
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * 
 *     Initial:
 *              values = [1, 2, 3, null, 4, null, 5]
 *              i = 1, queue = [1]
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * 
 *     Iteration 1: Process node 1
 * 
 *       - Left child       : values[1] = 2  → create node(2), add to queue
 *       - Right child      : values[2] = 3 → create node(3), add to queue
 * 
 *       - i = 3, queue = [2, 3]
 * 
 *       - Tree:     1
 *                  / \
 *                 2   3
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * 
 *     Iteration 2: Process node 2
 * 
 *       - Left child       : values[3] = null → skip
 *       - Right child      : values[4] = 4 → create node(4), add to queue
 * 
 *       - i = 5, queue = [3, 4]
 * 
 *       - Tree:     1
 *                  / \
 *                 2   3
 *                  \
 *                   4
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * 
 *     Iteration 3: Process node 3
 * 
 *       - Left child       : values[5] = null → skip
 *       - Right child      : values[6] = 5 → create node(5), add to queue
 * 
 *       - i = 7, queue = [4, 5]
 * 
 *       - Tree:     1
 *                  / \
 *                 2   3
 *                  \   \
 *                   4   5
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * 
 *     Final tree structure:
 *           1
 *          / \
 *         2   3
 *          \   \
 *           4   5
 *
 **/
buildFromArray(values) {
    if (!values || values.length === 0 || values[0] === null) {
        return null;
    }
    
    const root = new TreeNode(values[0]);
    const queue = [root];
    let i = 1;
    
    while (queue.length > 0 && i < values.length) {
        const node = queue.shift();
        
        if (i < values.length && values[i] !== null) {
            node.left = new TreeNode(values[i]);
            queue.push(node.left);
        }
        i++;
        
        if (i < values.length && values[i] !== null) {
            node.right = new TreeNode(values[i]);
            queue.push(node.right);
        }
        i++;
    }
    
    return root;
}

}

function createTree(root) {
    const tree = new Tree(root);
    return tree.root;
}

if (typeof module !== 'undefined' && module.exports) {
    module.exports = { TreeNode, Tree, createTree };
}

if (typeof exports !== 'undefined') {
    exports.TreeNode = TreeNode;
    exports.Tree = Tree;
    exports.createTree = createTree;
}