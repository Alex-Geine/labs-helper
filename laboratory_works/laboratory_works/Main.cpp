#include <iostream>
#include <math.h>

using namespace std;




class Lab
{

	
public:
	int lenght;
	
	float* masx;
	float* masy;
	
	int name;
	
	

	virtual void funct( int name_mas) = 0;
	virtual void name_f() = 0;

};
class appr_error : public Lab
{


	virtual void funct(int name_mas)
	{
		int n;
		float b, q, g, * masdy, * masS, * masoy, t = 2.228;


	
		cout << "Введи n: " << endl;
		cin >> n;
		
		cout << "Введи b: " << endl;
		cin >> b;
		
		cout << "Введи g: " << endl;
		cin >> g;

		cout << "Введи Q: " << endl;
		cin >> q;
		

		
		lenght = n;
		name = name_mas;
		masy = new float[lenght];
		masx = new float[lenght];
		masdy = new float[lenght];
		masS =  new float[lenght];
		masoy =  new float[lenght];

		float x, sum = 0, sum1 = 0;

		for (int i = 0; i < n; i++) {
			cout << "Значение " << i + 1 << ": " << endl;

			float a;

			cin >> a;

			masx[i] = a;
		}

		cout << endl;
		cout << "Преобразования c массивом " << name << ": " << endl;

		for (int i = 0; i < n; i++) {
			masy[i] = (b * masx[i] + g);
			sum += masx[i];
		}
		x = sum / lenght;
		
		cout << "Средний x" << x << endl;
		for (int i = 0; i < n; i++) {
			
			sum1 += pow((masx[i] - x), 2);
		}
		cout << "Sum1 " << sum1 << endl;
		for (int i = 0; i < n; i++) {
			masS[i] = sqrt((q/(n-2)) * ( 1/n + pow((masx[i] - x), 2)/sum1));
			cout << "S " << i + 1 << " " << masS[i] << endl;
		}

		for (int i = 0; i < n; i++) {
			masdy[i] = t * masS[i];
			cout << "Y " << i + 1 << " " << masy[i] << endl;
		}
		for (int i = 0; i < n; i++) {
			masoy[i] = masdy[i] / masy[i];
			cout << "oy " << i + 1 << " " << masoy[i] << endl;
		}
		for (int i = 0; i < n; i++) {
			cout << "Значения для N = " << i + 1 << ": xi = " << masx[i] << " ; yi = " << masy[i] << " ; dyi = " << masdy[i] << " ; Si = " << masS[i] << " ; yi отн = " << masoy[i] << endl;
		}

		delete[] masx;
		delete[] masdy;
		delete[] masS;
		delete[] masoy;
	};

	virtual void name_f()
	{
		cout << "Аппроксимация функции" << endl;
	};
};
class average : public Lab
{
	

	virtual void funct( int name_mas)
	{
		int n;
		cout << "Введи n: " << endl;
		cin >> n;

		float St, Del, ds, dp, da;

		cout << "Введи Коэф Стьюента: " << endl;
		cin >> St;
		cout << "Введи Цену деления: " << endl;
		cin >> Del;

		float* masx;
		lenght = n;
		name = name_mas;
		masx = new float[lenght];

		for (int i = 0; i < n; i++) {
			cout << "Значение " << i + 1 << ": " << endl;

			float a;

			cin >> a;

			masx[i] = a;
		}

		cout << endl;
		cout << "Преобразования c массивом " << name << ": " << endl;

		float a = 0, sum = 0, s = 0, x = 0;

		for (int i = 0; i < lenght; i++) {

			x += masx[i];

		}

		a = x / lenght;

		cout << "Среднее значение А = " << a << endl;

		for (int i = 0; i < lenght; i++) {

			sum += pow((masx[i] - a), 2);

		}

		if (sum == 0) {
			cout << "Тебе повезло, сука, случайной погрешности нет" << endl;
		}

		else {
			s = sqrt(sum / (lenght *(lenght - 1)));

			cout << "Коэфициент S = " << s << endl;
		}

		ds = s * St;

		dp = (Del / 3) * 1.96;

		da = sqrt(pow(ds, 2) + pow(dp, 2));

		cout << "Случайная погрешность = " << ds << endl;
		cout << "Приборная погрешность = " << dp << endl;
		cout << "Абсолютная погрешность = " << da << endl;
		

		delete[] masx;
	};

	virtual void name_f()
	{
		cout << "Средние значения и погрешности" << endl;
	};
};

class total_error : public Lab
{


	virtual void funct( int name_mas)
	{
		name = name_mas;
		float a, b;

		cout << "Введи случайную погрешность, потом приборную(похер в каком порядке): " << endl;
		cin >> a;
		cin >> b;


		cout << endl;
		cout << "Преобразования c массивом " << name << ": " << endl;

		float c;

		
			c = sqrt((pow(a,2)+(pow(b,2))));

			cout << "Полная погрешность dA = " << c << endl;
		
	};

	virtual void name_f()
	{
		cout << "Абсолютная погрешность" << endl;
	};
};

class least_square_method : public Lab
{


	virtual void funct( int name_mas)
	{
		int n;
		cout << "Введи n: " << endl;
		cin >> n;
		lenght = n;
		name = name_mas;
		
		masx = new float[n];
		masy = new float[n];
		cout << "Выгрузи значения x, y:" << endl;

		for (int i = 0; i < lenght; i++) {
			float x, y;


			cout << i+1 << "й x: " << endl;
			cin >> x;

			masx[i] = x;

			cout << i+1 << "й y: " << endl;
			cin >> y;

			masy[i] = y;
		}

		cout << endl;
		cout << "Преобразования c массивом " << name << ": " << endl;

		float sum1 = 0, sum2 = 0, sum3 = 0, by = 0,  bx = 0, x = 0, q = 0, b, g, sb, sg;

		for (int i = 0; i < lenght; i++) {
			sum1 += (masx[i] * masy[i]);
			sum2 += pow(masx[i], 2);

			by += masy[i];
			bx += masx[i];
		}
		
		x = bx / lenght;
		
		for (int i = 0; i < lenght; i++) {
			sum3 += pow((masx[i] - x), 2);						
		}

		b = (n * sum1 - bx * by) / (n * sum2 - pow(bx, 2));
		g = (sum2 * by - bx * sum1) / (n * sum2 - pow(bx, 2));
		
		for (int i = 0; i < lenght; i++) {
			q += pow((b * masx[i] - masy[i] + g), 2);
		}

		sb = sqrt(q / ((n - 2) * sum3));
		sg = sqrt(q / (n * (n - 2)) + pow((x * sb), 2));
		
		cout << "Коэфициент b = " << b << endl;
		cout << "Коэфициент g = " << g << endl;
		cout << "Коэфициент q= " << q << endl;
		cout << "Коэфициент Sb= " << sb << endl;
		cout << "Коэфициент Sg= " << sg << endl;

		delete[] masx;
		delete[] masy;
	};

	virtual void name_f()
	{
		cout << "Метод наименьших квадратов" << endl;
	};
};

class correlation : public Lab
{


	virtual void funct( int name_mas)
	{
		int n;
		cout << "Введи n: " << endl;
		cin >> n;
		lenght = n;
		name = name_mas;
		masx = new float[n];
		masy = new float[n];

		cout << "Выгрузи значения x, y:" << endl;

		for (int i = 0; i < lenght; i++) {
			float x, y;


			cout << i+1 << "й x: " << endl;
			cin >> x;

			masx[i] = x;

			cout << i+1 << "й y: " << endl;
			cin >> y;

			masy[i] = y;
		}

		cout << endl;
		cout << "Преобразования c массивом " << name << ": " << endl;

		float x = 0, y = 0, sum1 = 0, sum2 = 0, sum3 = 0, r = 0, bx = 0, by = 0;

		for (int i = 0; i < lenght; i++) {

			bx += masx[i];
			by += masy[i];

		}

		x = bx / lenght;
		y = by / lenght;

		

		for (int i = 0; i < lenght; i++) {
			sum1 += ((masx[i] - x) * (masy[i] - y));
			sum2 += pow((masx[i] - x), 2);
			sum3 += pow((masy[i] - y), 2);
		}
			
			r = sum1/(sqrt(sum2)*sqrt(sum3));

			cout << "Коэфициент R= " << r << endl;

			delete[] masx;
			delete[] masy;
			
	};

	virtual void name_f()
	{
		cout << "Коэффициент корреляции" << endl;
	};
};

void main() {
	setlocale(LC_ALL, "rus");
	
	
	average av;
	correlation cor;
	total_error er;
	least_square_method lsm;
	appr_error ae;
    float* massive;
	
    const int b = 5;
	int i = 0;
	Lab* func[b];
	func[0] = &av;
	func[1] = &cor;
	func[2] = &er;
	func[3] = &lsm;
	func[4] = &ae;

	while (true) {
		i++;
		
		int num;
		

		

		cout << "Доступные тулзы: " << endl;
		cout << endl;

		for (int i = 0; i < b; i++)
		{
			cout << i + 1 << ": ";

			func[i]->name_f();

			cout << endl;

		}

		cout << "Забей номер функции, как бычок в перила: " << endl;
		cout << endl;
		cin >> num;

		func[num - 1]->funct( i);

		
	}
	

	

};
