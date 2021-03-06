## CWORK

### 第一阶段使用 paho.mqtt.c + protobuf 进行通信

#### 使用方法
- 安装 protobuf库
- 安装 paho.mqtt.c库
- 编码&编译
- proto_*  protobuf 相关库、代码
- util.h mqtt封装库

一键执行测试：sh run_publish.sh

* 会删除已有的可执行端（publish:cliPub/subscribe:cliSub）
* 结束残留进程（cliPub）
* 后台运行发布端 每5秒发送一次消息
* 窗口运行订阅端 每3秒检查收一次订阅的主题
* Ctrl+c结束会有残留进程 cliPub

### 第二阶段 迁移至 paho.mqtt.embedded-c进行通信
- TODO


### mqtt 编译依赖
pthread
paho.mqtt.c github 编译安装
libssl-dev 安装这个库, mqtt 需要
cjson
mosquitto 用于测试
protobuf

### BLE 编译依赖
* build-essential  
* cmake  
* pkg-config  
* libbluetooth-dev  
* libpcre++-dev  
* libglib2.0-dev  
* apt-get install libdbus-1-dev  
* apt-get install libudev-dev  
* apt-get install libical-dev  
* apt-get install libreadline-dev  

### BLE 开发
编译环境: ubuntu 18.04  
编译工具: cmake  
蓝牙底层: bluez  
使用语言: c
编译依赖:  
  libbluetooth-dev (也就是bluez的开发版本, bluez版本5.48, 使用dbus接口)   

### BLE 开发   
文件组织  
bridge  
  gattlib  
    linux下主要的访问gatt的方法, 当前使用dbus  
  lock  
    与锁相关的信息  
  ble-sdk(test)  
    访问ble的主要子任务的函数  
  bridge_main  
    用于管理bridge的进程和任务  

### BLE 发现设备设计:  
  1. ign.c 中 event 函数, 只检查当前的状态是否为出错或者完成. 直到完成, 取出数据后,删除这个任务.   
  2. WatingBLE进行所有的蓝牙工作, 因为蓝牙工作, 分别有几个任务 发现设备, ADMIN连接,guest连接, 解锁, 有些是根用户没有关系的, 所以我需要在系统信息里面保留一个 ble_task 的指标, 以方便 WatingBLE 进行当前是哪个状态的判断.  
  3. 然后每个工作 (发现时被, admin连接, 都有不同的状态), 所以我需要 ble_task_state 来判断这个任务是否完成, 让别人判断知道这个任务完成,可以进行别的任务  
  4. 整个任务的流程是(发现设备为例): 
    4.1  某原因, 引起了需要一个蓝牙设备支持, InsertDTaskFront(msg_id, BLE_DISCOVER_BEGIN, NULL, NULL), 因为这里不需要传递给蓝牙任何数据.
    4.2  然后这个task 进入了 doing list, 当FSM_handle函数检查到当前的task, 判断当前操作是否合法(可能存在多个蓝牙任务,需要派对等情况), 假设合法, 那么就设置system info里面的BLE_TASK 为 BLE_DISCOVER_LOCK
    4.3 Wait BLE 线程, 不断检查sysinf里面的 task 是否有任务,如果有, 就调用相应的处理函数.
    4.4 Wait BLE 线程, 负责创建内存, 给相关的BLE函数, 保存返回数据
    4.5 Wait BLE 线程, 通过sysinfo返回相应的数据给调用task的 



### 命名规则:
  结构体命名: IGMLock形式, igm_lock_t
  结构体成语变量,局部变量:addr_len 形式
  函数: updateCachedTime 形式
  枚举类型: FSM_STATE 形式

### BLE TEST 相关程序:
1. 启动相关发现, 发现的设备,会打印出下面形式列表

运行命令:
  ./bridge/test/test_ble_scan 

所得结果:
4115: 12 May 2020 00:58:54.080 * --------------print Lock begin----------------
addr_len 17, addr: D9:78:2F:E3:1A:5C        // 蓝牙地址, 在pairing的时候需要
name_len 12, name: IGM303e31a5c             // 名字
paired 0                                    // 是否paired
admin_connection 0                          // 是否admin_connection
guest_connection 0
connectionID 0                              // connectionID 是多少
4115: 12 May 2020 00:58:54.081 * --------------print Lock end------------------

2. ./bridge/test/test_ble_pair D9:78:2F:E3:1A:5C
最后成功所得结果:
5949: 12 May 2020 01:45:47.227 * saving ble TASK_BLE_PAIRING data
5949: 12 May 2020 01:45:47.228 * pairing_result:
5949: 12 May 2020 01:45:47.228 * pairing success: 1
5949: 12 May 2020 01:45:47.229 * pairing admin_key:
974341a13a966c3aa9ba9720af4a7237
5949: 12 May 2020 01:45:47.229 * pairing password:
b5fa603bb0d01d38


3. ./bridge/test/test_ble_admin_unlock D9:78:2F:E3:1A:5C 974341a13a966c3aa9ba9720af4a7237 b5fa603bb0d01d38

最后成功结果:
7910: 12 May 2020 02:30:18.161 * saving ble TASK_BLE_ADMIN_UNLOCK data
7910: 12 May 2020 02:30:18.161 * unlock_result:
7910: 12 May 2020 02:30:18.161 * unlock error: 0 0 means unlock

4. ./bridge/test/test_ble_admin_unpair D9:78:2F:E3:1A:5C 974341a13a966c3aa9ba9720af4a7237 b5fa603bb0d01d38

最后成功结果:
8719: 12 May 2020 02:47:06.231 * saving ble TASK_BLE_ADMIN_UNPAIR data
8719: 12 May 2020 02:47:06.232 * unpair_result:
8719: 12 May 2020 02:47:06.232 * unlock error: 0 0 means unlock
8719: 12 May 2020 02:47:06.232 * doing_task_head is empty, check Lock list.

### BLE 相关用法
1. void addDiscoverTask(int msg_id)
添加扫描任务
扫描后, 会得到周围的数据, 打印出来如下,本例子只显示一个
4115: 12 May 2020 00:58:54.080 * --------------print Lock begin----------------
addr_len 17, addr: D9:78:2F:E3:1A:5C        // 蓝牙地只
name_len 12, name: IGM303e31a5c             // 名字
paired 0                                    // 是否paired
admin_connection 0                          // 是否admin_connection
guest_connection 0
connectionID 0                              // connectionID 是多少
4115: 12 May 2020 00:58:54.081 * --------------print Lock end------------------


2. saveTaskData(ptn);
根据不同的任务,保存不同的数据, 如果需要,就在这里获得我的数据和进行出来

3. 

  
### TODO List
1. 当锁已经被paired, 当前会出错.
2. 发送完成一个命令, 把锁有连接和监听都关闭, unpaired 命令


