-- Disable Parallel Queries (for simpler plans)
SET max_parallel_workers_per_gather = 0;

-- Sequential Scan
SELECT *
FROM fact_schema;

-- Sequential Scan with Filter
SELECT *
FROM fact_schema
WHERE label = 'Yearly Tuition';

-- Index Scan
SELECT *
FROM fact_schema
WHERE name = 'Tuition';

-- Bitmap Index Scan
SELECT *
FROM fact_schema
WHERE name IN ('Tuition', 'NetPrice');

-- Nested Loop Join
ALTER TABLE fact DROP CONSTRAINT fact_entity_uuid_fact_uuid_key;

SELECT *
FROM fact_schema AS fs
INNER JOIN fact AS f ON fs.uuid = f.fact_uuid
WHERE f.entity_uuid = '00352600-dd27-4048-9ff7-6ca67b3854e8'
AND fs.label = 'Yearly Tuition';

-- Index Scan Join
ALTER TABLE fact ADD CONSTRAINT fact_entity_uuid_fact_uuid_key UNIQUE(entity_uuid, fact_uuid);

SELECT *
FROM fact_schema AS fs
INNER JOIN fact AS f ON fs.uuid = f.fact_uuid
WHERE f.entity_uuid = '00219d2b-b49c-4fd4-a361-02ccb1ccd4c4'
AND fs.label = 'Yearly Tuition';

-- Hash Join
SELECT *
FROM fact_schema AS fs
INNER JOIN fact AS f ON fs.uuid = f.fact_uuid;

-- Subquery
SELECT *, (
	SELECT fs.name
	FROM fact_schema AS fs
	WHERE fs.uuid = f.fact_uuid
)
FROM fact AS f;

-- In-Memory QuickSort
SELECT *
FROM fact_schema
ORDER BY label;

-- Index Sort
SELECT *
FROM fact
ORDER BY entity_uuid

-- Re-enable Parallel Queries
SET max_parallel_workers_per_gather = 2;
