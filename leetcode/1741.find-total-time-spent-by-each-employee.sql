# Write your MySQL query statement below

select event_day as day, emp_id, sum(out_time - in_time) as total_time from Employees group by day, emp_id;
#                   ^^^  ^^^^^^
# order strts  with  1     2
# select event_day as day, emp_id, sum(out_time - in_time) as total_time from Employees 1,2;
