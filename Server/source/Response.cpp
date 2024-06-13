#include "../headers/Response.h"


Response::Response(unsigned char* data, int len)
{
    this->data = data;
    this->len = len;
}