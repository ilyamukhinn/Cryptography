#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "atbash.h"
#include "caesar.h"
#include "scitula.h"
#include "polybius_square.h"
#include "vigenere.h"
#include "vernam.h"

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

void MainWindow::on_ChoosepushButton_clicked()
{
    if(ui->AlgorithmcomboBox->currentText() == "Choose...")
    {
        QErrorMessage errorMessage;
        errorMessage.showMessage("Please choose an algorithm!");
        errorMessage.exec();
        return;
    }

    if(ui->AlgorithmcomboBox->currentText() == "Atbash")
    {
        Atbash *W = new Atbash;
        W->exec();
        delete W;
    }
    else if(ui->AlgorithmcomboBox->currentText() == "Caesar")
    {
        Caesar *W = new Caesar;
        W->exec();
        delete W;
    }
    else if(ui->AlgorithmcomboBox->currentText() == "Scitula")
    {
        Scitula *W = new Scitula;
        W->exec();
        delete W;
    }
    else if(ui->AlgorithmcomboBox->currentText() == "Polybius square")
    {
        Polybius_square *W = new Polybius_square;
        W->exec();
        delete W;
    }
    else if(ui->AlgorithmcomboBox->currentText() == "Vigenere")
    {
        Vigenere *W = new Vigenere;
        W->exec();
        delete W;
    }
    else if(ui->AlgorithmcomboBox->currentText() == "Vernam")
    {
        Vernam *W = new Vernam;
        W->exec();
        delete W;
    }
}

void MainWindow::on_ExitpushButton_clicked()
{
    this->close();
}

