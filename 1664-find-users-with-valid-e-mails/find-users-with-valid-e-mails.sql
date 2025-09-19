SELECT
    user_id,
    name,
    mail
FROM
    Users
WHERE
    -- Use REGEXP BINARY to force a case-sensitive match
    mail REGEXP '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com$' COLLATE utf8mb4_bin;