#include "reservation_form.h"
#include "ui_reservation_form.h"
#include "ResortReservationRecord.h"
#include<QMessageBox>


ResortReservationRecord currentRecord = ResortReservationRecord();

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
    QString customerName = ui->enter_name->toPlainText(); // Gets text from textbox
    currentRecord.SetCustomersName(customerName.toStdString());

    ui -> stackedWidget -> setCurrentIndex(1);
}

void Reservation_Form::on_queen_clicked()
{
    bool isStandardChecked = ui -> standard -> isChecked();
    bool isAtruimChecked = ui -> atruim -> isChecked();
    bool isYesChecked = ui -> yes -> isChecked();

    if (isStandardChecked) {
        currentRecord.SetRoomType(1);
    } else if (isAtruimChecked) {
        currentRecord.SetRoomType(2);
    }
	
    ui -> guest_num -> setMaximum(4);
    ui -> total_sum -> setText(QString::number(currentRecord.CalculateCosts()));
}

void Reservation_Form::on_king_clicked()
{
    bool isStandardChecked = ui -> standard -> isChecked();
    bool isAtruimChecked = ui -> atruim -> isChecked();
    bool isYesChecked = ui -> yes -> isChecked();

    if (isStandardChecked) {
        currentRecord.SetRoomType(3);
    } else if (isAtruimChecked) {
        currentRecord.SetRoomType(4);
    }

    ui -> guest_num -> setMaximum(3);
    ui -> total_sum -> setText(QString::number(currentRecord.CalculateCosts()));

}

void Reservation_Form::on_standard_clicked()
{
    bool isQueenChecked = ui -> queen -> isChecked();
    bool isKingChecked = ui -> king -> isChecked();
    bool isYesChecked = ui -> yes -> isChecked();
    int guests = 0;

    if (isQueenChecked) {
        currentRecord.SetRoomType(1);
        guests = 4;
    } else if (isKingChecked) {
        currentRecord.SetRoomType(3);
        guests = 3;
    }

    ui -> guest_num -> setMaximum(guests);
    ui -> total_sum -> setText(QString::number(currentRecord.CalculateCosts()));
}

void Reservation_Form::on_atruim_clicked()
{
    bool isQueenChecked = ui -> queen -> isChecked();
    bool isKingChecked = ui -> king -> isChecked();
    bool isYesChecked = ui -> yes -> isChecked();
    int guests = 0;

    if (isQueenChecked) {
        currentRecord.SetRoomType(2);
        guests = 4;
    } else if (isKingChecked) {
        currentRecord.SetRoomType(4);
        guests = 3;
    }

    ui -> guest_num -> setMaximum(guests);
    ui -> total_sum -> setText(QString::number(currentRecord.CalculateCosts()));
}

void Reservation_Form::on_yes_clicked()
{
    currentRecord.SetParkingNeeded(true);
    ui -> total_sum -> setText(QString::number(currentRecord.CalculateCosts()));
}

void Reservation_Form::on_no_clicked()
{
    currentRecord.SetParkingNeeded(false);
    ui -> total_sum -> setText(QString::number(currentRecord.CalculateCosts()));
}

void Reservation_Form::on_stay_length_valueChanged(int arg1)
{
    int val = ui->stay_length->value();
    currentRecord.SetNightsStayed(val);

    ui -> total_sum -> setText(QString::number(currentRecord.CalculateCosts()));

}

void Reservation_Form::on_guest_num_valueChanged(int arg1)
{
    int val = ui->guest_num->value();
    currentRecord.SetGuests(val);
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
