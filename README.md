# CLabWork
## 运行环境
windows + vs2015 **x64位环境**
## 功能介绍
+ 完成同济方压缩文件展开，并输出到文件 **output\_tongji_xx.txt**
+ 完成上汽方压缩文件展开，并输出到文件 **output\_shangqi_xx.txt**

<font color = red>**(以上输出均已经完成单个配置内按familyCode排序，单个车型之间按配置排序。xx是指车型的编号，即在配置表当中的排列顺序，全文相同。)**</font>

+ 完成双方的文件对比
	+ 同济方有而上汽方没有的配置行数输出到文件 **tongji\_extra_xx.txt**
	+ 上汽方有而同济方没有的配置行数输出到文件 **shangqi\_extra_xx.txt**

<font color = red>**(以上输出中的行数是指output\_tong\_xx.txt,output\_shangqi\_xx.txt中的行数)**</font>
## 输入格式
+ **input1.txt:** familyCode featureCode:
+ **outp_ex_xx.csv:** 同济方的压缩文件
+ **xx.csv:** 上汽方的压缩文件
