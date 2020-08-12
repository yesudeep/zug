//
// zug: transducers for C++
// Copyright (C) 2019 Juan Pedro Bolivar Puente
//
// This software is distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt
//

#include <catch2/catch.hpp>

#include <zug/compose.hpp>
#include <zug/into_vector.hpp>
#include <zug/run.hpp>
#include <zug/transducer/enumerate.hpp>
#include <zug/transducer/sink.hpp>

#ifndef HAVE_BAZEL_BUILD
#include "../spies.hpp"
#else
#include "test/spies.hpp"
#endif

using namespace zug;

TEST_CASE("sink, sink")
{
    // example1 {
    auto v = std::vector<int>{1, 2, 3, 6};
    auto r = std::vector<int>{};
    run(sink([&](int x) { r.push_back(x); }), v);
    CHECK(v == r);
    // }
}

TEST_CASE("sink, sink2")
{
    // example2 {
    auto v = std::vector<int>{1, 42, 13, 6};
    auto r = into_vector(sink([&](int x) {}) | enumerate, v);
    CHECK(r == std::vector<std::size_t>{0, 1, 2, 3});
    // }
}

TEST_CASE("sink, moves values out of rvalue_container")
{
    using elem = testing::copy_spy<>;

    auto x      = elem{};
    auto v      = std::vector<elem>{x, x, x, x};
    auto copies = x.copied.count();

    auto r = into_vector(comp(sink([](elem) {}), enumerate), std::move(v));

    CHECK(x.copied.count() == copies);
    CHECK(r == (decltype(r){0, 1, 2, 3}));
}
