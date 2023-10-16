/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 *
 * https://leetcode.cn/problems/course-schedule/description/
 *
 * algorithms
 * Medium (53.87%)
 * Total Accepted:    346.4K
 * Total Submissions: 642.9K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
 * 
 * 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi]
 * ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
 * 
 * 
 * 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
 * 
 * 
 * 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：numCourses = 2, prerequisites = [[1,0]]
 * 输出：true
 * 解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
 * 
 * 示例 2：
 * 
 * 
 * 输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
 * 输出：false
 * 解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * prerequisites[i] 中的所有课程对 互不相同
 * 
 * 
 */
class Solution {
  std::unordered_map<int, vector<int>> edges;
  std::unordered_map<int, int> nodes_indegree;

  std::unordered_map<int, vector<int>> all_dependencies;
  std::unordered_set<int> total_nodes;
  std::unordered_set<int> visited_nodes;

  bool valid = true;
  vector<int> visit;
      
public:
  void dfs(int v) {
    visit[v] = 1;

    for (auto node : edges[v]) {
      if (visit[node] == 0) {
        dfs(node);
      } else if (visit[node] == 1) {
        valid = false;
        return;
      }
    }

    visit[v] = 2;
  }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      visit.resize(numCourses);

      for (const auto& edge : prerequisites) {
        edges[edge[1]].push_back(edge[0]);
      }

      for (size_t i = 0; i < numCourses; ++i) {
        if (visit[i] == 0) {
          dfs(i);
        }

        if (!valid) {
          return false;
        }
      }

      return true;
    }

    bool canFinish2(int numCourses, vector<vector<int>>& prerequisites) {
      for (auto& edge : prerequisites) {
        edges[edge[1]].push_back(edge[0]);
        nodes_indegree[edge[0]]++;

        if (!nodes_indegree.contains(edge[1])) {
          nodes_indegree[edge[1]] = 0;
        }
      }

      vector<int> starters;
      for (auto [node, indegree] : nodes_indegree) {
        if (indegree == 0) {
          starters.push_back(node);
        }
      }

      std::unordered_set<int> visited;

      while (!starters.empty()) {
        vector<int> next_starters;

        for (auto node : starters) {
          visited.insert(node);
          for (auto neigh : edges[node]) {
            nodes_indegree[neigh]--;
            if (nodes_indegree[neigh] == 0) {
              next_starters.push_back(neigh);
            }
          }
        }

        swap(starters, next_starters);
      }

      return nodes_indegree.size() == visited.size();
    }

  bool hasCycle(int node, std::unordered_set<int>& visited) {
    visited_nodes.insert(node);

    if (visited.contains(node)) {
      return true;
    }

    visited.insert(node);
    for (const auto& next : edges[node]) {
      if (hasCycle(next, visited)) {
        return true;
      }
    }
    visited.erase(node);

    return false;
  }

    bool canFinish1(int numCourses, vector<vector<int>>& prerequisites) {
      if (prerequisites.empty()) {
        return true;
      }

      for (auto& pre_require : prerequisites) {
        edges[pre_require[1]].push_back(pre_require[0]);
        all_dependencies[pre_require[0]].push_back(pre_require[1]);

        total_nodes.insert(pre_require[0]);
        total_nodes.insert(pre_require[1]);
      }

      vector<int> starters;
      for (auto n : total_nodes) {
        if (!all_dependencies.contains(n)) {
          starters.push_back(n);
        }
      }

      if (starters.empty()) {
        return false;
      }

      for (auto starter : starters) {
        std::unordered_set<int> visited;
        if (hasCycle(starter, visited)) {
          return false;
        }
      }

      return total_nodes.size() == visited_nodes.size();
    }
};
