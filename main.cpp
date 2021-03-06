#include "Window.h"
#include "GUI.h"
#include "Analog_dial.hpp"
#include "Clock.hpp"
#include <unistd.h>

using namespace std;
using namespace Graph_lib;

constexpr int window_w = 800;
constexpr int window_h = 600;
const Point xy {0, 0};
const Point clock_xy {window_w / 2, window_h / 2};
constexpr int dial_rad = 150;
constexpr int arrow_rad = 100;

int main() {
  Graph_lib::Window win {xy, window_w, window_h, "Test"};

  Analog_Dial ac {clock_xy, dial_rad};
  Clocks c{clock_xy, dial_rad};
  
  win.attach(ac);
  win.attach(c);

  while (Fl::wait()) {
    sleep(1);
    c.update_clock();
    Fl::redraw();
  }

  return 0;
}
