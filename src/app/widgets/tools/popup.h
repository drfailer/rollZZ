#ifndef POPUP_HPP
#define POPUP_HPP

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>

class Popup : public QWidget {
    Q_OBJECT
public:
    Popup(const QString& name);
    void add(QWidget *wdgt);

signals:
    void confirm(bool);

private:
    QVBoxLayout mainLyt;
    QLabel title;
    QVBoxLayout bodyLyt;
    QHBoxLayout btnLyt;
    QPushButton confirmBtn;
    QPushButton cancelBtn;
};

#endif
