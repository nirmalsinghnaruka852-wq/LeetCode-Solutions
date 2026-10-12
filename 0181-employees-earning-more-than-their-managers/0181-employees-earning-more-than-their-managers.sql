# Write your MySQL query statement below


--  u just have to return employees who earning more then their managers  ;
-- there is only one table which is the Employee ;
-- now the task is to merge the table with the currentTable ;

select t1.name   as Employee 
from Employee as t1 
left join Employee as t2
on t1.managerId = t2.id 
where t1.salary > t2.salary ;


 