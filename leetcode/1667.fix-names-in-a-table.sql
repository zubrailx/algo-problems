# Write your MySQL query statement below
select users.user_id, concat(upper(substr(users.name, 1, 1)), LOWER(substr(users.name, 2, length(users.name) - 1))) as name from users order by 1;

# function substr(users.name, 2, length(usrs.name) - 1) can be simplified:
#  -> substr(users.name, 2)

# without substring:
# left(str, length), right() - extranct length symbols from str

