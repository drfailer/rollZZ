#ifndef QTCONVERTOR_HPP
#define QTCONVERTOR_HPP
#include "convertor.hpp"
#include <QString>
#include "descriptortypes.h"

// TODO rename
struct QtConvertor {
    deserialize_custom_type(CS::DescriptorTypes, const std::string& str) {
        std::istringstream iss(str);
        int out;
        iss >> out;
        return (CS::DescriptorTypes) out;
    }

    serialize_custom_type(CS::DescriptorTypes type) {
        std::ostringstream oss;
        oss << type;
        return oss.str();
    }

    deserialize_custom_type(QString, const std::string& str) {
        return QString(str.substr(1, str.size() - 1).c_str());
    }

    static inline std::string serialize(const QString &elt) {
        std::ostringstream oss;
        oss << "\"" << elt.toStdString() << "\"";
        return oss.str();
    }

    CONVERTOR;
};

#endif
