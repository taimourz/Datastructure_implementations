const { Tree, TreeNode } = require('./tree-main');

Tree.prototype.printStructure = function() {
    if (!this.root) {
        console.log("Empty tree");
        return;
    }

    function makeCopy(node) {
        if (!node) return null;
        const newNode = new TreeNode(node.val);
        newNode.left = makeCopy(node.left);
        newNode.right = makeCopy(node.right);
        return newNode;
    }

    function getHeight(node) {
        if (!node) return 0;
        return Math.max(getHeight(node.left), getHeight(node.right)) + 1;
    }

    function fillTree(node, height) {
        if (height <= 1 || !node) return;
        
        if (!node.left) {
            node.left = new TreeNode(' ');
        }
        if (!node.right) {
            node.right = new TreeNode(' ');
        }
        fillTree(node.left, height - 1);
        fillTree(node.right, height - 1);
    }

    const totalLayers = getHeight(this.root);
    const tree = makeCopy(this.root);
    fillTree(tree, totalLayers);

    let output = '';
    const queue = [tree];
    let gen = 1;

    while (queue.length > 0) {
        const levelSize = queue.length;
        const copy = [...queue];
        queue.length = 0;

        let firstItemInLayer = true;
        let edgesString = '';
        let extraSpacesNextNode = false;

        for (let i = 0; i < levelSize; i++) {
            const node = copy[i];
            let spacesFront = Math.pow(2, totalLayers - gen + 1) - 2;
            let spacesMid = Math.pow(2, totalLayers - gen + 2) - 2;
            let dashCount = Math.pow(2, totalLayers - gen) - 2;
            
            if (dashCount < 0) dashCount = 0;
            
            spacesMid = spacesMid - (dashCount * 2);
            spacesFront = spacesFront - dashCount;
            
            const initPadding = 2;
            spacesFront += initPadding;
            
            if (firstItemInLayer) {
                edgesString += ' '.repeat(initPadding);
            }

            let edgeSym = ' ';
            if (node.left && node.left.val !== ' ') {
                edgeSym = '/';
            }

            if (firstItemInLayer) {
                edgesString += ' '.repeat(Math.pow(2, totalLayers - gen) - 1) + edgeSym;
            } else {
                edgesString += ' '.repeat(Math.pow(2, totalLayers - gen + 1) + 1) + edgeSym;
            }
            
            edgeSym = ' ';
            if (node.right && node.right.val !== ' ') {
                edgeSym = '\\';
            }
            edgesString += ' '.repeat(Math.max(0, Math.pow(2, totalLayers - gen + 1) - 3)) + edgeSym;

            let dashLeft = ' ';
            if (node.left && node.left.val !== ' ') {
                dashLeft = '_';
            }
            let dashRight = ' ';
            if (node.right && node.right.val !== ' ') {
                dashRight = '_';
            }

            let extraSpaces = 0;
            if (extraSpacesNextNode) {
                extraSpaces = 1;
                extraSpacesNextNode = false;
            }

            const dataLength = (node.val || '').toString().length;
            if (dataLength > 1) {
                if (dataLength % 2 === 1) {
                    if (dashCount > 0) {
                        dashCount -= ((dataLength - 1) / 2);
                    } else {
                        spacesMid -= (dataLength - 1) / 2;
                        spacesFront -= (dataLength - 1) / 2;
                        if (dataLength !== 1) {
                            extraSpacesNextNode = true;
                        }
                    }
                } else {
                    if (dashCount > 0) {
                        dashCount -= ((dataLength) / 2) - 1;
                        extraSpacesNextNode = true;
                    } else {
                        spacesMid -= (dataLength - 1);
                        spacesFront -= (dataLength - 1);
                    }
                }
            }

            if (dashCount < 0) dashCount = 0;

            if (firstItemInLayer) {
                output += ' '.repeat(spacesFront) + dashLeft.repeat(dashCount) + node.val + dashRight.repeat(dashCount) + ' ';
                firstItemInLayer = false;
            } else {
                output += ' '.repeat(spacesMid - extraSpaces) + dashLeft.repeat(dashCount) + node.val + dashRight.repeat(dashCount) + ' ';
            }

            if (node.left) queue.push(node.left);
            if (node.right) queue.push(node.right);
        }

        if (queue.length > 0) {
            output += '\n' + edgesString + '\n';
        }

        gen += 1;
    }

    console.log(output);
}; 


Tree.prototype.printTraversals = function() {
    if (!this.root) {
        console.log("Empty tree");
        return;
    }
    console.log("Level Order:", this.levelOrder());
    console.log("Inorder:    ", this.inorder());
    console.log("Preorder:   ", this.preorder());
    console.log("Postorder:  ", this.postorder());
};