# Задание 4

```
nm file1.o 
                 U global_var
0000000000000000 T main
                 U printf
                 U print_from_file1
                 U print_from_file2

❯ nm file2.o 
                 U global_var
                 U printf
0000000000000000 T print_from_file2
                 U static_var

❯ nm main.o
                 U global_var
0000000000000000 T main
                 U printf
                 U print_from_file1
                 U print_from_file2
```

Благодаря команде nm можно увидеть, что static переменная доступна только внутри файла в котором создана, а благодаря extern можно использовать переменную объявленную в другом файле.


Объявление одной и той же глобальной переменной(global_var) в разных файлах вызывает ошибку линковки.

# Работа функций:

# nm:
функция nm показывает:показывает таблицу символов, таких как: глобальные (D), локальные (d), функции (T) и неопределенные (U) символы. 

функции и глобальные переменные являются неопределёнными в выводе nm, так как они определятся во время линковки.

чтобы переменная не была неопределенна(U) ей надо явно(зависит от расположения переменной) присвоить значение например int global_var = 30;

# objdump: 
функция objdump используется для отображения информации о объектных и используемых файлах.

-t:
Показывает записи таблицы символов файла. Похоже на информацию, предоставленную программой NM.

-x:
позволяет вывести все заголовки и секции файла



# strings:

функция strings показывает строки в бинарном файле.

строки из strings program видны:
```
file1.c -> global_var = %d
file1.c -> static_var = %d
file2.c -> global_var = %d
main.c -> global_var = %d
```

```
GLIBC_2.34
_ITM_deregisterTMCloneTable
__gmon_start__
_ITM_registerTMCloneTable
PTE1
u3UH
file1.c -> global_var = %d
file1.c -> static_var = %d
file2.c -> global_var = %d
main.c -> global_var = %d
;*3$"
GCC: (GNU) 14.2.1 20250207
file1.c
static_var
file2.c
```



# сегменты:

С помощью фукнции objdump с ключом -t я узнал:
```
 objdump -t file1.o

file1.o:     file format elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*  0000000000000000 file1.c
0000000000000000 l    d  .text  0000000000000000 .text
0000000000000000 l    d  .data  0000000000000000 .data
0000000000000004 l     O .data  0000000000000004 static_var
0000000000000000 l    d  .rodata        0000000000000000 .rodata
0000000000000000 g     O .data  0000000000000004 global_var
0000000000000000 g     O .bss   0000000000000004 notinitialized_var
0000000000000000 g     F .text  000000000000003f print_from_file1
0000000000000000         *UND*  0000000000000000 printf
```
Что: 

в .text находятся функции файлов.

в .bss находятся неинициализированные глобальные и static переменные, таких нет в этих файлах поэтому .bss вообще не показывается в выводе objdump.

в .data хранит инициализированные глобальные и static.


#  Из что посмотреть:

**откуда начинается программа:**
```
objdump -x a.out 

a.out:     file format elf64-x86-64
a.out
architecture: i386:x86-64, flags 0x00000150:
HAS_SYMS, DYNAMIC, D_PAGED
start address 0x0000000000001040

Program Header:
    PHDR off    0x0000000000000040 vaddr 0x0000000000000040 paddr 0x0000000000000040 align 2**3
         filesz 0x0000000000000310 memsz 0x0000000000000310 flags r--
  INTERP off    0x00000000000003b4 vaddr 0x00000000000003b4 paddr 0x00000000000003b4 align 2**0
         filesz 0x000000000000001c memsz 0x000000000000001c flags r--
    LOA ...
```

start address 0x0000000000001040 - адрес с которого начинается выполнение main функции.

```
objdump -x a.out | grep start (посмотрел через grep так как вывод очень большой)
start address 0x0000000000402ce0
0000000000000000 l    df *ABS*  0000000000000000 libc-start.o
00000000004033d0 l     F .text  000000000000009c __libc_start_call_main
0000000000400000 l       .note.gnu.property     0000000000000000 __ehdr_start
0000000000400310 l       .rela.plt      0000000000000000 __rela_iplt_start
00000000004a2e50 l       .fini_array    0000000000000000 __fini_array_start
00000000004a2e40 l       .init_array    0000000000000000 __init_array_start
00000000004a2e40 l       .tbss  0000000000000000 __preinit_array_start
00000000004054b0 g     F .text  00000000000002da .hidden __libc_start_main_impl
0000000000401335 g     F .text  000000000000000d _dl_start
0000000000402ce0 g     F .text  0000000000000026 .hidden _start
00000000004a8aa0 g       .bss   0000000000000000 __bss_start
00000000004a70a0  w      .data  0000000000000000 data_start
00000000004449c4 g       .text  0000000000000000 __syscall_cancel_arch_start
00000000004054b0 g     F .text  00000000000002da .hidden __libc_start_main
00000000004a70a0 g       .data  0000000000000000 __data_start

```
у static компиляции start address 0x0000000000402ce0 так как с начала выполняется динамическая линковка.

**используемые библиотеки:**
У обычной компиляции программа зависит от внешних библиотек, а статическая не имеет внешних зависимостей, поэтому статическая программа гораздо больше обычной.

# Дополнительный вопрос:

переменная static_var не отображается в таблице символов у main.o и file2.o(в file1.o она есть) потому что это static переменная и она не передаётся другим файлам.

```
❯ objdump -t file1.o | grep static_var
0000000000000004 l     O .data  0000000000000004 static_var

❯ objdump -t file2.o | grep static_var

❯ objdump -t main.o | grep static_var

```