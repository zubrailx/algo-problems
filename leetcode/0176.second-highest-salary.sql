# Write your MySQL query statement below
select max(salary) as SecondHighestSalary 
from employee a
where salary < (select max(b.salary) from employee b);

# also can be used limit and offset
