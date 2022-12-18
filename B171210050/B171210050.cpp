#include <iostream>
#include <math.h>
using namespace std;

class Complex
{
private:
    float reel;
    float imag;
public:
    Complex(): reel(0),imag(0){ }
    void input()
    {
        cout << "Karmasik sayinin gercek ve sanal kisimlarini ayri ayri giriniz" << endl;
        cin >> reel;
        cin >> imag;
    }

    void polarForm()
    {
        float r = sqrt((reel * reel) + (imag * imag));
        float result = atan2f(imag, reel);
        float degree = result * (180 / 3.141592);
        cout << "Kutupsal gosterimi" << endl;
        cout << r << "*(cos(" << degree << ")+i.sin(" << degree << "))" << endl;
    }
    Complex operator + (Complex obj)
    {
        Complex temp;
        temp.reel = reel + obj.reel;
        temp.imag = imag + obj.imag;
        return temp;
    }
    Complex operator - (Complex obj)
    {
        Complex temp;
        temp.reel = reel - obj.reel;
        temp.imag = imag - obj.imag;
        return temp;
    }
    Complex operator * (Complex obj)
    {
        Complex temp;
        temp.reel = reel * obj.reel - imag * obj.imag;
        temp.imag = reel * obj.imag + imag * obj.reel;
        return temp;
    }
    Complex operator / (Complex obj)
    {
        Complex temp;
        float reelNumber = obj.reel * obj.reel + obj.imag * obj.imag;
        temp.reel = (reel * obj.reel - imag * (-1 * obj.imag)) / reelNumber;
        temp.imag = (reel * (-1 * obj.imag) + imag * obj.reel) / reelNumber;
        return temp;
    }

    Complex operator += (Complex obj)
    {
        reel = reel + obj.reel;
        imag = imag + obj.imag;
        return *this;
    }


    Complex operator -= (Complex obj)
    {
        reel = reel - obj.reel;
        imag = imag - obj.imag;
        return *this;
    }

    Complex operator *= (Complex obj)
    {
        float temp = (reel * obj.reel) - (imag * obj.imag);
        imag = (reel * obj.imag) + (imag * obj.reel);
        reel = temp;
        return *this;
    }
    Complex operator /= (Complex obj)
    {
        float reelNumber = ((obj.imag * obj.imag) + (obj.reel * obj.reel));
        float temp = ((reel * obj.reel) + (imag * obj.imag)) / reelNumber;
        imag = ((imag * obj.reel) - (reel * obj.imag)) / reelNumber;
        reel = temp;
        return *this;
    }

    void output()
    {
        if (imag < 0)
            cout << "Karmasik sayi: " << reel << imag << "i\n";
        else
            cout << "Karmasik sayi: " << reel << "+" << imag << "i\n";
    }
};

int main()
{
    Complex c1, c2, result;
    cout << "Menu\n1.Toplama\n2.Cikarma\n3.Carpma\n4.Bolme\n5.+= Islemi\n6.-= Islemi\n7.*= Islemi\n8./= Islemi\n9.Kutupsal Gosterim" << endl;
    int cevap;
    cin >> cevap;
    if (cevap == 1) {
        cout << "Toplama islemi icin karmasik sayilari giriniz" << endl;
        c1.input();
        c2.input();
        result = c1 + c2;
        result.output();
    }
    else if (cevap == 2) {
        cout << "Cikarma islemi icin karmasik sayilari giriniz" << endl;
        c1.input();
        c2.input();
        result = c1 - c2;
        result.output();

    }
    else if (cevap == 3) {
        cout << "Carpma islemi icin karmasik sayilari giriniz" << endl;
        c1.input();
        c2.input();
        result = c1 * c2;
        result.output();

    }
    else if (cevap == 4) {
        cout << "Bolme islemi icin karmasik sayilari giriniz" << endl;
        c1.input();
        c2.input();
        result = c1 / c2;
        result.output();
    }
    else if (cevap == 5) {
        cout << "+= islemi icin karmasik sayilari giriniz" << endl;
        c1.input();
        c2.input();
        c1+=c2;
        c1.output();
    }
    else if (cevap == 6) {
        cout << "-= islemi icin karmasik sayilari giriniz" << endl;
        c1.input();
        c2.input();
        c1 -= c2;
        c1.output();
    }
    else if (cevap == 7) {
        cout << "*= islemi icin karmasik sayilari giriniz" << endl;
        c1.input();
        c2.input();
        c1 *= c2;
        c1.output();
    }
    else if (cevap == 8) {
        cout << "/= islemi icin karmasik sayilari giriniz" << endl;
        c1.input();
        c2.input();
        c1 += c2;
        c1.output();
    }
    else if (cevap == 9)
    {
        cout << "Kutupsal gosterimi icin karmasik sayi giriniz" << endl;
        c1.input();
        c1.output();
        c1.polarForm();
    }
    else {
        // Güvenli cikis
        exit(1);
    }

    system("pause");
}
