/****************************************************************************************
MIT License

Copyright (c) 2022 流陳光

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
****************************************************************************************/
#ifndef DESPAIR_CGI_DPCGI_PCH_HH
#define DESPAIR_CGI_DPCGI_PCH_HH

#include <algorithm>
#include <ostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#ifdef WIN32
#include "dpcgi_windoze.inl"
#else
#include "dpcgi_pengu.inl"
#endif

#define DPCGI_NAMESPACE_BEGIN   namespace dpcgi {
#define DPCGI_NAMESPACE_END     }    

//$ Set tag attribute, same code for both lValue and rValue.
#define dpcgi_tag_set_string(AttrName, AttrNameStr, AttrVal) \
    if(AttrName.empty()) { \
        this->_SUPER::add_attrib(AttrNameStr, AttrVal); \
        return; \
    } \
    auto ptr = this->_SUPER::find_attrib(AttrNameStr); \
    ptr->value = AttrVal;

#endif // !DESPAIR_CGI_DPCGI_PCH_HH
