| ![image](https://user-images.githubusercontent.com/63486672/113641162-ad092e00-9642-11eb-8814-9d55299fc177.png) |
| :------: |
🚗 Collection of personal utilities to make wardriving easier
 
## 📝 Installation

After installing [g++](https://installlion.com/kali/kali/main/g/g++/install/index.html), build each desired tool

```bash
g++ -o drgrepper drgrepper.cpp; g++ -o monset monset.cpp
```

Drop each compiled binary to `/usr/bin/`

## 🥤 Dr.Grepper: Usage

Searches a file for given string, refreshing after a specified time (Default: 3 seconds)
```bash
sudo drgrepper [input file] [search term] (optional: wait_value) 
```
## 🕶️ Monset: Usage

Enables or disables monitor mode on a given interface
```bash
sudo monset [interface] [start/stop] 
```
Note: Network manager needs to be restarted when re-entering managed mode  

`sudo NetworkManager restart`

## License
[MIT](https://choosealicense.com/licenses/mit/)
