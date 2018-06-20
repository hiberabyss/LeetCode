#
# [177] Nth Highest Salary
#
# https://leetcode.com/problems/nth-highest-salary/description/
#
# database
# Medium (21.46%)
# Total Accepted:    37.8K
# Total Submissions: 176.1K
# Testcase Example:  '{"headers": {"Employee": ["Id", "Salary"]}, "argument": 2, "rows": {"Employee": [[1, 100], [2, 200], [3, 300]]}}'
#
# Write a SQL query to get the nth highest salary from the Employee table.
# 
# 
# +----+--------+
# | Id | Salary |
# +----+--------+
# | 1  | 100    |
# | 2  | 200    |
# | 3  | 300    |
# +----+--------+
# 
# 
# For example, given the above Employee table, the nth highest salary where n =
# 2 is 200. If there is no nth highest salary, then the query should return
# null.
# 
# 
# +------------------------+
# | getNthHighestSalary(2) |
# +------------------------+
# | 200                    |
# +------------------------+
# 
# 
#
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
    # Write your MySQL query statement below.
    select Salary from Employee order by Salary desc limit N-1, 1
  );
END
