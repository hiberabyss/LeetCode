--  #
--  # [626] Exchange Seats
--  #
--  # https://leetcode.com/problems/exchange-seats/description/
--  #
--  # database
--  # Medium (48.89%)
--  # Total Accepted:    9K
--  # Total Submissions: 18.4K
--  # Testcase Example:  '{"headers": {"seat": ["id","student"]}, "rows": {"seat": [[1,"Abbot"],[2,"Doris"],[3,"Emerson"],[4,"Green"],[5,"Jeames"]]}}'
--  #
--  # Mary is a teacher in a middle school and she has a table seat storing
--  # students' names and their corresponding seat ids.
--  # The column id is continuous increment.
--  # Mary wants to change seats for the adjacent students.
--  # Can you write a SQL query to output the result for Mary?
--  # 
--  # +---------+---------+
--  # |    id   | student |
--  # +---------+---------+
--  # |    1    | Abbot   |
--  # |    2    | Doris   |
--  # |    3    | Emerson |
--  # |    4    | Green   |
--  # |    5    | Jeames  |
--  # +---------+---------+
--  # 
--  # For the sample input, the output is:
--  # 
--  # +---------+---------+
--  # |    id   | student |
--  # +---------+---------+
--  # |    1    | Doris   |
--  # |    2    | Abbot   |
--  # |    3    | Green   |
--  # |    4    | Emerson |
--  # |    5    | Jeames  |
--  # +---------+---------+
--  # 
--  # 
--  # Note:
--  # If the number of students is odd, there is no need to change the last one's
--  # seat.
--  # 
--  #
--  # Write your MySQL query statement below

select
(case
when id % 2 != 0 and counts != id then id + 1
when mod(id, 2) != 0 and counts = id then id
else id - 1
end) as id, student
from
seat, (select count(*) as counts from seat) as seat_counts
order by id;
