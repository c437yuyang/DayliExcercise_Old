# 获取当前（to_date='9999-01-01'）薪水第二多的员工的emp_no以及其对应的薪水salary
select emp_no,salary
from salaries 
where to_date = '9999-01-01'
order by salary desc limit 1,1

# 查找当前薪水(to_date='9999-01-01')排名第二多的员工编号emp_no、薪水salary、last_name以及first_name，不准使用order by
select s.emp_no,max(salary),e.last_name,e.first_name # sql server不支持这样不用group by就用聚合函数
from salaries as s
inner join employees as e
on s.emp_no = e.emp_no
where s.salary != 
(
    select max(salary)
    from salaries
    where to_date = '9999-01-01'
) and s.to_date = '9999-01-01'

# 查找所有员工的last_name和first_name以及对应的dept_name，也包括暂时没有分配部门的员工
select e.last_name,e.first_name,d.dept_name
from employees as e 
left join dept_emp as de 
on e.emp_no = de.emp_no
left join departments as d # 这里必须还是left join才行!!!
on d.dept_no = de.dept_no


# 查找员工编号emp_no为10001其自入职以来的薪水salary涨幅值growth
select max(salary)-min(salary) as growth
from salaries
where emp_no = 10001;

# 查找所有员工自入职以来的薪水涨幅情况，给出员工编号emp_no以及其对应的薪水涨幅growth，并按照growth进行升序
select 
t1.emp_no,(t1.sTo-t2.sHire) as growth 
from 
    ( # 找出每个员工当前工资
        select 
        e.emp_no,s.salary as sTo 
        from employees as e
        left join salaries as s # 每个员工,因此是left join 
        on e.emp_no=s.emp_no 
        where s.to_date='9999-01-01'
    ) as t1 inner join # 这里inner join其实有争议，只是OJ输出要这样没办法
    ( # 找出每个员工入职时工资
        select
        e.emp_no,s.salary as sHire 
        from employees as e
        left join salaries as s # 每个员工,因此是left join 
        on e.emp_no=s.emp_no and s.from_date=e.hire_date
    ) as t2 
on t1.emp_no=t2.emp_no
order by growth asc;