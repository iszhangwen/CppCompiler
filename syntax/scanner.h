#pragma once
#include <string>
#include "token.h"
#include "source.h"

struct Token {
    Token(){}
    Token(TokenType type, SourceLocation location):
    type_(type), value_(""), location_(location){}
    Token(TokenType type, const std::string& value, SourceLocation location):
    type_(type), value_(value), location_(location){}

    TokenType type_;
    std::string value_;
    SourceLocation location_;
};

// 扫描器从SourceBuffer读取字符，返回Token
class scanner {
private:
    SourceBuffer buffer;

    Token identifier();
    Token numberLiteral();
    Token stringLiteral();
    Token error();

public:
    Token nextToken();

    static bool isSpace(u_char);
    static bool isLetter(u_char);
    static bool isDecimal(u_char);
    static bool isHexacimal(u_char);
    static bool isOctal(u_char ch);
    static bool isBinary(u_char ch);

    static TokenType getIdentifierTokenType(const std::string&);

};