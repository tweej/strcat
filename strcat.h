#ifndef STRCAT_H
#define STRCAT_H

#include <cstddef>
#include <cstring>
#include <string>
#include <utility>

namespace minimal
{

struct StringLike
{
    // String literals
    template <std::size_t length>
    constexpr StringLike(const char (&str)[length]) noexcept
        : mStr(str), mLength(length-1)
    {}
    
    // Char pointers
    // This must be a function template because of overload resolution rules,
    // otherwise string literals will prefer to decay to const char *.
    template <typename T = const char * const>
    constexpr StringLike(T str) noexcept
        : mStr(str), mLength(std::strlen(str))
    {}
    
    // Char pointers with length
    constexpr StringLike(const char * const str, const std::size_t length) noexcept
        : mStr(str), mLength(length)
    {}
    
    // STL strings
    StringLike(const std::string &str) noexcept
        : mStr(str.c_str()), mLength(str.length())
    {}
    
    StringLike(const StringLike &) = delete;
    StringLike(StringLike &&)      = delete;
    
    const char * const mStr;
    const std::size_t  mLength;
};

namespace { // internal linkage
    std::size_t adder() { return 0; }

    std::size_t adder(const std::size_t size)
    { return size; }

    template <typename ... Sizes>
    std::size_t adder(const std::size_t first, const Sizes ... args)
    { return first + adder(args...); }

    void append(const std::string &s) {}

    template <typename T, typename ... Args>
    void append(std::string &s, T && first, Args && ... others)
    {
        const StringLike && ref = static_cast<const StringLike &&>(first);
        s.append(ref.mStr, ref.mLength);
        append(s, std::forward<Args>(others)...);
    }
} // unnamed namespace

template <typename ... Str>
std::string strcat(
    const StringLike & first,
    const StringLike & second,
    Str && ...         others)
{ 
    const std::size_t sum = first.mLength + second.mLength +
        adder((static_cast<const StringLike &&>(others).mLength)...);
    
    std::string ret;
    ret.reserve(sum); // allocate once

    ret.append(first.mStr, first.mLength).append(second.mStr, second.mLength);
    append(ret, std::forward<Str>(others)...);
    
    return ret;
}

} // namespace minimal

#endif // STRCAT_H
