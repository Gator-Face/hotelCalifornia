#include "reservation_form.h"
#include "ui_reservation_form.h"

#include<QMessageBox>

double total_cost = 0.00;
const double parking_fee = 12.75;

Reservation_Form::Reservation_Form(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Reservation_Form)
{
    ui->setupUi(this);
    ui -> dateEdit -> setDate(QDate::currentDate());
    ui -> total_sum -> setText(QString::number(0));
    ui -> stay_length -> setRange(1, 7);
    ui -> guest_num -> setMinimum(1);

}

Reservation_Form::~Reservation_Form()
{
    delete ui;
}

void Reservation_Form::on_to_page_2_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(1);
}

void Reservation_Form::on_queen_clicked()
{
    bool isStandardChecked = ui -> standard -> isChecked();
    bool isAtruimChecked = ui -> atruim -> isChecked();
    bool isYesChecked = ui -> yes -> isChecked();

    if (isStandardChecked) {
        total_cost = 284.00;
    } else if (isAtruimChecked) {
        total_cost = 325.00;
    }
    if (isYesChecked) {
        total_cost += parking_fee;
    }
    ui -> total_sum -> setText(QString::number(total_cost));
    ui -> guest_num -> setMaximum(4);
}

void Reservation_Form::on_king_clicked()
{
    bool isStandardChecked = ui -> standard -> isChecked();
    bool isAtruimChecked = ui -> atruim -> isChecked();
    bool isYesChecked = ui -> yes -> isChecked();

    if (isStandardChecked) {
        total_cost = 290.00;
    } else if (isAtruimChecked) {
        total_cost = 350.00;
    }
    if (isYesChecked) {
        total_cost += parking_fee;
    }
    ui -> total_sum -> setText(QString::number(total_cost));
    ui -> guest_num -> setMaximum(3);
}

void Reservation_Form::on_standard_clicked()
{
    bool isQueenChecked = ui -> queen -> isChecked();
    bool isKingChecked = ui -> king -> isChecked();
    bool isYesChecked = ui -> yes -> isChecked();
    int guests = 0;

    if (isQueenChecked) {
        total_cost = 284.00;
        guests = 4;
    } else if (isKingChecked) {
        total_cost = 290.00;
        guests = 3;
    }
    if (isYesChecked) {
        total_cost += parking_fee;
    }
    ui -> total_sum -> setText(QString::number(total_cost));
    ui -> guest_num -> setMaximum(guests);
}

void Reservation_Form::on_atruim_clicked()
{
    bool isQueenChecked = ui -> queen -> isChecked();
    bool isKingChecked = ui -> king -> isChecked();
    bool isYesChecked = ui -> yes -> isChecked();
    int guests = 0;

    if (isQueenChecked) {
        total_cost = 325.00;
        guests = 4;
    } else if (isKingChecked) {
        total_cost = 350.00;
        guests = 3;
    }
    if (isYesChecked) {
        total_cost += parking_fee;
    }
    ui -> total_sum -> setText(QString::number(total_cost));
    ui -> guest_num -> setMaximum(guests);
}

void Reservation_Form::on_yes_clicked()
{
    double extra_cost = total_cost + parking_fee;
    ui -> total_sum -> setText(QString::number(extra_cost));
}

void Reservation_Form::on_no_clicked()
{
    ui -> total_sum -> setText(QString::number(total_cost));
}

void Reservation_Form::on_back_to_1_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(0);
}

void Reservation_Form::on_to_page_3_clicked()
{
    QMessageBox processed_msg;
    processed_msg.setText("transaction processed successfully");
    processed_msg.exec();
    ui -> stackedWidget -> setCurrentIndex(2);
}

void Reservation_Form::on_exit_clicked()
{
    QApplication::quit();
}

void Reservation_Form::on_VISA_clicked()
{
    ui -> card_num -> setValidator( new QIntValidator(0, 9, this) );
    ui -> card_num -> setInputMask("9999-9999-9999-9999");
    ui -> card_num -> setMaxLength(16);

    ui -> exp_date -> setValidator( new QIntValidator(0, 9, this) );
    ui -> exp_date -> setInputMask("99/9999");
    ui -> exp_date -> setMaxLength(6);
}


void Reservation_Form::on_MasterCard_clicked()
{
    ui -> card_num -> setValidator( new QIntValidator(0, 9, this) );
    ui -> card_num -> setInputMask("9999 9999 9999 9999");
    ui -> card_num -> setMaxLength(16);

    ui -> exp_date -> setValidator( new QIntValidator(0, 9, this) );
    ui -> exp_date -> setInputMask("99/9999");
    ui -> exp_date -> setMaxLength(6);
}

void Reservation_Form::on_Discover_clicked()
{
    ui -> card_num -> setValidator( new QIntValidator(0, 9, this) );
    ui -> card_num -> setInputMask("9999 9999 9999 9999");
    ui -> card_num -> setMaxLength(16);

    ui -> exp_date -> setValidator( new QIntValidator(0, 9, this) );
    ui -> exp_date -> setInputMask("99/9999");
    ui -> exp_date -> setMaxLength(6);
}

void Reservation_Form::on_American_Express_clicked()
{
    ui -> card_num -> setValidator( new QIntValidator(0, 9, this) );
    ui -> card_num -> setInputMask("9999 999999 99999");
    ui -> card_num -> setMaxLength(15);

    ui -> exp_date -> setValidator( new QIntValidator(0, 9, this) );
    ui -> exp_date -> setInputMask("99/9999");
    ui -> exp_date -> setMaxLength(6);
}
