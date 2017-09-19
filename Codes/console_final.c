/* Processed by ecpg (4.10.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "console_final.pgc"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



#line 1 "/usr/include/postgresql/sqlda.h"
#ifndef ECPG_SQLDA_H
#define ECPG_SQLDA_H

#ifdef _ECPG_INFORMIX_H

#include "sqlda-compat.h"
typedef struct sqlvar_compat sqlvar_t;
typedef struct sqlda_compat sqlda_t;

#else

#include "sqlda-native.h"
typedef struct sqlvar_struct sqlvar_t;
typedef struct sqlda_struct sqlda_t;

#endif

#endif   /* ECPG_SQLDA_H */

#line 7 "console_final.pgc"

//EXEC SQL WHENEVER NOT FOUND DO BREAK;
/* exec sql whenever sqlerror  call print_sqlca ( ) ; */
#line 9 "console_final.pgc"



sqlda_t *sqlda1; /* an output descriptor */
sqlda_t *sqlda2; /* an input descriptor  */


//EXEC SQL WHENEVER SQLERROR STOP;

void print_sqlca();
int main()
{
    

    /* exec sql begin declare section */
        
        
        
     
     
     
        

//    const char *stmt = "SELECT batch FROM student WHERE sid='1'"; //side query
  //  const char *stmtinsert = "INSERT INTO student VALUES(?,?,?,?,?);";
      
    
#line 24 "console_final.pgc"
 const char * target = "201401103@10.100.71.21" ;
 
#line 25 "console_final.pgc"
 const char * user = "201401103" ;
 
#line 26 "console_final.pgc"
 const char * password = "alskdj123" ;
 
#line 27 "console_final.pgc"
 int intval ;
 
#line 28 "console_final.pgc"
 float floatval ;
 
#line 29 "console_final.pgc"
 int c ;
 
#line 30 "console_final.pgc"
 unsigned long long longlongval ;
 
#line 34 "console_final.pgc"
 char query [ 1024 ] = "" ;
/* exec sql end declare section */
#line 35 "console_final.pgc"


    { ECPGconnect(__LINE__, 0, target , user , password , NULL, 0); 
#line 37 "console_final.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 37 "console_final.pgc"

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "set search_path to researchportal", ECPGt_EOIT, ECPGt_EORT);
#line 38 "console_final.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 38 "console_final.pgc"


    int mode;
    
    char *scanmode = (char *) malloc(sizeof(char)); // 1 for insert
    
    
    while(true)
   { 
    printf("Select action\n0: Select\n1: Insert\n2: Delete\n3: Update\n Ctrl-c to quit\n");
    gets(scanmode);
//    printf("%s\n", scanmode);
    // scan for action to perform
    
//   printf("Select action\n0: Select\n1: Insert\n2: Delete\n3: Update\n");
//   gets(scanmode);
   

   
   
   mode = atoi(scanmode);
    
    if (mode==1)
        {
          
            printf("enter query for insert\n");
            gets(query);
            
           // sprintf(query, "INSERT INTO student (sid, sname, prog_name, batch, cpi) values ('105', 'Tingu', 'BTech', 1998, 9.0)");
          // strcpy(query, temp);
           
           
           // EXEC SQL EXECUTE IMMEDIATE "INSERT INTO student (sid, sname, prog_name, batch, cpi) values ('101', 'Pingu', 'BTech', 1996, 10.0)";
          // EXEC SQL PREPARE stmt1 FROM :query; 
         //  EXEC SQL EXECUTE stmt1;
          
            //EXEC SQL EXECUTE IMMEDIATE :query;
            
            { ECPGprepare(__LINE__, NULL, 0, "mystmt", query);
#line 76 "console_final.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 76 "console_final.pgc"

            { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "mystmt", ECPGt_EOIT, ECPGt_EORT);
#line 77 "console_final.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 77 "console_final.pgc"
 
          //  EXEC SQL EXECUTE mystmt USING 102, 'Tingu', 'BTech', 1996, 9.0;
            

            { ECPGtrans(__LINE__, NULL, "commit");
#line 81 "console_final.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 81 "console_final.pgc"

            
           // return;   
        }
    else if (mode==2)
    {
             printf("enter query for delete\n");
             gets(query);
            
             { ECPGprepare(__LINE__, NULL, 0, "mystmt", query);
#line 90 "console_final.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 90 "console_final.pgc"

             { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "mystmt", ECPGt_EOIT, ECPGt_EORT);
#line 91 "console_final.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 91 "console_final.pgc"
 


             { ECPGtrans(__LINE__, NULL, "commit");
#line 94 "console_final.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 94 "console_final.pgc"

            
            
       //     return;
    }    
    
    else if (mode==3)
    {
//               EXEC SQL EXECUTE IMMEDIATE "UPDATE student SET sname='Pingu' WHERE sid='100'";
               
             printf("enter query for update\n");
             gets(query);
            
             { ECPGprepare(__LINE__, NULL, 0, "mystmt", query);
#line 107 "console_final.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 107 "console_final.pgc"

             { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "mystmt", ECPGt_EOIT, ECPGt_EORT);
#line 108 "console_final.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 108 "console_final.pgc"
 


             { ECPGtrans(__LINE__, NULL, "commit");
#line 111 "console_final.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 111 "console_final.pgc"

            
         //    return;
    }

 
  else
    {    
    printf("enter query for select\n");
    
       gets(query);
     
    
    //fflush(stdout);
   // printf("%s\n",query); //check
     //fflush(stdout);
//end test test ok

    { ECPGprepare(__LINE__, NULL, 0, "stmt1", query);
#line 129 "console_final.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 129 "console_final.pgc"

    /* declare cur1 cursor for $1 */
#line 130 "console_final.pgc"


    /* Create a SQLDA structure for an input parameter */
    /*sqlda2 = (sqlda_t *)malloc(sizeof(sqlda_t) + sizeof(sqlvar_t));
    memset(sqlda2, 0, sizeof(sqlda_t) + sizeof(sqlvar_t));
    sqlda2->sqln = 2; // a number of input variables 

    sqlda2->sqlvar[0].sqltype = ECPGt_char;
    sqlda2->sqlvar[0].sqldata = "postgres";
    sqlda2->sqlvar[0].sqllen  = 8;

    intval = 1;
    sqlda2->sqlvar[1].sqltype = ECPGt_int;
    sqlda2->sqlvar[1].sqldata = (char *) &intval;
    sqlda2->sqlvar[1].sqllen  = sizeof(intval);*/



    // open the cursor
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cur1 cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "stmt1", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 149 "console_final.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 149 "console_final.pgc"
 // USING DESCRIPTOR sqlda2; // cursor for result of query
 
 while (true) // uttam sqlca.sqlcode==0
    {
        sqlda_t *cur_sqlda;

        /* Assign descriptor to the cursor  */
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch next from cur1", ECPGt_EOIT, 
	ECPGt_sqlda, &sqlda1, 0L, 0L, 0L, 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 156 "console_final.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 156 "console_final.pgc"


        for (cur_sqlda = sqlda1 ; cur_sqlda != NULL ; cur_sqlda = cur_sqlda->desc_next)
        {
            int i;
            char name_buf[1024];
            char var_buf[1024];

            /* Print every column in a row. */
            for (i=0 ; i<(cur_sqlda->sqld); i++) // 1 less 
            {
                sqlvar_t v = cur_sqlda->sqlvar[i];
                char *sqldata = v.sqldata;
                short sqllen  = v.sqllen;

                strncpy(name_buf, v.sqlname.data, v.sqlname.length);
                name_buf[v.sqlname.length] = '\0';

                //printf("dtype:%d\n",v.sqltype);
                switch (v.sqltype)
                {
                    case ECPGt_char:
                        memset(&var_buf, 0, sizeof(var_buf));
                        memcpy(&var_buf, sqldata, (sizeof(var_buf)<=sqllen ? sizeof(var_buf)-1 : sqllen) );
                        printf("%s = %s \n", name_buf, var_buf);
                        break;

                    case ECPGt_int: // integer 
                        memcpy(&intval, sqldata, sqllen);
                        snprintf(var_buf, sizeof(var_buf), "%d", intval);
                        printf("%s = %s \n", name_buf, var_buf);
                        break;

                    /*case ECPGt_decimal: // bigint 
                        memcpy(&floatval, sqldata, sqllen);
                        snprintf(var_buf, sizeof(var_buf), "%f", floatval);
                        break;*/ 

                        
                    
                    case ECPGt_numeric:
                     
                      // char *PGTYPESnumeric_to_asc(numeric *num,0);
                        printf( "%s = %s\n", name_buf, (PGTYPESnumeric_to_asc(sqldata,2)) );
                      //  printf("is this repearing?\n");
                        break;
                    
                    case 18:
                        printf("%s = %s\n", name_buf, PGTYPESdate_to_asc(*v.sqldata));
                       // printf("%s = %s \n", name_buf, var_buf);
                        break;    
                    
                    default:
                    {
                        int i;
                      
                        
                        memset(var_buf, 0, sizeof(var_buf));
                        for (i = 0; i < sqllen; i++)
                        {
                            char tmpbuf[16];
                            
                          
                            
                            snprintf(tmpbuf, sizeof(tmpbuf), "%c", (unsigned char) sqldata[i]); // "%02x" -> "%c"
                            strncat(var_buf, tmpbuf, sizeof(var_buf));
                            
                            printf("%s = %s \n", name_buf, var_buf);
                        }
                    }
                       // break; new changed
                }

                //printf("%s = %s (type: %d)\n", name_buf, var_buf, v.sqltype);
              if (sqlca.sqlcode==100)
                break;
               
                //printf("%s = %s \n", name_buf, var_buf); // removed
            
            }
             
            printf("\n");
            
             printf("---------------------------------------------------------------------------------------\n");
              if (sqlca.sqlcode==100)
                break;
        }
        
           if (sqlca.sqlcode==100)
                break;  
    }
 
     { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cur1", ECPGt_EOIT, ECPGt_EORT);
#line 248 "console_final.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 248 "console_final.pgc"

    { ECPGtrans(__LINE__, NULL, "commit");
#line 249 "console_final.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 249 "console_final.pgc"

    
    printf("\n");
    printf("\n");
    printf("\n");
    printf("************************************************************************************************\n");
   }
}
    { ECPGdisconnect(__LINE__, "ALL");
#line 257 "console_final.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 257 "console_final.pgc"

return 0;
}

void
print_sqlca()
{
    fprintf(stderr, "==== sqlca ====\n");
    fprintf(stderr, "sqlcode: %ld\n", sqlca.sqlcode);
    fprintf(stderr, "sqlerrm.sqlerrml: %d\n", sqlca.sqlerrm.sqlerrml);
    fprintf(stderr, "sqlerrm.sqlerrmc: %s\n", sqlca.sqlerrm.sqlerrmc);
    fprintf(stderr, "sqlerrd: %ld %ld %ld %ld %ld %ld\n", sqlca.sqlerrd[0],sqlca.sqlerrd[1],sqlca.sqlerrd[2],
                                                          sqlca.sqlerrd[3],sqlca.sqlerrd[4],sqlca.sqlerrd[5]);
    fprintf(stderr, "sqlwarn: %d %d %d %d %d %d %d %d\n", sqlca.sqlwarn[0], sqlca.sqlwarn[1], sqlca.sqlwarn[2],
                                                          sqlca.sqlwarn[3], sqlca.sqlwarn[4], sqlca.sqlwarn[5],
                                                          sqlca.sqlwarn[6], sqlca.sqlwarn[7]);
    fprintf(stderr, "sqlstate: %5s\n", sqlca.sqlstate);
    fprintf(stderr, "===============\n");
}
