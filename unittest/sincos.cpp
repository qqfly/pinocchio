//
// Copyright (c) 2018 INRIA
//

#include "utils/macros.hpp"
#include "pinocchio/math/sincos.hpp"
#include <cstdlib>

#include <boost/test/unit_test.hpp>
#include <boost/utility/binary.hpp>

template<typename Scalar>
void testSINCOS(int n)
{
  for(int k = 0; k < n; ++k)
  {
    Scalar sin_value, cos_value;
    Scalar alpha = (Scalar)std::rand()/(Scalar)RAND_MAX;
    pinocchio::SINCOS(alpha,&sin_value,&cos_value);
    
    Scalar sin_value_ref = std::sin(alpha),
           cos_value_ref = std::cos(alpha);
    
    BOOST_CHECK(sin_value == sin_value_ref);
    BOOST_CHECK(cos_value == cos_value_ref);
  }
}

BOOST_AUTO_TEST_SUITE(BOOST_TEST_MODULE)

BOOST_AUTO_TEST_CASE(test_sincos)
{
#ifndef NDEBUG
  const int n = 1e3;
#else
  const int n = 1e6;
#endif
  testSINCOS<float>(n);
  testSINCOS<double>(n);
  testSINCOS<long double>(n);
}

BOOST_AUTO_TEST_SUITE_END()
