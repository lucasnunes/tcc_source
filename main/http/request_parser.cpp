/**
 * Copyright 2014 Lucas Nunes de Lima
 * 
 * Based on http_server from Christopher M. Kohlhoff (chris at kohlhoff dot com).
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **/

#include "request_parser.hpp"
#include "request.hpp"

namespace controller { namespace http {
    
RequestParser::RequestParser() : state(method_start) 
{}

void RequestParser::reset() 
{
    state = method_start; 
}

RequestParser::ResultType RequestParser::consume(Request& req, char input)
{/*
    switch(state)
    {
        case method_start:
            if(!is_char(input) || is_ctl(input) || is_tspecial(input))
            {
                return bad;
            }
            else
            {
                state = method;
                req.method.push_back(input);
                return indeterminate;
            }
        case method:
            if(input == ' ')
            {
                state = uri;
                return indeterminate;
            }
            else if(!is_char(input) || is_ctl(input) || is_tspecial(input))
            {
                return bad;
            }
            else
            {
                req.method.push_back(input);
                return indeterminate;
            }
        case uri:
            if(input == ' ')
            {
                state = http_version_h;
                return indeterminate;
            }
            else if(is_ctl(input))
            {
                return bad;
            }
            else
            {
                req.uri.push_back(input);
                return indeterminate;
            }
        case http_version_h:
            if(input == 'H')
            {
                state = http_version_t_1;
                return indeterminate;
            }
            else
            {
                return bad;
            }
        case http_version_t_1:
            if(input == 'T')
            {
                state = http_version_t_2;
                return indeterminate;
            }
            else
            {
                return bad;
            }
        case http_version_t_2:
            if(input == 'T')
            {
                state = http_version_p;
                return indeterminate;
            }
            else
            {
                return bad;
            }
        case http_version_p:
            if(input == 'P')
            {
                state = http_version_slash;
                return indeterminate;
            }
            else
            {
                return bad;
            }
        case http_version_slash:
            if(input == '/')
            {
                req.http_version_major = 0;
                req.http_version_minor = 0;
                state = http_version_major_start;
                return indeterminate;
            }
            else
            {
                return bad;
            }
        case http_version_major_start:
            if(is_digit(input))
            {
                req.http_version_major = req.http_version_major * 10 + input - '0';
                state = http_version_major;
                return indeterminate;
            }
            else
            {
                return bad;
            }
        case http_version_major:
            if(input == '.')
            {
                state = http_version_minor_start;
                return indeterminate;
            }
            else if(is_digit(input))
            {
                req.http_version_major = req.http_version_major * 10 + input - '0';
                return indeterminate;
            }
            else
            {
                return bad;
            }
        case http_version_minor_start:
            if(is_digit(input))
            {
                req.http_version_minor = req.http_version_minor * 10 + input - '0';
                state = http_version_minor;
                return indeterminate;
            }
            else
            {
                return bad;
            }
        case http_version_minor:
            if(input == '\r')
            {
                state = expecting_newline_1;
                return indeterminate;
            }
            else if(is_digit(input))
            {
                req.http_version_minor = req.http_version_minor * 10 + input - '0';
                return indeterminate;
            }
            else
            {
                return bad;
            }
        case expecting_newline_1:
            if(input == '\n')
            {
                state = header_line_start;
                return indeterminate;
            }
            else
            {
                return bad;
            }
        case header_line_start:
            if(input == '\r')
            {
                state = expecting_newline_3;
                return indeterminate;
            }
            else if(!req.headers.empty() && (input == ' ' || input == '\t'))
            {
                state = header_lws;
                return indeterminate;
            }
            else if(!is_char(input) || is_ctl(input) || is_tspecial(input))
            {
                return bad;
            }
            else
            {
                req.headers.push_back(Header());
                req.headers.back().name.push_back(input);
                state = header_name;
                return indeterminate;
            }
        case header_lws:
            if(input == '\r')
            {
                state = expecting_newline_2;
                return indeterminate;
            }
            else if(input == ' ' || input == '\t')
            {
                return indeterminate;
            }
            else if(is_ctl(input))
            {
                return bad;
            }
            else
            {
                state = header_value;
                req.headers.back().value.push_back(input);
                return indeterminate;
            }
        case header_name:
            if(input == ':')
            {
                state = space_before_header_value;
                return indeterminate;
            }
            else if(!is_char(input) || is_ctl(input) || is_tspecial(input))
            {
                return bad;
            }
            else
            {
                req.headers.back().name.push_back(input);
                return indeterminate;
            }
        case space_before_header_value:
            if(input == ' ')
            {
                state = header_value;
                return indeterminate;
            }
            else
            {
                return bad;
            }
        case header_value:
            if(input == '\r')
            {
                state = expecting_newline_2;
                return indeterminate;
            }
            else if(is_ctl(input))
            {
                return bad;
            }
            else
            {
                req.headers.back().value.push_back(input);
                return indeterminate;
            }
        case expecting_newline_2:
            if(input == '\n')
            {
                state = header_line_start;
                return indeterminate;
            }
            else
            {
                return bad;
            }
        case expecting_newline_3:
            return (input == '\n') ? good : bad;
        default:
            return bad;
    }*/
}

bool RequestParser::is_char(int c) 
{ 
    return c >= 0 && c <= 127; 
}

bool RequestParser::is_ctl(int c) 
{ 
    return (c >= 0 && c <= 31) || (c == 127); 
}

bool RequestParser::is_tspecial(int c)
{
    switch(c)
    {
        case '(':
        case ')':
        case '<':
        case '>':
        case '@':
        case ',':
        case ';':
        case ':':
        case '\\':
        case '"':
        case '/':
        case '[':
        case ']':
        case '?':
        case '=':
        case '{':
        case '}':
        case ' ':
        case '\t':
            return true;
        default:
            return false;
    }
}

bool RequestParser::is_digit(int c) 
{
    return c >= '0' && c <= '9'; 
}

}  // namespace server
}  // namespace http
