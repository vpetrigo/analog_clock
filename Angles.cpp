#include <cmath>
#include "Point.h"

double deg_to_rad(double ang) {
  return ang * M_PI / 180;
}

Point circle_coords(const Point& center, const double radius, const double angle) {
  int x, y;

  double rad_ang = deg_to_rad(angle);

  x = center.x + radius * cos(rad_ang);
  y = center.y + radius * sin(rad_ang);

  return Point{x, y};
}
