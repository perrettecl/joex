/*  =========================================================================
    joex_proto - joe example protocol

    Codec header for joex_proto.

    ** WARNING *************************************************************
    THIS SOURCE FILE IS 100% GENERATED. If you edit this file, you will lose
    your changes at the next build cycle. This is great for temporary printf
    statements. DO NOT MAKE ANY CHANGES YOU WISH TO KEEP. The correct places
    for commits are:

     * The XML model used for this code generation: joex_proto.xml, or
     * The code generation script that built this file: zproto_codec_c
    ************************************************************************
    =========================================================================
*/

#ifndef JOEX_PROTO_H_INCLUDED
#define JOEX_PROTO_H_INCLUDED

/*  These are the joex_proto messages:

    HELLO -
        name                string
        header              hash

    PING -

    PONG -

    OK -

    CLOSE -

    ERROR -
        reason              string
        code                number 8

    CHUNK -
        data                chunk
        offset              number 8
        chunksize           number 8
        chunkchecksum       number 8

    UPLOAD -
        filename            string
        filesize            number 8
        filechecksum        number 8

    UPLOAD_FINISHED -
*/


#define JOEX_PROTO_HELLO                    1
#define JOEX_PROTO_PING                     2
#define JOEX_PROTO_PONG                     3
#define JOEX_PROTO_OK                       4
#define JOEX_PROTO_CLOSE                    5
#define JOEX_PROTO_ERROR                    6
#define JOEX_PROTO_CHUNK                    7
#define JOEX_PROTO_UPLOAD                   8
#define JOEX_PROTO_UPLOAD_FINISHED          9

#include <czmq.h>

#ifdef __cplusplus
extern "C" {
#endif

//  Opaque class structure
#ifndef JOEX_PROTO_T_DEFINED
typedef struct _joex_proto_t joex_proto_t;
#define JOEX_PROTO_T_DEFINED
#endif

//  @interface
//  Create a new empty joex_proto
joex_proto_t *
    joex_proto_new (void);

//  Destroy a joex_proto instance
void
    joex_proto_destroy (joex_proto_t **self_p);

//  Receive a joex_proto from the socket. Returns 0 if OK, -1 if
//  the read was interrupted, or -2 if the message is malformed.
//  Blocks if there is no message waiting.
int
    joex_proto_recv (joex_proto_t *self, zsock_t *input);

//  Send the joex_proto to the output socket, does not destroy it
int
    joex_proto_send (joex_proto_t *self, zsock_t *output);


//  Print contents of message to stdout
void
    joex_proto_print (joex_proto_t *self);

//  Get/set the message routing id
zframe_t *
    joex_proto_routing_id (joex_proto_t *self);
void
    joex_proto_set_routing_id (joex_proto_t *self, zframe_t *routing_id);

//  Get the joex_proto id and printable command
int
    joex_proto_id (joex_proto_t *self);
void
    joex_proto_set_id (joex_proto_t *self, int id);
const char *
    joex_proto_command (joex_proto_t *self);

//  Get/set the name field
const char *
    joex_proto_name (joex_proto_t *self);
void
    joex_proto_set_name (joex_proto_t *self, const char *value);

//  Get a copy of the header field
zhash_t *
    joex_proto_header (joex_proto_t *self);
//  Get the header field and transfer ownership to caller
zhash_t *
    joex_proto_get_header (joex_proto_t *self);
//  Set the header field, transferring ownership from caller
void
    joex_proto_set_header (joex_proto_t *self, zhash_t **hash_p);

//  Get/set the reason field
const char *
    joex_proto_reason (joex_proto_t *self);
void
    joex_proto_set_reason (joex_proto_t *self, const char *value);

//  Get/set the code field
uint64_t
    joex_proto_code (joex_proto_t *self);
void
    joex_proto_set_code (joex_proto_t *self, uint64_t code);

//  Get a copy of the data field
zchunk_t *
    joex_proto_data (joex_proto_t *self);
//  Get the data field and transfer ownership to caller
zchunk_t *
    joex_proto_get_data (joex_proto_t *self);
//  Set the data field, transferring ownership from caller
void
    joex_proto_set_data (joex_proto_t *self, zchunk_t **chunk_p);

//  Get/set the offset field
uint64_t
    joex_proto_offset (joex_proto_t *self);
void
    joex_proto_set_offset (joex_proto_t *self, uint64_t offset);

//  Get/set the chunksize field
uint64_t
    joex_proto_chunksize (joex_proto_t *self);
void
    joex_proto_set_chunksize (joex_proto_t *self, uint64_t chunksize);

//  Get/set the chunkchecksum field
uint64_t
    joex_proto_chunkchecksum (joex_proto_t *self);
void
    joex_proto_set_chunkchecksum (joex_proto_t *self, uint64_t chunkchecksum);

//  Get/set the filename field
const char *
    joex_proto_filename (joex_proto_t *self);
void
    joex_proto_set_filename (joex_proto_t *self, const char *value);

//  Get/set the filesize field
uint64_t
    joex_proto_filesize (joex_proto_t *self);
void
    joex_proto_set_filesize (joex_proto_t *self, uint64_t filesize);

//  Get/set the filechecksum field
uint64_t
    joex_proto_filechecksum (joex_proto_t *self);
void
    joex_proto_set_filechecksum (joex_proto_t *self, uint64_t filechecksum);

//  Self test of this class
void
    joex_proto_test (bool verbose);
//  @end

//  For backwards compatibility with old codecs
#define joex_proto_dump     joex_proto_print

#ifdef __cplusplus
}
#endif

#endif
