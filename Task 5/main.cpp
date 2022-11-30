#include "BinaryTree.h"

int main() {
    system("chcp 65001");
    // Добавление элементов и вывод дерева
    vector<bool> treeA{};
    BinaryTree binaryTreeA(10);

    try {
        treeA.push_back(false);
        binaryTreeA.addElem(4, treeA);
        treeA.push_back(true);
        binaryTreeA.addElem(1, treeA);
        treeA.push_back(false);
        binaryTreeA.addElem(2, treeA);
        treeA.push_back(true);
        binaryTreeA.addElem(3, treeA);
        }
    catch (exception &ex) {
        cout << "Ошибка добавления элемента!" << endl;
    }
    cout
            << "_____________________________________________\n \t \tИмеем дерево А: \n_____________________________________________\n"
            << binaryTreeA << endl;

    cout << "Количество четных чисел в дереве: ";
    cout << binaryTreeA.countOfEven() << endl; //4

    cout << "Среднее арифметическое всех чисел в дереве: ";
    cout << binaryTreeA.average() << endl; //11

    cout << "Введите элемент для поиска =";
    int c;
    cin >>c ;
    cout << "Путь элемента "<<c<<": ";
    vector<bool> findArr = binaryTreeA.findElem(c);
    for (const auto &i: findArr) {
        cout << i << " ";
    }

    cout << "\nВсе элементы положительны: ";
    cout << binaryTreeA.allPositive() << endl;


    if (binaryTreeA.allPositive() == true) {
        cout << "Дерево не имеет отрицательного элемента, поэтому добавим -10" << endl;
        binaryTreeA.addElem(-10, treeA);
        cout << "Все элементы положительны: ";
        cout << binaryTreeA.allPositive() << endl;
    } else { cout << "Дерево имеет отрицательный элемент" << endl; }


    cout
            << "\n_____________________________________________\n \t \tИмеем дерево B: \n_____________________________________________\n"
            << endl;
    vector<bool> treeB{};
    BinaryTree binaryTreeB(4);
    try {
        treeB.push_back(false);
        binaryTreeB.addElem(1, treeB);
        treeB.push_back(false);
        binaryTreeB.addElem(2, treeB);
        treeB.push_back(false);
        binaryTreeB.addElem(3, treeB);
        treeB.pop_back();
        treeB.push_back(true);
        treeB.push_back(true);
        treeB.push_back(true);
        //  binaryTreeB.addElem(8, treeB); // строка для срабатывания исключения
    } catch (exception &ex) {
        cout << "Ошибка добавления элемента!" << endl;
    }

    std::cout << binaryTreeB;

    cout << "--------------------------" << endl;
    cout << "Удаление листьев:" << endl;
    binaryTreeB.deleteLeaves();
    std::cout << binaryTreeB;

    cout << "--------------------------" << endl;
    BinaryTree bin(binaryTreeB);
    cout << bin << endl;

    cout << "--------------------------" << endl;
    cout << "Очистка дерева:" << endl;
    std::cout << binaryTreeB;
    binaryTreeB.clear();
    cout << "--------------------------" << endl;

    std::cout << binaryTreeB;
    cout << "Проверка на пустом дереве В положительных элементов: " << binaryTreeB.allPositive() << endl;
}