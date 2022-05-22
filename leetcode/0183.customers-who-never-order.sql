# Write your MySQL query statement below
#select customers.name as Customers from customers where id not in (select distinct customerId from orders);

# example two (using left join)
select customers.name as Customers from customers left join orders on customers.id = orders.customerId where orders.customerId is null;

