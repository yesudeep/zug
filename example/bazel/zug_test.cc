#include <vector>

#include "gtest/gtest.h"
#include "zug/into.hpp"
#include "zug/into_vector.hpp"
#include "zug/transducer/cycle.hpp"

namespace {

using namespace zug;

// This is just a test to ensure the library compiles and links.
// For more tests browse the library code.
TEST(ZugTest, Mutation) {
  auto v = std::vector<int>{1, 2, 3};
  auto res = std::vector<int>{};
  auto& res2 = into(res, identity, v);
  ASSERT_EQ(res, (std::vector<int>{1, 2, 3}));
  ASSERT_EQ(&res, &res2);
}

TEST(ZugTest, Cycle) {
  auto v1 = std::vector<int>{13, 4, 2143, 398, 10};
  auto v2 = std::vector<int>{0, 1};
  auto r = into_vector(cycle(v2), v1);
  using t = std::vector<std::tuple<int, int>>;
  ASSERT_EQ(r, (t{{13, 0}, {4, 1}, {2143, 0}, {398, 1}, {10, 0}}));
}

}  // namespace
