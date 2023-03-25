#include"Box.h"
#include<vector>
#include"Box.h"

class Container {
public:
    vector<Box> array;
    int length;
    int width;
    int height;
    int maxWeight;

    Container(vector<Box> array, int length, int width, int height, int maxWeight);


    void appendBoxInContainer(int i, Box box);
    void deleteBoxInContainer(int i);

    int countBoxesCont();

    double sumWeightCont();

    int sumValueCont();
    Box returnBoxByIndex(int i);

    Box& operator[](const int index);

};

istream& operator >> (istream& in, Container& container);
ostream& operator <<(ostream& out, Container& container);


class MyException : public exception {
private:
    string m_error;
public:
    MyException(string error) : m_error(error) {

    }
    const char* what() const noexcept { return m_error.c_str(); }
};
