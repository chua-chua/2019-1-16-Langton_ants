
#if 0
兰顿蚂蚁

问题描述

兰顿蚂蚁，是于1986年，由克里斯·兰顿提出来的，属于细胞自动机的一种。
平面上的正方形格子被填上黑色或白色。在其中一格正方形内有一只“蚂蚁”。
蚂蚁的头部朝向为：上下左右其中一方。
蚂蚁的移动规则十分简单：
若蚂蚁在黑格，右转90度，将该格改为白格，并向前移一格；
若蚂蚁在白格，左转90度，将该格改为黑格，并向前移一格。
规则虽然简单，蚂蚁的行为却十分复杂。刚刚开始时留下的路线都会有接近对称，像是会重复，
但不论起始状态如何，蚂蚁经过漫长的混乱活动后，会开辟出一条规则的“高速公路”。
蚂蚁的路线是很难事先预测的。
你的任务是根据初始状态，用计算机模拟兰顿蚂蚁在第n步行走后所处的位置。
输入格式
输入数据的第一行是 m n 两个整数（3 < m, n < 100），表示正方形格子的行数和列数。
接下来是 m 行数据。
每行数据为 n 个被空格分开的数字。0 表示白格，1 表示黑格。
接下来是一行数据：x y s k, 其中x y为整数，表示蚂蚁所在行号和列号（行号从上到下增长，
列号从左到右增长，都是从0开始编号）。s 是一个大写字母，表示蚂蚁头的朝向，我们约定：
上下左右分别用：UDLR表示。k 表示蚂蚁走的步数。
输出格式
输出数据为两个空格分开的整数 p q, 分别表示蚂蚁在k步后，所处格子的行号和列号。
样例输入
5 6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
2 3 L 5
样例输出
1 3
样例输入
3 3
0 0 0
1 1 1
1 1 1
1 1 U 6
样例输出
0 0

#endif

#include <iostream>
using namespace std;

#define LENGTH	100	//地图长度上限
#define WIDTH	100	//地图宽度上限
#define U		1	//上
#define L		2	//左
#define D		3	//下
#define R		4	//右

//左转
void TurnLeft(int &direction)
{
	direction++;
	if (direction > 4)
		direction -= 4;
}

//右转
void TurnRight(int &direction)
{
	direction--;
	if (direction < 1)
		direction += 4;
}

//寻路
void Find(int(*map)[LENGTH], int length, int width, int i, int j, int direction, int step)
{
	//步数耗尽，则打印结果，结束寻路
	if (step <= 0)
	{
		cout << i << " " << j << endl;
		return;
	}

	//先转弯
	if (map[i][j] == 0)
		TurnLeft(direction);
	else
		TurnRight(direction);

	//再变色
	map[i][j] = map[i][j] == 0 ? 1 : 0;

	//再移动
	switch (direction)
	{
		//上
	case U:
		i--;
		break;

		//下
	case D:
		i++;
		break;

		//左
	case L:
		j--;
		break;

		//右
	case R:
		j++;
		break;

	default:
		break;
	}

	//判断是否越界
	if (i >= width || i < 0 || j >= length || j < 0)
		cout << "蚂蚁越界了!" << endl;

	//继续寻路
	Find(map, length, width, i, j, direction, step - 1);
}



//设置地图
void SetMap(int(*map)[LENGTH], int &length, int &width)
{

	cout << "void SetMap(int (*map)[LENGTH], int &length, int &width)..." << endl;

	//输入地图长宽
	while (length < 3 || length > 100 || width < 3 || width > 100)
	{
		cout << "3 <= length, width <= 100, 请设置地图长 宽:" << endl;
		cin >> width >> length;
	}

	//再设置地图详细信息
	cout << "请输入地图信息(width行length列):" << endl;
	int i = 0, j = 0;
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < length; j++)
		{
			cin >> map[i][j];
		}
	}
}


//设置蚂蚁
void SetAnt(int &i, int &j, int &direction, int &step)
{
	cout << endl;
	cout << "void SetAnt(int &i, int &j, int &direction, int &step)..." << endl;
	cout << "依次输入蚂蚁行列坐标，方向，步数:" << endl;
	char define[] = { 'U', 'L', 'D', 'R' };
	char dire = 0;

	cin >> i >> j >> dire >> step;

	//方向字符转换成数字
	for (direction = 0; direction < 4; direction++)
	{
		if (dire == define[direction])
		{
			direction++;
			break;
		}
	}
}

void test()
{
	//蚂蚁位置，i为行号，j为列号
	int i = 0;
	int j = 0;

	//地图长度和宽度
	int length = 0;
	int width = 0;

	//地图二维数组
	int map[WIDTH][LENGTH] = { 0 };

	//蚂蚁当前方向
	int direction = 0;

	//剩余步数
	int step = 0;

	//设置地图
	SetMap(map, length, width);

	//设置蚂蚁
	SetAnt(i, j, direction, step);

	//开始寻路
	Find(map, length, width, i, j, direction, step);
}


int main(void)
{
	test();

	system("pause");
	return 0;
}