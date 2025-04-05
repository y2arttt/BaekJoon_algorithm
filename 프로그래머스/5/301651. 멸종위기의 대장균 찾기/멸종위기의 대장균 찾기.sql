WITH RECURSIVE Generations AS (
    -- 1세대(최초 개체)
    SELECT ID, 1 AS GENERATION
    FROM ECOLI_DATA
    WHERE PARENT_ID IS NULL
    
    UNION ALL
    
    -- 다음 세대들
    SELECT e.ID, g.GENERATION + 1
    FROM ECOLI_DATA e
    JOIN Generations g ON e.PARENT_ID = g.ID
),
-- 자식이 없는 개체들 찾기
NoChildren AS (
    SELECT e.ID
    FROM ECOLI_DATA e
    WHERE NOT EXISTS (
        SELECT 1
        FROM ECOLI_DATA child
        WHERE child.PARENT_ID = e.ID
    )
)
-- 결과: 각 세대별 자식이 없는 개체 수 계산 및 정렬
SELECT COUNT(*) AS COUNT, g.GENERATION
FROM Generations g
JOIN NoChildren nc ON g.ID = nc.ID
GROUP BY g.GENERATION
ORDER BY g.GENERATION;
