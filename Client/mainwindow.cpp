
#include "BuilderMail.h"
#include  "Client.h"
#include "vector"
#define SERVER_IP "127.0.0.1"
#define PORT 5555

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    std::string number = ui->lineEdit->text().toStdString();
    int numberInt = std::stoi(number);
    std::string bytes = ui->lineEdit_2->text().toStdString();
    std::vector<unsigned char> chars;
    std::string temp = "";
    for (int i = 0; i < bytes.size();i++)
    {
        if (bytes[i] != ' ')
        {
            int j = i;
            while(j<bytes.size() && bytes[j] != ' ')
            {
                temp = temp + bytes[j];
                j++;
            }
            i = j;
            unsigned char tempChar = std::stoi(temp);
            temp  = "";
            chars.push_back(tempChar);
        }
    }
    ResponseLogger logger = ResponseLogger(ui->textBrowser);
    Client client = Client(PORT, SERVER_IP, logger);
    client.Connect();
    BuilderMail builder = BuilderMail();
    builder.AddStart();
    builder.AddAdrSource(60);
    builder.AddAdrDestination(123);
    builder.AddStop();
    int lenData = 3 + chars.size();
    unsigned char* data = new unsigned char[lenData];
    data[0] = 5;
    data[1] = 0;
    data[2] = numberInt;
    for (int i = 3; i < lenData; i++)
    {
        data[i] = chars[i - 3];
    }
    builder.AddData(data,lenData);
    unsigned char * res = builder.Build();
    int len = builder.GetMailLen();
    client.Send(res, builder.GetMailLen());
    client.Receive();
    client.Close();
}


void MainWindow::on_pushButton_2_clicked()
{
    int* indexs = new int[7] {0,6,7,9,11,12,13};
    ResponseLogger logger = ResponseLogger(ui->textBrowser);
    ui->textBrowser->clear();
    for (int i = 0 ;i < 7; i++)
    {
        Client client = Client(PORT, SERVER_IP, logger);
        client.Connect();
        BuilderMail builder = BuilderMail();
        builder.AddStart();
        builder.AddAdrSource(60);
        builder.AddAdrDestination(123);
        builder.AddStop();
        unsigned char* data = new unsigned char[3];
        data[0] = 3;
        data[1] = 0;
        data[2] = indexs[i];
        builder.AddData(data,3);
        unsigned char * res = builder.Build();
        int len = builder.GetMailLen();
        client.Send(res, builder.GetMailLen());
        client.Receive();
        client.Close();
    }

}

