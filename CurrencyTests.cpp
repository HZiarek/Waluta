#include <boost/test/unit_test.hpp>

#include "WalletOperator.h"
#include "CurrencyOperator.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(CurrencyTests)

BOOST_AUTO_TEST_CASE(comparator)
{
  const Currency c1, c2;

  BOOST_CHECK (c1==c2);
}

BOOST_AUTO_TEST_CASE(assignment)
{
  const Currency c1 = Currency ("euro", "EUR", 250);
  const Currency c2=c1;

  BOOST_CHECK_EQUAL(c2==c1);
}

BOOST_AUTO_TEST_CASE(new_multiplication)
{
  const Currency c1, c2 = Currency ("euro", "EUR", 10);

  c1=c2*2.5;

  BOOST_CHECK_EQUAL(c1.exchange, 25);
}

BOOST_AUTO_TEST_CASE(add)
{
  const Currency c = Currency ("euro", "EUR", 10);

  c+=5;

  BOOST_CHECK_EQUAL(c.exchange, 15);
}

BOOST_AUTO_TEST_CASE(subtraction)
{
  const Currency c=Currency ("euro", "EUR", 10);

  c-=5;

  BOOST_CHECK_EQUAL(c.exchange, 5);
}

BOOST_AUTO_TEST_CASE(multiplication)
{
  const Currency c=Currency ("euro", "EUR", 10);

  c*=2.5;

  BOOST_CHECK_EQUAL(c.exchange, 25);
}

BOOST_AUTO_TEST_SUITE_END()
