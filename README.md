# 浮生日记

---

使用visual studio打开项目中的`LeafLife.sln`文件，选择Release & x64平台最后生成可执行文件，

需要将res目录的资源文件同时拷贝到生成的目录下，才能保证程序的资源文件正常被使用，

### MVC结构设计

- 关于mvc架构、mvp架构、mvvm架构介绍：https://zhuanlan.zhihu.com/p/616953800

整个游戏的软件结构是以MVC的结构设计的，分成3层结构：Model数据模型层、View视图层（用于显示）、Controller层（用于游戏进程控制） 

使用单例模式管理每个层次的类对象，

- View视图层：`GameViewer` 、`GameMainView` 、`GameInfoView` 
- Model数据层：`GameModel` 、`GameScene` 、`GameRole`  
- Controller控制层：`GameController`、`GameCore`、`SoundController`，

GameController与GameCore的比较：GameController更偏向于整体游戏的控制，而GameCore主要用于游戏开始的具体内容显示，

### 主要功能与技术点

1. step1：游戏开始界面
    - MVC架构设计、单例模式、
    - 游戏开场剧情展示、打字动画、
    - 构建声音播放控制器、播放打字音效与背景音乐、
2. step2：游戏主界面
    - 音效开启和关闭设置
    - 游戏主循环（游戏核心）、
    - 游戏界面布局标题和时间显示、玩家信息显示、功能选择菜单
    - 游戏计时功能
4. step3：黑市交易系统
    - 黑市商品价格随机
    - 黑市商品类型随机
    - 黑市商品列表数据更新
    - 加载显示黑市商品列表数据
    - 出租屋货物列表数据更新
    - 加载显示出租屋货物列表数据
    - 购买黑市商品、出售出租屋货物功能
4. step4：事件发生控制系统
    - 游戏中构建随机事件控制器
    - 随机事件产生机制
    - 随机事件触发机制
    - 随机事件的事件效果处理

### 备忘memo

1. 目前商品id读取显示存在问题需要修复，可能需要设计一张表格用于对应物品及其id，





