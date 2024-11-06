use [xujg-schooldb]

-- 1
SELECT 姓名 as 'name', YEAR(GETDATE()) - YEAR([出生日期]) as age from student

-- 2
SELECT 
CASE 成绩
	WHEN 成绩 > 90 THEN '优',
  when 成绩 >= 75 THEN '良',
  when 成绩 >= 60 THEN '及格',
  when 成绩 >= 60 THEN '不及格',
END
from score

-- 3
select [课程名], [学分] from course where 