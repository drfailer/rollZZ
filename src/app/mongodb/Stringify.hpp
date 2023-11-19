#ifndef STRINGIFY_HPP
#define STRINGIFY_HPP

#include <bsoncxx/builder/concatenate.hpp>
#include <bsoncxx/builder/stream/array.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/json.hpp>
#include <iostream>
#include <type_traits>

#define genStringifier(...) Stringify<__VA_ARGS__> strf_;
#define genStringifierList(...) strf_(__VA_ARGS__, #__VA_ARGS__)
// #define genToString() std::string toString() {return strf_.toString(); }
// #define op(__CLASS__) std::ostream& operator<<(std::ostream& os, __CLASS__&
// c) {os << c.toString(); return os;} #define opdef(__CLASS__)  std::ostream&
// operator<<(std::ostream& os,__CLASS__& c);

/******************************************************************************/
/*                           stringify from JSON                              */
/******************************************************************************/

/**template<typename ...Types>
class Stringify
{
public:
  Stringify(Types& ...args, std::string idsStr): ptrs(args...) {
    // get ids
    std::cout << idsStr << std::endl;
    size_t start = 0;
    while (start < idsStr.size()) {
      size_t end = idsStr.find(",",start);

      ids.push_back(idsStr.substr(start,end-start));
      while (end < idsStr.size() && (idsStr[end] == ' ' || idsStr[end] == ','))
++end; // skip spaces and comas start = end;
    }
  }
  ~Stringify() = default;

  template<typename H>
  std::string toString_(int i, H& head) {
    std::ostringstream ss;
    ss << '"' <<ids[i] << "\" : " << head << " ";
    return ss.str();
  }

  template<typename H, typename ...T>
  std::string toString_(int i, H& head, T& ...ags) {
    std::ostringstream ss;
    ss << '"' << ids[i] << "\":" <<  head << ", " << toString_(i+1, ags...);
    return ss.str();
  }

  template<typename T, size_t... Is>
  std::string extrTuple(const T& t, std::index_sequence<Is...>) {
    std::cout << "extr Tuple start" <<std::endl;
    std::ostringstream ss;
    ss << "{ " << toString_(0, std::get<Is>(t)...) <<  "}";
    std::cout << ss.str() <<std::endl;
    std::cout << "extr Tuple end" <<std::endl;
    return ss.str();
  }

  std::string toString(){
    std::cout << "To string start" <<std::endl;
    return extrTuple(ptrs, std::make_index_sequence<sizeof...(Types)>());
  }

private:
  std::tuple<Types&...> ptrs;
  std::vector<std::string> ids;
};**/

/******************************************************************************/
/*                          stringify with stream                             */
/******************************************************************************/

namespace stream = bsoncxx::builder::stream;
/* namespace document = bsoncxx::document; */

/* using bsoncxx::builder::basic::kvp; */

#define genToBSONValue()                                                       \
  stream::document toBSONValue() const override { return strf_.toBSONValue(); }
/* #define opstream(__CLASS__)                                                    \ */
/*   stream::document &operator<<(stream::document &os, const __CLASS__ &c) {     \ */
/*     os << bsoncxx::builder::concatenate(c.toBSONValue().view());               \ */
/*     return os;                                                                 \ */
/*   } */
/* #define opstreamdef(__CLASS__)                                                 \ */
/*   stream::document &operator<<(stream::document &os, const __CLASS__ &c); */

inline stream::document &operator<<(stream::document &os, int *i) {
  os << "[" << i[0] << "]";
  return os;
}

class Serialisable {
public:
    virtual ~Serialisable() {};
    virtual stream::document toBSONValue() const = 0;
};

template <class T>
using type_base_t = typename std::remove_reference<typename std::remove_const<T>::type>::type;

template <class T1,class T2>
using meme_type_t = std::is_same< type_base_t<T1>,type_base_t<T2> >;

template<class Base, class Derived>
using based_of_t = std::is_base_of<type_base_t<Base>, type_base_t<Derived>>;

template <typename... Types> class Stringify {
public:
    Stringify(Types &...args, std::string idsStr) : ptrs(args...) {
        // get ids
        std::cout << idsStr << std::endl;
        size_t start = 0;
        while (start < idsStr.size()) {
            size_t end = idsStr.find(",", start);

            ids.push_back(idsStr.substr(start, end - start));
            while (end < idsStr.size() && (idsStr[end] == ' ' || idsStr[end] == ','))
                ++end; // skip spaces and comas
            start = end;
        }
    }
    ~Stringify() = default;

    void toBSONValue_(stream::document &doc, int i, int *tab) const {
        doc << ids[i] << tab[0];
    }
    template <typename... T>
    void toBSONValue_(stream::document &doc, int i, const Serialisable &head, T &...ags) const {
        doc << ids[i] << bsoncxx::builder::concatenate(head.toBSONValue().view());
        toBSONValue_(doc, i + 1, ags...);
    }

    void toBSONValue_(stream::document &doc, int i, const Serialisable &head) const {
        doc << ids[i] << bsoncxx::builder::concatenate(head.toBSONValue().view());
    }

    template <typename H, typename... T,
             class = typename std::enable_if<!based_of_t<Serialisable, H>::value>::type>
    void toBSONValue_(stream::document &doc, int i, const H &head, T &...ags) const {
        doc << ids[i] << head;
        toBSONValue_(doc, i + 1, ags...);
    }

    template <typename H,
             class = typename std::enable_if<!based_of_t<Serialisable, H>::value>::type>
    void toBSONValue_(stream::document &doc, int i, const H &head) const {
        doc << ids[i] << head;
    }

    template <typename T, size_t... Is>
    void extrTuple(stream::document &doc, const T &t,
            std::index_sequence<Is...>) const {
        std::cout << "extr Tuple start" << std::endl;
        toBSONValue_(doc, 0, std::get<Is>(t)...);
        std::cout << "extr Tuple end" << std::endl;
    }

    stream::document toBSONValue() const {
        stream::document doc;
        extrTuple(doc, ptrs, std::make_index_sequence<sizeof...(Types)>());
        return doc;
    }

private:
    std::tuple<Types &...>   ptrs;
    std::vector<std::string> ids;
};

#endif // STRINGIFY_HPP
