# Ceng213-the1-tester
I test some invariants, also testcases 6, 8 &amp; 9 are replicated here(for SocialNetwork).

You might get aborts- if i did not make a mistake -they signal some kind of broken link.

If you get any kind of error please make sure you debug using gdb and valgrind.

# Usage
First copy your code into the folder directly. It is not given a dedicated folder.
You want core dumps, do this:
```shell
ulimit -c unlimited
```

```shell
make test
```

This should test your code. You wont see any output. You should check diff files to see whether you have any difference, if they are empty you're good.

If they are not matching you have a fail -or I am stupid-. 

If you see an error with (core dumped) find your core(which was dumped). Find the test that is causing the error by Makefile err line number.

For example if line number is 21 ctest2 is causing the error:
```shell
Segmentation fault
make: *** [Makefile:21: out] Error 139
```

Now to debug, use:

```shell
gdb _testcase_name_ core
```

This should give you the call stack which was being executed when you get the error.(use bt)

Now you can either try to understand your problem, or you can try using breakpoints to debug your program.

Learn gdb and valgrind for your own sake, here is a useful video:

https://youtu.be/bWH-nL7v5F4
