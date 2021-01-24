# 重命名表
rename table vendnew1 to vendnew;
# 创建外键约束
alter table audit add foreign key(EMP_no) references employees_test(ID);
# 将所有获取奖金的员工当前的薪水增加10%。
update salaries
set salary = salary * 1.1
where to_date='9999-01-01' and 
emp_no in (select emp_no from emp_bonus)

# 针对库中的所有表生成select count(*)对应的SQL语句
select table_name from information_schema.tables where table_schema=database(); # 获取所有表
select concat('select count(*) from ',table_name,';') from information_schema.tables where table_schema=database();

# 查找字符串'10,A,B' 中逗号','出现的次数cnt
SELECT (length("10,A,B")-length(replace("10,A,B",",","")))/length(",") AS cnt;