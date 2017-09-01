
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <cstdlib>                   //for exit(0)

#include <unistd.h>
#include <dirent.h>
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h> 

#include <time.h> 





void nscanner( char *msgstr )
{
	char cmdi[PATH_MAX];
	char cwd[PATH_MAX];

	strncpy( cmdi, "", PATH_MAX );
	strncat( cmdi , " " , PATH_MAX - strlen( cmdi ) -1 );
	strncat( cmdi , " xmsg \"" , PATH_MAX - strlen( cmdi ) -1 );
	strncat( cmdi , msgstr , PATH_MAX - strlen( cmdi ) -1 );
	strncat( cmdi , "\" " , PATH_MAX - strlen( cmdi ) -1 );
	strncat( cmdi , "  " , PATH_MAX - strlen( cmdi ) -1 );
	printf( "<CMD:%s\n>", cmdi );
	system( cmdi );

      long t;
      struct tm *ltime;
      time(&t);
      ltime=localtime(&t);
      char charo[50];  int fooi ; 
      fooi = snprintf( charo, 50 , "%04d%02d%02d%02d%02d%02d",
	1900 + ltime->tm_year, ltime->tm_mon +1 , ltime->tm_mday, 
	ltime->tm_hour, ltime->tm_min, ltime->tm_sec 
	);
	/// size_t siz = sizeof charo ; 

	strncpy( cmdi, " scanimage --mode color >> " , PATH_MAX );
	strncat( cmdi , " \"" , PATH_MAX - strlen(cmdi) - 1);
	strncat( cmdi , charo , PATH_MAX - strlen(cmdi) - 1);
	strncat( cmdi , "-pcscan" , PATH_MAX - strlen(cmdi) - 1);
	strncat( cmdi , "-" , PATH_MAX - strlen(cmdi) - 1);
	strncat( cmdi , msgstr , PATH_MAX - strlen(cmdi) - 1);
	strncat( cmdi , ".ppm\" "  , PATH_MAX - strlen(cmdi) - 1);
	printf( "<PATH: %s>\n" , getcwd( cwd, PATH_MAX ));
	printf( "<CMD:  %s>\n" , cmdi );
	system( cmdi );
}







using namespace std;

void copy_cb( Fl_Widget* , void* );  //function prototypes
void close_cb( Fl_Widget* , void* );
void make_window();

   
int main() 
{

   printf( "\n" );
   printf("****************************\n");
   printf("** 2017, PC SCANNER       **\n" );
   printf("****************************\n");
   printf( "\n" );

   make_window();
   return Fl::run();
}


void make_window() {
  
   //Fl_Window* win= new Fl_Window(300,200, "FLTK PCSCANNER");
   Fl_Window* win= new Fl_Window(350,300, "FLTK FSCANNER");
   win->begin();       
      Fl_Button*  close = new Fl_Button( 125, 150, 70, 30, "&Quit"); //child 1    : 2nd widget
      Fl_Button*  copy =  new Fl_Button( 10+25 , 150, 70, 30, "&Scan!"); //child 0   : 1st widget
      Fl_Input*       inp = new Fl_Input( 100, 50, 140, 30, "Filename");              //child 2 : 3rd widget
      //Fl_Output*    out = new Fl_Output(100, 100, 140, 30, "Filename");     //child 3   : 4th widget
   win->end();
   copy->callback(  copy_cb );
   close->callback( close_cb );
   win->show();
 }





void copy_cb( Fl_Widget* o , void* ) 
{
   Fl_Button* b=(Fl_Button*)o;
   Fl_Input* iw = (Fl_Input*) b -> parent() -> child(2);
   //Fl_Output* ow = (Fl_Output*) b -> parent() -> child(3);
   //ow->value( iw->value() );
   if ( strcmp( iw->value() , "" ) == 0 )
      printf( "Value Item: null\n" );
   else
   {
      printf( "Value Item: %s\n" , iw->value() );
      char strpassed[PATH_MAX];
      strncpy( strpassed, iw->value() , PATH_MAX );
      nscanner( strpassed );
   }



}


void close_cb( Fl_Widget* o, void*) 
{
   exit(0);
}
