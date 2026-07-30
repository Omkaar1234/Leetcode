# Write your MySQL query statement below
select customer_id, COUNT(*) as count_no_trans from 
(select v.customer_id from 
 visits v left join transactions t
 on v.visit_id = t.visit_id
 where t.transaction_id is NULL
) AS x GROUP BY customer_id;
