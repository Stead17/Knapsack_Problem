//
//  problemSolving.cpp
//  KnapSackProblemSolve
//
//  Created by Ваня Ткаченко on 12/21/15.
//  Copyright © 2015 stead. All rights reserved.
//

#include "problemSolving.hpp"

Knapsack::Knapsack(int KnapsackCarry, const vector<Thing>& things) {
    knapsackWeight = KnapsackCarry;
    restOfThings = things;
}

void Knapsack::newStateGenerate() {
    int randInd = rand() % restOfThings.size();
    
    while (knapsackWeight < currentWeight + restOfThings[randInd].weight)
        ThingToRestOfThings(rand() % knapSackThings.size());
    
    ThingToKnapsack(randInd);
}

void Knapsack::ThingToRestOfThings(int currentPostion) {
    restOfThings.push_back(knapSackThings[currentPostion]);
    currentWeight -= knapSackThings[currentPostion].weight;
    currentValue -= knapSackThings[currentPostion].value;
    
    knapSackThings.erase(knapSackThings.begin() + currentPostion);
}

void Knapsack::ThingToKnapsack(int currentPostion) {
    knapSackThings.push_back(restOfThings[currentPostion]);
    currentWeight += restOfThings[currentPostion].weight;
    currentValue += restOfThings[currentPostion].value;
    
    restOfThings.erase(restOfThings.begin() + currentPostion);
}

void Knapsack::vectorCopy(const Knapsack &currentState) {
    this->knapSackThings = currentState.knapSackThings;
    this->restOfThings = currentState.restOfThings;
    this->currentWeight = currentState.currentWeight;
    this->currentValue = currentState.currentValue;
}

Knapsack::~Knapsack() {}
