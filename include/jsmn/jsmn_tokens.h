#ifndef JSMN_WT_H
#define JSMN_WT_H

#include <stdbool.h>
#include <stdint.h>

#ifndef JSMN_MAX_TOKEN_LEN
#define JSMN_MAX_TOKEN_LEN 256
#endif

#ifndef JSMN_MAX_TOKEN_HEADER_LEN
#define JSMN_MAX_TOKEN_HEADER_LEN 64
#endif

#ifndef JSMN_MAX_TOKENS
#define JSMN_MAX_TOKENS 64
#endif

#ifndef JSMN_MAX_HEADER_TOKENS
#define JSMN_MAX_HEADER_TOKENS 16
#endif

#define JSMN_HEADER
#include JSMN_HEADER_FILE

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct jsmn_value
    {
        const char* p;
        uint32_t len;
    } jsmn_value;

    typedef enum JSMN_ALG
    {
        JSMN_ALG_ERROR = -1,
        JSMN_ALG_HS256 = 0,
        JSMN_ALG_HS384 = 1,
        JSMN_ALG_HS512 = 2,
        // JSMN_ALG_RS256,
        // JSMN_ALG_RS384,
        // JSMN_ALG_RS512,
        // JSMN_ALG_ES256,
        // JSMN_ALG_ES384,
        // JSMN_ALG_ES512,
        // JSMN_ALG_TERM
    } JSMN_ALG;
#define JSMN_ALG_COUNT 3

    typedef enum JSMN_ERROR
    {
        JSMN_ERROR_OK = 0
    } JSMN_ERROR;

    typedef struct jsmn_token_s
    {
        JSMN_ALG alg;
        uint32_t len;
        char b[JSMN_MAX_TOKEN_LEN];
    } jsmn_token_s;

    typedef struct jsmn_token_decoded_s
    {
        JSMN_ALG alg;
        jsmntok_t head[JSMN_MAX_HEADER_TOKENS];
        jsmntok_t body[JSMN_MAX_TOKENS];
        uint32_t n_head;
        uint32_t n_body;
        uint32_t json_len;
        char json[JSMN_MAX_TOKEN_LEN];
    } jsmn_token_decode_s;

    int jsmn_token_init(jsmn_token_s* t, JSMN_ALG alg, const char* claims, ...);
    int jsmn_token_sign(jsmn_token_s* t, const char* secret, uint32_t slen);
    uint32_t jsmn_token_len(jsmn_token_s* t);
    const char* jsmn_token_data(jsmn_token_s* t);
    int jsmn_token_decode(
        jsmn_token_decode_s*,
        const char* secret,
        JSMN_ALG,
        const char*,
        uint32_t);
    int jsmn_token_get_claim_str(
        jsmn_token_decode_s* t,
        const char* claim,
        jsmn_value* result);
    int jsmn_token_get_claim_int(
        jsmn_token_decode_s* token,
        const char* claim,
        int* result);

#ifdef __cplusplus
}
#endif
#endif
