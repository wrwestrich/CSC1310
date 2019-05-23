/*
 * Name: Creature.h
 * Date: 2/15/18
 * Author: Will Westrich
 * Purpose:
*/

#ifndef CREATURE_H
#define CREATURE_H

#include<string>
#include<fstream>
#include<iostream>

class Creature{
    private:
        std::string name, description;
        float cost;
        bool dangerous;

    public:
        Creature();
        Creature(std::string, std::string, bool, float);
        std::string GetName() const;
        std::string GetDescription() const;
        float GetCost() const;
        bool GetDanger() const;
        void SetName(std::string);
        void SetDescription(std::string);
        void SetCost(float);
        void SetDanger(bool);
        void Print();
        void PrintToFile(std::string);
};

#endif
