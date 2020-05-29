#include <iostream>
#include <iomanip> // �N�|�ϥΨ� setprecision
using namespace std;

// Rectangle ���O
class Rectangle
{
public:
    // �w�]�غc�l
    Rectangle();
    // ��ӿ�J�Ѽƪ��غc�l
    Rectangle(double, double);
    // �]�w�e
    void setWidth(double);
    // �]�w��
    void setHeight(double);
    // ���o�e
    double getWidth();
    // ���o��
    double getHeight();
    // ���o���n
    double getArea();
    // �z�L Reference �洫
    void swapByReference(Rectangle &r2);
    // �z�L Pointer �洫
    void swapByPointer(Rectangle *p2);

private:
    // ������(data fields) �� private�A���O���e�B��
    double width;
    double height;
};
// �w�]�غc�l��@
Rectangle::Rectangle()
{
    width = 1;
    height = 1;
}
// ��ӿ�J�Ѽƪ��غc�l��@
Rectangle::Rectangle(double newWidth, double newHeight)
{
    width = newWidth;
    height = newHeight;
}
// �]�w�e��@
void Rectangle::setWidth(double newWidth)
{
    width = newWidth;
}
// �]�w����@
void Rectangle::setHeight(double newHeight)
{
    height = newHeight;
}
// ���o�e��@
double Rectangle::getWidth()
{
    return width;
}
// ���o����@
double Rectangle::getHeight()
{
    return height;
}
// ���o���n��@
double Rectangle::getArea()
{
    return width * height;
}
// �z�L Reference �洫��@
void Rectangle::swapByReference(Rectangle &r2)
{
    Rectangle temp = *this;
    *this = r2;
    r2 = temp;
}
// �z�L Pointer �洫��@
void Rectangle::swapByPointer(Rectangle *p2)
{
    Rectangle temp = *this;
    *this = *p2;
    *p2 = temp;
}
// �D�{��
int main()
{
    // �ŧi�|�ӱ���J���ȡA���O����ռe�B��
    double width1,height1,width2, height2;
    // ��J��
    cin >> width1 >> height1 >> width2 >> height2;
    // �ŧi��Ӫ���
    Rectangle rectangle1(width1, height1);
    Rectangle rectangle2(width2, height2);
    // �i�� Reference �洫
    cout << "SwapByReference:";
    cout << fixed << setprecision(2) << rectangle1.getArea() << " " << rectangle2.getArea();
    rectangle1.swapByReference(rectangle2);
    cout << " to " << fixed << setprecision(2) << rectangle1.getArea() << " " << rectangle2.getArea() << endl;
    // �i�� Pointer �洫
    cout << "SwapByPointer:";
    cout << fixed << setprecision(2) << rectangle1.getArea() << " " << rectangle2.getArea();
    rectangle1.swapByPointer(&rectangle2);
    cout << " to " << fixed << setprecision(2) << rectangle1.getArea() << " " << rectangle2.getArea() << endl;

    return 0;
}
