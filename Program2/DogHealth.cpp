/*
 * Title: DogHealth.cpp
 * Date: 2/1/2018
 * Author: Will Westrich
 * Purpose: Define class functions for DogHealth.
*/

#include "DogHealth.h"
#include "ArrayHelper.h"

using namespace std;

DogHealth::DogHealth(){

    cout << endl << "Please enter your dog's name: ";
    getline(cin, name);

    cout << endl << endl << "Please enter " << name << "'s age: ";
    do{
        while(!(std::cin >> age)){
            cout << endl << "Please enter a valid age: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if(age < 0)
            cout << endl << "Please enter a positive age: ";
    } while(age < 0);

    for(size_t i = 0; i < MONTHS; ++i){
        cout << endl << endl << "Please enter " << name << "'s weight for month " << i+1 << ": ";
        do{
            while(!(cin >> weight[i])){
                cout << endl << "Please enter a valid weight: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if(weight[i] < 1)
                cout << endl << "Please enter a valid weight: ";
        } while(weight[i] < 1);

        cout << endl << "Please enter " << name << "'s heart rate for month " << i+1 << " in beats/minute: ";
            do{
                while(!(cin >> heartRate[i])){
                    cout << endl << "Please enter a valid heart rate: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if(heartRate[i] < 1)
                    cout << endl << "Please enter a valid heart rate: ";
            } while(heartRate[i] < 1);
    }
}

void DogHealth::printDogHealth(){

    cout << endl << endl << "All health info for " << name << ":" << endl;
    cout << endl << "Age: " << age << endl;
    
    for(size_t i = 0; i < MONTHS; ++i){
        cout << endl << name << "'s weight for month " << i+1 << ":  " << weight[i] << endl;
        cout << name << "'s heart rate for month " << i+1 << ":  " << heartRate[i] << endl;
    }
}

void DogHealth::printWeightStatistics(){

    ArrayHelper<double>* tempWeight = new ArrayHelper<double>(this->weight, MONTHS);

    cout << endl << endl << "Weight Statistics:" << endl << endl;
    cout << name << " weighed the most in month " << tempWeight->getMax() + 1 << " at " << tempWeight->getValue(tempWeight->getMax()) << " lbs." << endl << endl;
    cout << name << " weighed the least in month " << tempWeight->getMin() + 1 << " at " << tempWeight->getValue(tempWeight->getMin()) << " lbs." << endl << endl;
    cout << name << "'s average weight was " << tempWeight->getAverage() << " lbs." << endl << endl;

    delete tempWeight;
}

void DogHealth::printHeartRateStatistics(){

    ArrayHelper<int>* hr = new ArrayHelper<int>(heartRate, MONTHS);

    cout << endl << endl << "Heart Rate Statistics:" << endl << endl;
    cout << name << "'s heart rate was highest in month " << hr->getMax() + 1 << " at " << hr->getValue(hr->getMax()) << " bpm." << endl << endl;
    cout << name << "'s heart rate was lowest in month " << hr->getMin() + 1 << " at " << hr->getValue(hr->getMin()) << " bpm." << endl << endl;
    cout << name << "'s average heart rate was " << hr->getAverage() << " bpm." << endl << endl;

    delete hr;
}
