# 浮生日记

---

### MVC结构设计

- 关于mvc架构、mvp架构、mvvm架构介绍：https://zhuanlan.zhihu.com/p/616953800

整个游戏的软件结构是以MVC的结构设计的，分成3层结构：Model数据模型层、View视图层（用于显示）、Controller层（用于游戏进程控制） 

使用单例模式管理每个层次的类对象，

- View视图层：`GameViewer` 
- Model数据层：`GameModel` 
- Controller控制层：`GameController`、`GameCore`、`SoundController`，

GameController与GameCore的比较：GameController更偏向于整体游戏的控制，而GameCore主要用于游戏开始的具体内容显示，

### 运行方式

使用visual studio打开项目中的`LeafLife.sln`文件，选择Release & x64平台最后生成可执行文件，

需要将res目录的资源文件同时拷贝到生成的目录下，才能保证程序的资源文件正常被使用，

### 主要技术点

1. step1：
    - MVC架构设计、单例设计模式、
    - 游戏开场剧情展示、打字动画
    - 构建声音播放控制器、同步播放打字音效、异步播放背景音乐
2. step2：
    - 游戏主循环（游戏核心）、
    - 音效开启和关闭设置
    - 游戏计时功能
3. step3：
    - 游戏界面布局
    - 游戏界面标题和时间显示
    - 玩家信息显示
    - 游戏功能选择菜单
4. step4：
    - 商品价格随机波动
    - 商品类型随机波动
    - 加载黑市商品列表数据
    - 显示黑市商品列表
5. step5：
    - 购买/出售商品功能
    - 黑市商品列表更新
    - 黑市商品列表刷新
    - 出租屋货物列表更新
    - 出租屋货物显示刷新
6. step6：
    - 构建随机事件控制器
    - 随机事件产生机制
    - 随机事件的触发
    - 随机事件的事件效果处理