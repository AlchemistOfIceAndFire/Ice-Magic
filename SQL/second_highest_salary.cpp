//
// Created by huanyan on 2021/11/5.
//

//Table: Employee
//
//
//+-------------+------+
//| Column Name | Type |
//+-------------+------+
//| id          | int  |
//| salary      | int  |
//+-------------+------+
//id is the primary key column for this table.
//Each row of this table contains information about the salary of an employee.
//
//
//
//
// Write an SQL query to report the second highest salary from the Employee
//table. If there is no second highest salary, the query should report null.
//
// The query result format is in the following example.
//
//
// Example 1:
//
//
//Input:
//Employee table:
//+----+--------+
//| id | salary |
//+----+--------+
//| 1  | 100    |
//| 2  | 200    |
//| 3  | 300    |
//+----+--------+
//Output:
//+---------------------+
//| SecondHighestSalary |
//+---------------------+
//| 200                 |
//+---------------------+
//
//
// Example 2:
//
//
//Input:
//Employee table:
//+----+--------+
//| id | salary |
//+----+--------+
//| 1  | 100    |
//+----+--------+
//Output:
//+---------------------+
//| SecondHighestSalary |
//+---------------------+
//| null                |
//+---------------------+
//
// Related Topics 数据库 👍 902 👎 0


//There is no code of C++ type for this problem

#临时表避免NULL情况出错 limit
SELECT (SELECT DISTINCT salary FROM Employee ORDER BY salary DESC limit 1, 1) as SecondHighestSalary;

#临时表避免NULL情况出错 limit offset
SELECT (SELECT DISTINCT salary FROM Employee ORDER BY salary DESC LIMIT 1 OFFSET 1) as SecondHighestSalary;

#IFNULL 函数避免 NULL 出错, Note: IFNULL函数里面的 SQL 需要括号括起来
SELECT IFNULL((SELECT DISTINCT salary FROM Employee ORDER BY salary DESC LIMIT 1 OFFSET 1, NULL)) as SecondHighestSalary;