#ifndef STRCAT_H
#define STRCAT_H

#include <string>
#include <string_view>
#include <utility>

namespace minimal
{

template <typename ... Str>
std::string strcat(
    std::string_view first,
    std::string_view second,
    Str && ...       others) 
{
    const std::string::size_type sum = first.size() + second.size() +
        (static_cast<std::string_view>(others).size() + ... + 0);

    std::string ret;
    ret.reserve(sum); // allocate once

    ret.append(first).append(second);
    (ret.append(std::forward<Str>(others)), ...);

    return ret;
}

} // namespace minimal

#endif // STRCAT_H
