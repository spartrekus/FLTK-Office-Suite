
 
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>  
#include <time.h>


 void strgettime( )
 {
      long t;
      struct tm *ltime;
      time(&t);
      ltime=localtime(&t);
      char charo[50];  int fooi ; 
      fooi = snprintf( charo, 50 , "%02d:%02d:%02d",
       ltime->tm_hour, ltime->tm_min, ltime->tm_sec 
	);
   }



// the random function
int RandomNumberGenerator(const int nMin,const int nMax,const int  nNumOfNumsToGenerate)
{
  int nRandonNumber = 0;
  int i ; 
  for (i = 0; i < nNumOfNumsToGenerate; i++)
   {
          nRandonNumber = rand()%(nMax-nMin) + nMin;
   }
   // printf(“%d “, nRandonNumber);
   return nRandonNumber; 
}


char *valuemath()
{	
    char ptr[250];

    char line[250];
    char cmdi[PATH_MAX];

    char charoout[PATH_MAX];
    int  fooint;
    char gametype[PATH_MAX];
    int  i;
    strncpy( gametype , " vim " , PATH_MAX );
    char filetarget[250];
    char idata[1240][250];
    char cwd[PATH_MAX];
    char pathbefore[PATH_MAX];
    strncpy( pathbefore , getcwd( cwd, PATH_MAX ) , PATH_MAX );
    int foo ;
    unsigned filemax = 0;
    unsigned n=0;
    DIR *dirp;
    struct dirent *dp;
    int selection = 0 ; 
    int selectionmax = 0 ; 
    int scrolly=0; 

    FILE *fp;


   int resultval = 0;
   int resultok = 0;
   int resultko = 0;
   int mylevel = 1;

    ////////
    //printf( "PATH: %s\n" , getcwd( cwd, PATH_MAX ) );
    mylevel = 1;

    int valc1, valc2 ; 
    valc1 = 3;
    valc2 = 3;

    int mylevelmax = 10;
    if ( mylevel == 1 ) mylevelmax = 10;
    if ( mylevel == 2 ) mylevelmax = 15;
    if ( mylevel == 3 ) mylevelmax = 20;
    if ( mylevel == 4 ) mylevelmax = 25;

    srand(time(NULL));
    strgettime( );
    srand(time(NULL));

    srand(time(NULL));
     valc1 = RandomNumberGenerator(1, mylevelmax ,15) ;
    srand(time(NULL));
    valc2 = RandomNumberGenerator(1, mylevelmax ,25) ;
    printf( " %d + %d " , valc1, valc2 ) ;
    printf( "\n" );

    int foio = 0;
    char charo[250];
    snprintf( charo, 250 , " %d + %d = ? ", valc1, valc2 ) ;
    strncpy( ptr, charo, 250 );

    srand(time(NULL));
    sleep( 1/3 );
    strgettime( );

  
      size_t siz = sizeof ptr ; 
      char *r = (char*)malloc( sizeof ptr );
      return r ? (char*)memcpy(r, ptr, siz ) : NULL;  
}

 