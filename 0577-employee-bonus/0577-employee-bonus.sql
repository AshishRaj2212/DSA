# Write your MySQL query statement below
select emp.name, b.bonus
from Employee emp
left join Bonus b
on emp.empID = b.empID
where b.bonus < 1000 or b.bonus is null