#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "team.cpp"

class Game{
    public:
    Game();
    Game(Team userTeam_in, Team computerTeam_in);
    void print_spaces(int length);
    void print_teams_side_by_side();
    void check_duos(vector<string> names, int &team_points);
    int calculate_points(Team team);
    bool determine_winner(int user_points, int computer_points);
    bool play();
    

    private:
    Team userTeam;
    Team computerTeam;
};

Game::Game(){
    userTeam = Team();
    computerTeam = Team();
}

Game::Game(Team userTeam_in, Team computerTeam_in){
    userTeam = userTeam_in;
    computerTeam = computerTeam_in;
}

void Game:: print_spaces(int length){
    for (int i = 0; i < length; ++i){
        cout << " ";
    }
}

void Game::print_teams_side_by_side(){
    int length = 0;
    cout << "Your team:               Computer's team: " << endl; //15 spaces between the : and C
    
    //print the point guards
    cout << userTeam.get_point_guard().get_name();
    length = 25 - int(userTeam.get_point_guard().get_name().size());
    print_spaces(length);
    cout << computerTeam.get_point_guard().get_name() << endl;

    //print the shooting guards
    cout << userTeam.get_shooting_guard().get_name();
    length = 25 - int(userTeam.get_shooting_guard().get_name().size());
    print_spaces(length);
    cout << computerTeam.get_shooting_guard().get_name() << endl;

    //print the small forwards
    cout << userTeam.get_small_forward().get_name();
    length = 25 - int(userTeam.get_small_forward().get_name().size());
    print_spaces(length);
    cout << computerTeam.get_small_forward().get_name() << endl;

    //print the power forwards
    cout << userTeam.get_power_forward().get_name();
    length = 25 - int(userTeam.get_power_forward().get_name().size());
    print_spaces(length);
    cout << computerTeam.get_power_forward().get_name() << endl;

    //print the centers
    cout << userTeam.get_center().get_name();
    length = 25 - int(userTeam.get_center().get_name().size());
    print_spaces(length);
    cout << computerTeam.get_center().get_name() << endl;

}

void Game::check_duos(vector<string> names, int &team_points){
    for (size_t i = 0; i < names.size(); ++i){

        //check for MJ-pippen duo
        if (names.at(i) == "Michael Jordan"){
            for (size_t j = i + 1; j < names.size(); ++ j){
                if (names.at(i) == "Scottie Pippen"){
                    team_points += 3;
                }
            }
        }
        if (names.at(i) == "Scottie Pippen"){
            for (size_t j = i + 1; j < names.size(); ++ j){
                if (names.at(i) == "Michael Jordan"){
                    team_points += 3;
                }
            }
        }

        //check for Lebron-Wade duo
        if (names.at(i) == "Lebron James"){
            for (size_t j = i + 1; j < names.size(); ++ j){
                if (names.at(i) == "Dwayne Wade"){
                    team_points += 3;
                }
            }
        }
        if (names.at(i) == "Dwayne Wade"){
            for (size_t j = i + 1; j < names.size(); ++ j){
                if (names.at(i) == "Lebron James"){
                    team_points += 3;
                }
            }
        }

        //check for kobe-shaq duo
        if (names.at(i) == "Kobe Bryant"){
            for (size_t j = i + 1; j < names.size(); ++ j){
                if (names.at(i) == "Shaquielle O'neal"){
                    team_points += 3;
                }
            }
        }
        if (names.at(i) == "Shaquielle O'neal"){
            for (size_t j = i + 1; j < names.size(); ++ j){
                if (names.at(i) == "Kobe Bryant"){
                    team_points += 3;
                }
            }
        }
        //check for steph-klay duo
        if (names.at(i) == "Steph Curry"){
            for (size_t j = i + 1; j < names.size(); ++ j){
                if (names.at(i) == "Klay Thompson"){
                    team_points += 3;
                }
            }
        }
        if (names.at(i) == "Klay Thompson"){
            for (size_t j = i + 1; j < names.size(); ++ j){
                if (names.at(i) == "Steph Curry"){
                    team_points += 3;
                }
            }
        }

        //check for magic-kareem duo
        if (names.at(i) == "Magic Johnson"){
            for (size_t j = i + 1; j < names.size(); ++ j){
                if (names.at(i) == "Kareem Abdul-Jabbar"){
                    team_points += 3;
                }
            }
        }
        if (names.at(i) == "Kareem Abdul-Jabbar"){
            for (size_t j = i + 1; j < names.size(); ++ j){
                if (names.at(i) == "Magic Johnson"){
                    team_points += 3;
                }
            }
        }

        //this is not quite a duo, but if MJ and Lebron are on the same team, its probably over for the other team
                //check for magic-kareem duo
        if (names.at(i) == "Michael Jordan"){
            for (size_t j = i + 1; j < names.size(); ++ j){
                if (names.at(i) == "Lebron James"){
                    team_points += 5;
                }
            }
        }
        if (names.at(i) == "Lebron James"){
            for (size_t j = i + 1; j < names.size(); ++ j){
                if (names.at(i) == "Michael Jordan"){
                    team_points += 3;
                }
            }
        }
    }
}

int Game::calculate_points(Team team){
    int points = 0;
    points += team.get_value();
    string pg_abbrev = team.get_point_guard().get_abbrev();
    string sg_abbrev = team.get_shooting_guard().get_abbrev();
    string sf_abbrev = team.get_small_forward().get_abbrev();
    string pf_abbrev = team.get_power_forward().get_abbrev();
    string c_abbrev = team.get_center().get_abbrev();
    vector<string> abbrevs;
    abbrevs.push_back(pg_abbrev);
    abbrevs.push_back(sg_abbrev);
    abbrevs.push_back(sf_abbrev);
    abbrevs.push_back(pf_abbrev);
    abbrevs.push_back(c_abbrev);

    bool one_match = false;
    bool two_match = false;
    bool three_match = false;
    //this double for loop evaluates points based on if players are on the same NBA team
    for (size_t i = 0 ; i < abbrevs.size(); ++i){
        for (size_t j = i + 1; j < abbrevs.size(); ++j){
            //we have matched two
            if(abbrevs.at(i) == abbrevs.at(j) && three_match){
                points += 2;
            }
            else if (abbrevs.at(i) == abbrevs.at(j) && one_match && two_match){
                points += 6;
                three_match = true;
            }
            //we have matched only one
            else if (abbrevs.at(i) == abbrevs.at(j) && one_match){
                points += 4;
                two_match = true;
            }
            //we have not matched one yet
            else if (abbrevs.at(i) == abbrevs.at(j) && !one_match){
                points += 3;
                one_match = true;
            }

        }
        one_match = false;
        two_match = false;
        three_match = false;
    }

    vector<string> names;
    string name1 = team.get_point_guard().get_name();
    string name2 = team.get_shooting_guard().get_name();
    string name3 = team.get_small_forward().get_name();
    string name4 = team.get_power_forward().get_name();
    string name5 = team.get_center().get_name();
    names.push_back(name1);
    names.push_back(name2);
    names.push_back(name3);
    names.push_back(name4);
    names.push_back(name5);
    for (size_t i = 0; i < names.size(); ++i){
        if (names.at(i) == "Lebron James"){
            points += 2;
        }
        else if (names.at(i) == "Michael Jordan"){
            points += 2;
        }
        else if (names.at(i) == "Tim Duncan"){
            points += 2;
        }
        else if (names.at(i) == "Shaquille O'neal"){
            points += 2;
        }
        else if (names.at(i) == "Steph Curry"){
            points += 2;
        }
        else if (names.at(i) == "Magic Johnson"){
            points += 2;
        }
        else if (names.at(i) == "Larry Bird"){
            points += 2;
        }
        else if (names.at(i) == "Kareem Abdul-Jabbar"){
            points += 2;
        }
        else if (names.at(i) == "Bill Russell"){
            points += 2;
        }
        else if (names.at(i) == "Damian Lillard"){
            if (rand() % 2 == 0){
                points += 5;
            }
        }
    }

    check_duos(names, points);
    

    //check the teams random age
    int age1 = team.get_point_guard().get_age();
    int age2 = team.get_shooting_guard().get_age();
    int age3 = team.get_small_forward().get_age();
    int age4 = team.get_power_forward().get_age();
    int age5 = team.get_center().get_age();
    vector <int> ages;
    ages.push_back(age1);
    ages.push_back(age2);
    ages.push_back(age3);
    ages.push_back(age4);
    ages.push_back(age5);
    //if the player is retired, revert their age to from 99 to 30; 
    //this sets up the average age calculation
    for (size_t i = 0; i < ages.size(); ++i){
        if(ages.at(i) == 99){
            ages.at(i) = 30;
        }
    }


    double average_age = (
                    ages.at(0) +
                    ages.at(1) +
                    ages.at(2) +
                    ages.at(3) +
                    ages.at(4)
                    ) / 5;
    if(average_age >= 24 && average_age <= 28){
        points += 4;
    }

    int value1 = team.get_point_guard().get_value();
    int value2 = team.get_shooting_guard().get_value();
    int value3 = team.get_small_forward().get_value();
    int value4 = team.get_power_forward().get_value();
    int value5 = team.get_center().get_value();
    vector<int> values;
    values.push_back(value1);
    values.push_back(value2);
    values.push_back(value3);
    values.push_back(value4);
    values.push_back(value5);

    int value1counter = 0;
    int value5counter = 0;
    //check for multiple players value 1 or value 5, unbalanced teams
    for (size_t i = 0; i < values.size(); i++){
        if (values.at(i) == 1){
            value1counter++;
        }
        else if(values.at(i) == 5){
            value5counter++;
        }
    }
    if (value1counter >= 2){ points -= 3;}
    else if (value5counter >= 2){ points -= 3;}

    //basketball always has a bit of randomness to it!
    //let these if statements simulate random conditions, i.e. bad refs or off day for players
    if (rand() % 2 == 0){
        if (rand() % 2 == 0){
            points += 3;
        }
        else {
            points += 1;
        }
    }
    else{
        if (rand() % 2 == 0){
            points += 1;
        }
        else {
            points -= 1;
        }
    }

    int random = rand();
    if (random % 4 == 0 || random % 4 == 3){
        points += 3;
    }
    else{
        points -= 3;
    }

    return points;
}

bool Game::determine_winner(int user_points, int computer_points){
    if (user_points > computer_points){
        cout << "Your team won by a score of " << user_points << " to " << computer_points << endl;
        return true;
    }
    else if (computer_points > user_points){
        cout << "The computer's team won by a score of " << computer_points << " to " << user_points << endl;
        return false;
    }
    else{//they are equal
        if(rand() % 2 == 0){
            cout << "Your team won by a score of " << user_points + 1 << " to " << computer_points << endl;
            return true;
        }
        else{
            cout << "The computer's team won by a score of " << computer_points + 1 << " to " << user_points << endl;
            return false;
        }

    }
}


bool Game::play(){
    print_teams_side_by_side();
    srand((unsigned int)time(NULL));
    int random_num = rand() % 36;
    int computer_score = 75 + random_num;
    int user_score = 75 + random_num;

    computer_score += calculate_points(computerTeam);
    user_score += calculate_points(userTeam);

    cout << endl;
    return determine_winner(user_score, computer_score);
}
