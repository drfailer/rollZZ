#ifndef CSCREATORSECTION_H
#define CSCREATORSECTION_H

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

enum Direction {
    UP = 0,
    DOWN = 1,
};

class CSCreatorSection : public QWidget
{
    Q_OBJECT
public:
    explicit CSCreatorSection(const QString& title, QWidget *parent = nullptr);
    void setTitle(QString newTitle) { title.setText(newTitle); }
    void add(QWidget* wgt);
    void move(Direction direction, QWidget* wgt);

signals:
    void edit();
    void remove();
    void moveUp();
    void moveDown();

private:
    QVBoxLayout mainLyt;
    QHBoxLayout headerLyt; // contains the title and the buttons
    QVBoxLayout bodyLyt;
    QLabel title;
    QHBoxLayout titleLyt;
    QHBoxLayout btnsLyt;
    QPushButton removeBtn;
    QPushButton settingsBtn;
    QPushButton moveUpBtn;
    QPushButton moveDownBtn;
    QPushButton addElementBtn;
    QList<QWidget*> content;
};

#endif // CSCREATORSECTION_H
