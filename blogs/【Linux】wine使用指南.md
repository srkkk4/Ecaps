你有两种选择：
- 在[github/wine-mirror/wine](https://github.com/wine-mirror/wine)下载未编译源码
- `sudo apt install wine`

## 只讲第一种方法：
下载得到`.zip`文件，解压得到`wine`文件夹。

执行以下命令：  
（这里的 `-j` 是指几个任务并行来加速编译，如果是多核CPU可用）
```
./configure
或
./configure --enable-win64
```
然后
```
make -j3
make install
```

### 可能的错误和解决方法

**1.**`configure: error: no suitable flex found. Please install the 'flex' package`

解决办法：   
```
sudo apt-get install flex
```

**2.**`configure: error: no suitable flex found. Please install the 'bison' package`

解决办法：  
```
sudo apt-get install bison
```

**3.**
```c++
configure: error: X 64-bit development files not found. Wine will be built
without X support, which probably isn't what you want. You will need
to install 64-bit development packages of Xlib at the very least.
Use the --without-x option if you really want this.
```

解决办法：  
```
sudo apt-get install xserver-xorg-dev
```

### 配置
`make install`命令执行完后，运行
```
winecfg
```
进行初始化。这一步做完后主文件夹下会出现 `.wine/.wine64` 文件夹。

### 安装winetricks
```
sudo apt install winetricks
```
安装基础组件：
```
WINEPREFIX=~/.wine winetricks vcrun2019
```
运行GUI：
```
winetricks
```

#### （可选）安装相关组件
系统相关：
```
winetricks corefonts
```
网络相关：
```
winetricks wininet
winetricks winhttp
winetricks dotnet48
winetricks gecko
winetricks mono
```
游戏相关：
```
winetricks d3dx9 //DirectX
```

**安装完后请再次使用`winecfg`进行配置**

### 运行wine\wine64
使用64位的前提是编译时使用了`--enable-win64`。

32位：
```
sudo wine PROGRAM [ARGUMENTS...]
```
64位：
```
sudo wine64 PROGRAM [ARGUMENTS...]
```

关闭`WOW64`模式：
```
32位： sudo WINEWOW64_DISABLE=1 wine PROGRAM [ARGUMENTS...]
64位： sudo WINEWOW64_DISABLE=1 wine64 PROGRAM [ARGUMENTS...]
```

### 程序运行中可能出现的问题

1.**中文显示**

如果出现中文变成方格的问题，`winecfg`打开设置，调到“显示”，下面的中文示例应是方格。

解决办法：

从原生 windows 系统下 `windows\fonts` 文件夹复制 `simsum.ttc` 字体文件到 `\.wine\drive_c\windows\Fonts` 文件夹下即可（记得 `winecfg` ）。

2.**程序读写权限**

有时会报错 `Failed to create ...`，这是因为没有给程序读写权限，如果你不想给程序一个个设置，那么可以尝试一下办法：

把你的程序转移到 `\.wine\drive_c\users\***\Desktop\` 中，然后使用

```
cd ~\.wine
sudo chmod -R 777 *
```

赋予所有程序对 `\.wine ` 文件夹的读写权限。

### 参考资料
- [**Chatgpt Chat**](https://chatgpt.com/share/676d62f7-e6a0-8003-b08d-4668e0b23413)
- [**使用源码安装wine**](https://blog.csdn.net/u013350783/article/details/90742468)