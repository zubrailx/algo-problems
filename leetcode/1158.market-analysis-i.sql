# Write your MySQL query statement below
select user_id as buyer_id, join_date, sum(if(year(order_date) = '2019', 1, 0)) as orders_in_2019
from users
left join orders on orders.buyer_id = users.user_id
group by user_id;

