SELECT P.id, P.contest_id, P.code FROM problems P 
JOIN submissions S ON p.id = S.problem_id 
WHERE S.success = true
GROUP BY P.id, S.success, P.contest_id, P.code
HAVING COUNT(DISTINCT S.user_id) > 1 
ORDER BY P.id
