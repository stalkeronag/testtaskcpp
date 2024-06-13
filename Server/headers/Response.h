#include <iostream>

class Response
{
public:
    unsigned char* data;
    int len; 
public:
    Response(unsigned char* data, int len);
};