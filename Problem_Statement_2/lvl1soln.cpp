#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class bender {
public:
    string name;
    string element;
    int hp;
    int attack;
    int defense;
    int speed;
    int hptotal;

     struct moves {
        string name;
        int power;
    };
    moves array[4];

    bender(string name,string element,int hp,int attack,int defense,int speed,moves arr[]){
        this->name=name;
        this->element=element;
        this->hp=hp;
        this->attack=attack;
        this->defense=defense;
        this->speed=speed;
        for(int i=0;i<4;i++){
            array[i]=arr[i];
        }
        hptotal=hp;

    }

    void display_stats() {
        cout << name << " (" <<element<<") " << "- ";
        cout << "HP:" << hp <<"/"<< hptotal <<" ";
        cout << "attack:" << attack <<" ";
        cout << "defense:" << defense <<" ";
        cout << "speed:" << speed <<" ";
        cout << endl;
        cout << "Moves:";
        for (int i = 0; i < 4; i++) {
            cout << array[i].name << " (" << array[i].power<< ") " << ", ";
        }
        cout << endl;
    }

    void attacks(bender &defender,int move_index){
       int attacker_attack=0;
       int defender_defense=0;
       int move_power=0;
       attacker_attack=this->attack;
       move_power=this->array[move_index].power;
       defender_defense=defender.defense;

       cout << this->name << " attacks " << defender.name << " with " << array[move_index].name <<"!" << endl;

    int damage=round((attacker_attack * move_power) / defender_defense);
    cout << defender.name << " took " << damage << " damage! " << endl;

    defender.hp=defender.hp-damage;
    if(defender.hp < 0){
        defender.hp = 0;
    }
}

void is_fainted(){
    if(this->hp>=0){
        cout << this->name << " fainted : false " << endl;
    }
    else{
        cout << this->name << " fainted : true " << endl;
    }
}
};

int main() {
    bender::moves Magmar_moves[4]={{"Ember Slash",(40)}, {"Quick Jab",(30)}, {"Focus",(0)}, {"Flame Surge",(70)}};
    bender Magmar("Magmar","fire", 70, 50, 40, 90, Magmar_moves);

    Magmar.display_stats();
    cout << endl;

    bender::moves Celebi_moves[4]={{"Water Whip",(35)}, {"Tide Push",(25)}, {"Mist Veil",(0)}, {"Tidal Wave",(60)}};
    bender Celebi("Celebi", "water", 92, 50, 45, 60, Celebi_moves);

    Celebi.display_stats();
    cout << endl;

    Magmar.attacks(Celebi,3);
    cout << endl;

    Celebi.display_stats();
    Celebi.is_fainted();

    return 0;
}