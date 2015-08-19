/*********************************************************************************
 * Leetcode : Consecutive Numbers -- https://leetcode.com/problems/consecutive-numbers/
 * Coded in Aug 19th, 2015
 *
 * [Problem]
 * Write a SQL query to find all numbers that appear at least three times consecutively.
 * 
 * +----+-----+
 * | Id | Num |
 * +----+-----+
 * | 1  |  1  |
 * | 2  |  1  |
 * | 3  |  1  |
 * | 4  |  2  |
 * | 5  |  1  |
 * | 6  |  2  |
 * | 7  |  2  |
 * +----+-----+
 * For example, given the above Logs table, 1 is the only number that appears consecutively for at least three times.
 *********************************************************************************/
SELECT DISTINCT T1.Num
FROM Logs AS T1, Logs AS T2, Logs AS T3
WHERE T1.Num = T2.Num AND
      T2.Num = T3.Num AND
      T3.Id = T2.Id + 1 AND
      T2.id = T1.Id + 1
