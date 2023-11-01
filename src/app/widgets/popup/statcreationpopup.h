#ifndef STATCREATIONPOPUP_H
#define STATCREATIONPOPUP_H

#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QWidget>

class StatCreationPopup : public QWidget
{
    Q_OBJECT
public:
    explicit StatCreationPopup(QWidget *parent = nullptr);
    QString getName() const { return nameEdit.text(); }
    int getValue() const { return valueEdit.value(); }

signals:
    void confirm();

private:
    QVBoxLayout layout;
    QPushButton confirmBtn;
    QLineEdit nameEdit;
    QSpinBox valueEdit;
};

#endif // STATCREATIONPOPUP_H
