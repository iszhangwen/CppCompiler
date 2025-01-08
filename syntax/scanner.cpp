#include "scanner.h"

Token scanner::nextToken()
{
    // 跳过空格
    u_char ch = buffer.curch();
    while (isSpace(ch)) {
        ch = buffer.nextch();
    }
    buffer.start();
    // DFA状态图验证：以程序为中心实现
    switch (ch)
    {
    case 0x80:
        break;

        break;
    // 数字判断
    case '0'...'9':  return numberLiteral();
    // 标识符,关键字
    case 'a'...'z':
    case 'A'...'Z':
    case '_':        return identifier();
    // 分隔符
    case '{':        return Token(TokenType::LCurly_Brackets_, buffer.location);
    case '}':        return Token(TokenType::RCurly_Brackets_, buffer.location);
    case '[':        return Token(TokenType::LSquare_Brackets_, buffer.location);
    case ']':        return Token(TokenType::RSquare_Brackets_, buffer.location);
    case '(':        return Token(TokenType::LParent_, buffer.location);
    case ')':        return Token(TokenType::RParent_, buffer.location);
    case ';':        return Token(TokenType::Semicolon_, buffer.location);
    case '\n':       return Token(TokenType::NewLine_, buffer.location);
    // 预处理器指令
    case '#':
        if (buffer.peek() == '#') { 
            buffer.nextch();
            return Token(TokenType::Pound_, buffer.location);
        } 
        return Token(TokenType::TokenPasting_, buffer.location);
    default:
        return error();
    }
    return Token();
}

Token scanner::identifier()
{
    // 读取token直到遇到非字母数字下划线符号
    u_char ch = buffer.nextch();
    while (true) {
        if (isLetter(ch) || isDecimal(ch)) {
            ch = buffer.nextch();
        } else {
            break;
        }
    }

    // 获取标识符的Token类型, 关键字也是标识符
    std::string value = buffer.segment();
    TokenType id = getIdentifierTokenType(value);
    return Token(id, value, buffer.location);
}

Token scanner::numberLiteral()
{   
    TokenType type = TokenType::LITERAL_;
    u_char ch = buffer.curch();
    if (ch == '0') {
        ch == buffer.nextch();
        switch (ch)
        {
        case 'x':
        case 'X':
            ch = buffer.nextch();
            while (isHexacimal(ch)) {
                ch = buffer.nextch();
            }
            type = TokenType::Integer_Literal_;
            break;
        case 'b':
        case 'B':
            ch = buffer.nextch();
            while (isBinary(ch)) {
                ch = buffer.nextch();
            }
            type = TokenType::Integer_Literal_;
            break;
        default:
            ch = buffer.nextch();
            while (isOctal(ch)) {
                ch = buffer.nextch();
            }
            type = TokenType::Integer_Literal_;
            break;
        }
    } 
    if (ch == '.') {}
    return Token();
}

Token scanner::stringLiteral()
{
    return Token();
}

Token scanner::error()
{
    return Token();
}

bool scanner::isSpace(u_char ch)
{
    if (ch == ' ' || ch == '\r' || ch == '\t') {
        return true;
    }
    return false;
}

bool scanner::isLetter(u_char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || '_') {
        return true;
    }
    return false;
}

bool scanner::isDecimal(u_char ch)
{
    if (ch >= '0' && ch <= '9') {
        return true;
    }
    return false;
}

bool scanner::isHexacimal(u_char ch)
{
    if ((ch >= '0' && ch <= '9') || (ch <= 'f' && ch >= 'a') || (ch <= 'F' && ch >= 'A')) {
        return true;
    }
    return false;
}

bool scanner::isOctal(u_char ch) {
    if (ch >= '0' && ch <= '7') {
        return true;
    }
    return false;
}

bool scanner::isBinary(u_char ch) {
    if (ch == '0' || ch == '1') {
        return true;
    }
    return false;
}

TokenType scanner::getIdentifierTokenType(const std::string& word)
{
    auto search = KeyWordMap.find(word);
    if (search != KeyWordMap.end()) {
        return search->second;
    }
    return TokenType::Name_;
}