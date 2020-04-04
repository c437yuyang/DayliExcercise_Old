# 获取有奖金的员工相关信息,给出emp_no、first_name、last_name、奖金类型btype、
# 对应的当前薪水情况salary以及奖金金额bonus。 bonus类型btype为1其奖金为薪水salary的10%，
# btype为2其奖金为薪水的20%，其他类型均为薪水的30%。 当前薪水表示to_date='9999-01-01'
select
e.emp_no,e.first_name,e.last_name,eb.btype,s.salary,
    case eb.btype
        when 1 then s.salary * 0.1
        when 2 then s.salary * 0.2
        else s.salary * 0.3 end
    as bonus
from 
employees as e
inner join emp_bonus as eb
on eb.emp_no = e.emp_no
inner join salaries as s
on e.emp_no = s.emp_no
where s.to_date='9999-01-01'

# 按照salary的累计和running_total，其中running_total为前两个员工的salary累计和，其他以此类推。
select s.emp_no,s.salary,
    (
        select sum(s1.salary)
        from salaries as s1
         where s1.emp_no <= s.emp_no and s1.to_date='9999-01-01'
    )
    as running_total
from salaries as s
where s.to_date='9999-01-01'

# 对于employees表中，给出奇数行的first_name
SELECT E1.first_name FROM employees E1
WHERE (SELECT COUNT(*) FROM employees E2 WHERE E1.first_name>=E2.first_name)%2=1;