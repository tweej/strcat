#ifndef STRCAT_H
#define STRCAT_H

#include <string>
#include <string_view>
#include <concepts>
#include <array>

namespace minimal
{

std::string strcat(
    std::string_view first,
    std::string_view second,
    const std::convertible_to<std::string_view> auto&... others)
{
    const std::array<std::string_view, sizeof...(others)> views{others...};

    std::string::size_type sum = first.size() + second.size();
    for (auto v : views) sum += v.size();

    std::string ret;
    ret.reserve(sum); // allocate once

    ret.append(first).append(second);
    for (auto v : views) ret.append(v);

    return ret;
}

} // namespace minimal

#endif // STRCAT_H
