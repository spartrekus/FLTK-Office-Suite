
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h> //chdir

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_File_Browser.H>
#include <FL/fl_ask.H>

//#define PATH_MAX 1000

//
// Demonstrate Fl_File_Browser with callback -- erco 6/4/11
//
void BrowserCallback(Fl_Widget *w, void *data) 
{
  Fl_File_Browser *fbrow = (Fl_File_Browser*)w;
  int index = fbrow->value();            // get index of selected item
  if ( index > 0 ) 
  {  
         // valid item?
         //fl_alert("Selected: %d (%s)\n", index, fbrow->text(index));  // show item's text
         char myfile[PATH_MAX];
         strncpy( myfile, fbrow->text( index ), PATH_MAX );
         char cmdi[PATH_MAX];
         printf("SYS CALL FEH: %s\n", myfile );
         strncpy( cmdi, "", PATH_MAX );
         strncat( cmdi , " feh --bg-tile   " , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , " \"" , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , myfile , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , "\"" , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , "  &  " , PATH_MAX - strlen( cmdi ) -1 );
         printf( "<CMD: %s>\n", cmdi );
         system( cmdi );
  }
 }




int main()
{

    chdir( getenv( "HOME" ));
    chdir( "Wallpapers" );

    Fl_Window win(300, 400, "FLWALLPAPER");
        Fl_File_Browser fbrow(10,10,300-20,400-20);
        fbrow.load(".");                    // load directory listing of current directory
        fbrow.type(FL_HOLD_BROWSER);        // use for single selection
        //fbrow.type(FL_MULTI_BROWSER);     // use for multiple selection
        fbrow.callback(BrowserCallback);
    win.end();
    win.resizable(fbrow);
    win.show();
    return(Fl::run());
}
    

