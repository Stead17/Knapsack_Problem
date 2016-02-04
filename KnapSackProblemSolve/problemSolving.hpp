//
//  problemSolving.hpp
//  KnapSackProblemSolve
//
//  Created by Ваня Ткаченко on 12/21/15.
//  Copyright © 2015 stead. All rights reserved.
//

#ifndef problemSolving_hpp
#define problemSolving_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <random>
#include <fstream> 

using namespace std;

class Thing {
public:
    int weight;
    int value;
};

class Knapsack {
private:
    vector<Thing> knapSackThings;
    vector<Thing> restOfThings;
    int knapsackWeight;
    void ThingToKnapsack(int currentPostion);
    void ThingToRestOfThings(int currentPostion);
    
public:
    Knapsack(int KnapsackCarry, const vector<Thing>& things);
    
    int currentWeight = 0;
    int currentValue = 0;
    void vectorCopy(const Knapsack& currentState);
    void newStateGenerate();
    double probabilityFind() { return double(rand() / (RAND_MAX) + 1); }
    double changeState(int difValue, double temp) { return exp(difValue / temp); }
    
    ~Knapsack();

};

#endif /* problemSolving_hpp */
