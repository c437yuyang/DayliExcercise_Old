# 使用含有关键字exists查找未分配具体部门的员工的所有信息。
* SELECT * FROM employees WHERE NOT EXISTS 
(SELECT emp_no FROM dept_emp WHERE emp_no = employees.emp_no)

# 存在如下的视图：
create view emp_v as select * from employees where emp_no >10005;
# 获取employees中的行数据，且这些行也存在于emp_v中。注意不能使用intersect关键字。
select *
from employees where emp_no in
(
    select emp_no from emp_v
)