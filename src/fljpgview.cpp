#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Box.H>
// COMPILE: fltk-config --use-images --compile load-jpeg.cxx


int main( int argc, char *argv[])
{
    fl_register_images();                       // initialize image lib

    ////////////////////////////////////////////////////////
    if ( argc == 2)
      if ( strcmp( argv[1] , "" ) !=  0 ) 
      {
          Fl_Window     win(720,486);                 // make a window
          Fl_Box        box(10,10,720-20,486-20);     // widget that will contain image
          Fl_JPEG_Image jpg( argv[ 1 ] );      // load jpeg image into ram
          box.image(jpg);                             // attach jpg image to box
          win.show();
          return(Fl::run());
      }
   return 0;
} 
    
