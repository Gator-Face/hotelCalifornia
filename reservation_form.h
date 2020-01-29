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

private:
    Ui::Reservation_Form *ui;
};
#endif // RESERVATION_FORM_H
