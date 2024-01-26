#ifndef PART_HPP
#define PART_HPP
#include "CS/part.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

namespace CSCreator {

class SectionPopup;
class Section;

class Part : public QWidget {
    Q_OBJECT
public:
    QString getName() const { return part->getName(); }
    void setName(const QString& name) { part->setName(name); }
    Part(CS::Part *part, QWidget* parent = nullptr);
    ~Part() {}

private:
    CS::Part* part;

    /* widgets ****************************************************************/
    QVBoxLayout layout;
    QPushButton newSectionBtn;

    /* popup ******************************************************************/
    SectionPopup *sectionPopup = nullptr;

    /* private methods ********************************************************/
    void addSectionPopup();
    Section* createSection(CS::Section *section);
    void move(bool up, QWidget *wgt);
};

} // end namespace CSCreator

#endif
