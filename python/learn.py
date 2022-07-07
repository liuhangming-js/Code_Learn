# + - * /
print(5 + 6)
print(50 - 5 * 6)
print((50 - 5 * 6) / 4)
print(8 / 5)

# // % **
print(17 // 3)
print(17 % 3)
print(2 ** 5)

# 赋值
width = 20
height = 5 * 9
print(width * height)

# 混合计算转浮点
print(4 * 3.75 - 1)

# String
print("'Isn\'t,' they said.")

# r-原始字符串
print("C:\some\name")
print(r"C:\some\name")

# 多行字符串 \换行
print("""\
Usage: thingy [OPTIONS]
     -h                        Display this usage message
     -H hostname               Hostname to connect to
""")

# string's + *
print(3 * 'un' + 'ium')

# 相邻字符串自动合并
print('Py' 'thon')

text = ('Put several strings within parentheses '
        'to have them joined together.')
print(text)
# print(text 'thon') 不可以,自动合并功能不能用于变量或表达式,只能用于两个字面值
print(text + 'thon')

# 字符串索引访问
word = 'Python'
print(word[0])
print(word[-1])  # 负数索引,从右边开始计数,初始下标-1

# 字符串切片,包含开始而不包含结束
print(word[2:5])
print(word[2:])
print(word[:5])
# word[42]越界会报错,但是word[42:]切片会自动处理越界,输出空串
print(word[42:])

# Python字符串不能修改
# word[0] = 'J'会报错,需新建字符串
print('J' + word[1:])

# 内置函数len()返回字符串长度
print(len(word))
