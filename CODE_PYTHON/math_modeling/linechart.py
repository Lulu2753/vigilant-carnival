import matplotlib.pyplot as plt
 
x = range(11,31)
y_1 = [1,0,1,1,2,4,3,2,3,4,4,5,6,5,4,3,3,1,1,1]
y_2 = [1,0,3,1,2,2,3,3,2,1,2,1,1,1,1,1,1,1,1,1]
 
#设置图形大小
plt.figure(figsize=(20,8),dpi=80)
 
#画两条线，并写明哪条线表示什么,设置线条样式
plt.plot(x,y_1,label="得分1",color="coral",linewidth=5)
plt.plot(x,y_2,label="得分2",color="cyan",linestyle='--')
 
#设置x轴刻度
_xtick_labels = ["{}岁".format(i) for i in x]
plt.xticks(x,_xtick_labels)
#plt.yticks(range(0,9))
 
#显示中文字体
plt.rcParams['font.sans-serif'] = ['SimHei',]
 
#绘制网格,alpha设置网格透明度
plt.grid(alpha=0.5,linestyle=':')
 
#添加图例(在指定位置显示线条对应的含义)
plt.legend(loc="upper left")
plt.show()