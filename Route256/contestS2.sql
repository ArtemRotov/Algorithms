SELECT u.id, u.name, COUNT(DISTINCT CASE WHEN s.success is true THEN c.id ELSE NULL END) AS solved_at_least_one_contest_count, COUNT (DISTINCT c.id) AS take_part_contest_count 
FROM users u

LEFT JOIN submissions s ON s.user_id = u.id
LEFT JOIN problems p ON s.problem_id = p.id
LEFT JOIN contests c ON p.contest_id = c.id

GROUP BY u.id, u.name

ORDER BY solved_at_least_one_contest_count DESC,
  take_part_contest_count DESC,
  u.id
