#ifndef CLOCK_HPP
#define CLOCK_HPP

#include "Graph.h"

struct Clocks : Graph_lib::Lines {  
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

#endif // CLOCK_HPP
