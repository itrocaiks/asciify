# asciify
very simple script to decrypt/encrypt ASCII (doesn't work for stdin)
## Installation
```
git clone https://github.com/itrocaiks/asciify
cd asciify
clang asciify.c -o asciify
sudo install -m 755 ./asciify /usr/bin/
```

## Usage
```
Usage: asciify [OPTION] [MESSAGE]
  -e    encrypts the input
  -d    decrypts the input
```
asciify only decrypts text characters, others will be decrypted as (null)
