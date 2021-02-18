/*
    Anushka Verma <Z1911937>
    Database
    Assignment 5
    02/16/2021
*/
USE BabyName;               -- Select the BabyName database

SHOW TABLES;                -- Show all of the tables in the database

DESCRIBE BabyName;          -- Displays the properties of column table

SELECT DISTINCT name        -- Displays the name only once
FROM BabyName               -- Picks the name from the database
WHERE year = '1997'         -- Filter's names from my birth year
LIMIT 50;

SELECT DISTINCT year        -- Displays the name only once
FROM BabyName               -- Picks the name from the database
WHERE name = 'Anushka'      -- Filter's names from my birth year
LIMIT 50;

SELECT name, gender                                             -- Selects the most popular name and gender
FROM BabyName                                                   -- From the database          
WHERE count IN                                                  -- IN operator used to check current count against the list
    (SELECT MAX(count)                                          -- The Subquery
      FROM BabyName
      WHERE place = 'US' and year = '1984' and gender = 'M')    -- Returning only place in US, The year and The gender
      UNION                                                     -- Merges the two tables
SELECT name, gender                                             -- Selects the most popular name and gender
FROM BabyName                                                   -- From the database
WHERE count IN                                                  -- IN operator used to check current count against the list
    (SELECT MAX(count)                                          -- The Subquery
      FROM BabyName
      WHERE place = 'US' and year = '1984' and gender = 'F');   -- Returning only place in US, The year and The gender

SELECT place,               -- Selects the place
COUNT(DISTINCT name)        -- Counts the names of each place
FROM BabyName
GROUP BY place              -- Helps in grouping them by place
LIMIT 50;

SELECT * FROM BabyName      -- Selects all columns from the BabyName database
WHERE name LIKE '%Anushka%' -- Creates a clause that is anything between 'Anushka'
ORDER BY name, count, year  -- Sorts everything out in alphabetical order
LIMIT 50;

SELECT COUNT(DISTINCT name) -- Doesn't duplicate any values
FROM BabyName
WHERE year = '1974'         -- Filters names from the year 1974
LIMIT 50;

SELECT COUNT(*) FROM BabyName   -- Counts the content in the database
LIMIT 50;

SELECT gender,                  -- Picks either Male Or Female
COUNT(DISTINCT name)            -- Doesn't duplicate any values
FROM BabyName
WHERE year = '1962'             -- From the year 1962
GROUP BY gender
LIMIT 50;

