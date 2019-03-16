#pragma once
#include "pch.h"
/*
File: kn.h
Author: Evan Gertis.
Date: 03/16/2019
Purpose: Holds defs, class, namespace, and memebers used in kn.cpp
*/

//Begin namespace
namespace KN {

	//Begin class
	class KnightsTour
	{

		//cells store integers (step counter)
		std::vector<std::vector<int>> solutionMatrix;

		//steps horizontally.
		const static std::array<int, 8> xMoves;
		const static std::array<int, 8> yMoves;

		constexpr static int BOARD_SIZE = 8;

	public:
		KnightsTour();
		~KnightsTour();

		void solveKNightsTourProblem();
		bool solveProblem(int stepCount, int x, int y);

		bool isValidMove(int x, int y);

		void showSolution();

	private:

		void initializeBoard();
	};
	//End class

}
//End namespace