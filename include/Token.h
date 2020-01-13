#ifndef Token_H
#define Token_H

#include <string>

struct Token {
  /**
   * @brief The different kinds of tokens
   * The positive and negative numbers represent different types
   * of tokens but a grammar rule that accepts any kind of number
   * can use the Number type
   */
  enum Type {
      StringLiteral,
      Separator,
      PositiveNumber,
      NegativeNumber,
      FloatingPointNumber,
      Number,
      Identifier,
      ArithmeticSign,
      Eof
  };

  /**
   * @return A Token representing an arithmetic sign
   */
  static Token createArithmeticSign(char src);
  
  /**
   * @return A Token representing a separator
   */
  static Token createSeparator(char src);

  /**
   * The Token's type returned here depends on is_positive and is_float
   * @param number The image of the number
   * @param is_positive true if number represents a positive number
   * @param is_float true if the number represents a floating-point number
   * @return A Token representing a number
   */
  static Token createNumber(const std::string& number, bool is_positive, bool is_float);
  
  /**
   * @brief Constructs an EOF token.
   */
  Token();

  /**
   * @brief Construct a new token with the given type and image
   */
  Token(Type type, const std::string& image = "");
  
  Token(const Token&) = default;
  Token& operator=(const Token&) = default;
  Token(Token&&) = default;
  Token& operator=(Token&&) = default;

  /**
   * @brief Equality comparison with another token
   * @see operator== with string and Token::Type
   */
  bool operator==(const Token&) const;
  
  /**
   * @return true if the token's image is equal to other
   * @param other String to compare
   */
  bool operator==(const std::string&) const;
  
  /**
   * If the token's type is Number or if other is Number,
   * then it also matches PositiveNumber, NegativeNumber and FloatingPointNumber
   *  
   * @return true if the token's type is equal to other
   * @param other Type to compare
   */
  bool operator==(Token::Type) const;

  /**
   * @see operator==
   */
  bool operator!=(const Token&) const;

  /**
   * @see operator==
   */
  bool operator!=(const std::string&) const;
  
  /**
   * @see operator==
   */
  bool operator!=(Token::Type) const;

  /**
   * Using the standard library's functionnalities, parses the 
   * image to an unsigned integer
   */
  unsigned long long toUInt() const;
  
  /**
   * Same as above but outputs a signed integer
   */
  long long toInt() const;
  
  /**
   * Same as above but outputs a floating-point number
   */
  double toDouble() const;
  
  /**
   * @brief The token's type
   */
  Type type;
  
  /**
   * @brief The token's image, ie. the string that represents it
   */
  std::string image;
};

#endif
