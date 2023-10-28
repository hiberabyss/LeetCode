/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 *
 * https://leetcode.cn/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (53.81%)
 * Total Accepted:    60.3K
 * Total Submissions: 112K
 * Testcase Example:  '-3\n0\n3\n4\n0\n-1\n9\n2'
 *
 * 给你 二维 平面上两个 由直线构成且边与坐标轴平行/垂直 的矩形，请你计算并返回两个矩形覆盖的总面积。
 * 
 * 每个矩形由其 左下 顶点和 右上 顶点坐标表示：
 * 
 * 
 * 
 * 第一个矩形由其左下顶点 (ax1, ay1) 和右上顶点 (ax2, ay2) 定义。
 * 第二个矩形由其左下顶点 (bx1, by1) 和右上顶点 (bx2, by2) 定义。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
 * 输出：45
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 =
 * 2
 * 输出：16
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -10^4 <= ax1, ay1, ax2, ay2, bx1, by1, bx2, by2 <= 10^4
 * 
 * 
 */
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
      int area1 = (ax2 - ax1) * (ay2 - ay1);
      int area2 = (bx2 - bx1) * (by2 - by1);

      int cx1 = max(ax1, bx1);
      int cy1 = max(ay1, by1);
      int cx2 = min(ax2, bx2);
      int cy2 = min(ay2, by2);

      int area_intersect = max(cx2 - cx1, 0) * max(0, cy2 - cy1);

      return area1 + area2 - area_intersect;
    }

    int computeArea1(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
      std::tuple<int, int, int, int> r1 = {ax1, ay1, ax2, ay2};
      std::tuple<int, int, int, int> r2 = {bx1, by1, bx2, by2};

      // make sure rectangle r1 in the left of r2
      if (ax1 > bx1) {
        std::swap(r1, r2);
      }

      auto rec_area = [](const tuple<int,int,int,int>& rec) {
        auto [x1, y1, x2, y2] = rec;
        return (x2 - x1) * (y2 - y1);
      };

      const auto [r1_x1, r1_y1, r1_x2, r1_y2] = r1;
      const auto [r2_x1, r2_y1, r2_x2, r2_y2] = r2;

      // r1 contains r2
      if (r1_x1 <= r2_x1 && r1_y1 <= r2_y1 &&
          r1_x2 >= r2_x2 && r1_y2 >= r2_y2) {
        return rec_area(r1);
      }

      auto is_in_r1 = [&r1] (int x, int y) -> bool {
        auto [x1, y1, x2, y2] = r1;
        return x1 <= x && x <= x2 && y1 <= y && y <= y2;
      };

      // r1 intersect with r2
      if (is_in_r1(r2_x1, r2_y1) || is_in_r1(r2_x1, r2_y2) ||
          is_in_r1(r2_x1, (r2_y1 + r2_y2) / 2)) {
        decltype(r1) rec_intersect = {
          max(r1_x1, r2_x1), max(r1_y1, r2_y1),
          min(r1_x2, r2_x2), min(r1_y2, r2_y2),
        };

        return rec_area(r1) + rec_area(r2) - rec_area(rec_intersect) ;
      }

      return rec_area(r1) + rec_area(r2);

      return 0;
    }
};
