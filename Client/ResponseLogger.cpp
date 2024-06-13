#include "ResponseLogger.h"

ResponseLogger::ResponseLogger(QTextBrowser* browser)
{
    this->browser = browser;
}

ResponseLogger::ResponseLogger()
{

}
void ResponseLogger::Log(unsigned char* message, int len)
{
    unsigned char command = message[0];

    switch (command)
    {
        case 0x04:
            LogReadAndWriteResponse(message, len);
            break;
        case 0x06:
            LogReadAndWriteResponse(message, len);
            break;
        case 0x0A:
            LogError(message, len);
            break;
        default:
            LogReadAndWriteResponse(message, len);
            break;
    }
}

void ResponseLogger::LogError(unsigned char* message, int len)
{
    std::string result = "RESPONSE";
    result = result + " Command:" + std::to_string((int)message[0]);
    result = result + " code error:" + std::to_string((int)message[1]);
    result = result + " " + std::to_string((int)message[2]);
    browser->append(QString::fromUtf8(result.c_str()));
}

void ResponseLogger::LogReadAndWriteResponse(unsigned char* message, int len)
{
    std::string result = "RESPONSE";
    result = result + " Command:" + std::to_string((int)message[0]);
    result = result + " number:" + std::to_string((int)message[1]);
    result = result + " " + std::to_string((int)message[2]);
    result = result + " register message:";
    for (int i = 3; i < len; i++)
    {
        result = result + std::to_string((int)message[i]) + " ";
    }
    browser->append(QString::fromUtf8(result.c_str()));
}
