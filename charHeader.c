#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#include "Player.h"
#include <iostream>

class TicTacToeView; // forward declaration

class TicTacToe
{
private:
	char fBoard[3][3];
	int fFieldsSet;
	bool fActive;
	TicTacToeView* fView;

	// private methods
	bool check_winner();
	bool check_row();
	bool check_column();
	bool check_leading_diag();
	bool check_secondary_diag();
	bool individual_row(int x);
	bool individual_column(int y);

	int check_diag(Player aPlayer);

public:
	TicTacToe();

	void registerView( TicTacToeView* aView );

	int getField( int aIndex ) const;
	void setField( int aIndex, const Player& aPlayer );
	int findOptimalMoveForPlayer( const Player& aPlayerA, const Player& aPlayerB );

	bool isGameActive() const;
	bool isGameOverForPlayer( const Player& aPlayer );

	friend std::ostream& operator<<( std::ostream& out, const TicTacToe& obj );

};

#endif
