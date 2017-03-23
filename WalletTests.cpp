#include <boost/test/unit_test.hpp>

#include "WalletOperator.h"
#include "CurrencyOperator.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(WalletTests)


BOOST_AUTO_TEST_CASE(comparator)
{
  const Wallet w1, w2;
  BOOST_CHECK (w1==w2);
}

BOOST_AUTO_TEST_CASE(assignment)
{
  const Currency c = Currency ("euro", "EUR", 250);
  const Wallet w1 = Wallet (c, 100);
  const Wallet w2 = w1;

  BOOST_CHECK(w1==w2);
}

BOOST_AUTO_TEST_CASE(add)
{
  const Wallet w1, w2, w3;

  w1=w2+w3;

  BOOST_CHECK_EQUAL(w1.value, 200);
}

BOOST_AUTO_TEST_CASE(subtraction)
{
  const Wallet w1, w2, w3;

  w1=w2-w3;

  BOOST_CHECK_EQUAL(w1.value, 0);
}

BOOST_AUTO_TEST_CASE(not_new_add)
{
  const Wallet w1, w2;

  w1+=w2;

  BOOST_CHECK_EQUAL(w1.value, 200);
}

BOOST_AUTO_TEST_CASE(not_new_subtraction)
{
  const Wallet w1, w2;

  w1-=w2;

  BOOST_CHECK_EQUAL(w1.value, 0);
}

BOOST_AUTO_TEST_SUITE_END()
