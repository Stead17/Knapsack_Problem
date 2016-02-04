//
//  main.cpp
//  KnapSackProblemSolve
//
//  Created by Ваня Ткаченко on 12/21/15.
//  Copyright © 2015 stead. All rights reserved.
//

#include "problemSolving.hpp"

void problemSolving(vector<Thing>&, int&);
int fileReading(vector<Thing>&, int&);
void vectorPrint(const vector<Thing>&);

int main(int argc, const char * argv[]) {
    srand(time(nullptr));
    
    vector<Thing> resultState;
    int knapSackMaxWeight;
    
    problemSolving(resultState, knapSackMaxWeight);
    
    vectorPrint(resultState);
    return 0;
}

// Print the result vector which contain things that fit knapsack
void vectorPrint(const vector<Thing>& currentVector) {
    for (int i = 0; i < currentVector.size(); ++i) {
        cout << i << ":\n";
        cout << "weight: " << currentVector[i].weight << endl;
        cout << "value: " << currentVector[i].value << endl;
    }
}

int fileReading(vector<Thing>& thingsOne, int& knapSackCarrying) {
    
    int items_num;
    ifstream f("/Developer/uniCode/TASK2_OOP/KnapSackProblemSolve/KnapSackProblemSolve/"
               "knapsack128.in", ios::in); // file with things
    if (f.is_open())
    {
        f >> items_num;
        f >> knapSackCarrying;
        Thing* items;
        items = new Thing[items_num];
        
        for (int i = 0; i < items_num; ++i)
            f >> items[i].value;
        
        for (int i = 0; i < items_num; ++i)
            f >> items[i].weight;
        
        f.close();
        
        for (int i = 0; i < items_num; ++i)
            thingsOne.push_back(items[i]);
        
        return 0;
    }
    return 1;
}

// The main algoritm which find optimal set of things
void problemSolving(vector<Thing>& resThings, int& knapSackWeight) {
    double probability;
    double currentTemp;
    const double endTemp = 1e-50;
    const double decrement = 0.95;
    const double initialTemp = 50.0;
    const int amountOfIter = 40;
    
    if (fileReading(resThings, knapSackWeight) == 0) {
        currentTemp = initialTemp;
        
        Knapsack resultState(knapSackWeight, resThings);
        Knapsack candidateState(knapSackWeight, resThings);
        
        while (currentTemp > endTemp) {
            
            for (int i = 0; i < amountOfIter; ++i) {
                candidateState.vectorCopy(resultState);
                candidateState.newStateGenerate();
                
                if (candidateState.currentValue > resultState.currentValue) {
                    resultState.vectorCopy(candidateState);
                } else {
                    int valueDif = candidateState.currentValue - resultState.currentValue;
                    probability = resultState.probabilityFind();
                    if (resultState.changeState(valueDif, currentTemp) >= probability)
                        resultState.vectorCopy(candidateState);
                }
            }
            
            currentTemp *= decrement;
        }
        
        
        cout << "Max weight: " << knapSackWeight << endl;
        cout << "Weight: " << resultState.currentWeight << endl;
        cout << "Value: " << resultState.currentValue << endl;
        
    } else {
        cout << "Open file error" << endl;
    }
}