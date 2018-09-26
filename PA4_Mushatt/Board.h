/*
 * Board.h
 *
 *  Created on: Sep 26, 2018
 *      Author: jemushatt
 */

#ifndef BOARD_H_
#define BOARD_H_

class Board {
public:
	Board();
	virtual ~Board();
	int getRow();
	int getCol();
	int getTotalTurns();
	void buildBoard();
private:
	int rows, cols, totalTurns;

};

#endif /* BOARD_H_ */
