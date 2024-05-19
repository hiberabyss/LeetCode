/*
 * @lc app=leetcode.cn id=427 lang=cpp
 *
 * [427] Construct Quad Tree
 *
 * https://leetcode.cn/problems/construct-quad-tree/description/
 *
 * algorithms
 * Medium (71.54%)
 * Total Accepted:    30.7K
 * Total Submissions: 42.9K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * 给你一个 n * n 矩阵 grid ，矩阵由若干 0 和 1 组成。请你用四叉树表示该矩阵 grid 。
 * 
 * 你需要返回能表示矩阵 grid 的 四叉树 的根结点。
 * 
 * 四叉树数据结构中，每个内部节点只有四个子节点。此外，每个节点都有两个属性：
 * 
 * 
 * val：储存叶子结点所代表的区域的值。1 对应 True，0 对应 False。注意，当 isLeaf 为 False 时，你可以把 True 或者
 * False 赋值给节点，两种值都会被判题机制 接受 。
 * isLeaf: 当这个节点是一个叶子结点时为 True，如果它有 4 个子节点则为 False 。
 * 
 * 
 * 
 * class Node {
 * ⁠   public boolean val;
 * public boolean isLeaf;
 * public Node topLeft;
 * public Node topRight;
 * public Node bottomLeft;
 * public Node bottomRight;
 * }
 * 
 * 我们可以按以下步骤为二维区域构建四叉树：
 * 
 * 
 * 如果当前网格的值相同（即，全为 0 或者全为 1），将 isLeaf 设为 True ，将 val 设为网格相应的值，并将四个子节点都设为 Null
 * 然后停止。
 * 如果当前网格的值不同，将 isLeaf 设为 False， 将 val 设为任意值，然后如下图所示，将当前网格划分为四个子网格。
 * 使用适当的子网格递归每个子节点。
 * 
 * 
 * 
 * 
 * 如果你想了解更多关于四叉树的内容，可以参考 wiki 。
 * 
 * 四叉树格式：
 * 
 * 你不需要阅读本节来解决这个问题。只有当你想了解输出格式时才会这样做。输出为使用层序遍历后四叉树的序列化形式，其中 null
 * 表示路径终止符，其下面不存在节点。
 * 
 * 它与二叉树的序列化非常相似。唯一的区别是节点以列表形式表示 [isLeaf, val] 。
 * 
 * 如果 isLeaf 或者 val 的值为 True ，则表示它在列表 [isLeaf, val] 中的值为 1 ；如果 isLeaf 或者 val
 * 的值为 False ，则表示值为 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：grid = [[0,1],[1,0]]
 * 输出：[[0,1],[1,0],[1,1],[1,1],[1,0]]
 * 解释：此示例的解释如下：
 * 请注意，在下面四叉树的图示中，0 表示 false，1 表示 True 。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：grid =
 * [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
 * 
 * 输出：[[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
 * 解释：网格中的所有值都不相同。我们将网格划分为四个子网格。
 * topLeft，bottomLeft 和 bottomRight 均具有相同的值。
 * topRight 具有不同的值，因此我们将其再分为 4 个子网格，这样每个子网格都具有相同的值。
 * 解释如下图所示：
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == grid.length == grid[i].length
 * n == 2^x 其中 0 <= x <= 6
 * 
 * 
 */
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

  bool isSame(std::vector<std::vector<int>>& grid, int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; i++) {
      for (size_t j = y1; j <= y2; ++j) {
        if (grid[i][j] != grid[x1][y1]) {
          return false;
        }
      }
    }
    return true;
  }

  Node* newTree(std::vector<std::vector<int>>& grid, int x1, int y1, int x2, int y2) {
    Node* tree = new Node();
    if (isSame(grid, x1, y1, x2, y2)) {
      tree->isLeaf = true;
      tree->val = !!grid[x1][y1];
    } else {
      buildTree(grid, tree, x1, y1, x2, y2);
    }
    return tree;
  }

  void buildTree(std::vector<std::vector<int>>& grid, Node* root, int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
      root->isLeaf = true;
      root->val = !!grid[x1][y1];
      return;
    }

    int cx = (x1 + x2) / 2;
    int cy = (y1 + y2) / 2;

    int tlx1 = x1, tly1 = y1;
    int tlx2 = cx, tly2 = cy;

    int trx1 = x1, try1 = cy+1;
    int trx2 = cx, try2 = y2;

    int blx1 = cx+1, bly1 = y1;
    int blx2 = x2, bly2 = cy;

    int brx1 = cx + 1, bry1 = cy + 1;
    int brx2 = x2, bry2 = y2;

    root->topLeft = newTree(grid, tlx1, tly1, tlx2, tly2);
    root->topRight = newTree(grid, trx1, try1, trx2, try2);
    root->bottomLeft = newTree(grid, blx1, bly1, blx2, bly2);
    root->bottomRight = newTree(grid, brx1, bry1, brx2, bry2);
  }

    Node* construct(vector<vector<int>>& grid) {
      int N = grid.size();
      return newTree(grid, 0, 0, N-1, N-1);
    }
};
