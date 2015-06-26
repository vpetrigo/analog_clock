#include <utility>
#include <cmath>
#include <ctime>
#include "Window.h"
#include "GUI.h"

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
  Clocks c{clock_xy, arrow_rad};
  
  win.attach(ac);
  win.attach(c);
  
  gui_main();
  
  return 0;
}
