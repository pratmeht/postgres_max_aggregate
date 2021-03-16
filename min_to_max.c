#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include <limits.h>
#define _XOPEN_SOURCE

void do_exit(PGconn *conn) {
    PQfinish(conn);
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 3) {
        printf("Enter 3 arguments only!!\n\"Format: filename arg1 arg2 (eg. min_to_max col_name table_name)\"\n\n");
        return 0;
    }

    char sql[BUFSIZ];
    //Connect to DB. If unsuccessful then print it.
    PGconn *conn = PQconnectdb("user=postgres dbname=postgres");
    if (PQstatus(conn) == CONNECTION_BAD) {
        fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));
        do_exit(conn);
    }

    //Prepare SQL stmt and Execute it.
    sprintf(sql, "select min(%s), max(%s) from %s", argv[1], argv[1], argv[2]);
    PGresult *res = PQexec(conn, sql);
    if (PQresultStatus(res) != PGRES_TUPLES_OK)   {
        fprintf(stderr, "SELECT failed: %s", PQerrorMessage(conn));
        PQclear(res);
        do_exit(conn);
    }

    //Count rows and Print it.
    int rows = PQntuples(res);
    for(int i=0; i<rows; i++) {
        printf("%s -> %s\n", PQgetvalue(res, i, 0), PQgetvalue(res, i, 1));
    }
    //Free the result of previous command and end the DB session.
    PQclear(res);
    PQfinish(conn);
    return 0;
}
