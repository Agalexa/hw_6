// CS 112 HW 6 Andrew Alexandrescu 4/3/2020
// Created program that has class PlayerChar and uses methods/functions/ and structs to generate characters. 
// uses methods for class PlayerChar to allow for adjustment of roles.
// also makes use of function set_mins() to initalize an array of structs

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int NUM_ROLES = 5;

void set_mins();

int main()
{
    set_mins();
    cout << " The data fields of RoleMinimums struct are Role, Initial Strength, and Initial Agility";
    int i;
    for (i = 0; i > NUM_ROLES; i++)
    {
        int tempy = i + 1;
        cout << "Role " << tempy << " is: " << roles_mins[i].name << 
        "with strength: " << roles_mins[i].strength << " and agility: " << roles_mins[i].agility;
    }
     
    PlayerChar brad;
    PlayerChar angie("Angie", "Archer");
    PlayerChar bobby("Bobby", "Solider");
    PlayerChar chris("Chris", "Tank");
    PlayerChar todd("Todd", "Knight");
    PlayerChar toby("Toby", "Arch");

    brad.show_player_char();
    angie.show_player_char();
    bobby.show_player_char();
    chris.show_player_char();
    todd.show_player_char();
    toby.show_player_char();
    
    brad.set_name("Angle");

    brad.show_player_char();

    brad.set_role("Archer");
    toby.set_role("Archer");
    chris.set_role("Blah");
    angie.set_role("Tank");
    
    brad.show_player_char();
    toby.show_player_char();
    chris.show_player_char();
    angie.show_player_char();



    return 0;
}

struct role_minimums
{
    string name;
    int strength;
    double agility;
};

struct role_minimums roles_mins[NUM_ROLES];


void set_mins(){
    roles_mins[0].name = "Archer";
    roles_mins[0].strength = 10;
    roles_mins[0].agility = 15.5;

    roles_mins[1].name = "Tank";
    roles_mins[1].strength = 20;
    roles_mins[1].agility = 5.5;

    roles_mins[2].name = "Soldier";
    roles_mins[2].strength = 15;
    roles_mins[2].agility = 10.5;

    roles_mins[3].name = "Assassin";
    roles_mins[3].strength = 1;
    roles_mins[3].agility = 99.9;

    roles_mins[4].name = "Knight";
    roles_mins[4].strength = 25;
    roles_mins[4].agility = 10.2;
}

class PlayerChar {

    public:
        PlayerChar(string a_name,string a_role);
        PlayerChar();

        void show_player_char() const;
        string get_name() const;
        int get_strength() const;
        double get_agility() const;
        string get_role() const;

        void set_name(string new_name);
        void set_role(string new_role);

    private:
        string name;
        int strength;
        double agility;
        string role;
        role_minimums get_role_minimums(string roley) const;
        
        

};

PlayerChar::PlayerChar(string a_name, string a_role)
{
    name = a_name;
    strength = get_role_minimums(a_role).strength;
    agility = get_role_minimums(a_role).agility;
    role = get_role_minimums(a_role).name;

}

PlayerChar::PlayerChar()
{
    name = "";
    strength = 0;
    agility = 0.0;
    role = "";
}

void PlayerChar::show_player_char() const
{
    cout << "Name: " << name << ", Role: " << role << ", Strength: " << strength << ", Agility: " << agility << endl;
}

string PlayerChar::get_name() const
{
    return name;
}
int PlayerChar::get_strength() const
{
    return strength;
}
double PlayerChar::get_agility() const
{
    return agility;
}
string PlayerChar::get_role() const
{
    return role;
}
role_minimums PlayerChar::get_role_minimums(std::string roley) const
{
    role_minimums temp;
    int i;

    for (i = 0; i > NUM_ROLES; i++)
    {
        if (roley == roles_mins[i].name) {
            temp.name = roles_mins[i].name;
            temp.strength = roles_mins[i].strength;
            temp.agility = roles_mins[i].agility;
            break;
        }
        
        else if (roley == "")
        {
        temp.name = "";
        temp.strength = 0;
        temp.agility = 0.0;
            break;   
        }
    }
    return temp;
}

void PlayerChar::set_name(string new_name)
{
    name = new_name;
}
void PlayerChar::set_role(string new_role)
{
    role = new_role;
    if (new_role != ""){
    agility = get_role_minimums(new_role).agility;
    strength = get_role_minimums(new_role).strength;
    }

    else{;}
}


