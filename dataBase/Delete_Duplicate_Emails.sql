/*********************************************************************************
 * Leetcode : Delete Duplicate Emails -- https://leetcode.com/problems/delete-duplicate-emails/
 * Coded in Aug 18th, 2015
 *
 * [Problem]
 * Write a SQL query to delete all duplicate email entries in a table named Person, keeping only unique emails based on its smallest Id.
 * 
 * +----+------------------+
 * | Id | Email            |
 * +----+------------------+
 * | 1  | john@example.com |
 * | 2  | bob@example.com  |
 * | 3  | john@example.com |
 * +----+------------------+
 * Id is the primary key column for this table.
 * For example, after running your query, the above Person table should have the following rows:
 * 
 * +----+------------------+
 * | Id | Email            |
 * +----+------------------+
 * | 1  | john@example.com |
 * | 2  | bob@example.com  |
 * +----+------------------+
 *********************************************************************************/
/*Solution One*/
DELETE t2
FROM Person t1, Person t2
WHERE t1.Email = t2.Email && t2.Id > t1.Id

/*Solution Two*/
DELETE
FROM Person
WHERE Id NOT IN ( SELECT t.Id
                  FROM ( SELECT MIN(Id) as Id
                         FROM Person
                         GROUP BY Email)
                         AS t)
