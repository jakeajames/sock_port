# sock_port

iOS 10.0-12.2 (+12.4) tfp0 for all devices (in theory).

Some info:
- Uses socket bug by Ned Williamson
- Uses some things by Ian Beer, machswap, SockPuppet
- The rest of the code is licensed under GPL, unless given permission explicitly to distribute closed-source (the unc0ver team, pwn20wnd and sbingner, have this permission)
- The difference between this and original sock_port is that the main technique of this is taken from SockPuppet, the original sock_port took the initial ideas then I had my own, while this uses the same overall techniques with differences in implementation. Success rate on my iPad Air 2 is close to 100%, and most of the time it takes less than a second to run.

Write-up: https://raw.githubusercontent.com/jakeajames/sock_port/master/sock_port.pdf

Thanks to Pwn20wnd and GeoSn0w & users for helping with testing on multiple devices (and Corellium).
