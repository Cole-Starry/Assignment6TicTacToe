#pragma once
#include "Game.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <array>
#include <vector>
#include <fstream>

using namespace std;

class TicTacToe : public Game {
private:
	char m_board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
	int player = 0;


public:
	bool IsGameOver() const override
	{
		int line = 0;
		int strikex = 0;
		int strikeo = 0;

		for (int y = 0; y < 3; y++) {
			line = 3 * y;
			for (int i = line; i < line + 3; i++)
			{

				if (m_board[i] == 'X')
				{
					strikex++;
				}
				else if (m_board[i] == 'O')
				{
					strikeo++;
				}
			}
			if (strikex == 3 || strikeo == 3)
			{
				cout << "\n";
				return true;
			}
			strikex = 0;
			strikeo = 0;

			for (int i = y; i <= 6 + y; i += 3)
			{

				if (m_board[i] == 'X')
				{
					strikex++;
				}
				else if (m_board[i] == 'O')
				{
					strikeo++;
				}
			}
			if (strikex == 3 || strikeo == 3)
			{
				cout << "\n";
				return true;
			}
			strikex = 0;
			strikeo = 0;
		}

		for (int y = 0; y < 2; y++) {
			int add = 4 - y * 2;
			for (int i = y * 2; i < 9 - y * 2; i += add) {
				if (m_board[i] == 'X')
				{
					strikex++;
				}
				else if (m_board[i] == 'O')
				{
					strikeo++;
				}
			}
			if (strikex == 3 || strikeo == 3)
			{
				cout << "\n";
				return true;
			}
			strikex = 0;
			strikeo = 0;
		}


		for (int i = 0; i < 9; i++)
		{
			if (m_board[i] == 'X')
			{
				strikex++;
			}
			else if (m_board[i] == 'O')
			{
				strikeo++;
			}
		}

		if (strikex + strikeo == 9) {
			cout << "\n";
			return true;
		}

		return false;
	}

	void Display() const override {
		system("cls");
		for (int i = 0; i < 3; i++)
		{
			int pos = i * 3;
			cout << "--"+to_string(pos+1)+"---" + to_string(pos+2) + "---" + to_string(pos+3) + "--\n";
			cout << "| "+string(1, m_board[pos])+" | "+string(1, m_board[pos+1])+" | "+string(1,m_board[pos+2])+ " |\n";
			
		}
		cout << "-------------\n\n";
		cout << "It is player " + to_string(player)+"'s turn.\n";
	}


	void TakeTurn() {
		while(true){
		char piece = 'O';
		if (player == 0) piece = 'X';
		cout << "\nPlace a "+ string(1,piece) +" in position between 1 and 9: ";
		int position;
		cin >> position;
		if (!(position <= 9 && position >= 1 && m_board[position-1]==' '))
		{
			cout << "Please enter a vaild postion.";
			continue;
		}
		m_board[position - 1] = piece;
		
		if (player == 0) player = 1;
		else player = 0;
		return;
		}
	}



};