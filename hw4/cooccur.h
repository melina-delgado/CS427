#ifndef __COOCCUR_H__
#define __COOCCUR_H__

#include <unordered_map>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iterator>

/**
 * A cooccurrence matrix.
 */
class CooccurrenceMatrix
{
public:
  /**
   * Creates a cooccurrence matrix that counts cooccurrences of the given keywords
   * and is initialized to 0 for all entries.
   *
   * @param keywords a vector of unique strings 
   */
  CooccurrenceMatrix(std::vector<std::string> keywords);

  /**
   * Reads keywords from the given matrix from the current line of the given stream.
   * A keyword is considered to have been read if it appears on the stream before
   * the next newline surrounded by whitespace, the beginning of input (as seen by
   * this function), or EOF.  The newline is read and removed from the stream.
   *
   * @param is an input stream
   * @return an set of strings containing all the keywords read
   */
  std::unordered_set<std::string> readContext(std::istream& is) const;

  /**
   * Updates the given cooccurrence matrix by incrementing the counts for
   * each pair of keywords in the given context.
   *
   * @param context an set of strings that are keywords for this matrix
   */
  void update(const std::unordered_set<std::string>& context);

  /**
   * Returns the vector (row) for the given word in the given matrix.
   * Values in the returned array correspond to the keywords for the
   * given matrix in the order they were given in the array passed to
   * the constructor that created the given matrix.  Each
   * value is the proportion of times that the given keyword appeared in
   * a call to update for the given matrix that also contained
   * each other keyword.  If the given word is not a keyword for the
   * given matrix or the keyword has never appeared in a call to
   * update for the given matrix, then the returned array
   * contains 0.0 in every entry.
   *
   * @param word a string, non-NULL
   * @return an vector of doubles
   */
  std::vector<double> getVector(const std::string& keyword) const;
  
private:
  std::vector<std::vector<int>> matrix;
  const int nkeywords;
  std::vector<std::string> keys;
  std::unordered_map<std::string, double> keyMap;
  std::unordered_map<std::string, int> keyPos;
};

#endif
