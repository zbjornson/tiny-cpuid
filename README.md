# tiny-cpuid
A tiny utility to retrieve a bit from cpuid

```
Usage: cpuid outreg bit initEax [initEcx]
  outreg  register to retrieve bit from (eax=0, ebx=1, ecx=2, edx=3)
  bit     bit to retrieve from output register
  initEax initial value for eax
  initEcx initial value for ecx (default 0)
```

For example:

    $ cpuid 1 5 7 # bit 5 from ebx with eax=7 to test for AVX2
    1 # has AVX2 support
