#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox_2->addItem("Maintenance");
    ui->comboBox_2->addItem("Groceries");
    ui->comboBox_2->addItem("Bills");
    ui->comboBox_2->addItem("Miscellaneous");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int num = ui->nameLineEdit->text().toInt();
    g.setSize(num);
    ui->tableWidget->setRowCount(num);
    ui->tableWidget->setColumnCount(num);
}



void MainWindow::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    QModelIndex index = ui->tableWidget->indexFromItem(item);
    int source = index.row();
    int target = index.column();
    if (item->text() == "") {
        return;
    }
    int debt = item->text().toInt();
    if (source == target) {
        QMessageBox::information(this, "Invalid input", "A person cannot owe themselves!!!");
        item->setText("");
        return;
    }
    if (debt <= 0) {
        QMessageBox::information(this, "Invalid input", "Debt cannot be zero or negative");
        item->setText("");
        return;
    }
    g.addEdge(source, target, debt);
    ui->listWidget->addItem(new QListWidgetItem(QString::fromStdString(to_string(source) + " owes " + to_string(target) + " the amount " + to_string(debt))));
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->listWidget_2->clear();
    vector<vector<int>> result = g.MinimisedResidualGraph();
    for (vector<int> v : result) {
        string s = to_string(v[0]) + " pays " + to_string(v[1]) + " the amount " + to_string(v[2]);
        ui->listWidget_2->addItem(new QListWidgetItem(QString::fromStdString(s)));
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    g.setSize(g.getSize());
    ui->listWidget->clear();
    ui->tableWidget->clear();
    ui->listWidget_2->clear();
}


void MainWindow::on_pushButton_7_clicked()
{
    int num = ui->lineEdit->text().toInt();
    qDebug() << num;
    ui->tableWidget_3->setRowCount(num);
    ui->tableWidget_3->setColumnCount(num);
    ui->tableWidget_4->setRowCount(num);
    ui->tableWidget_4->setColumnCount(num);
    tg.setSize(num);
    ui->comboBox->addItem("Calculate by cost");
    ui->comboBox->addItem("Calculate by distance");
}


void MainWindow::on_tableWidget_3_itemChanged(QTableWidgetItem *item)
{
    if (item->text() == "") {
        return;
    }
    QModelIndex index = ui->tableWidget_3->indexFromItem(item);
    int source = index.row();
    int target = index.column();
    QString s = item->text();
    QStringList lst = s.split(" ");
    if (lst.size() != 2) {
        QMessageBox::information(this, "Invalid input", "Invalid input format.");
        item->setText("");
        return;
    }
    float dist = lst[0].toFloat();
    float cost = lst[1].toFloat();
    if (source == target) {
        QMessageBox::information(this, "Invalid input", "Cannot trace a path to the same location!!!");
        item->setText("");
        return;
    }
    if (dist <= 0 || cost <= 0) {
        QMessageBox::information(this, "Invalid input", "Distance or cost cannot be negative!!!");
        item->setText("");
        return;
    }
    tg.addEdge(source, target, dist, cost);
}


void MainWindow::on_pushButton_8_clicked()
{
    int choice = ui->comboBox->currentIndex();
    choice = max(choice, 0);
    vector<vector<float>> result = tg.MinCostAllPoints(choice);
    int s = tg.getSize();
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            ui->tableWidget_4->setItem(i, j, new QTableWidgetItem(QString::fromStdString(to_string(result[i][j]))));
        }
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    tg.setSize(tg.getSize());
    ui->tableWidget_3->clear();
    ui->tableWidget_4->clear();
}


void MainWindow::on_pushButton_12_clicked()
{
    string name = ui->lineEdit_3->text().toStdString();
    float price = ui->lineEdit_4->text().toFloat();
    if (name == "") {
        QMessageBox::information(this, "Invalid input", "Item Name cannot be none!");
        return;
    }
    if (price <= 0) {
        QMessageBox::information(this, "Invalid input", "Item price cannot be empty, zero or negative!!!");
        return;
    }
    mc.addItem(name, price);
    string s = name + " - " + to_string(price);
    ui->listWidget_5->addItem(new QListWidgetItem(QString::fromStdString(s)));
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
}


void MainWindow::on_pushButton_11_clicked()
{
    float budget = ui->lineEdit_2->text().toFloat();
    if (budget <= 0) {
        QMessageBox::information(this, "Invalid budget input", "Budget cannot be zero or negative!!!");
        return;
    }
    int count = 1;
    qDebug() << budget;
    vector<vector<pair<string, int>>> result = mc.AllCombinations(budget);
    for (auto it : result) {
        ui->listWidget_6->addItem(new QListWidgetItem(QString::fromStdString(to_string(count++) + ")")));
        for (pair<string, int> p : it) {
            string s = "   " + p.first + " - " + to_string(p.second);
            ui->listWidget_6->addItem(new QListWidgetItem(QString::fromStdString(s)));
        }
    }
}


void MainWindow::on_pushButton_13_clicked()
{
    mc.Clear();
    ui->listWidget_5->clear();
    ui->listWidget_6->clear();
    ui->lineEdit_2->setText("");
}


void MainWindow::on_pushButton_14_clicked()
{
    string desc = ui->lineEdit_5->text().toStdString();
    string cat = ui->comboBox_2->currentText().toStdString();
    float amount = ui->lineEdit_7->text().toFloat();
    if (desc == "" || cat == "") {
        QMessageBox::information(this, "Invalid input", "Description or category cannot be empty!!!");
        return;
    }
    if (amount <= 0) {
        QMessageBox::information(this, "Invalid input", "Amount of transaction cannot be zero or negative!!!");
        return;
    }
    d.addTransaction(desc, cat, amount);
    string s = cat + " : " + desc + " - " + to_string(amount);
    ui->listWidget_7->addItem(new QListWidgetItem(QString::fromStdString(s)));
    unordered_map<string, float> result = d.getDistribution();
    float total = 0;
    for (auto it : result) {
        total += it.second;
    }
    ui->progressBar->setValue(result["Maintenance"]/total * 100);
    ui->progressBar_2->setValue(result["Groceries"]/total * 100);
    ui->progressBar_3->setValue(result["Bills"]/total * 100);
    ui->progressBar_4->setValue(result["Miscellaneous"]/total * 100);
}


void MainWindow::on_pushButton_18_clicked()
{
    d.loadConfig();
    ui->listWidget_7->clear();
    unordered_map<string, float> result = d.getDistribution();
    float total = 0;
    for (auto it : result) {
        total += it.second;
    }
    ui->progressBar->setValue(result["Maintenance"]/total * 100);
    ui->progressBar_2->setValue(result["Groceries"]/total * 100);
    ui->progressBar_3->setValue(result["Bills"]/total * 100);
    ui->progressBar_4->setValue(result["Miscellaneous"]/total * 100);
}


void MainWindow::on_pushButton_15_clicked()
{
    ui->listWidget_7->clear();
    ui->progressBar->setValue(25);
    ui->progressBar_2->setValue(25);
    ui->progressBar_3->setValue(25);
    ui->progressBar_4->setValue(25);
    d.Clear();
}


void MainWindow::on_pushButton_19_clicked()
{
    d.save();
    QMessageBox::information(this, "Current config saved", "Distribution of expenses saved.");
}



void MainWindow::on_pushButton_20_clicked()
{
    g.loadConfig();
}


void MainWindow::on_pushButton_21_clicked()
{
    g.save();
    QMessageBox::information(this, "Current config saved", "Distribution of expenses saved.");
}

