#include "strcat.h"

#include "gtest/gtest.h"

TEST(StringLiteral, Two) {
  EXPECT_EQ("foobar", minimal::strcat("foo", "bar"));
}

TEST(StringLiteral, Three) {
  EXPECT_EQ("foobarbat", minimal::strcat("foo", "bar", "bat"));
}

TEST(CharPointer, Two) {
    const char * const foo{"foo"};
    const char * const bar{"bar"};
    EXPECT_EQ("foobar", minimal::strcat(foo, bar));
}

TEST(CharPointer, Three) {
    const char * const foo{"foo"};
    const char * const bar{"bar"};
    const char * const bat{"bat"};
    EXPECT_EQ("foobarbat", minimal::strcat(foo, bar, bat));
}

TEST(CharPointerLength, Two) {
    const char * const foo{"foo"};
    const char * const bar{"bar"};
    const minimal::StringLike s0{foo, 3};
    EXPECT_EQ("foobar", minimal::strcat(s0, minimal::StringLike{bar, 3}));
}

TEST(CharPointerLength, Three) {
    const char * const foo{"foo"};
    const char * const bar{"bar"};
    const char * const bat{"bat"};
    const minimal::StringLike s0{foo, 3};
    const minimal::StringLike s1{bar, 3};
    const minimal::StringLike s2{bat, 3};
    EXPECT_EQ("foobarbat", minimal::strcat(s0, s1, s2));
}

TEST(STLString, Two) {
    EXPECT_EQ("foobar", minimal::strcat(std::string{"foo"}, std::string{"bar"}));
}

TEST(STLString, Three) {
    EXPECT_EQ("foobarbat",
              minimal::strcat(std::string{"foo"}, std::string{"bar"}, std::string{"bat"}));
}

TEST(Mix, Permutation1) {
    const char * const bar{"bar"};
    const std::string bat{"bat"};
    EXPECT_EQ("foobarbat", minimal::strcat("foo", bar, bat));
}

TEST(Mix, Permutation2) {
    const char * const bar{"bar"};
    const std::string bat{"bat"};
    EXPECT_EQ("barbatfoo", minimal::strcat(bar, bat, "foo"));
}

TEST(Mix, Permutation3) {
    const char * const bar{"bar"};
    const std::string bat{"bat"};
    EXPECT_EQ("batfoobar", minimal::strcat(bat, "foo", bar));
}
