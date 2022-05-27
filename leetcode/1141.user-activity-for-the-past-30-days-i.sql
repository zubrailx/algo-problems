# Write your MySQL query statement below
select activity_date as day, count(distinct user_id) as active_users
from activity 
where datediff('2019-07-27', activity_date) < 30 and datediff('2019-07-27', activity_date) >= 0
group by day;

# can be replaces with datediff('2019-07-27', activity_date) between 0 and 29

