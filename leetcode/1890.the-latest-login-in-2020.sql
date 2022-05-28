# Write your MySQL query statement below
select user_id, max(time_stamp) as last_stamp from (select * from logins where year(time_stamp) = '2020') a group by user_id;

