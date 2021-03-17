# postgres_max_aggregate
Manually creating aggregate to calculate max and min for different datatypes (int, char, date)

Following code files are uploaded in this repo.
They have been tested on:

Community Postgresql 13.2 and 12.6. 
RHEL/CentOS 7 and 8

1. **min_to_max.c Source file**
Compile it using following command:
gcc min_to_max.c -o min_to_max  -I/usr/pgsql-13/include/server -L/usr/lib64 -lpq -std=gnu99

Format to run it:
_filename arg1 arg2_

Example:
_min_to_max  <column_name>   <table_name>_   
--- use the column and the table name whose aggregate needs to be calulated. This has been tested to work on data types - integer, char, date.

2. **max aggregate code on postgresql DB**
These are individual max and min aggregate functions for integer data type. 
Additionally, by modifying the data type from 'int' to 'char' in a function, a max aggregate function can be used for 'char' data type.

