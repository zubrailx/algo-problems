# Write your MySQL query statement below
select a.customer_number 
from 
  (select customer_number, count(order_number) 
   from orders 
   group by 1 
   order by 2 desc
  ) a limit 1; 
  

# can order by column that is not selected:

# SELECT customer_number
# FROM Orders
# GROUP BY customer_number
# ORDER BY COUNT(customer_number) DESC LIMIT 1;
