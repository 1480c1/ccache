// Copyright (C) 2020 Joel Rosdahl and other contributors
//
// See doc/AUTHORS.adoc for a complete list of contributors.
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 3 of the License, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// more details.
//
// You should have received a copy of the GNU General Public License along with
// this program; if not, write to the Free Software Foundation, Inc., 51
// Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

#pragma once

#include "system.hpp"

void cc_log(const char* format, ...) ATTR_FORMAT(printf, 1, 2);
void cc_bulklog(const char* format, ...) ATTR_FORMAT(printf, 1, 2);
void cc_log_argv(const char* prefix, char** argv);
void cc_dump_debug_log_buffer(const char* path);
void fatal(const char* format, ...) ATTR_FORMAT(printf, 1, 2) ATTR_NORETURN;
void warn(const char* format, ...) ATTR_FORMAT(printf, 1, 2);

bool copy_fd(int fd_in, int fd_out);
bool clone_file(const char* src, const char* dest, bool via_tmp_file);
bool copy_file(const char* src, const char* dest, bool via_tmp_file);
bool move_file(const char* src, const char* dest);
const char* get_hostname();
const char* tmp_string();
char* format(const char* format, ...) ATTR_FORMAT(printf, 1, 2);
void format_hex(const uint8_t* data, size_t size, char* buffer);
void reformat(char** ptr, const char* format, ...) ATTR_FORMAT(printf, 2, 3);
char* x_strdup(const char* s);
char* x_strndup(const char* s, size_t n);
void* x_malloc(size_t size);
void* x_realloc(void* ptr, size_t size);
void x_setenv(const char* name, const char* value);
void x_unsetenv(const char* name);
char* x_dirname(const char* path);
const char* get_extension(const char* path);
char* format_human_readable_size(uint64_t size);
char* format_parsable_size_with_suffix(uint64_t size);
bool parse_size_with_suffix(const char* str, uint64_t* size);
char* x_realpath(const char* path);
char* gnu_getcwd();
#ifndef HAVE_LOCALTIME_R
struct tm* localtime_r(const time_t* timep, struct tm* result);
#endif
#ifndef HAVE_STRTOK_R
char* strtok_r(char* str, const char* delim, char** saveptr);
#endif
int create_tmp_fd(char** fname);
FILE* create_tmp_file(char** fname, const char* mode);
const char* get_home_directory();
char* get_cwd();
bool same_executable_name(const char* s1, const char* s2);
size_t common_dir_prefix_length(const char* s1, const char* s2);
char* get_relative_path(const char* from, const char* to);
bool is_absolute_path(const char* path);
bool is_full_path(const char* path);
void update_mtime(const char* path);
void x_exit(int status) ATTR_NORETURN;
int x_rename(const char* oldpath, const char* newpath);
int tmp_unlink(const char* path);
int x_unlink(const char* path);
int x_try_unlink(const char* path);
#ifndef _WIN32
char* x_readlink(const char* path);
#endif
bool read_file(const char* path, size_t size_hint, char** data, size_t* size);
char* read_text_file(const char* path, size_t size_hint);
char* subst_env_in_string(const char* str, char** errmsg);
void set_cloexec_flag(int fd);
double time_seconds();
