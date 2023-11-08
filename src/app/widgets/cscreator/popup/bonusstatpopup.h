#ifndef BONUSSTATPOPUP_H
#define BONUSSTATPOPUP_H

#include "basicstatpopup.h"

namespace CSCreator {

class BonusStatPopup : public BasicStatPopup
{
    Q_OBJECT
public:
    BonusStatPopup();

private:
    // TODO: it would be greate if we could make the bonus calculus configurable
    // TODO: need something else ?
};

} // end namespace CSCreator

#endif // BONUSSTATPOPUP_H
