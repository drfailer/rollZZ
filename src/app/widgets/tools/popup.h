#ifndef POPUP_HPP
#define POPUP_HPP

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>
#include <QFormLayout>

namespace Tools {

class Popup : public QWidget {
    Q_OBJECT
public:
    Popup(const QString& name);
    void add(QWidget *wgt);
    void add(const QString& description, QWidget *wgt);

signals:
    void confirm(bool);

private:
    QVBoxLayout mainLyt;
    QLabel title;
    QFormLayout bodyLyt;
    QHBoxLayout btnLyt;
    QPushButton confirmBtn;
    QPushButton cancelBtn;
};

} // end namespace Tools

#endif
