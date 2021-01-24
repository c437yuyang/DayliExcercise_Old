# 20180603练习
# 汇总各个部门当前员工的title类型的分配数目，结果给出部门编号dept_no、dept_name、其当前员工所有的title以及该类型title对应的数目count
select de.dept_no,d.dept_name,t.title,count(1)
from titles as t
inner join dept_emp as de
on de.emp_no=t.emp_no
inner join departments as d
on d.dept_no=de.dept_no
where t.to_date='9999-01-01' and de.to_date='9999-01-01'
group by de.dept_no,d.dept_name,t.title

# 查找描述信息中包括robot的电影对应的分类名称以及电影数目，而且还需要该分类对应电影数量>=2部
select c.name,count(1) as cnt
from film as f
inner join film_category as fc
on fc.film_id=f.film_id
inner join category as c
on c.category_id=fc.category_id
where f.description like '%robot%'
group by c.name
having cnt>=2

# 使用join查询方式找出没有分类的电影id以及名称
select f.film_id,f.title
from film as f
left join film_category as fc
on f.film_id=fc.film_id
where fc.category_id is null

# 使用子查询的方式找出属于Action分类的所有电影对应的title,description
select title,description
from film
where film_id in
(
  select film_id from film_category where category_id = 
  (
    select category_id from category where name='Action'
  )
)

# 获取select * from employees对应的执行计划
explain select * from employees

# 将employees表的所有员工的last_name和first_name拼接起来作为Name，中间以一个空格区分
select concat(last_name,' ',first_name) as Name
from employees