# 通知
目前该项目已经转移到Gitee, 详情请访问: https://gitee.com/ShenMian/Herobrine

![横幅](banner_cn.jpg)  

**提示** 目前公布的源代码为早期编写的半成品, 最新的源代码将尽快上传.  

**特点**(部分还在实现中)  
- "云"命令  
  执行命令时会先下载并载入相应的模块, 并在合适的时候卸载. 有效减小被控端的体积.  
  [**基本命令**](https://gitee.com/ShenMian/Herobrine/wikis/%E5%9F%BA%E6%9C%AC%E5%91%BD%E4%BB%A4)  
- 绕过查杀软件  
  利用的被控端中的远程执行漏洞来植入HIM, 有效绕过基于特征/线索/模拟运行环境的查杀技术. 使HIM直接在内存中运行而杀毒软件和用户浑然不觉.  
- 跳跃Web认证上网  
  许多公共场所会普及Web认证上网, HIM将利用同个局域网中的HIM作为跳板, 与外网连接, 以此绕过认证.  
- 人机交互友好  
  命令行具有输入预测提示/Tab一键补全/上下键切换历史命令等功能.  
	[**该功能测试版下载**](https://gitee.com/ShenMian/Herobrine/releases/v0.0.0001)  
- 动态更新主控端IP地址  
  从给定的URL列表指定的页面中自动获取最新的主控端IP地址.  
- 支持数据库  
  可以利用MySQL数据库存储数据, 使团队协作变得轻松简单, 无需担心本地同步等问题.  
- 绕过防火墙  
  - 通过多种常见应用层协议封装数据来绕过防火墙.  
  - 采用TCP反弹式连接以绕过防火墙.  
- 代码风格严谨  
  严格按照一定规范进行编写, 使源代码具有较高的可读性.  
- 永久开放源代码  
  Herobrine已宣布永久开放源代码, 目前遵循Apache-2.0开源协议.  

详情请翻阅[**Wiki**](https://gitee.com/ShenMian/Herobrine/wikis/).  

**反馈**  
欢迎提交错误或建议到[**Issues**](https://gitee.com/ShenMian/Herobrine/issues), 或发送电子邮件至`shenmian000@outlook.com`/`shenmian000@foxmail.com`.  

**免责声明**  
在未经事先双方同意的情况下使用Herobrine攻击目标是非法的. 最终用户有责任承担所有法律责任. 开发人员不承担任何责任, 也不对此计划造成的任何误用或损害负责.  
