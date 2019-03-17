/*
File name: kn.cpp
Author: Evan Gertis
Date: 03/16/2019
Purpose: contains the function implementations used to solve the knights tour problem.
*/

#pragma once
#include "pch.h"

//the valid steps for the knight(xMoves[i], yMoves[i])
const std::array<int, 8> KN::KnightsTour::xMoves = { 2, 1, -1, -2, -2, -1, 1, 2};
const std::array<int, 8> KN::KnightsTour::yMoves = { 1, 2, 2, 1, -1, -2, -2, -1};

//Begin KnightsTour
KN::KnightsTour::KnightsTour()
{
	//solution matrix stores the counter value.
	solutionMatrix.resize(BOARD_SIZE);

	for (auto &subMatrix : solutionMatrix) {
		subMatrix.resize(BOARD_SIZE);
	}

	initializeBoard();
}
//End KnightsTour

//Begin ~KnightsTour
KN::KnightsTour::~KnightsTour()
{
}
//End ~KnightsTour

//Begin solveKnightsTourProblem
void KN::KnightsTour::solveKNightsTourProblem()
{
	//the knights starts at (0,0)
	solutionMatrix[0][0] = 0;

	//no solution.
	if (!solveProblem(1, 0, 0)) {
		std::cout << "no feasible solution found...\n";
	}

	//print out solution.
	showSolution();
}
//End solveKNightsTourProblem

//Begin solveProblem
bool KN::KnightsTour::solveProblem(int stepCount, int x, int y)
{ 
	//if we have done the last step: we are done.
	if (stepCount == BOARD_SIZE * BOARD_SIZE) {
		return true;
	}

	//consider all the moves a knight can make
	for (size_t i = 0; i < xMoves.size(); ++i)
	{
		//moves for the x and y coordinates
		int nextX = x + xMoves[i];
		int nextY = y + yMoves[i];

		//is it a valid move?
		if (isValidMove(nextX, nextY)) {
			//the move is valid.
			solutionMatrix[nextX][nextY] = stepCount;

			//let's try to find the next step.
			if (solveProblem(stepCount + 1, nextX, nextY)) {
				return true; //good solution.
			}

			//backtraing stage, we have modify previous steps
			//remove from solutions --> backtracking.
			solutionMatrix[nextX][nextY] = INT_MIN;
		}

	}

	return false;
}
//End solveProblem

//Begin isValidMove
bool KN::KnightsTour::isValidMove(int x, int y)
{
	//knight is out of the board (horizontally)
	if (x < 0 || x >= BOARD_SIZE) {
		return false;
	}

	//knight is out of the board (vertically)
	if (y < 0 || y >= BOARD_SIZE) {
		return false;
	}

	//knight is already stepped on this cell in the past.
	if (solutionMatrix[x][y] != INT_MIN) {
		return false;
	}
	//(x,y) cell is a valid move for the night.
	return true;
}
//End isValidMove

//Begin showSolution
void KN::KnightsTour::showSolution()
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		std::cout << std::left;
		
		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			std::cout << std::setw(2) << solutionMatrix[i][j] << std::setw(2) << ' ';
		}
		std::cout << "\n";
	}

}
//End showSolution

//Begin initalizeBoard
void KN::KnightsTour::initializeBoard()
{
	//INT_MIN implies that the knight has not visited that cell.
	for (int x = 0; x < BOARD_SIZE; ++x)
	{
		for (int y = 0; y < BOARD_SIZE; ++y)
		{
			solutionMatrix[x][y] = INT_MIN;
		}
	}
}
//End initalizeBoard
