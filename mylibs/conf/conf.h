extern size_t findarg(const char *confdir, const char *arg);
extern char * _getarg(FILE *, char *, size_t);

#define getarg(f, b, l) (b = _getarg(f, b, l))
