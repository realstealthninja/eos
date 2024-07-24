/*
 * tHMM.h
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

#ifndef HMMU_HEADER
#define HMMU_HEADER

#include <cstdint>
#include <vector>
#include <deque>



class HMMU {
public:
	std::vector<std::vector<uint8_t> > hmm;
	std::vector<uint32_t> sums;
	std::vector<int> ins, outs;
	uint8_t posFBNode,negFBNode;
	uint8_t nrPos, nrNeg;
	std::vector<int> posLevelOfFB,negLevelOfFB;
	std::deque<uint8_t> chosenInPos, chosenInNeg, chosenOutPos, chosenOutNeg;
	
	uint8_t _xDim,_yDim;

	HMMU();
	~HMMU();

	void setup(std::vector<uint8_t> &genome, int start);
	void setupQuick(std::vector<uint8_t> &genome, int start);
	void update(uint8_t *states, uint8_t *newStates);
	void show(void);
	
};

#endif // HMMU_HEADER