#ifndef STRINGIFIABLE_H
#define STRINGIFIABLE_H

#include <sstream>
#include "Stringifier.hpp"

/******************************************************************************/
/*                               stringifiable                                */
/******************************************************************************/

// macro for calling the constructor
#define stringifiable(...) Stringifiable(__VA_ARGS__, #__VA_ARGS__)

template<typename ...Types>
class Stringifiable {
public:
  stream::document toBSONValue() const {
    return strf.toBSONValue();
  }
  Stringifiable(Types& ...vars, std::string varsStr): strf(vars..., varsStr) { }
  virtual ~Stringifiable() {}

private:
  Stringifier<Types...> strf;
};

template<typename ...Types>
inline stream::document & operator<<(stream::document & doc, const Stringifiable<Types...>& s) {
  doc << s.toBSONValue();
  return doc;
}

#endif // STRINGIFIABLE_H
