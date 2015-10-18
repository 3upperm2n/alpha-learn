# Tutorials

[1] https://gcc.gnu.org/projects/prefetch.html<br>
spatial locality / temporal locality <br>
The mentioned guideline is useful.<br>
The prefeching should function at the granuality of 32 bytes or cache line size. <br>
Different arch has different intrinsics/ISA to support prefeching. <br>

[2] https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html <br>
**__builtin_prefetch** is the function to use in gcc. <br>


---
### Some examples
* http://www.naftaliharris.com/blog/2x-speedup-with-one-line-of-code/
* http://tomoyo.osdn.jp/cgi-bin/lxr/source/include/linux/prefetch.h
* http://ftp.netbsd.org/pub/NetBSD/NetBSD-current/src/sys/netinet/cpu_in_cksum.c
* http://web.engr.oregonstate.edu/~mjb/cs475/Handouts/prefetch.6pp.pdf
* http://web.engr.oregonstate.edu/~mjb/cs475/Handouts/



