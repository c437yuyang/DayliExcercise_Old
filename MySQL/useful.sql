# 查找入职员工时间排名倒数第三的员工所有信息（考察limit,distinct等的用法）

# 查找各个部门当前(to_date='9999-01-01')领导当前薪水详情以及其对应部门编号dept_no （不难，但是可以练习基础的连接查询）

# 获取所有非manager的员工emp_no （子查询）

# 获取所有部门中当前员工薪水最高的相关信息，给出dept_no, emp_no以及其对应的salary （连接、分组）
# 统计出当前各个title类型对应的员工当前薪水对应的平均工资。结果给出title以及平均工资avg（同上）

# 查找当前薪水(to_date='9999-01-01')排名第二多的员工编号emp_no、薪水salary、last_name以及first_name，不准使用order by （子查询）



# 查找所有员工自入职以来的薪水涨幅情况，给出员工编号emp_no以及其对应的薪水涨幅growth，并按照growth进行升序







# 自己的练习，有重名的人，删除只保留一条
# id    name
# 1     a
# 2     a
# 3     b

delete from people 
where id not in
(
    select id
    from people
    where name = 'a'
    limit 1
)
and name = 'a'
