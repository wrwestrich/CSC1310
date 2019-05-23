/*
 * Name: Creature.cpp
 * Date: 2/15/18
 * Author: Will Westrich
 * Purpose:
*/

#include "Creature.h"

Creature::Creature(){}

Creature::Creature(std::string n, std::string d, bool danger, float c)
    : name(n), description(d), dangerous(danger), cost(c){
}

std::string Creature::GetName() const{
    return name;
}

std::string Creature::GetDescription() const{
    return description;
}

float Creature::GetCost() const{
    return cost;
}

bool Creature::GetDanger() const{
    return dangerous;
}

void Creature::SetName(std::string n){
    name = n;
}

void Creature::SetDescription(std::string d){
    description = d;
}

void Creature::SetCost(float c){
    cost = c;
}

void Creature::SetDanger(bool dang){
    dangerous = dang;
}

void Creature::Print(){
    std::string danger;
    if(dangerous == 0)
        danger = "No";
    else
        danger = "Yes";
    
    std::cout << "Name:  " << name << std::endl;
    std::cout << "Description:" << std::endl << std::endl <<  description << std::endl << std::endl;
    std::cout << "Dangerous?  " << danger << std::endl;
    std::cout << "Cost per month:  $" << cost << std::endl;
}

void Creature::PrintToFile(std::string fileName){
    std::ofstream oF;

    oF.open(fileName, std::fstream::app);
    oF << name << std::endl << description << std::endl << dangerous << std::endl << cost << std::endl;
    oF.close();
}
