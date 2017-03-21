//
//  HighestScore.h
//  CardsSimulator
//
//  Created by Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath on 12/11/15.
//  Copyright (c) 2015 Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath. All rights reserved.
//

#pragma once

#include <string>

class HighestScore
{
public:
	HighestScore();
	~HighestScore();
	void printScores();
	void saveScores(std::string name, int score);
	std::string lineReader(std::string line);
};

