# Write your MySQL query statement below
select 
  employee_id,
  case 
    when employee_id % 2 = 1 and substring(name, 1, 1) != 'M'
    then salary
    else 0
  end as bonus
from employees;

# substring(name, start_pos, length);
# = is equals
# substring(name, 1, 1) != 'M' |same as| name not like 'M%'

