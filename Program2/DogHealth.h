/*
 * Title: DogHealth.h
 * Date: 2/1/2018
 * Author: Will Westrich
 * Purpose: Define DogHealth class.
*/
#ifndef DOG_H
#define DOG_H
#include <string>
#include <limits>
#include <iostream>

static const std::size_t MONTHS = 12;

class DogHealth
{
private:
  std::string name;
  int age, heartRate[MONTHS];
  double weight[MONTHS];

public:
  DogHealth();
  void printDogHealth();
  void printWeightStatistics();
  void printHeartRateStatistics();
};
#endif
