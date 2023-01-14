#ifndef DESPAIR_CGI_DPCGI_WINDOZE_INL
#define DESPAIR_CGI_DPCGI_WINDOZE_INL

inline const char* get_env(const char* envName)
{
    const char* Env = getenv(envName);
    return (Env != nullptr ? Env : "");
}

#endif // !DESPAIR_CGI_DPCGI_WINDOZE_INL
