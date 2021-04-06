| ![image](https://user-images.githubusercontent.com/63486672/113641162-ad092e00-9642-11eb-8814-9d55299fc177.png) |
| :------: |
🚗 Collection of personal utilities to make wardriving easier
 
## 📝 Installation

After installing [gcc](https://www.cyberciti.biz/faq/debian-linux-install-gnu-gcc-compiler/), build each desired tool

```bash
gcc -o drgrepper drgrepper.cpp; gcc -o monset monset.cpp
```

Drop each compiled binary to `/usr/bin/`

## 🥤 Dr.Grepper Usage

Searches a file for given string, refreshing after a specified time (Default: 3s)
```bash
sudo drgrepper [input file] [search term] (optional: wait value) 
```
## 🕶️ Monset Usage

Places a given interface into monitor mode or back into managed mode
```bash
sudo monset [interface] [start/stop] 
```
Note: remember to restart your network manager if placing back into managed mdoe
Syntax: `sudo NetworkManager restart`

## License
[MIT](https://choosealicense.com/licenses/mit/)
