

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_File_Browser.H>
#include <FL/fl_ask.H>
//
// Demonstrate Fl_File_Browser with callback -- erco 6/4/11
//
void BrowserCallback(Fl_Widget *w, void *data) {
  Fl_File_Browser *fbrow = (Fl_File_Browser*)w;
  int index = fbrow->value();            // get index of selected item
  if ( index > 0 ) {                     // valid item?
    fl_alert("Selected: %d (%s)\n", index, fbrow->text(index));  // show item's text
  }
}
int main(int argc, char **argv) {
    Fl_Window win(300, 400, "Fl_File_Browser with Callback");
        Fl_File_Browser fbrow(10,10,300-20,400-20);
        fbrow.load(".");                    // load directory listing of current directory
        fbrow.type(FL_HOLD_BROWSER);        // use for single selection
        //fbrow.type(FL_MULTI_BROWSER);     // use for multiple selection
        fbrow.callback(BrowserCallback);
    win.end();
    win.resizable(fbrow);
    win.show(argc,argv);
    return(Fl::run());
}
    