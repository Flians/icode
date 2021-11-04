# 增广拉格朗日乘子法

<center>

![cover](./figure/ALM_cover.png)

</center>

&emsp;&emsp;之前的[文章](https://mp.weixin.qq.com/s?__biz=Mzg2NjY5NTE0Mw==&mid=2247483676&idx=1&sn=7ef872fc7d4106c243a54c61d6cb2138&chksm=ce47a394f9302a82d30996167721af6d18e3f13ab477355c680f728bd04e98e41a82e9b04d08&token=1050164083&lang=en_US#rd)已经介绍了拉格朗日乘数法（Lagrange Multipliers），对于一般性约束问题（包含等式约束和不等式约束）：

$$
\begin{equation}
\begin{aligned}
\mathrm{min}\ \ &f(x),\ x\in R^n \\
\mathrm{s.t.}\ \ &g(x)=c,\ c\in R^m \\
&h(x)\ge 0,\ k\in R^k
\end{aligned}
\end{equation}
$$

可以得到其拉格朗日函数：

$$
\begin{equation}
\begin{aligned}
L(x,\lambda, \gamma)&=f(x)+\lambda^T\left(g(x)-c\right)+\gamma^T\left(h(x)-\eta\right) \\
\mathrm{s.t.}\ \ \eta&\ge 0,\ \eta\in R^k,\ \lambda\in R^m,\ \eta\in R^k
\end{aligned}
\end{equation}
$$

拉格朗日乘数法通过引入拉格朗日乘子来加入一个控制项，将有约束问题转化为无约束问题。如果满足约束条件，那么这个控制项就有助于最优化，而不满足约束条件，则这个控制项就惩罚最优化。拉格朗日乘数法求解比较缓慢，且优化过程不平滑。为此，增广拉格朗日乘子法在拉格朗日函数的基础上增加了一个二次惩罚项，来平滑优化过程。

## 1 Markdown Nice 简介

- 支持自定义样式的 Markdown 编辑器
- 支持微信公众号、知乎和稀土掘金
- 欢迎扫码回复「排版」加入推文群

![](https://files.mdnice.com/pic/cd3ca20c-896f-4cfc-9bdd-c4c58e69ba26.jpg)

## 2 主题

**https://product.mdnice.com/themes/**

欢迎提交主题，提供更多文章示例~~

## 3 通用语法

### 3.1 标题

在文字写书写不同数量的`#`可以完成不同的标题，如下：

# 一级标题

## 二级标题

### 三级标题

### 3.2 无序列表

无序列表的使用，在符号`-`后加空格使用。如下：

- 无序列表 1
- 无序列表 2
- 无序列表 3

如果要控制列表的层级，则需要在符号`-`前使用空格。如下：

- 无序列表 1
- 无序列表 2
  - 无序列表 2.1
  - 无序列表 2.2

**由于微信原因，最多支持到二级列表**。

### 3.3 有序列表

有序列表的使用，在数字及符号`.`后加空格后输入内容，如下：

1. 有序列表 1
2. 有序列表 2
3. 有序列表 3

### 3.4 粗体和斜体

粗体的使用是在需要加粗的文字前后各加两个`*`。

而斜体的使用则是在需要斜体的文字前后各加一个`*`。

如果要使用粗体和斜体，那么就是在需要操作的文字前后加三个`*`。如下：

**这个是粗体**

_这个是斜体_

**_这个是粗体加斜体_**

注：由于 commonmark 标准，可能会导致加粗与想象不一致，如下

**今天天气好晴朗，**处处好风光。

这个是正常现象，请参考[加粗 Issue](https://github.com/markdown-it/markdown-it/issues/410 "加粗 Issue")。

### 3.5 链接

微信公众号仅支持公众号文章链接，即域名为`https://mp.weixin.qq.com/`的合法链接。使用方法如下所示：

对于该论述，欢迎读者查阅之前发过的文章，[你是《未来世界的幸存者》么？](https://mp.weixin.qq.com/s/s5IhxV2ooX3JN_X416nidA)

### 3.6 引用

引用的格式是在符号 `>` 后面书写文字，文字的内容可以包含标题、链接、图片、粗体和斜体等。

一级引用如下：

> ### 一级引用示例
>
> 读一本好书，就是在和高尚的人谈话。 **——歌德**
>
> [Markdown Nice 最全功能介绍](https://mp.weixin.qq.com/s/lM808MxUu6tp8zU8SBu3sg)
>
> ![这里写图片描述](https://files.mdnice.com/pic/cd3ca20c-896f-4cfc-9bdd-c4c58e69ba26.jpg)

当使用多个 `>` 符号时，就会变成多级引用

二级引用如下：

> > ### 二级引用示例
> >
> > 读一本好书，就是在和高尚的人谈话。 **——歌德**
> >
> > [Markdown Nice 最全功能介绍](https://mp.weixin.qq.com/s/lM808MxUu6tp8zU8SBu3sg)
> >
> > ![这里写图片描述](https://files.mdnice.com/pic/cd3ca20c-896f-4cfc-9bdd-c4c58e69ba26.jpg)

三级引用如下：

> > > ### 三级引用示例
> > >
> > > 读一本好书，就是在和高尚的人谈话。 **——歌德**
> > >
> > > [Markdown Nice 最全功能介绍](https://mp.weixin.qq.com/s/lM808MxUu6tp8zU8SBu3sg)
> > >
> > > ![这里写图片描述](https://files.mdnice.com/pic/cd3ca20c-896f-4cfc-9bdd-c4c58e69ba26.jpg)

### 3.7 分割线

可以在一行中用三个以上的减号来建立一个分隔线，同时需要在分隔线的上面空一行。如下：

---

### 3.8 删除线

删除线的使用，在需要删除的文字前后各使用两个`~`，如下：

~~这是要被删除的内容。~~

### 3.9 表格

可以使用冒号来定义表格的对齐方式，如下：

| 姓名       | 年龄 |         工作 |
| :--------- | :--: | -----------: |
| 小可爱     |  18  |     吃可爱多 |
| 小小勇敢   |  20  |   爬棵勇敢树 |
| 小小小机智 |  22  | 看一本机智书 |

宽度过长的表格可以滚动，可在自定义主题中调节宽度：

| 姓名       | 年龄 |         工作 |      邮箱       |    手机     |
| :--------- | :--: | -----------: | :-------------: | :---------: |
| 小可爱     |  18  |     吃可爱多 | lovely@test.com | 18812345678 |
| 小小勇敢   |  20  |   爬棵勇敢树 | brave@test.com  | 17712345678 |
| 小小小机智 |  22  | 看一本机智书 | smart@test.com  | 16612345678 |

### 3.10 图片

插入图片，如果是行内图片则无图例，否则有图例，格式如下：

![这里写图片描述](https://files.mdnice.com/pic/cd3ca20c-896f-4cfc-9bdd-c4c58e69ba26.jpg)

支持 jpg、png、gif、svg 等图片格式，**其中 svg 文件仅可在微信公众平台中使用**，svg 文件示例如下：

![](https://files.mdnice.com/i-am-svg.svg)

- 支持图片**拖拽和截图粘贴**到编辑器中上传，上传时使用当前选择的图床。
- 可使用**格式->图片**上传本地图片，网站目前支持「mdnice」图床，失败率低，但是只可保存一天用于排版

**注：仅支持 https 的图片，图片粘贴到微信、知乎或掘金时会自动上传其服务器，不必担心使用上述图床会导致图片丢失**。

图片还可以和链接嵌套使用，能够实现推荐卡片的效果，用法如下：

[![Markdown Nice 最全功能介绍](https://files.mdnice.com/dance.gif)](https://mp.weixin.qq.com/s/lM808MxUu6tp8zU8SBu3sg)

## 4. 特殊语法

### 4.1 脚注

> 支持平台：微信公众号、知乎。

脚注与链接的区别如下所示：

```markdown
链接：[文字](链接)
脚注：[文字](脚注解释 "脚注名字")
```

有人认为在[大前端时代](https://en.wikipedia.org/wiki/Front-end_web_development "Front-end web development")的背景下，移动端开发（Android、IOS）将逐步退出历史舞台。

[全栈工程师](是指掌握多种技能，并能利用多种技能独立完成产品的人。 "什么是全栈工程师")在业务开发流程中起到了至关重要的作用。

脚注内容请拉到最下面观看。

### 4.2 代码块

> 支持平台：微信公众号、知乎。

如果在一个行内需要引用代码，只要用反引号引起来就好，如下：

Use the `printf()` function.

在需要高亮的代码块的前一行及后一行使用三个反引号，同时**第一行反引号后面表示代码块所使用的语言**，如下：

```java
// FileName: HelloWorld.java
public class HelloWorld {
  // Java 入口程序，程序从此入口
  public static void main(String[] args) {
    System.out.println("Hello,World!"); // 向控制台打印一条语句
  }
}
```

支持以下语言种类：

```
bash
clojure，cpp，cs，css
dart，dockerfile, diff
erlang
go，gradle，groovy
haskell
java，javascript，json，julia
kotlin
lisp，lua
makefile，markdown，matlab
objectivec
perl，php，python
r，ruby，rust
scala，shell，sql，swift
tex，typescript
verilog，vhdl
xml
yaml
```

如果想要更换代码主题，可在上方挑选，不支持代码主题自定义。

diff 不能同时和其他语言的高亮同时显示，使用效果如下:

```diff
+ 新增项
- 删除项
```

**其他主题不带行号，可自定义是否换行，代码大小与当前编辑器一致**

### 4.3 数学公式

> 支持平台：微信公众号、知乎。

行内公式使用方法，比如这个化学公式：$\ce{Hg^2+ ->[I-] HgI2 ->[I-] [Hg^{II}I4]^2-}$

块公式使用方法如下：

$$H(D_2) = -\left(\frac{2}{4}\log_2 \frac{2}{4} + \frac{2}{4}\log_2 \frac{2}{4}\right) = 1$$

矩阵：

$$
  \begin{pmatrix}
  1 & a_1 & a_1^2 & \cdots & a_1^n \\
  1 & a_2 & a_2^2 & \cdots & a_2^n \\
  \vdots & \vdots & \vdots & \ddots & \vdots \\
  1 & a_m & a_m^2 & \cdots & a_m^n \\
  \end{pmatrix}
$$

公式由于微信不支持，目前的解决方案是转成 svg 放到微信中，无需调整，矢量不失真。

目前测试如果公式量过大，在 Chrome 下会存在粘贴后无响应，但是在 Firefox 中始终能够成功。

### 4.4 TOC

> 支持平台：微信公众号、知乎。

TOC 全称为 Table of Content，列出全部标题。由于示例标题过多，需要使用将下方代码段去除即可。

```
[TOC]
```

由于微信只支持到二级列表，本工具仅支持二级标题和三级标题的显示。

### 4.5 注音符号

> 支持平台：微信公众号。

支持注音符号，用法如下：

Markdown Nice 这么好用，简直是{喜大普奔|hē hē hē hē}呀！

### 4.6 横屏滑动幻灯片

> 支持平台：微信公众号。

通过`<![](url),![](url)>`这种语法设置横屏滑动滑动片，具体用法如下：

<![蓝1](https://files.mdnice.com/blue.jpg),![绿2](https://files.mdnice.com/green.jpg),![红3](https://files.mdnice.com/red.jpg)>

## 5 其他语法

### 5.1 HTML

支持原生 HTML 语法，请写内联样式，如下：

<span style="display:block;text-align:right;color:orangered;">橙色居右</span>
<span style="display:block;text-align:center;color:orangered;">橙色居中</span>

### 5.2 UML

不支持，推荐使用开源工具`https://draw.io/`制作后再导入图片

### 5.3 更多文档

更多文档请参考 [mdnice 产品主页](https://product.mdnice.com/articles/ "更多文档")
