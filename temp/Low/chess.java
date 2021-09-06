// 1. IT should have 2 players
// 2. There should be a time for each player?


class Chess {

	ChessBoard chessBoard;
	vector<Player> players;
	Player currentPlayer;
	vector<Move> movesvector;
	GameStatus gameStatus;

	public bool playerMove(CellPosition fromPosition, CellPositionb toPosition, Piece piece); 
	public bool endGame();
	private void changeTurn(); // this is private because it is called by playerMove

}

class Player {

	Account account;
	Color color;
	Time timeLeft;

}

class Time {

	int mins;
	int secs;

}

public enum Color {

	BLACK, WHITE;
	
}

public enum GameStatus {

	ACTIVE, PAUSED, FORTFEIGHT, BLACK_WIN, WHITE_WIN;
}

class ChessBoard {

	vector<vector<Cell>>> board;

	public void resetBoard();
	public void updateBoard(Move move); // this will be called by playerMove

class Cell {

	Color color;
	Piece piece;
	CellPosition position;
}

class CellPosition {

	Char ch;
	int i;
}

class Move {

	Player turn;
	Piece piece;
	Piece killedPiece;
	CellPosition startPosition;
	CellPosition endPosition;

}

class Piece {

	Color color;

	public virtual bool move(CellPosition fromPosition, CellPositionb toPosition);
	public virtual vector<CellPosition> possibleMoves(CellPosition fromPosition);
	
}

class Knight : Piece {

	public bool move(CellPosition fromPosition, CellPositionb toPosition);
	public vector<CellPosition> possibleMoves(CellPosition fromPosition);

}

class Bishop : Piece {
	
	public bool move(CellPosition fromPosition, CellPositionb toPosition);
	public vector<CellPosition> possibleMoves(CellPosition fromPosition);

}

class rook : Piece {
	
	public bool move(CellPosition fromPosition, CellPositionb toPosition);
	public vector<CellPosition> possibleMoves(CellPosition fromPosition);

}

class King : Piece {
	
	public bool move(CellPosition fromPosition, CellPositionb toPosition);
	public vector<CellPosition> possibleMoves(CellPosition fromPosition);

}

class Queen : Piece {
	
	public bool move(CellPosition fromPosition, CellPositionb toPosition);
	public vector<CellPosition> possibleMoves(CellPosition fromPosition);

}

class Pawn : Piece {
	
	public bool move(CellPosition fromPosition, CellPositionb toPosition);
	public vector<CellPosition> possibleMoves(CellPosition fromPosition);

}