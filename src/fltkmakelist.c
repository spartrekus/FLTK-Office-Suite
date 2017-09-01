


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>


static int compare_fun( const void *p, const void *q)
{
  const char *l = p ; 
  const char *r = q ; 
  int cmp; 
  cmp = strcmp( l, r );
  return cmp; 
}

char *binstrcut( char *str , int myposstart, int myposend )
{  
      char ptr[strlen(str)+1];
      int i,j=0;
      for(i=0; str[i]!='\0'; i++)
      {
        if ( ( str[i] != '\0' ) && ( str[i] != '\0') )
         if ( ( i >=  myposstart-1 ) && (  i <= myposend-1 ) )
           ptr[j++]=str[i];
      } 
      ptr[j]='\0';
      size_t siz = sizeof ptr ; 
      char *r = malloc( sizeof ptr );
      return r ? memcpy(r, ptr, siz ) : NULL;
}






char *strrlf(char *str)
{    
      char ptr[strlen(str)+1];
      int i,j=0;
      for(i=0; str[i]!='\0'; i++)
      {
        if (str[i] != '\n' && str[i] != '\n') 
        ptr[j++]=str[i];
      } 
      ptr[j]='\0';
      size_t siz = sizeof ptr ; 
      char *r = malloc( sizeof ptr );
      return r ? memcpy(r, ptr, siz ) : NULL;
}





///////////////////////////////////////
///////////////////////////////////////
///////////////////////////////////////
///////////////////////////////////////
int fexiststatic(char *a_option)
{
  char dir1[PATH_MAX]; 
  char *dir2;
  DIR *dip;
  strncpy( dir1 , "",  PATH_MAX  );
  strncpy( dir1 , a_option,  PATH_MAX  );

  struct stat st_buf; 
  int status; 
  int fileordir = 0 ; 

  status = stat ( dir1 , &st_buf);
  if (status != 0) {
    fileordir = 0;
  }
  FILE *fp2check = fopen( dir1  ,"r");
  if( fp2check ) {
  fileordir = 1; 
  fclose(fp2check);
  } 

  if (S_ISDIR (st_buf.st_mode)) {
    fileordir = 2; 
  }
return fileordir;
/////////////////////////////
}








char *filename_newext( char *str , char *newext )
{
      char ptr[strlen(str)+1];
      int i,j=0;
      int foundpoint = 0; 
      for(i=strlen(str)-1 ; i!=-1 ; i--)
      {
          if ( str[i] == '.' ) foundpoint = i; 
      } 

     if ( foundpoint >= 1 ){
      int maxsize = strlen(str)+1+strlen(newext) ;
      char ptrnew[ maxsize ];
      strncpy( ptrnew, binstrcut( str, 1, foundpoint+1 ),  maxsize  ); 

      ptrnew[ foundpoint ] = '.';
      if ( strlen( newext ) >= 1 )
      for(i=0 ; i<= strlen( newext )-1 ; i++)
         ptrnew[ foundpoint+1 +i ] = newext[ i ];
      ptrnew[ foundpoint +i+1] = '\0';

       size_t siz = sizeof ptrnew ; 
       char *r = malloc( sizeof ptrnew );
       return r ? memcpy(r, ptrnew, siz ) : NULL;
    } else return ""; 
}







int main()
{	

    int ch = 0; 
    int selection = 0; 
    int scrolly = 0; 

    char line[PATH_MAX];
    char filetarget[250];
    char idata[1240][250];

    char currentselection[PATH_MAX];
    strncpy( currentselection, "", PATH_MAX );

    unsigned filemax = 0;
    unsigned n=0;
    DIR *dirp;
    struct dirent *dp;






  void loaddir()
  {
    n = 0 ; 
    filemax = 0; 
    dirp = opendir( "." );
    while  ((dp = readdir( dirp )) != NULL  &&  
            n < sizeof idata / sizeof idata[ 0 ]) {
            if ( strcmp( dp->d_name , "." ) != 0 )
            if ( strcmp( dp->d_name , ".." ) != 0 )
            if ( dp->d_name[0] !=  '.' )
            {
              strncpy( idata[ n++ ] , dp->d_name , 250 );
            }
    }
    filemax = n-1 ; 
    closedir( dirp );

    if ( n > 1 )
      qsort( idata, n , sizeof idata[0], compare_fun );
  }



    loaddir();
    int posy=2;
    char targetfile[PATH_MAX];
    char cmdi[PATH_MAX];
    // all cxx
    for ( n = 0 ; n <= filemax ; n++)
    if ( strstr( idata[n] , "makelist" ) == 0 )
    if ( idata[n][strlen( idata[n] )-1 ] == 'x' )
    if ( idata[n][strlen( idata[n] )-2 ] == 'x' )
    if ( idata[n][strlen( idata[n] )-3 ] == 'c' )
    if ( idata[n][strlen( idata[n] )-4 ] == '.' )
    {


          printf( "___________________________\n" );
          printf( "Source: %s\n",           idata[ n ] );
          printf( "Code C: %s\n",   idata[ n ] );
          strncpy( targetfile , "" , PATH_MAX );
          strncat( targetfile , "../bin/" , PATH_MAX - strlen(targetfile) - 1);
          strncat( targetfile , filename_newext( idata[n] , "" ) , PATH_MAX - strlen(targetfile) - 1);
          printf( "Compile from %s to %s (...)\n", idata[n] , targetfile );
          printf( "Compiler (default): g++ with FLTK DEV\n");


          /// this implies that you use BSD
            strncpy( cmdi, 
            "   g++ -L/usr/local/lib -lfltk -lXext -lX11 -lm  " 
	    , PATH_MAX );
                   strncat( cmdi , " \"" , PATH_MAX - strlen(cmdi) - 1);
                   strncat( cmdi , idata[n] , PATH_MAX - strlen(cmdi) - 1);
                   strncat( cmdi , "\" " , PATH_MAX - strlen(cmdi) - 1);
                   strncat( cmdi , " -o " , PATH_MAX - strlen(cmdi) - 1);
                   strncat( cmdi , " \"" , PATH_MAX - strlen(cmdi) - 1);
                   strncat( cmdi , targetfile ,  PATH_MAX - strlen(cmdi) - 1);
                   strncat( cmdi , "\" " , PATH_MAX - strlen(cmdi) - 1);

                   if ( fexiststatic( idata[ n ] ) == 1 )
		   {
	    	         printf( "File idata: %d [OK]\n" , fexiststatic( idata[ n ] ) );
	    	         printf( "<CMD: %s>\n" ,  cmdi );
	                 system( cmdi );
                         if ( fexiststatic( targetfile ) == 1 )
	    	              printf( "File found: %s [OK]\n" , targetfile  );
		   }
    }


    return 0;
}



