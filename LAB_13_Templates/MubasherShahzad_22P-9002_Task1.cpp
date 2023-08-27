#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
template <class V>
class Vector
{
private:
    V v;

public:
    Vector(V v = 0)
    {
        this->v = v;
    }
    int calculateDotProduct(Vector<V> &obj)
    {
        int temp = v.calculateDotProduct(obj.v);
        return temp;
    }
};

class My2DVector
{
private:
    int x;
    int y;
    friend ostream &operator<<(ostream &output, const My2DVector &);
    friend istream &operator>>(istream &input, My2DVector &);

public:
    My2DVector(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }

    int calculateDotProduct(const My2DVector &myVector)
    {
        int temp = x * myVector.x + y * myVector.y;
        return temp;
    }
};

class My3DVector
{
private:
    int x, y, z;
    friend ostream &operator<<(ostream &output, const My3DVector &);
    friend istream &operator>>(istream &input, My3DVector &);

public:
    My3DVector(int x = 0, int y = 0, int z = 0)
    {

        this->x = x;
        this->y = y;
        this->z = z;
    }

    int calculateDotProduct(const My3DVector &myVector)
    {
        int temp = x * myVector.x + y * myVector.y + z * myVector.z;
        return temp;
    }
};
ostream &operator<<(ostream &output, const My2DVector &vector)
{
    output << "(" << vector.x << ", " << vector.y << ")";
    return output;
}

istream &operator>>(istream &input, My2DVector &vector)
{
    input >> vector.x >> vector.y;
    return input;
}

ostream &operator<<(ostream &output, const My3DVector &vector)
{
    output << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
    return output;
}

istream &operator>>(istream &input, My3DVector &vector)
{

    input >> vector.x >> vector.y >> vector.z;
    return input;
}

int main()
{
    My2DVector V2d1, V2d2;
    My3DVector V3d1, V3d2;

    cout << "Enter x and y: ";
    cin >> V2d1;
    cout << "Enter x and y: ";
    cin >> V2d2;
    Vector<My2DVector> myV2d1(V2d1), myV2d2(V2d2);

    cout << "2D Vector " << endl;
    cout << "Vector: " << V2d1 << endl;
    cout << "Vector: " << V2d2 << endl;
    cout << "Dot product of 2D Vectors: " << myV2d1.calculateDotProduct(myV2d2) << endl;

    cout << "Enter x, y, and z: ";
    cin >> V3d1;
    cout << "Enter x, y, and z: ";
    cin >> V3d2;
    Vector<My3DVector> myV3d1(V3d1), myV3d2(V3d2);

    cout << "3D Vector" << endl;
    cout << "Vector: " << V3d1 << endl;
    cout << "Vector: " << V3d2 << endl;
    cout << "Dot product of 3D Vectors: " << myV3d1.calculateDotProduct(myV3d2) << endl;

    return 0;
}
