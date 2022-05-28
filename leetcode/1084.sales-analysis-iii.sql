# Write your MySQL query statement below
select product_id, product_name
from sales
join product using(product_id)
group by 1
having min(sale_date) >= '2019-01-01' and max(sale_date) <= '2019-03-31';

# cast, having - like where but works with aggregated data
