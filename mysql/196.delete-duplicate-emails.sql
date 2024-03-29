#
# [196] Delete Duplicate Emails
#
# https://leetcode.com/problems/delete-duplicate-emails/description/
#
# database
# Easy (26.05%)
# Total Accepted:    46.1K
# Total Submissions: 176.3K
# Testcase Example:  '{"headers": {"Person": ["Id", "Email"]}, "rows": {"Person": [[1, "john@example.com"], [2, "bob@example.com"], [3, "john@example.com"]]}}'
#
# 
# Write a SQL query to delete all duplicate email entries in a table named
# Person, keeping only unique emails based on its smallest Id.
# 
# 
# +----+------------------+
# | Id | Email            |
# +----+------------------+
# | 1  | john@example.com |
# | 2  | bob@example.com  |
# | 3  | john@example.com |
# +----+------------------+
# Id is the primary key column for this table.
# 
# 
# For example, after running your query, the above Person table should have the
# following rows:
# 
# +----+------------------+
# | Id | Email            |
# +----+------------------+
# | 1  | john@example.com |
# | 2  | bob@example.com  |
# +----+------------------+
# 
#
# Write your MySQL query statement below

delete p1 from Person p1
join Person p2
where p1.Id > p2.Id and p1.Email = p2.Email;
