#ifndef DESPAIR_CGI_DPCGI_WINDOZE_INL
#define DESPAIR_CGI_DPCGI_WINDOZE_INL

namespace dpcgi {

inline const char* get_env(const char* envName)
{
    char* buffer;
    const errno_t err = _dupenv_s(&buffer, nullptr, envName);

    return (
        err == EINVAL || err == ENOMEM ? "" : buffer
    );
}

} // namespace dpcgi

#endif // !DESPAIR_CGI_DPCGI_WINDOZE_INL
