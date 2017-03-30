#include <boost/test/unit_test.hpp>

#include "Wallet.h"
#include "Currency.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(WalletTests)


BOOST_AUTO_TEST_CASE(comparator)
{
  const Wallet w2;
  Wallet w1;
  BOOST_CHECK (w1==w2);
}


BOOST_AUTO_TEST_CASE(assignment)
{
  const Currency c = Currency ("euro", "EUR", 250);
  const Wallet w1 = Wallet (c, 100);
  Wallet w2 = w1;

  BOOST_CHECK(w2==w1);
}

BOOST_AUTO_TEST_CASE(add)
{
  const Wallet w3;
  Wallet w1, w2;

  w1=w2+w3;

  BOOST_CHECK_EQUAL(w1.get_value(), 200);
}

BOOST_AUTO_TEST_CASE(subtraction)
{
  const Wallet w3;
  Wallet w1, w2;

  w1=w2-w3;

  BOOST_CHECK_EQUAL(w1.get_value(), 0);
}

BOOST_AUTO_TEST_CASE(not_new_add)
{
  const Wallet w2;
  Wallet w1;

  w1+=w2;

  BOOST_CHECK_EQUAL(w1.get_value(), 200);
}

BOOST_AUTO_TEST_CASE(not_new_subtraction)
{
  const Wallet w2;
  Wallet w1;

  w1-=w2;

  BOOST_CHECK_EQUAL(w1.get_value(), 0);
}


BOOST_AUTO_TEST_SUITE_END()
