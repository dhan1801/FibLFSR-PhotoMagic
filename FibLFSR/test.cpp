
// Copyright 2025 Dhanvika Nakka
#define BOOST_TEST_MODULE LFSRTest
#include <iostream>
#include <string>
#include <sstream>
#include <boost/test/included/unit_test.hpp>

#include "FibLFSR.hpp"

using PhotoMagic::FibLFSR;

BOOST_AUTO_TEST_CASE(testStepInstr) {
    FibLFSR l("1011011000110110");
    BOOST_REQUIRE_EQUAL(l.step(), 0);
    BOOST_REQUIRE_EQUAL(l.step(), 0);
    BOOST_REQUIRE_EQUAL(l.step(), 0);
    BOOST_REQUIRE_EQUAL(l.step(), 1);
    BOOST_REQUIRE_EQUAL(l.step(), 1);
    BOOST_REQUIRE_EQUAL(l.step(), 0);
    BOOST_REQUIRE_EQUAL(l.step(), 0);
    BOOST_REQUIRE_EQUAL(l.step(), 1);
}

BOOST_AUTO_TEST_CASE(testGenerateInstr) {
    FibLFSR l("1011011000110110");
    BOOST_REQUIRE_EQUAL(l.generate(9), 51);
}

BOOST_AUTO_TEST_CASE(test_step) {
    FibLFSR lfsr("1011011000110110");
    BOOST_CHECK_EQUAL(lfsr.step(), 0);
    std::ostringstream oss1;
    oss1 << lfsr;
    BOOST_CHECK_EQUAL(oss1.str(), "0110110001101100");

    BOOST_CHECK_EQUAL(lfsr.step(), 0);
    std::ostringstream oss2;
    oss2 << lfsr;
    BOOST_CHECK_EQUAL(oss2.str(), "1101100011011000");

    BOOST_CHECK_EQUAL(lfsr.step(), 0);
    std::ostringstream oss3;
    oss3 << lfsr;
    BOOST_CHECK_EQUAL(oss3.str(), "1011000110110000");
}

BOOST_AUTO_TEST_CASE(test_generate) {
    FibLFSR lfsr("1011011000110110");
    BOOST_CHECK_EQUAL(lfsr.generate(5), 3);
    std::ostringstream oss1;
    oss1 << lfsr;
    BOOST_CHECK_EQUAL(oss1.str(), "1100011011000011");

    BOOST_CHECK_EQUAL(lfsr.generate(5), 6);
    std::ostringstream oss2;
    oss2 << lfsr;
    BOOST_CHECK_EQUAL(oss2.str(), "1101100001100110");
}

BOOST_AUTO_TEST_CASE(test_stream_output) {
    FibLFSR lfsr("1011011000110110");
    std::ostringstream oss;
    oss << lfsr;
    BOOST_CHECK_EQUAL(oss.str(), "1011011000110110");
}

BOOST_AUTO_TEST_CASE(invalid_seed_test) {
    BOOST_CHECK_THROW(FibLFSR("1234567890123456"), std::invalid_argument);
    BOOST_CHECK_THROW(FibLFSR("11000110110000AB"), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(invalid_generate_test) {
    FibLFSR lfsr("1010101010101010");
    BOOST_CHECK_THROW(lfsr.generate(-1), std::invalid_argument);
}
