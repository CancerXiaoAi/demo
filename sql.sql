use [xujg-schooldb]

-- 1(1)
SELECT 姓名 as 'name', YEAR(GETDATE()) - YEAR([出生日期]) as age from student

-- 1(2)
SELECT 
CASE 
	WHEN 成绩 > 90 THEN '优' 
  when 成绩 BETWEEN 75 and 90 THEN '良' 
  when 成绩 BETWEEN 60 and 75 THEN '及格'
  when 成绩 < 60 THEN '不及格'
END as '成绩'
from score

-- 1(3)
select [课程名], [学分] from course where [学时] >= 48

-- 1(4)
select [课程名], [学期] from course where [前置课] is null

-- 1(5)
SELECT * from student where [姓名] like '王__'

-- 2(1)
select student.[学号], student.[姓名], course.[课程号], score.[成绩] from student, score , course

-- 2(2)
SELECT student.[学号], student.[姓名], class.[班级名称] FROM student inner join class on student.[学号] = (SELECT * from) where class.[院系] = '会计学院'

-- 2(3)
SELECT student.[学号], student.[姓名], score.[成绩] from student join score on student.[学号] = score.[学号] where score.[成绩] >= 90

-- 2(4)
SELECT 