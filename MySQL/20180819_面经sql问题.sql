# 学校中有一个年级表，有两个核心字段，student_id和class_id，把年级中大于30人的班级查出来？ 

# 连接查询实现
select s.class_id,count(1) as cnt
from class as c
inner join student as s
on s.class_id=c.id
group by s.class_id
having cnt>30

# 子查询实现
select a.class_id from
(
    select class_id, count(*) cnt from student group by class_id
) 
as a where a.cnt > 30;

# 这样子查询也可以
select tclassid from tblclass where tclassid in
(
	select tsclassid from tblstudent group by tsclassid having count(1) > 10
)


# 一个成绩表，其中存放了学生信息和成绩信息，三列 id，subject，grade其中subject就是课程的id，如何将学生按总分排序？
select id,sum(grade) as total
from score
group by id
order by total desc

# stu_id class_id grade 用一句SQL语句找出每个班级里面的及格的人数和不及格的人数
select 
    class_id,
    sum(case when score>=60 then 1 else 0 end) as 及格人数,
    sum(case when score<60 then 1 else 0 end) as 不及格人数
    from tb1
    group by class_id;

# 表格中有A, B两列，分别是日期和比赛的胜／负情况，要求展示每个日期的胜负个数。
select
day,sum(case when res='win' then 1 else 0) as 'win_num',
sum(case when res='lose' then 1 else 0) as 'lose_num'
from game
group by day


# 订单表user_order结构和数据如下。请编写sql语句查出首次下单日期是2018年05月22号的用户数量，注意是首次下单。

id  user_id  product price  create_date
1   234     坚果Pro2 1400   '2018-05-21'
2   234     锤子TNT 1400   '2018-05-21'
3   356     小米mix 1400   '2018-05-21'
4   357     硅胶娃娃 1400   '2018-05-21'

select user_id,min(create_date)
from user_order
group by user_id
having(min(create_date)='2018-05-22')


# 根据商品交易记录找商品销量的中位数，然后对于销量超过中位数的商品找出超过中位数的时间点。 
select item_id,count(1) as cnt
from order_record 
group by item_id
limit 总数/2,1  # 总数通过select count(*) from order_record 得到
