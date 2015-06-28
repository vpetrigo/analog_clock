#include "Analog_dial.hpp"
#include "Angles.hpp"

using namespace Graph_lib;

Analog_Dial::Analog_Dial(const Point& center, int size) : c{center}, sz{size} 
{
  double ang = 0;
  
  for (int i = 0; i < hours_q; ++i) {
    add(circle_coords(c, sz, ang), circle_coords(c, sz - 10, ang));
    
    ang += deg_b_hours;
  }
}

const Point& Analog_Dial::get_center() const {
  return c;
}

const int Analog_Dial::get_radius() const {
  return sz;
}
