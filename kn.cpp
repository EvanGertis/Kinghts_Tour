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
}
//End solveKNightsTourProblem

//Begin solveProblem
bool KN::KnightsTour::solveProblem(int stepCount, int x, int y)
{
	return false;
}
//End solveProblem

//Begin isValidMove
bool KN::KnightsTour::isValidMove(int x, int y)
{
	return false;
}
//End isValidMove

//Begin showSolution
void KN::KnightsTour::showSolution()
{
}
//End showSolution

//Begin initalizeBoard
void KN::KnightsTour::initializeBoard()
{
}
//End initalizeBoard
