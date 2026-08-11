# Write your MySQL query statement below
SELECT s.student_id, s.student_name, sub.subject_name , COUNT(exam.subject_name) as attended_exams
FROM Students s CROSS JOIN Subjects sub
LEFT JOIN Examinations exam
on s.student_id = exam.student_id AND sub.subject_name = exam.subject_name
GROUP BY s.student_id, s.student_name , sub.subject_name
ORDER BY s.student_id , sub.subject_name;