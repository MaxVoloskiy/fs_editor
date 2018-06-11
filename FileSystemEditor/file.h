#ifndef FILE_H
#define FILE_H

#pragma pack(push, 1)
struct fileStruct
{
    char filename[8];
    char ext[3];
    u_int8_t attributes;
    char reserved[10];
    u_int16_t time_created;
    u_int16_t modify_date;
    u_int16_t starting_cluster;
    u_int32_t file_size;
};
#pragma pack(pop)

#endif // FILE_H
