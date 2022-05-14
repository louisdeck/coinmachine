# coinmachine

A wargame in C

How to compile :

```bash
#!/bin/bash

gcc -fno-stack-protector -no-pie -m32 coinmachine.c -o coinmachine

sudo chown root:root flag.txt
sudo chmod 600 flag.txt

sudo chown root:root coinmachine
sudo chmod 4655 coinmachine
```
