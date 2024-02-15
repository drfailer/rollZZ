#ifndef COMPONENTCONVERTOR_H
#define COMPONENTCONVERTOR_H

#ifndef CS_COMPONENTCONVERTOR_HPP
#define CS_COMPONENTCONVERTOR_HPP
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

  DESERIALIZE_POLYMORPHIC();

  CONVERTOR;
};

#endif

#endif // COMPONENTCONVERTOR_H
