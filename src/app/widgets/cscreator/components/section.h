#ifndef CSCREATORSECTION_H
#define CSCREATORSECTION_H

#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QFrame>

namespace CSCreator {

class SectionPopup;
class BasicStatPopup;
class BonusStatPopup;
class ListStatPopup;
class DescriptorPopup;
class EquipmentPopup;
class AttacksPopup;

enum ComponentTypes {
    None = 0,
    BasicStat = 1,
    BonusStat = 2,
    ListStat = 3,
    Descriptor = 4,
    Equipment = 5,
    Attacks = 6,
};

class Section : public QFrame
{
    Q_OBJECT
public:
    explicit Section(const QString& title, QWidget *parent = nullptr);
    ~Section();
    void setTitle(QString newTitle) { title.setText(newTitle); }
    void add(QWidget* wgt);
    void move(bool up, QWidget* wgt);

    // TODO: write accessors
    QString getTitle() const { return title.text(); }
    void setTitle(const QString& newTitle) { title.setText(newTitle); }

signals:
    void remove();
    void moveUp();
    void moveDown();

private slots:
    void settingsPopup();
    void addElement(int element);
    void addBasicStat();
    void addBonusStat();
    void addListStat();
    void addDescriptor();
    void addEquipment();
    void addAttacks();

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
    QComboBox addElementBtn;
    QList<QWidget*> content;

    /* popups ******************************************************************/
    SectionPopup *sectionPopup = nullptr;
    BasicStatPopup *basicStatPopup = nullptr;
    BonusStatPopup *bonusStatPopup = nullptr;
    ListStatPopup *listStatPopup = nullptr;
    DescriptorPopup *descriptorPopup = nullptr;
    EquipmentPopup *equipmentPopup = nullptr;
    AttacksPopup *attacksPopup = nullptr;
};

} // end namespace CSCrator

#endif // CSCREATORSECTION_H
