#include <iostream>
using namespace std;
#include "nbaplayer.h"

class PointGuard: public NBAPlayer {
    public:
    PointGuard(){
        name = "None";
        age = 0;
        abbrev = "NA";
        value = 0;
        position = "point guard";
    }
    PointGuard(string name_in, int age_in, string team_abbrev, int val, string position_in):
        name(name_in), age(age_in), abbrev(team_abbrev), value(val), position(position_in){}  
    
    void set_name(string name_in) override {
        name = name_in;
    }
    string get_name() override {
        return name;
    }

    void set_value(int val_in) override {
        value = val_in;
    }
    int get_value() override {
        return value;
    }
    
    void set_position(string position_in) override {
        position = position_in;
    }
    string get_position() override {
        return position;
    }

    void set_age(int age_in) override {
        age = age_in;
    }
    int get_age() override {
        return age;
    }

    void set_abbrev(string abbrev_in) override {
        abbrev = abbrev_in;
    }
    string get_abbrev() override {
        return abbrev;
    }

    private:
    string name;
    int age;
    string abbrev;
    int value;
    string position;

};

class ShootingGuard: public NBAPlayer {
    public:
    ShootingGuard(){
        name = "None";
        age = 0;
        abbrev = "NA";
        value = 0;
        position = "shooting guard";
    }
    ShootingGuard(string name_in, int age_in, string team_abbrev, int val, string position_in):
        name(name_in), age(age_in), abbrev(team_abbrev), value(val), position(position_in){}  
    
    void set_name(string name_in) override {
        name = name_in;
    }
    string get_name() override {
        return name;
    }

    void set_value(int val_in) override {
        value = val_in;
    }
    int get_value() override {
        return value;
    }
    
    void set_position(string position_in) override {
        position = position_in;
    }
    string get_position() override {
        return position;
    }

    void set_age(int age_in) override {
        age = age_in;
    }
    int get_age() override {
        return age;
    }

    void set_abbrev(string abbrev_in) override {
        abbrev = abbrev_in;
    }
    string get_abbrev() override {
        return abbrev;
    }


    private:
    string name;
    int age;
    string abbrev;
    int value;
    string position;

};
bool lessValuable_sg(ShootingGuard& lhs, ShootingGuard& rhs, PointGuard point_guard) {
    int lhs_points = 0;
    int rhs_points = 0;
    srand((unsigned int)time(NULL));

    //test left had shooting guard
    if(lhs.get_abbrev() == point_guard.get_abbrev()){
        lhs_points += 1;
    }
    if(lhs.get_age() <= 30 || lhs.get_age() == 99){
        lhs_points += 2;
    }
    if(rand() % 2 == 0){
        lhs_points += 1;
    }
    if(point_guard.get_value() == 1){
        if(lhs.get_value() == 1){
            lhs_points -= 20;
        }
    }

    //test right hand shooting guards
    if(rhs.get_abbrev() == point_guard.get_abbrev()){
        rhs_points += 1;
    }
    if(rhs.get_age() <= 30 || rhs.get_age() == 99){
        lhs_points += 2;
    }
    if(rand() % 2 == 0){
        rhs_points += 1;
    }
    if(point_guard.get_value() == 1){
        if(rhs.get_value() == 1){
            rhs_points -= 20;
        }
    }

    //compare their values
    if(lhs.get_value() > rhs.get_value()){
        lhs_points++;
    }
    else{
        rhs_points++;
    }



    //determine which is higher
    if (lhs_points < rhs_points){
        return true;
    }
    else if (rhs_points < lhs_points){
        return false;
    }
    
    //if rhs and lhs points are equal, return random answer
    return rand() % 2 == 0;
}

class SmallForward: public NBAPlayer {
    public:
    SmallForward(){
        name = "None";
        age = 0;
        abbrev = "NA";
        value = 0;
        position = "small forward";
    }
    SmallForward(string name_in, int age_in, string team_abbrev, int val, string position_in):
        name(name_in), age(age_in), abbrev(team_abbrev), value(val), position(position_in){}  
    
    void set_name(string name_in) override {
        name = name_in;
    }
    string get_name() override {
        return name;
    }

    void set_value(int val_in) override {
        value = val_in;
    }
    int get_value() override {
        return value;
    }
    
    void set_position(string position_in) override {
        position = position_in;
    }
    string get_position() override {
        return position;
    }

    void set_age(int age_in) override {
        age = age_in;
    }
    int get_age() override {
        return age;
    }

    void set_abbrev(string abbrev_in) override {
        abbrev = abbrev_in;
    }
    string get_abbrev() override {
        return abbrev;
    }


    private:
    string name;
    int age;
    string abbrev;
    int value;
    string position;

};

bool lessValuable_sf(SmallForward& lhs, SmallForward& rhs, PointGuard pg, ShootingGuard sg) {
    int lhs_points = 0;
    int rhs_points = 0;
    srand((unsigned int)time(NULL));

    //test lhs
    if(lhs.get_abbrev() == pg.get_abbrev()){
        lhs_points += 1;
    }
    if (lhs.get_abbrev() == sg.get_abbrev()){
        lhs_points += 1;
    }
    if(lhs.get_age() <= 30 || lhs.get_age() == 99){
        lhs_points += 2;
    }
    if(rand() % 2 == 0){
        lhs_points += 1;
    }
    //if we have at least 12 credits left to spend, we do not want a sf with value 1
    if(pg.get_value() + sg.get_value() <= 4){
        if(lhs.get_value() < 2){
            lhs_points -= 20;
        }
    }


    if(pg.get_value() + sg.get_value() <= 2){
        if (lhs.get_value() <= 2){
            lhs_points -= 2;
        }
    }
    //if we only have 7 credits left for 3 players, then it is optimal the sf is less than 3 credits
    else if (pg.get_value() + sg.get_value() >= 9){
        if(lhs.get_value() > 3){
            lhs_points -= 20;
        }
    }

    //test rhs
    if(rhs.get_abbrev() == pg.get_abbrev()){
        rhs_points += 1;
    }
    if(rhs.get_abbrev() == sg.get_abbrev()){
        rhs_points += 1;
    }
    if(rhs.get_age() <= 30 || rhs.get_age() == 99){
        lhs_points += 2;
    }
    if(rand() % 2 == 0){
        rhs_points += 1;
    }
    //if we have at least 12 credits left to spend, we do not want a sf with value 1
    if(pg.get_value() + sg.get_value() <= 4){
        if(rhs.get_value() < 2){
            rhs_points -= 20;
        }
    }


    if(pg.get_value() + sg.get_value() <= 2){
        if (rhs.get_value() <= 2){
            rhs_points -= 2;
        }
    }
    else if (pg.get_value() + sg.get_value() >= 9){
        if(rhs.get_value() > 3){
            rhs_points -= 20;
        }
    }

    //compare their values
    if(lhs.get_value() > rhs.get_value()){
        lhs_points++;
    }
    else{
        rhs_points++;
    }


    //determine which is higher
    if (lhs_points < rhs_points){
        return true;
    }
    else if (rhs_points < lhs_points){
        return false;
    }
    
    //if rhs and lhs points are equal, return random answer
    return rand() % 2 == 0;
}



class PowerForward: public NBAPlayer {
    public:
    PowerForward(){
        name = "None";
        age = 0;
        abbrev = "NA";
        value = 0;
        position = "power forward";
    }
    PowerForward(string name_in, int age_in, string team_abbrev, int val, string position_in):
        name(name_in), age(age_in), abbrev(team_abbrev), value(val), position(position_in){}  
    
    void set_name(string name_in) override {
        name = name_in;
    }
    string get_name() override {
        return name;
    }

    void set_value(int val_in) override {
        value = val_in;
    }
    int get_value() override {
        return value;
    }
    
    void set_position(string position_in) override {
        position = position_in;
    }
    string get_position() override {
        return position;
    }

    void set_age(int age_in) override {
        age = age_in;
    }
    int get_age() override {
        return age;
    }

    void set_abbrev(string abbrev_in) override {
        abbrev = abbrev_in;
    }
    string get_abbrev() override {
        return abbrev;
    }

    private:
    string name;
    int age;
    string abbrev;
    int value;
    string position;

};

bool lessValuable_pf(PowerForward& lhs, PowerForward& rhs, PointGuard pg, ShootingGuard sg, SmallForward sf){
    int lhs_points = 0;
    int rhs_points = 0;
    srand((unsigned int)time(NULL));

    //test lhs
    if(lhs.get_abbrev() == pg.get_abbrev()){
        lhs_points += 1;
    }
    if (lhs.get_abbrev() == sg.get_abbrev()){
        lhs_points += 1;
    }
    if(lhs.get_abbrev() == sf.get_abbrev()){
        lhs_points += 1;
    }
    if(lhs.get_age() <= 30 || lhs.get_age() == 99){
        lhs_points += 2;
    }
    if(rand() % 2 == 0){
        lhs_points += 1;
    }
    

    //if we have 9 or more credits left, we don't want anyone less than a 4 value pf
    if(pg.get_value() + sg.get_value() + sf.get_value() <= 7){
        if (lhs.get_value() <= 3){
            lhs_points -= 20;
        }
    }
    //if we have 8 credits left, we don't want anyone less than a 3 value pf
    else if(pg.get_value() + sg.get_value() + sf.get_value() <= 8){
        if (lhs.get_value() <= 2){
            lhs_points -= 20;
        }
    }
    //if we have 7 credits left, we don't want anyone less than a 2 rated pf
    else if(pg.get_value() + sg.get_value() + sf.get_value() <= 9){
        if (lhs.get_value() == 1){
            lhs_points -= 20;
        }
    }
    //if we have less than 4 credits left, we don't want anyone more than a 2 rated pf
    else if (pg.get_value() + sg.get_value() + sf.get_value() > 12){
        if(lhs.get_value() > 2){
            lhs_points -= 20;
        }
    }
    //if we have less than 5 credits left, we don't want anyone more than a 3 rated pf
    else if (pg.get_value() + sg.get_value() +sf.get_value() > 11){
        if(lhs.get_value() > 3){
            lhs_points -= 20;
        }
    }
    //if we have less than 6 credits left, we don't want anyone more than a 4 rated pf
    else if (pg.get_value() + sg.get_value() +sf.get_value() > 10){
        if(lhs.get_value() > 4){
            lhs_points -= 20;
        }
    }


    //test rhs
    if(rhs.get_abbrev() == pg.get_abbrev()){
        rhs_points += 1;
    }
    if(rhs.get_abbrev() == sg.get_abbrev()){
        rhs_points += 1;
    }
    if(rhs.get_abbrev() == sf.get_abbrev()){
        rhs_points += 1;
    }
    if(rhs.get_age() <= 30 || rhs.get_age() == 99){
        lhs_points += 2;
    }
    if(rand() % 2 == 0){
        rhs_points += 1;
    }
    

    if(pg.get_value() + sg.get_value() +sf.get_value() <= 7){
        if (rhs.get_value() <= 3){
            rhs_points -= 20;
        }
    }
    else if(pg.get_value() + sg.get_value() +sf.get_value() <= 8){
        if (rhs.get_value() <= 2){
            rhs_points -= 20;
        }
    }
    else if(pg.get_value() + sg.get_value() +sf.get_value() <= 9){
        if (rhs.get_value() == 1){
            rhs_points -= 20;
        }
    }
    else if (pg.get_value() + sg.get_value() +sf.get_value() > 12){
        if(rhs.get_value() > 2){
            rhs_points -= 20;
        }
    }
    else if (pg.get_value() + sg.get_value() +sf.get_value() > 11){
        if(rhs.get_value() > 3){
            rhs_points -= 20;
        }
    }
    else if (pg.get_value() + sg.get_value() +sf.get_value() > 10){
        if(rhs.get_value() > 4){
            rhs_points -= 20;
        }
    }

    //compare their values
    if(lhs.get_value() > rhs.get_value()){
        lhs_points++;
    }
    else{
        rhs_points++;
    }


    //determine which is higher
    if (lhs_points < rhs_points){
        return true;
    }
    else if (rhs_points < lhs_points){
        return false;
    }
    
    //if rhs and lhs points are equal, return random answer
    return rand() % 2 == 0;
}


class Center: public NBAPlayer {
    public:
    Center(){
        name = "None";
        age = 0;
        abbrev = "NA";
        value = 0;
        position = "center";
    }
    Center(string name_in, int age_in, string team_abbrev, int val, string position_in):
        name(name_in), age(age_in), abbrev(team_abbrev), value(val), position(position_in){}  
    
    void set_name(string name_in) override {
        name = name_in;
    }
    string get_name() override {
        return name;
    }

    void set_value(int val_in) override {
        value = val_in;
    }
    int get_value() override {
        return value;
    }
    
    void set_position(string position_in) override {
        position = position_in;
    }
    string get_position() override {
        return position;
    }

    void set_age(int age_in) override {
        age = age_in;
    }
    int get_age() override {
        return age;
    }

    void set_abbrev(string abbrev_in) override {
        abbrev = abbrev_in;
    }
    string get_abbrev() override {
        return abbrev;
    }


    private:
    string name;
    int age;
    string abbrev;
    int value;
    string position;

};
