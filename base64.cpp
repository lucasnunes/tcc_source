#include "base64.hpp"

#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <boost/archive/iterators/insert_linebreaks.hpp>
#include <boost/archive/iterators/remove_whitespace.hpp>
#include <iostream>
#include <string>

namespace controller
{
    namespace base64
    {
        using namespace boost::archive::iterators;
        
        typedef transform_width< binary_from_base64<remove_whitespace<std::string::const_iterator> >, 8, 6 > it_binary_t;
        typedef insert_linebreaks<base64_from_binary<transform_width<std::string::const_iterator,6,8> >, 72 > it_base64_t;
        
        std::string encode(const std::string& msg)
        {
            unsigned int write_padd_chars = (3 - msg.length() % 3) % 3;
            
            std::string result(it_base64_t(msg.begin()), it_base64_t(msg.end()));
            result.append(write_padd_chars, '=');
            
            return result;
        }
        
        std::string decode(const std::string& encoded)
        {
            unsigned int padd_chars = count(encoded.begin(), encoded.end(), '=');
            std::string temp = encoded;
            
            std::replace(temp.begin(), temp.end(), '=', 'A');
            std::string result(it_binary_t(temp.begin()), it_binary_t(temp.end()));
            result.erase(result.end() - padd_chars, result.end());
            
            return result;
        }
        
        std::string encodeAccount(const std::string& login, const std::string& pass)
        {
            std::string msg = login;
            msg += ':';
            msg += pass;
            
            return encode(msg);
        }
    }
}
