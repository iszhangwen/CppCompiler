#pragma once
#include <vector>
#include <fstream>
#include <functional>
#include <list>

// 源码位置
struct SourceLocation {
    std::string filename;
    int line;
    int coloum;
};

/*
实现功能：利用双循环缓冲 + 哨兵标记，给scanner提供输入数据处理
*/
#define BUFFER_LEN  1024

class Source 
{
    enum TAG {BUFFER_TAG_0, BUFFER_TAG_1};
private:
    // double buffer. per buffer size is 4K
    char buffer_0[BUFFER_LEN];
    char buffer_1[BUFFER_LEN];
    char* start;
    char* follow;
    Source::TAG bufferTag;

    // record source location by file
    int line;
    int coloum;

    // file stream mannage
    std::ifstream infile;
    bool fill();

    // error handle
    std::function<void(int, int, std::string)> errorHandle;

public:
    Source(const std::string& fileName, std::function<void(int, int, std::string)>);
    virtual ~Source();
    std::tuple<int, int> pos() const;
    /*核心接口，获取下一个字符串，获取当前字符串在文件中的位置，用于词法识别器识别词素*/
    char rewind();
    char nextch();
    /*核心接口：获取词素*/
    std::string segment();
    /*是否读完*/
    bool is_end = false;
};

// 源码输入缓冲
class SourceBuffer {
private:


public:
    SourceLocation location;

    u_char curch(){ return ' ';}
    u_char nextch(){ return ' ';}
    // 不移动指针返回下一个值
    u_char peek(){ return ' ';}

    void start(){}
    void stop(){}  
     
    // 返回句子段落
    std::string segment(){ return std::string("");}
};
