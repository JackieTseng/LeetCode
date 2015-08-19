/*********************************************************************************
 * Leetcode : Department Highest Salary -- https://leetcode.com/problems/department-highest-salary/
 * Coded in Aug 19th, 2015
 *
 * [Problem]
 * The Employee table holds all employees. Every employee has an Id, a salary, and
 * there is also a column for the department Id.
 * 
 * +----+-------+--------+--------------+
 * | Id | Name  | Salary | DepartmentId |
 * +----+-------+--------+--------------+
 * | 1  | Joe   | 70000  | 1            |
 * | 2  | Henry | 80000  | 2            |
 * | 3  | Sam   | 60000  | 2            |
 * | 4  | Max   | 90000  | 1            |
 * +----+-------+--------+--------------+
 * The Department table holds all departments of the company.
 * 
 * +----+----------+
 * | Id | Name     |
 * +----+----------+
 * | 1  | IT       |
 * | 2  | Sales    |
 * +----+----------+
 * Write a SQL query to find employees who have the highest salary in each of
 * the departments. For the above tables, Max has the highest salary in the IT
 * department and Henry has the highest salary in the Sales department.
 * 
 * +------------+----------+--------+
 * | Department | Employee | Salary |
 * +------------+----------+--------+
 * | IT         | Max      | 90000  |
 * | Sales      | Henry    | 80000  |
 * +------------+----------+--------+
 *********************************************************************************/
SELECT D.Name, E.Name, E.Salary
FROM Department D, Employee E, (SELECT DepartmentId, MAX(Salary) as Salary
                                FROM Employee
                                GROUP BY DepartmentId) H
WHERE E.Salary = H.Salary AND
      E.DepartmentId = H.DepartmentId AND
      E.DepartmentId = D.Id
