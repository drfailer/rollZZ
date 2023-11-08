#ifndef LISTSTATPOPUP_H
#define LISTSTATPOPUP_H

#include "cscreatorpopup.h"

namespace CSCreator {

class ListStatPopup : public CSCreatorPopup
{
    Q_OBJECT
public:
    ListStatPopup();

private:
    // TODO: add a widget with a QLineEdit and a QComboBox and a + button to add
    //       the name and the BonusStat that corresponds to the added skill.
    QLabel todo;
};

} // end namespace CSCreator

#endif // LISTSTATPOPUP_H
