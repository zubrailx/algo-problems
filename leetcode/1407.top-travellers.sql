# Write your MySQL query statement below
select name, sum(if(distance is null, 0, distance)) as travelled_distance
from rides
right join users on rides.user_id = users.id
group by users.id
order by travelled_distance desc, name asc;

# fnull(sum(r.distance), 0)
