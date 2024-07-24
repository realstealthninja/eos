/*
 * agent.h
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

#ifndef AGENT_H
#define AGENT_H

#include <cstdio>
#include <vector>

#include "constants.h"
#include "hmm.h"

static int masterID = 0;

class Dot{
public:
	double xPos, yPos;
};


class Agent{
public:
	std::vector<HMMU*> hmmus;
	std::vector<unsigned char> genome;
	std::vector<Dot> dots;
#ifdef useANN
	tANN *ANN;
#endif
	
	Agent *ancestor;
    Agent *predator;
	uint32_t nrPointingAtMe;
	uint8_t states[maxNodes*swarmSize]{}, newStates[maxNodes*swarmSize]{};
	double fitness{},convFitness{};
	std::vector<double> fitnesses;
	int food;
	
	double xPos{}, yPos{}, direction{};
	double sX{},sY{};

	bool foodAlreadyFound{};

	int steps{},bestSteps,totalSteps;
	int ID,nrOfOffspring;
	bool saved;
	bool retired;
	int born{};
	int correct{}, incorrect{};
	
	Agent();

	~Agent();

	void setupRandomAgent(int nucleotides);
	void loadAgent(char* filename);
	void loadAgentWithTrailer(char* filename);
	void setupPhenotype();
    void setupMegaPhenotype(int howMany);
	void inherit(Agent *from, double mutationRate, int theTime);
	uint8_t* getStatesPointer();
	void updateStates();
	void resetBrain();
	void ampUpStartCodons();
	void showBrain();
	void showPhenotype();
	void saveToDot(const char *filename, bool predator);
	void saveToDotFullLayout(char *filename);
	
	void initialize(int x, int y, int d);
	Agent* findLMRCA() const;
	void saveFromLMRCAtoNULL(FILE *statsFile, FILE *genomeFile);

	void retire();
	void setupDots(int x, int y,double spacing);
	void saveLogicTable(const char *filename);
	void saveGenome(const char *filename);
};

#endif // AGENT_H