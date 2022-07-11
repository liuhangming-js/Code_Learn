# 1 Python速览
## 1.1 python用作计算器
### 1.1.1 数字

***加减乘除***
```python
# + - * /
print(5 + 6)
print(50 - 5*6)
print((50 - 5*6) / 4)
print(8 / 5)
```

***商 模 乘方***
```python
# // % **
print(17 // 3)
print(17 % 3)
print(2 ** 5)
```

***赋值计算***
```python
# 赋值
width = 20
height = 5 * 9
print(width * height)
```

***混合计算自动转浮点***
```python
# 混合计算转浮点
print(4 * 3.75 - 1)
```
***

### 1.1.2 字符串
***基本字符串***
```python
# String
print("'Isn\'t,' they said.")
```

***原始字符串打印***
```python
# r-原始字符串
print("C:\some\name")
print(r"C:\some\name")
```

***多行字符串***
```python
# 多行字符串 \换行
print("""\
Usage: thingy [OPTIONS]
     -h                        Display this usage message
     -H hostname               Hostname to connect to
""")
```

***字符串合并***
```python
# string's + *
print(3 * 'un' + 'ium')

# 相邻字符串自动合并
print('Py' 'thon')

text = ('Put several strings within parentheses '
        'to have them joined together.')
print(text)
# print(text 'thon') 不可以,自动合并功能不能用于变量或表达式,只能用于两个字面值
print(text + 'thon')
```

***字符串索引及切片***
```python
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
```

***字符串长度***
```python
# 内置函数len()返回字符串长度
print(len(word))
```
***

### 1.1.3 列表

***列表定义,索引,切片,浅拷贝***
```python
squares = [1, 4, 9, 16, 25]
print(squares)
print(squares[-1])
print(squares[-3:])
print(squares[:])  # 浅拷贝
```

***合并,改变,添加***
```python
print(squares + [36, 49, 64, 81, 100])

cubes = [1, 8, 27, 64, 125]
cubes[3] = 64
print(cubes)

cubes[1:3] = []
print(cubes)

cubes.append(6 ** 3)
print(cubes)
```

***函数len()***
```python
print(len(cubes))
```

***嵌套列表***
```python
a = ['a', 'b', 'c']
n = [1, 2, 3]
x = [a, n]
print(x)
print(x[0][1])
```

***走向编程的第一步(斐波那契)***
```python
a, b = 0, 1
while a < 10:
    print(a, end=',')
    a, b = b, a+b
```