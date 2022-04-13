
-- 求选修了老师“王刚”开课课程且成绩在90分以上的学生姓名、课程名称和成绩；
select `姓名`,`课程名`,`成绩`
from `学生`,`学习`,`教师`,`课程`
where `教师`.`教师名`='王刚' and `学习`.`教师号`=`教师`.`教师号`
and `学习`.`课程号`=`课程`.`课程号` and `学习`.`学号`=`学生`.`学号`
and `学习`.`成绩`>=90;

-- 求选修了“王刚”老师所授全部课程的学生姓名和学院名称；（姓名，学院名称）

select `姓名`,`学院名称`
from `学生`,`学院`
where `学生`.`学院代码`=`学院`.`学院代码` and not exists
(
    select `课程号`
    from `授课`,`教师`
    where `授课`.`教师号`=`教师`.`教师号` and `教师`.`教师名`='王刚' and not exists
    (
        select `课程号`
        from `学习`
        where `学习`.`学号`=`学生`.`学号` and 学习.`课程号`=授课.`课程号`
    )
);

-- 求没有选修课程“软件工程”的学生学号和姓名；（学生学号，姓名）

select 学生.学号 as 学生学号,姓名
from 学生
where not exists
(
    select * 
    from 学习,课程
    where 学习.课程号=课程.课程号 and 学生.学号=学习.学号 and 课程.课程名='软件工程'
);

-- 求至少选修了两门课程的学生学号；（学号）

select 学号
from 学习
group by 学号
having count(课程号)>=2;

-- 求课程“经济学”不及格学生姓名和考试成绩；

select 姓名,成绩
from 学生,学习,课程
where 学习.成绩<=60 and 课程.课程名='经济学' and 学习.课程号=课程.课程号 and 学生.学号=学习.学号;

-- 求至少选修了与学号“T06” 同学选修的课程相同的学生学号；（学号）

select 学号
from 学生
where not exists
(
    select * 
    from 学习 as a
    where a.学号='T06' and not exists
    (
        select * 
        from 学习 as b
        where a.课程号=b.课程号 and b.学号=学生.学号
    )
);

-- 求至少选修了“C3，C4”两门课程的学生姓名和学院名称；（姓名，学院名称）

select 姓名,学院名称
from 学生,学院,学习
where 学生.学号=学习.学号 and 学习.课程号='C3' and 学生.学院代码=学院.学院代码 and 学习.学号 in
(
    select 学号
    from 学习
    where 课程号='C4'
);

-- 8．查询“王石”同学没有选修的课程号和课程名； （课程号，课程名）

select 课程号,课程名
from 课程
where 课程号 not in
(
    select 课程号
    from 学习,学生
    where 学生.学号=学习.学号 and 学生.姓名='王石'
);

-- 9．查询没有被任何学生选修的课程的课程号；（课程号）

select 课程号
from 课程
where 课程号 not in(
    select distinct 课程号
    from 学习
);

-- 10．求选修了全部课程的学生姓名；（姓名）

select 姓名
from 学生
where not exists(
    select *
    from 课程
    where not exists(
        select * 
        from 学习 
        where 学习.课程号=课程.课程号 and 学生.学号=学习.学号
    )
);

-- 查询各学院课程“经济学”的平均分，并按照成绩从高到低的顺序排列；（学院名称，平均分）

select 学院名称,avg(成绩) as 平均分
from 学习,学生,学院,课程
where 学习.学号=学生.学号 and 学习.课程号=课程.课程号 and 学生.学院代码=学院.学院代码 and 课程.课程名='经济学'
group by 学生.学院代码
order by avg(成绩) desc;

-- 12．查询选修课程“经济学”的学生姓名和所在院系，结果按各院系排列，同时成绩从高到低排列；（姓名，学院名称，成绩）

select 姓名,学院名称,成绩
from 学生,学习,课程,学院
where 学生.学号=学习.学号 and 学习.课程号=课程.课程号 and 课程.课程名='经济学' and 学生.学院代码=学院.学院代码
order by 学生.学院代码,成绩 desc;

-- 13．求学时在30-45之间（含30和45）的课程的课程号和课程名称及授课教师；（课程号，课程名，教师姓名）

select 课程.课程号,课程名,教师名 as 教师姓名
from 课程,教师,授课
where 课程.课程号=授课.课程号 and 授课.教师号=教师.教师号 and (课程.学时 between 30 and 40);

-- 14．检索选修课程“经济学”的最高分学生的姓名；（姓名）

select 姓名
from 学生,学习,课程
where 学生.学号=学习.学号 and 学习.课程号=课程.课程号 and 课程.课程名='经济学' and 成绩=(select max(成绩) -- 注意max用法,where中不能直接用聚合函数
from 学习,课程
where 学习.课程号=课程.课程号 and 课程.课程名='经济学');

-- 15．查询选课人数超过5人的课程的课程号及课程名；（课程号，课程名）

select 课程.课程号,课程名
from 学习,课程
where 学习.课程号=课程.课程号
group by 课程号
having count(*)>5;