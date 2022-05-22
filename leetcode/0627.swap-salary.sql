# Write your MySQL query statement below
#update salary
#set sex = if(sex = 'f', 'm', 'f');

update salary
set sex = case 
  when sex = 'm' then 'f'
  when sex = 'f' then 'm'
  else sex
end;
