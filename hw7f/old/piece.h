#ifndef __PIECE_H__
#define __PIECE_H__

namespace cs427_527
{
  class Board;

  /**
   * A piece.
   */
  class Piece
  {
    public: 
      /**
       * Creates a piece owned by the given player at the given position.
       *
       * @param p 0 or 1
       * @param r a nonnegative integer
       * @param c a nonnegative integer
       */
      Piece(int p, int r, int c);

      /**
       * Destroys this piece.
       */
      virtual ~Piece();

      /**
       * Determines if it is legal to move this piece to the
       * given position on the given board, considering only the
       * movement rules for a piece.  So this method does not
       * consider turn, can-jump-must-jump rules, or similar rules.
       *
       * @param board a board
       * @param toR a row on that board
       * @param toC a column on that board
       */
      virtual bool isLegalMove(const Board& board, int toR, int toC) const=0;

      /**
       * Moves this piece to the given position on the given board,
       * provided the move is legal, considering the movement rules
       * for a piece.
       *
       * @param board a board
       * @param toR a row on that board
       * @param toC a column on that board
       */
      virtual void makeMove(Board& board, int toR, int toC)=0;

      /**
       * Returns the index of the player this piece belongs to.
       *
       * @return the index of the owner
       */
      int getPlayer() const;

      /**
       * Returns a printable representation of this piece.
       *
       * @return a printable representation of this piece
       */
      virtual std::string toString() const=0;

    protected:
      /**
       * Determines if it is legal to move this piece to the given
       * location on the board, considering only the contents of
       * that location.
       *
       * @param board the board this piece is on
       * @param toR a row on that board
       * @param toC a column on that board
       * @return true if and only if the move is legal, considering only
       * the contents of the destination
       */
      virtual bool isLegalDestination(const Board& board, int toR, int toC) const=0;

      /**
       * Determines if it is legal to move this piece to the given
       * location, considering only the direction of the move.
       *
       * @param toR a row index
       * @param toC a column index
       * @return true if and only if the move is legal, considering only direction
       */
      virtual bool isLegalDirection(int toR, int toC) const=0;

      /**
       * Determines if it is legal to move this piece the given
       * distance, considering only the distance.  The distance is
       * defined as the larger of the change in row and the change in
       * column.
       *
       * @param a nonnegative integer
       * @return true if it is generally legal to move this piece that distance
       */
      virtual bool isLegalDistance(int dist) const=0;

      /**
       * Returns whether this piece can move backwards.
       *
       * @return true if and only if this piece can move backwards
       */
      virtual bool canMoveBackwards() const=0;

      /**
       * Determines if this piece is promoted if moving to the given
       * location.
       *
       * @param board the board this piece is on
       * @param toR a row on that board
       * @param toC a column on that board
       * @return true if this piece is promoted
       */
      virtual bool checkPromote(const Board& board, int toR, int toC) const;

      /**
       * Returns the piece this piece is promoted to.  The new piece
       * is located at the same position as this piece.
       *
       * @return the piece this piece is promoted to
       */
      virtual std::shared_ptr<Piece> promote() const;

      /**
       * The index of the player this piece belongs to.
       */
      int player;

      /**
       * The row of the position of this piece.
       */
      int row;

      /**
       * The column of the position of this piece.
       */
      int col;
  };
}

#endif
