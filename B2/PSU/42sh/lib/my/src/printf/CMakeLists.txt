set(INCROOT ${PROJECT_SOURCE_DIR}/include/libmy)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/printf)

set(SRC
    ${INCROOT}/printf.h
    ${INCROOT}/printf/config.h
    ${INCROOT}/printf/printf.h
    ${SRCROOT}/my_asprintf.c
    ${SRCROOT}/my_dprintf.c
    ${SRCROOT}/my_fprintf.c
    ${SRCROOT}/my_printf_boolean.c
    ${SRCROOT}/my_printf_boolean_len.c
    ${SRCROOT}/my_printf.c
    ${SRCROOT}/my_printf_char.c
    ${SRCROOT}/my_printf_conversion.c
    ${SRCROOT}/my_printf_conversion_len.c
    ${SRCROOT}/my_printf_count_parameters.c
    ${SRCROOT}/my_printf_fill_args.c
    ${SRCROOT}/my_printf_fill_types.c
    ${SRCROOT}/my_printf_get_conv_base.c
    ${SRCROOT}/my_printf_get_conv_specifier.c
    ${SRCROOT}/my_printf_get_flags.c
    ${SRCROOT}/my_printf_get_len_modifier.c
    ${SRCROOT}/my_printf_get_position.c
    ${SRCROOT}/my_printf_get_type.c
    ${SRCROOT}/my_printf.h
    ${SRCROOT}/my_printf_next_conversion.c
    ${SRCROOT}/my_printf_pad.c
    ${SRCROOT}/my_printf_parse_conversion.c
    ${SRCROOT}/my_printf_percent.c
    ${SRCROOT}/my_printf_pointer.c
    ${SRCROOT}/my_printf_pointer_len.c
    ${SRCROOT}/my_printf_sint.c
    ${SRCROOT}/my_printf_sint_len.c
    ${SRCROOT}/my_printf_string.c
    ${SRCROOT}/my_printf_string_len.c
    ${SRCROOT}/my_printf_uint.c
    ${SRCROOT}/my_printf_uint_len.c
    ${SRCROOT}/my_snprintf.c
    ${SRCROOT}/my_sprintf.c
    ${SRCROOT}/my_vasprintf.c
    ${SRCROOT}/my_vdprintf.c
    ${SRCROOT}/my_vfprintf.c
    ${SRCROOT}/my_vprintf.c
    ${SRCROOT}/my_vsnprintf.c
    ${SRCROOT}/my_vsprintf.c
)

# IDE source group
source_group("" FILES ${SRC})

libmy_add_module(my-printf SOURCES ${SRC})

# setup dependencies
target_link_libraries(my-printf PUBLIC my-io my-parsing)

target_include_directories(my-printf PUBLIC "${PROJECT_SOURCE_DIR}/include")
