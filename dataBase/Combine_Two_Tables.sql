/*********************************************************************************
 * Leetcode : Combine Two Tables -- https://leetcode.com/problems/combine-two-tables/
 * Coded in Aug 18th, 2015
 *
 * [Problem]
 * Table: Person
 * 
 * +-------------+---------+
 * | Column Name | Type    |
 * +-------------+---------+
 * | PersonId    | int     |
 * | FirstName   | varchar |
 * | LastName    | varchar |
 * +-------------+---------+
 * PersonId is the primary key column for this table.
 * Table: Address
 * 
 * +-------------+---------+
 * | Column Name | Type    |
 * +-------------+---------+
 * | AddressId   | int     |
 * | PersonId    | int     |
 * | City        | varchar |
 * | State       | varchar |
 * +-------------+---------+
 * AddressId is the primary key column for this table.
 * 
 * Write a SQL query for a report that provides the following information for each
 * person in the Person table, regardless if there is an address for each of those
 * people:
 * 
 * FirstName, LastName, City, State
 *********************************************************************************/
SELECT Person.FirstName, Person.LastName, Address.City, Address.State
FROM Person
LEFT JOIN Address
ON Person.PersonId = Address.PersonId
