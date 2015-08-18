/*********************************************************************************
 * Leetcode : Duplicate Emails -- https://leetcode.com/problems/duplicate-emails/
 * Coded in Aug 18th, 2015
 *
 * [Problem]
 * Write a SQL query to find all duplicate emails in a table named Person.
 * 
 * +----+---------+
 * | Id | Email   |
 * +----+---------+
 * | 1  | a@b.com |
 * | 2  | c@d.com |
 * | 3  | a@b.com |
 * +----+---------+
 * For example, your query should return the following for the above table:
 * 
 * +---------+
 * | Email   |
 * +---------+
 * | a@b.com |
 * +---------+
 * Note: All emails are in lowercase.
 *********************************************************************************/

/*Solution One*/
SELECT DISTINCT t1.Email
FROM Person t1
INNER JOIN Person t2
ON t1.Id <> t2.Id
WHERE t1.Email = t2.Email

/*Solution Two*/
SELECT Email
FROM Person
GROUP BY Email
HAVING count(*) > 1
