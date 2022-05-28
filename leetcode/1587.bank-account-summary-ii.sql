# Write your MySQL query statement below
select u.name, sum(t.amount) as balance
from users as u
inner join 
transactions as t using(account)
group by u.account
having sum(t.amount) > 10000;
