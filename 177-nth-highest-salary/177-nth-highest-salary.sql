CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N = N - 1;
  RETURN (
      # Write your MySQL query statement below.
      select (
        select distinct Salary from Employee order by Salary Desc limit 1 offset N
    )
  );
END