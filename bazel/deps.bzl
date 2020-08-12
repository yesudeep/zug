load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def zug_deps():
    """Loads dependencies needed to compile and test Zug."""

    if "rules_cc" not in native.existing_rules():
        http_archive(
            name = "rules_cc",
            sha256 = "35f2fb4ea0b3e61ad64a369de284e4fbbdcdba71836a5555abb5e194cf119509",
            strip_prefix = "rules_cc-624b5d59dfb45672d4239422fa1e3de1822ee110",
            urls = ["https://github.com/bazelbuild/rules_cc/archive/624b5d59dfb45672d4239422fa1e3de1822ee110.tar.gz"],
        )

    if "com_github_nelhage_rules_boost" not in native.existing_rules():
        http_archive(
            name = "com_github_nelhage_rules_boost",
            sha256 = "8b72c1cde81ad03e328ab8ff2b31ccebd1366eb1ac1c9dbfc584e1e11d50c53f",
            strip_prefix = "rules_boost-1da7517245fb944d6b7b427aa86fd5571663f90a",
            urls = ["https://github.com/nelhage/rules_boost/archive/1da7517245fb944d6b7b427aa86fd5571663f90a.tar.gz"],
        )

    if "com_github_catchorg_catch2" not in native.existing_rules():
        http_archive(
            name = "com_github_catchorg_catch2",
            sha256 = "6994d16989a1c7955f9509765572934e9ff3105f8a998c6777d1feddc6b8550f",
            strip_prefix = "Catch2-229cc4823c8cbe67366da8179efc6089dd3893e9",
            urls = ["https://github.com/catchorg/catch2/archive/229cc4823c8cbe67366da8179efc6089dd3893e9.tar.gz"],
        )
