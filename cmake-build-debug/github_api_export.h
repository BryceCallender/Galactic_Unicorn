
#ifndef GITHUB_API_EXPORT_H
#define GITHUB_API_EXPORT_H

#ifdef GITHUB_API_STATIC_DEFINE
#  define GITHUB_API_EXPORT
#  define GITHUB_API_NO_EXPORT
#else
#  ifndef GITHUB_API_EXPORT
#    ifdef github_api_EXPORTS
        /* We are building this library */
#      define GITHUB_API_EXPORT 
#    else
        /* We are using this library */
#      define GITHUB_API_EXPORT 
#    endif
#  endif

#  ifndef GITHUB_API_NO_EXPORT
#    define GITHUB_API_NO_EXPORT 
#  endif
#endif

#ifndef GITHUB_API_DEPRECATED
#  define GITHUB_API_DEPRECATED 
#endif

#ifndef GITHUB_API_DEPRECATED_EXPORT
#  define GITHUB_API_DEPRECATED_EXPORT GITHUB_API_EXPORT GITHUB_API_DEPRECATED
#endif

#ifndef GITHUB_API_DEPRECATED_NO_EXPORT
#  define GITHUB_API_DEPRECATED_NO_EXPORT GITHUB_API_NO_EXPORT GITHUB_API_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef GITHUB_API_NO_DEPRECATED
#    define GITHUB_API_NO_DEPRECATED
#  endif
#endif

#endif /* GITHUB_API_EXPORT_H */
