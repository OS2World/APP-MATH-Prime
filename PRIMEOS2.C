/*
        PRIME is (C)opyright 1995 by Paul Damer and Jawed Karim
        You may distribute the source freely only if it remains
        unchanged. You may also recompile it for whatever 
        platform, and give yourself credit by letting it display
        your name upon startup of PRIME. Leave the authors display 
        lines unchanged however.

        Jawed Karim <kari0022@gold.tc.umn.edu>
*/



#define INCL_VIO

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <os2.h>

void main()
{
        double x = 1, y;
        long dis;
        int counter = 0, ch;
        char s[2] = {' ', '\0'};
        /*        clrscr(); */
        VioScrollDn(0,0,-1,-1,-1,(PBYTE)&s,0);
        VioSetCurPos(0,0,0);
        
        puts("PRIME.EXE -- PRIME NUMBER GENERATOR v1.0");
        puts("(C) 1995 by Paul Damer & Jawed Karim <kari0022@gold.tc.umn.edu>");
        puts("---------------------------------------------------------------");
        puts("");
        puts("Hit CTRL-C at any time to stop.");
        puts("--hit any key when ready--");
        ch = getch();
        puts("");
        
        printf("2\n3\n"); /* the loop leaves these numbers out.. */

        while (1)
        {
                x++;                
        
                y = floor ( sqrt ( x ) );

        lbl: ;

                if ( ( (x/y)-(floor (x/y)) ) != 0 )
                {
                        y--;                
                        
                        if ( y<2 )
                        {        
                                if (counter == 24)
                                {
                                        VioSetCurPos(0,0,0);
                                        counter = 0;
                                }

                                dis = x;
                                printf("%ld\n", dis);
                                counter++;
                        }
                        
                        else
                                goto lbl;
                                /* 
                                yuck goto! sorry, but I had
                                to... this actually
                                runs faster!
                                */
                }
        }
}
