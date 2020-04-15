#ifndef STRCAT_H
#define STRCAT_H

#include <cstddef>
#include <string>
#include <string_view>
#include <utility>

namespace minimal
{

namespace { // internal linkage
    constexpr std::size_t adder() noexcept { return 0; }

    constexpr std::size_t adder(const std::size_t size) noexcept
    { return size; }

    template <typename ... Sizes>
    constexpr std::size_t adder(const std::size_t first, const Sizes ... args) noexcept
    { return first + adder(args...); }

    constexpr void append(const std::string &s) noexcept {}

    template <typename T, typename ... Args>
    constexpr void append(std::string &s, T && first, Args && ... others) noexcept
    {
        // should not throw; already allocated and reserve() would have
        // also thrown for size() > max_size()
        s.append(static_cast<std::string_view>(first));
        append(s, std::forward<Args>(others)...);
    }
} // unnamed namespace

template <typename ... Str>
constexpr std::string strcat(
    std::string_view first,
    std::string_view second,
    Str && ...       others)
{
    constexpr std::size_t sum = first.size() + second.size() +
        adder((static_cast<std::string_view>(others).size())...);

    std::string ret;
    ret.reserve(sum); // allocate once

    ret.append(first).append(second);
    append(ret, std::forward<Str>(others)...);

    return ret;
}

} // namespace minimal

#endif // STRCAT_H
