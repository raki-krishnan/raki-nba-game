#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include "game.cpp"
using namespace std;

void print_instructions(){
    cout << endl;
    cout << "/////////////////////////////////////////////////////" << endl;
    cout << "Your goal is to create the best team possible" << 
    " and beat the randomized computer team." << endl;
    cout << "When you are asked to choose a player, " << 
    "please type in the number next to their name." << endl;
    cout << "The number next to the player's name is also their value. Each player has a value worth 1-5." << endl;
    cout << "You start with 16 credits, and each time you choose a player, ";
    cout << "the number of credits you pay is listed next to their name." << endl;
    cout << "Good luck and choose wisely!" << endl;
    cout << endl;
}
void print_status(Team team, int credits){
    
    cout << endl;
    cout << "/////////////////////////////////////////////////////" << endl;
    cout << "Current credits: " << credits << endl;
    cout << "Current team: " << endl;
    team.print_starting_lineup();
    cout << "/////////////////////////////////////////////////////" << endl;
    cout << endl;
}
bool is_valid_choice(int choice){
    if (choice <= 5 && choice >= 1){
        return true;
    }
    cout << "Your choice was invalid. Please enter a number 1-5: " << endl;
    return false;
}
void reset_choice_variables(int &choice, bool &valid_choice){
    choice = 0;
    valid_choice = false;
}
int random_number_generator(int num_players){
    static bool is_seeded = false;  // Ensure srand is called only once

    if (!is_seeded) {
        srand((unsigned int)time(NULL));
        is_seeded = true;
    }

    int random_number = rand() % num_players;
    return random_number;
}

Team create_computer_team(vector<PointGuard> point_guards, vector<ShootingGuard> shooting_guards, 
vector<SmallForward> small_forwards, vector<PowerForward> power_forwards, vector<Center> centers){
    
    Team computerTeam;
    int credits = 16;
    srand((unsigned int)time(NULL));

    PointGuard pg_computer = point_guards.at(size_t(rand()) % point_guards.size());
    computerTeam.set_point_guard(pg_computer); //The point guard the computer takes is random
    credits -= pg_computer.get_value();


    //set the shooting guard
    ShootingGuard sg_computer = shooting_guards.at(size_t(rand()) % shooting_guards.size());
    for(size_t i = 0; i < shooting_guards.size(); i++){
        if(lessValuable_sg(sg_computer, shooting_guards.at(i), pg_computer)){
            sg_computer = shooting_guards.at(i);
        }
    }
    computerTeam.set_shooting_guard(sg_computer);
    credits -= sg_computer.get_value();

    //set the small forward
    SmallForward sf_computer = small_forwards.at(size_t(rand()) % small_forwards.size());
    for (size_t i = 0; i < small_forwards.size(); ++i){
        if(lessValuable_sf(sf_computer, small_forwards.at(i), pg_computer, sg_computer)){
            sf_computer = small_forwards.at(i);
        }
    }

    computerTeam.set_small_forward(sf_computer);
    credits -= sf_computer.get_value();

    //set the power forward
    PowerForward pf_computer = power_forwards.at(size_t(rand()) % power_forwards.size());
    for (size_t i = 0; i < power_forwards.size(); ++i){
        if(lessValuable_pf(pf_computer, power_forwards.at(i), pg_computer, sg_computer, sf_computer)){
            pf_computer = power_forwards.at(i);
        }
    }
    computerTeam.set_power_forward(pf_computer);
    credits -= pf_computer.get_value();
    //set the center
    Center c_computer;
    if (credits >= 5){
        c_computer = centers.at(centers.size() - 1);
    }
    else{
        for (size_t i = 0; i < size_t(credits); ++i){
            if (centers.at(i).get_value() == credits){
                c_computer = centers.at(i);
            }
            //ex. if we have 3 credits left but the value 3 center is already taken, then set 
            //c_computer to the center in the spot before the current one because the current center is too expensive
            else if (centers.at(i).get_value() > credits){
                c_computer = centers.at(i - 1);
            }
        }
    }
    computerTeam.set_center(c_computer);
    credits -= c_computer.get_value();

    return computerTeam;
}

void tally_score(int &userWins, int &computerWins, bool userWon){
    if(userWon){
        userWins++;
    }
    else{
        computerWins++;
    }
}
PointGuard generate_point_guard_5(){

    PointGuard steph_curry("Steph Curry", 35, "GSW", 5, "point guard");
    PointGuard magic_johnson("Magic Johnson", 99, "LAL", 5, "point guard");
    PointGuard jerry_west("Jerry West", 99, "LAL", 5, "point guard");
    PointGuard oscar_robertson("Oscar Robertson", 99, "MIL", 5, "point guard");
    PointGuard isaiah_thomas("Isaiah Thomas(older one)", 99, "DET", 5, "point guard");
    PointGuard kyrie_irving("Kyrie Irving", 31, "DAL", 4, "point guard");
    PointGuard allen_iverson("Allen Iverson", 99, "PHI", 5, "point guard");
    

    vector<PointGuard> point_guards;
    point_guards.push_back(steph_curry); //point_guards.at(0)
    point_guards.push_back(magic_johnson); //point_guards.at(1) etc
    point_guards.push_back(jerry_west);
    point_guards.push_back(oscar_robertson);
    point_guards.push_back(isaiah_thomas);
    point_guards.push_back(kyrie_irving);
    point_guards.push_back(allen_iverson);
    


    return point_guards.at(size_t(random_number_generator(int(point_guards.size()))));
}

PointGuard generate_point_guard_4(){
    PointGuard russell_westbrook("Russell Westbrook", 34, "LAC", 4, "point guard");
    PointGuard chris_paul("Chris Paul", 38, "PHX", 5, "point guard");
    PointGuard john_stockton("John Stockton", 99, "UTA", 4, "point guard");
    PointGuard steve_nash("Steve Nash", 99, "PHX", 4, "point guard");
    PointGuard rajon_rondo("Rajon Rondo", 99, "BOS", 4, "point guard");
    PointGuard jason_kidd("Jason Kidd", 99, "DAL", 4, "point guard");
    PointGuard damian_lillard("Damian Lillard", 32, "POR", 4, "point guard");
    PointGuard gary_payton("Gary Payton", 99, "PKC", 4, "point guard");
    PointGuard bob_cousy("Bob Cousy", 99, "BOS", 5, "point guard");
    

    vector<PointGuard> point_guards;
    point_guards.push_back(russell_westbrook);
    point_guards.push_back(chris_paul);
    
    point_guards.push_back(john_stockton);
    point_guards.push_back(steve_nash);
    point_guards.push_back(rajon_rondo);
    point_guards.push_back(jason_kidd);
    point_guards.push_back(damian_lillard);
    point_guards.push_back(gary_payton);
    point_guards.push_back(bob_cousy);
    
   return point_guards.at(size_t(random_number_generator(int(point_guards.size()))));
}

PointGuard generate_point_guard_3(){
    PointGuard jamal_murray("Jamal Murray", 26, "DEN", 3, "point guard");
    PointGuard trae_young("Trae Young", 24, "ATL", 3, "point guard");
    PointGuard deaaron_fox("De'Aaron Fox", 25, "SAC", 3, "point guard");
    PointGuard kemba_walker("Jrue Holiday", 32, "MIL", 3, "point guard");
    PointGuard deron_williams("Deron Williams", 99, "BKN", 3, "point guard");
    PointGuard ja_morant("Ja Morant", 23, "MEM", 3, "point guard");
    PointGuard steve_francis("Steve Francis", 99, "HOU", 3, "point guard");
    PointGuard shai_ga("Shai Gilgeous-Alexander", 99, "OKC", 3, "point guard");

    vector<PointGuard> point_guards;
    point_guards.push_back(jamal_murray);
    point_guards.push_back(trae_young);
    point_guards.push_back(deaaron_fox);
    point_guards.push_back(kemba_walker);
    point_guards.push_back(deron_williams);
    point_guards.push_back(ja_morant);
    point_guards.push_back(steve_francis);
    point_guards.push_back(shai_ga);
    
    return point_guards.at(size_t(random_number_generator(int(point_guards.size()))));
}

PointGuard generate_point_guard_2(){

    PointGuard fred_vanvleet("Fred VanVleet", 29, "TOR", 2, "point guard");
    PointGuard spencer_dinwiddie("Spencer Dinwiddie", 30, "BKN", 2, "point guard");
    PointGuard john_wall("John Wall", 32, "LAC", 2, "point guard");
    PointGuard jalen_brunson("Jalen Brunson", 26, "NYK", 2, "point guard");
    PointGuard lamelo_ball("LaMelo Ball", 21, "CHA", 2, "point guard");
    PointGuard kemba_walker("Kemba Walker", 33, "CHA", 2, "point guard");
    PointGuard kyle_lowry("Kyle Lowry", 37, "MIA", 2, "point guard");
   


    vector<PointGuard> point_guards;

    point_guards.push_back(fred_vanvleet);
    point_guards.push_back(spencer_dinwiddie);
    point_guards.push_back(john_wall);
    point_guards.push_back(jalen_brunson);
    point_guards.push_back(lamelo_ball);
    point_guards.push_back(kemba_walker);
    point_guards.push_back(kyle_lowry);

    return point_guards.at(size_t(random_number_generator(int(point_guards.size()))));
}

PointGuard generate_point_guard_1(){
    PointGuard lonzo_ball("Lonzo Ball", 25, "CHI", 1, "point guard");
    PointGuard patrick_beverly("Patrick Beverley", 34, "CHI", 1, "point guard");
    PointGuard mike_conley("Mike Conley", 35, "MIN", 1, "point guard");
    PointGuard goerge_hill("George Hill", 99, "IND", 1, "point guard");
    PointGuard cade_cunningham("Cade Cunningham", 21, "DET", 1, "point guard");
    PointGuard lou_williams("Lou Williams", 99, "LAC", 1, "point guard");
    PointGuard reggie_jackson("Reggie Jackson", 33, "DEN", 1, "point guard");

    vector<PointGuard> point_guards;

    point_guards.push_back(lonzo_ball);
    point_guards.push_back(patrick_beverly);
    point_guards.push_back(mike_conley);
    point_guards.push_back(goerge_hill);
    point_guards.push_back(reggie_jackson);
    point_guards.push_back(cade_cunningham);
    point_guards.push_back(lou_williams);

    return point_guards.at(size_t(random_number_generator(int(point_guards.size()))));
}



ShootingGuard generate_shooting_guard_5(){
    ShootingGuard michael_jordan("Michael Jordan", 99, "CHI", 5, "shooting guard");
    ShootingGuard ray_allen("Ray Allen", 99, "BOS", 5, "shooting guard");
    ShootingGuard kobe_bryant("Kobe Bryant", 99, "LAL", 5, "shooting guard");
    ShootingGuard dwayne_wade("Dwayne Wade", 99, "MIA", 5, "shooting guard");
    ShootingGuard james_harden("James Harden", 33, "PHI", 5, "shooting guard");
    ShootingGuard clyde_drexler("Clyde Drexler", 99, "POR", 5, "shooting guard");
    ShootingGuard tracy_mcgrady("Tracy McGrady", 99, "HOU", 5, "shooting guard");

    vector<ShootingGuard> shooting_guards;
    shooting_guards.push_back(michael_jordan);
    shooting_guards.push_back(ray_allen);
    shooting_guards.push_back(kobe_bryant);
    shooting_guards.push_back(dwayne_wade);
    shooting_guards.push_back(clyde_drexler);
    shooting_guards.push_back(james_harden);
    shooting_guards.push_back(tracy_mcgrady);

    return shooting_guards.at(size_t(random_number_generator(int(shooting_guards.size()))));
}
ShootingGuard generate_shooting_guard_4(){
    ShootingGuard george_gervin("George Gervin", 99, "SAS", 4, "shooting guard");
    ShootingGuard reggie_miller("Reggie Miller", 99, "IND", 4, "shooting guard");
    ShootingGuard vince_carter("Vince Carter", 99, "TOR", 4, "shooting guard");
    ShootingGuard klay_thompson("Klay Thompson", 33, "GSW", 4, "shooting guard");
    ShootingGuard manu_ginobili("Manu Ginobili", 99, "SAS", 4, "shooting guard");
    ShootingGuard earl_monroe("Earl Monroe", 99, "NYK", 4, "shooting guard");
    ShootingGuard devin_booker("Devin Booker", 26, "PHX", 4, "shooting guard");
    

    vector<ShootingGuard> shooting_guards;
    shooting_guards.push_back(george_gervin);
    shooting_guards.push_back(reggie_miller);
    shooting_guards.push_back(vince_carter);
    shooting_guards.push_back(klay_thompson);
    shooting_guards.push_back(manu_ginobili);
    shooting_guards.push_back(earl_monroe);
    shooting_guards.push_back(devin_booker);
    
    return shooting_guards.at(size_t(random_number_generator(int(shooting_guards.size()))));
}

ShootingGuard generate_shooting_guard_3(){
    ShootingGuard kyle_korver("Kyle Korver", 99, "ATL", 3, "shooting guard");
    ShootingGuard bradley_beal("Bradley Beal", 29, "WAS", 3, "shooting guard");
    ShootingGuard zach_lavine("Zach LaVine", 28, "CHI", 3, "shooting guard");
    ShootingGuard jason_terry("Jason Terry", 99, "DAL", 3, "shooting guard");
    ShootingGuard jj_redick("J.J. Reddick", 99, "ORL", 3, "shooting guard");
    ShootingGuard donovan_mitchell("Donovan Mitchell", 26, "CLE", 3, "shooting guard");
    ShootingGuard jaylen_brown("Jaylen Brown", 26, "BOS", 3, "shooting guard");
    ShootingGuard anthony_edwards("Anthony Edwards", 21, "MIN", 3, "shooting guard");

    vector<ShootingGuard> shooting_guards;
    shooting_guards.push_back(kyle_korver);
    shooting_guards.push_back(bradley_beal);
    shooting_guards.push_back(zach_lavine);
    shooting_guards.push_back(jason_terry);
    shooting_guards.push_back(jj_redick);
    shooting_guards.push_back(donovan_mitchell);
    shooting_guards.push_back(jaylen_brown);
    shooting_guards.push_back(anthony_edwards);

    return shooting_guards.at(size_t(random_number_generator(int(shooting_guards.size()))));
}


ShootingGuard generate_shooting_guard_2(){

    ShootingGuard cj_mccollum("C.J. McCollum", 99, "NOP", 2, "shooting guard");
    ShootingGuard buddy_hield("Buddy Hield", 30, "IND", 2, "shooting guard");
    ShootingGuard tyler_herro("Tyler Herro", 23, "MIA", 2, "shooting guard");
    ShootingGuard victor_oladipo("Victor Oladipo", 31, "MIA", 2, "shooting guard");
    ShootingGuard desmond_bane("Desmond Bane", 24, "MEM", 2, "shooting guard");
    ShootingGuard tyrese_maxey("Tyrese Maxey", 22, "PHI", 2, "shooting guard");
    ShootingGuard jalen_green("Jalen Green", 21, "HOU", 2, "shooting guard");

    vector<ShootingGuard> shooting_guards;
    shooting_guards.push_back(cj_mccollum);
    shooting_guards.push_back(buddy_hield);
    shooting_guards.push_back(tyler_herro);
    shooting_guards.push_back(victor_oladipo);
    shooting_guards.push_back(desmond_bane);
    shooting_guards.push_back(tyrese_maxey);
    shooting_guards.push_back(jalen_green);

    return shooting_guards.at(size_t(random_number_generator(int(shooting_guards.size()))));

}
ShootingGuard generate_shooting_guard_1(){
    ShootingGuard seth_curry("Seth Curry", 32, "BKN", 1, "shooting guard");
    ShootingGuard eric_gordon("Eric Gordon", 34, "LAC", 1, "shooting guard");
    ShootingGuard austin_reaves("Austin Reaves", 24, "LAL", 1, "shooting guard");
    ShootingGuard terry_rozier("Terry Rozier", 29, "CHA", 1, "shooting guard");
    ShootingGuard bogdan_bogdanovic("Bogdan Bogdanovic", 30, "ATL", 1, "shooting guard");
    ShootingGuard caris_levert("Caris LeVert", 28, "CLE", 1, "shooting guard");
    ShootingGuard alex_caruso("Alex Caruso", 29, "CHI", 1, "shooting guard");
    ShootingGuard kelly_oubre("Kelly Oubre", 27, "CHA", 1, "shooting guard");


    vector<ShootingGuard> shooting_guards;
    shooting_guards.push_back(seth_curry);
    shooting_guards.push_back(eric_gordon);
    shooting_guards.push_back(austin_reaves);
    shooting_guards.push_back(terry_rozier);
    shooting_guards.push_back(bogdan_bogdanovic);
    shooting_guards.push_back(caris_levert);
    shooting_guards.push_back(alex_caruso);
    shooting_guards.push_back(kelly_oubre);

    return shooting_guards.at(size_t(random_number_generator(int(shooting_guards.size()))));
}

SmallForward generate_small_forward_5(){

    SmallForward lebron_james("Lebron James", 38, "LAL", 5, "small forward");
    SmallForward larry_bird("Larry Bird", 99, "BOS", 5, "small forward");
    SmallForward kevin_durant("Kevin Durant", 34, "PHX", 5, "small forward");
    SmallForward scottie_pippen("Scottie Pippen", 99, "CHI", 5, "small forward");
    SmallForward julius_erving("Julius Erving", 99, "PHI", 5, "small forward");
    SmallForward elgin_baylor("Elgin Baylor", 99, "LAL", 5, "small forward");
    SmallForward kawhi_leonard("Kawhi Leonard", 31, "LAC", 5, "small forward");

    vector<SmallForward> small_forwards;
    small_forwards.push_back(lebron_james);
    small_forwards.push_back(larry_bird);
    small_forwards.push_back(kevin_durant);
    small_forwards.push_back(scottie_pippen);
    small_forwards.push_back(julius_erving);
    small_forwards.push_back(elgin_baylor);
    small_forwards.push_back(kawhi_leonard);

    return small_forwards.at(size_t(random_number_generator(int(small_forwards.size()))));
}
SmallForward generate_small_forward_4(){
    SmallForward paul_pierce("Paul Pierce", 99, "BOS", 4, "small forward");
    SmallForward paul_george("Paul George", 33, "LAC", 4, "small forward");
    SmallForward john_havlicek("John Havlicek", 99, "BOS", 4, "small forward");
    SmallForward dominique_wilkins("Dominique Wilkins", 99, "ATL", 4, "small forward");
    SmallForward carmelo_anthony("Carmelo Anthony", 99, "NYK", 4, "small forward");
    SmallForward james_worthy("James Worthy", 99, "LAL", 4, "small forward");
    SmallForward rick_barry("Rick Barry", 99, "GSW", 4, "small forward");
    SmallForward jayson_tatum("Jayson Tatum", 25, "BOS", 4, "small forward");
    SmallForward jimmy_butler("Jimmy Butler", 33, "MIA", 4, "small forward");
    
    vector<SmallForward> small_forwards;
    small_forwards.push_back(paul_pierce);
    small_forwards.push_back(paul_george);
    small_forwards.push_back(john_havlicek);
    small_forwards.push_back(dominique_wilkins);
    small_forwards.push_back(carmelo_anthony);
    small_forwards.push_back(james_worthy);
    small_forwards.push_back(rick_barry);
    small_forwards.push_back(jayson_tatum);
    small_forwards.push_back(jimmy_butler);

    return small_forwards.at(size_t(random_number_generator(int(small_forwards.size()))));
}
SmallForward generate_small_forward_3(){
    SmallForward brandon_ingram("Brandon Ingram", 25, "NOP", 3, "small forward");
    SmallForward khris_middleton("Khris Middleton", 31, "MIL", 3, "small forward");
    SmallForward richard_jefferson("Richard Jefferson", 99, "BKN", 3, "small forward");
    SmallForward andre_iguodala("Andre Iguodala", 39, "GSW", 3, "small forward");
    SmallForward gerald_wallace("Gerald Wallace", 99, "CHA", 3, "small forward");
    SmallForward shane_battier("Shane Battier", 99, "MEM", 3, "small forward");

    vector<SmallForward> small_forwards;
    small_forwards.push_back(khris_middleton);
    small_forwards.push_back(brandon_ingram);
    small_forwards.push_back(richard_jefferson);
    small_forwards.push_back(andre_iguodala);
    small_forwards.push_back(gerald_wallace);
    small_forwards.push_back(shane_battier);

    return small_forwards.at(size_t(random_number_generator(int(small_forwards.size()))));
}
SmallForward generate_small_forward_2(){
    SmallForward andrew_wiggins("Andrew Wiggins", 28, "GSW", 2, "small forward");
    SmallForward mikal_bridges("Mikal Bridges", 26, "BKN", 2, "small forward");
    SmallForward michael_porter_jr("Micheal Porter Jr", 24, "DEN", 2, "small forward");
    SmallForward rj_barrett("R.J. Barrett", 22, "NYK", 2, "small forward");
    SmallForward franz_wagner("Franz Wagner", 21, "ORL", 2, "small forward");
    SmallForward og_anunoby("O.G. Anunoby", 25, "TOR", 2, "small forward");
    SmallForward keldon_johnson("Keldon Johnson", 23, "SAS", 2, "small forward");

    vector<SmallForward> small_forwards;
    small_forwards.push_back(andrew_wiggins);
    small_forwards.push_back(mikal_bridges);
    small_forwards.push_back(michael_porter_jr);
    small_forwards.push_back(rj_barrett);
    small_forwards.push_back(franz_wagner);
    small_forwards.push_back(og_anunoby);
    small_forwards.push_back(keldon_johnson);

    return small_forwards.at(size_t(random_number_generator(int(small_forwards.size()))));
}
SmallForward generate_small_forward_1(){
    
    SmallForward harrison_barnes("Harrison Barnes", 30, "SAC", 1, "small forward");
    SmallForward gordon_hayward("Gordon Hayward", 33, "CHA", 1, "small forward");
    SmallForward kyle_kuzma("Kyle Kuzma", 27, "WAS", 1, "small forward");
    SmallForward dillon_brooks("Dillon Brooks", 27, "MEM", 1, "small forward");
    SmallForward matisse_thybulle("Matisse Thybulle", 26, "POR", 1, "small forward");
    SmallForward saddiq_bey("Saddiq Bey", 24, "ATL", 1, "small forward");
    SmallForward keegan_murray("Keegan Murray", 22, "SAC", 1, "small forward");

    vector<SmallForward> small_forwards;
    small_forwards.push_back(harrison_barnes);
    small_forwards.push_back(gordon_hayward);
    small_forwards.push_back(kyle_kuzma);
    small_forwards.push_back(dillon_brooks);
    small_forwards.push_back(matisse_thybulle);
    small_forwards.push_back(saddiq_bey);
    small_forwards.push_back(keegan_murray);

    return small_forwards.at(size_t(random_number_generator(int(small_forwards.size()))));
}

PowerForward generate_power_forward_5(){
    PowerForward tim_duncan("Tim Duncan", 99, "SAS", 5, "power forward");
    PowerForward karl_malone("Karl Malone", 99, "UTA", 5, "power forward");
    PowerForward kevin_garnett("Kevin Garnett", 99, "MIN", 5, "power forward");
    PowerForward charles_barkley("Charles Barkley", 99, "PHX", 5, "power forward");
    PowerForward dirk_nowitzki("Dirk Nowitzki", 99, "DAL", 5, "power forward");
    PowerForward elvin_hayes("Elvin Hayes", 99, "WAS", 5, "power forward");
    PowerForward giannis_antetokounmpo("Giannis Antetokounmpo", 28, "MIL", 5, "power forward");

    vector<PowerForward> power_forwards;
    power_forwards.push_back(tim_duncan);
    power_forwards.push_back(karl_malone);
    power_forwards.push_back(kevin_garnett);
    power_forwards.push_back(charles_barkley);
    power_forwards.push_back(dirk_nowitzki);
    power_forwards.push_back(elvin_hayes);
    power_forwards.push_back(giannis_antetokounmpo);

    return power_forwards.at(size_t(random_number_generator(int(power_forwards.size()))));
}

PowerForward generate_power_forward_4(){
    PowerForward dennis_rodman("Dennis Rodman", 99, "CHI", 4, "power forward");
    PowerForward bob_petit("Bob Petit", 99, "ATL", 4, "power forward");
    PowerForward chris_bosh("Chris Bosh", 99, "MIA", 4, "power forward");
    PowerForward lamarcus_aldridge("LaMarcus Aldridge", 99, "POR", 4, "power forward");
    PowerForward elton_brand("Elton Brand", 99, "LAC", 4, "power forward");
    PowerForward chris_webber("Chris Webber", 99, "SAC", 4, "power forward");
    PowerForward horace_grant("Horace Grant", 99, "CHI", 4, "power forward");
    
    vector<PowerForward> power_forwards;
    power_forwards.push_back(dennis_rodman);
    power_forwards.push_back(bob_petit);
    power_forwards.push_back(chris_bosh);
    power_forwards.push_back(lamarcus_aldridge);
    power_forwards.push_back(elton_brand);
    power_forwards.push_back(chris_webber);
    power_forwards.push_back(horace_grant);

    return power_forwards.at(size_t(random_number_generator(int(power_forwards.size()))));
}

PowerForward generate_power_forward_3(){
    PowerForward zach_randolph("Zach Randolph", 99, "MEM", 3, "power forward");
    PowerForward draymond_green("Draymond Green", 33, "GSW", 3, "power forward");
    PowerForward kevin_love("Kevin Love", 34, "MIA", 3, "power forward");
    PowerForward amare_stoudemire("Amar'e Stoudemire", 99, "NYK", 3, "power forward");
    PowerForward blake_griffin("Blake Griffin", 34, "LAC", 3, "power forward");
    PowerForward shawn_kemp("Shawn Kemp", 99, "OKC", 3, "power forward");
    PowerForward zion_williamson("Zion Williamson", 22, "NOP", 3, "power forward");
    PowerForward pascal_siakam("Pascal Siakam", 29, "TOR", 3, "power forward");
    PowerForward lauri_markkanen("Lauri Markkanen", 25, "UTA", 3, "power forward");
    PowerForward jaren_jackson_jr("Jaren Jackson Jr", 23, "MEM", 3, "power forward");
    PowerForward victor_wembanyama("Victor Wembanyama", 21, "SAS", 3, "power forward");

    vector<PowerForward> power_forwards;
    power_forwards.push_back(zach_randolph);
    power_forwards.push_back(draymond_green);
    power_forwards.push_back(kevin_love);
    power_forwards.push_back(amare_stoudemire);
    power_forwards.push_back(blake_griffin);
    power_forwards.push_back(shawn_kemp);
    power_forwards.push_back(zion_williamson);
    power_forwards.push_back(pascal_siakam);
    power_forwards.push_back(lauri_markkanen);
    power_forwards.push_back(jaren_jackson_jr);
    power_forwards.push_back(victor_wembanyama);

    return power_forwards.at(size_t(random_number_generator(int(power_forwards.size()))));
}

PowerForward generate_power_forward_2(){
    PowerForward carlos_boozer("Carlos Boozer", 99, "UTA", 2, "power forward");
    PowerForward serge_ibaka("Serge Ibaka", 99, "OKC", 2, "power forward");
    PowerForward paolo_banchero("Paolo Banchero", 20, "ORL", 2, "power forward");
    PowerForward julius_randle("Julius Randle", 28, "NYK", 2, "power forward");
    PowerForward aaron_gordon("Aaron Gordon", 27, "DEN", 2, "power forward");
    PowerForward jerami_grant("Jerami Grant", 27, "POR", 2, "power forward");
    PowerForward bojan_bogdanovic("Bojan Bogdanovic", 34, "DET", 2, "power forward");
    PowerForward kristaps_porzingis("Kristaps Porzingis", 27, "WAS", 2, "power forward");

    vector<PowerForward> power_forwards;
    power_forwards.push_back(carlos_boozer);
    power_forwards.push_back(serge_ibaka);
    power_forwards.push_back(paolo_banchero);
    power_forwards.push_back(julius_randle);
    power_forwards.push_back(aaron_gordon);
    power_forwards.push_back(jerami_grant);
    power_forwards.push_back(bojan_bogdanovic);
    power_forwards.push_back(kristaps_porzingis);

    return power_forwards.at(size_t(random_number_generator(int(power_forwards.size()))));
}

PowerForward generate_power_forward_1(){
    PowerForward john_collins("John Collins", 25, "ATL", 1, "power forward");
    PowerForward jarred_vanderbilt("Jarred Vanderbilt", 24, "LAL", 1, "power forward");
    PowerForward kelly_olynyk("Kelly Olynyk", 32, "UTA", 1, "power forward");
    PowerForward cameron_johnson("Cameron Johnson", 27, "BKN", 1, "power forward");
    PowerForward tobias_harris("Tobias Harris", 30, "PHI", 1, "power forward");
    PowerForward jabari_smith_jr("Jabari Smith Jr", 20, "HOU", 1, "power forward");
    PowerForward marvin_bagley("Marvin Bagley III", 24, "DET", 1, "power forward");

    vector<PowerForward> power_forwards;
    power_forwards.push_back(john_collins);
    power_forwards.push_back(jarred_vanderbilt);
    power_forwards.push_back(kelly_olynyk);
    power_forwards.push_back(cameron_johnson);
    power_forwards.push_back(tobias_harris);
    power_forwards.push_back(jabari_smith_jr);
    power_forwards.push_back(marvin_bagley);

    return power_forwards.at(size_t(random_number_generator(int(power_forwards.size()))));
}


Center generate_center_5(){
    Center shaq("Shaquille O'neal", 99, "LAL", 5, "center");
    Center bill_russell("Bill Russell", 99, "BOS", 5, "center");
    Center kareem_abdul_jabbar("Kareem Abdul-Jabbar", 99, "LAL", 5, "center");
    Center wilt_chamberlain("Wilt Chamblerlain", 99, "PHI", 5, "center");
    Center hakeem_olajuwon("Hakeem Olajuwon", 99, "HOU", 5, "center");
    Center moses_malone("Moses Malone", 99, "HOU", 5, "center");
    Center david_robinson("David Robinson", 99, "SAS", 5, "center");
    Center yao_ming("Yao Ming", 99, "HOU", 5, "center");
    Center nikola_jokic("Nikola Jokic", 28, "DEN", 4, "center");


    vector<Center> centers;
    centers.push_back(shaq);
    centers.push_back(bill_russell);
    centers.push_back(kareem_abdul_jabbar);
    centers.push_back(wilt_chamberlain);
    centers.push_back(hakeem_olajuwon);
    centers.push_back(moses_malone);
    centers.push_back(david_robinson);
    centers.push_back(yao_ming);
    centers.push_back(nikola_jokic);

    return centers.at(size_t(random_number_generator(int(centers.size()))));
}

Center generate_center_4(){
    Center patrick_ewing("Patrick Ewing", 99, "NYK", 4, "center");
    Center george_mikan("George Mikan", 99, "LAL", 4, "center");
    Center joel_embiid("Joel Embiid", 29, "PHI", 4, "center");
    Center wes_unseld("Wes Unseld", 99, "WAS", 4, "center");
    Center alonzo_mourning("Alonzo Mourning", 99, "MIA", 4, "center");
    Center dikembe_mutumbo("Dikembe Mutumbo", 99, "ATL", 4, "center");
    Center anthony_davis("Anthony Davis", 30, "LAL", 4, "center");
    Center pau_gasol("Pau Gasol", 99, "LAL", 3, "center");

    vector<Center> centers;
    centers.push_back(patrick_ewing);
    centers.push_back(george_mikan);
    centers.push_back(joel_embiid);
    centers.push_back(wes_unseld);
    centers.push_back(alonzo_mourning);
    centers.push_back(dikembe_mutumbo);
    centers.push_back(anthony_davis);
    centers.push_back(pau_gasol);

    return centers.at(size_t(random_number_generator(int(centers.size()))));
}
Center generate_center_3(){
    Center dwight_howard("Dwight Howard", 37, "ORL", 3, "center");
    Center manute_bol("Manute Bol", 99, "WAS", 3, "center");
    Center rudy_gobert("Rudy Gobert", 30, "MIN", 3, "center");
    Center joakim_noah("Joakim Noah", 99, "CHI", 3, "center");
    Center karl_anthony_towns("Karl Anthony Towns", 27, "MIN", 3, "center");
    Center bam_adebayo("Bam Adebayo", 25, "MIA", 3, "center");
    Center steven_adams("Steven Adams", 29, "MEM", 3, "center");
    
    vector<Center> centers;
    centers.push_back(dwight_howard);
    centers.push_back(manute_bol);
    centers.push_back(rudy_gobert);
    
    centers.push_back(joakim_noah);
    centers.push_back(karl_anthony_towns);
    centers.push_back(bam_adebayo);
    centers.push_back(steven_adams);

    return centers.at(size_t(random_number_generator(int(centers.size()))));
}

Center generate_center_2(){
    Center deandre_jordan("DeAndre Jordan", 34, "DEN", 2, "center");
    Center brook_lopez("Brook Lopez", 35, "MIL", 2, "center");
    Center deandre_ayton("Deandre Ayton", 24, "PHX", 2, "center");
    Center jarrett_allen("Jarrett Allen", 25, "CLE", 2, "center");
    Center myles_turner("Myles Turner", 27, "IND", 2, "center");
    Center nikola_vucevic("Nikola Vucevic", 32, "CHI", 2, "center");
    Center al_horford("Al Horford", 36, "BOS", 2, "center");
    Center jonas_valanciunas("Jonas Valanciunas", 31, "BOS", 2, "center");

    vector<Center> centers;
    centers.push_back(deandre_jordan);
    centers.push_back(brook_lopez);
    centers.push_back(deandre_ayton);
    centers.push_back(jarrett_allen);
    centers.push_back(myles_turner);
    centers.push_back(nikola_vucevic);
    centers.push_back(al_horford);
    centers.push_back(jonas_valanciunas);

    return centers.at(size_t(random_number_generator(int(centers.size()))));
}

Center generate_center_1(){
    Center walker_kessler("Walker Kessler", 21, "UTA", 1, "center");
    Center wendell_carter_jr("Wendell Carter Jr", 24, "ORL", 1, "center");
    Center isaiah_stewart("Isaiah Stewart", 21, "DET", 1, "center");
    Center jakob_poeltl("Jakob Poeltl", 27, "TOR", 1, "center");
    Center alperen_sengun("Alperen Sengun", 20, "HOU", 1, "center");
    Center ivica_zubac("Ivica Zubac", 26, "LAC", 1, "center");
    Center bol_bol("Bol Bol", 23, "ORL", 1, "center");
    Center kevon_looney("Kevon Looney", 27, "GSW", 1, "center");

    vector<Center> centers;
    centers.push_back(walker_kessler);
    centers.push_back(wendell_carter_jr);
    centers.push_back(isaiah_stewart);
    centers.push_back(jakob_poeltl);
    centers.push_back(alperen_sengun);
    centers.push_back(ivica_zubac);
    centers.push_back(bol_bol);
    centers.push_back(kevon_looney);

    return centers.at(size_t(random_number_generator(int(centers.size()))));
}


int main(){
    char yesorno;
    //keeps track of the user choice
    int choice = 0;
    bool valid_choice = false;
    //keeps track of the user credits and variabesl to keep track of user's record against the computer
    int credits = 16;
    int userWins = 0;
    int computerWins = 0;
    //keeps track of the user's team
    Team userTeam;
    //initialize the user's team
    PointGuard pg_decision;
    ShootingGuard sg_decision;
    SmallForward sf_decision;
    PowerForward pf_decision;
    Center c_decision;

    userTeam.set_point_guard(pg_decision);
    userTeam.set_shooting_guard(sg_decision);
    userTeam.set_small_forward(sf_decision);
    userTeam.set_power_forward(pf_decision);
    userTeam.set_center(c_decision);
    //////////////////////////////////////////////////
    cout << "Welcome to Raki's NBA team creator game!" << endl;
    cout << "Would you like to read the instructions? (if yes then type 'y', if not then type any other letter)" << endl;
    cin >> yesorno;
    if (toupper(yesorno) == 'Y' ){
        print_instructions();
    } 

    cout << "please type any letter when you are ready to start. ";
    string random_letter = "a";
    cin >> random_letter;
    cout << endl;

    print_status(userTeam, credits);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout << "First, for your point guard, please choose one of the players below:" << endl;

    //keeps track of the player the user is on
    vector<PointGuard> pg_list;

    PointGuard level_5_pg = generate_point_guard_5();
    PointGuard level_4_pg = generate_point_guard_4();
    PointGuard level_3_pg = generate_point_guard_3();
    PointGuard level_2_pg = generate_point_guard_2();
    PointGuard level_1_pg = generate_point_guard_1();
    pg_list.push_back(level_1_pg);
    pg_list.push_back(level_2_pg);
    pg_list.push_back(level_3_pg);
    pg_list.push_back(level_4_pg);
    pg_list.push_back(level_5_pg);

    while(!valid_choice){
        cout << "(" << level_5_pg.get_value() << ") " << level_5_pg.get_name() << endl;
        cout << "(" << level_4_pg.get_value() << ") " << level_4_pg.get_name() << endl;
        cout << "(" << level_3_pg.get_value() << ") " << level_3_pg.get_name() << endl;
        cout << "(" << level_2_pg.get_value() << ") " << level_2_pg.get_name() << endl;
        cout << "(" << level_1_pg.get_value() << ") " << level_1_pg.get_name() << endl;
        cout << endl;
        cin >> choice; 
        if (is_valid_choice(choice)){
            valid_choice = true;
        }
    }


        pg_decision = pg_list.at(choice - 1);
        cout << "You chose: " << pg_decision.get_name() << "!" << endl;
        credits -= pg_decision.get_value();
        userTeam.set_point_guard(pg_decision);


    print_status(userTeam, credits);
    reset_choice_variables(choice, valid_choice);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Now onto shooting guards! Please choose one of the players below:" << endl;

    vector<ShootingGuard> sg_list;
    ShootingGuard leve1_5_sg = generate_shooting_guard_5();
    ShootingGuard leve1_4_sg = generate_shooting_guard_4();
    ShootingGuard leve1_3_sg = generate_shooting_guard_3();
    ShootingGuard leve1_2_sg = generate_shooting_guard_2();
    ShootingGuard leve1_1_sg = generate_shooting_guard_1();
    sg_list.push_back(leve1_1_sg);
    sg_list.push_back(leve1_2_sg);
    sg_list.push_back(leve1_3_sg);
    sg_list.push_back(leve1_4_sg);
    sg_list.push_back(leve1_5_sg);

    while(!valid_choice){

        cout << "(" << leve1_5_sg.get_value() << ") " << leve1_5_sg.get_name() << endl;
        cout << "(" << leve1_4_sg.get_value() << ") " << leve1_4_sg.get_name() << endl;
        cout << "(" << leve1_3_sg.get_value() << ") " << leve1_3_sg.get_name() << endl;
        cout << "(" << leve1_2_sg.get_value() << ") " << leve1_2_sg.get_name() << endl;
        cout << "(" << leve1_1_sg.get_value() << ") " << leve1_1_sg.get_name() << endl;
        cout << endl;
        cin >> choice;
        if(is_valid_choice(choice)){
            valid_choice = true;
        }
    }
    sg_decision = (sg_list.at(size_t(choice - 1)));
    cout << "You chose:  " << sg_decision.get_name() << "!" << endl;
    credits -= sg_decision.get_value();
    userTeam.set_shooting_guard(sg_decision);

    print_status(userTeam, credits);
    reset_choice_variables(choice, valid_choice);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Next up, you must choose a small forward! Please choose one of the players below: " << endl;

    vector<SmallForward> sf_list;
    SmallForward level_5_sf = generate_small_forward_5();
    SmallForward level_4_sf = generate_small_forward_4();
    SmallForward level_3_sf = generate_small_forward_3();
    SmallForward level_2_sf = generate_small_forward_2();
    SmallForward level_1_sf = generate_small_forward_1();
    sf_list.push_back(level_1_sf);
    sf_list.push_back(level_2_sf);
    sf_list.push_back(level_3_sf);
    sf_list.push_back(level_4_sf);
    sf_list.push_back(level_5_sf);

   bool sf_chosen = false;
   while(!valid_choice || !sf_chosen){

        cout << "(" << sf_list.at(4).get_value() << ") " << sf_list.at(4).get_name() << endl;
        cout << "(" << sf_list.at(3).get_value() << ") " << sf_list.at(3).get_name() << endl;
        cout << "(" << sf_list.at(2).get_value() << ") " << sf_list.at(2).get_name() << endl;
        cout << "(" << sf_list.at(1).get_value() << ") " << sf_list.at(1).get_name() << endl;
        cout << "(" << sf_list.at(0).get_value() << ") " << sf_list.at(0).get_name() << endl;
        cout << endl;
   
        cin >> choice; 
        ///below we check if the choice is valid
        if (is_valid_choice(choice)){
            valid_choice = true;
        }
        else{
            valid_choice = false;
        }
        //if they choose the 5 level player 3 times in a row, they will only have 1 credit left
        if(valid_choice){
            if(credits - choice < 2){
                cout << "You do not have enough credits to select " << sf_list.at(size_t(choice - 1)).get_name();
                cout << ". Please choose someone else: " << endl;
                valid_choice = false;
                sf_chosen = false;
            }
            else{
                sf_chosen = true;
            }
        }
   }
    sf_decision = (sf_list.at(size_t(choice - 1)));
    cout << "You chose: " << sf_decision.get_name() << "!" << endl;
    credits -= sf_decision.get_value();
    userTeam.set_small_forward(sf_decision);

    print_status(userTeam, credits);
    reset_choice_variables(choice, valid_choice);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout << "Good decision! Now please choose one of the Power Forwards below: " << endl;
    vector<PowerForward> pf_list;
    PowerForward level_5_pf = generate_power_forward_5();
    PowerForward level_4_pf = generate_power_forward_4();
    PowerForward level_3_pf = generate_power_forward_3();
    PowerForward level_2_pf = generate_power_forward_2();
    PowerForward level_1_pf = generate_power_forward_1();
    pf_list.push_back(level_1_pf);
    pf_list.push_back(level_2_pf);
    pf_list.push_back(level_3_pf);
    pf_list.push_back(level_4_pf);
    pf_list.push_back(level_5_pf);

   bool pf_chosen = false;
   while(!valid_choice || !pf_chosen){

        cout << "(" << level_5_pf.get_value() << ") " << level_5_pf.get_name() << endl;
        cout << "(" << level_4_pf.get_value() << ") " << level_4_pf.get_name() << endl;
        cout << "(" << level_3_pf.get_value() << ") " << level_3_pf.get_name() << endl;
        cout << "(" << level_2_pf.get_value() << ") " << level_2_pf.get_name() << endl;
        cout << "(" << level_1_pf.get_value() << ") " << level_1_pf.get_name() << endl;
        cout << endl;
        cin >> choice;
        if(is_valid_choice(choice)){
            valid_choice = true;
            if(credits - choice > 0){
                pf_chosen = true;
            }
            else{
                cout << "You do not have enough credits to select " << pf_list.at(size_t(choice - 1)).get_name();
                cout << ". Please choose someone else: " << endl;
                pf_chosen = false;
                valid_choice = false;
            }
        }
   }
        pf_decision = pf_list.at(size_t(choice - 1));
        cout << "You chose: " << pf_decision.get_name() << "!" << endl;
        credits -= pf_decision.get_value();
        choice = 0;
        userTeam.set_power_forward(pf_decision);

    print_status(userTeam, credits);
    reset_choice_variables(choice, valid_choice);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout << "The last player on your team is your center. Please choose one of the players below: " << endl;

    vector<Center> c_list;
    Center level_5_c = generate_center_5();
    Center level_4_c = generate_center_4();
    Center level_3_c = generate_center_3();
    Center level_2_c = generate_center_2();
    Center level_1_c = generate_center_1();
    c_list.push_back(level_1_c);
    c_list.push_back(level_2_c);
    c_list.push_back(level_3_c);
    c_list.push_back(level_4_c);
    c_list.push_back(level_5_c);

    bool center_chosen = false;
    while(!valid_choice || !center_chosen){

        cout << "(" << level_5_c.get_value() << ") " << level_5_c.get_name() << endl;
        cout << "(" << level_4_c.get_value() << ") " << level_4_c.get_name() << endl;
        cout << "(" << level_3_c.get_value() << ") " << level_3_c.get_name() << endl;
        cout << "(" << level_2_c.get_value() << ") " << level_2_c.get_name() << endl;
        cout << "(" << level_1_c.get_value() << ") " << level_1_c.get_name() << endl;
        cout << endl;

        cin >> choice;
        if(is_valid_choice(choice)){
            valid_choice = true;
            if(credits - choice >= 0){
                center_chosen = true;
            }
            else{
                cout << "You do not have enough credits to select " << c_list.at(size_t(choice - 1)).get_name();
                cout << ". Please choose someone else: " << endl;
                center_chosen = false;
                valid_choice = false;
            }
        }
    }
    c_decision = c_list.at(size_t(choice - 1));
    cout << "You chose: " << c_decision.get_name() << "!" << endl;
    credits -= c_decision.get_value();
    userTeam.set_center(c_decision);

    print_status(userTeam, credits);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    pg_list.erase(pg_list.begin() + (pg_decision.get_value() - 1));
    sg_list.erase(sg_list.begin() + (sg_decision.get_value() - 1));
    sf_list.erase(sf_list.begin() + (sf_decision.get_value() - 1));
    pf_list.erase(pf_list.begin() + (pf_decision.get_value() - 1));
    c_list.erase(c_list.begin() + (c_decision.get_value() - 1));
    //After erasing the players that the user chose, the computer can generate its own team from the remaining players
    
    Team computerTeam = create_computer_team(pg_list, sg_list, sf_list, pf_list, c_list);

    cout << "The computer has generated it's team! Please hit any letter key when you're ready." << endl;
    cin >> random_letter;
    cout << endl;

    print_status(computerTeam, 16 - computerTeam.get_value());

    cout << "Above is the computer's team, generated from the players you did not pick." << endl;
    cout << "Please hit any letter key when you're ready to see who wins:   ";
    cin >> random_letter;
    cout << endl;
    Game game(userTeam, computerTeam);
    bool userWon = false; //this bool keeps track of whether the user has won the current game
    userWon = game.play();
    tally_score(userWins, computerWins, userWon);
    cout << "Your current record against the computer is " << userWins << " - " << computerWins << endl;

    cout << "Would you like a rematch? (type 'y' if yes, otherwise type any other letter)" << endl;
    cin >> yesorno;

    while(toupper(yesorno) == 'Y'){
        cout << endl;
        userWon = game.play();
        tally_score(userWins, computerWins, userWon);
        cout << "Your current record against the computer is " << userWins << " - " << computerWins << endl;
        cout << endl << "Good game on the rematch! ";
        cout << "Would you like a rematch again? (type 'y' if yes, otherwise type any other letter)" << endl;
        cin >> yesorno;
    }
    cout << endl << "This is now the end of Raki's basketball game. Thanks for playing!";
}