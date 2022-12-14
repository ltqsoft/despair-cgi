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
#ifndef DESPAIR_CGI_TAG_HH
#define DESPAIR_CGI_TAG_HH

#include "def.h"
#include "string.hh"
#include <ostream>
#include <vector>


namespace dpcgi {

enum class result : uint32_t {
    success = 0, err_op_denied    
};

class DPCGI_DLL_API tag
{
    struct attribute { string name, value; };
    typedef std::vector<attribute> attrib_table;
    typedef std::vector<attribute>::iterator attrib_ptr;
public:
    //$ Parse a string for a tag, use with non-nested only.
    static tag parse(const string& str);

    tag() noexcept;
    tag(const string& name);
    virtual ~tag() noexcept;

    tag(const tag&) = default;
    tag(tag&&) = default;
    tag& operator=(const tag&) = default;
    tag& operator=(tag&&) = default;

    void add_attrib(const string& lValNameLV, const string& lValValue) noexcept;
    void add_attrib(string&& rValName, string&& rValValue) noexcept;
    void add_child(const tag& child) noexcept { children_.push_back(&child); }
    virtual string end() const noexcept final;

    virtual string str() const noexcept final;

    inline virtual const string& name() const noexcept final { return name_; }
    inline void name(const string& name) noexcept { name_ = name; }
    inline void name(string&& name) noexcept { name_ = name; }

    inline string id() const noexcept {
        return idAttribIndex_ != string::npos ? attribs_[idAttribIndex_].value : "";
    }
    void id(const string& newId) noexcept;
    void id(string&& newId) noexcept;

    dpcgi_class_getset(string, val, val_);
    
    inline virtual bool self_closed() const noexcept final { return selfClosed_; }
    inline void self_closed(bool YesNo) noexcept { selfClosed_ = YesNo; }

    attrib_ptr find_attrib(const string& name) noexcept;

    inline bool has_no_id() const noexcept { return idAttribIndex_ == string::npos; }

    //$ EOL: if set, an EOL will be inserted to the end of ::str() result.
    inline bool eol() const noexcept { return hasEol_; }
    inline void eol(bool YesNo) noexcept { hasEol_ = YesNo; }
    
    inline bool empty() const noexcept { return name_.empty(); }
    inline bool unnamed() const noexcept { return name_.empty(); }
    inline bool null_attrib(const attrib_ptr& attrib) const noexcept {
        return attrib == attribs_.end();
    }

    friend std::ostream& operator<<(std::ostream&, const tag&);

protected:
    string name_;
    size_t idAttribIndex_;
    std::vector<attribute> attribs_;
    string val_;
    std::vector<const tag*> children_;
    bool selfClosed_;
    bool hasEol_;
};

std::ostream& operator<<(std::ostream& wStream, const dpcgi::tag& wTag);

} // namespace dpcgi

// std::ostream& operator<<(std::ostream& wStream, const dpcgi::tag& wTag);


#endif // !DESPAIR_CGI_TAG_HH
