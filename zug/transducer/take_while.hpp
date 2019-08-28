//
// zug: transducers for C++
// Copyright (C) 2019 Juan Pedro Bolivar Puente
//
// This software is distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://boost.org/LICENSE_1_0.txt
//

#pragma once

#include <zug/maybe_reduced.hpp>
#include <zug/skip.hpp>

namespace zug {

constexpr auto take_while = [](auto predicate) {
    return [=](auto&& step) {
        return [=](auto&& s, auto&&... is) mutable {
            return invoke(predicate, is...)
                       ? not_reduced(call(
                             step, state_unwrap(ZUG_FWD(s)), ZUG_FWD(is)...))
                       : reduced(skip(
                             step, state_unwrap(ZUG_FWD(s)), ZUG_FWD(is)...));
        };
    };
};

} // namespace zug