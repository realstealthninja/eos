/*
 * tGame.h
 *
 * This file is part of the Evolution of Swarming project.
 *
 * Copyright 2012 Randal S. Olson, Arend Hintze.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#ifndef GAME_H
#define GAME_H

#include "constants.h"
#include "agent.h"

#include <vector>
#include <string>


class Octuplet{
public:
    std::vector<int> data;
    void loadOctuplet(FILE *f);
};

class Experiment{
public:
    std::vector<Octuplet> dropSequences,sizeSequences,selfSequences;
    std::vector<std::vector<std::vector<bool> > > shouldHit;

    void loadExperiment(char *filename);
    void showExperimentProtokoll();
    int drops() const;
    int sizes() const;
    int selves() const;
};

class Game{
public:
    Experiment theExperiment;
    void loadExperiment(char *filename);
    std::string executeGame(Agent* swarmAgent, Agent* predatorAgent, FILE *data_file, bool report, double safetyDist, double predatorVisionAngle, int killDelay, double confusionMultiplier);
    
    Game();
    ~Game();

    static double calcDistanceSquared(double fromX, double fromY, double toX, double toY);
    static double calcAngle(double fromX, double fromY, double fromAngle, double toX, double toY);
    void calcSwarmCenter(const double preyX[], const double preyY[], const bool preyDead[], double& preyCenterX, double& preyCenterY);
    void recalcPredDistTable(double preyX[], double preyY[], bool preyDead[],
                             double predX, double predY,
                             double predDists[swarmSize]);
    void recalcPredAndPreyDistTable(double preyX[], double preyY[], const bool preyDead[],
                                    double predX, double predY,
                                    double predDists[swarmSize], double preyDists[swarmSize][swarmSize]);
    static void applyBoundary(double& positionVal);
    static double sum(const std::vector<double>& values);
    double average(const std::vector<double>& values);
    double variance(const std::vector<double>& values);
    static double mutualInformation(std::vector<int> A, std::vector<int>B);
    static double ei(std::vector<int> A, std::vector<int> B,int theMask);
    double computeAtomicPhi(std::vector<int>A,int states);
    double predictiveI(std::vector<int>A);
    double nonPredictiveI(std::vector<int>A);
    double predictNextInput(std::vector<int>A);
    double computeR(std::vector<std::vector<int> > table,int howFarBack);
    double computeOldR(std::vector<std::vector<int> > table);
    static double entropy(std::vector<int> list);
    int neuronsConnectedToPreyRetina(Agent *agent);
    int neuronsConnectedToPredatorRetina(Agent* agent);

};

#endif // GAME_H
