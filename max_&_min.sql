
-- Function to get the greater integer value.

create function greaterint(int, int)
returns int language sql
as $$
    select case when $1 < $2 then $2 else $1 end
$$;

-- Aggregate to get the max integer value. It calls the function "greaterint" N number of times where N is the number of tuples.

create aggregate max_int(int) (
    sfunc = greaterint,
    stype = integer,
    initcond = 0
);

-----------------------------------------------------------------------------------------------------------------------------------------------------
-- Function to get the lesser integer value.

create function lesserint(int, int)
returns int language sql
as $$
    select case when $1 > $2 then $2 else $1 end
$$;

-- Aggregate to get the min integer value. It calls the function "lesserint" N number of times where N is the number of tuples.

create aggregate min_int(int) (
    sfunc = lesserint,
    stype = integer,
    initcond = 2147483647
);


-----------------------------------------------------------------------------------------------------------------------------------------------------
-- Function to get the greater char value.

create function greaterchar(char, char)
returns char language sql
as $$
    select case when $1 > $2 then $2 else $1 end
$$;

-- Aggregate to get the max char value. It calls the function "greaterchar" N number of times where N is the number of tuples.

create aggregate max_char(char) (
    sfunc = greaterchar,
    stype = char,
    initcond = a
);\
