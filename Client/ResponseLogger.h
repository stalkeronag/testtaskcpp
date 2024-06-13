#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtWidgets"
#include <iostream>
class ResponseLogger
{
private:
    QTextBrowser* browser;
public:
    ResponseLogger();
    ResponseLogger(QTextBrowser* browser);
    void Log(unsigned char* message, int len);
    void LogError(unsigned char* message, int len);
    void LogReadAndWriteResponse(unsigned char* message, int len);
};
