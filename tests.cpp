#include <boost/test/unit_test.hpp>

#include "operator.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(CurrencyTests)

BOOST_AUTO_TEST_CASE(comparator)
{
  Currency c1, c2;
  bool i=0;
  if (c1==c2) i=1;
  BOOST_CHECK_EQUAL(i, 1);
}

BOOST_AUTO_TEST_CASE(assignment)
{
  Currency c1 = Currency ("euro", "EUR", 250);
  Currency c2=c1;
  bool i=0;
  if (c1==c2) i=1;
  BOOST_CHECK_EQUAL(i, 1);
}

BOOST_AUTO_TEST_CASE(new_multiplication)
{
  Currency c1, c2 = Currency ("euro", "EUR", 10);
  c1=c2*2.5;
  BOOST_CHECK_EQUAL(c1.exchange, 25);
}

BOOST_AUTO_TEST_CASE(add)
{
  Currency c = Currency ("euro", "EUR", 10);
  c+=5;
  BOOST_CHECK_EQUAL(c.exchange, 15);
}

BOOST_AUTO_TEST_CASE(subtraction)
{
  Currency c=Currency ("euro", "EUR", 10);
  c-=5;
  BOOST_CHECK_EQUAL(c.exchange, 5);
}

BOOST_AUTO_TEST_CASE(multiplication)
{
  Currency c=Currency ("euro", "EUR", 10);
  c*=2.5;
  BOOST_CHECK_EQUAL(c.exchange, 25);
}

//BOOST_AUTO_TEST_SUITE(CurrencyTests)


BOOST_AUTO_TEST_CASE(comparator)
{
  Wallet w1, w2;
  bool i=0;
  if (w1==w2) i=1;
  BOOST_CHECK_EQUAL(i, 1);
}

BOOST_AUTO_TEST_CASE(assignment)
{
  Currency c = Currency ("euro", "EUR", 250);
  Wallet w1 = (c, 100);
  Wallet w2 = w1;
  bool i=0;
  if (w1==w2) i=1;
  BOOST_CHECK_EQUAL(i, 1);
}

BOOST_AUTO_TEST_CASE(add)
{
  Wallet w1, w2, w3;
  w1=w2+w3;
  BOOST_CHECK_EQUAL(w1.value, 200);
}

BOOST_AUTO_TEST_CASE(subtraction)
{
  Wallet w1, w2, w3;
  w1=w2-w3;
  BOOST_CHECK_EQUAL(w1.value, 0);
}

BOOST_AUTO_TEST_CASE(not_new_add)
{
  Wallet w1, w2;
  w1+=w2;
  BOOST_CHECK_EQUAL(w1.value, 200);
}

BOOST_AUTO_TEST_CASE(not_new_subtraction)
{
  Wallet w1, w2;
  w1-=w2;
  BOOST_CHECK_EQUAL(w1.value, 0);
}

BOOST_AUTO_TEST_SUITE_END()
