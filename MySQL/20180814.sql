# 获取所有员工当前的manager，如果当前的manager是自己的话结果不显示，当前表示to_date='9999-01-01'
# 结果第一列给出当前员工的emp_no,第二列给出其manager对应的manager_no。
select de.emp_no,dm.emp_no
from dept_emp as de
inner join dept_manager as dm
on de.dept_no = dm.dept_no
where dm.to_date = '9999-01-01' and dm.emp_no!=de.emp_no


# 获取所有部门中当前员工薪水最高的相关信息，给出dept_no, emp_no以及其对应的salary
select de.dept_no,de.emp_no,max(s.salary)
from salaries as s
inner join dept_emp as de
on de.emp_no = s.emp_no
where s.to_date = '9999-01-01' and de.to_date = '9999-01-01'
group by de.dept_no

# 从titles表获取按照title进行分组，每组个数大于等于2，给出title以及对应的数目t。
select title,count(title) as t
from titles
group by title
having t>=2

# 从titles表获取按照title进行分组，每组个数大于等于2，给出title以及对应的数目t。注意对于重复的emp_no进行忽略。
select title,count(distinct emp_no) as t
from titles
group by title
having t>=2

# 统计出当前各个title类型对应的员工当前薪水对应的平均工资。结果给出title以及平均工资
select t.title,avg(s.salary)
from titles as t
inner join salaries as s
on t.emp_no = s.emp_no
where s.to_date='9999-01-01' and t.to_date = '9999-01-01'
group by title

