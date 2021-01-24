# 查找入职员工时间排名倒数第三的员工所有信息
select * 
from employees 
where emp_no not in
(select emp_no from employees order by hire_date desc limit 2)
order by hire_date desc limit 1; # 这个太挫了(首先两个limit可以用limit 2,1)，而且mysql不支持这种语法，并且如果倒数第三有多个，就错了

# 正确的写法:
select *
from
employees
where hire_date in (select distinct hire_date from employees order by hire_date desc limit 2,1);


# 查找各个部门当前(to_date='9999-01-01')领导当前薪水详情以及其对应部门编号dept_no
# 注意:查询的最终结果是薪水，返回的是当前的薪水，而不是当前的领导
select 
    d.emp_no as emp_no,
    s.salary as salary,
    s.from_date as from_date,
    d.to_date as to_date,
    d.dept_no as dept_no 
from salaries as s 
inner join dept_manager as d  
on d.emp_no=s.emp_no
where s.to_date = '9999-01-01' and d.to_date='9999-01-01';

# 查找所有已经分配部门的员工的last_name和first_name
select e.last_name,e.first_name,de.dept_no
from employees as e
inner join dept_emp as de
on e.emp_no = de.emp_no


# 查找所有员工的last_name和first_name以及对应部门编号dept_no，也包括展示没有分配具体部门的员工
select e.last_name,e.first_name,de.dept_no
from employees as e
left join dept_emp as de
on e.emp_no = de.emp_no

# 查找所有员工入职时候的薪水情况，给出emp_no以及salary， 并按照emp_no进行逆序
select e.emp_no,s.salary
from salaries as s
inner join employees as e 
on s.emp_no = e.emp_no
where e.hire_date = s.from_date # inner join 的话，写在on里面和外面都可以
order by s.emp_no desc

# 查找薪水涨幅超过15次的员工号emp_no以及其对应的涨幅次数t
select emp_no,count(salary) as t
from salaries
group by emp_no 
having count(salary)>15

# 找出所有员工当前(to_date='9999-01-01')具体的薪水salary情况，对于相同的薪水只显示一次,并按照逆序显示
select distinct salary
from salaries
where to_date = '9999-01-01'
order by salary desc

# 获取所有部门当前manager的当前薪水情况，给出dept_no, emp_no以及salary
select dm.dept_no,s.emp_no,s.salary
from salaries as s
inner join dept_manager as dm
on s.emp_no = dm.emp_no
where s.to_date = '9999-01-01' and dm.to_date = '9999-01-01'

# 获取所有非manager的员工emp_no
select emp_no
from employees
where emp_no not in
(select emp_no from dept_manager)

