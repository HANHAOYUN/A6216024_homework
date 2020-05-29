#include <iostream>
#include <iomanip> // 將會使用到 setprecision
using namespace std;

// Rectangle 類別
class Rectangle
{
public:
    // 預設建構子
    Rectangle();
    // 兩個輸入參數的建構子
    Rectangle(double, double);
    // 設定寬
    void setWidth(double);
    // 設定高
    void setHeight(double);
    // 取得寬
    double getWidth();
    // 取得高
    double getHeight();
    // 取得面積
    double getArea();
    // 透過 Reference 交換
    void swapByReference(Rectangle &r2);
    // 透過 Pointer 交換
    void swapByPointer(Rectangle *p2);

private:
    // 資料欄位(data fields) 為 private，分別有寬、高
    double width;
    double height;
};
// 預設建構子實作
Rectangle::Rectangle()
{
    width = 1;
    height = 1;
}
// 兩個輸入參數的建構子實作
Rectangle::Rectangle(double newWidth, double newHeight)
{
    width = newWidth;
    height = newHeight;
}
// 設定寬實作
void Rectangle::setWidth(double newWidth)
{
    width = newWidth;
}
// 設定高實作
void Rectangle::setHeight(double newHeight)
{
    height = newHeight;
}
// 取得寬實作
double Rectangle::getWidth()
{
    return width;
}
// 取得高實作
double Rectangle::getHeight()
{
    return height;
}
// 取得面積實作
double Rectangle::getArea()
{
    return width * height;
}
// 透過 Reference 交換實作
void Rectangle::swapByReference(Rectangle &r2)
{
    Rectangle temp = *this;
    *this = r2;
    r2 = temp;
}
// 透過 Pointer 交換實作
void Rectangle::swapByPointer(Rectangle *p2)
{
    Rectangle temp = *this;
    *this = *p2;
    *p2 = temp;
}
// 主程式
int main()
{
    // 宣告四個欲輸入的值，分別為兩組寬、高
    double width1,height1,width2, height2;
    // 輸入值
    cin >> width1 >> height1 >> width2 >> height2;
    // 宣告兩個物件
    Rectangle rectangle1(width1, height1);
    Rectangle rectangle2(width2, height2);
    // 進行 Reference 交換
    cout << "SwapByReference:";
    cout << fixed << setprecision(2) << rectangle1.getArea() << " " << rectangle2.getArea();
    rectangle1.swapByReference(rectangle2);
    cout << " to " << fixed << setprecision(2) << rectangle1.getArea() << " " << rectangle2.getArea() << endl;
    // 進行 Pointer 交換
    cout << "SwapByPointer:";
    cout << fixed << setprecision(2) << rectangle1.getArea() << " " << rectangle2.getArea();
    rectangle1.swapByPointer(&rectangle2);
    cout << " to " << fixed << setprecision(2) << rectangle1.getArea() << " " << rectangle2.getArea() << endl;

    return 0;
}
