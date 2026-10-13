# Write your MySQL query statement below


select id from (
select * , lag(temperature) over(order by recordDate) as pervdata 
     , lag(recordDate) over(order by recordDate) as  prevDate 
from Weather  ) as tempTable 
where  pervdata < temperature and DATEDIFF(recordDate , prevDate) = 1
 ;