
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_ask.H>
#include <stdio.h>

int main(int argc, char **argv) 
{
    Fl::scheme(NULL);
    Fl::args(argc, argv);
    Fl::get_system_colors();

    ////////////////////////////////////////////////////////
    if ( argc == 2)
    {
         fl_message( argv[ 1 ] );
         return 0;
    }

  return 0;

}

