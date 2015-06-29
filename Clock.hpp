#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <ctime>
#include "Graph.h"
#include "Angles.hpp"

struct Time {
    Time() {
        time_refresh();
    }

    vector<int> get_time() const {
        return vector<int> {hour, min, sec};
    }

    void update_time() {
        time_refresh();
    }

 private:
    void time_refresh() {
        struct tm * timeinfo = nullptr;

        time(&tm);
        timeinfo = localtime(&tm);

        hour = timeinfo->tm_hour;
        min = timeinfo->tm_min;
        sec = timeinfo->tm_sec;
    }

    int hour;
    int min;
    int sec;

    time_t tm;
};

struct Clocks : Graph_lib::Lines {  
    Clocks(const Point& center, const int hm_rad) : c{center}, cl_rad{hm_rad} {
        vector<int> cur_time = t.get_time();

        add(c, calc_hourarr_coords(cur_time[0]));
        add(c, calc_minarr_coords(cur_time[1]));
        add(c, calc_secarr_coords(cur_time[2]));
    }

    void update_clock() {
        t.update_time();
        vector<int> cur_time = t.get_time();

        set_point(1, calc_hourarr_coords(cur_time[0]));
        set_point(3, calc_minarr_coords(cur_time[1]));
        set_point(5, calc_secarr_coords(cur_time[2]));
    }

    static constexpr int hours_on_dial = 12;
    static constexpr int mins_on_dial = 60;
    static constexpr int secs_on_dial = 60;

    static constexpr int degs_b_hours = 360 / hours_on_dial;
    static constexpr int degs_b_mins = 360 / mins_on_dial;
    static constexpr int degs_b_secs = 360 / secs_on_dial;

    static constexpr int start_dial_pos = 90;

 private:
    Point calc_hourarr_coords(int hour) const {
        double angle = hour % hours_on_dial * degs_b_hours;

        return circle_coords(c, cl_rad - 40, angle - start_dial_pos);
    }

    Point calc_minarr_coords(int min) const {
        double angle = min * degs_b_mins;

        return circle_coords(c, cl_rad - 25, angle - start_dial_pos);
    }

    Point calc_secarr_coords(int sec) const {
        double angle = sec * degs_b_secs;

        return circle_coords(c, cl_rad - 10, angle - start_dial_pos);
    }

    Point c;
    int cl_rad;

    Time t;
};

#endif // CLOCK_HPP
