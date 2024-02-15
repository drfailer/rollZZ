#ifndef CS_COMPONENTCONVERTOR_HPP
#define CS_COMPONENTCONVERTOR_HPP
#include "attacks.h"
#include "basicstat.h"
#include "bonusstat.h"
#include "component.h"
#include "descriptor.h"
#include "equipment.h"
#include "liststat.h"
#include "tools/qtconvertor.h"
#include "serializer.hpp"

struct ComponentConvertor {
    // NOTE: this shouldn't be like this
    deserialize_custom_type(QString, const std::string &str) {
        return QtConvertor::deserialize<QString>(str);
    }

    static inline std::string serialize(const QString &elt) {
        return QtConvertor::serialize(elt);
    }

    DESERIALIZE_POLYMORPHIC(
            CS::Component,
            CS::Equipment,
            CS::Attacks,
            CS::Descriptor,
            CS::BasicStat,
            CS::BonusStat,
            CS::ListStat);

    CONVERTOR;
};

#endif
