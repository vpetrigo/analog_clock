#ifndef ANALOG_DIAL_HPP
#define ANALOG_DIAL_HPP

struct Analog_Dial : Graph_lib::Lines {    
  explicit Analog_Dial(const Point& center, int size);
            
  const Point& get_center() const;    
  const int get_radius() const;
    
  static constexpr int hours_q = 12;
  static constexpr int deg_b_hours = 360 / hours_q;    
 private:
  Point c;
  int sz;
};

#endif // ANALOG_DIAL_HPP
