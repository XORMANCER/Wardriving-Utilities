| ![image](https://user-images.githubusercontent.com/63486672/113641162-ad092e00-9642-11eb-8814-9d55299fc177.png) |
| :------: |
🚗 Collection of personal utilities to make wardriving easier
 
## 📝 Installation

After installing [crystal](https://crystal-lang.org/install/), build main.cr and run the setup file

```bash
sudo crystal build --release main.cr -o blackmoth
sudo chmod +x setup.sh
./setup.sh
```

The compiled binary will be moved to `/usr/bin/blackmoth`  
All configuration files are located within `/usr/share/BLACKMOTH`

## 🦋 Usage

```bash
sudo blackmoth
```
## 💡 Configuration
Recommended deauth wait time values
* mdk4: `15` 
* aireplay-ng: `10`
## License
[MIT](https://choosealicense.com/licenses/mit/)
