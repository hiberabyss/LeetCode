#
# [197] Rising Temperature
#
# https://leetcode.com/problems/rising-temperature/description/
#
# database
# Easy (31.44%)
# Total Accepted:    50.4K
# Total Submissions: 160.3K
# Testcase Example:  '{"headers": {"Weather": ["Id", "RecordDate", "Temperature"]}, "rows": {"Weather": [[1, "2015-01-01", 10], [2, "2015-01-02", 25], [3, "2015-01-03", 20], [4, "2015-01-04", 30]]}}'
#
# Given a Weather table, write a SQL query to find all dates' Ids with higher
# temperature compared to its previous (yesterday's) dates.
# 
# 
# +---------+------------------+------------------+
# | Id(INT) | RecordDate(DATE) | Temperature(INT) |
# +---------+------------------+------------------+
# |       1 |       2015-01-01 |               10 |
# |       2 |       2015-01-02 |               25 |
# |       3 |       2015-01-03 |               20 |
# |       4 |       2015-01-04 |               30 |
# +---------+------------------+------------------+
# 
# 
# For example, return the following Ids for the above Weather table:
# 
# 
# +----+
# | Id |
# +----+
# |  2 |
# |  4 |
# +----+
# 
# 
#
# Write your MySQL query statement below

select a.Id as Id
from Weather as a, Weather as b
where a.RecordDate = b.RecordDate + interval 1 day and a.Temperature > b.Temperature;
