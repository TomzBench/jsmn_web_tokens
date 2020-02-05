#ifndef JSMN_WT_H
#define JSMN_WT_H

#include <stdbool.h>
#include <stdint.h>

#ifndef JSMN_WEB_TOKEN_MAX_LEN
#define JSMN_WEB_TOKEN_MAX_LEN 256
#endif

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct jsmn_web_token_value
    {
        const char* p;
        uint32_t len;
    } jsmn_web_token_value;

    typedef enum JSMN_WEB_TOKEN_ALG
    {
        JSMN_WEB_TOKEN_ALG_NONE = 0,
        JSMN_WEB_TOKEN_ALG_HS256 = 1,
        JSMN_WEB_TOKEN_ALG_HS384 = 2,
        JSMN_WEB_TOKEN_ALG_HS512 = 3,
        // JSMN_WEB_TOKEN_ALG_RS256,
        // JSMN_WEB_TOKEN_ALG_RS384,
        // JSMN_WEB_TOKEN_ALG_RS512,
        // JSMN_WEB_TOKEN_ALG_ES256,
        // JSMN_WEB_TOKEN_ALG_ES384,
        // JSMN_WEB_TOKEN_ALG_ES512,
        // JSMN_WEB_TOKEN_ALG_TERM
    } JSMN_WEB_TOKEN_ALG;
#define JSMN_WEB_TOKEN_ALG_MAX JSMN_WEB_TOKEN_ALG_HS512

    typedef struct jsmn_web_token_s
    {
        JSMN_WEB_TOKEN_ALG alg;
        uint32_t len;
        char b[JSMN_WEB_TOKEN_MAX_LEN];
    } jsmn_web_token_s;

    int jsmn_web_token_init(
        jsmn_web_token_s* token,
        JSMN_WEB_TOKEN_ALG alg,
        const char* claims,
        ...);

#ifdef __cplusplus
}
#endif
#endif
