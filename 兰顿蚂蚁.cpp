
#if 0
��������

��������

�������ϣ�����1986�꣬�ɿ���˹������������ģ�����ϸ���Զ�����һ�֡�
ƽ���ϵ������θ��ӱ����Ϻ�ɫ���ɫ��������һ������������һֻ�����ϡ���
���ϵ�ͷ������Ϊ��������������һ����
���ϵ��ƶ�����ʮ�ּ򵥣�
�������ںڸ���ת90�ȣ����ø��Ϊ�׸񣬲���ǰ��һ��
�������ڰ׸���ת90�ȣ����ø��Ϊ�ڸ񣬲���ǰ��һ��
������Ȼ�򵥣����ϵ���Ϊȴʮ�ָ��ӡ��ոտ�ʼʱ���µ�·�߶����нӽ��Գƣ����ǻ��ظ���
��������ʼ״̬��Σ����Ͼ��������Ļ��һ�󣬻Ὺ�ٳ�һ������ġ����ٹ�·����
���ϵ�·���Ǻ�������Ԥ��ġ�
��������Ǹ��ݳ�ʼ״̬���ü����ģ�����������ڵ�n�����ߺ�������λ�á�
�����ʽ
�������ݵĵ�һ���� m n ����������3 < m, n < 100������ʾ�����θ��ӵ�������������
�������� m �����ݡ�
ÿ������Ϊ n �����ո�ֿ������֡�0 ��ʾ�׸�1 ��ʾ�ڸ�
��������һ�����ݣ�x y s k, ����x yΪ��������ʾ���������кź��кţ��кŴ��ϵ���������
�кŴ��������������Ǵ�0��ʼ��ţ���s ��һ����д��ĸ����ʾ����ͷ�ĳ�������Լ����
�������ҷֱ��ã�UDLR��ʾ��k ��ʾ�����ߵĲ�����
�����ʽ
�������Ϊ�����ո�ֿ������� p q, �ֱ��ʾ������k�����������ӵ��кź��кš�
��������
5 6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
2 3 L 5
�������
1 3
��������
3 3
0 0 0
1 1 1
1 1 1
1 1 U 6
�������
0 0

#endif

#include <iostream>
using namespace std;

#define LENGTH	100	//��ͼ��������
#define WIDTH	100	//��ͼ�������
#define U		1	//��
#define L		2	//��
#define D		3	//��
#define R		4	//��

//��ת
void TurnLeft(int &direction)
{
	direction++;
	if (direction > 4)
		direction -= 4;
}

//��ת
void TurnRight(int &direction)
{
	direction--;
	if (direction < 1)
		direction += 4;
}

//Ѱ·
void Find(int(*map)[LENGTH], int length, int width, int i, int j, int direction, int step)
{
	//�����ľ������ӡ���������Ѱ·
	if (step <= 0)
	{
		cout << i << " " << j << endl;
		return;
	}

	//��ת��
	if (map[i][j] == 0)
		TurnLeft(direction);
	else
		TurnRight(direction);

	//�ٱ�ɫ
	map[i][j] = map[i][j] == 0 ? 1 : 0;

	//���ƶ�
	switch (direction)
	{
		//��
	case U:
		i--;
		break;

		//��
	case D:
		i++;
		break;

		//��
	case L:
		j--;
		break;

		//��
	case R:
		j++;
		break;

	default:
		break;
	}

	//�ж��Ƿ�Խ��
	if (i >= width || i < 0 || j >= length || j < 0)
		cout << "����Խ����!" << endl;

	//����Ѱ·
	Find(map, length, width, i, j, direction, step - 1);
}



//���õ�ͼ
void SetMap(int(*map)[LENGTH], int &length, int &width)
{

	cout << "void SetMap(int (*map)[LENGTH], int &length, int &width)..." << endl;

	//�����ͼ����
	while (length < 3 || length > 100 || width < 3 || width > 100)
	{
		cout << "3 <= length, width <= 100, �����õ�ͼ�� ��:" << endl;
		cin >> width >> length;
	}

	//�����õ�ͼ��ϸ��Ϣ
	cout << "�������ͼ��Ϣ(width��length��):" << endl;
	int i = 0, j = 0;
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < length; j++)
		{
			cin >> map[i][j];
		}
	}
}


//��������
void SetAnt(int &i, int &j, int &direction, int &step)
{
	cout << endl;
	cout << "void SetAnt(int &i, int &j, int &direction, int &step)..." << endl;
	cout << "�������������������꣬���򣬲���:" << endl;
	char define[] = { 'U', 'L', 'D', 'R' };
	char dire = 0;

	cin >> i >> j >> dire >> step;

	//�����ַ�ת��������
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
	//����λ�ã�iΪ�кţ�jΪ�к�
	int i = 0;
	int j = 0;

	//��ͼ���ȺͿ��
	int length = 0;
	int width = 0;

	//��ͼ��ά����
	int map[WIDTH][LENGTH] = { 0 };

	//���ϵ�ǰ����
	int direction = 0;

	//ʣ�ಽ��
	int step = 0;

	//���õ�ͼ
	SetMap(map, length, width);

	//��������
	SetAnt(i, j, direction, step);

	//��ʼѰ·
	Find(map, length, width, i, j, direction, step);
}


int main(void)
{
	test();

	system("pause");
	return 0;
}