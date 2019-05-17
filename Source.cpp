#include<iostream>
using namespace std;
class PhanSo
{
private:
	int Tu;
	int Mau;
public:
	//Getter
	int LayTu() const
	{
		return Tu;
	}
	int LayMau() const
	{
		return Mau;
	}
	//Setter
	void SetTu(int a)
	{
		Tu = a;
	}
	void SetMau(int b)
	{
		Mau = b;
	}
	PhanSo(int a = 0, int b = 1)
	{
		Tu = a;
		Mau = b;
	}
	PhanSo operator+(PhanSo);
	PhanSo operator+(int);
	friend PhanSo operator+(int, PhanSo&);
	friend istream &operator>>(istream&, PhanSo &);
	friend ostream &operator<<(ostream&, PhanSo&);
	PhanSo operator++();
};
istream &operator>>(istream&is, PhanSo&ps)
{
	cout << "Nhap tu: ";
	int a, b;
	is >> a;
	do
	{
		cout << "Nhap mau (b!=0): ";
		is >> b;
	} while (b == 0);
	ps = PhanSo(a, b);
	return is;
}
ostream & operator<<(ostream &os, PhanSo &ps)
{
	os << ps.LayTu() << "/" << ps.LayMau();
	return os;
}
PhanSo PhanSo::operator+(int a)
{
	PhanSo temp;
	temp.Tu = LayTu() + a * LayMau();
	temp.Mau = LayMau();
	return temp;
}
PhanSo PhanSo::operator++()
{
	Tu = LayTu() +  LayMau();
	return *this;
}
PhanSo PhanSo::operator+(PhanSo ps)
{
	PhanSo temp;																//non-member function
	temp.Tu = LayTu()*ps.LayMau() + ps.LayTu()*LayMau();
	temp.Mau = LayMau() * ps.LayMau();
	return temp;
}
PhanSo operator+(int a, PhanSo &ps)
{
	PhanSo temp = ps;
	temp.Tu = a * ps.LayMau() + ps.LayTu();
	return temp;
}
int main()
{
	PhanSo A(1, 2), B(1, 2), C, D, E, F;
	C = 2 + A;
	F = B + 3;
	cout << A << "\n" << C << "\n" << D <<"\n" <<F<< endl;
	cin >> E;
	++E;
	cout << E << endl;
	system("pause");
	return 0;
}
