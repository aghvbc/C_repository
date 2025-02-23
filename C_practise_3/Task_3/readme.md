```
Дополнительное задание:
❯ nm main.o
                 U calculate_distance
                 U check_fuel
                 U __isoc99_scanf
0000000000000000 T main
                 U printf
                 U putchar
                 U __stack_chk_fail

❯ nm fuel.o
0000000000000000 T check_fuel
                 U printf

❯ nm navigation.o
0000000000000000 T calculate_distance
                 U printf


❯ nm program 
0000000000004030 B __bss_start
0000000000001250 T calculate_distance
0000000000001228 T check_fuel
                 w __cxa_finalize@GLIBC_2.2.5
0000000000004020 D __data_start
0000000000004020 W data_start
0000000000004028 D __dso_handle
0000000000003de0 d _DYNAMIC
0000000000004030 D _edata
0000000000004038 B _end
000000000000129c T _fini
0000000000003fe8 d _GLOBAL_OFFSET_TABLE_
                 w __gmon_start__
00000000000020c4 r __GNU_EH_FRAME_HDR
0000000000001000 T _init
0000000000002000 R _IO_stdin_used
                 U __isoc99_scanf@GLIBC_2.7
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
                 U __libc_start_main@GLIBC_2.34
0000000000001169 T main
                 U printf@GLIBC_2.2.5
                 U putchar@GLIBC_2.2.5
                 U __stack_chk_fail@GLIBC_2.4
0000000000001070 T _start
0000000000004030 D __TMC_END__

```
Как можно заметить после сначала есть три файла в которых свои неопределённые и определённые функции, но единой программе все неопределённости из трёх файлов разрешились(кроме фукнций которые загружаются динамически из libc), а также добавилось множество всего дополнительного, например символ _start - функция которая инициализирует среду выполнения программы и вызывает основную функцию программы.