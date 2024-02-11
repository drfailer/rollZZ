#include "cs.h"

namespace CS {

CS::~CS() {
    clearParts();
}

void CS::clearParts() {
    for (Part *part : parts) {
        delete part;
    }
    parts.clear();
}

}; // end namespace CS
