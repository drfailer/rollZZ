#include "cs.h"

namespace CS {

CS::~CS() {
    for (Part *part : parts) {
        delete part;
    }
    parts.clear();
}

}; // end namespace CS
