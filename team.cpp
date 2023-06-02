#include "nba.cpp"
#include <string>
#include <iostream>
using namespace std;

class Team {
    public:
    void set_starting_lineup(string pg, string sg, string sf, string pf, string c);
    void print_starting_lineup(string pg, string sg, string sf, string pf, string c);
    void set_point_guard(PointGuard pg_in){
        point_guard = pg_in;
    }
    void set_shooting_guard(ShootingGuard sg_in){
        shooting_guard = sg_in;
    }
    void set_small_forward(SmallForward sg_in){
        small_forward = sg_in;
    }
    void set_power_forward(PowerForward pf_in){
        power_forward = pf_in;
    }
    void set_center(Center c_in){
        center = c_in;
    }
    PointGuard get_point_guard(){
        return point_guard;
    }
    ShootingGuard get_shooting_guard(){
        return shooting_guard;
    }
    SmallForward get_small_forward(){
        return small_forward;
    }
    PowerForward get_power_forward(){
        return power_forward;
    }
    Center get_center(){
        return center;
    }
    int get_value(){
        return point_guard.get_value() +
                shooting_guard.get_value() +
                small_forward.get_value() +
                power_forward.get_value() +
                center.get_value();
    }

    void print_starting_lineup(){
        cout << "Point Guard: " << point_guard.get_name() << ", Value: " << point_guard.get_value() << endl;
        cout << "Shooting Guard: " << shooting_guard.get_name() << ", Value: " << shooting_guard.get_value() << endl;
        cout << "Small Forward: " << small_forward.get_name() << ", Value: " << small_forward.get_value() << endl;
        cout << "Power Forward: " << power_forward.get_name() << ", Value: " << power_forward.get_value() << endl;
        cout << "Center: " << center.get_name() << ", Value: " << center.get_value() << endl;
    }

    private:
    PointGuard point_guard;
    ShootingGuard shooting_guard;
    SmallForward small_forward;
    PowerForward power_forward;
    Center center;
};