#include <boost/test/unit_test.hpp>

#include "Wallet.h"
#include "Currency.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(CurrencyTests)

BOOST_AUTO_TEST_CASE(comparator)
{
  const Currency c2;
  Currency c1;

  BOOST_CHECK (c1==c2);
}

BOOST_AUTO_TEST_CASE(assignment)
{
  const Currency c1 = Currency ("euro", "EUR", 250);
  Currency c2=c1;

  BOOST_CHECK (c2==c1);
}

BOOST_AUTO_TEST_CASE(new_multiplication)
{
  Currency c1, c2 = Currency ("euro", "EUR", 10);

  c1=c2*2.5;

  BOOST_CHECK_EQUAL(c1.get_exchange(), 25);
}

BOOST_AUTO_TEST_CASE(add)
{
  Currency c = Currency ("euro", "EUR", 10);

  c+=5;

  BOOST_CHECK_EQUAL(c.get_exchange(), 15);
}

BOOST_AUTO_TEST_CASE(subtraction)
{
  Currency c=Currency ("euro", "EUR", 10);

  c-=5;

  BOOST_CHECK_EQUAL(c.get_exchange(), 5);
}

BOOST_AUTO_TEST_CASE(multiplication)
{
  Currency c=Currency ("euro", "EUR", 10);

  c*=2.5;

  BOOST_CHECK_EQUAL(c.get_exchange(), 25);
}

BOOST_AUTO_TEST_SUITE_END()
