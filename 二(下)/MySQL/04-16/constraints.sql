use information_schema;

show tables;

desc table_constraints;

select table_name, constraint_name from table_constraints;