#include "bsoncxx/builder/stream/single_context.hpp"
#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QFile>
#include "mongodb/mongodb.hpp"
#include "mongodb/Stringifiable.hpp"

class Test;
class Test2;

class Test : public Stringifiable<int,int>
{
public:
  Test(): stringifiable(x, y) { }
  Test(int _x, int _y): x(_x), y(_y), stringifiable(x, y) { }
  ~Test() = default;


  private:
  int x;
  int y;
};

class Test2 : public  Stringifiable<int,int,Test,int*>
{
public:
  Test2(): stringifiable(a, b, t, tab) { }
  Test2(int _a, int _b,Test _t,int* _tab): a(_a), b(_b),t(_t),tab(_tab), stringifiable(a, b, t, tab) { }
  ~Test2() = default;

  private:
    int a;
    int b;
    Test t;
    int* tab;

};

//op(Test)
//op(Test2)
/* opstream(Test) */
//opstream(Test2)

/******************************************************************************/
/*                                    main                                    */
/******************************************************************************/

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  MainWindow   w;
  // on peut faire un steelsheet dans le code aussi :)
  // w.setStyleSheet("#QLabel                    { color: #F2F2F2; }");
  w.show();

  Dice d;
  //try {
      MongoDB::init("rollZZ");
      //MongoDB::insertDocument(toDocument(d),"dice");
      //MongoDB::requestAll("dice");
      Dice d1 = toObject(MongoDB::requestOne("dice"));
      std::cout << "faces: " << d1.getFaces() << " & diceNumber:" << d1.getDiceNumber() << std::endl << std::endl;

      Test test(1, 2);
      Test2 test2(3,4,test, new int[10]);
      std::cout << "Start Stringify" << std::endl;
      //bsoncxx::document::value doc = bsoncxx::from_json(test2.toString());
      stream::document doc = test2.toBSONValue();
      std::cout << "End Stringify" << std::endl;
      std::cout <<  bsoncxx::to_json(doc.extract()) << std::endl;

      return 0;

  /**} catch (std::exception&) {
      std::cout << "mé !!! ça marche pas mongo :(" << std::endl;
  }**/

  return app.exec();
}
