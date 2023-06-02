#include <string>
#include <iostream>
using namespace std;

class NBAPlayer {
 public:

    //set and get the name of a player
    virtual void set_name(string name_in) = 0;
    virtual string get_name() = 0;

    //set and get the value of a player
    virtual void set_value(int val_in) = 0;
    virtual int get_value() = 0;

    //set and get the position of a player
    virtual void set_position(string position_in) = 0;
    virtual string get_position() = 0;

    //set and get the age of a player
    virtual void set_age(int age_in) =0;
    virtual int get_age() = 0;

    //set and get the team abbreviation of a player
    virtual void set_abbrev(string abbrev_in) = 0;
    virtual string get_abbrev() = 0;
    
private:
    string name;
    int age;
    string abbrev;
    int value;
    string position;
};