#include <iostream>
using namespace std;
int a[7][7], b[7][7];
int main()
{
    int n;
    cin >> n;
    
    while (n--) //处理n个数组
    {
        //输入5*5的数字矩阵
        getchar();//排除矩阵前的"\n"
        for (int i = 1; i <= 5; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                char ch = getchar();
                a[i][j] = ch - '0';//循环将字符类型的数字转换后放入二维数组
            }
            getchar();//排除每一行最后的"\n"
        }

        for (int i = 0; i <= (1 << 5); i++) //枚举了第一行的不同方法
        {
            for (int j = 1; j <= 5; j++)
            {
                for (int k = 1; k <= 5; k++)
                    b[j][k] = a[j][k]; 
            }
            int ans = 0; //开始计数
            
        }
    }
    
    return 0;
}