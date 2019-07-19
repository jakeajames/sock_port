# sock_port
~~iOS 11.0-12.2 A7-A9 tfp0~~

iOS 11.0-12.1.4 A7-A9 tfp0 (in theory).

Tested successfully on:
- iPad Air 2, 12.1.1 
- iPad Air 2, 11.3.1
- iPhone 6, 12.1.2
- iPhone SE, 11.2.1

Some info:
- Uses socket bug by Ned Williamson
- Uses some things by Ian Beer, machswap, SockPuppet
- The rest of the code is licensed under GPL, unless given permission explicitly to distribute closed-source (the unc0ver team, pwn20wnd and sbingner, have this permission)

## SMAP
A10 and up could be fixed by:
- hardcoding the kernproc address & reading its vm_map using rk64_via_uaf (yes the exploit gets kernel read since the really beginning but it's slow and not 100% reliable so going through all procs would make the exploit pretty bad)
- doing spraying one more time, fake port -> get kernel read using it -> new fake port (could slightly make reliability worse)
- could probably use pipe buffers like v3ntex and machswap2 (though I haven't looked into how that works)

## 12.2 support is broken. IOurface's setValue fails with "Invalid argument" and I haven't got any 12.2 device nor 12.2 blobs to mess with it. If anyone can help with that it would be appreciated. In the meanwhile I'll be looking into other spraying methods.

Thanks to Pwn20wnd and GeoSn0w for helping with testing on multiple devices (and Corellium).
