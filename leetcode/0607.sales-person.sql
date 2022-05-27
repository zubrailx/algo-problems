# Write your MySQL query statement below
select distinct sp.name as name
from salesperson as sp
where sales_id not in (select distinct sales_id from orders join company using(com_id) where company.name = "RED");

# without inner queries
# select salesperson.name
# from orders o join company c on (o.com_id = c.com_id and c.name = 'RED')
# right join salesperson on salesperson.sales_id = o.sales_id
# where o.sales_id is null

