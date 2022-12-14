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
#ifndef DESPAIR_CGI_HTML_DOCUMENT_HH
#define DESPAIR_CGI_HTML_DOCUMENT_HH

#include "cookie.hh"
#include "tag.hh"
#include <set>


namespace dpcgi {

class DPCGI_DLL_API html_document
{
    typedef html_document _THIS;
public:
    html_document() noexcept; ~html_document() noexcept;
    
    html_document(const html_document&) = delete;
    html_document& operator=(const html_document&) = delete;

    result add_tag(const tag& tagLvalue) noexcept;
    result add_tag(tag&& tagRvalue) noexcept;
    
    string str() const noexcept;
    
    typedef std::vector<cookie*> cookie_table;
    const cookie_table& cookies() const noexcept { return cookies_; }

    dpcgi_class_getset(string, char_set, charSet_);
    dpcgi_class_getset(string, title, title_);

private:
    static const string CONTENT_TYPE_STR_;

    static bool tagIsForbidden(const tag& wTag);
    static const std::set<string> forbiddenTags_;

    string charSet_;
    string title_;
    cookie_table cookies_;
    std::vector<tag> tags_;
};

} // namespace dpcgi

#endif // !DESPAIR_CGI_HTML_DOCUMENT_HH
