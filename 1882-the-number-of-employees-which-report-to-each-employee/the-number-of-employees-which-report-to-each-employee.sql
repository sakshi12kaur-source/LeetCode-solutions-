/* Write your T-SQL query statement below */
select emp.reports_to as employee_id, mgr.name, count(*) as reports_count, ROUND(AVG(emp.age * 1.0), 0) as average_age
from employees emp
inner join employees mgr
on emp.reports_to = mgr.employee_id
group by emp.reports_to, mgr.name
order by employee_id