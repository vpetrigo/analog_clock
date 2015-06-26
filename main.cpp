#include <iostream>
#include <utility>
#define _USE_MATH_DEFINES
#include <cmath>
#include <ctime>
#include "Window.h"
#include "GUI.h"

using namespace std;
using namespace Graph_lib;

double deg_to_rad(const double deg);

struct Analog_Dial : Lines {    
    explicit Analog_Dial(const Point& center, int size) : c{center}, sz{size} {
        double ang = 0;
        
        for (int i = 0; i < hours_q; ++i) {
            add(circle_coords(sz, ang), circle_coords(sz - 10, ang));
            
            ang += deg_b_hours;
        }
    }
    
    const Point& get_center() const {
        return c;
    }
    
    int get_radius() const {
        return sz;
    }
    
    static constexpr int hours_q = 12;
    static constexpr int deg_b_hours = 360 / hours_q;    
 private:
    Point circle_coords(const double radius, const double angle);
 
    Point c;
    int sz;
};

struct Clocks : Lines {  
    Clocks(const Point& center, const int hm_rad) : c{center}, cl_rad{hm_rad} {
        time_t tm;
        struct tm * timeinfo = nullptr;
        
        time (&tm);
        timeinfo = localtime(&tm);
        
        hour.set_val(timeinfo->tm_hour);
        min.set_val(timeinfo->tm_min);
        sec.set_val(timeinfo->tm_sec);
        
        add(c, conv_tm_to_coord(hour));
        add(c, conv_tm_to_coord(min));
        add(c, conv_tm_to_coord(sec));
    }
    
 private:
    struct Hour {
        explicit Hour(int h) : h_{h} {}
        
        static constexpr int num_of_div = 12;
        static constexpr int deg_p_dib = 360 / num_of_div;
        
        const int get_val() const {
            return h_;
        }
        
        void set_val(const int h) {
            h_ = h;
        }
     private:
        int h_;
    };
    
    struct Minutes {
        explicit Minutes(int m) : m_{m} {}
        
        static constexpr int num_of_div = 60;
        static constexpr int deg_p_dib = 360 / num_of_div;
        
        const int get_val() const {
            return m_;
        }
        
        void set_val(const int m) {
            m_ = m;
        }
     private:
        int m_;
    };
    
    struct Seconds {
        explicit Seconds(int s) : s_{s} {}
        
        static constexpr int num_of_div = 60;
        static constexpr int deg_p_dib = 360 / num_of_div;
        
        const int get_val() const {
            return s_;
        }
        
        void set_val(const int s) {
            s_ = s;
        }
     private:
        int s_;
    };
 
    template <class T>
    Point conv_tm_to_coord(const T& time) {
        int x, y;  
        double rad_andle = deg_to_rad(time.get_val() % T::num_of_div * T::deg_p_dib - 90);
       
        x = c.x + cl_rad * cos(rad_andle);
        y = c.y + cl_rad * sin(rad_andle);
        
        return Point {x, y};
    }
    
    Point c;
    int cl_rad;
    
    Hour hour{0};
    Minutes min{0};
    Seconds sec{0};
};

Point Analog_Dial::circle_coords(const double radius, const double angle) {
    int x, y;
    double rad_andle = deg_to_rad(angle);
    
    x = c.x + radius * cos(rad_andle);
    y = c.y + radius * sin(rad_andle);
    
    return Point{x, y};
}

int main() {
    Graph_lib::Window win {{0, 0}, 800, 600, "Test"};
    
    Analog_Dial ac {{400, 300}, 150};
    Clocks c{{400, 300}, 100};

    win.attach(ac);
    win.attach(c);
    
    gui_main();
    
    return 0;
}

double deg_to_rad(const double deg) {
    return deg * M_PI / 180;
}

