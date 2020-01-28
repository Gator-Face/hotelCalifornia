#include "reservation_form.h"
#include "ui_reservation_form.h"

double total_cost = 0.00;
const double parking_fee = 12.75;

Reservation_Form::Reservation_Form(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Reservation_Form)
{
    ui->setupUi(this);
    ui -> dateEdit -> setDate(QDate::currentDate());
    ui -> total_sum -> setText(QString::number(0));
    ui -> stay_length -> setMaximum(7);

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

    if (isStandardChecked) {
        total_cost = 284.00;
    } else if (isAtruimChecked) {
        total_cost = 325.00;
    }
    ui -> total_sum -> setText(QString::number(total_cost));
    ui -> guest_num -> setRange(1, 4);
}

void Reservation_Form::on_king_clicked()
{
    bool isStandardChecked = ui -> standard -> isChecked();
    bool isAtruimChecked = ui -> atruim -> isChecked();

    if (isStandardChecked) {
        total_cost = 290.00;
    } else if (isAtruimChecked) {
        total_cost = 350.00;
    }
    ui -> total_sum -> setText(QString::number(total_cost));
    ui -> guest_num -> setRange(1, 3);
}

void Reservation_Form::on_standard_clicked()
{
    bool isQueenChecked = ui -> queen -> isChecked();
    bool isKingChecked = ui -> king -> isChecked();
    int guests = 0;

    if (isQueenChecked) {
        total_cost = 284.00;
        guests = 4;
    } else if (isKingChecked) {
        total_cost = 290.00;
        guests = 3;
    }
    ui -> total_sum -> setText(QString::number(total_cost));
    ui -> guest_num -> setRange(1, guests);
}

void Reservation_Form::on_atruim_clicked()
{
    bool isQueenChecked = ui -> queen -> isChecked();
    bool isKingChecked = ui -> king -> isChecked();
    int guests = 0;

    if (isQueenChecked) {
        total_cost = 325.00;
        guests = 4;
    } else if (isKingChecked) {
        total_cost = 350.00;
        guests = 3;
    }
    ui -> total_sum -> setText(QString::number(total_cost));
    ui -> guest_num -> setRange(1, guests);
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
