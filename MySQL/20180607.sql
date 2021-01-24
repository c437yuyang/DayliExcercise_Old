# 获取Employees中的first_name，查询按照first_name最后两个字母，按照升序进行排列
select first_name
from Employees
order by right(first_name,2) asc

# 按照dept_no进行汇总，属于同一个部门的emp_no按照逗号进行连接，结果给出dept_no以及连接出的结果employees
SELECT dept_no, group_concat(emp_no) AS employees
FROM dept_emp GROUP BY dept_no

# 查找排除当前最大、最小salary之后的员工的平均工资avg_salary。
select avg(salary)
from salaries
where to_date='9999-01-01' 
and salary !=  
(
    select max(salary) 
    from salaries
    where to_date='9999-01-01'
)
and salary !=  
(
    select min(salary) 
    from salaries
    where to_date='9999-01-01'
)

# 分页查询employees表，每5行一页，返回第2页的数据
select * from employees
limit 5,5
