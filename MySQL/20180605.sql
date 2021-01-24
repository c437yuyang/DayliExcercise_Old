# 针对salaries表emp_no字段创建索引idx_emp_no，查询emp_no为10005, 使用强制索引。
create index idx_emp_no on salaries(emp_no);
select * from salaries force index(idx_emp_no) where emp_no=10005;

# 现在在last_update后面新增加一列名字为create_date, 类型为datetime, NOT NULL，默认值为'0000 00:00:00'
alter table actor add create_date datetime not null default '0000-00-00 00:00:00'

# 构造一个触发器audit_log，在向employees_test表中插入一条数据的时候，触发插入相关的数据到audit中。
delimiter //
create trigger tgr_employees_test_insert after insert on employees_test
for each row
begin
insert into audit values (old.emp_no,old.name)
end if;
end;
//

# 删除emp_no重复的记录，只保留最小的id对应的记录。
CREATE TABLE IF NOT EXISTS titles_test (
id int(11) not null primary key,
emp_no int(11) NOT NULL,
title varchar(50) NOT NULL,
from_date date NOT NULL,
to_date date DEFAULT NULL);

insert into titles_test values ('1', '10001', 'Senior Engineer', '1986-06-26', '9999-01-01'),
('2', '10002', 'Staff', '1996-08-03', '9999-01-01'),
('3', '10003', 'Senior Engineer', '1995-12-03', '9999-01-01'),
('4', '10004', 'Senior Engineer', '1995-12-03', '9999-01-01'),
('5', '10001', 'Senior Engineer', '1986-06-26', '9999-01-01'),
('6', '10002', 'Staff', '1996-08-03', '9999-01-01'),
('7', '10003', 'Senior Engineer', '1995-12-03', '9999-01-01');

delete from titles_test
where id not in
(
    select min(id) as id
    from titles_test
    group by emp_no
)