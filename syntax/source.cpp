#include "source.h"
#include <memory>
#include <sstream>
#include <iostream>
#include <cstring>


Source::Source(const std::string& fileName, std::function<void(int, int, std::string)> handle): errorHandle(handle)
{
    // init file
    infile.open(fileName);
    if (!infile.is_open()) {
        errorHandle(line + 1, coloum + 1, "file openfaild");
        return;
    }
    // init buffer
    memset(buffer_0, 0, BUFFER_LEN);
    memset(buffer_1, 0, BUFFER_LEN);
    infile.read(buffer_0, BUFFER_LEN-1);
    int count = infile.gcount();
    buffer_0[count] = EOF;
    start = &buffer_0[0];
    follow = &buffer_0[0];
}

Source::~Source()
{
    if (infile.is_open()) {
        infile.close();
    }
}

std::tuple<int, int> Source::pos() const
{
    return {line+1, coloum+1};
}


char Source::rewind()
{
    if (follow == &buffer_1[0]) {
        follow = &buffer_0[BUFFER_LEN - 2];
    } else if (follow == &buffer_0[0] && buffer_1[BUFFER_LEN-1] != EOF) {
    } else if (follow == &buffer_0[0] && buffer_1[BUFFER_LEN-1] == EOF) {
        follow = &buffer_1[BUFFER_LEN-2];
    }
    return *follow;
}

char Source::nextch()
{
    coloum++;
    follow++;
    switch (*follow)
    {
    case EOF:
        if (follow == &buffer_0[BUFFER_LEN-1]) {
            infile.read(buffer_1, BUFFER_LEN-1);
            int count = infile.gcount();
            buffer_1[count] = EOF;
            follow = &buffer_1[0];
        } else if(follow == &buffer_1[BUFFER_LEN-1]) {
            infile.read(buffer_0, BUFFER_LEN-1);
            int count = infile.gcount();
            buffer_0[count] = EOF;
            follow = &buffer_0[0];
        } else {
            is_end = true;
            return EOF;
        }
        break;
    case '\n':
        line++;
        coloum = 0;
        break;
    default:
        break;
    }
    return *follow;
}

std::string Source::segment()
{
    std::string str;
    char* link = start;
    while (link != follow) {
        switch (*link)
        {
        case EOF:
            if (link == &buffer_0[BUFFER_LEN-1]) {
                link = &buffer_1[0];
            } else if (link == &buffer_1[BUFFER_LEN-1]) {
                link = &buffer_0[0];
            } 
            break;
        default:
            str.push_back(*link);
            link++;
            break;
        }
    }
    start = follow;
    return str;
}
