# Write your MySQL query statement belowse

select ROUND(COUNT(
    CASE 
        WHEN d2.order_date = d2.customer_pref_delivery_date THEN 1
    END
)/ COUNT(*) * 100 , 2) as immediate_percentage from (
    select * from ( 
        select * , row_number() over (partition by customer_id order by order_date ASC) as t
        from Delivery
    ) as d1
    where d1.t = 1
) as d2
 
