#ifndef RESERVATION_FORM_H
#define RESERVATION_FORM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Reservation_Form; }
QT_END_NAMESPACE

class Reservation_Form : public QMainWindow
{
    Q_OBJECT

public:
    Reservation_Form(QWidget *parent = nullptr);
    ~Reservation_Form();

private slots:

    void on_to_page_2_clicked();

    void on_queen_clicked();

    void on_king_clicked();

    void on_standard_clicked();

    void on_atruim_clicked();

    void on_back_to_1_clicked();

    void on_to_page_3_clicked();

    void on_exit_clicked();

    void on_VISA_clicked();

    void on_yes_clicked();

    void on_no_clicked();

    void on_MasterCard_clicked();

    void on_Discover_clicked();

    void on_American_Express_clicked();

    void on_stay_length_valueChanged(int arg1);

    void on_guest_num_valueChanged(int arg1);

    void SetPage2Labels();

    void Page1Complete();


    void on_dateEdit_userDateChanged(const QDate &date);

    void on_enter_name_textChanged();

    void LoadAndDisplayImages();


private:
    Ui::Reservation_Form *ui;
    QPixmap imgBed;
    QPixmap imgCar;
    QPixmap imgMoney;
    QPixmap imgThankyou;
};
#endif // RESERVATION_FORM_H
