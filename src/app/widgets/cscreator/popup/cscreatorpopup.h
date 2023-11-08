#ifndef CSCREATORPOPUP_H
#define CSCREATORPOPUP_H

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>

namespace CSCreator {

// NOTE: this class is very generic, it may be placed somewhere else (to be accessible everywhere)
class CSCreatorPopup : public QWidget
{
    Q_OBJECT
public:
    explicit CSCreatorPopup(QString name);
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

} // end namespace CSCreator

#endif // CSCREATORPOPUP_H
