#pragma once
#include <string>
#include <unordered_map>

// token 类型
enum class TokenType {
    EOF_,
    // 标识符定义
    IDENTIFIER_,
    Name_,

    // 字面量定义
    LITERAL_,
    Integer_Literal_,
    Character_Literal_,
    Floating_Literal_,
    String_Literal_,
    Boolean_Literal_,
    Pointer_Literal_,
    User_Defined_Literal_,

    OPERATOR_,
    // 复合语句和分隔符 {} [] () ; ...  \n
    LCurly_Brackets_,
    RCurly_Brackets_,
    LSquare_Brackets_,
    RSquare_Brackets_,
    LParent_,
    RParent_,
    Semicolon_,
    Ellipsis_,
    NewLine_,
    // 预处理器指令 # ##
    Pound_,
    TokenPasting_,
    // 特殊语法构造 <: :> <% %> %: %:%: 暂时不会用到
    LAlternative_Curly_Brackets_,
    RAlternative_Curly_Brackets_,
    LAlternative_Square_Brackets_,
    RAlternative_Square_Brackets_,
    Alternative_Pound_,
    Alternative_TokenPasting_,
    // 操作符 new delte 三元条件运算符 ? : 作用域解析运算符 :: 成员访问运算符.* ->* 箭头运算符 ->
    Conditional_, // ? :
    Scope_Resolution_, // ::
    PtrObject_Member_Access_,
    Object_Member_Access_,
    Arrow_,
    // 算术运算符: + - * / % ^ & | ~
    Addition_,
    Subtraction_,
    Multiplication_,
    Division_,
    Modulus_,
    BitWise_XOR_,
    BitWise_AND_,
    BitWise_OR_,
    BitWise_NOT_,
    // 逻辑运算符 ! && ||
    Logical_NOT_,
    Logical_AND_,
    Logical_OR_,
    // 关系运算符: == != < > <= >=
    Equality_,
    Inequality_,
    Less_,
    Greater_,
    Less_Equal_,
    Greater_Equal_,
    // 赋值运算符 = += -+ *= /= %= ^= &= |=
    Assign_,
    Add_Assign_,
    Sub_Assign_,
    Mult_Assign_,
    Div_Assign_,
    Mod_Assign_,
    XOR_Assign_,
    AND_Assign_,
    OR_Assign_,
    // 自增自减运算符 ++ --
    Increment_,
    Decrement_,
    // 其他运算符 逗号运算符,
    Comma_,
    PUNCTURTOR_,
    // 关键字定义
    KEYWORD_,
    Alignas_,
    Continue_,
    Friend_,
    Register_,
    True_,
    Alignof_,
    Decltype_,
    Goto_,
    Reinterpret_Cast_,
    Try_,
    Asm_,
    Default_,
    If_,
    Return_,
    Typedef_,
    Auto_,
    Delete_,
    Inline_,
    Short_,
    Typeid_,
    Bool_,
    Double_,
    Int_,
    Signed_,
    Typename_,
    Break_,
    Do_,
    Long_,
    Sizeof_,
    Union_,
    Case_,
    Dynamic_Cast_,
    Mutable_,
    Static_,
    Unsigned_,
    Catch_,
    Else_,
    Namespace_,
    Static_Assert_,
    Using_,
    Char_,
    Enum_,
    New_,
    Static_Cast_,
    Virtual_,
    Char16_T_,
    Explicit_,
    Noexcept_,
    Struct_,
    Void_,
    Char32_T_,
    Export_,
    Nullptr_,
    Switch_,
    Volatile_,
    Class_,
    Extern_,
    Operator_,
    Template_,
    Wchar_T_,
    Const_,
    False_,
    Private_,
    This_,
    While_,
    Constexpr_,
    Float_,
    Protected_,
    Thread_Local_,
    Const_Cast_,
    For_,
    Public_,
    Throw_,  
END_
};

const std::string KeyWords = "alignas continue friend register true \
 alignof decltype goto reinterpret_cast try \
 asm default if return typedef \
 auto delete inline short typeid \
 bool double int signed typename \
 break do long sizeof union \
 case dynamic_cast mutable static unsigned \
 catch else namespace static_assert using \
 char enum new static_cast virtual \
 char16_t explicit noexcept struct void \
 char32_t export nullptr switch volatile \
 class extern operator template wchar_t \
 const false private this while \
 constexpr float protected thread_local \
 const_cast for public throw";

const std::string Operators = " { } [ ] # ## ( ) \
 <: :> <% %> %: %:%: ; : ... \
 new delete ? :: . .* \
 +- * / % ˆ & | ~ \
 ! = < > +=-= *= /= %= \
 ˆ= &= |= << >> >>= <<= == != \
 <= >= && || ++-- ,->*-> \
 and and_eq bitand bitor compl not not_eq \
 or or_eq xor xor_eq";

const std::unordered_map<std::string, TokenType> KeyWordMap = {
    { "alignas",     TokenType::Alignas_ },
    { "continue",    TokenType::Continue_ },
    { "friend",      TokenType::Friend_ },
    { "register",    TokenType::Register_ },
    { "true",        TokenType::True_ },
    { "alignof",     TokenType::Alignof_ },
    { "decltype",    TokenType::Decltype_ },
    { "goto",        TokenType::Goto_ },
    { "reinterpret_cast", TokenType::Reinterpret_Cast_ },
    { "try",         TokenType::Try_ },
    { "asm",         TokenType::Asm_ },
    { "default",     TokenType::Default_ },
    { "if",          TokenType::If_ },
    { "return",      TokenType::Return_ },
    { "typedef",     TokenType::Typedef_ },
    { "auto",        TokenType::Auto_ },
    { "delete",      TokenType::Delete_ },
    { "inline",      TokenType::Inline_ },
    { "short",       TokenType::Short_ },
    { "typeid",      TokenType::Typeid_ },
    { "bool",        TokenType::Bool_ },
    { "double",      TokenType::Double_ },
    { "int",         TokenType::Int_ },
    { "signed",      TokenType::Signed_ },
    { "typename",    TokenType::Typename_ },
    { "break",       TokenType::Break_ },
    { "do",          TokenType::Do_ },
    { "long",        TokenType::Long_ },
    { "sizeof",      TokenType::Sizeof_ },
    { "union",       TokenType::Union_ },
    { "case",        TokenType::Case_ },
    { "dynamic_cast", TokenType::Dynamic_Cast_ },
    { "mutable",     TokenType::Mutable_ },
    { "static",      TokenType::Static_ },
    { "unsigned",    TokenType::Unsigned_ },
    { "catch",       TokenType::Catch_ },
    { "else",        TokenType::Else_ },
    { "namespace",   TokenType::Namespace_ },
    { "static_assert", TokenType::Static_Assert_ },
    { "using",       TokenType::Using_ },
    { "char",        TokenType::Char_ },
    { "enum",        TokenType::Enum_ },
    { "new",         TokenType::New_ },
    { "static_cast", TokenType::Static_Cast_ },
    { "virtual",     TokenType::Virtual_ },
    { "char16_t",    TokenType::Char16_T_ },
    { "explicit",    TokenType::Explicit_ },
    { "noexcept",    TokenType::Noexcept_ },
    { "struct",      TokenType::Struct_ },
    { "void",        TokenType::Void_ },
    { "char32_t",    TokenType::Char32_T_ },
    { "export",      TokenType::Export_ },
    { "nullptr",     TokenType::Nullptr_ },
    { "switch",      TokenType::Switch_ },
    { "volatile",    TokenType::Volatile_ },
    { "class",       TokenType::Class_ },
    { "extern",      TokenType::Extern_ },
    { "operator",    TokenType::Operator_ },
    { "template",    TokenType::Template_ },
    { "wchar_t",     TokenType::Wchar_T_ },
    { "const",       TokenType::Const_ },
    { "false",       TokenType::False_ },
    { "private",     TokenType::Private_ },
    { "this",        TokenType::This_ },
    { "while",       TokenType::While_ },
    { "constexpr",   TokenType::Constexpr_ },
    { "float",       TokenType::Float_ },
    { "protected",   TokenType::Protected_ },
    { "thread_local", TokenType::Thread_Local_ },
    { "const_cast",  TokenType::Const_Cast_ },
    { "for",         TokenType::For_ },
    { "public",      TokenType::Public_ },
    { "throw",       TokenType::Throw_ },
};



